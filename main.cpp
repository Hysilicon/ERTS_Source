#include <systemc.h>
#include "Testbench.h"

int sc_main(int argc, char* argv[]) {
    Testbench tb("Testbench");
    sc_core::sc_start();
    return 0;
}
