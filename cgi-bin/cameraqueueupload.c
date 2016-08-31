#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(void){
	char *len=NULL,*p=NULL;
	int i=0;
	int length=0;
	char *data=NULL;
	FILE *fp1;

	printf("Content-Type:text/html;charset=gb2312\n\n");
	if(getenv("CONTENT_LENGTH")){
	length=atoi(getenv("CONTENT_LENGTH"));
	data=(char*)malloc(length*sizeof(char));
	memset(data,0x00,strlen(data));
	for(i=0;i<length;i++)
		data[i]=getchar();
	}
	//printf(data);
	if((fp1=fopen("/param/uploadfile/rtsp_queue.bin","wb"))==NULL){
	printf("can not open file \n");
	exit(0);
	}
	p=strstr(data,"stream");
	fwrite(p+8,sizeof(char),5136,fp1);
	fclose(fp1);
	
	fflush(stdout);
}
