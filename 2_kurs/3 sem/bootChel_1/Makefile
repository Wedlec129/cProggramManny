all: buld run

buld:
	nasm -f bin boot.asm -o floppy.img

run:
	qemu-system-i386 -fda floppy.img

#ghex floppy.img 						 16 ричный редактор
#sudo dd if=floppy.img of=/dev/disk5s2 	 скопировать на флешку
