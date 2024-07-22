extern _malloc
extern _ft_strlen
extern _ft_strcpy

global _ft_strdup
section .text

_ft_strdup:
	call _ft_strlen
	push rdi
	mov	rdi, rax
	inc	rdi
	call _malloc
	pop rsi
	test rax, rax
	jz .error
	mov rdi, rax
	call _ft_strcpy
	ret

.error:
	ret