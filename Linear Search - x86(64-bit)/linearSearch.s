
	global linearSearch
	section .data
	
	a	DW	0

	section .text

linearSearch:
	push	rbx
	mov	rbx, 0
	mov	[a], rdx
loop:	cmp	rbx, rsi
	je	done1
	mov	r10d, DWORD[rdi + 4*rbx]
	cmp	r10d, [a]
	je	done
	inc	rbx
	jmp	loop
done1:	mov	rax, -1
	pop 	rbx
	ret
done:	mov	rax, rbx
	pop	rbx
	ret
	
	
