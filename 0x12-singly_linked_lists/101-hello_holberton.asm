global main
main:
	mov rdi, msg
	mov eax, 0
	extern printf
	call printf
	mov eax, 0
	ret
section .rodata
msg:
	db "Hello, Holberton", 10, 0
