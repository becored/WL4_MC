// @Description MC_Sub_803D2B4_EntityAI_0x2F_Tmain_zako_domino_lst
// @HookAddress 0x78E8BC
// @HookString P
// @EntryFunctionSymbol MC_Sub_803D2B4_EntityAI_0x2F_Tmain_zako_domino_lst
// Made by beco
// Verison 1.0

#define SCOKAZU 8	 // スコアOBJ同時処理個数

#define TOKEI_ICON_Y	0x02
#define TOKEI_ICON_X	0x50

#define TIME_DSP_Y 0x02
#define TIME_DSP_X 0x60

enum {
    Q_INITIAL,
    Q_INITIAL2,
    Q_INITIAL3,
    Q_INITIAL4,
    Q_INITIAL5,
    Q_INITIAL6,
    Q_INITIAL7,
    Q_INITIAL8,
    Q_INITIAL9,
    Q_INITIAL10,
    Q_INITIAL11,
    Q_INITIAL12,
    Q_INITIAL13,
    Q_INITIAL14,
    Q_INITIAL15,
    Q_K0_WALK,
    K0_WALK,
    Q_K0_TURN1,
    K0_TURN1,
    Q_K0_TURN2,
    K0_TURN2,
    Q_K0_TURN3,
    K0_TURN3,
    Q_JITTO,
    JITTO,
    Q_TOBIOKI,
    TOBIOKI,
    Q_N_RAKKA_V,
    N_RAKKA_V,
    Q_H_RAKKA_V,
    H_RAKKA_V,
    Q_K2_LEFT,

    K2_LEFT,
    Q_K2_RIGHT,
    K2_RIGHT,
    Q_K1_LEFT,
    K1_LEFT,
    Q_K1_RIGHT,
    K1_RIGHT,
    Q_K6_LEFT,
    K6_LEFT,
    Q_K6_RIGHT,
    K6_RIGHT,
    Q_HIKKURI_L,
    HIKKURI_L,
    Q_HIKKURI_R,
    HIKKURI_R,
    Q_H_JITABAT,

    H_JITABAT,
    Q_K5_HIP,
    K5_HIP,
    Q_K4_LEFT,
    K4_LEFT,
    Q_K4_RIGHT,
    K4_RIGHT,
    Q_BOUND1_L,
    BOUND1_L,
    Q_BOUND2_L,
    BOUND2_L,
    Q_BOUND3_L,
    BOUND3_L,
    Q_BOUND1_R,
    BOUND1_R,
    Q_BOUND2_R,

    BOUND2_R,
    Q_BOUND3_R,
    BOUND3_R,
    Q_NH_RAKKA_L,
    NH_RAKKA_L,
    Q_NH_RAKKA_R,
    NH_RAKKA_R,
    Q_H_RAKKA_L,
    H_RAKKA_L,
    Q_H_RAKKA_R,
    H_RAKKA_R,
    Q_JISHINTOBI1,
    JISHINTOBI1,
    JISHINTOBI2,
    JISHINTOBI3,
    Q_K2D_LEFT,

    Q_K2D_RIGHT,
    Q_K3_LEFT,
    K3_LEFT,
    Q_K3_RIGHT,
    K3_RIGHT,
    Q_LF_MOVE_R,
    LF_MOVE_R,
    Q_LF_MOVE_L,
    LF_MOVE_L,
    Q_NAGE_L,
    NAGE_L,
    Q_NAGE_R,
    NAGE_R,
    Q_TNAGE_L,
    TNAGE_L,
    Q_TNAGE_R,

    TNAGE_R,
    Q_UNAGE_L,
    UNAGE_L,
    Q_UNAGE_R,
    UNAGE_R,
    Q_UTNAGE_L,
    UTNAGE_L,
    Q_UTNAGE_R,
    UTNAGE_R,
    Q_TD_ATA_R,
    Q_TD_ATA_L,
    Q_SOKUSI,
    Q_K5_HIP2,
    K5_HIP2,
    Q_T_AUX_0,
    T_AUX_0,
    Q_T_AUX_1,
    T_AUX_1,
    Q_T_AUX_2,
    T_AUX_2,
    Q_T_AUX_3,
    T_AUX_3,
    Q_T_AUX_4,
    T_AUX_4,
    Q_T_AUX_5,
    T_AUX_5,
    Q_T_AUX_6,
    T_AUX_6,
};

