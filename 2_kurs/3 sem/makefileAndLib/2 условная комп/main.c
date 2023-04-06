#include <stdio.h>

//это спец константы дифайны  
#ifndef MY_NAME //типо если такая переменная задефвайнена [] типо если не обявлена -обявим
#define MY_NAME "World" //даём значение
#endif  //конц условия  

int main()
{
	
	int a=10;	
	
	printf("hello world in c | %s     \n",MY_NAME);
    printf("%d",a);
    
    return 0;
}
