#pragma once
#include <systemc.h>
#include <iostream>
#include <fstream>
#include <vector>


using namespace sc_core;

// Define the filter parameters
const int FILTER_ORDER = 64; // Number of filter coefficients
const double STEP_SIZE = 0.01; // Step size (mu)

SC_MODULE(LMSFilter) {

    sc_in<double> input_signal;      // Input signal (x[n])
    sc_in<double> desired_signal;    // Desired signal (d[n])
    sc_out<double> output_signal;    // Filtered output (y[n])


    std::vector<double> weights;     // Filter weights
    std::vector<double> inputs;      // Input buffer
    double error;             // Error signal

    std::ofstream results_file;

    void filter();

    SC_CTOR(LMSFilter) : weights(FILTER_ORDER, 0.0), inputs(FILTER_ORDER, 0.0), error(0.0) {

        results_file.open("lms_results.csv");
        results_file << "Iteration,Output,Error\n"; 
        SC_METHOD(filter);
        sensitive << input_signal << desired_signal;
    }

    ~LMSFilter() {
        if (results_file.is_open()) {
            results_file.close();
        }
    }
};
