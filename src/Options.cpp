#include <cstddef>
#include <cstdlib>
#include <getopt.h>
#include <iostream>
#include <string>

#include "Options.h"

namespace ing2ofx
{

    #define OPTION_MT940_LONG   "mt940"
    #define OPTION_MT940_SHORT  'm'
    #define OPTION_OFX_LONG     "ofx"
    #define OPTION_OFX_SHORT    'o'
    #define OPTION_NULL_SHORT   '\0'

    Options::Options(int argc, char *argv[])
    {
        static char shortopts[] =
        {
            OPTION_MT940_SHORT,
            OPTION_OFX_SHORT,
            OPTION_NULL_SHORT
        };
        static struct option longopts[] =
        {
            {OPTION_MT940_LONG, no_argument, NULL, OPTION_MT940_SHORT},
            {OPTION_OFX_LONG,   no_argument, NULL, OPTION_OFX_SHORT},
            {NULL,              no_argument, NULL, OPTION_NULL_SHORT}
        };

        outputFormat = OutputFormat::DEFAULT_FORMAT;
        int longindex;
        int c;
        while ((c = getopt_long(argc, argv, shortopts, longopts, &longindex)) != -1)
        {
            switch (c)
            {
                case OPTION_MT940_SHORT:
                    outputFormat = OutputFormat::MT940;
                    break;
                case OPTION_OFX_SHORT:
                    outputFormat = OutputFormat::OFX;
                    break;
                default:
                    std::cerr << "Usage: " << argv[0] << " [options] [file..]" << std::endl;
                    std::cerr << std::endl;
                    std::cerr << "Options:" << std::endl;
                    std::cerr << "\t-" << OPTION_MT940_SHORT << std::endl;
                    std::cerr << "\t--" << OPTION_MT940_LONG << std::endl;
                    std::cerr << "\t\tSet output format to MT940." << std::endl;
                    std::cerr << "\t-" << OPTION_OFX_SHORT << std::endl;
                    std::cerr << "\t--" << OPTION_OFX_LONG << std::endl;
                    std::cerr << "\t\tSet output format to OFX." << std::endl;
                    exit(EXIT_FAILURE);
            }
        }
        while (optind < argc)
        {
            arguments.push_back(std::string(argv[optind++]));
        }
    }

}
