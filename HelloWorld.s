global _start

section .data
	msg db "Hello, World!", 0xa
	len equ $ - msg

section .text
_start:
	mov	rax, 0x2000004
	mov	rdi, 1
	mov	rsi, [rel msg]
	mov rdx, 14
	syscall
	mov rax, 0x2000001
	mov rdi, 0
	syscall