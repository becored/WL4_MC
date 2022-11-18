// @Description code will be excute once every frame, modified from UnlimitedRockBouncing
// @HookAddress 0x6C75E
// Mode: Thumb
// Made by Goldensunboy, ssp(shinespeciall)
// Modified by beco

/* Hook details
------------------------- this only works when the new function push lr at first and bx lr at last.
0x806C75E: LDR R0, 0x806C767    | 4803
0x806C760: MOV LR, R0           | 4686
0x806C762: LDR R0, pointer      | 4801
0x806C764: BX R0                | 4700
0x806C766: B 0x806C770          | E002
0x806C768: .fill a pointer      | 0XXXXXXX ; end with 1 (in binary) to make it run in thumb mode
0x806C76C: .fill 67C70608       | 0806C767 ; end with 1 (in binary) to make it run in thumb mode
0x806C770: nop                  | 46C0     ; i.e. mov r8, r8
0x806C772: nop....
-------------------------
Hook String:
@HookString 03 48 86 46 01 48 00 47 02 E0 P 67 C7 06 08 C0 46 C0 46 C0 46 C0 46 C0 46 C0 46 C0 46 C0 46 C0 46 C0 46
count:                                     ^14                                                                     ^38
Hook length: 38 Bytes
*/
enum WAR_STAT_NORMAL {
	WALK,					//歩き
	TURN,					//振り返り
	STOP,					//止まり
	JUMPB,					//ジャンプ前
	JUMP,					//ジャンプ
	SQUAT,					//しゃがみ
	SSLIP,					//しゃがみすべり
	SWALK,					//しゃがみ歩き
	SJUMP,					//しゃがみジャンプ
	STURN,					//しゃがみ振り返り
	WKBRK,					//歩き止まり
	DSBRK,					//最速走り止まり
	SLIP,					//すべり始め（坂）
	ROLLB,					//転がり前
	ROLL,					//転がり
	RJUMP,					//転がりジャンプ
	RFLIP,					//転がり後の跳ね返り
	DOKANU,					//土管上
	DOKAND,					//土管下
	MISS,					//ダメージ
	MISS2,
	HAJIK,					//敵はじく
	ATTACK,					//アタック
	DATTACK,				//最速アタック
	AJUMP,					//アタックジャンプ
	DAJUMP,					//最速アタックジャンプ
	AFLIP,					//アタック後の跳ね返り
	HIP,					//ヒップアタック（空中）
	PHIP,					//パワーヒップアタック
	HIP2,					//ヒップアタック（地面）
	PHIP2,					//パワーヒップアタック（地面）
	FUMI,					//踏んづけ跳ね
	LIFT1,					//敵持ち上げ（軽い）
	LIFT2,					//敵持ち上げ（重い）
	THROW0,					//投げ準備
	TAME,					//投げ溜め
	THROW1,					//投げ（弱）
	THROW2,					//投げ（強）
	JTHROW,					//飛び投げ
	TAMCURN,				//溜め反転
	LDMOVE,					//はしご移動
	LDSTOP,					//はしご止まり
	LDDOWN,					//はしご飛び落り
	NETMOVEY,				//金網移動Ｙ
	NETMOVEX,				//金網移動Ｘ
	NETSTOP,				//金網止まり
	NETDOWN,				//金網飛び落り
	HANERU,					//敵地震
	AWATE,					//はしご・金網落ちる
	GATEIN,					//扉入る
	GATEOUT,				//扉出る
	UPFACE,					//上向く
	TSQUAT,					//積み木用しゃがみ
	ASERI,					//あせり
	WAIT0,					//待機ポーズ
	WAIT1,					//待機ポーズ
	BARBELL0,				//バーベル０
	BARBELL1,				//バーベル１
	ATWALK,					//オート歩き
	WAIT2,					//縄跳び
	CATCH,					//捕らえる
	JCLEAR,					//空中でボス戦クリア
	CLRWAIT,				//ボス戦クリア後
	CLRTURN,				//クリア後ターン
	CLRWALK,				//クリア後歩き
	CLRKIME,				//決めポーズ
	LSTWAIT,				//宝待ち（ラスボス）
	LSTKIME,				//決めポーズ（ラスボス）
	LSTAWATE,				//慌てる（ラスボス）

