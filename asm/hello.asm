format ELF64 executable
entry _start

newline equ 0xA
msg db "Hello world", newline, 0
len = $-msg

_start:
    mov rax, 4
    mov rbx, 1
    mov rcx, msg
    mov rdx, len
    int 0x80
    call exit

exit:
    mov rax, 1
    mov rbx, 0
    int 0x80
