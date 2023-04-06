PROGS=simple.exe shared.exe load.exe

all: $(PROGS)

simple.exe: main.o pprint.o
	gcc -o simple.exe main.o pprint.o


#собираем статическую библ \\mac no work
static.exe: main.o libpprint.a
	gcc -o static.exe main.o -static -L. -lpprint 
libpprint.a : pprint.o
	ar cr libpprint.a pprint.o


#собираем динам библ
shared.exe: main.o libpprint.so
	gcc -o static.exe main.o  -L. -lpprint 
libpprint.so : pprint.o
	gcc -shared -fPIC -o libpprint.so pprint.o

# mainLIB.c
# gcc -c mainLIB.c -o mainLIB.o
# gcc -shared -fPIC -o mainLIB.so mainLIB.o
# мы получили so



#собираем динамически через код файл load.c
load.exe: load.o libpprint.so
	gcc -o load.exe load.o -ldl


%.o:%.c
	gcc -c $< -o $@

clean:
	rm -vf *.o *.so *.a *.exe /tmp/libpprint.so *~