	SLEEP,					//眠り
	WAKEUP,					//目覚め
	JUMPA,					//着地
	DASH,					//最速走り
	DJUMP,					//最速ジャンプ
	JFLIP,					//跳ね返り
	CLASH,					//激突
	TAKARA,					//宝箱
	RPOUSE,					//構え
	GOWALK,					//ゴー
};

struct EnemyDataStructure {
    unsigned short CurEnemy_usStatus;
    unsigned char pAnmData1;
    unsigned char pAnmData2;
    unsigned long OAMDataPackPointerForCurrentAnimation;
    unsigned short CurEnemy_YPos;
    unsigned short CurEnemy_XPos;
    unsigned short CurEnemy_AffinePA;
    unsigned short CurEnemy_AffinePB;
    unsigned short CurEnemy_AffinePC;
    unsigned short CurEnemy_AffinePD;
    unsigned short CurEnemy_CurrentAnimationFrameId;
    unsigned char CurEnemy_RealFrameCountForCurrentAnimationFrame;
    unsigned char CurEnemy_GlobalId;
    unsigned char CurEnemy_RoomEntitySlotId;
    unsigned char CurEnemy_ucChrOfs;
    unsigned char CurEnemy_Prio;
    unsigned char CurEnemy_paletteId;
    unsigned char CurEnemy_CurrentAnimationId;
    unsigned char CurEnemy_Life;
    unsigned char CurEnemy_GuardAndDamageParam;
    unsigned char CurEnemy_DisableInteractionWithWarioCountdown;
    unsigned char CurEnemy_SizeY0_Bottom;
    unsigned char CurEnemy_SizeY1_Top;
    unsigned char CurEnemy_SizeX_LeftRight;
    unsigned char CurEnemy_HitboxY0;
    unsigned char CurEnemy_HitboxY1;
    unsigned char CurEnemy_HitboxX0;
    unsigned char CurEnemy_HitboxX1;
    unsigned char CurEnemy_TWork0;
    unsigned char CurEnemy_TWork1;
    unsigned char CurEnemy_TWork2;
    unsigned char CurEnemy_TWork3;
    unsigned char CurEnemy_padding;
};

struct EntityStateSlotInRoom {
    unsigned char field_0;
    unsigned char field_1;
    unsigned char field_2;
    unsigned char field_3;
    unsigned char field_4;
    unsigned char field_5;
    unsigned char field_6;
    unsigned char field_7;
    unsigned char field_8;
    unsigned char field_9;
    unsigned char field_A;
    unsigned char field_B;
    unsigned char field_C;
    unsigned char field_D;
    unsigned char field_E;
    unsigned char field_F;
    unsigned char field_10;
    unsigned char field_11;
    unsigned char field_12;
    unsigned char field_13;
    unsigned char field_14;
    unsigned char field_15;
    unsigned char field_16;
    unsigned char field_17;
    unsigned char field_18;
    unsigned char field_19;
    unsigned char field_1A;
    unsigned char field_1B;
    unsigned char field_1C;
    unsigned char field_1D;
    unsigned char field_1E;
    unsigned char field_1F;
    unsigned char field_20;
    unsigned char field_21;
    unsigned char field_22;
    unsigned char field_23;
    unsigned char field_24;
    unsigned char field_25;
    unsigned char field_26;
    unsigned char field_27;
    unsigned char field_28;
    unsigned char field_29;
    unsigned char field_2A;
    unsigned char field_2B;
    unsigned char field_2C;
    unsigned char field_2D;
    unsigned char field_2E;
    unsigned char field_2F;
    unsigned char field_30;
    unsigned char field_31;
    unsigned char field_32;
    unsigned char field_33;
    unsigned char field_34;
    unsigned char field_35;
    unsigned char field_36;
    unsigned char field_37;
    unsigned char field_38;
    unsigned char field_39;
    unsigned char field_3A;
    unsigned char field_3B;
    unsigned char field_3C;
    unsigned char field_3D;
    unsigned char field_3E;
    unsigned char field_3F;
};

