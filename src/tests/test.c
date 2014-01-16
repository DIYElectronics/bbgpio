/* quick tests for bbgpio

	expected output:
	0 0 0 0 pin val: 1

	recieved output:
	0 0 0 0 pin val: 1
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int pinval = 0;

    int ret1 = export_gpio_pin(1);
    int ret2 = set_pin_value(1, 1);
    int ret3 = get_pin_value(1, &pinval);
    int ret4 = unexport_gpio_pin(1);

    printf("%d %d %d %d pin val: %d\n", ret1, ret2, ret3, ret4, pinval);

    return EXIT_SUCCESS;
}
