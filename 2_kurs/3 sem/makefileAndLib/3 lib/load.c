//мы пытаемься использовать библ so через код
#include <dlfcn.h>
#include <stdio.h>

int main(){

void *(handle);
void *(*pprint)(char*);

handle=dlopen("./libpprint.so",RTLD_LAZY);
if(NULL==handle){
    fprintf(stderr,"ошибка загрузки библ: %s\n",dlerror());
    return -1;
}

pprint=(void(*))dlsym(handle,"pprint");
if(NULL==pprint){
    fprintf(stderr,"ошибка получ ф-я: %s\n",dlerror());
    return -1;
}
else{

pprint("hello from .so");

}

dlclose(handle);
return (NULL==pprint) ? (-1):(0);

}
