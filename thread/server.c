/*	1）服务器：				
	话机：socket				
	绑定号码：bind
	多路分机：listen	
	等待：accept				
	接通（转到分机）：新socket
	总机继续等别的电话，分机跟用户通信
	分机通信：反复write/read		
	挂断分机：close	

*/

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
	//1.话机：socket
	int fd = socket(AF_INET,SOCK_STREAM,0);//ipv4,tcp,protocol
	if(fd<0){perror("sock");return-1;}

	//2.绑定号码：bind
	struct sockaddr_in sockmes;
		sockmess.family=AF_INET;
		sockmess.sin_addr.s_addr = htonl(INADDR_ANY);//INADDR_ANY==0 表示本机ip地址
		sockmess.sin_port = htons(8788);//1024以上 
	int x=bind(fd,(struct sockaddr *)&sockmes,sizeof(si));
	if(x<0){perror("bind");return-1;}

	//多路分机：listen
	listen(fd,10);//允许10个接入请求
	
	//等待：accept,通信
	for(;;)
	{
		struct sockaddr_in c;//存客户的套接信息
		socklen_t len=sizeof(c);//必须初始化成本地套接长度
		int f_new = accept(fd,(struct sockaddr*)&c,&len);//等待客户连接，返回一个和用户连接的新套接字
		if(f_new<0)continue;
		char ip[16];
		inet_ntop(AF_INET,&c.sin_addr,ip,sizeof(ip));
		printf("%s老板光临了！快招待!",ip);
		char msg[1000];
		sprintf(msg,"welcome to GRM`GIRL!");
		write(f_new,msg,strlen(msg));
		close(f_new);
		
	}














}
