#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
int main()
{
	in_addr_t nip;
	inet_pton(AF_INET,"10.10.113.214",&nip);
	unsigned char*p=(unsigned char*)&nip;
	int i;
	for(i=0;i<4;i++)
	{
		printf("%02d ",*p++);
	}
	char buf[16];
	inet_ntop(AF_INET,&nip,buf,sizeof(buf));
	printf("\n%s\n",buf);
}
