#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(void){
	char *len=NULL,*p=NULL,*q=NULL;
	int i=0,j=0;
	int length=0;
	char data[1024]={0};
	char *input;
	FILE *fp1,*fp2;

	printf("Content-Type:text/html;charset=gb2312\n\n");
	if(getenv("CONTENT_LENGTH")){
	length=atoi(getenv("CONTENT_LENGTH"));
	for(i=0;i<length;i++)
		data[i]=getchar();
	}
	//printf(data);
	if(strstr(data,"cam.bin")){
		if((fp1=fopen("/param/uploadfile/cam.bin","wb"))==NULL){
		printf("can not open file \n");
		exit(0);
		}
		p=strstr(data,"stream");
		for(i=8;;i++){
			if(*(p+i+1)=='-'){break;}
			else{
				if(i%2==0){
					fwrite(p+i,2*sizeof(char),1,fp1);}
			}
		}
		fclose(fp1);
	}
	else if(strstr(data,"cam_title.bin")){
		if((fp2=fopen("/param/uploadfile/cam_title.bin","wb"))==NULL){
		printf("can not open file \n");
		exit(0);
		}
		p=strstr(data,"stream");
		for(i=8;;i++){
			if(*(p+i+1)=='-'){break;}
			else{
				if(i%2==0){
					fwrite(p+i,2*sizeof(char),1,fp2);}
			}
		}
		fclose(fp2);
	}
	else{exit(0);}
	
	fflush(stdout);
}
