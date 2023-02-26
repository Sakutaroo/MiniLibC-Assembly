BITS 64

SECTION .text
global strlen

strlen:
    push rbp
    mov rbp, rsp
    mov rax, 0

.loop:
    cmp byte[rdi + rax], 0x00
    je .endLoop
    inc rax
    jmp .loop

.endLoop:
    mov rsp, rbp
    pop rbp
    ret