enum {
    NO_ATA_H,
    NO_TOGE,
    NO_TOGE2_H,
    MAE_TOGE,
    MAE_TOGE2_H,
    MOTSU,
    L_COIN,
    FLOWER_H,
    ALL_TOGE,
    ALL_TOGE2,
    ALL_TOGE3,
    ALL_TOGE4,
    ALL_TOGE5,
    ALL_TOGE_BOSS_H,
    ALL_MOERU,
    ALL_DEBU,
    ALL_ZONBI,
    ALL_ZONBI2,
    ALL_YUKI,
    ALL_BAT_H,
    ALL_ICE_H,
    OTAFUKU_H,
    TUMIKI_4_H,
    NORU_HAKO,
    NORU_HAKO2,
    NORU_HAKO_NH,
    NORU_HAKO2_NH,
    NORU_YUKA_1,
    NORU_YUKA_1ND,
    NORU_YUKA_1A,
    D_MOAI_H1,
    D_MOAI_H2,
    S_BIRD_H1,
    UE_TOGE,
    PROPERA_H,
    HARIMEN_H1,
    HARIMEN_H2,
    MAE_UE_TOGE,
    USHIRO_UE_TOGE,
    ALL_BALLOON,
    ALL_BALLOON_BOSS_H,
    BIG_MARUMEN_H,
    BIG_MARUMEN_H2,
    BIG_MARUMEN_H3,
    PUUTIN_H,
    PUUTIN2_H,
    SHITA_TOGE,
    SHITA_MAE_TOGE_H,
    J_SWITCH_H,
    HATI_H,
    HATI2_H,
    SHITA_BANE_H,
    SHITA_MAE_BANE_H,
    MENISI_H,
    ROULETTE_H,
    TOBAWANI_UE_TOGE_H,
    ALL_TOGE_MAGMA_H,
    MAE_ALL_TOGE_H,
    MAE_ALL_TOGE_N_H,
    UE_TOGE_MOTSU_TOGEDON_H,
    FURAWANA_HEAD_H,
    ALL_ZONBI_MODORI_H,
    TUNAMI_H,
    DORAMORI_H,
    DORAMORI2_H,
    DORAMORI_HEAD_H,
    KONTOGE_SHABERU_H,
    KONTOGE_SHABERU_H2,
    KONTOGE_SHABERU_H3,
    ALL_TOGE_ZERO_H,
    PIYO_BOMB_H,
    KONTOGE_OYA_H,
    MOUJA_OMEN_H,
    MOUJA_FACE_H,
    ALL_AWA,
    MAE_UE_TOGE_WH,
    SHITA_MIGI_TOGE_WH,
    UE_MIGI_TOGE_WH,
    SHELL_WH,
    TOBAWANI_WH,
    TOBAWANI_NOTOGE_WH,
    ALL_TOGE_WH,
    ALL_HAJIKU_WH,
    DORIZAME_WH,
    DORIZAME2_WH,
};

enum {
	KN_TSCORE10A,
	KN_TSCORE50A,
	KN_TSCORE100A,
	KN_TSCORE500A,

	KN_TSCORE1000A,
	KN_HIPSTAR,				// ヒップの星のKind Number 	(TOptObjSet用)
	KN_ATKSTAR,				// アタックのバシッ！		(TOptObjSet用)
	KN_MIZUBASHIRA,			// 水柱のKind Number 		(TOptObjSet用)

	KN_KWR_IWA_1A,			// 岩壊れ1A	左			 	(TOptObjSet用)
	KN_KWR_IWA_2A,			// 岩壊れ2A	右			 	(TOptObjSet用)
	KN_KWR_IWA_3A,			// 岩壊れ3A	上			 	(TOptObjSet用)
	KN_KWR_IWA_4A,			// 岩壊れ4A	下			 	(TOptObjSet用)

	KN_KWR_IWA_5A,			// 岩壊れ5A	左遠くへ	 	(TOptObjSet用)
	KN_KWR_IWA_6A,			// 岩壊れ6A	右遠くへ	 	(TOptObjSet用)
	KN_KWR_IWA_1B,			// 岩壊れ1B	左			 	(TOptObjSet用)
	KN_KWR_IWA_2B,			// 岩壊れ2B	右			 	(TOptObjSet用)

