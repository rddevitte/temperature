#include "temperature_in_degrees_celsius.hpp"

namespace temperature {

TemperatureInDegreesCelsius::TemperatureInDegreesCelsius(TemperatureValueType _value) noexcept
    : BaseTemperature(_value, "°C")
{
}

TemperatureInDegreesCelsius TemperatureInDegreesCelsius::Convert(
    const TemperatureInKelvin &k) noexcept
{
    return TemperatureInDegreesCelsius{ k - 273.15 };
}

TemperatureInDegreesCelsius TemperatureInDegreesCelsius::Convert(
    const TemperatureInDegreesFahrenheit &f) noexcept
{
    return TemperatureInDegreesCelsius{ (f - 32.0) * (5.0 / 9.0) };
}

}  // namespace temperature
