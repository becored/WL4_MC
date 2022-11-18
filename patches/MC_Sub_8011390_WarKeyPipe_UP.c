// @Description MC_Sub_8011390_WarKeyPipe_UP
// @HookAddress 0x2DEE04
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
	TAMETURN,				//溜め反転
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
	YF_NASHI,		//00:無し					//---BG[1][2]---
	YF_TOBIRA,		//01:扉
	YF_HASHIGO_M,	//02:はしご
	YF_HASHIGO_U,	//03:はしご上
	YF_AMI,			//04:アミ
	YF_BELT_L,		//05:ベルトコンベア←左		//---BG[1]---
	YF_BELT_R,		//06:ベルトコンベア→右
	YF_TUBE_UL,		//07:土管↑（左）
	YF_TUBE_UR,		//08:土管↑（右）
	YF_TUBE_DL,		//09:土管↓（左）
	YF_TUBE_DR,		//0A:土管↓（右）
	YF_SLIP,		//0B:滑る（パネルの上表面が滑る）
	YF_MIZU_SR,		//0C:水流れ→				//---BG[0]から取得 → Fieldで返す---
	YF_MIZU_SL,		//0D:水流れ←
	YF_MIZU_SU,		//0E:水流れ↑
	YF_MIZU_SD,		//0F:水流れ↓
	YF_MIZU_FR,		//10:水流れ→（速い）
	YF_MIZU_FL,		//11:水流れ←（速い）
	YF_MIZU_FU,		//12:水流れ↑（速い）
	YF_MIZU_FD,		//13:水流れ↓（速い）
};

struct WJEffDef {
	unsigned char ucStat;
	unsigned char ucAnmTimer;			//アニメタイマー
	unsigned char ucAnmPat;			//アニメパターン
	unsigned short usPosX;				//Ｘ
	unsigned short usPosY;				//Ｙ
	unsigned long iAnmAddr;			//アドレス
} ;

#define Sub_8001DA4_m4aSongNumStart ((int (*)(int)) 0x8001DA5)
#define Sub_806DAC0_PanelYakuAllNum_TileEventId ((int (*)(unsigned short,unsigned short)) 0x806DAC1)

#define PassageID (*(volatile unsigned char*) 0x3000002)
#define InPassageLevelID (*(volatile unsigned char*) 0x3000003)
#define ucDisConFlg (*(volatile unsigned char*) 0x3000012)
#define CurrentRoomId (*(volatile unsigned char*) 0x3000024)
#define ucGateNum (*(volatile unsigned char*) 0x3000025)
#define ucTimeUp (*(volatile unsigned char*) 0x3000047)
#define sGameSeq (*(volatile unsigned short*) 0x3000C3C)
#define cGmStartFlg (*(volatile unsigned char*) 0x3000C3F)
#define KeyPressContinuous ((volatile unsigned short*) 0x3001844)
#define usTrg_KeyPress1Frame ((volatile unsigned short*) 0x3001848)
#define usBgEvy (*(volatile unsigned char*) 0x3001870)
#define Wario_ucReact (*(volatile unsigned char*) 0x3001898)
#define Wario_ucStat (*(volatile unsigned char*) 0x3001899)
#define Wario_ucDokan (*(volatile unsigned char*) 0x300189A)
#define Wario_ucJpNext (*(volatile unsigned char*) 0x300189F)
#define Wario_ucJpFlg (*(volatile unsigned char*) 0x30018A0)
#define Wario_usTimer (*(volatile unsigned short*) 0x30018A4)
#define Wario_usMukiX (*(volatile unsigned short*) 0x30018A6)
#define Wario_usMukiY (*(volatile unsigned short*) 0x30018A8)
#define Wario_usPosX (*(volatile unsigned short*) 0x30018AA)
#define Wario_usPosY (*(volatile unsigned short*) 0x30018AC)
#define Wario_ucAnmTimer (*(volatile unsigned char*) 0x30018B6)
#define Wario_ucAnmPat (*(volatile unsigned char*) 0x30018B7)
#define Wario_sMvSpeedX (*(volatile signed short*) 0x30018AE)
#define Wario_sMvSpeedY (*(volatile signed short*) 0x30018B0)
#define WarJEff ((volatile struct WJEffDef*) 0x3001950)
#define WarJEff_LOBYTE (*(volatile unsigned char*) 0x3001950)
#define WarioLift (*(volatile unsigned char*) 0x3001948)
#define usWarStopFlg (*(volatile unsigned char*) 0x30019F6)
#define ucWarOffFlg (*(volatile unsigned char*) 0x30019F8)

#define byte_8316078 ((volatile unsigned char*) 0x8316078)

#define Wario_ucDokan_Warp (*(volatile unsigned char*) 0x30018A3)

int MC_Sub_8011390_WarKeyPipe_UP() {
		int tile16_eventID;
		tile16_eventID = Sub_806DAC0_PanelYakuAllNum_TileEventId((Wario_usPosY + 54) & 0xFFFF, Wario_usPosX) >> 16;
		switch ( tile16_eventID )	{
			case YF_TUBE_UL: // 0x04
			case YF_TUBE_UR: // 0x05
			case YF_AMI: // 0x7B
				Wario_ucDokan = 0;
				return STOP;
			default:
				break;
		}
		/*
		if ( Wario_ucAnmTimer < byte_8316078[12 * Wario_ucAnmPat + 8] )
	    return 255;
		*/
	  Wario_ucAnmTimer = 0;
	  if ( byte_8316078[12 * ++Wario_ucAnmPat + 8] )
	    return 255;
		return 254;
}
