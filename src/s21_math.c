#include "s21_math.h"

// s21_abs
int s21_abs(int x) {
    return  x < 0 ? -x : x;
}

// s21_fabs
long double s21_fabs(double x) {
    return x < 0 ? -x : x;
}

// s21_fmod
long double s21_fmod(double x, double y)
{
    if (y == 0.0) {
        // Handle division by zero error
        return 0.0;
    }

    long double quotient = x / y;
    long double intPart = (long long)quotient;  // Get the integer part of the quotient

    // Calculate the remainder
    long double remainder = x - (intPart * y);

    // Handle negative remainders
    if (remainder < 0.0) {
        remainder += y;
    }

    return remainder;
}

// s21_ceil
long double s21_ceil(double x) {
    long double result; 

    if (x >= 0.0) {
        result = (long double)((long long)(x + 0.9999999));  // Adding a small value to handle floating-point precision
    } else {
        result = (long double)((long long)x);
    }

    return result;
}

// s21_floor
long double s21_floor(double x) {
    long double result;

    if (x >= 0.0) {
        result = (long double)((long long)x);
    } else {
        result = (long double)((long long)(x - 0.9999999));  // Subtracting a small value to handle floating-point precision
    }

    return result;
}

// s21_exp
long double s21_exp(double x) {
    long double result = 1.0;
    long double term = 1.0;
    if (x > 0) {
        for (int n = 1; s21_fabs(term) >= EPSILON; n++) {
            term *= x / n;
            result += term;
    }
    } else {
        for (double i = 0.0; i > x; i -= 1.0) {
            result /= E;
    }
    }
    return result;
}

// s21_sin
long double s21_sin(double x) {
    double result = 0.0; 
    int terms = 32;

    for (int i = 0; i <= terms; i++) {
        int powerVal = 2 * i +1;
        int sign = i % 2 == 0 ? 1 : -1;

        long double term = sign * s21_pow(x, powerVal) / s21_fact(powerVal);
        result += term;
    }
    return result;
}

// s21_neg_inf
long double s21_neg_inf() {
    return -1.0 / 0.0;
}

// s21_log
long double s21_log(double x) {
    if (x < 0) {
        return s21_nan();
    } else if (x == 0) {
        return s21_neg_inf();
    }
    
    long double result = 0.0;
    
    long double y = (x - 1.0) / (x + 1.0);
    long double term = y;
    long double term_squared = y * y;
    int n = 1;
    
    while (s21_fabs(term) > EPSILON) {
        result += term;
        term *= term_squared * (2 * n - 1) / (2 * n + 1);
        n++;
    }
    
    return 2.0 * result;
}

// s21_nan
long double s21_nan() {
    unsigned long nan_bits = 0x7FF8000000000000UL; // Bitwise representation of a NaN
    return *(long double*)&nan_bits; // Convert the bitwise representation to a long double
}

// s21_sqrt
long double s21_sqrt(double x) {
    double result = x;      // Initial guess for the result
    
    if (x < 0) {
        return s21_nan();
    }
    
    int max_iterations = 100; // Maximum number of iterations (modified for safety)
    int iteration = 0; // Current iteration
    
    while (s21_fabs(result * result - x) > EPSILON && iteration < max_iterations) {
        double next = 0.5 * (result + x / result); // Calculate the next approximation
        
        if (s21_fabs(next - result) < EPSILON) {
            // The difference between the current and next approximations is within the desired precision
            break;
        }
        
        result = next; // Update the current approximation
        iteration++; // Increment the iteration counter
    }
    
    return result;
}

// s21_tan
long double s21_tan(double x) {
    return s21_sin(x) / s21_cos(x);
}

// s21_pow
long double s21_pow(double base, double exp) {
    if (exp < 0)
        return 1.0 / s21_pow(base, -exp); // Handle negative exponent

    long double result = 1.0;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

// Function to compute the factorial of a number
long double s21_fact(int n) {
    long double fact = 1.0;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// s21_cos
long double s21_cos(double x) {
   long double result = 1.0; // Initialize the result
    int terms = 50;     // Number of terms to use in the series approximation

    // Compute the cosine value using the Taylor series
    for (int i = 1; i <= terms; i++) {
        int powerVal = 2 * i;
        int sign = i % 2 == 0 ? 1 : -1; // Alternate the sign of each term

       long double term = sign * s21_pow(x, powerVal) / s21_fact(powerVal);
        result += term;
    }

    return result;
}

// s21_acos
long double s21_acos(double x) {
    if (x > 1 || x < -1) {
        return s21_nan();
    }

    return (PI / 2) - s21_asin(x);
}

// s21_asin
long double s21_asin(double x) {
    if (x > 1 || x < -1) {
        return s21_nan();
    }
    
    double guess = x; // Initial guess for the root
    double delta; // Change in guess

    do {
        double f = s21_sin(guess) - x; // Calculate the function value
        double f_prime = s21_cos(guess); // Calculate the derivative
        delta = f / f_prime; // Calculate the change in guess
        guess -= delta; // Update the guess
    } while (delta > EPSILON || delta < -EPSILON); // Loop until the guess is within tolerance

    return guess;
}

// s21_tan
long double s21_atan(double x) {
    double numerator = x;
    double denominator = s21_sqrt(1 + s21_pow(x, 2));

    return s21_asin(numerator / denominator);
}