// Custom Enums
enum DASH_ATTACK_FLAG {
	D_ATTACK_INIT,		// Not avalaible
	D_ATTACK_CHARGED,	// Avalaible
};
enum AIR_ATTACK_FLAG {
	A_ATTACK_INIT,		// Not avalaible
	A_ATTACK_ENABLE,	// Avalaible
};
enum AIR_JUMP_FLAG {
	A_JUMP_INIT,			// Not avalaible
	A_JUMP_ENABLE,		// Avalaible
	A_JUMP_USING,			// Using (in the air)
};

#define CurrentEnemyData ((volatile struct EnemyDataStructure*) 0x3000104)
#define EntityLeftOverStateList ((volatile unsigned char*) 0x3000564)
#define GameState (*(volatile unsigned char*) 0x3000C3C) // 03(restart current room) - ingame - 00(restart room) 01(fade) 02(game runtime) 03(lose level) 04(pause) 05(freeze) 06(lose level) 08(debug mode)

#define ucBossRoom (*(volatile unsigned char*) 0x300001B)
#define ucBgAnimatedStop (*(volatile unsigned char*) 0x3000046)
#define Sub_806E08C_BgAnimatedMain ((void (*)()) 0x806E08D)

#define PAL_RAM ((volatile unsigned char*) 0x5000000) // PAL RAM
#define VRAM 0x6000000 // VRAM
#define OBJ_MODE0_VRAM 0x6010000 // OBJ Character RAM

#define bWarioPalette ((volatile unsigned char*) 0x30030D0) // wario palettes, 2 lines

#define usAlpfaBLD1 (*(volatile unsigned char*) 0x300002A)
#define usAlpfaBLD2 (*(volatile unsigned char*) 0x300002B)
#define REG_DMA3SAD (*(volatile unsigned int*) 0x40000D4)
#define REG_DMA3DAD (*(volatile unsigned int*) 0x40000D8)
#define REG_DMA3CNT (*(volatile unsigned int*) 0x40000DC)

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

#define ucGmScore_Tflg (*(volatile unsigned char*) 0x3000C02)
#define unk_8405AE8 0x8405AE8 // Score OBJ

// Misc function
#define Sub_8001DA4_m4aSongNumStart ((int (*)(int)) 0x8001DA5)
#define Sub_8001DD0_m4aSongNumStartOrChange ((int (*)(int)) 0x8001DD1)
#define Sub_8001E70_m4aSongNumStop ((int (*)(int)) 0x8001E71)
#define Sub_8001ED8_m4aMPlayAllStop ((void (*)()) 0x8001ED9)
#define Sub_801318C_WarChng_Other ((void (*)(unsigned char)) 0x801318D)
#define sub_80766E8_TOptObjSet ((int (*)(int, int, char)) 0x80766E9)
#define Sub_806DAC0_TileEventIdTester ((int (*)(int,int)) 0x806dac1)
#define Sub_801EA3C_ChangeWarioReact_FIRE_Sub ((void (*)()) 0x801ea3d)
#define Sub_801EA64_ChangeWarioReact_Fat_Sub ((void (*)()) 0x801ea65)
#define Sub_801EB7C_ChangeWarioReact_Flat_Sub ((void (*)()) 0x801eb7d)
#define Sub_801EB04_ChangeWarioReact_Spring_Sub ((void (*)()) 0x801eb05)
#define Sub_801EB54_ChangeWarioReact_ICE_Sub ((void (*)()) 0x801eb55)
#define Sub_801EAB4_ChangeWarioReact_SNOW_Sub ((void (*)()) 0x801eab5)
#define Sub_801EA8C_ChangeWarioReact_ZOMBI_Sub ((void (*)()) 0x801ea8d)
#define Sub_801EADC_ChangeWarioReact_BALLOON_Sub ((void (*)()) 0x801eadd)
#define Sub_801EB2C_ChangeWarioReact_BAT_Sub ((void (*)()) 0x801eb2d)
#define Sub_801EBA4_ChangeWarioReact_Bubble_Sub ((void (*)()) 0x801eba5)
#define Sub_801D248_GameMain_Fade_IN ((void (*)()) 0x801D249)
#define Sub_801D2A8_GameMain_Fade_OUT ((void (*)()) 0x801D2A9)
#define Sub_80714F0_GateWindow_TimeUp ((void (*)()) 0x80714F1)
#define Sub_80710D8_GateFade_Color ((void (*)(unsigned char,unsigned char)) 0x80710D9)
#define Sub_803BA64_DominoBlockDelete ((void (*)()) 0x803BA65)
#define Sub_8088620_WarioVoiceSet ((void (*)(int)) 0x8088621)

