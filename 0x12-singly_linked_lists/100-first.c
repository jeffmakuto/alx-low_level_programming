#include <stdio.h>

/**
 * before_main - a function to execute before the main function
 */
void __attribute__((constructor)) before_main(void)
{
	puts("You're beat! and yet, you must allow,");
	puts("I bore my house upon my back!");
}
