	.arch msp430g2553
	.p2align 1,0
	.text

	.extern red_on
	.extern green_on
	.extern led_changed
	.extern redVal
	.extern greenVal

led_init:
	bis &LEDS, &P1DIR
	mov #1, &led_changed
	call #led_update
	pop r0

led_update:
	cpm #0, &led_changed
	jz zero

	sub #1, r1

	mov &redVal, r5
	add &red_on, r5

	mov &greenVal, r6
	add &green_on, r6

	mov.b 0(r5), 0(r1)
	bis.b 0(r6), 0(r1)
	

	

zero:
	pop r0
