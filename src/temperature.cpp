#include <stdexcept>
#include "temperature.hpp"

namespace temperature {

Temperature::Temperature(const TemperatureInDegreesCelsius &c) noexcept
    : in_degrees_celsius(c),
      in_degrees_fahrenheit(TemperatureInDegreesFahrenheit::Convert(c)),
      in_kelvin(TemperatureInKelvin::Convert(c))
{
}

Temperature::Temperature(const TemperatureInDegreesFahrenheit &f) noexcept
    : in_degrees_celsius(TemperatureInDegreesCelsius::Convert(f)),
      in_degrees_fahrenheit(f),
      in_kelvin(TemperatureInKelvin::Convert(f))
{
}

Temperature::Temperature(const TemperatureInKelvin &k) noexcept
    : in_degrees_celsius(TemperatureInDegreesCelsius::Convert(k)),
      in_degrees_fahrenheit(TemperatureInDegreesFahrenheit::Convert(k)),
      in_kelvin(k)
{
}

Temperature::Temperature(const TemperatureInDegreesCelsius &c,
                         const TemperatureInDegreesFahrenheit &f, const TemperatureInKelvin &k)
    : in_degrees_celsius(c), in_degrees_fahrenheit(f), in_kelvin(k)
{
    if (c != TemperatureInDegreesCelsius::Convert(f) ||
        c != TemperatureInDegreesCelsius::Convert(k) ||
        f != TemperatureInDegreesFahrenheit::Convert(c) ||
        f != TemperatureInDegreesFahrenheit::Convert(k) || k != TemperatureInKelvin::Convert(c) ||
        k != TemperatureInKelvin::Convert(f)) {
        throw std::invalid_argument(
            "at least one of the temperatures' values in one unit "
            "does not correspond to another one in another unit");
    }
}

}  // namespace temperature
