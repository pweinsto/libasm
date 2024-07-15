global _ft_strlen
section .text

_ft_strlen:
	mov rax, rdi

loop:
	cmp byte [rax], 0	; byte to compare one byte at this adress
	je	return
	inc	rax
	jmp loop

return:
	sub rax, rdi
	ret