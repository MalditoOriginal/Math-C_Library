#include <check.h>
#include <math.h>
#include <stdlib.h>
#include "s21_math.h"

// Declare the unit test functions
START_TEST(test_abs_positive)
{
    int x;
    int s21_result;
    int math_result;

    // Test positive number
    x = 10;
    s21_result = s21_abs(x);
    math_result = abs(x);
    ck_assert_int_eq(s21_result, math_result);
}

START_TEST(test_abs_negative)
{
    int x;
    int s21_result;
    int math_result;

    // Test negative number
    x = -10;
    s21_result = s21_abs(x);
    math_result = abs(x);
    ck_assert_int_eq(s21_result, math_result);
}

START_TEST(test_abs_zero)
{
    int x;
    int s21_result;
    int math_result;

    // Test zero
    x = 0;
    s21_result = s21_abs(x);
    math_result = abs(x);
    ck_assert_int_eq(s21_result, math_result);
}
//s21_fmod
START_TEST(test_fmod_1)
{
            int x;
            int y;
            int s21_result;
            int math_result;

            x = 3;
            y = 5;
            s21_result = s21_fmod(x, y);
            math_result = fmod(x, y);
            ck_assert_ldouble_eq(s21_result, math_result);
}

START_TEST(test_fmod_2)
{
            int x;
            int y;
            int s21_result;
            int math_result;

            x = 1234;
            y = 345;
            s21_result = s21_fmod(x, y);
            math_result = fmod(x, y);
            ck_assert_ldouble_eq(s21_result, math_result);
}

// long double fabs(double x)
START_TEST(test_fabs_positive)
{
    double x = 2548;
    double s21_result;
    double math_result;

    s21_result = s21_fabs(x);
    math_result = fabs(x);

    ck_assert_ldouble_eq(s21_result, math_result); 
}

// ceil
START_TEST(test_ceil_positive)
{
    double x;
    double s21_result;
    double math_result;

    x = 2.4;
    s21_result = s21_ceil(x);
    math_result = ceil(x);

    ck_assert_ldouble_eq_tol(s21_result, math_result, 1e-6);
}

START_TEST(test_ceil_negative)
{
    double x;
    double s21_result;
    double math_result;

    x = -2.4;
    s21_result = s21_ceil(x);
    math_result = ceil(x);

    ck_assert_ldouble_eq_tol(s21_result, math_result, 1e-6);
}

// floor
START_TEST(test_floor_positive)
{
    double x;
    double s21_result;
    double math_result;

    x = 2.4;
    s21_result = s21_floor(x);
    math_result = floor(x);

    ck_assert_ldouble_eq_tol(s21_result, math_result, 1e-6);
}

START_TEST(test_floor_negative)
{
    double x;
    double s21_result;
    double math_result;

    x = -2.4;
    s21_result = s21_floor(x);
    math_result = floor(x);

    ck_assert_ldouble_eq_tol(s21_result, math_result, 1e-6);
}

// s21_pow
START_TEST(test_pow_positive)
{
    double x, y;
    double s21_result;
    double math_result;

    x = 2345634;
    y = 12341234;
    s21_result = s21_pow(x, y);
    math_result = pow(x, y);

    ck_assert_ldouble_eq(s21_result, math_result);
}

START_TEST(test_pow_negative_1)
{
    double x, y;
    double s21_result;
    double math_result;

    x = -2345634;
    y = 12341234;
    s21_result = s21_pow(x, y);
    math_result = pow(x, y);

    ck_assert_ldouble_eq(s21_result, math_result);
}

START_TEST(test_pow_negative_2)
{
    double x, y;
    double s21_result;
    double math_result;

    x = 2345634;
    y = -12341234;
    s21_result = s21_pow(x, y);
    math_result = pow(x, y);

    ck_assert_ldouble_eq(s21_result, math_result);
}

// s21_exp
START_TEST(test_exp_positive)
{
    double x;
    double s21_result;
    double math_result;

    x = 12.98;
    s21_result = s21_exp(x);
    math_result = exp(x);

    ck_assert_ldouble_eq_tol(s21_result, math_result, 1e-6);
}

START_TEST(test_exp_negative)
{
    double x;
    double s21_result;
    double math_result;

    x = -12.98;
    s21_result = s21_exp(x);
    math_result = exp(x);

    ck_assert_ldouble_eq_tol(s21_result, math_result, 1e-6);
}

START_TEST(test_cos) {
    double x;
    double s21_result;
    double math_result;

    x = 12;
    s21_result = s21_cos(x);
    math_result = cos(x);
    ck_assert_ldouble_eq_tol(s21_result, math_result, 1e-6);
}

START_TEST(test_sin) {
    double x;
    double s21_result;
    double math_result;

    x = 12;
    s21_result = s21_sin(x);
    math_result = sin(x);
    ck_assert_ldouble_eq_tol(s21_result, math_result, 1e-6);
}

// s21_log
START_TEST(test_sqrt_positive) {
    double x;
    double s21_result;
    double math_result;

    x = 999999999999;
    s21_result = s21_sqrt(x);
    math_result = sqrt(x);
    ck_assert_ldouble_eq(s21_result, math_result);
}

