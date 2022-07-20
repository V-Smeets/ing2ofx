#ifndef READ_CSV_FILE_H
#define READ_CSV_FILE_H

#include <string>

namespace ing2ofx
{

    class ReadCsvFile
    {
        private:
            std::string filename;
        public:
            ReadCsvFile(std::string filename): filename(filename){}

            int getStatement();
    };

}
#endif
