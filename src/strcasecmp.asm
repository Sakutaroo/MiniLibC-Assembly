BITS 64

SECTION .text
global strcasecmp

strcasecmp:
    push rbp
    mov rbp, rsp
    mov rax, 0
    mov rdx, 0
    jmp .loop

 .next:
    inc rcx
    jmp .loop

.loop:
    mov al, byte [rdi + rcx]
    mov dl, byte [rsi + rcx]
    cmp al, 0x00
    je .endLoop
    cmp dl, 0x00
    je .endLoop
    cmp al, dl
    je .next
    jmp .checkDest

.checkDest:
    cmp al, 'A'
    jl .checkSrc
    cmp al, 'Z'
    jg .checkSrc
    add al, 32
    jmp .checkSrc

.checkSrc:
    cmp dl, 'A'
    jl .checkEnd
    cmp dl, 'Z'
    jg .checkEnd
    add dl, 32
    jmp .checkEnd

.checkEnd:
    cmp al, dl
    je .next
    jmp .endLoop

.endLoop:
    sub al, dl
    movsx rax, al
    mov rsp, rbp
    pop rbp
    ret
