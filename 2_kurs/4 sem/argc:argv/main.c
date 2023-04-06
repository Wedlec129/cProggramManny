#include <stdlib.h> 
#include <stdio.h> 
#include <getopt.h>


//  ./a.out -h -f lol.txt --optb

int main (int argc, char** argv) {

    int a = 20;
    int b = 0;

    const char* short_options = "hf:"; //используем h и f(с параметром) как короткий 
    const struct option long_options[] = {
        {"help",no_argument,NULL,'h'},  //обазначаем длинный параметр
        {"opta",no_argument,&a,100},   //обазначаем длинный параметр типо другой режим
        {"optb",no_argument,&b,-30},
        {"file",required_argument,NULL,'f'},//обазначаем длинный и короткий + принемаем параметр

    };

    int r=0;
    int option_index=0;
    while((r=getopt_long(argc,argv,short_options,long_options,&option_index)) !=-1 ){

        switch(r){
            case  '?': //неизвесный флаг
                printf("you no USE NOT KNOW \n");
                

            case 'h': //флаг хелп
                printf("you use h\n");
                printf("option index = %d,%s,%d,%c\n",
                    option_index,
                    long_options[option_index].name,
                    long_options[option_index].has_arg,
                    long_options[option_index].val
                    );

                break;


            case 'f':// если ксть флаг файла то получаем параметр
                printf("faile = %s\n",optarg);
                break;

        }
    }
    if(argc == 1){
        printf("No arguments!\n");
        return 0;
    }

    printf("a=%d\tb=%d\n",a,b);




    return 0;
}