	KN_KWR_IWA_3B,			// 岩壊れ3B	上			 	(TOptObjSet用)
	KN_KWR_IWA_4B,			// 岩壊れ4B	下			 	(TOptObjSet用)
	KN_KWR_IWA_5B,			// 岩壊れ5B	左遠くへ	 	(TOptObjSet用)
	KN_KWR_IWA_6B,			// 岩壊れ6B	右遠くへ	 	(TOptObjSet用)

	KN_KWR_METAL_1A,		// 金属壊れ1A	左		 	(TOptObjSet用)
	KN_KWR_METAL_2A,		// 金属壊れ2A	右		 	(TOptObjSet用)
	KN_KWR_METAL_3A,		// 金属壊れ3A	上		 	(TOptObjSet用)
	KN_KWR_METAL_4A,		// 金属壊れ4A	下		 	(TOptObjSet用)

	KN_KWR_METAL_5A,		// 金属壊れ5A	左遠くへ	(TOptObjSet用)
	KN_KWR_METAL_6A,		// 金属壊れ6A	右遠くへ	(TOptObjSet用)
	KN_KWR_METAL_1B,		// 金属壊れ1B	左			(TOptObjSet用)
	KN_KWR_METAL_2B,		// 金属壊れ2B	右			(TOptObjSet用)

	KN_KWR_METAL_3B,		// 金属壊れ3B	上			(TOptObjSet用)
	KN_KWR_METAL_4B,		// 金属壊れ4B	下			(TOptObjSet用)
	KN_KWR_METAL_5B,		// 金属壊れ5B	左遠くへ	(TOptObjSet用)
	KN_KWR_METAL_6B,		// 金属壊れ6B	右遠くへ	(TOptObjSet用)

	KN_KWR_TREE_1A,			// 木材壊れ1A	左		 	(TOptObjSet用)
	KN_KWR_TREE_2A,			// 木材壊れ2A	右		 	(TOptObjSet用)
	KN_KWR_TREE_3A,			// 木材壊れ3A	上		 	(TOptObjSet用)
	KN_KWR_TREE_4A,			// 木材壊れ4A	下		 	(TOptObjSet用)

	KN_KWR_TREE_5A,			// 木材壊れ5A	左遠くへ	(TOptObjSet用)
	KN_KWR_TREE_6A,			// 木材壊れ6A	右遠くへ	(TOptObjSet用)
	KN_KWR_TREE_1B,			// 木材壊れ1B	左			(TOptObjSet用)
	KN_KWR_TREE_2B,			// 木材壊れ2B	右			(TOptObjSet用)

	KN_KWR_TREE_3B,			// 木材壊れ3B	上			(TOptObjSet用)
	KN_KWR_TREE_4B,			// 木材壊れ4B	下			(TOptObjSet用)
	KN_KWR_TREE_5B,			// 木材壊れ5B	左遠くへ	(TOptObjSet用)
	KN_KWR_TREE_6B,			// 木材壊れ6B	右遠くへ	(TOptObjSet用)

	KN_KWR_LEAF_A,			// 葉っぱ壊れ 共通		 	(TOptObjSet用)
	KN_KWR_LEAF_B,			// 葉っぱ壊れ 共通		 	(TOptObjSet用)
	KN_LOSTCOIN,			// 持ち時間０以降、ワリオから出るコイン(TOptObjSet用)
	KN_HIPSTAR2A,			// ヒップの星SE無しTimeUpスクロールOBJ消滅用(TOptObjSet用)

	KN_LOST_HEART,			// ワリオロストハート		(TOptObjSet用)
	KN_TUCHIKEMURI_L,		// 土煙Ｌ					(TOptObjSet用)
	KN_TUCHIKEMURI_R,		// 土煙Ｒ					(TOptObjSet用)
	KN_ITEM_BAKUHATU,		// 元店長専用アイテム爆発(KN_ATKSTARと同じ)	(TOptObjSet用)

	KN_ITEM_NOTE_0,			// 店長専用音符0			(TOptObjSet用)
	KN_ITEM_NOTE_1,			// 店長専用音符1			(TOptObjSet用)
	KN_ITEM_NOTE_2,			// 店長専用音符2			(TOptObjSet用)
	KN_ITEM_NOTE_3,			// 店長専用音符3			(TOptObjSet用)

