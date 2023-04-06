#include <stdio.h>

//это спец константы дифайны  
#ifdef DEBUG_MODE //типо если такой параметр объявлен то ф-я будет так раотать это МАКРОС
#define DEBUG(msg) fprintf(stderr,"[%s:%d] %s: %s\n",__FILE__,__LINE__,__func__,(msg));
#else
#define DEBUG(msg)

#endif  //конц условия  



void function(char *name){

    DEBUG("начало работы ф-я\n");
    printf("hello %s\n",name);
    DEBUG("конец работы ф-я\n");
}


int main()
{
    DEBUG("начало работы main\n");
	function("darlin\n");
    DEBUG("конец работы main\n");
    
    return 0;
}
