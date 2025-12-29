#ifndef TEMPERATURE_IN_DEGREES_FAHRENHEIT_HPP
#define TEMPERATURE_IN_DEGREES_FAHRENHEIT_HPP

#include "base_temperature.hpp"
#include "temperature_in_degrees_celsius.hpp"
#include "temperature_in_kelvin.hpp"

namespace temperature {

struct TemperatureInDegreesFahrenheit final : public BaseTemperature {
    explicit TemperatureInDegreesFahrenheit(TemperatureValueType _value) noexcept;

    explicit TemperatureInDegreesFahrenheit(const TemperatureInDegreesCelsius &c) noexcept;

    explicit TemperatureInDegreesFahrenheit(const TemperatureInKelvin &k) noexcept;

    bool operator==(const TemperatureInDegreesFahrenheit &other) const noexcept;

    bool operator!=(const TemperatureInDegreesFahrenheit &other) const noexcept;

    operator TemperatureInDegreesCelsius() const noexcept;

    operator TemperatureInKelvin() const noexcept;
};

}  // namespace temperature

#endif  // TEMPERATURE_IN_DEGREES_FAHRENHEIT_HPP
