#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* getcgidata(FILE* fp,char* requestmethod);
int main()
{
	char *input,*p=NULL,*tmp=NULL;
	char *req_method;
	char timeServerIp[64],timeinterval[64],timezone[64];
	int i=0;
	int j=0;
	FILE *fp1;
	char ch;

/*必加部分*/
	printf("Content-type:text/html\n\n");
//	printf("the following is query result:<br><br>");
	req_method=getenv("REQUEST_METHOD");
	input=getcgidata(stdin,req_method);

/*取timeseverip部分值*/
	for(i=13;i<(int)strlen(input);i++)
	{
		if(input[i]=='&')
		{
			timeServerIp[j]='\0';
			break;
		}
		timeServerIp[j++]=input[i];
	}

	for(i=27+strlen(timeServerIp),j=0;i<(int)strlen(input);i++)
	{
		if(input[i]=='&'){
			timeinterval[j]='\0';
			break;
		}
		timeinterval[j++]=input[i];
	}
	
	for(i=strlen(timeServerIp)+strlen(timeinterval)+36,j=0;i<(int)strlen(input);i++)
	{
		timezone[j++]=input[i];
	}
	timezone[j]='\0';
	
	if((fp1=fopen("/param/data/ntp.sh","w"))==NULL){
		printf("can not open file \n");
		exit(0);
	}
	tmp=(char*)malloc((strlen(timezone)+1)*sizeof(char));
	fputs("#!/bin/sh\n",fp1);
	if(p=strstr(timezone,"UTC-")){
		p=strstr(timezone,"UTC-");
		sscanf(p+3,"%[^\0]",tmp);
		fputs("#UTC= ",fp1);
		fputs(tmp,fp1);
	}
	else{
		p=strstr(timezone,"UTC");
		sscanf(p+6,"%[^\0]",tmp);
		fputs("#UTC= +",fp1);
		fputs(tmp,fp1);
	}
	/*p=strstr(timezone,"UTC");
	sscanf(p+3,"%[^\0]",tmp);
	fputs("#UTC= ",fp1);
	fputs(tmp,fp1);
	*/
	fputs("\n",fp1);
	free(tmp);
	fputs("./ntp_search.out -h ",fp1);
	for(i=0;i<strlen(timeServerIp);i++){
		ch=timeServerIp[i];
		fputc(ch,fp1);
	}
	fputs(" -i ",fp1);
	for(i=0;i<strlen(timeinterval);i++){
		ch=timeinterval[i];
		fputc(ch,fp1);
	}
	fputs("&",fp1);
	fclose(fp1);
	return 0;
}
char* getcgidata(FILE* fp,char* requestmethod)
{
	char* input;
	int len;
	int size=1024;
	int i=0;
/*把传递的值读进input指针*/
	if(!strcmp(requestmethod,"GET"))
	{
		input=getenv("QUERY_STRING");
		return input;
	}
	else if(!strcmp(requestmethod,"POST"))
	{
		len=atoi(getenv("CONTENT_LENGTH"));
		input=(char*)malloc(sizeof(char)*(size+1));

		if(len==0)
		{
			input[0]='\0';
			return input;
		}

		while(1)
		{
			input[i]=(char)fgetc(fp);
			if(i==size){
				input[i+1]='\0';
				return input;
			}
			--len;
			if(feof(fp)||(!(len))){
				i++;
				input[i]='\0';
				return input;
			}
			i++;
		}
	}
	return NULL;
}
