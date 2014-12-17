	.global _start
	.text

_start:
	push	{r4-r12,lr}

	@ =================== init
	ldr	r0, =GPM4CON
	ldr r0, [r0]
	ldr	r1, [r0]
	ldr	r2, =0xffff0000
	and	r1, r1, r2
	ldr	r2, =0x1111
	orr	r1, r1, r2
	str	r1, [r0]
	
	ldr	r0, =GPM4DAT
	ldr	r0, [r0]
	ldr	r1, [r0]
	mov	r2, #0xf
	orr	r1, r1, r2
	str	r1, [r0]
	
	@ ====================
	mov	r4, #0
loop:
	cmp	r4, #4
	beq	end_loop

	@ led_on
	ldr	r0, =GPM4DAT
	ldr	r0, [r0]
	ldr	r1, [r0]
	mov	r2, #1
	lsl	r2, r2, r4
	mvn	r2, r2
	and	r1, r1, r2
	str	r1, [r0]

	@ delay
	ldr	r0, =200000
	ldr	r5, =delay
	ldr	r5, [r5]
	blx	r5

	@ led_off
	ldr	r0, =GPM4DAT
	ldr	r0, [r0]
	ldr	r1, [r0]
	mov	r2, #1
	lsl	r2, r2, r4
	orr	r1, r1, r2
	str	r1, [r0]

	@ delay
	ldr	r0, =200000
	ldr	r5, =delay
	ldr	r5, [r5]
	blx	r5


	add	r4, r4, #1
	b	loop
end_loop:

	pop		{r4-r12,pc}



	.data

GPM4CON:
	.word	0x110002e0
GPM4DAT:
	.word	0x110002e4
delay:
	.word	0x43e25e88
