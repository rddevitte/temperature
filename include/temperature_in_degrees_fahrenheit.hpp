#ifndef TEMPERATURE_IN_DEGREES_FAHRENHEIT_HPP
#define TEMPERATURE_IN_DEGREES_FAHRENHEIT_HPP

#include "base_temperature.hpp"
#include "temperature_in_kelvin.hpp"
#include "temperature_in_degrees_celsius.hpp"

namespace temperature {

struct TemperatureInDegreesFahrenheit final : public BaseTemperature {
    explicit TemperatureInDegreesFahrenheit(TemperatureValueType _value) noexcept;

    static TemperatureInDegreesFahrenheit Convert(const TemperatureInKelvin &k) noexcept;

    static TemperatureInDegreesFahrenheit Convert(const TemperatureInDegreesCelsius &c) noexcept;
};

}  // namespace temperature

#endif  // TEMPERATURE_IN_DEGREES_FAHRENHEIT_HPP
