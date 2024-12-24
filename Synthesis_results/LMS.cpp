#include "LMS.h"
// LMS Filter Function
void lms_filter(double input_signal, double desired_signal, double &output_signal) {

	#pragma HLS PIPELINE II=1
    static double weights[FILTER_ORDER] = {0.0}; // Static weights array
    static double inputs[FILTER_ORDER] = {0.0};  // Static input buffer
    double error = 0.0;

    // Shift the input buffer
    for (int i = FILTER_ORDER - 1; i > 0; --i) {
        inputs[i] = inputs[i - 1];
    }
    inputs[0] = input_signal;

    // Calculate the output
    output_signal = 0.0;
    for (int i = 0; i < FILTER_ORDER; ++i) {
        output_signal += weights[i] * inputs[i];
    }

    // Calculate the error
    error = desired_signal - output_signal;

    // Update the weights
    for (int i = 0; i < FILTER_ORDER; ++i) {
        weights[i] += 2 * STEP_SIZE * error * inputs[i];
    }

    // Debug Output
//    std::cout << "Input: " << input_signal
//              << ", Desired: " << desired_signal
//              << ", Output: " << output_signal
//              << ", Error: " << error << std::endl;
}

