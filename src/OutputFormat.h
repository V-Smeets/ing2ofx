#ifndef OUTPUT_FORMAT_H
#define OUTPUT_FORMAT_H

#include <string>

namespace ing2ofx
{

    /*!
     * An enumeration the defines the output format.
     */
    enum class OutputFormat
    {
        /*!
         * The output format os OFX.
         */
        OFX,
        /*!
         * The output format is MT940.
         */
        MT940,
    };

    /*!
     * Convert the OutputFormat to a string.
     *
     * \param[in] outputFormat The OutputFormat.
     * \return A string representation of the OutputFormat.
     */
    std::string OutputFormatToString(OutputFormat outputFormat);

}
#endif
