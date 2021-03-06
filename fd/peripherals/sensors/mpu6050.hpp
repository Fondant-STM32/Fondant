/*
 *
 * Copyright Niels Post 2022.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE or copy at
 * https://www.boost.org/LICENSE_1_0.txt)
 *
*/
#ifndef FD_HDR_PERIPHERAL_MU6050
#define FD_HDR_PERIPHERAL_MU6050

#include "fd/targets/base/i2c.hpp"

// TODO corrigeer voor de ingestelde FSR van de chip
namespace fd::peripherals {
    class mpu6050 {
    private:
        fd::i2c_base &bus;
        uint16_t     address;

        uint8_t data[14] = {0};
    protected:

    public:
        mpu6050(i2c_base &bus, uint16_t address = 0x68);

        /**
         * Alle mogelijke dataregisters voor de MPU6050
         */
        enum class Register : uint8_t {
            SELF_TEST_X  = 0x0D,
            SELF_TEST_Y  = 0x0E,
            SELF_TEST_Z  = 0x0F,
            SELF_TEST_A  = 0x10,
            SMPLRT_DIV   = 0x19,
            CONFIG       = 0x1A,
            GYRO_CONFIG  = 0x1B,
            ACCEL_CONFIG = 0x1C,
            FIFO_EN      = 0x23,

            I2C_MST_CTRL   = 0x24,
            I2C_SLV0_ADDR  = 0x25,
            I2C_SLV0_REG   = 0x26,
            I2C_SLV0_CTRL  = 0x27,
            I2C_SLV1_ADDR  = 0x28,
            I2C_SLV1_REG   = 0x29,
            I2C_SLV1_CTRL  = 0x2A,
            I2C_SLV2_ADDR  = 0x2B,
            I2C_SLV2_REG   = 0x2C,
            I2C_SLV2_CTRL  = 0x2D,
            I2C_SLV3_ADDR  = 0x2E,
            I2C_SLV3_REG   = 0x2F,
            I2C_SLV3_CTRL  = 0x30,
            I2C_SLV4_ADDR  = 0x31,
            I2C_SLV4_REG   = 0x32,
            I2C_SLV4_CTRL  = 0x33,
            I2C_SLV4_DO    = 0x34,
            I2C_SLV4_DI    = 0x35,
            I2C_MST_STATUS = 0x36,
            INT_PIN_CFG    = 0x37,
            INT_ENABLE     = 0x38,
            INT_STATUS     = 0x3A,

            ACCEL_XOUT_H = 0x3B,
            ACCEL_XOUT_L = 0x3C,
            ACCEL_YOUT_H = 0x3D,
            ACCEL_YOUT_L = 0x3E,
            ACCEL_ZOUT_H = 0x3F,
            ACCEL_ZOUT_L = 0x40,
            TEMP_OUT_H   = 0x41,
            TEMP_OUT_L   = 0x42,
            GYRO_XOUT_H  = 0x43,
            GYRO_XOUT_L  = 0x44,
            GYRO_YOUT_H  = 0x45,
            GYRO_YOUT_L  = 0x46,
            GYRO_ZOUT_H  = 0x47,
            GYRO_ZOUT_L  = 0x48,

            EXT_SENS_DATA_00 = 0x49,
            EXT_SENS_DATA_01 = 0x4A,
            EXT_SENS_DATA_02 = 0x4B,
            EXT_SENS_DATA_03 = 0x4C,
            EXT_SENS_DATA_04 = 0x4D,
            EXT_SENS_DATA_05 = 0x4E,
            EXT_SENS_DATA_06 = 0x4F,
            EXT_SENS_DATA_07 = 0x50,
            EXT_SENS_DATA_08 = 0x51,
            EXT_SENS_DATA_09 = 0x52,
            EXT_SENS_DATA_10 = 0x53,
            EXT_SENS_DATA_11 = 0x54,
            EXT_SENS_DATA_12 = 0x55,
            EXT_SENS_DATA_13 = 0x56,
            EXT_SENS_DATA_14 = 0x57,
            EXT_SENS_DATA_15 = 0x58,
            EXT_SENS_DATA_16 = 0x59,
            EXT_SENS_DATA_17 = 0x5A,
            EXT_SENS_DATA_18 = 0x5B,
            EXT_SENS_DATA_19 = 0x5C,
            EXT_SENS_DATA_20 = 0x5D,
            EXT_SENS_DATA_21 = 0x5E,
            EXT_SENS_DATA_22 = 0x5F,
            EXT_SENS_DATA_23 = 0x60,

            I2C_SLV0_DO = 0x63,
            I2C_SLV1_DO = 0x64,
            I2C_SLV2_DO = 0x65,
            I2C_SLV3_DO = 0x66,

            I2C_MST_DELAY_CTRL = 0x67,
            SIGNAL_PATH_RESET  = 0x68,
            USER_CTRL          = 0x6A,
            PWR_MGMT_1         = 0x6B,
            PWR_MGMT_2         = 0x6C,
            FIFO_COUNTH        = 0x72,
            FIFO_COUNTL        = 0x73,
            FIFO_R_W           = 0x74,
            WHO_AM_I           = 0x75
        };

