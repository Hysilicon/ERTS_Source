#include <systemc.h>
#include <math.h>
#include "Testbench.h"


void Testbench::generate_signals() {

    /*double noise = 0.5; 
    double desired = 1.0; 

    for (int i = 0; i < 100; ++i) {
        input_signal.write(noise * (rand() % 100 / 100.0));
        desired_signal.write(desired);
        wait(10, SC_NS);
    }*/

    double A = 1.0; // Amplitude
    double f = 0.01; // Frequency (normalized)
    double noise_level = 0.5; // Noise amplitude

    double PI = 3.1416;

    for (int i = 0; i < 100; ++i) {
        double signal = A * sin(2 * PI * f * i); // Sine wave
        double noise = noise_level * ((rand() % 100 / 100.0) - 0.5); // Random noise
        input_signal.write(signal + noise);
        desired_signal.write(signal); // Assume desired signal is clean sine wave
        wait(10, SC_NS);
    }
}