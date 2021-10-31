#ifndef SVCLIST_H
#define SVCLIST_H

#include <CString.h>
#include <CList.h>

class SvcEntry;

class SvcList
{
public:

    SvcList();

    bool queryAll();
    bool writeTxt(const CString &filepath);

private:

    CList _entryList;

};

#endif // SVCLIST_H


