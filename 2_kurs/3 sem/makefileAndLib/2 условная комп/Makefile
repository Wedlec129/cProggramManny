#makefile используем make и оперант
CC=gcc		#для с compaller


all:
	@echo "Usage: "
	@echo "main -just a programm "
	@echo "custom -programm witch key"

main:
	$(CC) main.c

custom:
	$(CC) -DMY_NAME="\"ITS change define var"\" main.c
#тут на этапе компеляции обявляем дифайн майн нейм и добавляем значение 
#gcc -DMY_NAME="\"ITS change define var"\" main.c   

debug:
	$(CC) -DDEBUG_MODE debug.c

relise:
	$(CC) debug.c

#типо взлом
hack: main.c
	$(CC) -DMY_NAME="({char* msg;fprintf(stderr,\"this progg hack\\n\");msg=\"hack\";})" main.c
#define MY_NAME ({char* msg;fprintf(stderr,\"this progg hack\\n\");msg=\"hack\";})
#типо sql инъекция макрос раен переменной + запускаем код +меняем ту переменнную


clean:
	@echo "Clean project"
	@rm -fv *.o *~ a.out
#удаляем все .о файлы .ехе и все временные файлы
