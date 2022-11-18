// @Description MC_Sub_8010A9C_WarKeyJump
// @HookAddress 0x2DEDD0
// @HookString P
// Mode: Thumb
// Made by beco

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
};

struct WJEffDef{
	unsigned char ucStat;
	unsigned char ucAnmTimer;			//アニメタイマー
	unsigned char ucAnmPat;			//アニメパターン
	unsigned short usPosX;				//Ｘ
	unsigned short usPosY;				//Ｙ
	unsigned long iAnmAddr;			//アドレス
} ;

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

#define Sub_8001DA4_m4aSongNumStart ((int (*)(int)) 0x8001DA5)
#define Sub_806DAC0_PanelYakuAllNum_TileEventId ((int (*)(unsigned short,unsigned short)) 0x806DAC1)
#define Sub_8014090_WarHeadCheck ((int (*)(unsigned short,unsigned int,int)) 0x8014091)
#define Sub_80766E8_TOptObjSet ((int (*)(int,int,char)) 0x80766E9)

#define CurrentEnemyData ((volatile struct EnemyDataStructure*) 0x3000104)
#define EntityLeftOverStateList ((volatile unsigned char*) 0x3000564)
#define WarioKey_React ((volatile unsigned int*) 0x82DEC70)
#define WarioChng_React ((volatile unsigned int*) 0x82DECA0)
#define WarioOthr_React ((volatile unsigned int*) 0x82DED90)
#define WarioMove_React ((volatile unsigned int*) 0x82DECD0)

#define ucGmScore_Tflg (*(volatile unsigned char*) 0x3000C02)
#define KeyPressContinuous ((volatile unsigned short*) 0x3001844)
#define usTrg_KeyPress1Frame ((volatile unsigned short*) 0x3001848)
#define Wario_ucReact (*(volatile unsigned char*) 0x3001898)
#define Wario_ucJpNext (*(volatile unsigned char*) 0x300189F)
#define Wario_ucJpFlg (*(volatile unsigned char*) 0x30018A0)
#define Wario_usTimer (*(volatile unsigned short*) 0x30018A4)
#define Wario_usMukiX (*(volatile unsigned short*) 0x30018A6)
#define Wario_usMukiY (*(volatile unsigned short*) 0x30018A8)
#define Wario_usPosX (*(volatile unsigned short*) 0x30018AA)
#define Wario_usPosY (*(volatile unsigned short*) 0x30018AC)
#define Wario_ucAnmTimer (*(volatile unsigned char*) 0x30018B6)
#define Wario_ucAnmTimer_LOBYTE (*(volatile unsigned char*) 0x30018B6)
#define Wario_ucAnmTimer_HIBYTE (*(volatile unsigned char*) 0x30018B7)
#define Wario_sMvSpeedX (*(volatile signed short*) 0x30018AE)
#define Wario_sMvSpeedY (*(volatile signed short*) 0x30018B0)
#define WarJEff ((volatile struct WJEffDef*) 0x3001950)
#define WarJEff_BYTE1 (*(volatile unsigned char*) 0x3001951)
#define WarJEff_LOBYTE (*(volatile unsigned char*) 0x3001950)
#define WarioLift_BYTE1 (*(volatile unsigned char*) 0x3001949)
#define WarioLift_LOBYTE (*(volatile unsigned char*) 0x3001948)
#define cGmStartFlg (*(volatile unsigned char*) 0x3000C3F)
#define usWarStopFlg (*(volatile unsigned char*) 0x30019F6)
#define ucWarOffFlg (*(volatile unsigned char*) 0x30019F8)
#define ucDisConFlg (*(volatile unsigned char*) 0x3000012)
#define ucGateNum (*(volatile unsigned char*) 0x3000025)
#define ucTimeUp (*(volatile unsigned char*) 0x3000047)
#define PassageID (*(volatile unsigned char*) 0x3000002)
#define InPassageLevelID (*(volatile unsigned char*) 0x3000003)
#define CurrentRoomId (*(volatile unsigned char*) 0x3000024)
#define usBgEvy (*(volatile unsigned char*) 0x3001870)

#define byte_82F1200 ((volatile unsigned char*) 0x82F1200)
#define byte_8307048 ((volatile unsigned char*) 0x8307048)

#define Sub_8075F44_TmScInit ((void (*)()) 0x8075F45)
#define Sub_801DE7C_EnemyInit ((void (*)()) 0x801DE7D)
#define Sub_80711E8_GameInit_ColorSetWork_All ((void (*)()) 0x80711E9)
#define Sub_806BF88_BgmChangeInit ((void (*)()) 0x806BF89)
#define Sub_801D684_EnemyMain ((void (*)()) 0x801D685)
#define Sub_8074808_WarioHeartMake ((void (*)()) 0x8074809)

