#ifndef TEMPERATURE_IN_DEGREES_CELSIUS_HPP
#define TEMPERATURE_IN_DEGREES_CELSIUS_HPP

#include "base_temperature.hpp"
#include "temperature_in_kelvin.hpp"
#include "temperature_in_degrees_fahrenheit.hpp"

namespace temperature {

struct TemperatureInDegreesCelsius final : public BaseTemperature {
    explicit TemperatureInDegreesCelsius(TemperatureValueType _value) noexcept;

    static TemperatureInDegreesCelsius Convert(const TemperatureInKelvin &k) noexcept;

    static TemperatureInDegreesCelsius Convert(const TemperatureInDegreesFahrenheit &f) noexcept;
};

}  // namespace temperature

#endif  // TEMPERATURE_IN_DEGREES_CELSIUS_HPP
