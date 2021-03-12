#include "xv6.h"

struct emulator_t* emulatorNew()
{
        struct emulator_t* p = malloc(sizeof(struct emulator_t));
        p->memory            = vecNew();
        p->pc                = 0;
        return p;
}

void emulatorFree(struct emulator_t* p)
{
        if (p == NULL) return;
        vecFree(p->memory);
        free(p);
}
