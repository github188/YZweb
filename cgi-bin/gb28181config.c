#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	printf("content-Type:text/html;charset=gb2312\n\n");
	printf("<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\n");
	printf("<html xmlns=\"http://www.w3.org/1999/xhtml\"><head>\n");
	printf("<meta http-equiv=\"Content-Type\" content=\"text/html; charset=gb2312\" />\n");
	printf("<script type=\"text/javascript\" language=\"javascript\">\n");
	printf("function submit1(){document.gb28181.action=\"gb28181.cgi\";document.gb28181.submit();}");
	printf("function submit2(){document.upload.action=\"upload.cgi\";document.upload.submit();}");
	printf("</script>\n");
	printf("</head>\n");
	printf("<body>\n");
	printf("<iframe name='server' style='display:none;' src=''></iframe>\n");
	printf("<form name='gb28181' method='POST' target='server'>\n");
	printf("<br><br>");
	printf("<div style=\"width:100%;margin-left:auto;margin-right:auto;border:solid 1px #d7d7d7;\">\n");
	printf("<table align='center'>\n");
	printf("<tr>\n");
	printf("<td style='width:20%;text-align:right;padding:4pt .5em 4pt 1em;'>本地UUID：</td>\n");
	printf("<td><input type='text' name='localuuid'></td>\n");
	printf("</tr>\n");
	printf("<tr>\n");
	printf("<td style='width:20%;text-align:right;padding:4pt .5em 4pt 1em;'>服务器IP地址：</td>\n");
	printf("<td><input type='text' name='serverip'></td>\n");
	printf("<td style='width:20%;text-align:right;padding:4pt .5em 4pt 1em;'>服务器端口：</td>\n");
	printf("<td><input type='text' name='serverport'></td>\n");
	printf("</tr>\n");
	printf("<tr>\n");
	printf("<td style='width:20%;text-align:right;padding:4pt .5em 4pt 1em;'>服务器UUID：</td>\n");
	printf("<td><input type='text' name='serveruuid'></td>\n");
	printf("<td style='width:20%;text-align:right;padding:4pt .5em 4pt 1em;'>密码：</td>\n");
	printf("<td><input type='text' name='pw'></td>\n");
	printf("</tr>\n");
	printf("<tr>\n");
	printf("<td style='width:20%;text-align:right;padding:4pt .5em 4pt 1em;'>注册消息间隔时间：</td>\n");
	printf("<td><input type='text' name='timeinterval'></td>\n");
	printf("<td style='width:20%;text-align:right;padding:4pt .5em 4pt 1em;'>心跳消息间隔时间：</td>\n");
	printf("<td><input type='text' name='heartbeat'>秒</td>\n");
	printf("</tr>\n");
	printf("</table>\n");
	printf("</div>\n");

	printf("<br>");
	printf("<div style='text-align:center;'>");
	printf("<table style='margin:auto;'>");
	printf("<tr>\n");
	printf("<td style='text-align:center;'><input type='button' name='ACTION' value='保存' onclick='submit1()'></td></form>\n");
	printf("<td style='width:50px;'></td>");
	printf("<form name='upload' method='POST' ENCTYPE=\"multipart/form-data\">\n");
	printf("<td style='width:300px;text-align:center;'><input type='file' name='FILE1' id='FILE1' style='width:160px'><input type='button' name='ACTION' value='上传文件' onclick='submit2()'></td></form>");
	printf("</tr>\n");
	printf("</table>\n");
	printf("</div>\n");
	printf("</body>\n");
	printf("</html>");
	return 0;
}
