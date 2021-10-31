#include "SvcList.h"
#include "SvcEntry.h"

#include <CFile.h>
#include <CProcess.h>
#include <stdlib.h>

#include <print.h>

DELETEFUNC(SvcEntry)

SvcList::SvcList()
{
    SETDELETEFUNC(&_entryList, SvcEntry);
}

bool SvcList::queryAll()
{
    CString cmd = "systemctl --no-pager list-units --type=service";

    CProcess process;
    if (!process.start(cmd, CP_PIPEOUT))
    {
        print("start failed");

        return -1;
    }

    int status = process.exitStatus();

    if (status != 0)
    {
        print("program returned : %d", status);

        return -1;
    }

    char *ptr = process.outBuff.data();
    CString line;

    if (!strGetLine(&ptr, line))
        return false;

    while (strGetLine(&ptr, line))
    {
        if (!line.startsWith("  "))
            continue;

        SvcEntry *entry = new SvcEntry();

        if (!entry->readLineTxt(line))
        {
            delete entry;
            continue;
        }

        print(entry->unit);

        _entryList.append(entry);
    }

    return true;
}

bool SvcList::writeTxt(const CString &filepath)
{
    CFile outfile;

    if (!outfile.open(filepath, "wb"))
        return false;

    SvcEntry::writeHeaderTxt(outfile);

    int size = _entryList.size();

    for (int i = 0; i < size; ++i)
    {
        SvcEntry *entry = (SvcEntry*) _entryList[i];
        entry->writeLineTxt(outfile);
    }

    return true;
}


