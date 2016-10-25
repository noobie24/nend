#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	struct sockaddr_in serv;	
	int id,id1,size;
	id=socket(AF_INET,SOCK_STREAM,0);
	serv.sin_family=AF_INET;
	serv.sin_addr.s_addr=inet_addr("127.0.0.1");
	serv.sin_port=htons(5014);
	char s[1000];
	scanf("%s",s);
	connect(id,(struct sockaddr *)&serv,sizeof(serv));
	write(id,s,sizeof(s),0);
	int n=read(id,s,1000);
	s[n]='\0';
	char a[100];
	printf("enter new file name:");
	scanf("%s",a);
	//int fp=open("thala.txt",O_RDWR);
	FILE *fp=fopen(a,"w+");
		//n=read(fp,s,1000);
		//write(fp,s,sizeof(s)+1);
		fprintf(fp,"%s",s);
	printf("%s",s);	
}
