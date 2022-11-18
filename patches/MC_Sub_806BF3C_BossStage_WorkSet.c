// @Description MC_Sub_806BF3C_BossStage_WorkSet
// @HookAddress 0x6BF3C
// @HookString 01488646 01480047 65b40608 P
// Mode: Thumb
// Made by beco

enum {
	BOSS_NON,		//ボス部屋でない
	BOSS_PASS,		//ボス廊下			ボスステージ↓
	BOSS_HEYA,		//中ボス部屋		ボス部屋↓
	BOSS_YOKI,		//大ボス部屋
};

enum {
	BGYOKI_STOP,			//停止
	BGYOKI_LIGHT_ON,		//画面暗->スポットライトＯＮ
	BGYOKI_LIGHT_WAIT,		//スポットライトＯＮ状態、ＯＦＦ待ち
	BGYOKI_BGEVENT_OFF,		//イベント終了-> (BGYOKI_STOP)へ
};

#define ucWorldNum (*(volatile unsigned char*) 0x3000002)
#define ucStageNum (*(volatile unsigned char*) 0x3000003)
#define ucBossHeya (*(volatile unsigned char*) 0x300001B)
#define ucGmapSubSeq (*(volatile unsigned char*) 0x3000021)
#define ucHeyaNum (*(volatile unsigned char*) 0x3000024)
#define ucBgYoki (*(volatile unsigned char*) 0x3000045)

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

void MC_Sub_806BF3C_BossStage_WorkSet() {
		ucBossHeya = BOSS_NON;
		if ( ucStageNum != 4 ) return;
		ucBossHeyaPause = BOSS_PASS;	// My variable to control boss pause
		if ( ucHeyaNum > 1 ) return;	// Treating Room 02-15 as BOSS_NON
		ucBossHeya = BOSS_PASS;				// ボスステージ
		if ( ucHeyaNum ) {
			ucBossHeya = BOSS_HEYA;			// ボス部屋
			if( ucWorldNum == 5 ) {
				ucBossHeya = BOSS_YOKI;		// ヨーキ
				ucGmapSubSeq = 0;
				ucBgYoki = BGYOKI_STOP; 	// ヨーキ部屋BG-EVENT
			}
		}
}