	KN_ITEM_NOTE_4,			// 店長専用音符4			(TOptObjSet用)
	KN_ITEM_NOTE_5,			// 店長専用音符5			(TOptObjSet用)
	KN_ITEM_NOTE_6,			// 店長専用音符6			(TOptObjSet用)
	KN_ITEM_NOTE_7,			// 店長専用音符7			(TOptObjSet用)

	KN_ITEM_NOTE_8,			// 店長専用音符8			(TOptObjSet用)
	KN_ITEM_NOTE_9,			// 店長専用音符9			(TOptObjSet用)
	KN_GET_HEART,			// ハートゲットエフェクト	(TOptObjSet用)
	KN_GET_QHEART,			// 1/4ハートゲットエフェクト(TOptObjSet用)

	KN_ATKSTAR2,			// アタックのバシッ！の長い版(TOptObjSet用)
	KN_KAKERA_ICON_DSP,		// かけらアイコン表示		(TOptObjSet用)
	KN_CARD_ICON_DSP,		// カードアイコン表示		(TOptObjSet用)
	KN_MOUJA_HIKARI,		// モージャ専用、光			(TOptObjSet用)

	KN_KEMURI_M,			// ボス戦専用オプションけむりM(TOptObjSet用)
	KN_KEMURI_L,			// ボス戦専用オプションけむりM(TOptObjSet用)
	KN_OLDSTAR,				// 昔のアタックの星			(TOptObjSet用)
	KN_JEWELSTAR,			// 宝が上昇する時のきらきら星(TOptObjSet用)

	KN_HAKASE_AWA_L,		// 水中博士用泡Ｌ			(TOptObjSet用)
	KN_HAKASE_AWA_R,		// 水中博士用泡Ｒ			(TOptObjSet用)

// - - - - - - - - - - - - - ゲートでクリアしない＆後出し優先よりも優先↓(ここから下)

	KN_BAINOMIX2,			// 倍の実期間×２表示 		(TOptObjSet用)
	KN_KAGI,				// ワリオに引っ付く鍵		(TOptObjSet用)
	KN_TIMEUP_WARIO,		// タイムアップワリオ		(TOptObjSet用)
	KN_LIFEZERO_WARIO,		// ライフゼロワリオ			(TOptObjSet用)

// - - - - - - - - - - - - - 画面の固定位置に表示↓(ここから下)

	KN_TIME_DSP,			// カウントダウンデジタル表示(TOptObjSet用)
	KN_TOKEI_ICON_DSP,		// 時計アイコン表示			(TOptObjSet用)
	KN_HIPSTAR2B,			// ヒップの星SE無しTimeUp固定画面OBJ消滅用(TOptObjSet用)
	KN_SUGOROKU_ICON_DSP,	// すごろくアイコン表示(TOptObjSet用)

	KN_END_IWA_0,			// エンディング岩０			(TOptObjSet用)
	KN_END_IWA_1,			// エンディング岩１			(TOptObjSet用)
	KN_END_IWA_2,			// エンディング岩２			(TOptObjSet用)
	KN_END_IWA_3,			// エンディング岩３			(TOptObjSet用)
	KN_END_IWA_4,			// エンディング岩４			(TOptObjSet用)
	KN_END_IWA_00,			// エンディング岩０			(TOptObjSet用)
	KN_END_IWA_000,			// エンディング岩０			(TOptObjSet用)
	KN_END_IWA_0000,		// エンディング岩０			(TOptObjSet用)

