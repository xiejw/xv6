#ifndef XV6_H_
#define XV6_H_

#include <stdint.h>

#include "adt/sds.h"
#include "adt/vec.h"

#define REGISTERS_COUNT 33

enum register_t {
        reg_x0,
        reg_x1,
        reg_x2,
        reg_x3,
        reg_x4,
        reg_x5,
        reg_x6,
        reg_x7,
        reg_x8,
        reg_x9,
        reg_x10,
        reg_x11,
        reg_x12,
        reg_x13,
        reg_x14,
        reg_x15,
        reg_x16,
        reg_x17,
        reg_x18,
        reg_x19,
        reg_x20,
        reg_x21,
        reg_x22,
        reg_x23,
        reg_x24,
        reg_x25,
        reg_x26,
        reg_x27,
        reg_x28,
        reg_x29,
        reg_x31,
        reg_x32,
        reg_pc,
};

struct emulator_t {
        uint64_t registers[REGISTERS_COUNT];
        vec_t(uint8_t) memory;
        unsigned int pc;
};

struct emulator_t* emulatorNew();
void               emulatorFree(struct emulator_t*);
void               emulatorDump(struct emulator_t*, sds_t* s);

#endif
