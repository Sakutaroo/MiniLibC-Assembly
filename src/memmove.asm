BITS 64

SECTION .text
global memmove

memmove:
    mov rcx, 0
    cmp rdi, 0x00
    je .end
    cmp rsi, 0x00
    je .end
    cmp rdi, rsi
    jl .lowerLoop
    jmp .greaterLoop

.lowerLoop:
    cmp rcx, rdx
    je .end
    mov r8b, byte[rsi + rcx]
    mov byte[rdi + rcx], r8b
    inc rcx
    jmp .lowerLoop

.greaterLoop:
    cmp rdx, 0
    je .end
    mov r8b, byte[rsi + rdx - 1]
    mov byte[rdi + rdx - 1], r8b
    dec rdx
    jmp .greaterLoop

.end:
    mov rax, rdi
    ret
