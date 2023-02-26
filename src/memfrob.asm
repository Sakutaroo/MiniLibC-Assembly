BITS 64

SECTION .text
global memfrob

memfrob:
    push rbp
    mov rbp, rsp
    mov rdx, 0
    jmp .loop

.loop:
    cmp rsi, rdx
    je .endLoop
    xor byte[rdi + rdx], 42
    inc rdx
    jmp .loop

.endLoop:
    mov rax, rdi
    mov rsp, rbp
    pop rbp
    ret
