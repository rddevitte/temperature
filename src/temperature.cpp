#include <stdexcept>
#include "temperature.hpp"

namespace temperature {

Temperature::Temperature(const TemperatureInDegreesCelsius &c) noexcept
    : in_degrees_celsius(c),
      in_degrees_fahrenheit(static_cast<TemperatureInDegreesFahrenheit>(c)),
      in_kelvin(static_cast<TemperatureInKelvin>(c))
{
}

Temperature::Temperature(const TemperatureInDegreesFahrenheit &f) noexcept
    : in_degrees_celsius(static_cast<TemperatureInDegreesCelsius>(f)),
      in_degrees_fahrenheit(f),
      in_kelvin(static_cast<TemperatureInKelvin>(f))
{
}

Temperature::Temperature(const TemperatureInKelvin &k) noexcept
    : in_degrees_celsius(static_cast<TemperatureInDegreesCelsius>(k)),
      in_degrees_fahrenheit(static_cast<TemperatureInDegreesFahrenheit>(k)),
      in_kelvin(k)
{
}

Temperature::Temperature(const TemperatureInDegreesCelsius &c,
                         const TemperatureInDegreesFahrenheit &f, const TemperatureInKelvin &k)
    : in_degrees_celsius(c), in_degrees_fahrenheit(f), in_kelvin(k)
{
    if (c != static_cast<TemperatureInDegreesCelsius>(f) ||
        c != static_cast<TemperatureInDegreesCelsius>(k) ||
        f != static_cast<TemperatureInDegreesFahrenheit>(c) ||
        f != static_cast<TemperatureInDegreesFahrenheit>(k) ||
        k != static_cast<TemperatureInKelvin>(c) || k != static_cast<TemperatureInKelvin>(f)) {
        throw std::invalid_argument(
            "at least one of the temperatures' values in one unit "
            "does not correspond to another one in another unit");
    }
}

}  // namespace temperature
