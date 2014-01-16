bbgpio documentation
====================

# Functions:

## int export_gpio_pin(unsigned int pin)
Exports the GPIO pin indicated by the "pin" argument.
This function must be called before any I/O can occur on a given pin.
Returns an int whose value is either EXIT_SUCCESS or ERR_EXPORT_PIN

## int unexport_gpio_pin(unsigned int pin)
Unexports the GPIO pin indicated by the "pin" argument.
This function should be called after completing all activity on a given pin.
Failure to call this function may leave GPIO pins open and active.
Returns an int whose value is either EXIT_SUCCESS or ERR_UNEXPORT_PIN

## int get_pin_value(unsigned int pin, unsigned int* val)
Gets the value (1-HIGH/0-LOW) associated with the given "pin" argument and stores it in val.
Returns an int whose value is either EXIT_SUCCESS or ERR_GET_PIN_VALUE

## int set_pin_value(unsigned int pin, unsigned int val)
Sets the value of the given "pin" argument to the value of the "val" argument.
If "val" is not equal to 0, the pin's value is set to HIGH (1). 
If "val" is zero, the pin's value is set to LOW (0).
Returns an int whose value is either EXIT_SUCCESS or ERR_SET_PIN_VALUE