// Switch variables
#define Switch1Flag (*(volatile unsigned char*) 0x300002F)
#define Switch2Flag (*(volatile unsigned char*) 0x3000030)
#define Switch3Flag (*(volatile unsigned char*) 0x3000031)
#define Switch4Flag (*(volatile unsigned char*) 0x3000032)

// Misc variables
#define usRandomCount (*(volatile unsigned char*) 0x3000006)
#define ucSaveNum (*(volatile unsigned char*) 0x3000019)
#define Fade_ucKind (*(volatile unsigned char*) 0x30000D0)
#define ucHasKeyzer (*(volatile signed char*) 0x3000C0C)
#define Wario_ucReact (*(volatile unsigned char*) 0x3001898)
#define Wario_ucStat (*(volatile unsigned char*) 0x3001899)
#define Wario_ucDokan (*(volatile unsigned char*) 0x300189A)
#define Wario_ucTurn (*(volatile unsigned char*) 0x300189B)
#define WarioXPos (*(volatile unsigned short*) 0x30018AA)
#define WarioYPos (*(volatile unsigned short*) 0x30018AC)
#define Wario_sMvSpeedX (*(volatile unsigned short*) 0x30018AE)
#define Wario_sMvSpeedY (*(volatile unsigned short*) 0x30018B0)
#define WarioInvincibility (*(volatile unsigned char*) 0x300189C)
#define WarioHeart (*(volatile unsigned char*) 0x3001910)
#define usWarStopFlg (*(volatile unsigned short*) 0x30019F6)
#define Wario_ucPlace (*(volatile unsigned char*) 0x30018B2)
#define uknown_counter (*(volatile unsigned char*) 0x30018A2)
#define word_30018CE (*(volatile unsigned short*) 0x30018CE)
#define word_30018CC (*(volatile unsigned short*) 0x30018CC)
#define Layer0_DecompressedDataPointer (*(volatile unsigned int*) 0x3000054)
#define CurrentTileset_EventIdTablePointer (*(volatile unsigned int*) 0x30031FC)
#define Layer0_Width (*(volatile unsigned short*) 0x3000058)
#define CurrentRoomHeader_Layer0MappingType (*(volatile unsigned char*) 0x3000075)
#define usTekiBgPosX (*(volatile unsigned short*) 0x300003A) // u16, usTekiBgPosX, Specify SCR position from enemy (BG0-PosX)
#define usBg0Hofs (*(volatile unsigned short*) 0x3001876) // layer 0 x offset, usBg0Hofs, short (used for non-synchronized layer 0)
#define usBg0Vofs (*(volatile unsigned short*) 0x3001878) // layer 0 y offset, usBg0Vofs, short (used for non-synchronized layer 0)
#define usBg1Hofs_CameraXPos (*(volatile unsigned short*) 0x300187A) // layer 1 x offset, usBg1Vofs, i.e. camera x position, short (realtime)
#define usBg1Vofs_CameraYPos (*(volatile unsigned short*) 0x300187C) // layer 1 y offset, usBg1Hofs, i.e. camera y position, short (realtime)
#define usBg2Hofs (*(volatile unsigned short*) 0x300187E) // layer 2 x offset, usBg2Vofs, short
#define usBg2Vofs (*(volatile unsigned short*) 0x3001880) // layer 2 y offset, usBg2Hofs, short
#define usBg3Hofs (*(volatile unsigned short*) 0x3001882) // layer 3 x offset, usBg2Vofs, short
#define usBg3Vofs (*(volatile unsigned short*) 0x3001884) // layer 3 y offset, usBg2Hofs, short

