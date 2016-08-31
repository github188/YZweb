#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>

int main(void)
{
int i,j;
int length;
char data[1024];
char *timeServerIp=NULL,*timeinterval=NULL,*timezone=NULL;
char *len=NULL;
char *p=NULL;
FILE *fp;

printf("Content-Type:text/html;charset=gb2312\n\n");
if(getenv("CONTENT_LENGTH")){
	length=atoi(getenv("CONTENT_LENGTH"));
	for(i=0;i<length;i++)
		data[i]=getchar();
}
	//printf(data);
	len=(char*)malloc((strlen(data))*sizeof(char));
	p=strstr(data,"#!/bin/sh");
	sscanf(p,"%[^&]",len);
	if((fp=fopen("/param/uploadfile/ntp.sh","w"))==NULL){
		printf("can not open file \n");
		exit(0);
	}
	fputs(len,fp);
	fputs("&",fp);
	free(len);
	fclose(fp);
	timeServerIp=(char*)malloc((strlen(data))*sizeof(char));
	p=strstr(data,"-h ");
	sscanf(p+3,"%[^ ]",timeServerIp);
	printf("<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\n");
	printf("<html xmlns=\"http://www.w3.org/1999/xhtml\"><head>\n");
	printf("<meta http-equiv=\"Content-Type\" content=\"text/html; charset=gb2312\" />\n");
	printf("<title>gb28181</title>\n");
	printf("<link rel=\"stylesheet\" type=\"text/css\" src=\"../css/css.css\">\n");
	printf("</head>\n");
	printf("<body>\n");
	printf("<br><br>\n");
	printf("<div>\n");
	printf("<table style=\"width:1000px;margin-left:auto;margin-right:auto;border:solid 1px #d7d7d7;\" align=\"center\">\n");
	printf("<tr><td style='width:30%;text-align:right;padding:4pt .5em 4pt 1em;'>时间服务器IP：</td>\n");
	printf("<td>\n");
	printf("<input type='text' name='timeServerIp' value=%s>\n",timeServerIp);
	printf("</td>\n");
	printf("</tr>\n");
	free(timeServerIp);
	timeinterval=(char*)malloc((strlen(data))*sizeof(char));
	p=strstr(data,"-i ");
	sscanf(p+3,"%[^&]",timeinterval);
	printf("<tr><td style='width:30%;text-align:right;padding:4pt .5em 4pt 1em;'>时间间隔：\n");
	printf("</td>\n");
	printf("<td>\n");
	printf("<input type='text' name='timeinterval' value=%s>\n",timeinterval);
	printf("分钟</td>\n");
	free(timeinterval);
	timezone=(char*)malloc((strlen(data))*sizeof(char));
	p=strstr(data,"#UTC=");
	sscanf(p+6,"%[^ ]",timezone);
	printf("<tr><td style='width:30%;text-align:right;padding:4pt .5em 4pt 1em;'>时区：\n");
	printf("</td>\n");
	printf("<td>\n");
	printf("<input type='text' name='timezone' value=UTC%s>\n",timezone);
	printf("</td>\n");
	free(timezone);
	printf("</table>\n");
	printf("</div>\n");
	printf("<br>\n");

	printf("<div style='text-align:center;'>\n");
	printf("<table style='margin:auto;'>\n");
	printf("<tr>\n");
	printf("<td style='text-align:center;'><a href=\"ntpconfig.cgi\"><input type='button' value='返回上一页'></a></td>\n");
	printf("</tr>\n");
	printf("</table>\n");
	printf("</body>\n");
	printf("</html>\n");
	fflush(stdout);
}
