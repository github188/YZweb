#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	char c,lc=NULL;
	int i,line=0;
	char tmp1[64],tmp2[64],tmp3[64],tmp4[64],tmp5[64];
	char msgget[1024];
	FILE *fp;
	if((fp=fopen("/param/data/cam_config.txt","r"))==NULL){
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
	if(lc!='\n')line++;
	}
	fclose(fp);
	fp=fopen("/param/data/cam_config.txt","r");
	//fgets(msgget,1024,fp);
	//sscanf(msgget,"%[^,],%[^,],%[^,],%[^,],%s",tmp1,tmp2,tmp3,tmp4,tmp5);
    printf("content-Type:text/html;charset=gb2312\n\n");
    printf("<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\n");
	printf("<html xmlns=\"http://www.w3.org/1999/xhtml\"><head>\n");
	printf("<meta http-equiv=\"Content-Type\" content=\"text/html; charset=gb2312\" />\n");
	printf("<script>\n");
	printf("var yugi = {\n");	
    printf("col: 6,\n");
	printf("addRow: function(targetTable) {\n");
	printf("var u_ipaddress = document.getElementById('u_ipaddress');\n");
	printf("var u_controlport = document.getElementById('u_controlport');\n");
	printf("var u_protocol = document.getElementById('u_protocol');\n");
	printf("var u_cameraname = document.getElementById('u_cameraname');\n");
    printf("var vals = [targetTable.tBodies[0].rows.length,u_ipaddress.value, u_controlport.value, u_protocol.value, u_cameraname.value, \"<a href='###' onclick='yugi.del(targetTable,this)'>ɾ��</a>\"];\n");
    printf("var tr = targetTable.insertRow(targetTable.tBodies[0].rows.length); //insetRow��������ֵ\n");
	printf("var td0 = tr.insertCell(0);\n");
    printf("td0.innerHTML = '<input type=\"text\" value=\"'+vals[0]+'\">';\n");
	printf("var td1 = tr.insertCell(1);\n");
    printf("td1.innerHTML = '<input type=\"text\" name=\"ipaddress\" value=\"'+vals[1]+'\">';\n");
	printf("var td2 = tr.insertCell(2);");
    printf("td2.innerHTML = '<input type=\"text\" name=\"controlport\" value=\"'+vals[2]+'\">';\n");
	printf("var td3 = tr.insertCell(3);");
    printf("td3.innerHTML = '<input type=\"text\" name=\"protocol\" value=\"'+vals[3]+'\">';\n");
	printf("var td4 = tr.insertCell(4);\n");
    printf("td4.innerHTML = '<input type=\"text\" name=\"cameraname\" value=\"'+vals[4]+'\">';\n");
	printf("var td5 = tr.insertCell(5);\n");
    printf("td5.innerHTML = vals[5];\n");
	printf("},\n");

	printf("onload: function(targetTable){\n");
	if(line>0){
	for(i=0;i<line;i++){
	//memset(msgget, 0x00, sizeof(msgget));
	fgets(msgget,1024,fp);
	sscanf(msgget,"%[^,],%[^,],%[^,],%[^,],%s",tmp1,tmp2,tmp3,tmp4,tmp5);
	printf("var u_ipaddress = document.getElementById('u_ipaddress');\n");
	printf("var u_controlport = document.getElementById('u_controlport');\n");
	printf("var u_protocol = document.getElementById('u_protocol');\n");
	printf("var u_cameraname = document.getElementById('u_cameraname');\n");
	printf("var vals = [targetTable.tBodies[0].rows.length,u_ipaddress.value, u_controlport.value, u_protocol.value, u_cameraname.value, \"<a href='###' onclick='yugi.del(targetTable,this)'>ɾ��</a>\"];\n");
    printf("var tr = targetTable.insertRow(targetTable.tBodies[0].rows.length); //insetRow��������ֵ\n");
	printf("var td0 = tr.insertCell(0);\n");
	printf("td0.innerHTML = '<input type=\"text\" value=\"'+'%s'+'\">';\n",tmp1);
	printf("var td1 = tr.insertCell(1);\n");
	printf("td1.innerHTML = '<input type=\"text\" name=\"ipaddress\" value=\"'+'%s'+'\">';\n",tmp2);
	printf("var td2 = tr.insertCell(2);");
	printf("td2.innerHTML = '<input type=\"text\" name=\"controlport\" value=\"'+'%s'+'\">';\n",tmp3);
	printf("var td3 = tr.insertCell(3);");
	printf("td3.innerHTML = '<input type=\"text\" name=\"protocol\" value=\"'+'%s'+'\">';\n",tmp4);
	printf("var td4 = tr.insertCell(4);\n");
	printf("td4.innerHTML = '<input type=\"text\" name=\"cameraname\" value=\"'+'%s'+'\">';\n",tmp5);
	printf("var td5 = tr.insertCell(5);\n");
	printf("td5.innerHTML = vals[5];\n");
	}}
	printf("},\n");
	printf(" del: function(targetTable, row) {\n");
	printf("var ind = row.parentElement.parentElement.rowIndex;\n");
    printf("targetTable.tBodies[0].deleteRow(ind);\n");
    printf("}\n");
	printf("}\n");

	printf("function submit1(){\n");
	printf("document.camerasetdownload.action=\"camerasetdownload.cgi\";\n");
	printf("document.camerasetdownload.submit();\n");
	printf("}\n");
	printf("function submit2(){\n");
	printf("alert(\"�ϴ��ɹ�\");\n");
	printf("document.camerasetupload.action=\"camerasetupload.cgi\";");
	printf("document.camerasetupload.submit();\n");
	printf("}\n");
	printf("</script>\n");
	printf("</head>\n");
	printf("<body onload='yugi.onload(targetTable)'>\n");
	printf("<iframe name='server' style='display:none;' src=''></iframe>\n");
	printf("<form name='camerasetdownload' method='POST' target='server'>\n");
	printf("<div style=\"width:100%;margin-left:auto;margin-right:auto;border:solid 1px #d7d7d7;\">\n");
	printf("<table>\n");
	printf("<tr><td style='text-align:left;font-weight: bold;'>����һ�������</td></tr>\n");
	printf("</table>\n");

	printf("<table align='center'>\n");
	printf("<tr>\n");
	printf("<td style='width:20%;text-align:right;padding:4pt .5em 4pt 1em;'>IP��ַ��\n");
	printf("</td>\n");
	printf("<td>");
	printf("<input type='text' id='u_ipaddress'>\n");
	printf("</td>\n");
	printf("<td style='width:20%;text-align:right;padding:4pt .5em 4pt 1em;'>���ƶ˿ڣ�\n");
	printf("</td>\n");
	printf("<td>");
	printf("<input type='text' id='u_controlport'>\n");
	printf("</td>\n");
	printf("</tr>\n");

	printf("<tr>\n");
	printf("<td style='width:20%;text-align:right;padding:4pt .5em 4pt 1em;'>Э�飺\n");
	printf("</td>\n");
	printf("<td>");
	printf("<select id='u_protocol'>\n");
	printf("<option>1.NONE</option><option>2.VC</option><option>3.Shany</option><option>4.Sony</option><option>5.Honeywell</option><option>6.GE</option><option>7.Dlink</option>\n");
	printf("<option>8.Axis</option><option>9.Bosch</option><option>10.Panasonic</option><option>11.Sanyo</option><option>12.ȫ��</option><option>13.Ӣ����</option><option>14.����</option>\n");
	printf("<option>15.����ch01</option><option>16.����ch02</option><option>17.����ch03</option><option>18.����ch04</option><option>19.����ch05</option><option>20.����ch06</option>\n");
	printf("<option>21.����ch07</option><option>22.����ch08</option><option>23.����ch09</option><option>24.����ch10</option><option>25.����ch11</option><option>26.����ch12</option>\n");
	printf("<option>27.����ch13</option><option>28.����ch14</option><option>29.����ch15</option><option>30.����ch16</option>\n");
	printf("<option>31.blockcom</option><option>32.hik_ip_cam</option><option>33.ToTa</option><option>34.PELCO</option><option>35.test</option><option>36.vcnvr</option><option>37.vcenc</option>\n");
	printf("<option>38.hikrtsp</option><option>39.CCD</option><option>40.XM</option><option>41.����</option><option>42.����</option>\n");
	printf("<option>43.ΰ��</option><option>44.GB28181</option><option>45.RTP</option><option>46.��</option><option>47.����</option><option>48.vcnvr1</option>\n");
	printf("<option>49.ʩ�߿�</option><option>50.onvif</option><option>51.onvifShany</option><option>52.ToTa</option><option>53.mpeg2</option>\n");
	printf("</select>\n");
	printf("</td>\n");
	printf("<td style='width:20%;text-align:right;padding:4pt .5em 4pt 1em;'>��������ƣ�\n");
	printf("</td>\n");
	printf("<td>");
	printf("<input type='text' id='u_cameraname'>\n");
	printf("</td>\n");
	printf("</tr>\n");
	printf("</table>\n");
	printf("<table style='margin:auto;'>\n");
	printf("<tr>\n");
	printf("<td style='text-align:center;'><input type='button' onclick='yugi.addRow(targetTable)' value='����'></td>\n");
	printf("</tr>\n");
	printf("</table>");
	printf("</div>\n");
	printf("<br>\n");
	printf("<div style=\"width:100%;margin-left:auto;margin-right:auto;border:solid 1px #d7d7d7;\">\n");
	printf("<table>\n");
	printf("<tr><td style='text-align:left;font-weight: bold;'>��ǰ�����</td></tr>\n");
	printf("</table>");
	printf("<table id='targetTable'  align=\"center\">\n");
	printf("<tr>\n");
	printf("<th style='width:150px;text-align:left;'>���</th>\n");
	printf("<th style='width:150px;text-align:left;'>IP��ַ</th>\n");
	printf("<th style='width:150px;text-align:left;'>���ƶ˿�</th>\n");
	printf("<th style='width:150px;text-align:left;'>Э��</th>\n");
	printf("<th style='width:150px;text-align:left;'>���������</th>\n");
	printf("</tr>\n");
	printf("</table>");
	printf("</div>\n");
	printf("<br>");
	printf("<tr><td><input name='hello' value='hello' style='Visibility:hidden'></td></tr>");
	printf("<div style=\"width:100%;text-align:center;\">\n");
	printf("<table style='margin:auto;'>\n");
	printf("<tr>\n");
	printf("<td style='text-align:center;'><input type='button' value='����' onclick='submit1()'></td>\n");
	printf("</form>");
	printf("</tr>\n");
	printf("</table>");
	printf("</div>\n");
	printf("</body>\n");
	printf("</html\n>");
	fclose(fp);
    return 0;
}
