BITS 64

SECTION .text
global strstr

strstr:
    push rbp
    mov rbp, rsp
    mov rax, rdi
    cmp byte[rsi], 0x00
    je .endLoop
    mov rdx, 0
    jmp .loop

.next:
    inc rdi
    jmp .loop

.loop:
    cmp byte[rdi], 0x00
    je .endNull
    mov cl, byte[rdi]
    cmp cl, byte[rsi]
    jne .next
    mov rdx, 0
    jmp .checkNeedle

.checkNeedle:
    cmp byte[rsi + rdx], 0x00
    je .endSearch
    cmp byte[rdi + rdx], 0x00
    je .endNull
    mov cl, byte[rdi + rdx]
    cmp cl, byte[rsi + rdx]
    jne .next
    inc rdx
    jmp .checkNeedle

.endSearch:
    mov rax, rdi
    jmp .endLoop

.endNull:
    mov rax, 0
    jmp .endLoop

.endLoop:
    mov rsp, rbp
    pop rbp
    ret
