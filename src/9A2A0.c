// #include "global.h"
#include "PR/os_thread.h"
#include "PR/os_message.h"
#include "PR/os_pi.h"

extern OSThread sIdleThread;
extern OSThread gMainThread;
extern u8 sIdleThreadStack[];
extern OSMesgQueue gPiMgrCmdQueue;
extern OSMesg sPiMgrCmdBuff[50];  // might be wrong, as the real address could be sPiMgrCmdBuff - 50
extern u8 sMainThreadStack[4096]; // might be wrong, as the real address could be in sMainThreadStack - 4096

void osCreatePiManager(OSPri pri, OSMesgQueue* cmdQ, OSMesg* cmdBuf, s32 cmdMsgCnt);
void Idle_ThreadEntry(void* arg0);
void Main_ThreadEntry(void* arg0);
void osInitialize(void);

void bootproc(void* arg0) {
    osInitialize();
    osCreateThread(&sIdleThread, 1 /* THREAD_ID_IDLE ? */, &Idle_ThreadEntry, arg0,
                   &sIdleThreadStack /* + sizeof(sIdleThreadStack) */, 10);
    osStartThread(&sIdleThread);
}

void Idle_ThreadEntry(void* arg0) {
    osCreatePiManager(OS_PRIORITY_PIMGR, &gPiMgrCmdQueue, sPiMgrCmdBuff, 200);
    osCreateThread(&gMainThread, 2, &Main_ThreadEntry, arg0, sMainThreadStack /* + sizeof(sMainThreadStack) */, 0xA);
    osStartThread(&gMainThread);
    osSetThreadPri(NULL, OS_PRIORITY_IDLE);
    for (;;) {}
}

void func_80000450(void);
void func_80042C28(void);
void func_800458E0(void);
void func_80048338(void);
void func_800484F0(void);
void func_800704F0(void);
void func_80071830(void);
void func_80098D80(void);
void func_800994F4(s32, s32*, s32);
void func_8009B14C(void);
void func_8009C270(s32*, s32, s32);
void func_8009CA60(s32*, s32*, OSMesgQueue*);
extern s32 D_80000300;
extern s8 D_800EC8B0;
extern s8 D_8010ADFA;
extern OSMesgQueue D_80123FF8;
extern OSMesg D_80124010;
extern OSMesgQueue D_80124018;
extern OSMesg D_80124030;
extern OSMesgQueue D_80124050;
extern OSMesg D_80124068;
extern OSMesgQueue D_80124070;
extern OSMesg D_80124088;
extern s32 D_801240A8;
extern s32 D_80124820;
extern s8 D_8012482A;
extern s8 D_8012482B;
extern s8 D_8012482C;
extern s32 func_80072C30;

