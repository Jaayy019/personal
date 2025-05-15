; Jacob Sambor - hw11translate2Ascii.asm

section .data
	inputBuf db 0x83, 0x6A, 0x88, 0xDE, 0x9A, 0xC3, 0x54, 0x9A
	
section .bss
	outputBuf resb 80

section .text
	global _start

_start:
	
	; Indicies to track how many pairs we have done
	mov esi, 0
	mov edi, outputBuf

translate:

	; Moves to the done label if we have already translated all of the pairs
	cmp esi, 8
	jge done

	; Gets the first pair
	mov al, [esi + inputBuf]

	; Splices off the first character using shr, removes the last 4 bits
	mov ah, al
	shr ah, 4
	mov al, ah

	; Calls the function to translate, then moves it to the output
	call toAscii
	mov [edi], al
	inc edi

	; Splices off the last character using and, removes the first 4 bits
	mov al, [esi + inputBuf]
	and al, 0x0F
	
	; Calls the function to translate, then moves it to the output
	call toAscii
	mov [edi], al
	inc edi

	; Adds a space after each pair has been translated
	mov byte [edi], 0x20
	inc edi

	inc esi
	jmp translate

done:

	; Gets rid of the last space with a new line
	mov byte [edi], 0x0A
	inc edi

	; Gets the output length and stores it in eax
	mov eax, edi
	sub eax, outputBuf

	; Printing the pairs
	mov edx, eax
	mov ecx, outputBuf
	mov ebx, 1
	mov eax, 4
	int 0x80

	; Exit program
	mov eax, 1
	xor ebx, ebx
	int 0x80

toAscii:
	
	; If the character is equal to or less than 9, sends to digitToAscii
	cmp al, 9
	jbe digitToAscii
	
	; Converts into ASCII character (10-15, A-F)
	add al, 0x37
	ret

digitToAscii:
	
	; Converts digit to ASCII character
	add al, 0x30
	ret

