;Adi Pillai, arp3np@virginia.edu, 04/19/2021, "threexplusone.s"

;optimizations: used "sar  rdi, 1" to perform division by 2 in one step 
;used loop unrolling in the main program to run for loop 10x less iterations
;using test to check if a number is even or odd
;using lea to quickly add and multiply numbers in one instruction
;using bit shifts --> 2*rdi + rdi instead of 3*rdi
;eliminated all push and pops from program by using registers
;eliminated need for any registers to be backed up onto the stack
	global threexplusone

	section .data

	c	DQ	0

	section .text

; param 1 - rdi - positive int x
threexplusone:
	cmp	rdi, 1
	je	return
	test	rdi, 1
	jz	isEven
	lea 	rdi, [2*rdi+rdi+ 1]
	call	threexplusone
	add	qword [c], 1
	mov	rax, [c]
	ret
isEven:	sar	rdi, 1
	call	threexplusone
	add	qword [c], 1
	mov	rax, [c]
	ret
return:	mov	rax, [c]
	ret

