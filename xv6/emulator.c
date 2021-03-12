#include "xv6.h"

#include <string.h>

struct emulator_t* emulatorNew()
{
        struct emulator_t* p = malloc(sizeof(struct emulator_t));
        memset(p->registers, 0, sizeof(uint64_t) * REGISTERS_COUNT);
        p->memory = vecNew();
        p->pc     = 0;
        return p;
}

void emulatorFree(struct emulator_t* p)
{
        if (p == NULL) return;
        vecFree(p->memory);
        free(p);
}

void emulatorDump(struct emulator_t* em, sds_t* s)
{
        for (int i = 0; i < REGISTERS_COUNT; i++) {
                if (i == REGISTERS_COUNT - 1) {
                        sdsCatPrintf(s, "reg pc: %d\n", em->registers[i]);
                } else {
                        sdsCatPrintf(s, "reg %2d: %d\t", i, em->registers[i]);
                        if (i % 8 == 7) {
                                sdsCatPrintf(s, "\n");
                        }
                }
        }
}
