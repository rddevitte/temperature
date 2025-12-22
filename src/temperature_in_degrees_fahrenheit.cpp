#include "temperature_in_degrees_fahrenheit.hpp"

namespace temperature {

TemperatureInDegreesFahrenheit::TemperatureInDegreesFahrenheit(TemperatureValueType _value) noexcept
    : BaseTemperature(_value, "°F")
{
}

TemperatureInDegreesFahrenheit TemperatureInDegreesFahrenheit::Convert(
    const TemperatureInKelvin &k) noexcept
{
    return TemperatureInDegreesFahrenheit{ (k - 273.15) * (9.0 / 5.0) + 32.0 };
}

TemperatureInDegreesFahrenheit TemperatureInDegreesFahrenheit::Convert(
    const TemperatureInDegreesCelsius &c) noexcept
{
    return TemperatureInDegreesFahrenheit{ c * (9.0 / 5.0) + 32.0 };
}

}  // namespace temperature
