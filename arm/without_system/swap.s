	.section .text
	.global _start

_start:
	@ stmfd sp!, {r4, lr}
	push {r4, lr}

	ldr r0, =a
	ldr r1, =b
	@ mov lr, pc
	bl  swap

	ldr r0, =display

	ldr r1, a
	ldr r2, b
	
	ldr r4, =0x43e11434
	@ mov lr, pc
	blx  r4

	@ ldmfd sp!, {r4, pc}
	pop {r4, pc}


a:
	.word 1

b:
	.word 2

display:
	.asciz "a = %d, b = %d\n"
	.align 2

swap:
	@ stmfd sp!, {r4, r5, lr}
	push {r4, r5, lr}

	ldr r4, [r0]
	ldr r5, [r1]
	str r4, [r1]
	str r5, [r0]

	@ ldmfd sp!, {r4, r5, pc}
	pop {r4, r5, pc}


