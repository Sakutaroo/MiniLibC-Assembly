BITS 64

SECTION .text
global strpbrk

strpbrk:
    push rbp
    mov rbp, rsp
    mov rax, 0
    mov rcx, 0
    mov rdx, rdi
    mov r8b, 0

.loop:
    cmp byte[rdi], 0x00
    jne .findLoop
    jmp .endLoop

.resetFind:
    mov rcx, 0
    inc rdi
    jmp .loop

.findLoop:
    cmp byte[rsi + rcx], 0x00
    je .resetFind
    mov r8b, byte[rsi + rcx]
    cmp r8b, byte [rdi]
    je .setEndLoop
    inc rcx
    jmp .findLoop

.setEndLoop:
    mov rax, rdi
    jmp .endLoop

.endLoop:
    mov rsp, rbp
    pop rbp
    ret
