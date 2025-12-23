#include "temperature_in_degrees_fahrenheit.hpp"

namespace temperature {

TemperatureInDegreesFahrenheit::TemperatureInDegreesFahrenheit(TemperatureValueType _value) noexcept
    : BaseTemperature(_value, "°F")
{
}

TemperatureInDegreesFahrenheit::TemperatureInDegreesFahrenheit(
    const TemperatureInDegreesCelsius &c) noexcept
    : BaseTemperature(c * (9.0 / 5.0) + 32.0, "°F")
{
}

TemperatureInDegreesFahrenheit::TemperatureInDegreesFahrenheit(
    const TemperatureInKelvin &k) noexcept
    : BaseTemperature((k - 273.15) * (9.0 / 5.0) + 32.0, "°F")
{
}

TemperatureInDegreesFahrenheit::operator TemperatureInDegreesCelsius() const noexcept
{
    return static_cast<TemperatureInDegreesCelsius>(*this);
}

TemperatureInDegreesFahrenheit::operator TemperatureInKelvin() const noexcept
{
    return static_cast<TemperatureInKelvin>(*this);
}

}  // namespace temperature
