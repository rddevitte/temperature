#include "temperature_in_kelvin.hpp"

namespace temperature {

TemperatureInKelvin::TemperatureInKelvin(TemperatureValueType _value) noexcept
    : BaseTemperature(_value, "K")
{
}

TemperatureInKelvin TemperatureInKelvin::Convert(const TemperatureInDegreesCelsius &c) noexcept
{
    return TemperatureInKelvin{ c + 273.15 };
}

TemperatureInKelvin TemperatureInKelvin::Convert(const TemperatureInDegreesFahrenheit &f) noexcept
{
    return TemperatureInKelvin{ (f - 32.0) * (5.0 / 9.0) + 273.15 };
}

}  // namespace temperature
