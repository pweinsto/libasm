global	_ft_read
SECTION .text

extern ___error

_ft_read:
	mov		rax, 0x2000003
	syscall
	jc	.error
	ret

.error:
	mov r15, rax
	sub rsp, 8
	call ___error
	add rsp, 8
	mov [rax], r15
	mov rax, -1
	ret