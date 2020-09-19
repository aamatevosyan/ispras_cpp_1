# Quadratic equation solver
Application used for computing roots of the quadratic equation.

## Usage

### Prerequisites

You will need:

 * A modern C/C++ compiler
 * CMake 3.1+ installed
 * If you prefer to code in a great IDE, I highly recommend [Jetbrains CLion](https://www.jetbrains.com/clion/). It is fully compatible with this project.

### Building The Project

#### Git Clone

First we need to check out the git repo:

```bash
❯ mkdir ~/workspace
❯ cd ~/workspace
❯ git clone \
    https://github.com/aamatevosyan/ispras_cpp_1 \
    ispras_cpp_1
❯ cd ispras_cpp_1
❯ bash build-and-run
```

Now we can build this project, and below we show three separate ways to do so.

#### Building Manually

```bash
❯ rm -rf build && mkdir build
❯ cd build
❯ cmake ..
❯ make && make install
❯ cd ..
```

#### Running  Executable

```bash
❯ ispras_cpp_1
```

Program starts by checking data from "data.txt" and if all tests were passed it starts asking user for input. If entered values were not valid, new prompt will appear with explanation and user will be asked to input data again. After getting all needed data application computes and prints roots of the quadratic equation corresponding user data.

### Tests

All tests were located in "data.txt" where each line consists of six values separated by space. 
First three ones are coefficients of the quadratic equation, the forth one is number of available roots("QES_INF_ROOTS", if there are infinity roots). The last two ones are correct roots for equation. If the forth value is not 2, the last two values were ignored for "inifity roots" and "no root" case, and the last will be ignored for "one root" case. 

### Building in CLion

Assuming you've done the above two steps, you can start CLion, and open the project's top level folder. CLion should automatically detect the top level `CMakeLists.txt` file and provide you with the full set of build targets.

Select menu option **Build   ➜ Build Project**, and then **Build ➜ Install**.

#### Contributing

**Pull Requests are WELCOME!** Please submit any fixes or improvements, and I promise to review it as soon as I can at the project URL:

 * [Project Github Home](https://github.com/aamatevosyan/ispras_cpp_1)
 * [Submit Issues](https://github.com/aamatevosyan/ispras_cpp_1/issues)
 * [Pull Requests](https://github.com/aamatevosyan/ispras_cpp_1/pulls)

### License

&copy; 2020 Armen Matevosyan

Open sourced under MIT license, the terms of which can be read here — [MIT License](http://opensource.org/licenses/MIT).
