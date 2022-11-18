// @Description MC_Sub_801B8BC_GameMain_End
// @HookAddress 0x1BB4C
// @HookString 01 48 86 46 01 48 00 47 99 BB 01 08 P
// @EntryFunctionSymbol MC_Sub_801B8BC_GameMain_End
// Mode: Thumb
// Made by beco

// ゲーム画面内のアイコンポジション（４倍座標ではない）
#define KAKERA_ICON_Y	0x02
#define KAKERA_ICON_X	0x0C	//0x10

#define CARD_ICON_Y 0x02
#define CARD_ICON_X 0x24	//0x28

#define HEART_ICON_Y	0x06	// 0x02
#define HEART_ICON_X	0x09

#define TOKEI_ICON_Y	0x02
#define TOKEI_ICON_X	0x50

#define TIME_DSP_Y 0x02
#define TIME_DSP_X 0x60

#define COIN_ICON_Y 0x06	// 0x02
#define COIN_ICON_X 0xB3

#define TOTAL_COIN_Y	0x06	// 0x02
#define TOTAL_COIN_X1	0xBC
#define TOTAL_COIN_X2	0xCC

#define SIY 0x84*4 // すごろくアイコン初期座標Y
#define SIX 0x10*4 // すごろくアイコン初期座標X

#define BOSS_HP_X 0xA1

#define SCOKAZU 8	 // スコアOBJ同時処理個数

// ucStatus
#define TS_EXEC_ON  0x01 // d0　処理ON/OFFフラグ
#define TS_AFFINE_ON 0x02 // d1　回転拡縮フラグ （off:0　on:1）
#define TS_AFFINE_OFF 0xFD //
#define TS_YUUSEN_ON 0x04 // d2　優先フラグ  （off:0　on:1）
#define TS_YUUSEN_OFF 0xFB //
#define TS_TENMETU_ON 0x08 // d3　点滅ON/OFFフラグ（表示:0　非表示:1）
#define TS_TENMETU_OFF 0xF7 //

#define	KAGI_WAKEUP_TIME 48-1
#define	KAGI_TURN_TIME 25-1
#define	KAGI_TURN_2USIRO_TIME 10-1
#define	KAGI_TURN_USIRO2_TIME 16-1

#define KAGI_WAKEUP_L 0x83B49BC
#define KAGI_WALK_L 0x83B47C4
#define KAGI_WALK_R 0x83B47EC
#define KAGI_TURN_L2R 0x83B48DC
#define KAGI_TURN_R2L 0x83B4904
#define KAGI_TURN_L2USIRO 0x83B4814
#define KAGI_TURN_R2USIRO 0x83B483C
#define KAGI_USIRO 0x83B4864
#define KAGI_TURN_USIRO2L 0x83B488C
#define KAGI_TURN_USIRO2R 0x83B48B4

struct OamData {
  unsigned VPos : 8;
	unsigned AffineMode : 1;
	unsigned AffineParam : 1;
	unsigned ObjMode : 2;
	unsigned Mosaic : 1;
	unsigned ColorMode : 1;
	unsigned Shape : 2;
	unsigned HPos : 9;
	unsigned AffineParamNo_L : 3;
	unsigned HFlip : 1;
	unsigned VFlip : 1;
	unsigned Size : 2;
	unsigned CharNo : 10;
	unsigned Priority : 2;
	unsigned Pltt : 4;
} ;

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

// ucTimeUp シーケンス
enum ucTimeUp_stat{
  TUP_INIT,  // ステージ開始時
  TUP_COUNT,  // 残り時間カウント時(j_switchを踏んだ時)
  TUP_MOTI_T_END, // 持ち時間0:00になった時(0:00表示が上昇するきっかけ)
  TUP_DSP_CHANGE, // 持ち時間0:00表示が消えて右隅のコイン表示と入れ替わるきっかけ
  TUP_COIN_T_END, // 持ちコイン０（OBJデモの始まるきっかけ）
  TUP_WARIO_CHANGE,// 通常ワリオ止めて、消して、正面ワリオを出すきっかけ
  TUP_WARIO_CENTER,// タイムアップワリオ、真ん中に補正完了
  TUP_WARIO_KAKUDAI_START,// タイムアップワリオ、真ん中から前に押し出されるきっかけ
  TUP_ITEM_LOST, // かけら没収デモ始まりのきっかけ
  TUP_ITEM_LOST2, // カード没収デモ始まりのきっかけ
  TUP_END,
  TUP_KILL_BOSS, // ボス戦にてボスを倒した時
};

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

enum {
	KNH_WAKEUP,
	Q_KNH_WALK_L,
	KNH_WALK_L,
	Q_KNH_WALK_R,
	KNH_WALK_R,
	Q_KNH_TURN_L2R,
	KNH_TURN_L2R,
	Q_KNH_TURN_R2L,
	KNH_TURN_R2L,

