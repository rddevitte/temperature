#include <stdexcept>
#include "temperature.hpp"

namespace temperature {

Temperature::Temperature(const TemperatureInDegreesCelsius &c) noexcept
    : in_degrees_celsius(c), in_degrees_fahrenheit(c), in_kelvin(c)
{
}

Temperature::Temperature(const TemperatureInDegreesFahrenheit &f) noexcept
    : in_degrees_celsius(f), in_degrees_fahrenheit(f), in_kelvin(f)
{
}

Temperature::Temperature(const TemperatureInKelvin &k) noexcept
    : in_degrees_celsius(k), in_degrees_fahrenheit(k), in_kelvin(k)
{
}

Temperature::Temperature(const TemperatureInDegreesCelsius &c,
                         const TemperatureInDegreesFahrenheit &f, const TemperatureInKelvin &k)
    : in_degrees_celsius(c), in_degrees_fahrenheit(f), in_kelvin(k)
{
    if (c != f || c != k) {
        throw std::invalid_argument(
            "at least one of the temperatures' values in one unit "
            "does not correspond to another one in another unit");
    }
}

}  // namespace temperature
