#makefile используем make и оперант
CC=gcc		#для с compaller
CFLAGS:=-Wall #флагт компеляции
LDFLAGS=
LD=$(CC) # доолпр скобки -переменная

PYTHON:=$(shell which python) #получаем путь до питона shell топо bash 


all: main.exe  # если было написано make all то вызываем main.exe(1)
#что бы выполнить алл нужно выполнить мейн

echo: # если было написано make echo то путь до питона 
	echo "${PYTHON}"

noecho: # @ типо уменшает вывод и оставляет самое главное
	@echo "${PYTHON}" 
	

main.exe: main.o # если вызвали main.exe(1) то вызываем как зависимость main.o
	@echo "[LD] main.exe"
	@$(LD) -o main.exe main.o $(LDFLAGS)

%.o:%.c #цель удовлетворяющаяя все имена .о и .с
	@echo "[CC] $@"
	@$(CC) $(CFLAGS) -c $< -o $@
#в мейке < значит слева    @ справа main.o


#make all
#[CC] main.o   == gcc -Wall -c main.c -o main.o
#[LD] main.exe == gcc -o main.exe main.o



python: main.py #для запуска питона должен быть мейн.пай
	@echo "[EXE python script"
	@$(PYTHON) main.py
#просто запускаем 

clean:
	@echo "Clean project"
	@rm -fv *.o *.exe *~
#удаляем все .о файлы .ехе и все временные файлы