// My variables (perhaps unused in original)
#define crystal_Tflg (*(volatile unsigned char*) 0x3006F0E)
#define dashAttackFlag (*(volatile unsigned char*) 0x3006F0F)
#define airAttackNum (*(volatile unsigned char*) 0x3006F10)
#define airAttackStat (*(volatile unsigned char*) 0x3006F11)
#define airJumpNum (*(volatile unsigned char*) 0x3006F12)
#define aFlipFlag (*(volatile unsigned char*) 0x3006F13)
#define hFlipFlag (*(volatile unsigned char*) 0x3006F14)

int MC_Sub_8010A9C_WarKeyJump() {
    // Vanilla code
		unsigned char v0;
	  unsigned int v2;
	  short v3;
	  short v4;
	  int v5;

		// Custom Code
		if ( (usTrg_KeyPress1Frame[0] & 1 || Wario_ucJpNext) && airJumpNum > 0 ) // Press A
	  {
			--airJumpNum;
			crystal_Tflg = 1;
			Wario_ucJpFlg = 1;
			Sub_80766E8_TOptObjSet(Wario_usPosY + 28, Wario_usPosX - 28, KN_TUCHIKEMURI_L);
			Sub_80766E8_TOptObjSet(Wario_usPosY + 28, Wario_usPosX + 28, KN_TUCHIKEMURI_R);
			return 254;
		}
		if ( usTrg_KeyPress1Frame[0] & 2 && !WarioLift_LOBYTE && airAttackNum > 0 && !Sub_8014090_WarHeadCheck(0, 0xFF84, 1) ) // Press B
	  {
			--airAttackNum;
			crystal_Tflg = 1;
			airAttackStat = 1;
		  return ATTACK;
	  }
		airAttackStat = 0;

	  if ( WarioLift_LOBYTE )
	  {
	    v0 = KeyPressContinuous[0] & 0x40 ? WarioLift_BYTE1 | 0x80 : WarioLift_BYTE1 & 0xF;
	    WarioLift_BYTE1 = v0;
	    if ( usTrg_KeyPress1Frame[0] & 2 )
	      return JTHROW;
	  }
	  if ( usTrg_KeyPress1Frame[0] & 0x80 ) // Press Down
	    return HIP;
	  if ( usTrg_KeyPress1Frame[0] & 1 ) // Press A
	    Wario_ucJpNext = 1;
	  if ( (KeyPressContinuous[0] & 0x42) == 64 ) // Hold Up
	  {
	    v2 = Sub_806DAC0_PanelYakuAllNum_TileEventId((Wario_usPosY - 119) & 0xFFFF, Wario_usPosX) >> 16;
	    if ( !WarioLift_LOBYTE && Wario_sMvSpeedY <= 0 )
	    {
	      if ( (v2 - 2) <= 1 )
	        return LDSTOP;
	      if ( v2 == 4 )
	        return NETSTOP;
	    }
	  }
	  if ( KeyPressContinuous[0] & Wario_usMukiX ) // Hold Left or Right
	  {
	    if ( Wario_usMukiX & 0x10 )
	    {
	      v3 = Wario_sMvSpeedX;
	      if ( Wario_sMvSpeedX <= 63 )
	      {
	        Wario_sMvSpeedX += 6;
	        if ( (v3 + 6) > 64 )
	          Wario_sMvSpeedX = 64;
	      }
	    }
	    else
	    {
	      v4 = Wario_sMvSpeedX;
	      if ( Wario_sMvSpeedX > -64 )
	      {
	        Wario_sMvSpeedX -= 6;
	        if ( (v4 - 6) < -64 )
	          Wario_sMvSpeedX = -64;
	      }
	    }
	    goto LABEL_34;
	  }
	  if ( !((Wario_usMukiX ^ 0x30) & KeyPressContinuous[0]) )
	  {
	    if ( Wario_sMvSpeedX <= 0 )
	    {
	      if ( Wario_sMvSpeedX >= 0 )
	        goto LABEL_34;
	      v5 = Wario_sMvSpeedX + 10;
	      Wario_sMvSpeedX += 10;
	      if ( v5 << 16 <= 0 )
	        goto LABEL_34;
	    }
	    else
	    {
	      Wario_sMvSpeedX -= 10;
	      if ( !(Wario_sMvSpeedX & 0x8000) )
	        goto LABEL_34;
	    }
	    Wario_sMvSpeedX = 0;
	    goto LABEL_34;
	  }
	  Wario_usMukiX ^= 0x30;
	  Wario_sMvSpeedX = 0;
	LABEL_34:
	  if ( !(KeyPressContinuous[0] & 1) && Wario_sMvSpeedY > 0 )
	    Wario_sMvSpeedY = 0;
	  return 255;
	}
