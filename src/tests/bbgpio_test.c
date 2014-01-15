/*	bbgpio_test.c
	Author: William Woodruff
	-------------

	Test file for bbgpio's functions. 
*/

#include "bbgpio.h"
#include <stdio.h>

int main(void)
{
	export_gpio_pin(1);
	unexport_gpio_pin(1);
	return 0;
}