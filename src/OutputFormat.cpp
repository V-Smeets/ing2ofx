#include <cstdlib>

#include "OutputFormat.h"

namespace ing2ofx
{

    std::string OutputFormatToString(OutputFormat outputFormat)
    {
        switch (outputFormat)
        {
            case OutputFormat::MT940:
                return std::string("MT940");
            case OutputFormat::OFX:
                return std::string("OFX");
            default:
                std::abort();
        }
    }

}
