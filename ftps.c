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
	struct sockaddr_in serv,cli;
	char s[1000];int id,id1;
	id=socket(AF_INET,SOCK_STREAM,0);
	if(id<0)
	{
		printf("socket was not created\n");exit(1);
	}
	printf("socket was created\n");
	serv.sin_family=AF_INET;
	serv.sin_addr.s_addr=htonl(INADDR_ANY);
	serv.sin_port=htons(5014);
	int b=bind(id,(struct sockaddr *)&serv,sizeof(serv));
	if(b!=0)
	{printf("socket was not binded\n");exit(1);}
	listen(id,5);
	int size=sizeof(cli);
	id1=accept(id,(struct sockaddr *)&cli,&size);
	if(id1<0)
	{printf("socket was not accept\n");exit(1);}
	read(id1,s,1000);
	int fp=open(s,O_RDWR);
	int n=10;
		n=read(fp,s,1000);
		s[n]='\0';
		write(id1,s,sizeof(s)+1,0);
		//printf("%d\n",n);
		//printf("%d\n",n);
/*	printf("the client sent message is:%s\n",s);
		scanf("%s",s);
	write(id1,s,sizeof(s),0);*/
}
