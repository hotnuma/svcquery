#include "SvcEntry.h"
#include <libstr.h>
#include <libpath.h>
#include <ctype.h>
#include <string.h>

#include <print.h>

#define SEP_TAB     "\t"
#define SEP_SPACE   " "

#define COL_UNIT    26
#define COL6        6
#define COL7        7

SvcEntry::SvcEntry()
{
}

bool SvcEntry::readLineTxt(const CString &buffer)
{
    if (buffer.isEmpty())
        return false;

    int nparts = 5;

    char *ptr = buffer.data();
    char *part;
    int len;

    int count = 1;
    while (count < nparts && strGetPart(&ptr, &part, &len))
    {
        part[len] = '\0';

        switch (count)
        {
        case 1:
        {
            unit = part;
            const char *ext = pathExt(unit);
            if (ext)
                unit.terminate(ext - unit.c_str());
            break;
        }
        case 4:
        {
            if (strcmp("exited", part) != 0)
                sub = part;
            break;
        }
        }

        ++count;
    }

    while(isspace(*ptr)) ++ptr;

    // end of buffer ?
    if (*ptr == '\0')
        return false;

    description = ptr;

    return true;
}

bool SvcEntry::writeHeaderTxt(CFile &outfile)
{
    CString col;

    col = "Unit";
    strPadRight(col, COL_UNIT, ' ');
    outfile << col;

    outfile << SEP_SPACE;

    col = "Sub";
    strPadRight(col, COL7, ' ');
    outfile << col;

    outfile << SEP_SPACE;

    outfile << "Description";

    outfile << "\n";

    return true;
}

bool SvcEntry::writeLineTxt(CFile &outfile)
{
    strEllipsize(unit, COL_UNIT, "+");
    strPadRight(unit, COL_UNIT, ' ');
    outfile << unit;

    outfile << SEP_SPACE;

    strEllipsize(sub, COL7, "+");
    strPadRight(sub, COL7, ' ');
    outfile << sub;

    outfile << SEP_SPACE;

    outfile << description;

    outfile << "\n";

    return true;
}

//bool SvcEntry::writeLineCsv(CFile &outfile)
//{
//    outfile << unit;
//    outfile << SEP_TAB;
//    outfile << user;
//    outfile << SEP_TAB;
//    outfile << pid;
//    outfile << SEP_TAB;
//    outfile << command;

//    outfile << "\n";

//    return true;
//}


