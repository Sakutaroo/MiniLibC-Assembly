BITS 64

SECTION .text
global strchr
global index

strchr:
index:
    push rbp
    mov rbp, rsp
    mov rax, 0

.loop:
    cmp byte[rdi], sil
    je .endLoop
    cmp byte[rdi], 0x00
    je .end
    inc rdi
    jmp .loop

.endLoop:
    mov rax, rdi
    jmp .end

.end:
    mov rsp, rbp
    pop rbp
    ret