	Q_KNH_TURN_L2USIRO,
	KNH_TURN_L2USIRO,
	Q_KNH_TURN_R2USIRO,
	KNH_TURN_R2USIRO,
	Q_KNH_USIRO,
	KNH_USIRO,
	Q_KNH_TURN_USIRO2L,
	KNH_TURN_USIRO2L,
	Q_KNH_TURN_USIRO2R,
	KNH_TURN_USIRO2R,
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

#define REG_DMA3SAD (*(volatile unsigned int*) 0x40000D4)
#define REG_DMA3DAD (*(volatile unsigned int*) 0x40000D8)
#define REG_DMA3CNT (*(volatile unsigned int*) 0x40000DC)

#define Sub_806C75C_GmapBg_AnimatedMain ((void (*)()) 0x806C75D)
#define Sub_801D684_EnemyMain ((void (*)()) 0x801D685)
#define Sub_806E7F8_GmScrSet ((void (*)()) 0x806E7F9)
#define Sub_8010154_WarioDispMain ((void (*)()) 0x8010155)
#define Sub_8074808_WarioHeartMake ((void (*)()) 0x8074809)
#define Sub_8074988_GmScoreCreate ((void (*)()) 0x8074989)
#define Sub_80751FC_TmScMain ((void (*)()) 0x80751FD)
#define Sub_801C5D8_GmWarioCreate ((void (*)()) 0x801C5D9)
#define Sub_801D8C4_EnemyDisplayMain ((void (*)()) 0x801D8C5)
#define Sub_8000A0C_ClearOamBuf ((int (*)()) 0x8000A0D)
#define Sub_806C794_GmapSceneCreate ((void (*)(int)) 0x806C795)
#define Sub_80101D0_WarioSoundMain ((void (*)()) 0x80101D1)
#define Sub_806C130_MapBgmChangeMain ((void (*)()) 0x806C131)
#define Sub_80762E4_TScoreOamCreate ((void (*)(int)) 0x80762E5)
#define Sub_8075988_GmTimerSub_loseCoinSoundsPalette ((void (*)()) 0x8075989)
#define Sub_80752F0_CoinChrScore ((void (*)()) 0x80752F1)
#define Sub_8075388_TimeChrScore ((void (*)()) 0x8075389)
#define Sub_807569C_TimeChrScore2 ((void (*)()) 0x807569D)
#define Sub_8094DFC_call_via_r0 ((void (*)(int)) 0x8094DFD)
#define Sub_806DE8C_WarioBgCheck_Gate ((void (*)(int,int)) 0x806DE8D)
#define Sub_80766E8_TOptObjSet ((int (*)(int,int,char)) 0x80766E9)
#define Sub_8076784_Change_KN_HIPSTAR2A ((void (*)()) 0x8076785)
#define Sub_8000A3C_FixMul ((int (*)(int,int)) 0x8000A3D)
#define Sub_8000A6C_FixInverse ((int (*)(int)) 0x8000A6D)

#define ucStageNum (*(volatile unsigned char*) 0x3000003)
#define ucHeyaNum (*(volatile unsigned char*) 0x3000024)
#define ucTimeUp (*(volatile unsigned char*) 0x3000047)

#define ucGmTime_Tflg (*(volatile unsigned char*) 0x3000C01)
#define ucGmScore_Tflg (*(volatile unsigned char*) 0x3000C02)
#define ucGmTimeCc_Tflg (*(volatile unsigned char*) 0x3000C03)
#define ucHasKeyzer (*(volatile unsigned char*) 0x3000C0C)

#define ScEbuf ((volatile struct Tk2Def*) 0x3000B80) // 12 bytes
#define Scbuf (*(volatile struct Tk2Def*) 0x3000BE0) // 12 bytes
#define sGameSeq (*(volatile unsigned char*) 0x3000C3C)
#define OamBuf ((volatile struct OamData*) 0x3001444)

#define Wario_ucReact (*(volatile unsigned char*) 0x3001898)
#define Wario_ucStat (*(volatile unsigned char*) 0x3001899)
#define Wario_usMukiX (*(volatile unsigned short*) 0x30018A6)
#define Wario_usMukiY (*(volatile unsigned short*) 0x30018A8)
#define Wario_usPosX (*(volatile unsigned short*) 0x30018AA)
#define Wario_usPosY (*(volatile unsigned short*) 0x30018AC)
#define Wario_sHitDX1 (*(volatile short*) 0x30018CA)
#define Wario_sHitDY1 (*(volatile short*) 0x30018CC)
#define ucWarOffFlg (*(volatile unsigned char*) 0x30019F8)
#define usGatePosX (*(volatile unsigned short*) 0x3001890)
#define usGatePosY (*(volatile unsigned short*) 0x3001892)
#define Wario_ucDokan (*(volatile unsigned char*) 0x300189A)

#define pSCObjData (*(volatile unsigned long*) 0x3000C10)
#define coinNumOAMPal1 (*(volatile unsigned char*) 0x3001449)
#define coinNumOAMPal2 (*(volatile unsigned char*) 0x3001459)
#define ucCntObj (*(volatile unsigned char*) 0x300184A)

#define OamBuf ((volatile struct OamData*) 0x3001444)

#define usAffnPA (*(volatile unsigned short*) 0x3000C14)
#define usAffnPB (*(volatile unsigned short*) 0x3000C16)
#define usAffnPC (*(volatile unsigned short*) 0x3000C18)
#define usAffnPD (*(volatile unsigned short*) 0x3000C1A)

#define sin_cos_table ((volatile unsigned short*) 0x8095138)

const long TScoreRoutins[] = {
  0x8076E69, 0x8076E7D, 0x8076E91, 0x8076EA5, 0x8076EB9, // 0x00
  0x8076EF9, 0x8076F69, 0x8077045, 0x80776C9, 0x8077721, // 0x05
  0x8077779, 0x80777D1, 0x8077829, 0x8077881, 0x80776F5, // 0x0A
  0x807774D, 0x80777A5, 0x80777FD, 0x8077855, 0x80778AD, // 0x0F
  0x80778D9, 0x8077931, 0x8077989, 0x80779E1, 0x8077A39, // 0x14
  0x8077A91, 0x8077905, 0x807795D, 0x80779B5, 0x8077A0D, // 0x19
  0x8077A65, 0x8077ABD, 0x8077AE9, 0x8077B41, 0x8077B99, // 0x1E
  0x8077BF1, 0x8077C49, 0x8077CA1, 0x8077B15, 0x8077B6D, // 0x23
  0x8077BC5, 0x8077C1D, 0x8077C75, 0x8077CCD, 0x8077CF9, // 0x28
  0x8077D25, 0x80781FD, 0x8076F39, 0x8076C01, 0x8077071, // 0x2D
  0x807709D, 0x8076F69, 0x80773F9, 0x8077441, 0x8077489, // 0x32
  0x80774D1, 0x8077519, 0x8077561, 0x80775A9, 0x80775F1, // 0x37
  0x8077639, 0x8077681, 0x8076CD9, 0x8076DA1, 0x8076F95, // 0x3C
  0x8078E31, 0x807907D, 0x8076FC1, 0x8076FED, 0x8077019, // 0x41
  0x8076ECD, 0x8077121, 0x80770C9, 0x80770F5, 0x8077D51, // 0x46
  0x8077D5D, 0x807915D, 0x8079575, 0x80782A5, 0x8078A81, // 0x4B
  0x8076F39, 0x8074D9D, 0x8079869, 0x8079909, 0x8079931, // 0x50
  0x8079959, 0x8079981, 0x8079869, 0x8079869, 0x8079869, // 0x55
};

struct TAnmDef {
  unsigned long uiObjAddr;
  unsigned char ucTimer;
  unsigned char unused_1;
  unsigned char unused_2;
  unsigned char unused_3;
};

#define Sub_8076A0C_TimeScore_Animation ((int (*)(int)) 0x8076A0D)
#define Sub_8076A54_TScoreCom_main ((void (*)()) 0x8076A55)
#define Sub_8076A90_TScoreCom_mainAF20 ((void (*)()) 0x8076A91)
#define Sub_8076B48_TScoreCom_mainAF15 ((void (*)()) 0x8076B41)

#define suji_Obj_00 0x840F1C8
#define j_watch_Obj_00 0x84118EC

const unsigned short suji_Obj_02[4] =
{
 	0x0001,
 	0x00f8, 0x0000, 0x4115, // Custom Code
};

const struct TAnmDef suji_Anm_02[2] =
{
 	{suji_Obj_02, 0xC8},
 	{0, 0}
};

#define	Anm_Score10 suji_Anm_02

const short	suji_Obj_04[4] =
{
  0x0001,
  0x40f8, 0x0000, 0x4116, // Custom Code
};

const struct TAnmDef suji_Anm_04[2] =
{
 	{suji_Obj_04, 0xC8},
 	{0, 0}
};

#define	Anm_Score100 suji_Anm_04

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
#define BgmMapBackNum (*(volatile unsigned short*) 0x3006F17)

void MC_Sub_801B8BC_GameMain_End() {
    // Custom Code
    if ( Wario_ucDokan == 2 )
      Sub_806DE8C_WarioBgCheck_Gate(usGatePosY, usGatePosX);

    // Vanilla Code
    int v6;
    if ( sGameSeq )  // run inside all the time except loading new room
    {
      Sub_806C75C_GmapBg_AnimatedMain();
      Sub_801D684_EnemyMain();
      if ( !ucWarOffFlg ) // hide wario (when wario come out from a vortex)
      {
        Sub_806E7F8_GmScrSet();
        Sub_8010154_WarioDispMain();
      }
      Sub_8074808_WarioHeartMake();
      // Sub_8074988_GmScoreCreate();

  		// Custom Code
      GmScoreCreate();
      TCrystalOamCreate();
      /*
      for (int n = 0; n < 128; n++)
      {
  			if ( OamBuf[n].CharNo == 0x86 || OamBuf[n].CharNo == 0xCB )
        {
    			OamBuf[n].Pltt = 5; // Palette change for Blue/Red crystal icon
        }
      }
      */
      /*
      OamBuf[ucCntObj].VPos = 0x0F;
      OamBuf[ucCntObj].HPos = 0xB4;
      OamBuf[ucCntObj].CharNo = 0x10C;
      OamBuf[ucCntObj].Pltt = 5;
      OamBuf[ucCntObj].Size = 0;
      ++ucCntObj;
      */

      // Sub_80751FC_TmScMain();
      TmScMain();

      int i;
      if ( crystal_Tflg )
      {
        for (i = 0; i < 3; i++)
        {
          // Number of Blue Crystal
          if ( airJumpNum >= i+1 )
          {
            REG_DMA3SAD = 0x8401D48;
          } else {
            REG_DMA3SAD = 0x8401C88;
          }
          REG_DMA3DAD = 0x60121A0 + (0x20 * i);
          REG_DMA3CNT = 0x80000010;
          // Number of Red Crystal
          if ( airAttackNum >= i+1 )
          {
            REG_DMA3SAD = 0x8401D68;
          } else {
            REG_DMA3SAD = 0x8401CE8;
          }
          REG_DMA3DAD = 0x6012200 + (0x20 * i);
          REG_DMA3CNT = 0x80000010;
        }
        crystal_Tflg = 0;
      }

      // Vanilla code
      if ( !ucWarOffFlg )
        Sub_801C5D8_GmWarioCreate();
      Sub_801D8C4_EnemyDisplayMain();
      v6 = Sub_8000A0C_ClearOamBuf();
      Sub_806C794_GmapSceneCreate(v6);
    }
    Sub_80101D0_WarioSoundMain();
    Sub_806C130_MapBgmChangeMain();
}

void TmScMain() {
    int i;
    //----------------------------------------- 各スコアＯＢＪの処理
    //--------------------------------- 手前
    for ( i = 0; i < SCOKAZU ; i++ )
    {
      if ( (ScEbuf[i].ucStatus&(TS_YUUSEN_ON|TS_EXEC_ON)) == (TS_YUUSEN_ON|TS_EXEC_ON) )	// 処理ステータスチェック
      {
        Scbuf = ScEbuf[i];					// EachBufからTempBufへコピー
        TScoreRoutines_extend(); // Custom Code
        if (Scbuf.ucStatus & TS_EXEC_ON)		// 処理ステータスチェック
          TScoreOamCreate_extend(i); // Custom Code
        ScEbuf[i] = Scbuf;					// TempBufからEachBufへ戻す
      }
    }
    //--------------------------------- 奥
    for ( i = 0 ; i < SCOKAZU ; i++ )
    {
      if ( (ScEbuf[i].ucStatus&(TS_YUUSEN_ON|TS_EXEC_ON)) == TS_EXEC_ON )	// 処理ステータスチェック
      {
        Scbuf = ScEbuf[i];					// EachBufからTempBufへコピー
        TScoreRoutines_extend(); // Custom Code
        if ( Scbuf.ucStatus & TS_EXEC_ON )		// 処理ステータスチェック
          TScoreOamCreate_extend(i); // Custom Code
        ScEbuf[i] = Scbuf;					// TempBufからEachBufへ戻す
      }
    }

    //----------------------------------------- その他
    Sub_8075988_GmTimerSub_loseCoinSoundsPalette();				// ゲームタイマー処理
    if ( ucGmScore_Tflg )			// ステージスコアキャラ転送フラグチェック
      Sub_80752F0_CoinChrScore();		// ステージスコア表示 キャラ転送
    if ( ucGmTime_Tflg )			// トータルタイムキャラ転送フラグ
      Sub_8075388_TimeChrScore();		// トータルタイム表示 キャラ転送
    if ( ucGmTimeCc_Tflg )			// コロン点滅用 キャラ転送フラグ
      Sub_807569C_TimeChrScore2();		// コロンor空白キャラ転送
}

void TScoreRoutines_extend() {
  switch ( Scbuf.ucKind ) // Custom Code
  {
    case KN_TSCORE10A_JUMP:
      MC_TScore10A_main();
      break;
    case KN_TSCORE100A_DASH:
      MC_TScore100A_main();
      break;
    case KN_KAGI:
      MC_TKagiMark_main();
      break;
    case KN_TIME_DSP:
      TTimeDsp_main_extend();
      break;
    case KN_TOKEI_ICON_DSP:
      TTokeiIconDsp_main_extend();
      break;
    default:
      Sub_8094DFC_call_via_r0(TScoreRoutins[Scbuf.ucKind]);		// 各スコアOBJの処理
      break;
  }
}

void TScoreOamCreate_extend(int i) {
  int ucKind_bk;
  if ( Scbuf.ucKind > 0x59 ) // Custom Code
  {
    ucKind_bk = Scbuf.ucKind;
    Scbuf.ucKind = 0;
    Sub_80762E4_TScoreOamCreate(i);				// 表示処理
    Scbuf.ucKind = ucKind_bk;
  } else {
    Sub_80762E4_TScoreOamCreate(i);				// 表示処理
  }
}

void TCrystalOamCreate() {
    int vp;
    if ( ucStageNum >= 4 ) {
      if ( ucHeyaNum == 1 ) return; // Don't display during boss fight
      vp = 0x06; // VPos for Boss level
    } else {
      vp = 0x0F; // VPos for Normal level
    }
    OamBuf[ucCntObj].VPos = vp;
    OamBuf[ucCntObj].HPos = 0xBC;
    OamBuf[ucCntObj].CharNo = 0x10D;
    OamBuf[ucCntObj].Pltt = 5;
    OamBuf[ucCntObj].Size = 0;
    OamBuf[ucCntObj].Shape = 1;
    OamBuf[ucCntObj].HFlip = 0;
    OamBuf[ucCntObj].VFlip = 0;
    OamBuf[ucCntObj].Priority = 0;
    ++ucCntObj;
    OamBuf[ucCntObj].VPos = vp;
    OamBuf[ucCntObj].HPos = 0xCC;
    OamBuf[ucCntObj].CharNo = 0x10F;
    OamBuf[ucCntObj].Pltt = 5;
    OamBuf[ucCntObj].Size = 1;
    OamBuf[ucCntObj].Shape = 1;
    OamBuf[ucCntObj].HFlip = 0;
    OamBuf[ucCntObj].VFlip = 0;
    OamBuf[ucCntObj].Priority = 0;
    ++ucCntObj;
}

void MC_TScore10A_main() {
    Sub_8076A0C_TimeScore_Animation(Anm_Score10);
    Sub_8076A90_TScoreCom_mainAF20();
}

void MC_TScore100A_main() {
    Sub_8076A0C_TimeScore_Animation(Anm_Score100);
    Sub_8076A90_TScoreCom_mainAF20();
}

void MC_TKagiMark_main() {
    // Vanilla code
    unsigned short a,b;
    unsigned short wy,wx,ky,kx,dx,dy;
    char ws;

  	ws = 0;	// 普通状態

  	if(!Wario_ucReact)
  	{
  		if(Wario_ucStat >= LDMOVE && Wario_ucStat <= NETDOWN)	ws = 1;	// 梯子状態
  		else if(Wario_ucStat == DOKANU || Wario_ucStat == DOKAND)	ws = 1;	// 土管状態
  	}

  	if(ucTimeUp >= TUP_WARIO_CHANGE)
  	{
  		Sub_8076784_Change_KN_HIPSTAR2A();
  		return;
  	}

  	switch(Scbuf.ucSeq)
  	{
  		case KNH_WAKEUP:
  			Sub_8076A0C_TimeScore_Animation(KAGI_WAKEUP_L);
  			if(++Scbuf.ucWork0 < KAGI_WAKEUP_TIME);
  			else	Scbuf.ucSeq = Q_KNH_WALK_L;
  			break;

  		case Q_KNH_WALK_L:
  			Scbuf.ucSeq = KNH_WALK_L;
  			Scbuf.usAnmPat = 0;
  			Scbuf.ucAnmTimer = 0;
  		case KNH_WALK_L:
  			Sub_8076A0C_TimeScore_Animation(KAGI_WALK_L);
  			if(ws)	Scbuf.ucSeq = Q_KNH_TURN_L2USIRO;
  			else if(Wario_usMukiX & 0x10)	Scbuf.ucSeq = Q_KNH_TURN_L2R; // R_KEY
  			break;

  		case Q_KNH_WALK_R:
  			Scbuf.ucSeq = KNH_WALK_R;
  			Scbuf.usAnmPat = 0;
  			Scbuf.ucAnmTimer = 0;
  		case KNH_WALK_R:
  			Sub_8076A0C_TimeScore_Animation(KAGI_WALK_R);
  			if(ws)	Scbuf.ucSeq = Q_KNH_TURN_R2USIRO;
  			else if(Wario_usMukiX & 0x20)	Scbuf.ucSeq = Q_KNH_TURN_R2L; // L_KEY
  			break;

  		case Q_KNH_TURN_L2R:
  			Scbuf.ucSeq = KNH_TURN_L2R;
  			Scbuf.ucWork0 = KAGI_TURN_TIME;
  			Scbuf.usAnmPat = 0;
  			Scbuf.ucAnmTimer = 0;
  		case KNH_TURN_L2R:
  			Sub_8076A0C_TimeScore_Animation(KAGI_TURN_L2R);
  			if(--Scbuf.ucWork0);
  			else	Scbuf.ucSeq = Q_KNH_WALK_R;
  			break;

  		case Q_KNH_TURN_R2L:
  			Scbuf.ucSeq = KNH_TURN_R2L;
  			Scbuf.ucWork0 = KAGI_TURN_TIME;
  			Scbuf.usAnmPat = 0;
  			Scbuf.ucAnmTimer = 0;
  		case KNH_TURN_R2L:
  			Sub_8076A0C_TimeScore_Animation(KAGI_TURN_R2L);
  			if(--Scbuf.ucWork0);
  			else	Scbuf.ucSeq = Q_KNH_WALK_L;
  			break;

  		case Q_KNH_TURN_L2USIRO:
  			Scbuf.ucSeq = KNH_TURN_L2USIRO;
  			Scbuf.ucWork0 = KAGI_TURN_2USIRO_TIME;
  			Scbuf.usAnmPat = 0;
  			Scbuf.ucAnmTimer = 0;
  		case KNH_TURN_L2USIRO:
  			Sub_8076A0C_TimeScore_Animation(KAGI_TURN_L2USIRO);
  			if(--Scbuf.ucWork0);
  			else	Scbuf.ucSeq = Q_KNH_USIRO;
  			break;

  		case Q_KNH_TURN_R2USIRO:
  			Scbuf.ucSeq = KNH_TURN_R2USIRO;
  			Scbuf.ucWork0 = KAGI_TURN_2USIRO_TIME;
  			Scbuf.usAnmPat = 0;
  			Scbuf.ucAnmTimer = 0;
  		case KNH_TURN_R2USIRO:
  			Sub_8076A0C_TimeScore_Animation(KAGI_TURN_R2USIRO);
  			if(--Scbuf.ucWork0);
  			else	Scbuf.ucSeq = Q_KNH_USIRO;
  			break;

  		case Q_KNH_USIRO:
  			Scbuf.ucSeq = KNH_USIRO;
  			Scbuf.usAnmPat = 0;
  			Scbuf.ucAnmTimer = 0;
  		case KNH_USIRO:
  			Sub_8076A0C_TimeScore_Animation(KAGI_USIRO);
  			if(!ws)
  			{
  				if(Wario_usMukiX & 0x20)	Scbuf.ucSeq = Q_KNH_TURN_USIRO2L; // L_KEY
  				else	Scbuf.ucSeq = Q_KNH_TURN_USIRO2R;
  			}
  			break;

  		case Q_KNH_TURN_USIRO2L:
  			Scbuf.ucSeq = KNH_TURN_USIRO2L;
  			Scbuf.ucWork0 = KAGI_TURN_USIRO2_TIME;
  			Scbuf.usAnmPat = 0;
  			Scbuf.ucAnmTimer = 0;
  		case KNH_TURN_USIRO2L:
  			Sub_8076A0C_TimeScore_Animation(KAGI_TURN_USIRO2L);
  			if(--Scbuf.ucWork0);
  			else	Scbuf.ucSeq = Q_KNH_WALK_L;
  			break;

  		case Q_KNH_TURN_USIRO2R:
  			Scbuf.ucSeq = KNH_TURN_USIRO2R;
  			Scbuf.ucWork0 = KAGI_TURN_USIRO2_TIME;
  			Scbuf.usAnmPat = 0;
  			Scbuf.ucAnmTimer = 0;
  		case KNH_TURN_USIRO2R:
  			Sub_8076A0C_TimeScore_Animation(KAGI_TURN_USIRO2R);
  			if(--Scbuf.ucWork0);
  			else	Scbuf.ucSeq = Q_KNH_WALK_R;
  			break;

  		default:
  			Sub_8076A0C_TimeScore_Animation(KAGI_USIRO);
  			break;
  	}


  // ワリオ、どこでもドアーに入って脱出状態になった時
  	if( !ucHasKeyzer )
  	{
      // Custom code
			Sub_80766E8_TOptObjSet(Scbuf.usPosY, Scbuf.usPosX, KN_TUCHIKEMURI_R);
  		// Sub_801E430_EnemyChildSet_WS(DOCODOOR_KAGI_OUT, 0, ucDocodoorChrOfs, usDocodoorPosY, usDocodoorPosX);
  		Scbuf.ucStatus = 0;
  	}

  // 通常時
  //--------------------------------------------- X pos 作る
  	dx = 0;
  	kx = Scbuf.usPosX+512;
  	wx = Wario_usPosX+512;

  	if(ws)	b = 4;
  	else	b = 64;

  	if(Wario_usMukiX & 0x20) // L_KEY
  	{
  		wx += b;

  		if(kx > wx)	dx = kx - wx;
  		else	dx = wx - kx;

  		if(dx <= 8)	a = 0;
  		else	a = (dx-8) >> 3;

  		if(kx > wx)	Scbuf.usPosX -= a;
  		else if(kx < wx)	Scbuf.usPosX += a;
  	}
  	else
  	{
  		wx -= b;

  		if(kx > wx)	dx = kx - wx;
  		else	dx = wx - kx;

  		if(dx <= 8)	a = 0;
  		else	a = (dx-8) >> 3;

  		if(kx < wx)	Scbuf.usPosX += a;
  		else if(kx > wx)	Scbuf.usPosX -= a;
  	}
  //--------------------------------------------- Y pos 作る
  	dy = 0;
  	ky = Scbuf.usPosY+512;
  	if(ws)	wy = Wario_usPosY+512;
  	else	wy = Wario_usPosY+Wario_sHitDY1+512;

  	if(ky > wy)	dy = ky - wy;
  	else	dy = wy - ky;

  	if(dy <= 8)	a = 0;
  	else	a = (dy-8) >> 3;

  	if(ky > wy)	Scbuf.usPosY -= a;
  	else if(ky < wy)	Scbuf.usPosY += a;
}

void GmScoreCreate() {
  int n;

//OamBufの作成
	n = 0;

	if(ucStageNum >= 4)		// ボスステージでは、ボスの体力メーター
	{	// ただし、ボスステージの廊下以外でボスを倒していない時
		if(ucHeyaNum == 1 && ucTimeUp!=TUP_KILL_BOSS)
		{
      OamBuf[n].HFlip = 0;
      OamBuf[n].VFlip = 0;
      OamBuf[n].Priority = 0;
			OamBuf[n].VPos = COIN_ICON_Y;
			OamBuf[n].Shape = 1;
			OamBuf[n].HPos = BOSS_HP_X;
			OamBuf[n].Size = 1;
			OamBuf[n].CharNo = 0x160;
			OamBuf[n].Pltt = 0x0E;
			n++;

      OamBuf[n].HFlip = 0;
      OamBuf[n].VFlip = 0;
      OamBuf[n].Priority = 0;
			OamBuf[n].VPos = COIN_ICON_Y;
			OamBuf[n].Shape = 1;
			OamBuf[n].HPos = BOSS_HP_X+32;
			OamBuf[n].Size = 1;
			OamBuf[n].CharNo = 0x164;
			OamBuf[n].Pltt = 0x0E;
			n++;

      OamBuf[n].HFlip = 0;
      OamBuf[n].VFlip = 0;
      OamBuf[n].Priority = 0;
			OamBuf[n].VPos = COIN_ICON_Y;
			OamBuf[n].Shape = 1;
			OamBuf[n].HPos = BOSS_HP_X+64;
			OamBuf[n].Size = 0;
			OamBuf[n].CharNo = 0x168;
			OamBuf[n].Pltt = 0x0E;
			n++;
		}
	}
	else					// ボスステージ以外では、ステージコイン表示
	{
		if(ucTimeUp < TUP_DSP_CHANGE)
		{
		//--------------------------- コインアイコン
      OamBuf[n].HFlip = 0;
      OamBuf[n].VFlip = 0;
      OamBuf[n].Priority = 0;
			OamBuf[n].VPos = COIN_ICON_Y;
			OamBuf[n].HPos = COIN_ICON_X;
			OamBuf[n].Size = 0;
			OamBuf[n].CharNo = 0xCB;
			OamBuf[n].Pltt = 6;
			n++;
		//---------------------------- 合計コイン金額
      OamBuf[n].HFlip = 0;
      OamBuf[n].VFlip = 0;
      OamBuf[n].Priority = 0;
			OamBuf[n].VPos = TOTAL_COIN_Y;
			OamBuf[n].Shape = 1;
			OamBuf[n].HPos = TOTAL_COIN_X1;
			OamBuf[n].Size = 0;
			OamBuf[n].CharNo = 0x84;
			OamBuf[n].Pltt = 4;
			n++;

      OamBuf[n].HFlip = 0;
      OamBuf[n].VFlip = 0;
      OamBuf[n].Priority = 0;
			OamBuf[n].VPos = TOTAL_COIN_Y;
			OamBuf[n].Shape = 1;
			OamBuf[n].HPos = TOTAL_COIN_X2;
			OamBuf[n].Size = 1;
			OamBuf[n].CharNo = 0x86;
			OamBuf[n].Pltt = 4;
			n++;
		}
	}
//-----------------------------------------------------
// ワリオライフ表示

	if(ucStageNum >= 4)	// ボスステージ（下半分の1/8ハート用ゲージ無し）
	{
    /*
		if(!ucHeyaNum)	// ボスステージの廊下の時は、ハートゲージも無し
		{
			ucCntObj = n;
			return;
		}
    */

    OamBuf[n].HFlip = 0;
    OamBuf[n].VFlip = 0;
    OamBuf[n].Priority = 0;
		OamBuf[n].VPos = HEART_ICON_Y;
		OamBuf[n].Shape =1;
		OamBuf[n].HPos = HEART_ICON_X;
		OamBuf[n].Size = 1;
		OamBuf[n].CharNo = 0x90;
		OamBuf[n].Pltt = 7;
		n++;

    OamBuf[n].HFlip = 0;
    OamBuf[n].VFlip = 0;
    OamBuf[n].Priority = 0;
		OamBuf[n].VPos = HEART_ICON_Y;
		OamBuf[n].Shape =1;
		OamBuf[n].HPos = HEART_ICON_X+32;
		OamBuf[n].Size = 1;
		OamBuf[n].CharNo = 0x94;
		OamBuf[n].Pltt = 7;
		n++;
	}
	else				// ボスステージ以外
	{
    OamBuf[n].HFlip = 0;
    OamBuf[n].VFlip = 0;
    OamBuf[n].Priority = 0;
		OamBuf[n].VPos = HEART_ICON_Y;
		OamBuf[n].Shape =1;
		OamBuf[n].HPos = HEART_ICON_X;
		OamBuf[n].Size = 2;
		OamBuf[n].CharNo = 0x90;
		OamBuf[n].Pltt = 7;
		n++;

    OamBuf[n].HFlip = 0;
    OamBuf[n].VFlip = 0;
    OamBuf[n].Priority = 0;
		OamBuf[n].VPos = HEART_ICON_Y;
		OamBuf[n].Shape =1;
		OamBuf[n].HPos = HEART_ICON_X+32;
		OamBuf[n].Size = 2;
		OamBuf[n].CharNo = 0x94;
		OamBuf[n].Pltt = 7;
		n++;
	}

//-----------------------------------------------------
	ucCntObj = n;
}

void TTimeDsp_main_extend() {
  int a;
  switch(Scbuf.ucSeq)
  {
		case 45: // Quick timer appearing
      a = 512;
			Scbuf.ucStatus |= (TS_AFFINE_ON | TS_YUUSEN_ON);
			pSCObjData = suji_Obj_00;
			Scbuf.usPosY += 16;
      if ( Scbuf.usPosY == TIME_DSP_Y*4 )
      {
				Scbuf.usPosY = TIME_DSP_Y*4;
				Scbuf.ucSeq = 2;
			}
      if(Scbuf.ucStatus|TS_AFFINE_ON)
    	{
        usAffnPA = Sub_8000A3C_FixMul(256, Sub_8000A6C_FixInverse(512));
        usAffnPB = Sub_8000A3C_FixMul(sin_cos_table[0], Sub_8000A6C_FixInverse(512));
        usAffnPC = Sub_8000A3C_FixMul(-sin_cos_table[0], Sub_8000A6C_FixInverse(512));
        usAffnPD = Sub_8000A3C_FixMul(256, Sub_8000A6C_FixInverse(512));
      }
			break;
    default:
      Sub_8094DFC_call_via_r0(TScoreRoutins[Scbuf.ucKind]);
      break;
  }
}

void TTokeiIconDsp_main_extend() {
  int a;
  switch(Scbuf.ucSeq)
  {
		case 7: // Quick timer appearing
			pSCObjData = j_watch_Obj_00;	// 針無し
      Scbuf.ucStatus &= TS_AFFINE_OFF;
			Scbuf.usPosY += 16;
      if (Scbuf.usPosY == TIME_DSP_Y*4)
      {
				Scbuf.usPosY = TOKEI_ICON_Y*4;
				Scbuf.usPosX = TOKEI_ICON_X*4;
				Scbuf.ucSeq = 4;
			}
    	if(Scbuf.ucStatus|TS_AFFINE_ON)
    	{
        usAffnPA = Sub_8000A3C_FixMul(256, Sub_8000A6C_FixInverse(a));
        usAffnPB = Sub_8000A3C_FixMul(sin_cos_table[0], Sub_8000A6C_FixInverse(a));
        usAffnPC = Sub_8000A3C_FixMul(-sin_cos_table[0], Sub_8000A6C_FixInverse(a));
        usAffnPD = Sub_8000A3C_FixMul(256, Sub_8000A6C_FixInverse(a));
      }
			break;
    default:
      Sub_8094DFC_call_via_r0(TScoreRoutins[Scbuf.ucKind]);
      break;
  }
}
