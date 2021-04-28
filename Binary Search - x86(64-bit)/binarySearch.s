	global binarySearch:
	
	section .text
	
binarySearch:
	mov	r11, rdx
	sub	r11, rsi
	mov	r8, r11
	sar	r11, 1
	lea	r10, [rsi + r11]
	cmp	ecx, DWORD[4*r10 + rdi]
	je	done
	cmp	rsi, rdx
	je	done2
	cmp	ecx, DWORD[4*r10 + rdi]
	jg      great
	cmp	r8, 1
	je 	done2
	sub	r10, 1
	mov	rdx, r10
	call	binarySearch
	ret
great:	inc	r10
	mov	rsi, r10
	call	binarySearch
	ret
done:	mov	rax,  r10
	ret
done2:	mov	rax, -1
	ret
	
