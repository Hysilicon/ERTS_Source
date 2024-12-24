#include "LMS.h"
#include "top.h"

void top_lms_filter(double input_signal, double desired_signal, double &output_signal) {
    lms_filter(input_signal, desired_signal, output_signal);
}
