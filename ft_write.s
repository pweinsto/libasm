global	_ft_write
SECTION .text

_ft_write:
	mov		rax, 0x2000004
	syscall
	ret