#ifndef TEMPERATURE_IN_KELVIN_HPP
#define TEMPERATURE_IN_KELVIN_HPP

#include "base_temperature.hpp"
#include "temperature_in_degrees_celsius.hpp"
#include "temperature_in_degrees_fahrenheit.hpp"

namespace temperature {

struct TemperatureInKelvin final : public BaseTemperature {
    explicit TemperatureInKelvin(TemperatureValueType _value) noexcept;

    static TemperatureInKelvin Convert(const TemperatureInDegreesCelsius &c) noexcept;

    static TemperatureInKelvin Convert(const TemperatureInDegreesFahrenheit &f) noexcept;
};

}  // namespace temperature

#endif  // TEMPERATURE_IN_KELVIN_HPP
