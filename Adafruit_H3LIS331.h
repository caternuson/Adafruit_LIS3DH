/*!
 *  @file Adafruit_H3LIS331.h
 *
 *  This is a library for the Adafruit H3LIS331 Accel breakout board
 *
 *  Designed specifically to work with the [Adafruit H3LIS331 High-G Triple-Axis
 * Accelerometer (+-100g/200g/400g)](https://www.adafruit.com/product/4XXX)
 *
 *  This sensor communicates over I2C or SPI (our library code supports both) so
 * you can share it with a bunch of other sensors on the same I2C bus.
 *
 *  Adafruit invests time and resources providing this open source code,
 *  please support Adafruit andopen-source hardware by purchasing products
 *  from Adafruit!
 *
 *  Bryan Siepert for Adafruit Industries
 *  BSD license, all text above must be included in any redistribution
 */

#ifndef ADAFRUIT_H3LIS331_H
#define ADAFRUIT_H3LIS331_H

#include "Adafruit_LIS3X.h"

/** Used with register 0x2A (H3LIS331_REG_CTRL_REG1) to set bandwidth **/
typedef enum {
  H3LIS331_DATARATE_POWERDOWN = 0,
  H3LIS331_DATARATE_50_HZ = 0x4,
  H3LIS331_DATARATE_100_HZ = 0x5,
  H3LIS331_DATARATE_400_HZ = 0x6,
  H3LIS331_DATARATE_1000_HZ = 0x7,
  H3LIS331_DATARATE_LOWPOWER_0_5_HZ = 0x8,
  H3LIS331_DATARATE_LOWPOWER_1_HZ = 0xC,
  H3LIS331_DATARATE_LOWPOWER_2_HZ = 0x10,
  H3LIS331_DATARATE_LOWPOWER_5_HZ = 0x14,
  H3LIS331_DATARATE_LOWPOWER_10_HZ = 0x18,
} h3lis331dl_dataRate_t;

/** A structure to represent scales **/
typedef enum {
  H3LIS331_RANGE_100_G = 0x0,  ///< +/- 100g
  H3LIS331_RANGE_200_G = 0x1,  ///< +/- 200g
  H3LIS331_RANGE_400_G = 0x03, ///< +/- 400g
} h3lis331dl_range_t;

/*!
 *  @brief  Class that stores state and functions for interacting with
 *          Adafruit_H3LIS331
 */
class Adafruit_H3LIS331 : public Adafruit_LIS3X {
public:
  Adafruit_H3LIS331();

  bool begin_I2C(uint8_t i2c_addr = LIS3X_DEFAULT_ADDRESS,
                 TwoWire *wire = &Wire, int32_t sensorID = 0);

  bool begin_SPI(uint8_t cs_pin, SPIClass *theSPI = &SPI,
                 int32_t sensor_id = 0);
  bool begin_SPI(int8_t cs_pin, int8_t sck_pin, int8_t miso_pin,
                 int8_t mosi_pin, int32_t sensor_id = 0);
  void setDataRate(h3lis331dl_dataRate_t dataRate);
  h3lis331dl_dataRate_t getDataRate(void);

  void setRange(h3lis331dl_range_t range);
  h3lis331dl_range_t getRange(void);

private:
  bool _init(int32_t sensor_id);
  void _scaleValues(void);
};

#endif
