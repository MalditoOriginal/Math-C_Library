# Math-C_Library

## Math Library - A C Library for Mathematical Operations

The S21 Math Library is a comprehensive C library that provides a range of mathematical functions and constants for your C programs. This library is designed to help you perform various mathematical calculations, from basic operations to more complex trigonometric and exponential functions.

## Table of Contents

1. [Introduction](#introduction)
2. [Constants](#constants)
3. [List of Functions](#list-of-functions)
   - [s21_isnan](#s21_isnan)
   - [s21_abs](#s21_abs)
   - [s21_fabs](#s21_fabs)
   - [s21_fmod](#s21_fmod)
   - [s21_ceil](#s21_ceil)
   - [s21_floor](#s21_floor)
   - [s21_pow](#s21_pow)
   - [s21_exp](#s21_exp)
   - [s21_cos](#s21_cos)
   - [s21_sin](#s21_sin)
   - [s21_log](#s21_log)
   - [s21_sqrt](#s21_sqrt)
   - [s21_tan](#s21_tan)
   - [s21_acos](#s21_acos)
   - [s21_asin](#s21_asin)
   - [s21_atan](#s21_atan)
4. [Usage](#usage)
5. [Contributing](#contributing)
6. [License](#license)

## Introduction

The S21 Math Library is a versatile C library that simplifies mathematical operations in your C programs. It includes constants for common mathematical values like π (pi) and functions for various mathematical operations. Whether you need to calculate trigonometric values, exponentials, or perform simple arithmetic, this library has you covered.

## Constants

### `PI`

The mathematical constant π (pi) with a high degree of precision.

### `EPSILON`

A small constant representing the smallest possible difference between two numbers.

### `PRECISION`

A constant used for approximating values with high precision.

### `NEG_INF`

Represents negative infinity.

### `POS_INF`

Represents positive infinity.

### `PRECISION_TERM`

A constant used for precision calculations.

### `S21_NAN`

Represents "Not-a-Number" (NaN).

## List of Functions

### `s21_isnan`

- Check if a given number is NaN (Not-a-Number).

### `s21_abs`

- Calculate the absolute value of an integer.

### `s21_fabs`

- Calculate the absolute value of a floating-point number.

### `s21_fmod`

- Calculate the remainder of division of two floating-point numbers.

### `s21_ceil`

- Round a number up to the nearest integer.

### `s21_floor`

- Round a number down to the nearest integer.

### `s21_pow`

- Calculate the power of a base raised to an exponent.

### `s21_exp`

- Calculate the exponential value of a number.

### `s21_cos`

- Calculate the cosine of an angle.

### `s21_sin`

- Calculate the sine of an angle.

### `s21_log`

- Calculate the natural logarithm of a number.

### `s21_sqrt`

- Calculate the square root of a number.

### `s21_tan`

- Calculate the tangent of an angle.

### `s21_acos`

- Calculate the arccosine of a number.

### `s21_asin`
               
- Calculate the arcsine of a number.

### `s21_atan`

- Calculate the arctangent of a number.

## Usage

To use the S21 Math Library in your C programs, include the header file and call the functions as needed. Make sure to check the function descriptions and usage examples in the documentation.

```c
#include "s21_math.h"

int main() {
    double x = 2.0;
    double result = s21_sqrt(x);
    printf("The square root of %lf is %lf\n", x, result);
    return 0;
}
```

## Contributing

Contributions to the S21 Math Library are welcome! If you have suggestions, improvements, or bug fixes, please open an issue or submit a pull request on the [GitHub repository](https://github.com/your-repo).

## License

The S21 Math Library is licensed under the [MIT License](LICENSE). You are free to use, modify, and distribute it as needed.
