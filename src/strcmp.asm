BITS 64

SECTION .text
global strcmp

strcmp:
    push rbp
    mov rbp, rsp
    mov rax, 0
    mov rdx, 0
    mov rcx, 0
    mov r8b, 0

.loopLength:
    cmp byte [rdi + rdx], 0x00
    je .checkSourceLength
    cmp byte [rsi + rdx], 0x00
    je .checkDestLength
    inc rdx
    jmp .loopLength

.checkSourceLength:
    cmp byte[rsi + rdx], 0x00
    je .loop
    mov rax, -1
    jmp .endLoop

.checkDestLength:
    cmp byte[rdi + rdx], 0x00
    je .loop
    mov rax, 1
    jmp .endLoop

.loop:
    mov r8b, byte[rdi + rcx]
    cmp r8b, 0x00
    je .setEqual
    cmp r8b, byte[rsi + rcx]
    jne .setDiff
    inc rcx
    jmp .loop

.setDiff:
    cmp r8b, byte[rsi + rcx]
    jl .setLess
    jmp .setGreater

.setLess:
    mov rax, -1
    jmp .endLoop

.setGreater:
    mov rax, 1
    jmp .endLoop

.setEqual:
    mov rax, 0
    jmp .endLoop

.endLoop:
    mov rsp, rbp
    pop rbp
    ret
