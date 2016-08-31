#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	printf("content-Type:text/html;charset=gb2312\n\n");
	printf("<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\n");
	printf("<html xmlns=\"http://www.w3.org/1999/xhtml\"><head>\n");
	printf("<meta http-equiv=\"Content-Type\" content=\"text/html; charset=gb2312\" />\n");
	printf("<script type=\"text/javascript\" language=\"javascript\">\n");
	printf("function addOne(){ var showControl = document.getElementById(\"txtNumber\");showControl.value = parseInt(showControl.value) + 1;}");
	printf("function removeOne(){var showControl = document.getElementById(\"txtNumber\");showControl.value = parseInt(showControl.value) - 1;}");
	printf("function addOne1(){var showControl = document.getElementById(\"txtNumber1\");showControl.value = parseInt(showControl.value) + 1;}");
	printf("function removeOne1(){var showControl = document.getElementById(\"txtNumber1\");showControl.value = parseInt(showControl.value) - 1;}");
	printf("function addOne2(){var showControl = document.getElementById(\"txtNumber2\");showControl.value = parseInt(showControl.value) + 1;}");
	printf("function removeOne2(){var showControl = document.getElementById(\"txtNumber2\");showControl.value = parseInt(showControl.value) - 1;}");
	printf("function addOne3(){var showControl = document.getElementById(\"txtNumber3\");showControl.value = parseInt(showControl.value) + 1;}");
	printf("function removeOne3(){var showControl = document.getElementById(\"txtNumber3\");showControl.value = parseInt(showControl.value) - 1;}");
	printf("function addOne4(){var showControl = document.getElementById(\"txtNumber4\");showControl.value = parseInt(showControl.value) + 1;}");
	printf("function removeOne4(){var showControl = document.getElementById(\"txtNumber4\");showControl.value = parseInt(showControl.value) - 1;}");
	printf("function defaultvalue(){document.getElementById(\"txtNumber\").value = 128;document.getElementById(\"txtNumber3\").value = 100;document.getElementById(\"txtNumber1\").value = 128;	document.getElementById(\"txtNumber4\").value = 64;document.getElementById(\"txtNumber2\").value = 128;}");
	printf("function submit1(){document.rtspdownload.action=\"rtspdownload.cgi\";document.rtspdownload.submit();}");
	printf("function submit2(){document.rtspupload.action=\"rtspupload.cgi\";document.rtspupload.submit();}");
	printf("</script>\n");
	printf("</head>\n");
	printf("<body>\n");
	printf("<iframe name='server' style='display:none;' src=''></iframe>\n");
	printf("<form name='rtspdownload' method='POST' target='server'>\n");
	printf("<div style=\"width:100%;margin-left:auto;margin-right:auto;border:solid 1px #d7d7d7;\">\n");
	printf("<table>\n");
	printf("<tr><td style='text-align:left;font-weight: bold;'>网络设置</td></tr>\n");
	printf("</table>\n");
	printf("<table align='center'>\n");
	printf("<tr>\n");
	printf("<td style='width:25%;text-align:right;padding:4pt .5em 4pt 1em;'>组播地址：</td>\n");
	printf("<td><input type='text' name='Muticastaddress'></td>");
	printf("</tr>\n");
	printf("<tr>\n");
	printf("<td style='width:25%;text-align:right;padding:4pt .5em 4pt 1em;'>控制端口号：</td>\n");
	printf("<td><input type='text' name='Controlportnum' value=22222></td>\n");
	printf("<td style='width:25%;text-align:right;padding:4pt .5em 4pt 1em;'>解码器编号：</td>\n");
	printf("<td><select name='decodernum'><option>1</option><option>2</option><option>3</option><option>4</option><option>5</option><option>6</option><option>7</option>");
	printf("<option>8</option><option>9</option><option>10</option><option>11</option><option>12</option><option>13</option><option>14</option><option>15</option><option>16</option>");
	printf("<option>17</option><option>18</option><option>19</option><option>20</option><option>21</option><option>22</option><option>23</option><option>24</option><option>25</option>");
	printf("<option>26</option><option>27</option><option>28</option><option>29</option><option>30</option><option>31</option><option>32</option><option>33</option><option>34</option>");
	printf("<option>35</option><option>36</option><option>37</option><option>38</option><option>39</option><option>40</option><option>41</option><option>42</option><option>43</option>");
	printf("<option>44</option><option>45</option><option>46</option><option>47</option><option>48</option><option>49</option><option>50</option><option>51</option><option>52</option>");
	printf("<option>53</option><option>54</option><option>55</option><option>56</option><option>57</option><option>58</option><option>59</option><option>60</option><option>61</option>");
	printf("<option>62</option><option>63</option><option>64</option><option>65</option><option>66</option><option>67</option><option>68</option><option>69</option><option>70</option></select></td>");
	printf("</tr>\n");
	printf("</table>\n");
	printf("</div>\n");

	printf("<br>");
	printf("<div style=\"width:100%;margin-left:auto;margin-right:auto;border:solid 1px #d7d7d7;\">\n");
	printf("<table>\n");
	printf("<tr><td style='text-align:left;font-weight: bold;'>色彩信息</td></tr>\n");
	printf("</table>\n");
	printf("<table align='center'>\n");

	printf("<tr>\n");
	printf("<td style='text-align:right;padding:4pt .5em 4pt 1em;' rowspan=2>亮度：</td>");
	printf("<td rowspan=2><input type='text' name='brightness' id='txtNumber'/></td>");
	printf("<td><input type='button' value='︿' id='up' onclick='addOne()'/></td>");
	printf("</tr>\n");
	printf("<tr>\n");
	printf("<td><input id='down' type='button' onclick='removeOne()' value='﹀'/></td>");
	printf("</tr>\n");

	printf("<tr>\n");
	printf("<td style='text-align:right;padding:4pt .5em 4pt 1em;' rowspan=2>色调：</td>");
	printf("<td rowspan=2><input type='text' name='tonal' id='txtNumber1'/></td>");
	printf("<td><input type='button' value='︿' id='up' onclick='addOne1()'/></td>");
	printf("</tr>\n");
	printf("<tr>\n");
	printf("<td><input id='down' type='button' onclick='removeOne1()' value='﹀'/></td>");
	printf("</tr>\n");

	printf("<tr>\n");
	printf("<td style='text-align:right;padding:4pt .5em 4pt 1em;' rowspan=2>对比度：</td>");
	printf("<td rowspan=2><input type='text' name='contrast' id='txtNumber2'/></td>");
	printf("<td><input type='button' value='︿' id='up' onclick='addOne2()'/></td>");
	printf("</tr>\n");
	printf("<tr>\n");
	printf("<td><input id='down' type='button' onclick='removeOne2()' value='﹀'/></td>");
	printf("</tr>\n");

	printf("<tr>\n");
	printf("<td style='text-align:right;padding:4pt .5em 4pt 1em;' rowspan=2>cbsaturation：</td>");
	printf("<td rowspan=2><input type='text' name='cb' id='txtNumber3'/></td>");
	printf("<td><input type='button' value='︿' id='up' onclick='addOne3()'/></td>");
	printf("</tr>\n");
	printf("<tr>\n");
	printf("<td><input id='down' type='button' onclick='removeOne3()' value='﹀'/></td>");
	printf("</tr>\n");

	printf("<tr>\n");
	printf("<td style='text-align:right;padding:4pt .5em 4pt 1em;' rowspan=2>crsaturation：</td>");
	printf("<td rowspan=2><input type='text' name='cr' id='txtNumber4'/></td>");
	printf("<td><input type='button' value='︿' id='up' onclick='addOne4()'/></td>");
	printf("</tr>\n");
	printf("<tr>\n");
	printf("<td><input id='down' type='button' onclick='removeOne4()' value='﹀'/></td>");
	printf("</tr>\n");
	printf("<tr>\n");
	printf("<td></td>");
	printf("<td style='text-align:center;'><input type='button' name='ACTION' value='默认值' onclick='defaultvalue()'></td>");
	printf("</tr>\n");
	printf("</table>\n");
	printf("</div>\n");

	printf("<br>");
	printf("<div style=\"width:100%;margin-left:auto;margin-right:auto;border:solid 1px #d7d7d7;\">\n");
	printf("<table>\n");
	printf("<tr><td style='text-align:left;font-weight: bold;'>通道信息</td></tr>\n");
	printf("</table>\n");
	printf("<tr height=100px></tr>");
	printf("</div>\n");

	printf("<br>");
	printf("<div style='text-align:center;'>");
	printf("<table style='margin:auto;'>");
	printf("<tr>\n");
	printf("<td style='text-align:center;'><input type='button' name='ACTION' value='保存' onclick='submit1()'></td></form>\n");
	printf("<td style='width:150px;'></td>");
	printf("<form name='rtspupload' method='POST' ENCTYPE=\"multipart/form-data\">\n");
	printf("<td style='width:300px;text-align:center;'><input type='file' name='FILE1' id='FILE1' style='width:160px'><input type='button' name='ACTION' value='上传文件' onclick='submit2()'></td></form>");
	printf("</tr>\n");
	printf("</table>\n");
	printf("</div>\n");
	printf("</body>\n");
	printf("</html>");
	return 0;
}
