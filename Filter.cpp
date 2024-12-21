#include <systemc.h>
#include "Filter.h"

void LMSFilter::filter() {

    // Shift the input buffer
    for (int i = FILTER_ORDER - 1; i > 0; --i) {
        inputs[i] = inputs[i - 1];
    }
    inputs[0] = input_signal.read();

    // Calculate the output
    double output = 0.0;
    for (int i = 0; i < FILTER_ORDER; ++i) {
        output += weights[i] * inputs[i];
    }
    output_signal.write(output);

    // Calculate the error
    error = desired_signal.read() - output;

    // Update the weights
    for (int i = 0; i < FILTER_ORDER; ++i) {
        weights[i] += 2 * STEP_SIZE * error * inputs[i];
    }

    std::cout << "Output: " << output << ", Error: " << error << std::endl;

    static int iteration = 0;

    results_file << iteration++ << "," << output << "," << error << "\n";

}