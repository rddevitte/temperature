#ifndef TEMPERATURE_HPP
#define TEMPERATURE_HPP

#include "temperature_in_kelvin.hpp"
#include "temperature_in_degrees_celsius.hpp"
#include "temperature_in_degrees_fahrenheit.hpp"

namespace temperature {

struct Temperature {
    const TemperatureInDegreesCelsius in_degrees_celsius;
    const TemperatureInDegreesFahrenheit in_degrees_fahrenheit;
    const TemperatureInKelvin in_kelvin;

    explicit Temperature(const TemperatureInDegreesCelsius &c) noexcept;

    explicit Temperature(const TemperatureInDegreesFahrenheit &f) noexcept;

    explicit Temperature(const TemperatureInKelvin &k) noexcept;

    Temperature(const TemperatureInDegreesCelsius &c, const TemperatureInDegreesFahrenheit &f,
                const TemperatureInKelvin &k);
};

}  // namespace temperature

#endif  // TEMPERATURE_HPP
