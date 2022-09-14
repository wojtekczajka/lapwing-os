section .text
global clear_screen

clear_screen:
    mov eax, 13 
    mov rdi,0
    
    int 0x80

    ret