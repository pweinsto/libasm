global	_ft_strcmp
section	.text

_ft_strcmp:
	xor	rax, rax
	xor	rdx, rdx
	
loop:
	mov	al, byte [rdi]
	mov	dl, byte [rsi]
	test	al, al
	jz	.testdl
	inc	rdi
	inc rsi
	sub	rax, rdx
	jz	loop
	;js	.negative
	;mov	rax, 1
	ret

.testdl:
	test	dl, dl
	jz	.return
	inc	rdi
	inc rsi
	sub	rax, rdx
	jz	loop
	ret

;.negative:
;	mov	rax, -1

.return:
	ret
