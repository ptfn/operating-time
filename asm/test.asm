format ELF64
public _start

section '.text' executable
_start:
    add rax, 'A'
    call print_char
    call exit

section '.print_char' executable
print_char:
    push rax

    mov rax, 1 ; 1 - write
    mov rdi, 1 ; 1 - stdout
    mov rsi, rsp ; 
    mov rdx, 1
    syscall

    pop rax

    ret

section '.exit' executable
exit:
    mov rax, 1
    mov rbx, 0 ; xor rbx, rbx
    int 0x80