#include <iostream>
#include <cmath>
#include "top.h"

const int NUM_SAMPLES = 100;


int main() {
    double input_signal, desired_signal, output_signal;


    for (int i = 0; i < NUM_SAMPLES; ++i) {
        input_signal = sin(2 * M_PI * 0.01 * i);
        desired_signal = input_signal;

        top_lms_filter(input_signal, desired_signal, output_signal);

//        std::cout << "Input: " << input_signal
//                          << ", Desired: " << desired_signal
//                          << ", Output: " << output_signal
//                          << std::endl;


    }


    std::cout << "Simulation complete." << std::endl;
    return 0;
}
