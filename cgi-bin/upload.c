#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
 
  
int main(void)  
{  
int i,j;
int length;
char data[1024];
char localuuid[64];
char *len=NULL;
char *p=NULL;
char *uuid=NULL,*serverip=NULL,*serverport=NULL,*serverid=NULL,*password=NULL,*expiress=NULL,*heart=NULL;
FILE *fp;

printf("Content-Type:text/html;charset=gb2312\n\n");
if(getenv("CONTENT_LENGTH")){
	length=atoi(getenv("CONTENT_LENGTH"));
	for(i=0;i<length;i++)
		data[i]=getchar();
}

	len=(char*)malloc((strlen(data))*sizeof(char));
if(strstr(data,"local_uuid.txt")){
	p=strstr(data,"LocalUUID:");
	sscanf(p,"%[^-]",len);
	if((fp=fopen("/param/uploadfile/local_uuid.txt","w"))==NULL){
		printf("can not open file \n");
		exit(0);
	}
	fputs(len,fp);
	fclose(fp);
	uuid=(char*)malloc((strlen(data))*sizeof(char));
	sscanf(p+10,"%[^-]",uuid);
	printf("<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\n");
	printf("<html xmlns=\"http://www.w3.org/1999/xhtml\"><head>\n");
	printf("<meta http-equiv=\"Content-Type\" content=\"text/html; charset=gb2312\" />\n");
	printf("<title>gb28181</title>\n");
	printf("</head>\n");
	printf("<body>\n");
	printf("<br><br>\n");
	printf("<div>\n");
	printf("<table style=\"width:100%;margin-left:auto;margin-right:auto;border:solid 1px #d7d7d7;\" align=\"center\">\n");
	printf("<tr><td style='width:20%;text-align:right;padding:4pt .5em 4pt 1em;'>本地UUID：</td>\n");
	printf("<td>\n");
	printf("<input type='text' name='localuuid' value=%s>\n",uuid);
	printf("</td>\n");
	printf("<td></td><td></td>\n");
	printf("</tr>\n");
	printf("<tr><td style='width:20%;text-align:right;padding:4pt .5em 4pt 1em;'>服务器IP地址：</td><td><input type='text' name='serverip'></td><td style='width:20%;text-align:right;padding:4pt .5em 4pt 1em;'>服务器端口：</td><td><input type='text' name='serverport'></td></tr>\n");
	printf("<tr><td style='width:20%;text-align:right;padding:4pt .5em 4pt 1em;'>服务器UUID：</td><td><input type='text' name='serveruuid'></td><td style='width:20%;text-align:right;padding:4pt .5em 4pt 1em;'>密码：</td><td><input type='text' name='pw'></td></tr>\n");
	printf("<tr><td style='width:20%;text-align:right;padding:4pt .5em 4pt 1em;'>注册消息间隔时间：</td><td><input type='text' name='timeinterval'>秒</td><td style='width:20%;text-align:right;padding:4pt .5em 4pt 1em;'>心跳消息间隔时间：</td><td><input type='text' name='heartbeat'>秒</td></tr>\n");
	printf("</table>\n");
	printf("</div>\n");
	free(uuid);
}
else if(strstr(data,"server_uuid.txt")){
	p=strstr(data,"ServerIP:");
	sscanf(p,"%[^-]",len);
	if((fp=fopen("/param/uploadfile/sever_uuid.txt","w"))==NULL){
		printf("can not open file \n");
		exit(0);
	}
	fputs(len,fp);
	fclose(fp);
	serverip=(char*)malloc((strlen(data))*sizeof(char));
	sscanf(p+9,"%[^ ]",serverip);

	printf("<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\n");
	printf("<html xmlns=\"http://www.w3.org/1999/xhtml\"><head>\n");
	printf("<meta http-equiv=\"Content-Type\" content=\"text/html; charset=gb2312\" />\n");
	printf("<title>gb28181</title>\n");
	printf("</head>\n");
	printf("<body>\n");
	printf("<br><br>\n");
	printf("<div>\n");
	printf("<table style=\"width:100%;margin-left:auto;margin-right:auto;border:solid 1px #d7d7d7;\" align=\"center\">\n");
	printf("<tr><td style='width:20%;text-align:right;padding:4pt .5em 4pt 1em;'>本地UUID：</td>\n");
	printf("<td>\n");
	printf("<input type='text' name='localuuid'>\n");
	printf("</td>\n");
	printf("<td></td><td></td>\n");
	printf("</tr>\n");
	printf("<tr><td style='width:20%;text-align:right;padding:4pt .5em 4pt 1em;'>服务器IP地址：</td>\n");
	printf("<td><input type='text' name='serverip' value=%s>",serverip);
	printf("</td>\n");
	free(serverip);
	p=strstr(data,"ServerPort:");
	serverport=(char*)malloc((strlen(data))*sizeof(char));
	sscanf(p+11,"%[^ ]",serverport);
	printf("<td style='width:20%;text-align:right;padding:4pt .5em 4pt 1em;'>服务器端口：");
	printf("</td>\n");
	printf("<td>\n");
	printf("<input type='text' name='serverport' value=%s>",serverport);
	printf("</td></tr>\n");
	free(serverport);
	p=strstr(data,"ServerID:");
	serverid=(char*)malloc((strlen(data))*sizeof(char));
	sscanf(p+9,"%[^ ]",serverid);
	printf("<tr><td style='width:20%;text-align:right;padding:4pt .5em 4pt 1em;'>服务器UUID：");
	printf("</td>\n");
	printf("<td>\n");
	printf("<input type='text' name='serveruuid' value=%s>",serverid);
	printf("</td>\n");
	free(serverid);
	p=strstr(data,"Password:");
	password=(char*)malloc((strlen(data))*sizeof(char));
	sscanf(p+9,"%[^ ]",password);
	printf("<td style='width:20%;text-align:right;padding:4pt .5em 4pt 1em;'>密码：\n");
	printf("</td>\n");
	printf("<td>\n");
	printf("<input type='text' name='pw' value=%s>",password);
	printf("</td></tr>\n");
	free(password);
	p=strstr(data,"Expiress:");
	expiress=(char*)malloc((strlen(data))*sizeof(char));
	sscanf(p+9,"%[^ ]",expiress);
	printf("<tr><td style='width:20%;text-align:right;padding:4pt .5em 4pt 1em;'>注册消息间隔时间：\n");
	printf("</td>\n");
	printf("<td>\n");
	printf("<input type='text' name='timeinterval' value=%s>",expiress);
	printf("秒</td>\n");
	free(expiress);
	p=strstr(data,"heart:");
	heart=(char*)malloc((strlen(data))*sizeof(char));
	sscanf(p+6,"%[^ ]",heart);
	printf("<td style='width:20%;text-align:right;padding:4pt .5em 4pt 1em;'>心跳消息间隔时间：\n");
	printf("</td>\n");
	printf("<td>\n");
	printf("<input type='text' name='heartbeat' value=%s>",heart);
	printf("秒</td></tr>\n");
	free(heart);
	printf("</table>\n");
	printf("</div>\n");
}
else{
	exit(0);}
	printf("<br>\n");
	printf("<div style='text-align:center;'>\n");
	printf("<table style='margin:auto;'>\n");
	printf("<tr>\n");
	printf("<td style='text-align:center;'><a href=\"gb28181config.cgi\"><input type='button' value='返回上一页'></a></td>\n");
	printf("</tr>\n");
	printf("</table>\n");
	printf("</body>\n");
	printf("</html>\n");
free(len);
fflush(stdout);
}  
