#include <tuple>
#include "temperature_in_degrees_celsius.hpp"

namespace temperature {

TemperatureInDegreesCelsius::TemperatureInDegreesCelsius(TemperatureValueType _value) noexcept
    : BaseTemperature(_value, "°C")
{
}

TemperatureInDegreesCelsius::TemperatureInDegreesCelsius(
    const TemperatureInDegreesFahrenheit &f) noexcept
    : BaseTemperature((f - 32.0) * (5.0 / 9.0), "°C")
{
}

TemperatureInDegreesCelsius::TemperatureInDegreesCelsius(const TemperatureInKelvin &k) noexcept
    : BaseTemperature(k - 273.15, "°C")
{
}

bool TemperatureInDegreesCelsius::operator==(
    const TemperatureInDegreesCelsius &other) const noexcept
{
    return std::tie(value, unit_suffix) == std::tie(other.value, other.unit_suffix);
}

bool TemperatureInDegreesCelsius::operator!=(
    const TemperatureInDegreesCelsius &other) const noexcept
{
    return !(*this == other);
}

TemperatureInDegreesCelsius::operator TemperatureInDegreesFahrenheit() const noexcept
{
    return static_cast<TemperatureInDegreesFahrenheit>(*this);
}

TemperatureInDegreesCelsius::operator TemperatureInKelvin() const noexcept
{
    return static_cast<TemperatureInKelvin>(*this);
}

}  // namespace temperature
