#ifndef TEMPERATURE_IN_DEGREES_CELSIUS_HPP
#define TEMPERATURE_IN_DEGREES_CELSIUS_HPP

#include "base_temperature.hpp"
#include "temperature_in_degrees_fahrenheit.hpp"
#include "temperature_in_kelvin.hpp"

namespace temperature {

struct TemperatureInDegreesCelsius final : public BaseTemperature {
    explicit TemperatureInDegreesCelsius(TemperatureValueType _value) noexcept;

    explicit TemperatureInDegreesCelsius(const TemperatureInDegreesFahrenheit &f) noexcept;

    explicit TemperatureInDegreesCelsius(const TemperatureInKelvin &k) noexcept;

    bool operator==(const TemperatureInDegreesCelsius &other) const noexcept;

    bool operator!=(const TemperatureInDegreesCelsius &other) const noexcept;

    operator TemperatureInDegreesFahrenheit() const noexcept;

    operator TemperatureInKelvin() const noexcept;
};

}  // namespace temperature

#endif  // TEMPERATURE_IN_DEGREES_CELSIUS_HPP
