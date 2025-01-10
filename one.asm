section .data
    msg db "Hello, World!", 0Ah

section .text
global _start
_start:
mov eax, 4     ; sys_write
mov ebx, 1     ; file descriptor (stdout)
mov ecx, msg   ; message address
mov edx, 14    ; message length
int 0x80

mov eax, 1     ; sys_exit
xor ebx, ebx   ; status = 0
int 0x80
