// @Description MC_Sub_80845F0_GameSelectMmapPatch
// @HookAddress 0x7A0B8
// @HookString 01 48 86 46 01 48 00 47 6B A3 07 08 P C0 46 C0 46 C0 46 C0 46 C0 46 C0 46
// Mode: Thumb
// Made by beco

// Data
#define	KEY_L		0x200 // L
#define	KEY_R		0x100 // R
#define	KEY_A		0x001 // A
#define	KEY_B		0x002 // B
#define	KEY_DOWN	0x080 // Down
#define	KEY_UP		0x040 // Up
#define	KEY_LEFT	0x020 // Left
#define	KEY_RIGHT	0x010 // Right
#define	KEY_START	0x008 // Start
#define	KEY_SELECT	0x004 // Select
#define	KEY_ALL		0x3FF // Any key

#define VRAM 0x6000000
#define SPACE_CHAR 0x869EE68
#define DIAMOND_CHAR 0x869F8C8
#define SLASH_CHAR 0x869F928
#define NUM_CHAR 0x869FC88

#define PassageID (*(volatile unsigned char*) 0x3000002)
#define InPassageLevelID (*(volatile unsigned char*) 0x3000003)
#define CurrentDifficulty (*(volatile unsigned char*) 0x03000017) // 00 for normal, =01 for hard, =02 for S-hard
#define ucSaveNum (*(volatile unsigned char*) 0x3000019)
#define sGameSeq (*(volatile unsigned char*) 0x3000C3C)
#define ADDR_KEY_4 (*(volatile unsigned short*) 0x3001848)
#define bSelIdoFlg (*(volatile unsigned char*) 0x3003C45)
#define ucSelectVector ((volatile unsigned char*) 0x3004700) // 1: into passage, 3: back from passage, 4: into boss level

#define REG_DMA3SAD (*(volatile unsigned int*) 0x40000D4)
#define REG_DMA3DAD (*(volatile unsigned int*) 0x40000D8)
#define REG_DMA3CNT (*(volatile unsigned int*) 0x40000DC)

#define sub_8001DA4_m4aSongNumStart ((void (*)(int)) 0x8001DA5)
#define Sub_80845F0_GameSelectMmap ((int (*)()) 0x80845F1)
#define Sub_807A700_SelectHantei ((int (*)()) 0x807A701)

// My variables (perhaps unused in original)
#define usDisConR_EmpBlk (*(volatile unsigned short*) 0x3006F00)
#define restartFlag (*(volatile unsigned char*) 0x3006F02)
#define Wario_ucReact_bk (*(volatile unsigned char*) 0x3006F03)
#define Wario_ucStat_bk (*(volatile unsigned char*) 0x3006F04)
#define Wario_ucDokan_bk (*(volatile unsigned char*) 0x3006F05)
#define Wario_sMvSpeedX_bk (*(volatile unsigned short*) 0x3006F06)
#define Wario_sMvSpeedY_bk (*(volatile unsigned short*) 0x3006F08)
#define crystal_Tflg (*(volatile unsigned char*) 0x3006F0E)
#define dashAttackFlag (*(volatile unsigned char*) 0x3006F0F)
#define airAttackNum (*(volatile unsigned char*) 0x3006F10)
#define airAttackStat (*(volatile unsigned char*) 0x3006F11)
#define airJumpNum (*(volatile unsigned char*) 0x3006F12)
#define aFlipFlag (*(volatile unsigned char*) 0x3006F13)
#define hFlipFlag (*(volatile unsigned char*) 0x3006F14)

#define MY_VARIABLES ((volatile unsigned char*) 0x3006F00)
#define EXBACKUP_FIELD_EMPBLK ((volatile struct EmpBlkdef*) 0x203E000) // Empty block data

struct EmpBlkdef {
	short position;
	short tileID;
};

void MC_Sub_80845F0_GameSelectMmapPatch() {
    // Vanilla code
    if (Sub_80845F0_GameSelectMmap() && Sub_807A700_SelectHantei()) {
        sGameSeq = 0x24;
    }

    // Initialize my variables
    for (int i = 0; i <= 100; i++) {
        MY_VARIABLES[i] = 0;
        EXBACKUP_FIELD_EMPBLK[i].position = 0;
        EXBACKUP_FIELD_EMPBLK[i].tileID = 0;
    }
}
