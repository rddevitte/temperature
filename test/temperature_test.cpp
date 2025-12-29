#include <gtest/gtest.h>
#include "temperature.hpp"

class TemperatureTest : public ::testing::Test {
   public:
    virtual ~TemperatureTest() = default;

   protected:
    static const temperature::TemperatureInDegreesCelsius c;
    static const temperature::TemperatureInDegreesFahrenheit f;
    static const temperature::TemperatureInKelvin k;
    static const temperature::TemperatureInDegreesCelsius non_equivalent_c;
    static const temperature::TemperatureInDegreesFahrenheit non_equivalent_f;
    static const temperature::TemperatureInKelvin non_equivalent_k;
};

const temperature::TemperatureInDegreesCelsius TemperatureTest::c{ 40.0 };
const temperature::TemperatureInDegreesFahrenheit TemperatureTest::f{ 104.0 };
const temperature::TemperatureInKelvin TemperatureTest::k{ 313.15 };
const temperature::TemperatureInDegreesCelsius TemperatureTest::non_equivalent_c{ 0 };
const temperature::TemperatureInDegreesFahrenheit TemperatureTest::non_equivalent_f{ 0 };
const temperature::TemperatureInKelvin TemperatureTest::non_equivalent_k{ 0 };

TEST_F(TemperatureTest, ConvertCorrectlyFromDegreesCelsiusToDegreesFahrenheit)
{
    EXPECT_EQ(f, c);
}

TEST_F(TemperatureTest, ConvertCorrectlyFromDegreesCelsiusToKelvin)
{
    EXPECT_EQ(k, c);
}

TEST_F(TemperatureTest, ConvertCorrectlyFromDegreesFahrenheitToDegreesCelsius)
{
    EXPECT_EQ(c, f);
}

TEST_F(TemperatureTest, ConvertCorrectlyFromDegreesFahrenheitToKelvin)
{
    EXPECT_EQ(k, f);
}

TEST_F(TemperatureTest, ConvertCorrectlyFromKelvinToDegreesCelsius)
{
    EXPECT_EQ(c, k);
}

TEST_F(TemperatureTest, ConvertCorrectlyFromKelvinToDegreesFahrenheit)
{
    EXPECT_EQ(f, k);
}

TEST_F(TemperatureTest, NoThrowOnAllEquivalentTemperatureValuesInEachRespectiveUnit)
{
    EXPECT_NO_THROW(temperature::Temperature t(c, f, k));
}

TEST_F(TemperatureTest, ThrowOnNonEquivalentTemperatureInDegreesCelsius)
{
    EXPECT_THROW(temperature::Temperature t(non_equivalent_c, f, k), std::invalid_argument);
}

TEST_F(TemperatureTest, ThrowOnNonEquivalentTemperatureInDegreesFahrenheit)
{
    EXPECT_THROW(temperature::Temperature t(c, non_equivalent_f, k), std::invalid_argument);
}

TEST_F(TemperatureTest, ThrowOnNonEquivalentTemperatureInKelvin)
{
    EXPECT_THROW(temperature::Temperature t(c, f, non_equivalent_k), std::invalid_argument);
}
