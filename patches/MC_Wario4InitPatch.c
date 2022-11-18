// @Description MC_Wario4InitPatch
// @HookAddress 0x5EE0
// @HookString 01 48 86 46 01 48 00 47 F7 5E 00 08 P C0 46
// Mode: Thumb
// Made by beco

// WRAM
#define W4ItemStatus_SAVE ((volatile unsigned char*) 0x2038124)
#define unk_20382E0_SAVE (*(volatile unsigned char*) 0x20382E0)
#define unk_20382E1_SAVE (*(volatile unsigned char*) 0x20382E1)
#define unk_20382E2_SAVE (*(volatile unsigned char*) 0x20382E2)

// IRAM
#define ucPerfect (*(volatile unsigned char*) 0x3000015)
#define W4ItemStatus ((volatile unsigned char*) 0x3000A68)
#define s5_car_y (*(volatile unsigned short*) 0x3002C9C)
#define s5_super_hard (*(volatile unsigned short*) 0x3002CA2)
#define unk_3003BF8 (*(volatile unsigned char*) 0x3003BF8)

// I/O
#define REG_DISPCNT (*(volatile unsigned short*) 0x4000000)
#define REG_DMA3SAD (*(volatile unsigned int*) 0x40000D4)
#define REG_DMA3DAD (*(volatile unsigned int*) 0x40000D8)
#define REG_DMA3CNT (*(volatile unsigned int*) 0x40000DC)

// VRAM
#define VRAM 0x6000000
#define MapTexts1 ((volatile unsigned short*) 0x6008304)
#define MapTexts2 ((volatile unsigned short*) 0x6008344)

// SRAM
#define LastDifficulty (*(volatile unsigned char*) 0xE0009F0)
#define BestTimes ((volatile unsigned char*) 0xE000A00)
#define BestTimes_Boss ((volatile unsigned char*) 0xE000BA0)
#define LapTimes ((volatile unsigned char*) 0xE000C10)

// Char
#define TEXT1_CHAR 0x87A0000
#define TEXT2_CHAR 0x87A0200

void MC_Wario4InitPatch() {
    // Custom code
    // Enable S-Hard
    ucPerfect = 1;

    // Vanilla code
    s5_car_y = 150;
    if ( ucPerfect == 1 ) {
        s5_super_hard = 1;
    } else {
        s5_super_hard = 0;
    }
    REG_DISPCNT = 0;
}
