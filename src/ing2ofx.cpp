#include <cstdlib>
#include <iostream>

#include "Options.h"
#include "OutputFormat.h"
#include "ReadCsvFile.h"

int main(int argc, char *argv[])
{
    ing2ofx::Options options = ing2ofx::Options(argc, argv);

    for (auto it = options.cbeginArguments(); it != options.cendArguments(); it++)
    {
        ing2ofx::ReadCsvFile readCsvFile = ing2ofx::ReadCsvFile(*it);
    }

    return EXIT_SUCCESS;
}
