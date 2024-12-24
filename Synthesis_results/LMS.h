#pragma once
#include <iostream>
#include <cmath>

const int FILTER_ORDER = 32; // Number of filter coefficients
const double STEP_SIZE = 0.01; // Step size (mu)

void lms_filter(double input_signal, double desired_signal, double &output_signal);


