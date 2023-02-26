BITS 64

SECTION .text
global strrchr
global rindex

strrchr:
rindex:
    push rbp
    mov rbp, rsp
    mov rax, 0

.browseLoop:
    cmp byte[rdi], 0x00
    je .decLoop
    inc rax
    inc rdi
    jmp .browseLoop

.decLoop:
    cmp byte[rdi], sil
    je .endLoop
    cmp rax, 0
    je .errorLoop
    dec rdi
    dec rax
    jmp .decLoop

.endLoop:
    mov rax, rdi
    jmp .end

.errorLoop:
    mov rax, 0
    jmp .end

.end:
    mov rsp, rbp
    pop rbp
    ret
