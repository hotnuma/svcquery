#include "SvcQuery.h"

#include <libapp.h>
#include <libpath.h>

#include <print.h>

enum class ExecCmd
{
    None,
    Export
};

SvcQuery::SvcQuery()
{
}

bool SvcQuery::execute(int argc, char **argv)
{
    CString homeDir = getHomeDirectory();
    CString outpath = pathJoin(getHomeDirectory(), "sys_svcquery.txt");

    int n = 1;
    while (n < argc)
    {
        const CString &part = argv[n];

        if (part == "-o")
        {
            if (++n >= argc)
                return false;

            outpath = argv[n];
        }
        else
        {
            print("*** Invalid option.");
            return false;
        }

        n++;
    }

    if (!_svclist.queryAll())
    {
        print("*** PrcList error.");
        return false;
    }

    _svclist.writeTxt(outpath);

    return true;
}


