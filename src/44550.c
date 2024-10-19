#include "global.h"

s32 func_80042D58(u32);
s32 func_80043040(s16);
s32 func_80043060(s16);
s32 func_800437F0(s32*, s32*, s32);
s32 func_8007D190();
s32 func_80099C44(void*, s32, s32);

extern s16 D_80112130[];

// Some kind of scene loader
void func_80043950(void) {
    u32 temp_a0;

    switch (D_80121B50) {
        case 0:
            temp_a0 = (u32) &D_EC9A0 - (u32) &D_E35C0;
            D_80112130[8] = func_80042D58(temp_a0);
            func_80043060(D_80112130[8]);
            func_80099C44(&D_E35C0, func_80043040(D_80112130[8]), temp_a0);
            func_800437F0(&D_163410, &D_171480, 9);
            func_800437F0(&D_21D9D0, &D_222500, 0x1B);
            func_8007D190();
            func_800437F0(&D_1EC0F0, &D_1EC4A0, 0x1D);
            break;

        case 1:
            temp_a0 = (u32) &D_F6160 - (u32) &D_EC9A0;
            D_80112130[8] = func_80042D58(temp_a0);
            func_80043060(D_80112130[8]);
            func_80099C44(&D_EC9A0, func_80043040(D_80112130[8]), temp_a0);
            func_800437F0(&D_171480, &D_17D220, 9);
            func_800437F0(&D_222500, &D_2274A0, 0x1B);
            func_8007D190();
            func_800437F0(&D_1EC4A0, &D_1EC810, 0x1D);
            break;

        case 2:
            temp_a0 = (u32) &D_FEDA0 - (u32) &D_F6160;
            D_80112130[8] = func_80042D58(temp_a0);
            func_80043060(D_80112130[8]);
            func_80099C44(&D_F6160, func_80043040(D_80112130[8]), temp_a0);
            func_800437F0(&D_17D220, &D_186910, 9);
            func_800437F0(&D_2274A0, &D_22AE50, 0x1B);
            func_8007D190();
            func_800437F0(&D_1EC810, &D_1ECD00, 0x1D);
            break;

        case 3:
            temp_a0 = (u32) &D_10AAB0 - (u32) &D_FEDA0;
            D_80112130[8] = func_80042D58(temp_a0);
            func_80043060(D_80112130[8]);
            func_80099C44(&D_FEDA0, func_80043040(D_80112130[8]), temp_a0);
            func_800437F0(&D_186910, &D_197490, 9);
            func_800437F0(&D_22AE50, &D_2308E0, 0x1B);
            func_8007D190();
            func_800437F0(&D_1ECD00, &D_1ED910, 0x1D);
            break;

        case 4:
            temp_a0 = (u32) &D_118670 - (u32) &D_10AAB0;
            D_80112130[8] = func_80042D58(temp_a0);
            func_80043060(D_80112130[8]);
            func_80099C44(&D_10AAB0, func_80043040(D_80112130[8]), temp_a0);
            func_800437F0(&D_197490, &D_1A5620, 9);
            func_800437F0(&D_2308E0, &D_2349E0, 0x1B);
            func_8007D190();
            func_800437F0(&D_1ED910, &D_1EDC80, 0x1D);
            break;

        case 5:
            temp_a0 = (u32) &D_125C90 - (u32) &D_118670;
            D_80112130[8] = func_80042D58(temp_a0);
            func_80043060(D_80112130[8]);
            func_80099C44(&D_118670, func_80043040(D_80112130[8]), temp_a0);
            func_800437F0(&D_1A5620, &D_1B3160, 9);
            func_800437F0(&D_2349E0, &D_23A7D0, 0x1B);
            func_8007D190();
            func_800437F0(&D_1EDC80, &D_1EE060, 0x1D);
            break;

        case 6:
            temp_a0 = (u32) &D_131A90 - (u32) &D_125C90;
            D_80112130[8] = func_80042D58(temp_a0);
            func_80043060(D_80112130[8]);
            func_80099C44(&D_125C90, func_80043040(D_80112130[8]), temp_a0);
            func_800437F0(&D_1B3160, &D_1C24B0, 9);
            func_800437F0(&D_23A7D0, &D_23E9D0, 0x1B);
            func_8007D190();
            func_800437F0(&D_1EE060, &D_1EEEA0, 0x1D);
            break;

        case 7:
            temp_a0 = (u32) &D_1384B0 - (u32) &D_131A90;
            D_80112130[8] = func_80042D58(temp_a0);
            func_80043060(D_80112130[8]);
            func_80099C44(&D_131A90, func_80043040(D_80112130[8]), temp_a0);
            func_800437F0(&D_1C24B0, &D_1C9630, 9);
            func_800437F0(&D_23E9D0, &D_23FCC0, 0x1B);
            func_8007D190();
            break;

        case 8:
            temp_a0 = (u32) &D_13F3B0 - (u32) &D_1384B0;
            D_80112130[8] = func_80042D58(temp_a0);
            func_80043060(D_80112130[8]);
            func_80099C44(&D_1384B0, func_80043040(D_80112130[8]), temp_a0);
            func_800437F0(&D_1C9630, &D_1D3070, 9);
            func_800437F0(&D_23FCC0, &D_241160, 0x1B);
            func_8007D190();
            func_800437F0(&D_1EEEA0, &D_1EF1D0, 0x1D);
            break;

        case 9:
            temp_a0 = (u32) &D_145380 - (u32) &D_13F3B0;
            D_80112130[8] = func_80042D58(temp_a0);
            func_80043060(D_80112130[8]);
            func_80099C44(&D_13F3B0, func_80043040(D_80112130[8]), temp_a0);
            func_800437F0(&D_1D3070, &D_1D82B0, 9);
            func_800437F0(&D_241160, &D_2427D0, 0x1B);
            func_8007D190();
            func_800437F0(&D_1EF1D0, &D_1EF530, 0x1D);
            break;
    }
    temp_a0 = (u32) &D_14B450 - (u32) &D_147910;
    D_80112130[10] = func_80042D58(temp_a0);
    func_80043060(D_80112130[10]);
    func_80099C44(&D_147910, func_80043040(D_80112144), temp_a0);
    func_800437F0(&D_1D82B0, &D_1DCED0, 0xB);
    func_800437F0(&D_1E74E0, &D_1EC0F0, 0x1C);
    func_800437F0(&D_5DAF30, &D_5DB9D0, 0x2A);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/44550/func_800440F4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/44550/func_80044294.s")
