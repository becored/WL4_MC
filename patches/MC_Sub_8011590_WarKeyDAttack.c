// @Description MC_Sub_8011590_WarKeyDAttack
// @HookAddress 0x2DEE1C
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

struct WJEffDef{
	unsigned char ucStat;
	unsigned char ucAnmTimer;			//アニメタイマー
	unsigned char ucAnmPat;			//アニメパターン
	unsigned short usPosX;				//Ｘ
	unsigned short usPosY;				//Ｙ
	unsigned long iAnmAddr;			//アドレス
} ;

#define Sub_8001DA4_m4aSongNumStart ((int (*)(int)) 0x8001DA5)
#define Sub_806DAC0_PanelYakuAllNum_TileEventId ((int (*)(unsigned short,unsigned short)) 0x806DAC1)
#define Sub_8088620_WarioVoiceSet ((int (*)(int)) 0x8088621)

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
#define WarJEff_LOBYTE (*(volatile unsigned char*) 0x3001950)
#define WarioLift (*(volatile unsigned char*) 0x3001948)
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

#define byte_82FC2C4 ((volatile unsigned char*) 0x82FC2C4)

#define Sub_8075F44_TmScInit ((void (*)()) 0x8075F45)
#define Sub_801DE7C_EnemyInit ((void (*)()) 0x801DE7D)
#define Sub_80711E8_GameInit_ColorSetWork_All ((void (*)()) 0x80711E9)
#define Sub_806BF88_BgmChangeInit ((void (*)()) 0x806BF89)
#define Sub_801D684_EnemyMain ((void (*)()) 0x801D685)
#define Sub_8074808_WarioHeartMake ((void (*)()) 0

// My variables (perhaps unused in original)
#define crystal_Tflg (*(volatile unsigned char*) 0x3006F0E)
#define dashAttackFlag (*(volatile unsigned char*) 0x3006F0F)
#define airAttackNum (*(volatile unsigned char*) 0x3006F10)
#define airAttackStat (*(volatile unsigned char*) 0x3006F11)
#define airJumpNum (*(volatile unsigned char*) 0x3006F12)
#define aFlipFlag (*(volatile unsigned char*) 0x3006F13)
#define hFlipFlag (*(volatile unsigned char*) 0x3006F14)

int MC_Sub_8011590_WarKeyDAttack() {
    // Vanilla code
		signed int result;
	  short v1;
	  short v2;

		if ( usTrg_KeyPress1Frame[0] & 1 ) // Press A
	  {
	    Wario_ucJpFlg = 1;
	    result = 254;
	  }
	  else if ( KeyPressContinuous[0] & Wario_usMukiX )
	  {
	    if ( KeyPressContinuous[0] & 0x300 ) // Hold L or R
	    {
	      if ( Wario_ucAnmTimer >= byte_82FC2C4[12 * Wario_ucAnmTimer_HIBYTE + 8] )
	      {
					Wario_ucAnmTimer_LOBYTE = 0;
					++Wario_ucAnmTimer_HIBYTE;
	        if ( byte_82FC2C4[12 * Wario_ucAnmTimer_HIBYTE + 8] )
	        {
	          if ( Wario_ucAnmTimer_HIBYTE == 1 )
	            WarJEff_LOBYTE = 5;
	        }
	        else
	        {
	          Wario_ucAnmTimer_HIBYTE = 0;
	        }
	      }
	      result = 255;
	    }
	    else
	    {
	      if ( Wario_usMukiX & 0x10 )
	        v2 = Wario_sMvSpeedX - 6;
	      else
	        v2 = Wario_sMvSpeedX + 6;
	      Wario_sMvSpeedX = v2;
	      result = WALK;
	    }
	  }
	  else
	  {
	    if ( Wario_usMukiX & 0x10 )
	      v1 = Wario_sMvSpeedX - 3;
	    else
	      v1 = Wario_sMvSpeedX + 3;
	    Wario_sMvSpeedX = v1;
	    result = DSBRK;
	  }
		// Custom Code
		/*
		if ( usTrg_KeyPress1Frame[0] & 0x80 ) // Press Down to roll
		{
    	if ( Wario_usMukiX & 0x10 )
				Wario_sMvSpeedX += 40; // Speed up (only apply in the air)
			else {
				Wario_sMvSpeedX -= 40; // Speed up (only apply in the air)
			}
			Sub_8001DA4_m4aSongNumStart(87);
			Sub_8088620_WarioVoiceSet(0);
			result = ROLLB;
		}
		*/
	  return result;
	}
