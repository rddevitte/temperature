#ifndef BASE_TEMPERATURE_HPP
#define BASE_TEMPERATURE_HPP

#include <ostream>

namespace temperature {

using TemperatureValueType = double;
using TemperatureUnitSuffixType = std::string;

struct BaseTemperature {
    const TemperatureValueType value;
    const TemperatureUnitSuffixType unit_suffix;

    TemperatureValueType operator+(TemperatureValueType v) const noexcept;
    TemperatureValueType operator-(TemperatureValueType v) const noexcept;
    TemperatureValueType operator*(TemperatureValueType v) const noexcept;

   protected:
    BaseTemperature(TemperatureValueType _value,
                    const TemperatureUnitSuffixType &_unit_suffix) noexcept;

    virtual ~BaseTemperature() = default;
};

std::ostream &operator<<(std::ostream &os, const BaseTemperature &t);

// Forwarding declarations

struct TemperatureInKelvin;
struct TemperatureInDegreesCelsius;
struct TemperatureInDegreesFahrenheit;

}  // namespace temperature

#endif  // BASE_TEMPERATURE_HPP
