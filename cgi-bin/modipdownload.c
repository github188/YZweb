#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* getcgidata(FILE* fp,char* requestmethod);
int main()
{
	char *input;
	char *req_method;
	char IPaddress[64],NETmask[64],Gateway[64],textfield[64];
	int i=0;
	int j=0;
	FILE *fp1;
	char ch;

/*必加部分*/
	printf("Content-type:text/html\n\n");
//	printf("the following is query result:<br><br>");
	req_method=getenv("REQUEST_METHOD");
	input=getcgidata(stdin,req_method);

/*取IPaddress部分值*/
	for(i=10;i<(int)strlen(input);i++)
	{
		if(input[i]=='&')
		{
			IPaddress[j]='\0';
			break;
		}
		IPaddress[j++]=input[i];
	}

		if((fp1=fopen("/param/data/ifconfig.sh","w"))==NULL){
		printf("can not open file \n");
		exit(0);
	}
	//	fputs(input,fp1);
/*取得IPaddress值写入tx文件*/
	fputs("#!/bin/sh\n",fp1);
	fputs("ifconfig eth0 ",fp1);
	for(i=0;i<strlen(IPaddress);i++){
		ch=IPaddress[i];
		fputc(ch,fp1);
	}
	fputs("\n",fp1);

/*取NETmask部分值*/
	for(i=19+strlen(IPaddress),j=0;i<(int)strlen(input);i++)
	{
		if(input[i]=='&')
		{
			NETmask[j]='\0';
			break;
		}
		NETmask[j++]=input[i];
	}
	fputs("ifconfig eth0 ",fp1);
	for(i=0;i<strlen(NETmask);i++){
		ch=NETmask[i];
		fputc(ch,fp1);
	}
	fputs("\n",fp1);

/*取Gateway部分值*/
	for(i=28+strlen(IPaddress)+strlen(NETmask),j=0;i<(int)strlen(input);i++)
	{
		if(input[i]=='&')
		{
			Gateway[j]='\0';
			break;
		}
		Gateway[j++]=input[i];
	}
	fputs("route add default gw ",fp1);
	for(i=0;i<strlen(Gateway);i++){
		ch=Gateway[i];
		fputc(ch,fp1);
	}
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
