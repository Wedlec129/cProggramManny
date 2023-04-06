#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
    int cd;
    struct sockaddr_in addr;

    if(0>(cd=socket(AF_INET,SOCK_STREAM,0))){
        perror("Error caling socket");
        return __LINE__;
    }
    

    addr.sin_family=AF_INET;
    addr.sin_port=htons(2022);//port
    addr.sin_addr.s_addr=inet_addr("127.0.0.1");//ip its local || global- 0.0.0.0

    if((-1)==connect(cd,(struct sockaddr *)&addr,sizeof(addr))){
        perror("connet");
        return __LINE__;
    }

    send(cd,"hello,world\n",14,0);
    close(cd);

    printf("hello world in c \n");
    
    
    return 0;
}