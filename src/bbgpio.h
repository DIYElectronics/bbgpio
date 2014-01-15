/*	bbgpio.h
	Author: William Woodruff
	-------------

	Provides headers, macros, and prototypes used in bbgpio.c.
*/

#ifndef BBGPIO_H
#define BBGPIO_H

#include "bbgpio_error.h"

#define GPIO_ROOT_DIR "/sys/class/gpio/"
#define GPIO_EXPORT_FILE "/sys/class/gpio/export"
#define GPIO_UNEXPORT_FILE "/sys/class/gpio/unexport"
#define MAX_STRLEN 128

/* export/unexport prototypes */
int export_gpio_pin(unsigned int pin);
int unexport_gpio_pin(unsigned int pin);

/* read/write prototypes */
int get_pin_value(unsigned int pin, unsigned int* val);
int set_pin_value(unsigned int pin, unsigned int val);

#endif /* BBGPIO_H */