#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
/*
тут мы обращаемься к ядру ОС
и просим его скопировать файл

при старте программы мы имеет 3 открытых файла:
    0)стандартный поток ввода
    1)стандартный поток вывода 
    2)стандартный поток ошибок 
    все след 3++


FUSE (модуль ядра)
*/
int main(){

char buff[32];
 
 //будет новый поток 3
if(open("TEST.txt", O_RDONLY)<0){
    return -1; 
}
//будет новый поток 4
open("TEST_2.txt", O_WRONLY|O_CREAT|O_TRUNC, 0666);

//пищем в 4 поток    
write(4, buff, read(3,buff,32));

close(3);
close(4);


return 0;
}
