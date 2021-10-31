#ifndef SVCQUERY_H
#define SVCQUERY_H

#include "SvcList.h"

class SvcQuery
{
public:

    SvcQuery();

    bool execute(int argc, char **argv);

private:

    SvcList _svclist;

};

#endif // SVCQUERY_H


