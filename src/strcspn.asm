BITS 64

SECTION .text
global strcspn

strcspn:
    push rbp
    mov rbp, rsp
    mov rax, 0

.loop:
    mov dl, byte[rdi + rax]
    cmp dl, 0x00
    je .endLoop
    mov rcx, 0
    jmp .checkReject

.checkReject:
    cmp byte[rsi + rcx], 0x00
    je .next
    cmp byte[rsi + rcx], dl
    je .endLoop
    inc rcx
    jmp .checkReject

.next:
    inc rax
    jmp .loop

.endLoop:
    mov rsp, rbp
    pop rbp
    ret
