#include <tuple>
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

bool BaseTemperature::operator==(const BaseTemperature &other) const noexcept
{
    return std::tie(value, unit_suffix) == std::tie(other.value, other.unit_suffix);
}

bool BaseTemperature::operator!=(const BaseTemperature &other) const noexcept
{
    return !(*this == other);
}

std::ostream &operator<<(std::ostream &os, const temperature::BaseTemperature &t)
{
    return os << t.value << t.unit_suffix;
}

}  // namespace temperature
