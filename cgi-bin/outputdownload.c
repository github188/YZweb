#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char *input,*p=NULL;
	char *req_method;
	char output[64]={0},tv[64]={0};
	int i=0,length=0;
	int j=0;
	FILE *fp1;
	char ch;

/*必加部分*/
	printf("Content-type:text/html;charset=gb2312\n\n");
//	printf("the following is query result:<br><br>");
	if(getenv("CONTENT_LENGTH")){
			length=atoi(getenv("CONTENT_LENGTH"));
			input=(char*)malloc(length*sizeof(char));
			memset(input, 0x00, sizeof(input));
			for(i=0;i<length;i++)
				*(input+i)=getchar();
		}
/*取output部分值*/
	for(i=7;i<(int)strlen(input);i++){
		if(input[i]=='&'){
			output[j]='\0';
			break;
		}
		output[j++]=input[i];
	}
/*取tv部分值*/
	for(i=11+strlen(output),j=0;i<(int)strlen(input);i++){
		if(input[i]=='&'){
			tv[j]='\0';
			break;
		}
		tv[j++]=input[i];
	}

	if((fp1=fopen("/param/data/output.sh","w"))==NULL){
		printf("can not open file \n");
		exit(0);
	}

	fputs("#!/bin/sh\n",fp1);
	fputs("set_outports -digital -hdmi_chip SLi13 2 -cec_chip none -f ",fp1);
	for(i=0;i<strlen(output);i++){
		ch=output[i];
		fputc(ch,fp1);
	}
	fputs(" -audio_engine 0 -cs rgb_0_255 -route main -analog -f ",fp1);
	for(i=0;i<strlen(tv);i++){
		ch=tv[i];
		fputc(ch,fp1);
	}
	fputs(" -route vcr -component -cav_mode rgb_sog -f 1080p50 -cs rgb_0_255 -route main",fp1);
	fclose(fp1);
	return 0;
}
