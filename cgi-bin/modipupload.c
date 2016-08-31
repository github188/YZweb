#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
 
  
int main(void)  
{  
int i,j;
int length;
char data[1024];
char *len=NULL;
char *p=NULL;
char *IPaddress=NULL,*NETmask=NULL,*Gateway=NULL;
FILE *fp;

printf("Content-Type:text/html;charset=gb2312\n\n");
if(getenv("CONTENT_LENGTH")){
	length=atoi(getenv("CONTENT_LENGTH"));
	for(i=0;i<length;i++)
		data[i]=getchar();
}
	//printf(data);
	len=(char*)malloc((strlen(data))*sizeof(char));
	p=strstr(data,"#!");
	sscanf(p,"%[^-]",len);
	if((fp=fopen("/param/uploadfile/ifconfig.sh","w"))==NULL){
		printf("can not open file \n");
		exit(0);
	}
	fputs(len,fp);

	IPaddress=(char*)malloc((strlen(data))*sizeof(char));
	p=strstr(len,"eth0");
	sscanf(p+5,"%[^ ]",IPaddress);
	printf("<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\n");
	printf("<html xmlns=\"http://www.w3.org/1999/xhtml\"><head>\n");
	printf("<meta http-equiv=\"Content-Type\" content=\"text/html; charset=gb2312\" />\n");
	printf("<title>gb28181</title>\n");
	printf("</head>\n");
	printf("<body>\n");
	printf("<br><br>\n");
	printf("<div>\n");
	printf("<table style=\"width:1000px;margin-left:auto;margin-right:auto;border:solid 1px #d7d7d7;\" align=\"center\">\n");
	printf("<tr><td style='width:20%;text-align:right;padding:4pt .5em 4pt 1em;'>IP地址：</td>\n");
	printf("<td>\n");
	printf("<input type='text' name='IPaddress' value=%s>\n",IPaddress);
	printf("</td>\n");
	NETmask=(char*)malloc((strlen(data))*sizeof(char));
	sscanf(p+11+strlen(IPaddress),"%[^ ]",NETmask);
	printf("<td td style='width:20%;text-align:right;padding:4pt .5em 4pt 1em;'>子网掩码：</td>\n");
	printf("<td>\n");
	printf("<input type='text' name='NETmask' value=%s>\n",NETmask);
	printf("</td>\n");
	printf("</tr>\n");
	free(NETmask);
	free(IPaddress);
	Gateway=(char*)malloc((strlen(data))*sizeof(char));
	p=strstr(len,"gw");
	sscanf(p+3,"%[^ ]",Gateway);
	printf("<tr><td style='width:20%;text-align:right;padding:4pt .5em 4pt 1em;'>网关：</td>\n");
	printf("<td>\n");
	printf("<input type='text' name='serverip' value=%s>\n",Gateway);
	printf("</td>\n");
	free(Gateway);
	printf("<td style='width:20%;text-align:right;padding:4pt .5em 4pt 1em;'>MAC地址：</td>\n");
	printf("<td>\n");
	printf("<input type='text' name='serverport'>仅支持混频解码器\n");
	printf("</td>\n");
	printf("</tr>\n");
	printf("</table>\n");
	printf("</div>\n");
	printf("<br>\n");
	printf("<div style='text-align:center;'>\n");
	printf("<table style='margin:auto;'>\n");
	printf("<tr>\n");
	printf("<td style='text-align:center;'><a href=\"modipconfig.cgi\"><input type='button' value='返回上一页'></a></td>\n");
	printf("</tr>\n");
	printf("</table>\n");
	printf("</body>\n");
	printf("</html>\n");
	free(len);
	fflush(stdout);
}  
