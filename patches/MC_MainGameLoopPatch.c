// @Description MC_MainGameLoopPatch
// @HookAddress 0x1D4
// @HookString 01 48 86 46 01 48 00 47 ED 01 00 08 P
// Mode: Thumb
// Made by beco

// Key control
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

enum {
	TL_INIT = 0,
	TL_INIT_EXEC,
	TL_NINTENDO_INIT,
	TL_NINTENDO_EXEC,
	TL_SCENE0_INIT,
	TL_SCENE0_EXEC,
	TL_SCENE1_INIT,
	TL_SCENE1_EXEC,
	TL_SCENE2_INIT,
	TL_SCENE2_EXEC,
	TL_SCENE3_INIT,
	TL_SCENE3_EXEC,
	TL_SCENE4_INIT,
	TL_SCENE4_EXEC,
	TL_NEWSPAPER_INIT,
	TL_NEWSPAPER_EXEC,
	TL_WARIO4_INIT,
	TL_WARIO4_EXEC,
	TL_PUSH_START,

	TL_PYRAMID_INIT,
	TL_PYRAMID_EXEC,
	TL_SCENE7_INIT,
	TL_SCENE7_EXEC,
	TL_SCENE8_INIT,
	TL_SCENE8_EXEC,
	TL_END,

	TL_SCENE9_INIT,
	TL_SCENE9_EXEC,
	TL_SCENE10_INIT,
	TL_SCENE10_EXEC,
	TL_KISS_INIT,
	TL_KISS_EXEC,
	TL_SCENE11_INIT,
	TL_SCENE11_EXEC,
	TL_SCENE12_INIT,

	TL_SCENE20_INIT,
	TL_SCENE20_EXEC,
//	TL_SCENE21_INIT,
//	TL_SCENE21_EXEC,
//	TL_SCENE22_INIT,
//	TL_SCENE22_EXEC,
	TL_SCENE23_INIT,
	TL_SCENE23_EXEC,
	TL_SCENE24_INIT,
	TL_SCENE24_EXEC,
	TL_NEWS_END_INIT,
	TL_NEWS_END_EXEC,
	TL_SUPER_HARD_INIT,
	TL_SUPER_HARD_EXEC,
	TL_THE_END,

	TL_QUICK_INIT,

	TL_SEQ_MAX = TL_SUPER_HARD_EXEC,
};

enum {
	DMAP_NO_DEMO, DMAP_START_DEMO, DMAP_TUTO_DEMO, DMAP_TO_MMAP_DEMO,
	DMAP_BOSS_DEMO
};

enum {
  DMAP_SD_SISI_1, DMAP_SD_WARIO_SLIP, DMAP_SD_YURE, DMAP_SD_SISI_2
};

#define ucWorldNum (*(volatile unsigned char*) 0x3000002)
#define ucStageNum (*(volatile unsigned char*) 0x3000003)
#define usRandomCount (*(volatile unsigned short*) 0x3000006)
#define ucBossHeya (*(volatile unsigned char*) 0x300001B)
#define ucGmapSubSeq (*(volatile unsigned char*) 0x3000021)
#define ucHeyaNum (*(volatile unsigned char*) 0x3000024)
#define ucBgYoki (*(volatile unsigned char*) 0x3000045)
#define GlobalGameMode (*(volatile unsigned char*) 0x3000C3A)
#define sGameSeq (*(volatile unsigned char*) 0x3000C3C)
#define ucMainTimer (*(volatile unsigned short*) 0x3000C41)
#define usTrg_KeyPress1Frame (*(volatile unsigned short*) 0x3001848)
#define usFadeTimer (*(volatile unsigned short*) 0x300188E)
#define Wario_ucDokan (*(volatile unsigned char*) 0x300189A)
#define usWarStopFlg (*(volatile unsigned char*) 0x30019F6)
#define SelCur_sY (*(volatile signed short*) 0x3003C16)
#define ucSeldemoSeq (*(volatile unsigned char*) 0x3003C39)
#define sDmapBgPosY (*(volatile signed short*) 0x3003C6C)
#define ucDmapDemoStatus (*(volatile unsigned char*) 0x3003C94)
#define ucSmapWarioStatus (*(volatile unsigned char*) 0x3003CA0)

