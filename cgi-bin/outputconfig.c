#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	printf("content-Type:text/html;charset=gb2312\n\n");
	printf("<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\n");
	printf("<html xmlns=\"http://www.w3.org/1999/xhtml\"><head>\n");
	printf("<meta http-equiv=\"Content-Type\" content=\"text/html; charset=gb2312\" />\n");
	printf("<script type=\"text/javascript\" language=\"javascript\">\n");
	printf("function submit1(){document.outputdownload.action=\"outputdownload.cgi\";document.outputdownload.submit();}");
	printf("function submit2(){document.outputupload.action=\"outputupload.cgi\";document.outputupload.submit();}");
	printf("</script>\n");
	printf("</head>\n");
	printf("<body>\n");
	printf("<iframe name='server' style='display:none;' src=''></iframe>\n");
	printf("<form name='outputdownload' method='POST' target='server'>\n");
	printf("<br><br>");
	printf("<div style=\"width:100%;margin-left:auto;margin-right:auto;border:solid 1px #d7d7d7;\">\n");
	printf("<table align='center'>\n");
	printf("<tr>\n");
	printf("<td style='width:5%;text-align:right;padding:4pt .5em 4pt 1em;'>输出：</td>\n");
	printf("<td><select name='output'>\n");
	printf("<option>HDMI_720p50</option><option>HDMI_720p60</option><option>HDMI_1080i25</option><option>HDMI_1080i50</option><option>HDMI_1080i60</option>");
	printf("<option>HDMI_1080p50</option><option>HDMI_1080p60</option><option>DVI_720p50</option><option>DVI_720p60</option><option>DVI_1080i25</option>");
	printf("<option>DVI_1080i50</option><option>DVI_1080i60</option><option>DVI_1080p50</option><option>DVI_1080p60</option><option>DVI_1600*1200</option>");
	printf("<option>DVI_1600*900</option><option>DVI_1440*900</option><option>DVI_1920*1200</option><option>DVI_1280*1024</option>");
	printf("</select></td>\n");
	printf("<td style='width:100px;'></td>");
	printf("<td style='width:5%;text-align:right;padding:4pt .5em 4pt 1em;'>电视制式：</td>\n");
	printf("<td><select name='tv'>\n");
	printf("<option>NTSC_M_JAPAN</option><option>NTSC_M</option><option>PAL_69</option><option>PAL_M</option>");
	printf("</select></td>\n");
	printf("</tr>\n");
	printf("</table>\n");
	printf("</div>\n");

	printf("<br>");
	printf("<tr><td><input name='hello' value='hello' style='Visibility:hidden'></td></tr>");
	printf("<div style='text-align:center;'>");
	printf("<table style='margin:auto;'>");
	printf("<tr>\n");
	printf("<td style='text-align:center;'><input type='button' name='ACTION' value='保存' onclick='submit1()'></td></form>\n");
	printf("<td style='width:50px;'></td>");
	printf("<form name='outputupload' method='POST' ENCTYPE=\"multipart/form-data\">\n");
	printf("<td style='width:300px;text-align:center;'><input type='file' name='FILE1' id='FILE1' style='width:160px'><input type='button' name='ACTION' value='上传文件' onclick='submit2()'></td></form>");
	printf("</tr>\n");
	printf("</table>\n");
	printf("</div>\n");
	printf("</body>\n");
	printf("</html>");
	return 0;
}
