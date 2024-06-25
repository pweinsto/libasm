global _HelloWorld

section .data
	msg db "Hello, World!", 0xa
	len equ $ - msg

section .text
_HelloWorld:
	mov	rax, 0x2000004
	mov	rdi, 1
	mov	rsi, msg
	mov rdx, len
	syscall
	ret
