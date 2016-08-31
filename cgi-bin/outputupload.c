#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
	int i,j;
	int length;
	char data[1024];
	char *output=NULL,*tv=NULL,*len=NULL,*p=NULL;
	FILE *fp;

	printf("Content-Type:text/html;charset=gb2312\n\n");
	if(getenv("CONTENT_LENGTH")){
		length=atoi(getenv("CONTENT_LENGTH"));
		for(i=0;i<length;i++)
			data[i]=getchar();
	}
	len=(char*)malloc((strlen(data))*sizeof(char));
	p=strstr(data,"#!/bin/sh");
	sscanf(p,"%[^v]",len);
//	printf(len);

	if((fp=fopen("/param/uploadfile/output.sh","w"))==NULL){
		printf("can not open file \n");
		exit(0);
	}
	fputs(len,fp);
	fputs("vcr -component -cav_mode rgb_sog -f 1080p50 -cs rgb_0_255 -route main",fp);
	fclose(fp);
	output=(char*)malloc((strlen(data))*sizeof(char));
	p=strstr(len,"none -f");
	sscanf(p+8,"%[^ ]",output);
	
	printf("<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\n");
	printf("<html xmlns=\"http://www.w3.org/1999/xhtml\"><head>\n");
	printf("<meta http-equiv=\"Content-Type\" content=\"text/html; charset=gb2312\" />\n");
	printf("<title>gb28181</title>\n");
	printf("<link rel=\"stylesheet\" type=\"text/css\" src=\"../css/css.css\">\n");
	printf("</head>\n");
	printf("<body>\n");
	printf("<br><br><br><br><br>\n");
	printf("<div>\n");
	printf("<table style=\"width:1000px;margin-left:auto;margin-right:auto;border:solid 1px #d7d7d7;\" align=\"center\">\n");
	printf("<tr><td style='width:30%;text-align:right;padding:4pt .5em 4pt 1em;'>输出：</td>\n");
	printf("<td>\n");
	printf("<input type='text' name='output' value=%s>\n",output);
	printf("</td>\n");
	free(output);
	tv=(char*)malloc((strlen(data))*sizeof(char));
	p=strstr(data,"-analog -f");
	sscanf(p+11,"%[^ ]",tv);
	printf("<td style='width:30%;text-align:right;padding:4pt .5em 4pt 1em;'>电视制式：</td>\n");
	printf("<td>\n");
	printf("<input type='text' name='tv' value=%s>\n",tv);
	printf("</td>\n");
	printf("</tr>\n");
	printf("</table>\n");
	printf("</div>\n");
	printf("<br>\n");
	free(tv);
	printf("<div style='text-align:center;'>\n");
	printf("<table style='margin:auto;'>\n");
	printf("<tr>\n");
	printf("<td style='text-align:center;'><a href=\"outputconfig.cgi\"><input type='button' value='返回上一页'></a></td>\n");
	printf("</tr>\n");
	printf("</table>\n");
	printf("</body></html>\n");
	free(len);
	fflush(stdout);
}
