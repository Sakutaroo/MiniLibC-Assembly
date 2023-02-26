BITS 64

SECTION .text
global memcpy

memcpy:
    push rbp
    mov rbp, rsp
    mov cl, 0
    mov r8, 0

.loop:
    cmp rdx, 0
    je .endLoop
    mov cl, byte[rsi + r8]
    mov byte[rdi + r8], cl
    dec rdx
    inc r8
    jmp .loop

.endLoop:
    mov rax, rdi
    mov rsp, rbp
    pop rbp
    ret
