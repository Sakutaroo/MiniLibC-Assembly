BITS 64

SECTION .text
global strncmp

strncmp:
    push rbp
    mov rbp, rsp
    mov rax, 0
    mov rcx, 0
    cmp rcx, rdx
    je .endLoop

.loop:
    mov al, byte[rdi + rcx]
    cmp byte[rdi + rcx], 0x00
    je .checkSource
    cmp byte[rsi + rcx], 0x00
    je .checkDest
    cmp al, byte[rsi + rcx]
    jne .setDiff
    inc rcx
    cmp rcx, rdx
    je .setDiffEqual
    jmp .loop

.checkSource:
    cmp byte[rsi + rcx], 0x00
    jne .setDiffGreater
    jmp .setDiff

.checkDest:
    cmp byte[rdi + rcx], 0x00
    jne .setDiffGreater
    jmp .setDiff

 .setDiff:
    sub al, byte[rsi + rcx]
    movsx rax, al
    jmp .endLoop

 .setDiffEqual:
    sub rcx, 1
    sub al, byte[rsi + rcx]
    movsx rax, al
    jmp .endLoop

.setDiffGreater:
    sub al, byte[rsi + rcx]
    movsx rax, al
    jmp .endLoop

.endLoop:
    mov rsp, rbp
    pop rbp
    ret
