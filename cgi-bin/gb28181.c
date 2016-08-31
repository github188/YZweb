#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* getcgidata(FILE* fp,char* requestmethod);
int main()
{
	char *input;
	char *req_method;
	char localuuid[64],serverip[64],serverport[64],serverid[64],password[64],timeinterval[64],heartbeat[64];
	int i=0;
	int j=0;
	FILE *fp1,*fp2;
	char ch;

/*必加部分*/
	printf("Content-type:text/html\n\n");
//	printf("the following is query result:<br><br>");
	req_method=getenv("REQUEST_METHOD");
	input=getcgidata(stdin,req_method);

/*取localuuid部分值*/
	for(i=10;i<(int)strlen(input);i++)
	{
		if(input[i]=='&')
		{
			localuuid[j]='\0';
			break;
		}
		localuuid[j++]=input[i];
	}

		if((fp1=fopen("/param/data/local_uuid.txt","w"))==NULL){
		printf("can not open file \n");
		exit(0);
	}
/*取得localuuid值写入tx文件*/
	fputs("LocalUUID:",fp1);
	for(i=0;i<strlen(localuuid);i++){
		ch=localuuid[i];
		fputc(ch,fp1);
	}
	fclose(fp1);

	for(i=20+strlen(localuuid),j=0;i<(int)strlen(input);i++)
	{
		if(input[i]=='&'){
			serverip[j]='\0';
			break;
		}
		serverip[j++]=input[i];
	}
	
	for(i=strlen(localuuid)+strlen(serverip)+32,j=0;i<(int)strlen(input);i++)
	{
		if(input[i]=='&'){
			serverport[j]='\0';
			break;
		}
		serverport[j++]=input[i];
	}

	for(i=strlen(localuuid)+strlen(serverip)+strlen(serverport)+44,j=0;i<(int)strlen(input);i++)
	{
		if(input[i]=='&'){
			serverid[j]='\0';
			break;
		}
		serverid[j++]=input[i];
	}

	for(i=strlen(localuuid)+strlen(serverip)+strlen(serverport)+strlen(serverid)+48,j=0;i<(int)strlen(input);i++)
	{
		if(input[i]=='&'){
			password[j]='\0';
			break;
		}
		password[j++]=input[i];
	}

	for(i=strlen(localuuid)+strlen(serverip)+strlen(serverport)+strlen(serverid)+strlen(password)+62,j=0;i<(int)strlen(input);i++)
	{
		if(input[i]=='&'){
			timeinterval[j]='\0';
			break;
		}
		timeinterval[j++]=input[i];
	}

	for(i=strlen(localuuid)+strlen(serverip)+strlen(serverport)+strlen(serverid)+strlen(password)+strlen(timeinterval)+73,j=0;i<(int)strlen(input);i++)
	{
		heartbeat[j++]=input[i];
	}
	heartbeat[j]='\0';


	if((fp2=fopen("/param/data/server_uuid.txt","w"))==NULL){
		printf("can not open file \n");	
		exit(0);
	}

	fputs("ServerIP:",fp2);
	for(i=0;i<strlen(serverip);i++){
		ch=serverip[i];
		fputc(ch,fp2);
	}
	fputc(' ',fp2);

	fputs("ServerPort:",fp2);
	for(i=0;i<strlen(serverport);i++){
		ch=serverport[i];
		fputc(ch,fp2);
	}
	fputc(' ',fp2);

	fputs("ServerID:",fp2);
	for(i=0;i<strlen(serverid);i++){
		ch=serverid[i];
		fputc(ch,fp2);
	}
	fputc(' ',fp2);

	fputs("Password:",fp2);
	for(i=0;i<strlen(password);i++){
		ch=password[i];
		fputc(ch,fp2);
	}
	fputc(' ',fp2);

	fputs("Expiress:",fp2);
	for(i=0;i<strlen(timeinterval);i++){
		ch=timeinterval[i];
		fputc(ch,fp2);
	}
	fputc(' ',fp2);

	fputs("heart:",fp2);
	for(i=0;i<strlen(heartbeat);i++){
		ch=heartbeat[i];
		fputc(ch,fp2);
	}
	fputc(' ',fp2);

	fclose(fp2);

//	printf("E:\\apache\\Apache24\\cgi-bin\\data\\server_uuid.txt");
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
