#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(void){
	char *len=NULL,*p=NULL,*q=NULL;
	int i=0,j=0;
	int length=0;
	char *data=NULL,*input=NULL;
	FILE *fp;

	printf("Content-Type:text/html;charset=gb2312\n\n");
	if(getenv("CONTENT_LENGTH")){
	length=atoi(getenv("CONTENT_LENGTH"));
	data=(char*)malloc((length-72)*sizeof(char));
	memset(data,0x00,sizeof(data));
	for(i=0;i<length-72;i++)
		data[i]=getchar();
	}
	//printf(data);
	if((fp=fopen("/param/uploadfile/url_info.ini","w"))==NULL){
		printf("can not open file \n");
		exit(0);
		}
	input=(char*)malloc((length-72)*sizeof(char));
	memset(input,0x00,sizeof(input));
	p=strstr(data,"[");
	sscanf(p,"%[^ ]",input);
	//fputs(input,fp);
	for(i=0;i<strlen(input);i++){
		if(input[i]==' '){break;}
		else{
			fputc(input[i],fp);
		}
	}
	fclose(fp);
	free(input);
	free(data);
	fflush(stdout);
}