START_TEST(test_sqrt_zero) {
    double x;
    double s21_result;
    double math_result;

    x = 0;
    s21_result = s21_sqrt(x);
    math_result = sqrt(x);
    ck_assert_ldouble_eq(s21_result, math_result);
}

START_TEST(test_sqrt_negative) {
    double x;
    double s21_result;
    double math_result;

    x = -1;
    s21_result = s21_sqrt(x);
    math_result = sqrt(x);
    ck_assert(isnan(s21_result));
    ck_assert(isnan(math_result));
}

START_TEST(test_log_positive) {
    double x;
    double s21_result;
    double math_result;

    x = 4.56;
    s21_result = s21_log(x);
    math_result = log(x);
    ck_assert_ldouble_eq_tol(s21_result, math_result, 1e-6);
}

START_TEST(test_log_negative) {
    double x;
    double s21_result;
    double math_result;

    x = -1;
    s21_result = s21_log(x);
    math_result = log(x);
    ck_assert(isnan(s21_result));
    ck_assert(isnan(math_result));
}

START_TEST(test_log_zero) {
    double x;
    double s21_result;
    double math_result;

    x = 0;
    s21_result = s21_log(x);
    math_result = log(x);
    ck_assert(s21_result);
    ck_assert(math_result);
}
// long double acos(double x)
// START_TEST(test_acos_positive)
// {
//     double x = 0.5;
//     double s21_result = s21_acos(x);
//     double math_result = acos(x);
    
//     ck_assert_double_eq_tol(s21_result, math_result, 1e-6);
// }
// END_TEST

// START_TEST(test_acos_negative)
// {
//     double x = -0.5;
//     double s21_result = s21_acos(x);
//     double math_result = acos(x);
    
//     ck_assert_double_eq_tol(s21_result, math_result, 1e-6);
// }
// END_TEST

// Add more unit tests for other functions

// Create the test suite
Suite* s21_math_suite(void)
{
    Suite* suite = suite_create("s21_math");

    // Create a test case for abs
    TCase* tc_abs = tcase_create("abs");
    tcase_add_test(tc_abs, test_abs_positive);
    tcase_add_test(tc_abs, test_abs_negative);
    tcase_add_test(tc_abs, test_abs_zero);
    TCase* tc_acos = tcase_create("acos");
    // tcase_add_test(tc_acos, test_acos_positive);
    // tcase_add_test(tc_acos, test_acos_negative);
    suite_add_tcase(suite, tc_abs);
    suite_add_tcase(suite, tc_acos);
    // Add more test cases for other functions
    // fabs
    TCase* tc_fabs = tcase_create("fabs");
    tcase_add_test(tc_fabs, test_fabs_positive);
    suite_add_tcase(suite, tc_fabs);

    // fmod
    TCase* tc_fmod = tcase_create("fmod");
    tcase_add_test(tc_fmod, test_fmod_1);
    tcase_add_test(tc_fmod, test_fmod_2);
    suite_add_tcase(suite, tc_fmod);

    //ceil
    TCase* tc_ceil = tcase_create("ceil");
    tcase_add_test(tc_ceil, test_ceil_positive);
    tcase_add_test(tc_ceil, test_ceil_negative);
    suite_add_tcase(suite, tc_ceil);

    //floor
    TCase* tc_floor = tcase_create("floor");
    tcase_add_test(tc_floor, test_floor_positive);
    tcase_add_test(tc_floor, test_floor_negative);
    suite_add_tcase(suite, tc_floor);
    
    // pow
    TCase* tc_pow = tcase_create("pow");
    tcase_add_test(tc_pow, test_pow_positive);
    tcase_add_test(tc_pow, test_pow_negative_1);
    tcase_add_test(tc_pow, test_pow_negative_2);
    suite_add_tcase(suite, tc_pow);

    // exp
    TCase* tc_exp = tcase_create("exp");
    tcase_add_test(tc_exp, test_exp_positive);
    tcase_add_test(tc_exp, test_exp_negative);
    suite_add_tcase(suite, tc_exp);

    // cos
    TCase* tc_cos = tcase_create("cos");
    tcase_add_test(tc_cos, test_cos);
    suite_add_tcase(suite, tc_cos);

    // sin
    TCase* tc_sin = tcase_create("sin");
    tcase_add_test(tc_sin, test_sin);
    suite_add_tcase(suite, tc_sin);

    // sqrt
    TCase* tc_sqrt = tcase_create("sqrt");
    tcase_add_test(tc_sqrt, test_sqrt_positive);
    tcase_add_test(tc_sqrt, test_sqrt_negative);
    tcase_add_test(tc_sqrt, test_sqrt_zero);
    suite_add_tcase(suite, tc_sqrt);

    // log
    TCase* tc_log = tcase_create("log");
    tcase_add_test(tc_log, test_log_positive);
    tcase_add_test(tc_log, test_log_negative);
    tcase_add_test(tc_log, test_log_zero);
    suite_add_tcase(suite, tc_log);

    return suite;
}

// Run the test suite
int main(void)
{
    Suite* suite = s21_math_suite();
    SRunner* runner = srunner_create(suite);
    srunner_run_all(runner, CK_VERBOSE);
    int number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    
    // Run gcov to get coverage report
    system("gcov s21_math.c");
    
    return number_failed == 0 ? 0 : 1;
}
