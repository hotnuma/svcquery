#include "libapp.h"
#include "SvcQuery.h"

int main(int argc, char **argv)
{
    SvcQuery query;

    if (!query.execute(argc, argv))
        return 1;

    return 0;
}


