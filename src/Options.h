#ifndef OPTIONS_H
#define OPTIONS_H

#include <list>
#include <string>

#include "OutputFormat.h"

namespace ing2ofx
{

    /*!
     * Parse the options and return the other arguments.
     *
     * The class Options will parse the command line arguments.
     * First all the options (that start with - or --) are evaluated.
     * The allowed options are made available to the application.
     * In case an unknown option is encountered, then a usage message is shown and the application is stopped.
     *
     * Any remaining arguments (that are no options are considered filenames.
     * The application can iterate through the list of arguments.
     */
    class Options
    {
        private:
            /*!
             * The OutputFormat.
             */
            OutputFormat outputFormat;

            /*!
             * The list of command line argiments that are no options.
             */
            std::list<std::string> arguments;

        public:
            /*!
             * Parse the command line arguments.
             *
             * Create a new instance of this class and parse the command line arguments.
             * In case an unknown option is found, then an error message is displayed and the application exits.
             * \param[in] argc The number of elements in argv.
             * \param[in] argv The command line arguments.
             * \return The created instance.
             */
            Options(int argc, char *argv[]);

            /*!
             * Get the OutputFormat.
             *
             * Get the OutputFormat that is defined by the executable name or an option.
             * \return The OutputFormat.
             */
            OutputFormat getOutputFormat()
            {
                return outputFormat;
            }

            /*!
             * Get a new iterator to iterate over all the arguments.
             *
             * \return An iterator that points to the first elemnent of the arguments.
             */
            std::list<std::string>::const_iterator cbeginArguments()
            {
                return arguments.cbegin();
            }

            /*!
             * Get the end position of the iterator.
             *
             * \return An iterator that points to the position after the last element.
             */
            std::list<std::string>::const_iterator cendArguments()
            {
                return arguments.cend();
            }

    };

}
#endif
