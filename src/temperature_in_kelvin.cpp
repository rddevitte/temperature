#include <tuple>
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

bool TemperatureInKelvin::operator==(const TemperatureInKelvin &other) const noexcept
{
    return std::tie(value, unit_suffix) == std::tie(other.value, other.unit_suffix);
}

bool TemperatureInKelvin::operator!=(const TemperatureInKelvin &other) const noexcept
{
    return !(*this == other);
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
