#include "temperature_in_kelvin.hpp"

namespace temperature {

TemperatureInKelvin::TemperatureInKelvin(TemperatureValueType _value) noexcept
    : BaseTemperature(_value, "K")
{
}

TemperatureInKelvin::TemperatureInKelvin(const TemperatureInDegreesCelsius &c) noexcept
    : BaseTemperature(c + 273.15, "K")
{
}

TemperatureInKelvin::TemperatureInKelvin(const TemperatureInDegreesFahrenheit &f) noexcept
    : BaseTemperature((f - 32.0) * (5.0 / 9.0) + 273.15, "K")
{
}

TemperatureInKelvin::operator TemperatureInDegreesCelsius() const noexcept
{
    return static_cast<TemperatureInDegreesCelsius>(*this);
}

TemperatureInKelvin::operator TemperatureInDegreesFahrenheit() const noexcept
{
    return static_cast<TemperatureInDegreesFahrenheit>(*this);
}

}  // namespace temperature
