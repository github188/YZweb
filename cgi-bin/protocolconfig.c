#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	char c,lc=NULL;
	int i,line=0;
	char msgget[1024];
	char tmp1[128]={0},tmp2[128]={0},tmp3[128]={0},tmp4[128]={0},tmp5[128]={0};
	FILE *fp;
	if((fp=fopen("/web/htdocs/data/url_info.txt","r"))==NULL){
			printf("can not open file \n");
			exit(0);
	}
	if((c=fgetc(fp))==EOF){
		line=0;
	}
	else{
		while((c=fgetc(fp))!=EOF){
			if(c=='\n') line++;
			lc=c;
		}
		if(lc!='\n') line++;
	}
	fclose(fp);
	fp=fopen("/param/data/url_info.txt","r");
	printf("content-Type:text/html;charset=gb2312\n\n");
	printf("<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\n");
	printf("<html xmlns=\"http://www.w3.org/1999/xhtml\"><head>\n");
	printf("<meta http-equiv=\"Content-Type\" content=\"text/html; charset=gb2312\" />\n");
	printf("<script>\n");
	printf("var yugi = {\n");	
    printf("col: 6,\n");
	printf("addRow: function(targetTable) {\n");
	printf("var u_protocolname = document.getElementById('u_protocolname');\n");
	printf("var u_url1 = document.getElementById('u_url1');\n");
	printf("var u_url2 = document.getElementById('u_url2');\n");
	printf("var u_url3 = document.getElementById('u_url3');\n");
	printf("var vals = [targetTable.tBodies[0].rows.length,u_protocolname.value, u_url1.value, u_url2.value,u_url3.value, \"<a href='###' onclick='yugi.del(targetTable,this)'>删除</a>\"];\n");
	printf("var tr = targetTable.insertRow(targetTable.tBodies[0].rows.length);\n");
	printf("var td0 = tr.insertCell(0);\n");
	printf("td0.innerHTML = '<input type=\"text\" style=\"width:120px;\" value=\"'+vals[0]+'\">';\n");
	printf("var td1 = tr.insertCell(1);\n");
	printf("td1.innerHTML = '<input type=\"text\" style=\"width:120px;\" name=\"protocolname\" value=\"'+vals[1]+'\">';\n");
	printf("var td2 = tr.insertCell(2);\n");
	printf("td2.innerHTML = '<input type=\"text\" style=\"width:120px;\" name=\"url1\" value=\"'+vals[2]+'\">';\n");
	printf("var td3 = tr.insertCell(3);\n");
	printf("td3.innerHTML = '<input type=\"text\" style=\"width:120px;\" name=\"url2\" value=\"'+vals[3]+'\">';\n");
	printf("var td4 = tr.insertCell(4);\n");
	printf("td4.innerHTML = '<input type=\"text\" style=\"width:120px;\" name=\"url3\" value=\"'+vals[4]+'\">';\n");
	printf("var td5 = tr.insertCell(5);\n");
	printf("td5.innerHTML = vals[5];\n");
	printf("},\n");

	printf("onload: function(targetTable) {\n");
	if(line>0){
		for(i=0;i<line;i++){
			fgets(msgget,1024,fp);
			sscanf(msgget,"%[^,],%[^,],%[^,],%[^,],%s",tmp1,tmp2,tmp3,tmp4,tmp5);
			printf("var u_protocolname = document.getElementById('u_protocolname');\n");
			printf("var u_url1 = document.getElementById('u_url1');\n");
			printf("var u_url2 = document.getElementById('u_url2');\n");
			printf("var u_url3 = document.getElementById('u_url3');\n");
			printf("var vals = [targetTable.tBodies[0].rows.length,u_protocolname.value, u_url1.value, u_url2.value,u_url3.value, \"<a href='###' onclick='yugi.del(targetTable,this)'>删除</a>\"];\n");
			printf("var tr = targetTable.insertRow(targetTable.tBodies[0].rows.length);\n");
			printf("var td0 = tr.insertCell(0);\n");
			printf("td0.innerHTML = '<input type=\"text\" style=\"width:120px;\" value=\"'+'%s'+'\">';\n",tmp1);
			printf("var td1 = tr.insertCell(1);\n");
			printf("td1.innerHTML = '<input type=\"text\" style=\"width:120px;\" name=\"protocolname\" value=\"'+'%s'+'\">';\n",tmp2);
			printf("var td2 = tr.insertCell(2);\n");
			printf("td2.innerHTML = '<input type=\"text\" style=\"width:120px;\" name=\"url1\" value=\"'+'%s'+'\">';\n",tmp3);
			printf("var td3 = tr.insertCell(3);\n");
			printf("td3.innerHTML = '<input type=\"text\" style=\"width:120px;\" name=\"url2\" value=\"'+'%s'+'\">';\n",tmp4);
			printf("var td4 = tr.insertCell(4);\n");
			printf("td4.innerHTML = '<input type=\"text\" style=\"width:120px;\" name=\"url3\" value=\"'+'%s'+'\">';\n",tmp5);
			printf("var td5 = tr.insertCell(5);\n");
			printf("td5.innerHTML = vals[5];\n");
		}
	}
	printf("},\n");

	printf(" del: function(targetTable, row) {\n");
	printf("var ind = row.parentElement.parentElement.rowIndex;\n");
    printf("targetTable.tBodies[0].deleteRow(ind);\n");
    printf("}\n");
	printf("}\n");
	printf("function submit1(){\n");
	printf("document.protocoldownload.action=\"protocoldownload.cgi\";\n");
	printf("document.protocoldownload.submit();\n");
	printf("}\n");
	printf("</script>\n");
	printf("</head>\n");
	printf("<body onload='yugi.onload(targetTable)'>\n");
	printf("<iframe name='server' style='display:none;' src=''></iframe>\n");
	printf("<form name='protocoldownload' method='POST' target='server'>\n");
	printf("<div style=\"width:100%;margin-left:auto;margin-right:auto;border:solid 1px #d7d7d7;\">\n");
	printf("<table>\n");
	printf("<tr><td style='text-align:left;font-weight: bold;'>新增协议项</td></tr>\n");
	printf("</table>\n");

	printf("<table align='center'>\n");
	printf("<tr>\n");
	printf("<td style='width:25%;text-align:right;padding:4pt .5em 4pt 1em;'>协议名称：\n");
	printf("</td>\n");
	printf("<td>");
	printf("<input type='text' id='u_protocolname'>\n");
	printf("</td>\n");
	printf("<td style='width:25%;text-align:right;padding:4pt .5em 4pt 1em;'>协议编号：\n");
	printf("</td>\n");
	printf("<td>");
	printf("<input type='text' id='u_protocolnum'>\n");
	printf("</td>\n");
	printf("</tr>\n");

	printf("<tr>\n");
	printf("<td style='width:25%;text-align:right;padding:4pt .5em 4pt 1em;'>URL1：\n");
	printf("</td>\n");
	printf("<td>");
	printf("<input type='text' id='u_url1'>\n");
	printf("</td>\n");
	printf("<td style='width:25%;text-align:right;padding:4pt .5em 4pt 1em;'>URL2：\n");
	printf("</td>\n");
	printf("<td>");
	printf("<input type='text' id='u_url2'>\n");
	printf("</td>\n");
	printf("</tr>\n");
	printf("<tr>\n");
	printf("<td style='width:25%;text-align:right;padding:4pt .5em 4pt 1em;'>URL3：\n");
	printf("</td>\n");
	printf("<td>");
	printf("<input type='text' id='u_url3'>\n");
	printf("</td>\n");
	printf("</tr>\n");
	printf("</table>\n");
	printf("<table style='margin:auto;'>\n");
	printf("<tr>\n");
	printf("<td style='text-align:center;'><input type='button' onclick='yugi.addRow(targetTable)' value='增加'></td>");
	printf("</tr>\n");
	printf("</table>\n");
	printf("</div>\n");
	printf("<br>\n");

	printf("<div style=\"width:100%;margin-left:auto;margin-right:auto;border:solid 1px #d7d7d7;\">\n");
	printf("<table>\n");
	printf("<tr><td style='text-align:left;font-weight: bold;'>当前协议项</td></tr>\n");
	printf("</table>\n");
	printf("<table id='targetTable'  align=\"center\">\n");
	printf("<tr>\n");
	printf("<th style='width:120px;text-align:left;'>序号</th>\n");
	printf("<th style='width:120px;text-align:left;'>协议名称</th>\n");
	printf("<th style='width:120px;text-align:left;'>URL1</th>\n");
	printf("<th style='width:120px;text-align:left;'>URL2</th>\n");
	printf("<th style='width:120px;text-align:left;'>URL3</th>\n");
	printf("</tr>\n");
	printf("</table>\n");
	printf("</div>\n");
	printf("<br>\n");

	printf("<tr><td><input name='hello' value='hello' style='Visibility:hidden'></td></tr>");
	printf("<div style=\"width:100%;text-align:center;\">\n");
	printf("<table style='margin:auto;'>\n");
	printf("<tr>\n");
	printf("<td style='text-align:center;'><input type='button' value='保存' onclick='submit1()'></td>\n");
	printf("</form>\n");
	printf("</tr>\n");
	printf("</table>");
	printf("</div>\n");
	printf("</body>\n");
	printf("</html>");
	fclose(fp);
	return 0;
}
