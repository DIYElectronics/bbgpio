bbgpio - GPIO in C on BeagleBones
===================================================

bbgpio provides C programs with the ability to enable, disable, read, and write to/from 
GPIO pins on BeagleBone devices.

Although it was written with the BeagleBone Black in mind, it should work with similar devices.

### Compilation and usage:
To compile bbgpio into a static library, simply run
```
git clone http://github.com/DIYElectronics/bbgpio
cd bbgpio
make
```
'libbbgpio.a' will be compiled and left in your working directory.

You can then place it in whatever library folder you please for later linking.

To use libbbgpio, link it to the program you're compiling:
```
gcc yourfile.c /path/to/lib/libbbgpio.a
```

### Documentation:
https://github.com/DIYElectronics/bbgpio/blob/master/documentation.md

### Functionality:
bbgpio is currently limited to enabling, disabling, reading, and writing GPIO pins.

I intend to add more complex functionality later.

### License:
bbgpio is released under the MIT License.