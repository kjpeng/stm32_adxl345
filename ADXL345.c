
#include "ADXL345.h"

int ADXL345_Write(uint8_t reg, uint8_t val) {
  uint8_t buf[2] = {reg, val};
  if (HAL_I2C_Master_Transmit(&hi2c2,
                              ADXL_ADDR << 1,
                              buf,
                              2,
                              HAL_MAX_DELAY) != HAL_OK) {
    return -1;
  }
}

int ADXL345_Read(uint8_t reg, uint8_t *buf, uint16_t buf_size) {
  if (HAL_I2C_Mem_Read(&hi2c2,
                       ADXL_ADDR << 1,
                       reg,
                       I2C_MEMADD_SIZE_8BIT,
                       buf,
                       buf_size,
                       HAL_MAX_DELAY) != HAL_OK) {
    return -1;
  }
}

int ADXL345_Init(void) {
  ADXL345_Read(ADXL345_REG_DEVID, &chipid, 1);
  if (chipid != 0xE5) {
    return -1;
  }

  ADXL345_Write(ADXL345_REG_POWER_CTL, 0x08); // enable measurements
  ADXL345_Write(ADXL345_REG_DATA_FORMAT, 0x01); // data_format range +- 4g
}

int16_t ADXL345_ReadX(void) {
  uint8_t buf[2];
  HAL_I2C_Mem_Read(&hi2c2,
                   ADXL_ADDR << 1,
                   ADXL345_REG_DATAX0,
                   I2C_MEMADD_SIZE_8BIT,
                   buf,
                   2,
                   HAL_MAX_DELAY);
  int16_t x;
  x = buf[1] << 8 | buf[0];
  return x;
}

int16_t ADXL345_ReadY(void) {
  uint8_t buf[2];
  HAL_I2C_Mem_Read(&hi2c2,
                   ADXL_ADDR << 1,
                   ADXL345_REG_DATAY0,
                   I2C_MEMADD_SIZE_8BIT,
                   buf,
                   2,
                   HAL_MAX_DELAY);
  int16_t y;
  y = buf[1] << 8 | buf[0];
  return y;
}

int16_t ADXL345_ReadZ(void) {
  uint8_t buf[2];
  HAL_I2C_Mem_Read(&hi2c2,
                   ADXL_ADDR << 1,
                   ADXL345_REG_DATAZ0,
                   I2C_MEMADD_SIZE_8BIT,
                   buf,
                   2,
                   HAL_MAX_DELAY);
  int16_t z;
  z = buf[1] << 8 | buf[0];
  return z;
}