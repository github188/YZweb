#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(void){
	char *len=NULL,*p=NULL;
	int i=0,j=0;
	int length=0;
	char data[1024];
	FILE *fp;
	int ip_1=0,ip_2=0,ip_3=0,ip_4=0;
	int pn_value=0,dn_value=0,bri_value=0,to_value=0,con_value=0,cb_value=0,cr_value=0;

	printf("Content-Type:text/html;charset=gb2312\n\n");
	if(getenv("CONTENT_LENGTH")){
	length=atoi(getenv("CONTENT_LENGTH"));
	for(i=0;i<length;i++)
		data[i]=getchar();
	}
	len=(char*)malloc((strlen(data))*sizeof(char));
		p=strstr(data,"stream");
		if((fp=fopen("/param/uploadfile/rtsp_config.bin","wb"))==NULL){
			printf("can not open file \n");
			exit(0);
		}
	fwrite(p+8,84*sizeof(char),1,fp);
	fclose(fp);

	fp=fopen("/param/uploadfile/rtsp_config.bin","rb");
	fread(&ip_4,sizeof(char),1,fp);
	fseek(fp,1,SEEK_SET);
	fread(&ip_3,sizeof(char),1,fp);
	fseek(fp,2,SEEK_SET);
	fread(&ip_2,sizeof(char),1,fp);
	fseek(fp,3,SEEK_SET);
	fread(&ip_1,sizeof(char),1,fp);
	fseek(fp,4,SEEK_SET);
	fread(&pn_value,sizeof(short int),1,fp);
	fseek(fp,6,SEEK_SET);
	fread(&dn_value,sizeof(short int),1,fp);
	fseek(fp,8,SEEK_SET);
	fread(&bri_value,sizeof(char),1,fp);
	fseek(fp,9,SEEK_SET);
	fread(&to_value,sizeof(char),1,fp);
	fseek(fp,10,SEEK_SET);
	fread(&con_value,sizeof(char),1,fp);
	fseek(fp,11,SEEK_SET);
	fread(&cb_value,sizeof(char),1,fp);
	fseek(fp,12,SEEK_SET);
	fread(&cr_value,sizeof(char),1,fp);
	
	printf("<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\n");
	printf("<html xmlns=\"http://www.w3.org/1999/xhtml\"><head>\n");
	printf("<meta http-equiv=\"Content-Type\" content=\"text/html; charset=gb2312\" />\n");
	printf("<title>Rtsp协议参数配置</title>\n");
	printf("</head>\n");
	printf("<body>\n");
	printf("<br><br><br><br>");
	printf("<div>\n");
	printf("<div style=\"width:100%;margin-left:auto;margin-right:auto;border:solid 1px #d7d7d7;\">\n");
	printf("<table>\n");
	printf("<tr><td style='text-align:left;font-weight: bold;'>网络设置</td></tr>\n");
	printf("</table>\n");
	printf("<table align='center'>\n");
	printf("<tr>\n");
	printf("<td style='width:25%;text-align:right;padding:4pt .5em 4pt 1em;'>组播地址：\n");
	printf("</td>\n");
	printf("<td>");
	printf("<input type='text' name='Muticastaddress' value=%d.%d.%d.%d>\n",ip_1,ip_2,ip_3,ip_4);
	printf("</td>\n");
	printf("</tr>\n");

	printf("<tr>\n");
	printf("<td style='width:25%;text-align:right;padding:4pt .5em 4pt 1em;'>控制端口号：\n");
	printf("</td>\n");
	printf("<td>");
	printf("<input type='text' name='Controlportnum' value=%d>\n",pn_value);
	printf("</td>\n");
	printf("<td style='width:25%;text-align:right;padding:4pt .5em 4pt 1em;'>解码器编号：\n");
	printf("</td>\n");
	printf("<td>");
	printf("<input type='text' name='decodernum' value=%d>\n",dn_value);
	printf("</td>\n");
	printf("</tr>\n");
	printf("</table>\n");
	printf("</div>\n");
	printf("<br>\n");

	printf("<div style=\"width:100%;margin-left:auto;margin-right:auto;border:solid 1px #d7d7d7;\">\n");
	printf("<table>\n");
	printf("<tr><td style='text-align:left;font-weight: bold;'>色彩信息</td></tr>\n");
	printf("</table>\n");
	printf("<table align='center'>\n");
	printf("<tr>\n");
	printf("<td style='width:25%;text-align:right;padding:4pt .5em 4pt 1em;'>亮度：\n");
	printf("</td>\n");
	printf("<td>");
	printf("<input type='text' name='brightness' value=%d>\n",bri_value);
	printf("</td>\n");
	printf("<td style='width:25%;text-align:right;padding:4pt .5em 4pt 1em;'>色调：\n");
	printf("</td>\n");
	printf("<td>");
	printf("<input type='text' name='tonal' value=%d>\n",to_value);
	printf("</td>\n");
	printf("</tr>\n");

	printf("<tr>\n");
	printf("<td style='width:25%;text-align:right;padding:4pt .5em 4pt 1em;'>对比度：\n");
	printf("</td>\n");
	printf("<td>");
	printf("<input type='text' name='contrast' value=%d>\n",con_value);
	printf("</td>\n");
	printf("<td style='width:25%;text-align:right;padding:4pt .5em 4pt 1em;'>cbsaturation：\n");
	printf("</td>\n");
	printf("<td>");
	printf("<input type='text' name='cb' value=%d>\n",cb_value);
	printf("</td>\n");
	printf("</tr>\n");
	printf("<tr>\n");
	printf("<td style='width:25%;text-align:right;padding:4pt .5em 4pt 1em;'>crsaturation：\n");
	printf("</td>\n");
	printf("<td>");
	printf("<input type='text' name='cr' value=%d>\n",cr_value);
	printf("</td>\n");
	printf("</tr>\n");
	printf("</table>\n");
	printf("</div>\n");
	printf("<br>\n");
	
	printf("<div style=\"width:100%;margin-left:auto;margin-right:auto;border:solid 1px #d7d7d7;\">\n");
	printf("<table>\n");
	printf("<tr><td style='text-align:left;font-weight: bold;'>通道信息</td></tr>\n");
	printf("</table>\n");
	printf("</div>\n");
	printf("<br>\n");

	printf("<div style='text-align:center;'>\n");
	printf("<table style='margin:auto;'>\n");
	printf("<tr>\n");
	printf("<td style='text-align:center;'><a href=\"rtspconfig.cgi\"><input type='button' value='返回上一页'></a></td>\n");
	printf("</tr>\n");
	printf("<tr height=100px></tr>\n");
	printf("</table>\n");
	printf("</body>\n");
	printf("</html>\n");

	fflush(stdout);
}