    private:
        void setRegisterBits(Register reg, uint8_t bitMask, uint8_t newValue);

    public:

        /**
         * Mogelijke instellingen voor het volledige bereik van de MPU6050 voor Gyro.
         * Als deze ingesteld is op 250 graden/s, en getGyroX de hoogst mogelijke waarde (32767) teruggeeft, dan is
         * de gemeten gyrowaarde dus 250 graden/s
         */
        enum class GyroFullScaleRange : uint8_t {
            FSR_250DEG_PER_S  = 0,
            FSR_500DEG_PER_S  = 1,
            FSR_1000DEG_PER_S = 2,
            FSR_2000DEG_PER_S = 3,
        };

        /**
         * Mogelijke instellingen voor het volledige bereik van de MPU6050 voor Accel.
         * Als deze ingesteld is op 2G, en getAccelX de hoogst mogelijke waarde (32767) teruggeeft, dan is
         * de gemeten gyrowaarde dus 2G
         */
        enum class AccelFullScaleRange : uint8_t {
            FSR_2G  = 0,
            FSR_4G  = 1,
            FSR_8G  = 2,
            FSR_16G = 3,
        };

        /**
         * Lees een dataregister van de MPU6050 uit
         * @param reg Register om uit te lezen
         * @param data Data-array om de data naartoe te schrijven
         * @param length Lengte van de data
         */
        void readRegister(Register reg, uint8_t *data, uint8_t length);

        /**
         * Schrijf een nieuwe waarde naar een dataregister van de MPU6050
         * @param reg Register om naar te schrijven
         * @param data Data-byte om te schrijven
         */
        void writeRegister(Register reg, uint8_t data);

        /**
         * Vraag de sensordata op bij de MPU6050 en sla deze op in het mpu6050-object
         */
        void readData();

        /**
         * Stel de samplerate divider in.
         * Een hogere samplereate divider zorgt voor minder metingen per seconde, maar ook dat de mpu6050 minder energie
         * gebruikt
         * @param divider De nieuwe sampleratedivider
         */
        void setSampleRateDivider(uint8_t divider);

        /**
         * Stel de FSR voor de gyro in. Zie GyroFullScaleRange voor meer informatie
         * @param range  De nieuwe FSR voor de gyro
         */
        void setGyroFullScaleRange(const GyroFullScaleRange &range);

        /**
         * Stel de FSR voor de accelerometer in. Zie AccelFullScaleRange voor meer informatie
         * @param range  De nieuwe FSR voor de accelerometer
         */
        void setAccelFullScaleRange(const AccelFullScaleRange &range);

        /**
         * Stel I2C bypass in. Hiermee wordt de I2C bus op de MPU (SCL+SDA) automatisch verbonden met XCL+XDA, zodat
         * andere I2C apparaten "door de mpu6050 heen" aangesloten kunnen worden.
         * @param enabled Of I2C bypass ingeschakeld moet worden
         */
        void setI2CBypassEnabled(bool enabled);

        /**
         * Schakel de temperatuursensor in of uit
         * @param enabled Of de temp-sensor ingeschakeld moet zijn
         */
        void setTempEnabled(bool enabled);

        /**
         * Zet de MPU605 volledig in sleep modus
         * @param enabled True voor sleep, False voor wakker
         */
        void setSleepEnabled(bool enabled);

        /**
         * Herstel opgebouwde signaalpaden in de MPU6050 naar de standaard
         * @param resetGyro Of de gyro-paden hersteld moeten worden
         * @param resetAccel Of de accelerometer-paden hersteld moeten worden
         * @param resetTemp Of de temperatuursensor-paden hersteld moeten worden
         */
        void resetSignalPaths(bool resetGyro, bool resetAccel, bool resetTemp);

        /**
         * Herstel de MPU6050-registers en alle signaalpaden naar de standaardwaarden
         */
        void resetSignalPathsAndRegisters();

        /**
         * Bereken, en haal de gemeten waarde voor accelerometer X op
         * @return De gemeten waarde
         */
        uint16_t getAccelX();

        /**
         * Bereken, en haal de gemeten waarde voor accelerometer Y op
         * @return De gemeten waarde
         */
        uint16_t getAccelY();

        /**
         * Bereken, en haal de gemeten waarde voor accelerometer Z op
         * @return De gemeten waarde
         */
        uint16_t getAccelZ();

        /**
         * Bereken, en haal de gemeten temperatuur
         * @return De gemeten temperatuur in graden celcius
         */
        double getTemp();

        /**
         * Bereken, en haal de gemeten waarde voor gyro X op
         * @return De gemeten waarde
         */
        int getGyroX();

        /**
         * Bereken, en haal de gemeten waarde voor gyro Y op
         * @return De gemeten waarde
         */
        int getGyroY();

        /**
         * Bereken, en haal de gemeten waarde voor gyro Z op
         * @return De gemeten waarde
         */
        int getGyroZ();

        /**
         * Haal de waarde van het WHOAMI register op
         * @return WhoAmI waarde
         */
        uint8_t getWhoAmI();


    };

}
#endif //FD_HDR_PERIPHERAL_MU6050
