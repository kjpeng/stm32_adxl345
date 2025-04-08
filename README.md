# STM32_ADXL345
Creates an STM32 library for use with the ADXL345 (accelerometer) based
heavily off of @Amin98Hosseini's [ADXL345_STM32](https://github.com/Amin98Hosseini/ADXL345_STM32) as
well as [Adafruit_ADXL345](https://github.com/adafruit/Adafruit_ADXL345).
Specifically, this is for use with my [BasicBoard-STM32G473CET6 board](https://github.com/kjpeng/BasicBoard-STM32G473CET6), which uses I2C2 pins
PA8 (I2C2_SDA) and PA9 (I2C2_SCL), though that is set in the main.cpp file,
so this library can be adapted for use with other boards as well, as long as 
instances of I2C_HandleTypeDef hi2c2 is changed to reflect the correct I2C interface.

**Note:** this also works for the ADXL343 if ALT ADDRESS pin (pin 12) has 
been pulled to ground, as this makes the address 0x53. If not, the address 
should be adjusted to become 0x1D instead.