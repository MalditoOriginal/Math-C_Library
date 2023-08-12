#include "s21_math.h"

long double s21_isnan(double x) { return x != x; }

// s21_abs
int s21_abs(int x) { return x < 0 ? -x : x; }

// s21_fabs
long double s21_fabs(double x) { return x < 0 ? -x : x; }

// s21_pow
long double s21_pow(double base, double exp) {
  long double result = 0.0;

  if ((base == 0 && exp == 0) || (exp == 0))
    result = 1.0;
  else if (base == 0)
    result = 0.0;
  else if (s21_isnan(base) || s21_isnan(exp)) {
    if (s21_isnan(base) && s21_isnan(exp)) {
      result = S21_NAN;  // Both base and exponent are NaN
    }
  } else if ((base == NEG_INF) && (exp == POS_INF)) {
    result = POS_INF;
  } else if (exp && base == NEG_INF) {
    result = 0.0;  // Both base and exponent are negative infinity
  } else if (base < 0 && exp != 0 && s21_fmod(exp, 1.0) != 0.0) {
    result = S21_NAN;  // Negative base and fractional exponent
   } else if (exp < 0) {
     result = 1.0;
  } else if (exp > 0) {
    result = s21_exp(exp * s21_log(s21_fabs(base)));
    if (base < 0 && (int)exp % 2) result *= -1;
  }
  return result;
}

// s21_fmod
long double s21_fmod(double x, double y) {
  long double result = 0.0;

  if (y == POS_INF || y == NEG_INF) {
    if (x == POS_INF || x == NEG_INF) {
      result = S21_NAN;  // Handle division of infinities, result is NaN
    } else {
      result = x;  // y is infinity, return x
    }
  } else if (y == 0.0)
    result = S21_NAN;
  else {
    long double quotient = x / y;
    long double intPart =
        (long long)quotient;  // Get the integer part of the quotient
    // Calculate the remainder
    long double remainder = x - (intPart * y);
    result = remainder;
  }
  return result;
}

long double s21_ceil(double x) {
  long double result = 0.0;

  if (s21_isnan(x)) {
    result = S21_NAN;  // Return NaN if x is NaN
  } else if (x >= 0.0) {
    result = (long double)((
        long long)(x + PRECISION));  // Adding a small value to handle
                                     // floating-point precision
  } else {
    result = (long double)((long long)x);
  }
  return result;
}

// s21_floor
long double s21_floor(double x) {
  long double result = 0.0;

  if (s21_isnan(x)) {
    result = S21_NAN;  // Return NaN if x is NaN
  } else if (x >= 0.0) {
    result = (long double)((long long)x);
  } else {
    result = (long double)((
        long long)(x - PRECISION));  // Subtracting a small value to handle
                                     // floating-point precision
  }
  return result;
}

// s21_exp
long double s21_exp(double x) {
  long double result = 1.0;

  if (s21_isnan(x)) {
    return S21_NAN;  // Return NaN if x is NaN
  } else if (x >= 710) {
    return POS_INF;
  } else if (x > 0.0) {
    long double term = 1.0;
    for (long int n = 1; term > EPSILON; n++) {
      term *= x / n;
      result += term;
    }
  } else if (x < 0.0) {
    long double term = 1.0;
    for (long int n = 1; term > EPSILON; n++) {
      term *= -x / n;
      result += term;
    }
    result = 1/result;
  }

  return result;
}

// s21_log
long double s21_log(double x) {
  if (s21_isnan(x))
    return S21_NAN;  // Return NaN if x is NaN
  else if (x < 0)
    return S21_NAN;
  else if (x == 0)
    return NEG_INF;
  else {
  long double y = (x - 1.0) / (x + 1.0);
  long double term = y;
  long double termSquared = y * y;
  long double result = term;  // Initialize result with the first term
  long int n = 1;

  while (s21_fabs(term) > 1e-16) {
    term *= termSquared * (2 * n - 1) / (2 * n + 1);  // Series expansion
    result += term;
    n++;
  }

  return 2.0 * result;
}
}

// s21_sqrt
long double s21_sqrt(double x) {
  if (s21_isnan(x)) return S21_NAN;

  double result = x;  // Initial guess for the result

  if (x < 0) result = S21_NAN;
  // Newton's method
  while (s21_fabs(result * result - x) > EPSILON ) {
    double root =
        0.5 * (result + x / result);  // Calculate the next approximation
    result = root;                    // Update the current approximation
  }
  return result;
}

// s21_tan
long double s21_tan(double x) { return s21_sin(x) / s21_cos(x); }

// s21_sin
long double s21_sin(double x) {
  x = s21_fmod(x, 2 * PI);  // Make sure x is within the range of 0 to 2pi
  long double result = 0.0;
  long double term = x;

  for (int i = 1; i <= PRECISION_TERM; ++i) {
    result += term;
    term *= -(x * x) / ((2 * i) * (2 * i + 1));  // Series expansion
  }
  return result;
}

// s21_cos
long double s21_cos(double x) {
  // Adjust the input angle to the range [-2*PI, 2*PI]
  x = s21_fmod(x, 2 * PI);

  // Compute the cosine using the Taylor series expansion
  long double result = 1.0;  // Initial term of the series
  long double term = 1.0;    // Current term being added
  long double sign = -1.0;   // Sign of the current term

  for (int n = 2; term > EPSILON; n += 2) {
    term *= x * x / (n * (n - 1));  // Compute the next term
    result += sign * term;          // Add the next term to the result
    sign *= -1.0;                   // Change the sign for the next term
  }
  return result;
}

// s21_asin
long double s21_asin(double x) {
  if (s21_isnan(x)) return S21_NAN;

  long double result = 0.0;

  if (x > 1.0 || x < -1.0) {
    result = S21_NAN;
  } else {
    long double guess = x;  // Initial guess for the root
    long double delta;      // Change in guess
    do {
      long double func = s21_sin(guess) - x;    // Calculate the function value
      long double func_prime = s21_cos(guess);  // Calculate the derivative
      delta = func / func_prime;                // Calculate the change in guess
      guess -= delta;                           // Update the guess
    } while (s21_fabs(delta) >
             EPSILON);  // Loop until the guess is within tolerance

    result = guess;
  }

  return result;  // Return the final value
}

// s21_acos
long double s21_acos(double x) {
  if (s21_isnan(x)) return S21_NAN;

  long double result = 0.0;

  if (x > 1.0 || x < -1.0)
    result = S21_NAN;
  else if (x == 1)
    result = 0.0;
  else
    result = (PI / 2) - s21_asin(x);
  return result;
}

// s21_tan
long double s21_atan(double x) {
  if (s21_isnan(x)) return S21_NAN;
  long double result;

  if (x == 0.0)
    result = 0.0;
  else {
    double numerator = x;
    double denominator = s21_sqrt(1.0 + x * x);
    result = s21_asin(numerator / denominator);
  }
  return result;
}
