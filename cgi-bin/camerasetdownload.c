#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int convert(char *a,int n);
int main()
{
	char *input=NULL;
	char *req_method;
	char string_ip[16]={0},string_port[16]={0},string_protocol[16]={0},string_cameraname[32]={0};
	int i=0,j=0,length=0,count=0;
	char *p=NULL,*q=NULL,*len=NULL,*len1=NULL,*len2=NULL,*len22=NULL,*len3=NULL;
	FILE *fp,*fp1,*fp2;
	char *tmp=NULL;
	char tmp1[16],tmp2[16],tmp3[16],tmp4[16],st[16]={0};
	int ip_1=0,ip_2=0,ip_3=0,ip_4=0,port_value=0,protocol_value=0;

/*必加部分*/
	printf("Content-type:text/html;charset=gb2312\n\n");
//	printf("the following is query result:<br><br>");
	
	if(getenv("CONTENT_LENGTH")){
		length=atoi(getenv("CONTENT_LENGTH"));
		input=(char*)malloc(length*sizeof(char));
		memset(input, 0x00, sizeof(input));
		for(i=0;i<length;i++)
			*(input+i)=getchar();
	}
	//printf(input);
	for(i=0;i<strlen(input);i++){
		if(input[i]=='n'&&input[i+1]=='a'&&input[i+2]=='m'&&input[i+3]=='e'){
			count++;
		}
	}
	//printf("%d",count);
	if((fp=fopen("/param/data/cam.bin","wb"))==NULL){
		printf("can not open file \n");
		exit(0);
	}
	if((fp1=fopen("/param/data/cam_title.bin","wb"))==NULL){
		printf("can not open file \n");
		exit(0);
	}
	if((fp2=fopen("/param/data/cam_config.txt","w"))==NULL){
		printf("can not open file \n");
		exit(0);
	}
	len=(char*)malloc((strlen(input))*sizeof(char));
	memset(len, 0x00, sizeof(len));
	len1=(char*)malloc((strlen(input))*sizeof(char));
	memset(len1, 0x00, sizeof(len1));
	len2=(char*)malloc((strlen(input))*sizeof(char));
	memset(len2, 0x00, sizeof(len2));
	len22=(char*)malloc((strlen(input))*sizeof(char));
	memset(len22, 0x00, sizeof(len22));
	len3=(char*)malloc((strlen(input))*sizeof(char));
	memset(len3, 0x00, sizeof(len3));
if(count==0){
		exit(0);
	}
else{
	string_ip[0]='i';string_ip[1]='p';string_ip[2]='a';string_ip[3]='d';string_ip[4]='d';string_ip[5]='r';string_ip[6]='e';string_ip[7]='s';string_ip[8]='s';
	string_port[0]='c';string_port[1]='o';string_port[2]='n';string_port[3]='t';string_port[4]='r';string_port[5]='o';string_port[6]='l';string_port[7]='p';string_port[8]='o';string_port[9]='r';string_port[10]='t';
	string_protocol[0]='p';string_protocol[1]='r';string_protocol[2]='o';string_protocol[3]='t';string_protocol[4]='o';string_protocol[5]='c';string_protocol[6]='o';string_protocol[7]='l';
	string_cameraname[0]='c';string_cameraname[1]='a';string_cameraname[2]='m';string_cameraname[3]='e';string_cameraname[4]='r';string_cameraname[5]='a';string_cameraname[6]='n';string_cameraname[7]='a';string_cameraname[8]='m';string_cameraname[9]='e';

	fputs("1",fp2);
	fputs(",",fp2);
	/*找到ipaddress在input字符串中的起始位置*/
	p=strstr(input,string_ip);
	sscanf(p+10,"%[^&]",len);
	//printf(len);
	fputs(len,fp2);
	fputs(",",fp2);
	sscanf(len,"%[^.].%[^.].%[^.].%s",tmp1,tmp2,tmp3,tmp4);
	ip_1=convert(tmp1,strlen(tmp1));ip_2=convert(tmp2,strlen(tmp2));ip_3=convert(tmp3,strlen(tmp3));ip_4=convert(tmp4,strlen(tmp4));
	fwrite(&ip_4,sizeof(char),1,fp);
	fwrite(&ip_3,sizeof(char),1,fp);
	fwrite(&ip_2,sizeof(char),1,fp);
	fwrite(&ip_1,sizeof(char),1,fp);
	/*找到controlport在input字符串中的起始位置*/
	string_port[0]='c';string_port[1]='o';string_port[2]='n';string_port[3]='t';string_port[4]='r';string_port[5]='o';string_port[6]='l';string_port[7]='p';string_port[8]='o';string_port[9]='r';string_port[10]='t';
	p=strstr(input,string_port);
	sscanf(p+12,"%[^&]",len1);
	fputs(len1,fp2);
	fputs(",",fp2);
	port_value=convert(len1,strlen(len1));
	fwrite(&port_value,sizeof(short int),1,fp);
	/*找到protocol在input字符串中的起始位置*/
	p=strstr(input,string_protocol);
	sscanf(p+9,"%[^.]",len2);
	sscanf(p+9,"%[^&]",len22);
	fputs(len22,fp2);
	fputs(",",fp2);
	protocol_value=convert(len2,strlen(len2));
	protocol_value=protocol_value-1;
	fwrite(&protocol_value,sizeof(char),2,fp);
	j=0;
	fwrite(&j,sizeof(int),1,fp);
	/*找到cameraname在input字符串中的起始位置*/
	p=strstr(input,string_cameraname);
	sscanf(p+11,"%[^&]",len3);
	for(j=0;j<strlen(len3);j++){
		st[j]=len3[j];
	}
	fputs(st,fp2);
	fputs("\n",fp2);
	fwrite(st,sizeof(char),16,fp1);
	p=p+11+strlen(len3)+1;
	for(i=2;i<=count;i++){
		memset(len, 0x00, sizeof(len));
		memset(len1, 0x00, sizeof(len1));
		memset(len2, 0x00, sizeof(len2));
		memset(len22, 0x00, sizeof(len22));
		memset(len3, 0x00, sizeof(len3));
		memset(tmp1,0x00,sizeof(tmp1));memset(tmp2,0x00,sizeof(tmp2));memset(tmp3,0x00,sizeof(tmp3));memset(tmp4,0x00,sizeof(tmp4));
		memset(st,0x00,sizeof(st));
		fprintf(fp2,"%d",i);
		fputs(",",fp2);
		/*找到ipaddress在p指向字符串中的起始位置*/
		q=strstr(p,string_ip);
		sscanf(q+10,"%[^&]",len);
		//printf(len);
		fputs(len,fp2);
		fputs(",",fp2);
		sscanf(len,"%[^.].%[^.].%[^.].%s",tmp1,tmp2,tmp3,tmp4);
		ip_1=convert(tmp1,strlen(tmp1));ip_2=convert(tmp2,strlen(tmp2));ip_3=convert(tmp3,strlen(tmp3));ip_4=convert(tmp4,strlen(tmp4));
		fwrite(&ip_4,sizeof(char),1,fp);
		fwrite(&ip_3,sizeof(char),1,fp);
		fwrite(&ip_2,sizeof(char),1,fp);
		fwrite(&ip_1,sizeof(char),1,fp);
		p=p+10+strlen(len)+1;
		/*找到controlport在p指向字符串中的起始位置*/
		q=strstr(p,string_port);
		sscanf(q+12,"%[^&]",len1);
		fputs(len1,fp2);
		fputs(",",fp2);
		port_value=convert(len1,strlen(len1));
		fwrite(&port_value,sizeof(short int),1,fp);
		p=p+12+strlen(len1)+1;
		/*找到protocol在p指向字符串中的起始位置*/
		q=strstr(p,string_protocol);
		sscanf(q+9,"%[^.]",len2);
		sscanf(q+9,"%[^&]",len22);
		fputs(len22,fp2);
		fputs(",",fp2);
		protocol_value=convert(len2,strlen(len2));
		protocol_value=protocol_value-1;
		fwrite(&protocol_value,sizeof(char),2,fp);
		p=p+9+strlen(len22)+1;
		j=0;
		fwrite(&j,sizeof(int),1,fp);
		/*找到cameraname在p指向字符串中的起始位置*/
		q=strstr(p,string_cameraname);
		sscanf(q+11,"%[^&]",len3);
		for(j=0;j<strlen(len3);j++){
			st[j]=len3[j];
		}
		fputs(st,fp2);
		fputs("\n",fp2);
		fwrite(st,sizeof(char),16,fp1);
		p=p+11+strlen(len3)+1;
	}
}
	fclose(fp);
	fclose(fp1);
	free(len);
	free(len1);
	free(len2);
	free(len22);
	free(len3);
	return 0;
}

int convert(char *a,int n){
	int ref,tmp,sum;
	for(tmp=0,sum=0;tmp<n;tmp++){
		sum*=10;
		ref=a[tmp]-'0';
		sum+=ref;
	}
	return sum;
}