#define CameraYPos (*(volatile unsigned short*) 0x3003226)
#define CameraYPos (*(volatile unsigned short*) 0x3003226)

#define CurrentDifficulty (*(volatile unsigned char*) 0x03000017) // 00 for normal, =01 for hard, =02 for S-hard
#define CurrentPassage (*(volatile unsigned char*) 0x3000002) // 00(Entry) 01(Emerald) 02(Ruby) 03(Topaz) 04(Sapphire) 05(Golden) 06(Sound Room)
#define CurrentLevel (*(volatile unsigned char*) 0x3000003) // 00(first lvl) 01(second lvl) 02(third lvl) 03(fourth lvl) 04(Boss) 05(Mini-Game Shop)
#define CurrentRoomId (*(volatile unsigned char*) 0x03000024)
#define KilledEnemiesCounter (*(volatile unsigned char*) 0x3000C06)
#define ucTimeUp (*(volatile unsigned char*) 0x3000047) // 01(fighting boss) 02(Losing coins) 03(Losing coins without coin counter) 04(hide coin counter) 10(fade to grayscale) 0f(no interaction between wario and enemies)

#define cGmStartFlg (*(volatile unsigned char*) 0x3000C3F)
#define cPauseFlag (*(volatile unsigned char*) 0x3000C35)
#define soft_reset (*(volatile unsigned char*) 0x300001E)
#define ADDR_KEY_4 (*(volatile unsigned short*) 0x3001848)

#define ScEbuf ((volatile unsigned char*) 0x3000B80) // 12 bytes
#define ScEbufCounter (*(volatile unsigned char*) 0x3000B86) // The Big Board counter
#define ScEbufYPos (*(volatile unsigned short*) 0x3000B88) // 2 bytes, default: 0x0210
#define ScEbufXPos (*(volatile unsigned short*) 0x3000B8A) // 2 bytes, default: 0x0040
#define Scbuf_ucAnmTimer (*(volatile unsigned char*) 0x3000BE1)
#define Scbuf_ucSeq (*(volatile unsigned char*) 0x3000BE3)
#define roulette_current_case_type (*(volatile unsigned short*) 0x3000C10)
#define roulette_moving_case_OAM_gfx (*(volatile unsigned short*) 0x3001470)

#define Pyaku1 (*(volatile unsigned short*) 0x30000A0)
#define Pyaku2 (*(volatile unsigned short*) 0x30000A1) // 01(in water) 00(else)

#define Enemy1State (*(volatile unsigned char*) 0x3000104)
#define Enemy1YPos (*(volatile unsigned short*) 0x300010C)
#define Enemy1XPos (*(volatile unsigned short*) 0x300010E)
#define Enemy2State (*(volatile unsigned char*) 0x3000130)
#define Enemy2YPos (*(volatile unsigned short*) 0x3000138)
#define Enemy2XPos (*(volatile unsigned short*) 0x300013A)

//#define word_30018B4 (*(volatile unsigned char*) 0x30031B4)
//#define unk_30031C8 (*(volatile unsigned short*) 0x30031C8) // Wario X move speed, used in Sub_800FE58_WarMoveConvX

