#include <gtest/gtest.h>
#include "temperature.hpp"

class TemperatureTest : public ::testing::Test {
   protected:
    temperature::TemperatureInDegreesCelsius c{ 40.0 };
    temperature::TemperatureInDegreesFahrenheit f{ 104.0 };
    temperature::TemperatureInKelvin k{ 313.15 };
};

TEST_F(TemperatureTest, ConvertCorrectlyFromDegreesCelsiusToDegreesFahrenheit)
{
    //EXPECT_EQ(f, static_cast<temperature::TemperatureInDegreesFahrenheit>(c));
    EXPECT_EQ(f, static_cast<temperature::TemperatureInDegreesFahrenheit>(c));
}

TEST_F(TemperatureTest, ConvertCorrectlyFromDegreesCelsiusToKelvin)
{
    EXPECT_EQ(k, static_cast<temperature::TemperatureInKelvin>(c));
}

TEST_F(TemperatureTest, ConvertCorrectlyFromDegreesFahrenheitToDegreesCelsius)
{
    EXPECT_EQ(c, static_cast<temperature::TemperatureInDegreesCelsius>(f));
}

TEST_F(TemperatureTest, ConvertCorrectlyFromDegreesFahrenheitToKelvin)
{
    EXPECT_EQ(k, static_cast<temperature::TemperatureInKelvin>(f));
}

TEST_F(TemperatureTest, ConvertCorrectlyFromKelvinToDegreesCelsius)
{
    EXPECT_EQ(c, static_cast<temperature::TemperatureInDegreesCelsius>(k));
}

TEST_F(TemperatureTest, ConvertCorrectlyFromKelvinToDegreesFahrenheit)
{
    EXPECT_EQ(f, static_cast<temperature::TemperatureInDegreesFahrenheit>(k));
}

TEST_F(TemperatureTest, NoThrowOnAllCorrectTemperatureValuesInEachRespectiveUnit)
{
    EXPECT_NO_THROW(temperature::Temperature t(c, f, k));
}

TEST_F(TemperatureTest, ThrowOnInvalidTemperatureInDegreesCelsius)
{
    temperature::TemperatureInDegreesCelsius invalid_c{ 0 };

    EXPECT_THROW(temperature::Temperature t(invalid_c, f, k), std::invalid_argument);
}

TEST_F(TemperatureTest, ThrowOnInvalidTemperatureInDegreesFahrenheit)
{
    temperature::TemperatureInDegreesFahrenheit invalid_f{ 0 };

    EXPECT_THROW(temperature::Temperature t(c, invalid_f, k), std::invalid_argument);
}

TEST_F(TemperatureTest, ThrowOnInvalidTemperatureInKelvin)
{
    temperature::TemperatureInKelvin invalid_k{ 0 };

    EXPECT_THROW(temperature::Temperature t(c, f, invalid_k), std::invalid_argument);
}
