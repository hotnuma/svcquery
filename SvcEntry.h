#ifndef SVCENTRY_H
#define SVCENTRY_H

#include <CFile.h>

class SvcEntry
{
public:

    SvcEntry();

    bool readLineTxt(const CString &buffer);

    static bool writeHeaderTxt(CFile &outfile);
    bool writeLineTxt(CFile &outfile);

    //bool writeLineCsv(CFile &outfile);

    CString unit;
    //CString load;
    //CString active;
    CString sub;
    CString description;

};

#endif // SVCENTRY_H


