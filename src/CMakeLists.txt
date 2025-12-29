add_library(temperature)

target_sources(temperature PRIVATE
    base_temperature.cpp
    temperature.cpp
    temperature_in_degrees_celsius.cpp
    temperature_in_degrees_fahrenheit.cpp
    temperature_in_kelvin.cpp)

install(TARGETS temperature LIBRARY DESTINATION lib)
