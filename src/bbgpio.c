/*	bbgpio.c
	Author: William Woodruff
	-------------

	Provides functions for GPIO input and output for the BeagleBone [Black].
	Licensed under the MIT License. See the 'LICENSE' file for more information.
*/

#include "bbgpio.h"
#include <stdio.h>
#include <stdlib.h>

/*	export_gpio_pin
	args: uint pin
	attempts to export the GPIO pin indicated by the argument.
	returns EXIT_SUCCESS on success, ERR_EXPORT_PIN on failure.
*/
int export_gpio_pin(unsigned int pin)
{
	FILE* export_file = fopen(GPIO_EXPORT_FILE, "a");

	if (export_file == NULL)
	{
		return ERR_EXPORT_PIN;
	}

	fprintf(export_file, "%d", pin);

	fclose(export_file);

	return EXIT_SUCCESS;
}

/*	unexport_gpio_pin
	args: uint pin
	attempts to unexport the GPIO pin indicated by the argument.
	returns EXIT_SUCCESS on success, ERR_UNEXPORT_PIN on failure.
*/
int unexport_gpio_pin(unsigned int pin)
{
	FILE* unexport_file = fopen(GPIO_UNEXPORT_FILE, "a");

	if (unexport_file == NULL)
	{
		return ERR_UNEXPORT_PIN;
	}

	fprintf(unexport_file, "%d", pin);

	fclose(unexport_file);

	return EXIT_SUCCESS;
}

/*	get_pin_value
	args: uint pin, uint* val
	attempts to retrieve the value of the indicated GPIO pin and store it in val.
	returns EXIT_SUCCESS on success, ERR_GET_PIN_VALUE on failure
*/
int get_pin_value(unsigned int pin, unsigned int* val)
{
	FILE* pin_file;
	char pin_value_path[MAX_STRLEN];
	snprintf(pin_value_path, MAX_STRLEN, GPIO_ROOT_DIR "gpio%d/value", pin);

	pin_file = fopen(pin_value_path, "r");

	if (pin_file == NULL)
	{
		return ERR_GET_PIN_VALUE;
	}

	char c = fgetc(pin_file);

	if (c != '0')
	{
		*val = 1;
	}

	else
	{
		*val = 0;
	}

	return EXIT_SUCCESS;
}

/*	set_pin_value
	args: uint pin, uint val
	attempts to set the value of the indicated GPIO pin to val
	Note: values not equal to 0 will be set to 1 (HIGH), and 0 will be set to 0 (LOW)
	returns EXIT_SUCCESS on success, ERR_SET_PIN_VALUE on failure
*/
int set_pin_value(unsigned int pin, unsigned int val)
{
	FILE* pin_file;
	char pin_direction_path[MAX_STRLEN];
	char pin_value_path[MAX_STRLEN];
	snprintf(pin_direction_path, MAX_STRLEN, GPIO_ROOT_DIR "gpio%d/direction", pin);
	snprintf(pin_value_path, MAX_STRLEN, GPIO_ROOT_DIR "gpio%d/value", pin);

	pin_file = fopen(pin_direction_path, "a");

	if (pin_file == NULL)
	{
		return ERR_GET_PIN_VALUE;
	}

	fputs("high", pin_file);

	fclose(pin_file);

	pin_file = fopen(pin_value_path, "a");

	if (pin_file == NULL)
	{
		return ERR_SET_PIN_VALUE;
	}

	fprintf(pin_file, "%d", (val) ? 1 : 0);

	fclose(pin_file);

	return EXIT_SUCCESS;
}

