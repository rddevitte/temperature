#ifndef TEMPERATURE_IN_KELVIN_HPP
#define TEMPERATURE_IN_KELVIN_HPP

#include "base_temperature.hpp"
#include "temperature_in_degrees_celsius.hpp"
#include "temperature_in_degrees_fahrenheit.hpp"

namespace temperature {

struct TemperatureInKelvin final : public BaseTemperature {
    explicit TemperatureInKelvin(TemperatureValueType _value) noexcept;

    explicit TemperatureInKelvin(const TemperatureInDegreesCelsius &c) noexcept;

    explicit TemperatureInKelvin(const TemperatureInDegreesFahrenheit &f) noexcept;

    operator TemperatureInDegreesCelsius() const noexcept;

    operator TemperatureInDegreesFahrenheit() const noexcept;
};

}  // namespace temperature

#endif  // TEMPERATURE_IN_KELVIN_HPP
