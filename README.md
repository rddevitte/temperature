# temperature

A small library for storing temperature values as well as converting them from one unit to another.

## Build

### Prerequisites

To build locally on GNU/Linux, the GNU G++, the GNU Make, the Kitware's CMake and the Google's
GoogleTest packages must be installed.

To install them on Ubuntu, run:

    sudo apt update && sudo apt -y install g++ make cmake libgtest-dev

Otherwise, you can also use the Dockerized environment. The only prerequisite is to have the Docker
Engine installed. To install it, please refer to [the official Docker guide](https://docs.docker.com/get-started/get-docker/).

For running the environment, run:

    ./enter-devel

### Build

To build the library and the GTest executable, run:

    ./build

### Clean

To clean up the environment, run:

    ./clean

## Run

To run the GTest executable, run:

    ./_build/test/temperature_test
