global _ft_strcpy
section .text

_ft_strcpy:
	mov	rax, rdi
	sub	rsi, rdi					; get distance of rsi to rdi to only need to inc rdi in the loop

loop:
	mov		dl, byte [rdi + rsi]
	mov 	byte [rdi], dl
	inc		rdi
	test	dl, dl
	jnz		loop

	ret