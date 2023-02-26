BITS 64

SECTION .text
global memset

memset:
    push rbp
    mov rbp, rsp
    mov rax, rdi

.loop:
    cmp rdx, 0
    je .endLoop
    mov byte[rdi], sil
    inc rdi
    dec rdx
    jmp .loop

.endLoop:
    mov rsp, rbp
    pop rbp
    ret
