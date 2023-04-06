#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>

//nc 127.0.0.1 2022  подключение 


int main()
{
    int sd,cd;
    struct sockaddr_in addr;

    char msg[14];  
    int msglen;

    sd=socket(AF_INET,SOCK_STREAM,0); // мы хотим использовать ip протоколо и по этому используем AF_inet
                                    //SOCK_STREAM значит что будем передовать данные через поток 
                                    //это получаеться файловый дискриптер открытого сокета 
    if(sd<0){
        perror("Error calling socket");//обработка ошибки
        return __LINE__; //20
    }
    

    addr.sin_family=AF_INET;
    addr.sin_port=htons(2022);//its PORT
    addr.sin_addr.s_addr=inet_addr("127.0.0.1");//ip its local || global- 0.0.0.0

    //bind связывает сокет и адрес и проверяем на ошибку
    if(bind(sd,(struct sockaddr*)&addr,sizeof(addr))<0){
        perror("bind");
        return __LINE__;
        }

    //типо настройка что оект будет слушать какое то значение 
    if(listen(sd,5)){ //максимальное ко-во одноврем пользователей 
        perror("listen");
        return __LINE__;
    }

    //типо если есть посетитель
    //пока это не произойдёт будем на нём висеть
    if(0>(cd=accept(sd,NULL,NULL))){
        perror("acept");
        return __LINE__;
    }


    msglen=recv(cd,msg,14,0);//читаем данные 16 байт и получаем размер считаного
    if(msglen>0) write(1,msg,msglen); //просто вывод инфы как print
    //printf("%s",msg);
    //printf("%d",msglen);


    close(cd);
    close(sd);

    
    return 0;
}