  // Custom Code
  KN_TSCORE10A_JUMP,
  KN_TSCORE100A_DASH,
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

struct TAnmDef {
    unsigned long uiObjAddr;
    unsigned char ucTimer;
    unsigned char unused_1;
    unsigned char unused_2;
    unsigned char unused_3;
};

struct Tk2Def {
	unsigned char ucStatus;
	unsigned char ucAnmTimer;
	unsigned char ucKind;
	unsigned char ucSeq;
	unsigned char ucWork0;
	unsigned char ucWork1;
	unsigned short usAnmPat;
	unsigned short usPosY;
	unsigned short usPosX;
} ;

#define unk_83C4754 0x83C4754
#define unk_83C4794 0x83C4794
#define unk_83C47D4 0x83C47D4
#define unk_83C47B4 0x83C47B4

#define CurrentRoomId (*(volatile unsigned char*) 0x3000024)
#define ucBgCountDown (*(volatile unsigned char*) 0x3000035)
#define ucTimeUp (*(volatile unsigned char*) 0x3000047)
#define EntityLeftOverStateList ((volatile unsigned char*) 0x3000564)
#define CurrentEnemyData (*(volatile struct EnemyDataStructure*) 0x3000A24)
#define ucThit2 (*(volatile unsigned char*) 0x3000A51)
#define HasKeyzer (*(volatile signed short*) 0x3000C0C)
#define ucJSwitchOnFlg (*(volatile unsigned char*) 0x3000C0D)
#define Wario_ucReact (*(volatile unsigned char*) 0x3001898)
#define Wario_ucStat (*(volatile unsigned char*) 0x3001899)
#define BgmMapNextNum (*(volatile unsigned short*) 0x3003202)
#define BgmMapNowNum (*(volatile unsigned short*) 0x3003204)

#define MapSwitch1 (*(volatile unsigned char*) 0x300002f)
#define MapSwitch2 (*(volatile unsigned char*) 0x3000030)
#define MapSwitch3 (*(volatile unsigned char*) 0x3000031)
#define MapSwitch4 (*(volatile unsigned char*) 0x3000032) // frog blocks, etc (see WL4 RAM record)

#define ScEbuf ((volatile struct Tk2Def*) 0x3000B80) // 12 bytes
#define Scbuf (*(volatile struct Tk2Def*) 0x3000BE0) // 12 bytes

#define Sub_8001DA4_m4aSongNumStart ((int (*)(int)) 0x8001DA5)
#define Sub_8001DD0_m4aSongNumStartOrChange ((int (*)(int)) 0x8001DD1)
#define Sub_8001E70_m4aSongNumStop ((int (*)(int)) 0x8001E71)
#define Sub_8001ED8_m4aMPlayAllStop ((void (*)()) 0x8001ED9)

#define Sub_8023BFC_T_NoCorrectionBgAttack ((void (*)(unsigned short, unsigned short)) 0x8023BFD)
#define Sub_80766E8_TOptObjSet ((int (*)(int,int,char)) 0x80766E9)
#define Sub_8088620_WarioVoiceSet ((void (*)(int)) 0x8088621)
#define Sub_8026838_EnemyWanderingCom ((void (*)()) 0x8026839)

#define Sub_803C464_Q_INITIAL_zako_domino_rgl ((void (*)()) 0x803C465)
#define Sub_803C4DC_Q_INITIAL2_zako_domino_rgl ((void (*)()) 0x803C4DD)
#define Sub_803C5C0_K0_WALK_zako_domino_rgl ((void (*)()) 0x803C5C1)
#define Sub_803C654_Q_K0_TURN1_zako_domino_rgl ((void (*)()) 0x803C655)
#define Sub_803C6BC_K0_TURN1_zako_domino_rgl ((void (*)()) 0x803C6BD)
#define Sub_803C628_K0_TURN2_zako_domino_rgl ((void (*)()) 0x803C629)
#define Sub_803C550_Q_INITIAL3_zako_domino_rgl ((void (*)()) 0x803C551)

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

void MC_Sub_803D2B4_EntityAI_0x2F_Tmain_zako_domino_lst() {
  // Sub_803D2D0_EntityAI_0x3A_Tmain_zako_domino_rgl
  switch ( CurrentEnemyData.CurEnemy_CurrentAnimationId )
  {
    case Q_INITIAL:
      Q_INITIAL_zako_domino_rgl();
      break;
    case Q_INITIAL2:
      Sub_803C4DC_Q_INITIAL2_zako_domino_rgl();
      break;
    case K0_WALK:
      Sub_803C5C0_K0_WALK_zako_domino_rgl();
      break;
    case Q_K0_TURN1:
      Q_K0_TURN1_zako_domino_rgl();
      break;
    case K0_TURN1:
      K0_TURN1_zako_domino_rgl();
      break;
    case K0_TURN2:
      Sub_803C628_K0_TURN2_zako_domino_rgl();
      break;
    case JITTO:
      break;
    default:
      Sub_803C550_Q_INITIAL3_zako_domino_rgl();
      break;
  }
  Sub_8026838_EnemyWanderingCom();
}

void Q_INITIAL_zako_domino_rgl()
{
  CurrentEnemyData.CurEnemy_usStatus |= 0x408;
  CurrentEnemyData.CurEnemy_SizeY0_Bottom = 40;
  CurrentEnemyData.CurEnemy_SizeY1_Top = 0;
  CurrentEnemyData.CurEnemy_SizeX_LeftRight = 32;
  CurrentEnemyData.CurEnemy_HitboxY0 = 52;
  CurrentEnemyData.CurEnemy_HitboxY1 = 0;
  CurrentEnemyData.CurEnemy_HitboxX0 = 40;
  CurrentEnemyData.CurEnemy_HitboxX1 = 0;
  CurrentEnemyData.CurEnemy_GuardAndDamageParam = J_SWITCH_H;
  CurrentEnemyData.CurEnemy_XPos -= 32;
  CurrentEnemyData.CurEnemy_Prio = 3;
  CurrentEnemyData.OAMDataPackPointerForCurrentAnimation = unk_83C47D4;
  CurrentEnemyData.CurEnemy_RealFrameCountForCurrentAnimationFrame = 0;
  CurrentEnemyData.CurEnemy_CurrentAnimationFrameId = 0;
  CurrentEnemyData.CurEnemy_CurrentAnimationId = K0_WALK;
  CurrentEnemyData.CurEnemy_TWork0 = 30;
  CurrentEnemyData.CurEnemy_TWork1 = 0;
}

void Q_K0_TURN1_zako_domino_rgl()
{
  int i;
  EntityLeftOverStateList[64 * CurrentRoomId + CurrentEnemyData.CurEnemy_RoomEntitySlotId] = 33;
  // MapSwitch1 = 3;
  CurrentEnemyData.OAMDataPackPointerForCurrentAnimation = unk_83C4754;
  CurrentEnemyData.CurEnemy_RealFrameCountForCurrentAnimationFrame = 0;
  CurrentEnemyData.CurEnemy_CurrentAnimationFrameId = 0;
  CurrentEnemyData.CurEnemy_TWork0 = 15;
  CurrentEnemyData.CurEnemy_CurrentAnimationId = K0_TURN1;
  CurrentEnemyData.CurEnemy_GuardAndDamageParam = NORU_YUKA_1A;
  CurrentEnemyData.CurEnemy_HitboxY0 = 40;
  // Sub_803B9FC_DominodummyDelete();
  // Sub_803BA64_DominoBlockDelete();
  Sub_8001DA4_m4aSongNumStart(235);
  Sub_8088620_WarioVoiceSet(1);
  for ( i = 0 ; i < SCOKAZU ; i++ )
  {
    if ( ScEbuf[i].ucKind == KN_TIME_DSP )
    {
      ScEbuf[i].ucSeq = 44; // Quick Timer Appearing
    }
    if ( ScEbuf[i].ucKind == KN_TOKEI_ICON_DSP )
    {
      ScEbuf[i].ucSeq = 6; // Quick Timer Appearing
    }
  }
  ucJSwitchOnFlg = 0;
  ucBgCountDown = 0;
  MapSwitch4 = 3; // Frog Switch
  ucTimeUp = 0;
  Sub_8001DD0_m4aSongNumStartOrChange(bgmMapBackNum);
}

void K0_TURN1_zako_domino_rgl()
{
  if ( !--CurrentEnemyData.CurEnemy_TWork0 )
  {
    CurrentEnemyData.OAMDataPackPointerForCurrentAnimation = unk_83C47B4;
    CurrentEnemyData.CurEnemy_RealFrameCountForCurrentAnimationFrame = 0;
    CurrentEnemyData.CurEnemy_CurrentAnimationFrameId = 0;
    CurrentEnemyData.CurEnemy_CurrentAnimationId = JITTO;
    // Sub_80767DC_ScoreBunCoinDasu(CurrentEnemyData.CurEnemy_YPos - 64, CurrentEnemyData.CurEnemy_XPos + 96, 10);
  }
}
