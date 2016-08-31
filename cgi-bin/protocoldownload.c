#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
  
int main(void)  
{  
	int i;
	int length,count=0;
	char *data=NULL,*p=NULL,*q=NULL,*len=NULL,*len1=NULL,*len2=NULL,*len3=NULL;
	char string_name[16]={0},string_url1[16]={0},string_url2[16]={0},string_url3[16]={0};
	FILE *fp,*fp1;

	printf("Content-Type:text/html;charset=gb2312\n\n");
	if(getenv("CONTENT_LENGTH")){
		length=atoi(getenv("CONTENT_LENGTH"));
		data=(char*)malloc(length*sizeof(char));
		memset(data, 0x00, sizeof(data));
		for(i=0;i<length;i++)
			*(data+i)=getchar();
	}
	//printf(data);
	for(i=0;i<strlen(data);i++){
		if(data[i]=='n'&&data[i+1]=='a'&&data[i+2]=='m'&&data[i+3]=='e'){
			count++;
		}
	}
	//printf("%d",count);
	if((fp=fopen("/param/data/url_info.ini","w"))==NULL){
		printf("can not open file \n");
		exit(0);
	}
	if((fp1=fopen("/param/data/url_info.txt","w"))==NULL){
		printf("can not open file \n");
		exit(0);
	}
	len=(char*)malloc((strlen(data)+1)*sizeof(char));
	len1=(char*)malloc((strlen(data))*sizeof(char));
	len2=(char*)malloc((strlen(data))*sizeof(char));
	len3=(char*)malloc((strlen(data))*sizeof(char));
	if(count==0){
		exit(0);
	}
	else{
		fputs("[MAX_NUM]\n",fp);
		fputs("NUM=",fp);
		fprintf(fp,"%d\n\n",count); 
		string_name[0]='n';string_name[1]='a';string_name[2]='m';string_name[3]='e';
		string_url1[0]='u';string_url1[1]='r';string_url1[2]='l';string_url1[3]='1';
		string_url2[0]='u';string_url2[1]='r';string_url2[2]='l';string_url2[3]='2';
		string_url3[0]='u';string_url3[1]='r';string_url3[2]='l';string_url3[3]='3';
		fputs("[TYPE",fp);
		fputs("1",fp);
		fputs("1",fp1);
		fputs(",",fp1);
		fputs("]\nNAME=",fp);
		p=strstr(data,string_name);
		sscanf(p+5,"%[^&]",len);
		fputs(len,fp);
		fputs("\n",fp);
		fputs(len,fp1);
		fputs(",",fp1);
		p=strstr(data,string_url1);
		sscanf(p+5,"%[^&]",len1);
		fputs("URL0=",fp);
		fputs(len1,fp);
		fputs("\n",fp);
		fputs(len1,fp1);
		fputs(",",fp1);
		p=strstr(data,string_url2);
		sscanf(p+5,"%[^&]",len2);
		fputs("URL1=",fp);
		fputs(len2,fp);
		fputs("\n",fp);
		fputs(len2,fp1);
		fputs(",",fp1);
		p=strstr(data,string_url3);
		sscanf(p+5,"%[^&]",len3);
		fputs("URL2=",fp);
		fputs(len3,fp);
		fputs("\n\n",fp);
		fputs(len3,fp1);
		fputs("\n",fp1);
		p=p+5+strlen(len3)+1;
		for(i=2;i<=count;i++){
			memset(len, 0x00, sizeof(len));
			memset(len1, 0x00, sizeof(len1));
			memset(len2, 0x00, sizeof(len2));
			memset(len3, 0x00, sizeof(len3));
			fputs("[TYPE",fp);
			fprintf(fp,"%d",i);
			fprintf(fp1,"%d",i);
			fputs(",",fp1);
			fputs("]\nNAME=",fp);
			
			q=strstr(p,string_name);
			sscanf(q+5,"%[^&]",len);
			fputs(len,fp);
			fputs("\n",fp);
			fputs(len,fp1);
			fputs(",",fp1);
			p=p+13+strlen(len)+1;
			//strcat(string_url1,tmp);
			//printf(string_url1);
			q=strstr(p,string_url1);
			sscanf(q+5,"%[^&]",len1);
			fputs("URL0=",fp);
			fputs(len1,fp);
			fputs("\n",fp);
			fputs(len1,fp1);
			fputs(",",fp1);
			p=p+5+strlen(len)+1;

			q=strstr(p,string_url2);
			sscanf(q+5,"%[^&]",len2);
			fputs("URL1=",fp);
			fputs(len2,fp);
			fputs("\n",fp);
			fputs(len2,fp1);
			fputs(",",fp1);
			p=p+5+strlen(len)+1;

			q=strstr(p,string_url3);
			sscanf(q+5,"%[^&]",len3);
			fputs("URL2=",fp);
			fputs(len3,fp);
			fputs("\n\n",fp);
			fputs(len3,fp1);
			fputs("\n",fp1);
			p=p+5+strlen(len)+1;
		}
	free(data);
	free(len);free(len1);free(len2);free(len3);
	fclose(fp1);
	fclose(fp);
}  
}
