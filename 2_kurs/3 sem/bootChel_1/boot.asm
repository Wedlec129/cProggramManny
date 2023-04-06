BITS 16

section .date
section .bss
x resb 4 ; выделить 3 байта


section .text
global _start
_start:

mov ax,0x7c0
mov ds,ax


mov eax, 3 
mov ebx, 0 
mov ecx, x 
mov edx, 4 
int 0x80
mov eax,[x]
sub eax,0x30




;ds=0x7c0
;es=0xb800
mov ax,0xb800
mov es,ax


 
;это такое приревание
mov ax,3
int 0x10

xor di,di ;занулим di 

;типо вывод
mov si,msg
mov ah,0x0a
; цвет фона 0 and цвет текста a



next:

    lodsb ;ds=si and al=si and  si+
    test al,al ;проверяем что al не нулевой
    js end
    stosw ;ax=es and di=es
    jmp next

end:
    
    jmp $ ; венчный цикл

msg:
    db "'It will not last,' said O'Brien. 'Look me in the eyes. What country is Oceania at war with?' "
   
      

    

    times 510-($-$$) db 0 ;повторить  0 до 510 байт
    dw 0xAA55 ;поcледние 2 байта AA  55

;размер биоса 80 на 25 стррочек

