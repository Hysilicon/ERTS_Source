#pragma once
#include <systemc.h>
#include "Filter.h"


SC_MODULE(Testbench) {

    sc_signal<double> input_signal;
    sc_signal<double> desired_signal;
    sc_signal<double> output_signal;

    LMSFilter* filter;

    void generate_signals();


    SC_CTOR(Testbench) {
        filter = new LMSFilter("LMSFilter");
        filter->input_signal(input_signal);
        filter->desired_signal(desired_signal);
        filter->output_signal(output_signal);

        SC_THREAD(generate_signals);
    }

    ~Testbench() {
        delete filter;
    }
};