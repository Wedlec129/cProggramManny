#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


int main (int argc,char **argv)
{
    
    FILE *fin, *fout;
    
    if(argc !=3+1 ){
        printf("ERROR 228: no find parametr : ./a.out testIN.txt testout.txt lol");
        return 228;
    }
    
    
    
    
    fin =fopen(argv[1], "r");
    if(fin==NULL){printf("ERROR 1488: NOT FINF FILE READ");return 1488;}

    fout=fopen(argv[2], "w");
    
    fseek(fin, 0, SEEK_END);//перемещаем курсок в конец
    int size=ftell(fin); //типо дать размер
    fseek(fin, 0, SEEK_SET);//перемещаем курсок в конец
    
    
    char *text=(char*)malloc(size);
    fread(text, sizeof(char), size, fin);
    
    
    
    char *nado=argv[3];
    
    
    int q=0;
    int nach=0;
    int kon=0;
    for(int i=0; i<size; i++){
        
        
        //printf("%c\n",text[i]);
        if(i==0)nach=-1;
        if(text[i]=='\n'){
            
            nach=i;
            
        }
        
        
        
        if(text[i]==nado[q]){
            
            q++;
        }
        else{
            
            q=0;
        }
        
        
        
        
        if(q==strlen(nado)){
           
            kon=i;
            printf("FIND\n");
            
            
            
           // printf("%d, %d\n",nach,kon);
            
            // типо \n+1
            for(int i=nach+1; i<kon+1; i++){
                
                printf("%c",text[i]);
                fprintf(fout, "%c",text[i]);
                
            }
            
            
            
            
            printf("\n\n");
            
        }
        
        
       
        
        
    }
    
    
    
    
   
     
    
    return 0;
}


