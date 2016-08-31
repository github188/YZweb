#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* getcgidata(FILE* fp,char* requestmethod);
int convert(char *a,int n);
int main()
{
	char *input;
	char *req_method;
	char Muticastaddress[64],Controlportnum[64],decodernum[64],brightness[64],tonal[64],contrast[64],cb[64],cr[64];
	char tmp1[64],tmp2[64],tmp3[64],tmp4[64];
	int i=0,j=0;
	short int pn_value,dn_value;
	int ip_1,ip_2,ip_3,ip_4,bri_value,to_value,con_value,cb_value,cr_value;
	FILE *fp;
	char ch;

/*必加部分*/
	printf("Content-type:text/html\n\n");
//	printf("the following is query result:<br><br>");
	req_method=getenv("REQUEST_METHOD");
	input=getcgidata(stdin,req_method);
/*取Muticastaddress部分值*/
	for(i=16;i<(int)strlen(input);i++)
	{
		if(input[i]=='&')
		{
			Muticastaddress[j]='\0';
			break;
		}
		Muticastaddress[j++]=input[i];
	}

	for(i=32+strlen(Muticastaddress),j=0;i<(int)strlen(input);i++){
		if(input[i]=='&'){
			Controlportnum[j]='\0';
			break;
		}
		Controlportnum[j++]=input[i];
	}
	for(i=44+strlen(Muticastaddress)+strlen(Controlportnum),j=0;i<(int)strlen(input);i++){
		if(input[i]=='&'){
			decodernum[j]='\0';
			break;
		}
		decodernum[j++]=input[i];
	}
		for(i=56+strlen(Muticastaddress)+strlen(Controlportnum)+strlen(decodernum),j=0;i<(int)strlen(input);i++){
		if(input[i]=='&'){
			brightness[j]='\0';
			break;
		}
		brightness[j++]=input[i];
	}
		for(i=63+strlen(Muticastaddress)+strlen(Controlportnum)+strlen(decodernum)+strlen(brightness),j=0;i<(int)strlen(input);i++){
		if(input[i]=='&'){
			tonal[j]='\0';
			break;
		}
		tonal[j++]=input[i];
	}
		for(i=73+strlen(Muticastaddress)+strlen(Controlportnum)+strlen(decodernum)+strlen(brightness)+strlen(tonal),j=0;i<(int)strlen(input);i++){
		if(input[i]=='&'){
			contrast[j]='\0';
			break;
		}
		contrast[j++]=input[i];
	}
		for(i=77+strlen(Muticastaddress)+strlen(Controlportnum)+strlen(decodernum)+strlen(brightness)+strlen(tonal)+strlen(contrast),j=0;i<(int)strlen(input);i++){
		if(input[i]=='&'){
			cb[j]='\0';
			break;
		}
		cb[j++]=input[i];
	}
		for(i=81+strlen(Muticastaddress)+strlen(Controlportnum)+strlen(decodernum)+strlen(brightness)+strlen(tonal)+strlen(contrast)+strlen(cb),j=0;i<(int)strlen(input);i++){
		cr[j++]=input[i];
	}
		cr[j]='\0';
	/*把字符数组转化为int型数字*/
		pn_value=convert(Controlportnum,strlen(Controlportnum));
		dn_value=convert(decodernum,strlen(decodernum));
		bri_value=convert(brightness,strlen(brightness));
		to_value=convert(tonal,strlen(tonal));
		con_value=convert(contrast,strlen(contrast));
		cb_value=convert(cb,strlen(cb));
		cr_value=convert(cr,strlen(cr));
		/*分别取出Muticastaddress数组中每个段的字符*/
		for(i=0,j=0;i<strlen(Muticastaddress);i++){
			if(Muticastaddress[i]=='.'){
				tmp1[j]='\0';
				break;
			}
			tmp1[j++]=Muticastaddress[i];
		}
		for(i=1+strlen(tmp1),j=0;i<strlen(Muticastaddress);i++){
			if(Muticastaddress[i]=='.'){
				tmp2[j]='\0';
				break;
			}
			tmp2[j++]=Muticastaddress[i];
		}
		for(i=2+strlen(tmp1)+strlen(tmp2),j=0;i<strlen(Muticastaddress);i++){
			if(Muticastaddress[i]=='.'){
				tmp3[j]='\0';
				break;
			}
			tmp3[j++]=Muticastaddress[i];
		}
		for(i=3+strlen(tmp1)+strlen(tmp2)+strlen(tmp3),j=0;i<strlen(Muticastaddress);i++){
			tmp4[j++]=Muticastaddress[i];
		}
		tmp4[j]='\0';
		/*ip四个段的值*/
		ip_1=convert(tmp1,strlen(tmp1));
		ip_2=convert(tmp2,strlen(tmp2));
		ip_3=convert(tmp3,strlen(tmp3));
		ip_4=convert(tmp4,strlen(tmp4));

	if((fp=fopen("/param/data/rtsp_config.bin","wb"))==NULL){
		printf("can not open file \n");
		exit(0);
	}
	i=0,j=0;
	fwrite(&ip_4,sizeof(char),1,fp);
	fwrite(&ip_3,sizeof(char),1,fp);
	fwrite(&ip_2,sizeof(char),1,fp);
	fwrite(&ip_1,sizeof(char),1,fp);
	fwrite(&pn_value,sizeof(short int),1,fp);
	fwrite(&dn_value,sizeof(short int),1,fp);
	fwrite(&bri_value,sizeof(char),1,fp);
	fwrite(&to_value,sizeof(char),1,fp);
	fwrite(&con_value,sizeof(char),1,fp);
	fwrite(&cb_value,sizeof(char),1,fp);
	fwrite(&cr_value,sizeof(char),1,fp);
	fwrite(&i,sizeof(short int),1,fp);
	fwrite(&i,sizeof(char),1,fp);
	for(i=0;i<16;i++){
		fwrite(&j,sizeof(int),1,fp);
	}
	i=0;
	fwrite(&i,sizeof(int),1,fp);
	fclose(fp);
	return 0;
}
char* getcgidata(FILE* fp,char* requestmethod)
{
	char* input;
	int len;
	int size=1024;
	int i=0;
/*把传递的值读进input指针*/
	if(!strcmp(requestmethod,"GET"))
	{
		input=getenv("QUERY_STRING");
		return input;
	}
	else if(!strcmp(requestmethod,"POST"))
	{
		len=atoi(getenv("CONTENT_LENGTH"));
		input=(char*)malloc(sizeof(char)*(size+1));

		if(len==0)
		{
			input[0]='\0';
			return input;
		}

		while(1)
		{
			input[i]=(char)fgetc(fp);
			if(i==size){
				input[i+1]='\0';
				return input;
			}
			--len;
			if(feof(fp)||(!(len))){
				i++;
				input[i]='\0';
				return input;
			}
			i++;
		}
	}
	return NULL;
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
