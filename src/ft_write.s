global	_ft_write
SECTION .text

extern ___error	;	as defined in 	
				;	errno.h
				;	extern int * __error(void);
				;	#define errno (*__error())

_ft_write:
	mov		rax, 0x2000004
	syscall
	jc		.error  ; on BSD based OS like macOS CarryFlag (CF) is set whether an error occured  Macos -> Darwin -> BSD -> Unix
	ret

.error:
	mov	r15, rax	; mov the error code that is in rax to r15
	sub rsp, 8		; https://github.com/cirosantilli/x86-assembly-cheat/blob/master/x86-64/calling-convention.md
	call ___error	; sets the adress of the external ___error function in rax (like a function pointer)
	add rsp, 8
	mov	[rax], r15	; [] dereferenced the address in rax to get to the ___error function and give it the error code stored in r15. ___error function now sets the errno variable
	mov	rax, -1		; the c compiler always takes the value in rax to use it as the return value for the c function
	ret