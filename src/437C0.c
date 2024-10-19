#include "global.h"

extern s32 D_801107D8[];
extern u16 D_80110918;

extern void* D_80110184;
extern s32* D_8011091C;
extern s32 D_80160480;

void func_80042BC0(void) {
    s32* var_v0;
    s32 var_v1;

    var_v0 = D_80110184;
    if (var_v0 == NULL) {
        D_8011091C = &D_80160480;
        return;
    }
    
    var_v1 = var_v0[1];
    while (var_v1 != NULL) {
        var_v0 = var_v1;
        var_v1 = var_v0[1];
    }
    
    D_8011091C = var_v0[3] + var_v0[2];
}

void func_80042C20(void) {
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/437C0/func_80042C28.s")

extern u16 D_80110918;

typedef struct SegaCD {
    s32 unk_0;
    char pad_4[0xD];
    s8 unk_11;
    char pad_12[0x1F];
} SegaCD;

void* func_80042CDC(void) {
    SegaCD* temp_v0;

    if ((s32) D_80110918 >= 0x50) {
        return NULL;
    }
    temp_v0 = D_801107D8[D_80110918];
    temp_v0->unk_11 = 1;
    D_80110918++;
    
    return temp_v0;
}

void func_80042D28(s8* arg0) {
    D_80110918--;
    D_801107D8[D_80110918] = (s32) arg0;
    arg0[0x11] = 0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/437C0/func_80042D58.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/437C0/func_80042EE4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/437C0/func_80042FA0.s")

typedef struct UnkStruct_D_801101A0 {
    s32 unk_0;
    char pad[0x10];
} UnkStruct_D_801101A0;

extern UnkStruct_D_801101A0 D_801101A0[];

s32 func_80043040(s32 arg0) {
    return D_801101A0[arg0].unk_0;
}

typedef struct Size0x14 {
    u8 unk_0;
    char pad[0x10];
    u8 unk_11;
    char pad2[0x2];
} Size0x14;

extern Size0x14 D_80110198[];

void func_80043060(s32 arg0) {
    Size0x14* temp_v0;

    temp_v0 = (Size0x14*) &D_80110198[arg0].unk_0;
    if (temp_v0->unk_11 != 0) {
        temp_v0->unk_11 = 2;
    }
}

void func_80043094(s32 arg0) {
    Size0x14* temp_v0;

    temp_v0 = (Size0x14*) &D_80110198[arg0].unk_0;
    if (temp_v0->unk_11 != 0) {
        temp_v0->unk_11 = 1;
    }
}
