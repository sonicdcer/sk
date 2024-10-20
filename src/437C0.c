#include "global.h"

typedef struct SceneList {
    struct SceneList* unk_0;
    struct SceneList* unk_4;
    /* 0x08 */ u32 unk_8;
    /* 0x0C */ u32 unk_C;
    /* 0x10 */ u8 unk_10;
    /* 0x11 */ u8 unk_11;
    /* 0x12 */ char pad12[2];
} SceneList; // size = 0x14

extern SceneList D_80110198[];
extern SceneList* D_801107D8[];
extern SceneList D_80110180;
extern u16 D_80110918;
extern u16 D_80110918;

extern void* D_80110184;
extern u32 D_8011091C;
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

SceneList* func_80042CDC(void) {
    SceneList* node;

    if (D_80110918 >= 80) {
        return NULL;
    }
    node = D_801107D8[D_80110918];
    node->unk_11 = 1;
    D_80110918 += 1;
    return node;
}

void func_80042D28(SceneList* arg0) {
    D_80110918--;
    D_801107D8[D_80110918] = arg0;
    arg0->unk_11 = 0;
}

// regalloc and return type problems
// https://decomp.me/scratch/N4Mfa
#ifndef NON_MATCHING
#pragma GLOBAL_ASM("asm/us/nonmatchings/437C0/func_80042D58.s")
#else
s32 func_80042D58(uintptr_t addr) {
    SceneList* node1 = D_80110180.unk_4;
    SceneList* node2;
    SceneList* node3;

    while (node1 != NULL) {

        if (node1->unk_4 == NULL) {
            break;
        }

        if ((u32) ((node1->unk_4->unk_8 - node1->unk_8) - node1->unk_C) >= ALIGN16(addr)) {
            node3 = func_80042CDC();
            if (node3 == NULL) {
                return -1;
            }
            node3->unk_0 = node1;
            node3->unk_4 = node1->unk_4;
            if (node1->unk_4 != NULL) {
                node1->unk_4->unk_0 = node3;
            }
            node1->unk_4 = node3;
            node3->unk_8 = node1->unk_8 + node1->unk_C;
            node3->unk_C = ALIGN16(addr);
            return node3->unk_10;
        }
        node1 = node1->unk_4;
    }

    if ((u32) ((D_8011091C + ALIGN16(addr)) - (u32) &D_80160480) > 0x1C0000) {
        return -1;
    }

    if (node1 == NULL) {
        node1 = &D_80110180;
    }

    node2 = func_80042CDC();
    if (node2 == NULL) {
        return -1;
    }

    node2->unk_0 = node1;
    node2->unk_4 = node1->unk_4;

    if (node1->unk_4 != NULL) {
        node1->unk_4->unk_0 = node2;
    }
    node1->unk_4 = node2;
    node2->unk_8 = D_8011091C;
    node2->unk_C = ALIGN16(addr);

    func_80042BC0();

    return (u8) node2->unk_10;
}
#endif

s32 func_80042EE4(s32 arg0) {
    SceneList* node;

    if (arg0 == -1) {
        return -1;
    } else {
        node = &D_80110198[arg0];
        if (node->unk_11 != 0) {
            if (node->unk_4 == NULL) {
                D_8011091C -= node->unk_C;
            }
            node->unk_0->unk_4 = node->unk_4;
            if (node->unk_4 != NULL) {
                node->unk_4->unk_0 = node->unk_0;
            }
            func_80042D28(node);
            func_80042BC0();
        }
        return -1;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/437C0/func_80042FA0.s")

typedef struct UnkStruct_D_801101A0 {
    s32 unk_0;
    char pad[0x10];
} UnkStruct_D_801101A0;

extern UnkStruct_D_801101A0 D_801101A0[];

s32 func_80043040(s32 arg0) {
    return D_801101A0[arg0].unk_0;
}

void func_80043060(s32 arg0) {
    SceneList* temp_v0;

    temp_v0 = (SceneList*) &D_80110198[arg0].unk_0;
    if (temp_v0->unk_11 != 0) {
        temp_v0->unk_11 = 2;
    }
}

void func_80043094(s32 arg0) {
    SceneList* temp_v0;

    temp_v0 = (SceneList*) &D_80110198[arg0].unk_0;
    if (temp_v0->unk_11 != 0) {
        temp_v0->unk_11 = 1;
    }
}
