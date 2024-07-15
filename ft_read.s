global	_ft_read
SECTION .text

extern ___error

_ft_read:
	mov		rax, 0x2000003
	syscall
	jc	.error
	ret

.error:
	mov rcx, rax
	sub rsp, 8
	call ___error
	add rsp, 8
	mov [rax], rcx
	mov rax, -1
	ret