#define Sub_8000954_SetKeyPressWRAM ((void (*)()) 0x8000955)
#define Sub_80007BC_SoftResetCheck ((void (*)()) 0x80007BD)
#define Sub_8001DA4_m4aSongNumStart ((void (*)(int)) 0x8001DA5)
#define Sub_8001DD0_m4aSongNumStartOrChange ((void (*)(int)) 0x8001DD1)
#define Sub_8001ED8_m4aMPlayAllStop ((void (*)()) 0x8001ED9)
#define Sub_8002D58_MPlayVolumeControl ((void (*)(int,unsigned short,int)) 0x8002D59)

// My variables (perhaps unused in original)
#define usDisConR_EmpBlk (*(volatile unsigned short*) 0x3006F00)
#define reblockBrokenCnt (*(volatile unsigned char*) 0x3006F02)
#define reblockBrokenFail (*(volatile unsigned char*) 0x3006F03)
#define restartTimer (*(volatile unsigned char*) 0x3006F04)
#define restartFlag (*(volatile unsigned char*) 0x3006F05)
#define crystal_Tflg (*(volatile unsigned char*) 0x3006F0E)
#define dashAttackFlag (*(volatile unsigned char*) 0x3006F0F)
#define airAttackNum (*(volatile unsigned char*) 0x3006F10)
#define airAttackStat (*(volatile unsigned char*) 0x3006F11)
#define airJumpNum (*(volatile unsigned char*) 0x3006F12)
#define aFlipFlag (*(volatile unsigned char*) 0x3006F13)
#define hFlipFlag (*(volatile unsigned char*) 0x3006F14)
#define bFlipFlag (*(volatile unsigned char*) 0x3006F15)
#define ucBossHeyaPause (*(volatile unsigned char*) 0x3006F16)
#define disablePause (*(volatile unsigned char*) 0x3006F17)
#define bgmMapBackNum (*(volatile unsigned short*) 0x3006F18)

#define EXBACKUP_FIELD_EMPBLK ((volatile struct EmpBlkdef*) 0x203E000) // Empty block data

struct EmpBlkdef {
	short position;
	short tileID;
};

void MC_MainGameLoopPatch() {
    // Vanilla code
    Sub_8000954_SetKeyPressWRAM();
    Sub_80007BC_SoftResetCheck();
    ++ucMainTimer;
    ++usRandomCount;

    // Custom code
    // Cutscene skips
    switch ( GlobalGameMode )
    {
    	// Intro
      case 0:
        if ( sGameSeq > TL_PUSH_START )
        {
        	switch ( usTrg_KeyPress1Frame )
          {
            case KEY_A:
            case KEY_START:
              sGameSeq = TL_END;
              // Sub_8002D58_MPlayVolumeControl(0x30060F0, 0xFFFF, 0);
              Sub_8001ED8_m4aMPlayAllStop();
              Sub_8001DA4_m4aSongNumStart(293);
              break;
            default:
              break;
          }
        }
        break;
      case 1:
	    	// Pyramid entry
        if ( sGameSeq == 2 && ucDmapDemoStatus == DMAP_START_DEMO && ucSeldemoSeq == DMAP_SD_SISI_1 )
        {
        	switch ( usTrg_KeyPress1Frame )
          {
            case KEY_A:
            case KEY_START:
              Sub_8001DA4_m4aSongNumStart(293);
              SelCur_sY = 0x0D40;   // Wario Y Position
              sDmapBgPosY = 0x0480;
              ucSeldemoSeq = DMAP_SD_SISI_2;
              break;
            default:
              break;
          }
        }
		    // Level entry
        if ( sGameSeq == 9 && ucSmapWarioStatus == 1 )
        {
        	switch ( usTrg_KeyPress1Frame )
          {
            case KEY_A:
            case KEY_START:
              Sub_8001DA4_m4aSongNumStart(293);
              sGameSeq = 10;
              break;
            default:
              break;
          }
				}
        break;
			case 2:
				// Pause control
				if ( usWarStopFlg || Wario_ucDokan || (ucStageNum == 4 && ucHeyaNum > 1) )
					disablePause = 1;
				else
					disablePause = 0;
      default:
        break;
    }
}
