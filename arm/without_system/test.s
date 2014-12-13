	.section .text
	.global _start

_start:
	stmfd sp!, {r4, lr}
	
	ldr r0, =str
	ldr r4, =0x43e11434
	mov lr, pc
	bx  r4

	ldmfd sp!, {r4, pc}


str:
	.asciz "Hello, World!\n"


