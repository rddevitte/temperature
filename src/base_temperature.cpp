#include "base_temperature.hpp"

namespace temperature {

BaseTemperature::BaseTemperature(TemperatureValueType _value,
                                 const TemperatureUnitSuffixType &_unit_suffix) noexcept
    : value(_value), unit_suffix(_unit_suffix)
{
}

TemperatureValueType BaseTemperature::operator+(TemperatureValueType v) const noexcept
{
    return value + v;
}

TemperatureValueType BaseTemperature::operator-(TemperatureValueType v) const noexcept
{
    return value - v;
}

TemperatureValueType BaseTemperature::operator*(TemperatureValueType v) const noexcept
{
    return value * v;
}

std::ostream &operator<<(std::ostream &os, const temperature::BaseTemperature &t)
{
    return os << t.value << t.unit_suffix;
}

}  // namespace temperature
