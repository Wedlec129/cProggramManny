#include <stdlib.h> 
#include <stdio.h> 
#include <getopt.h>


int main (int argc, char** argv) {

    //int a = 20;
    //int b = 0;

    const char* short_options = "hf:d"; //используем h и f(с параметром) как короткий 
    const struct option long_options[] = {
        {"debag",no_argument,NULL,'d'},  //обазначаем длинный параметр
        {"help",no_argument,NULL,'h'},  //обазначаем длинный параметр
        {"file",required_argument,NULL,'f'},//обазначаем длинный и короткий + принемаем параметр

    };

    int r=0;
    int option_index=0;

    int used_faile=0;
    int used_D=0;

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

                printf("you can use fille(-f text.txt) OR debagg(-d) \n");
                printf("you canNT use botch parametrs \n");


                break;


            case 'f':// если ксть флаг файла то получаем параметр

                if(used_faile==0 && used_D==0){
                    printf("faile = %s\n",optarg);
                    used_faile=1;
                    }
                else{
                    printf("EEEROR 6666666");
                    return 66666666;
                    }
                break;

            case 'd':

                if(used_D==0 && used_faile==0){
                    printf("USE DEBBAGS MODE!!!!\n");
                    used_D=1;
                    }
                else{
                    printf("EEEROR -2");
                    return -2;
                    }
                break;



        }
    }
    if(argc == 1){
        printf("No arguments!\n");
        return 0;
    }

    //printf("a=%d\tb=%d\n",a,b);




    return 0;
}