void func_80099790(void) {
    osCreateMesgQueue(&D_80123FF8, &D_80124010, 1);
    osCreateMesgQueue(&D_80124050, &D_80124068, 2);
    osCreateMesgQueue(&D_80124070, &D_80124088, 8);
    osCreateMesgQueue(&D_80124018, &D_80124030, 8);
    if (D_80000300 == 1) {
        func_8009C270(&D_801240A8, 2, 1);
    } else {
        func_8009C270(&D_801240A8, 0x1E, 1);
    }
    func_8009CA60(&D_801240A8, &D_80124820, &D_80124050);
    func_80042C28();
    func_800458E0();
    func_80048338();
    func_800484F0();
    func_80098D80();
    func_8009B14C();
    func_80000450();
    func_800704F0();
    func_80071830();
    func_800994F4(0, &func_80072C30, 0x64);
    D_8012482A = 0;
    D_8012482B = 0;
    D_8012482C = 0;
    D_800EC8B0 = 0;
    D_8010ADFA = 0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/9A2A0/Main_ThreadEntry.s")
/*
void Main_ThreadEntry(s32 arg0) {
    s16* sp3C;
    s32 sp30;
    s16 temp_t7;
    s32 var_s5;

    sp3C = NULL;
    var_s5 = 0;
    sp30 = 0;
    func_80099790();
loop_1:
    do {
        if ((osRecvMesg(&D_80124018, &sp3C, 0) != 0) && (osRecvMesg(&D_80124070, &sp3C, 0) != 0) &&
(osRecvMesg(&D_80124050, &sp3C, 0) != 0)) { goto loop_1;
        }
        temp_t7 = *sp3C;
        switch (temp_t7) {
        case 1:
            D_80124828 = D_800DF150;
            if (var_s5 == 0) {
                var_s5 = 1;
                func_80098EAC();
                func_80071E80();
                func_80000A8C(0);
                func_80000A8C(1);
                func_80000A8C(2);
                func_80000A8C(3);
                func_80000960();
            } else {
                var_s5 = 0;
            }
            break;
        case 5:
            D_80123750 += 1;
            D_8012496E &= 0xFFFE;
            break;
        case 6:
            D_80123750 += 1;
            D_8013CF8E &= 0xFFFE;
            break;
        case 3:
            sp30 = 1;
            break;
        case 9:
            func_800009B0();
            break;
        }
    } while (sp30 == 0);
    func_800722B4(&D_80124018);
    osViBlack(1);
    func_80000A40(0);
    func_80000A40(1);
    func_80000A40(2);
    func_80000A40(3);
    func_80000A8C(0);
    func_80000A8C(1);
    func_80000A8C(2);
    func_80000A8C(3);
    func_80000A40(0);
    func_80000A40(1);
    func_80000A40(2);
    func_80000A40(3);
    func_80000A8C(0);
    func_80000A8C(1);
    func_80000A8C(2);
    func_80000A8C(3);
    func_80000A40(0);
    func_80000A40(1);
    func_80000A40(2);
    func_80000A40(3);
    func_80000A8C(0);
    func_80000A8C(1);
    func_80000A8C(2);
    func_80000A8C(3);
loop_16:
    do {
loop_17:
        if ((osRecvMesg(&D_80124018, &sp3C, 0) != 0) && (osRecvMesg(&D_80124070, &sp3C, 0) != 0)) {
            if (osRecvMesg(&D_80124050, &sp3C, 0) != 0) {
                goto loop_17;
            }
        }
    } while (*sp3C != 1);
    func_80000A40(0);
    func_80000A40(1);
    func_80000A40(2);
    func_80000A40(3);
    func_80000A8C(0);
    func_80000A8C(1);
    func_80000A8C(2);
    func_80000A8C(3);
    goto loop_16;
}
*/

extern s32 osRecvMesg(OSMesgQueue*, OSMesg*, s32);
void osInvalDCache(s32, s32);
void func_800A42D0(s32*, s32, s32, s32, s32, s32, OSMesgQueue*);

void func_80099C44(s32 arg0, s32 arg1, s32 arg2) {
    int pad[5];
    OSIoMesg* sp50;
    OSMesg sp4C;
    s32 var_s0;

    while (arg2 != 0) {
        if (arg2 > 0x2000) {
            var_s0 = 0x2000;
        } else {
            var_s0 = arg2;
        }
        osInvalDCache(arg1, var_s0);
        osPiStartDma((OSIoMesg *)&sp50, 0, 0, arg0, arg1, var_s0, &D_80123FF8);
        osRecvMesg(&D_80123FF8, &sp4C, 1);
        arg2 -= var_s0;
        arg0 += var_s0;
        arg1 += var_s0;
    }
}

// Chonker
#pragma GLOBAL_ASM("asm/us/nonmatchings/9A2A0/func_80099D10.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/9A2A0/func_8009B0E8.s")
/*
void func_8009B0E8(void) {
    s32* var_v1;

    D_80124858 = 0;
    D_80124888 = 0;
    var_v1 = &D_80124898;
    do {
        var_v1 += 0x30;
        var_v1->unk-30 = 0;
        var_v1->unk-24 = 0;
        var_v1->unk-18 = 0;
        var_v1->unk-C = 0;
    } while (var_v1 != &D_801248F8);
    D_801248F8 = 0;
    D_80124838 = 0;
    D_80124848 = 0;
    D_80124878 = 0;
    D_80124868 = 0;
}
*/

// Chonker
#pragma GLOBAL_ASM("asm/us/nonmatchings/9A2A0/func_8009B14C.s")

#ifndef NON_MATCHING
#pragma GLOBAL_ASM("asm/us/nonmatchings/9A2A0/func_8009B58C.s")
#else
extern s16 D_800DF140;
extern s8 D_80156618;
extern s8 D_80156619;
extern s8 D_8015661A;

void func_8009B58C(s8 arg0, s8 arg1, s8 arg2) {
    D_80156618 = arg0;
    D_80156619 = arg1;
    D_8015661A = arg2;
    D_800DF140 = 0x3E4;
}
#endif

#ifndef NON_MATCHING
#pragma GLOBAL_ASM("asm/us/nonmatchings/9A2A0/func_8009B5C0.s")
#else
extern s16 D_800DF140;
extern s8 D_80156618;
extern s8 D_80156619;
extern s8 D_8015661A;

void func_8009B5C0(s8 arg0, s8 arg1, s8 arg2) {
    D_80156618 = arg0;
    D_80156619 = arg1;
    D_8015661A = arg2;
    D_800DF140 = 0x3B6;
}
#endif

#pragma GLOBAL_ASM("asm/us/nonmatchings/9A2A0/func_8009B5F4.s")
/*
void func_8009B5F4(void) {
    s32 temp_a1;
    void* temp_v1;
    void* temp_v1_2;

    temp_v1 = D_80124830;
    D_80124830 = temp_v1 + 8;
    temp_v1->unk0 = 0xBC000008;
    temp_a1 = 0x3E8 - D_800DF140;
    temp_v1->unk4 = (s32) (((0x1F400 / temp_a1) << 0x10) | (((s32) ((D_800DF140 * -0x100) + 0x1F400) / temp_a1) &
0xFFFF)); temp_v1_2 = D_80124830; D_80124830 = temp_v1_2 + 8; temp_v1_2->unk0 = 0xF8000000; temp_v1_2->unk4 = (s32)
((D_80156618 << 0x18) | (D_80156619 << 0x10) | (D_8015661A << 8) | 0xFF);
}
*/

// Chonker
#pragma GLOBAL_ASM("asm/us/nonmatchings/9A2A0/func_8009B704.s")
