#include <stdio.h>

#include "adt/sds.h"

#include "xv6.h"

int main()
{
        sds_t s = sdsEmpty();

        printf("hello xv6.\n");
        struct emulator_t* em = emulatorNew();

        emulatorDump(em, &s);

        printf("%s\n", s);
        emulatorFree(em);
        sdsFree(s);
        return 0;
}