// Boss variables
#define ucBossPause (*(volatile unsigned char*) 0x300001A)
#define CractusHp (*(volatile unsigned char*) 0x3000255) // Cractus's health
#define CatbatAnimationId (*(volatile unsigned char*) 0x3000120) // Catbat AnimationId
#define CatbatCuckooHp (*(volatile unsigned char*) 0x3000121) // Catbat's/Cuckoo Condor's health
#define CatbatPalette (*(volatile unsigned char*) 0x300011F) // Catbat's Palette (Default:0x00)
#define CatbatWaveType (*(volatile unsigned char*) 0x300014D) // Catbat's Wave Type (0x00:Straight‐line, 0x01:Wave, 0x11,Faster wave)
#define CatbatSharkBotYPos (*(volatile unsigned short*) 0x3000164) // Catbat's Shark Bot Y Position
#define CatbatSharkBotXPos (*(volatile unsigned short*) 0x3000166) // Catbat's Shark Bot X Position
#define CatbatSharkBotPalette (*(volatile unsigned char*) 0x3000177) // Catbat's Shark Bot Palette (Default:0x00)
#define CatbatSharkBotSpeed (*(volatile unsigned char*) 0x3000185) // Catbat's Shark Bot Speed (Default:0x01)

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

void MC_FrameOperations() {
    // Vanilla code for animated tiles loading
    if ( (GameState == 2 || GameState == 6 || GameState == 4 && ucBossRoom == 1) && !ucBgAnimatedStop )
		{
        Sub_806E08C_BgAnimatedMain();
    }

    // In-level Functions (inactive during pause)
    if ( cGmStartFlg == 1 && cPauseFlag == 0 && ucBossPause == 0 && soft_reset == 0 )
		{
        // Press L to trigger debug mode (Don't forget to remove before release!)
				/*
        if ( ADDR_KEY_4 == KEY_L ) {
            if ( GameState == 8 ) {
                GameState = 2;
            } else if ( GameState == 2 ) {
                GameState = 8;
            }
        }
				*/

        // Custom Code
        // For custom block (YDAMAGE_WARP)
        if ( restartFlag && WarioHeart > 0 )
				{
            if ( ++restartTimer > 20 )
            {
								restartFlag = 0;
								restartTimer = 0;
                GameState = 0;
								ucHasKeyzer = 0;
                Sub_801318C_WarChng_Other(STOP);
            		Wario_sMvSpeedX = 0;
								Sub_8001E70_m4aSongNumStop(35);
								Sub_8001E70_m4aSongNumStop(41);
          			Sub_8001DA4_m4aSongNumStart(549);
            }
        }
        /*
        // Press SELECT to restart the current room
        if ( ADDR_KEY_4 == KEY_SELECT ) {
            if ( GameState == 2 && ( Wario_ucStat == 2 || Wario_ucStat == 4 ) ) {
                GameState = 0;
                restartFlag = 1;
            }
        }
        */
        /*
        // Disable Air-Attack/Jump when landing
        if ( Wario_ucPlace == 0 && (airAttackNum != A_ATTACK_INIT || airJumpNum != A_JUMP_INIT) )
        {
            dashAttackFlag = D_ATTACK_INIT;
            airAttackNum = A_ATTACK_INIT;
            airAttackStat = 0;
            airJumpNum = A_JUMP_INIT;
            Sub_8001DA4_m4aSongNumStart(297);
        }
        */
        if ( CurrentPassage == 1 && CurrentLevel == 0 && CurrentRoomId == 12 )
				{
						if ( reblockBrokenFail != 0xFF && reblockBrokenCnt != 0xFF )
						{
								if ( reblockBrokenFail > 0 )
								{
										Sub_8001DA4_m4aSongNumStart(549);
										reblockBrokenFail = 0xFF;
								}
								else
								{
										if ( reblockBrokenCnt >= 4 )
										{
												Sub_803BA64_DominoBlockDelete();
												Sub_8001DA4_m4aSongNumStart(235);
												Sub_8088620_WarioVoiceSet(1);
												reblockBrokenCnt = 0xFF;
												reblockBrokenFail = 0xFF;
										}
								}
						}
				}
    }
}
