	.section .text
	.global _start

	.equ PRINTF, 0x43e11434

_start:
	push {r4, lr}

	adr r0, s1
	adr r1, s2

	bl strcmp

	mov r1, r0
	adr r0, display
	ldr r4, =PRINTF
	blx r4

	pop {r4, pc}


s1:
	.asciz "4345"
	.align 2
s2:
	.asciz "23"
	.align 2

display:
	.asciz "result = %d\n"
	.align 2

strcmp:
	push {r4, r5, r6, lr}

loop_cmp:
	ldrb r4, [r0], #1
	ldrb r5, [r1], #1
	cmp r4, #0
	beq loop_cmp_end
	cmp r5, #0
	beq loop_cmp_end
	cmp r4, r5
	beq loop_cmp
loop_cmp_end:
	sub r6, r4, r5
	mov r0, r6

	pop {r4, r5, r6, pc}

