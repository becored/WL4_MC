// @Description MC_Sub_8012BAC_GmWarioChng
// @HookAddress 0x12BAE
// @HookString 024b 9e46024b 18470000 c12c0108 P
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

struct CapDef {
	char ucStat;				//状態
	char ucAnmTimer;		//アニメタイマー
	char ucAnmPat;			//アニメパターン
	short *pObjData;   	//OBJデータアドレス
};

struct WEffDef {
	char ucKind;				//0:なし 1:泡 2:バネ効果 3:ダッシュ効果 4:こうもり煙 5:汗
	char ucStat;				//状態
	char ucAnmTimer;		//アニメタイマー
	char ucAnmPat;			//アニメパターン
	short *pObjData;		//OBJデータアドレス
};

#define Sub_8001DA4_m4aSongNumStart ((void (*)(int)) 0x8001DA5)
#define Sub_800FD28_WarParClear ((void (*)()) 0x800FD29)
#define Sub_8012CC8_WarChng_Flying ((void (*)()) 0x8012CC9)
#define Sub_8012E5C_WarChng_Landing ((void (*)()) 0x8012E5D)
#define Sub_801318C_WarChng_Other ((void (*)(unsigned char)) 0x801318D)
#define Sub_8094ED0__modsi3 ((int (*)(int,int)) 0x8094ED1)
#define Sub_80950D8_memcpy ((void (*)(int,int,int)) 0x80950D9)
#define Sub_8014090_WarHeadCheck ((int (*)(unsigned short,unsigned int,int)) 0x8014091)

#define sGameSeq (*(volatile unsigned short*) 0x3000C3C)
#define KeyPressContinuous ((volatile unsigned short*) 0x3001844)
#define usTrg_KeyPress1Frame ((volatile unsigned short*) 0x3001848)
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
#define WarBk_ucReact (*(volatile unsigned char*) 0x30018D4)
#define WarBk_ucStat (*(volatile unsigned char*) 0x30018D5)
#define WarBk_ucJpFlg (*(volatile unsigned char*) 0x30018DC)
#define WarBk_usSlope (*(volatile signed short*) 0x30018F0)
#define WarCap (*(volatile struct CapDef*) 0x3001930)
#define WarEff (*(volatile struct WEffDef*) 0x3001940)
#define unk_3001934 (*(volatile unsigned char*) 0x3001934)

void MC_Sub_8012BAC_GmWarioChng(unsigned char a1) {
  unsigned char v1; // r4
  v1 = a1;
  Sub_800FD28_WarParClear();
  WarCap.ucStat = 0;
  WarCap.ucAnmTimer = 0;
  WarCap.ucAnmPat = 0;
  WarCap.pObjData = 0;
  if ( WarEff.ucKind != 4 )
  {
    WarEff.ucKind = 0;
    WarEff.ucStat = 0;
    WarEff.ucAnmTimer = 0;
    WarEff.ucAnmPat = 0;
    WarEff.pObjData = 0;
  }
	if ( Wario_ucDokan ) {
    Wario_ucDokan = 2;
		if ( Wario_ucStat == DOKANU )
		{
			Wario_sMvSpeedY = 64;
		}
		else if ( Wario_ucStat == DOKAND )
		{
			Wario_sMvSpeedY = -64;
		}
	}
  else if ( sGameSeq == 4 )                     // game is paused
  {
    sGameSeq = 2;
    Wario_ucAnmPat = 2;
  }
  else                                          // game is not paused
  {
    Wario_ucDokan = 0;
    if ( v1 == 5 && WarBk_usSlope & 1 )
      v1 = 0xC;
    if ( v1 == 0x1F )
    {
      if ( Sub_8014090_WarHeadCheck(0, 0xFFC0, 1) )
      {
        Sub_80950D8_memcpy(&Wario_ucReact, &WarBk_ucReact, 0x3C);
        return;
      }
      if ( KeyPressContinuous[0] & 1 )
      {
        WarBk_ucJpFlg = 1;
        v1 = 0xFE;
      }
    }
    if ( WarBk_ucStat == TAME )
    {
      if ( v1 != THROW2 && v1 != TAMETURN )
        Sub_8001DA4_m4aSongNumStart(40);        // B dash jump sfx
    }
    else if ( WarBk_ucStat == TAMETURN && v1 != 0x25 && v1 != 0x23 )
    {
      Sub_8001DA4_m4aSongNumStart(40);          // B dash jump sfx
    }
    if ( v1 == 0xFE )
    {
      Sub_8012CC8_WarChng_Flying();             // full jump when holding A
    }
    else if ( v1 == 0xFD )
    {
      Sub_8012E5C_WarChng_Landing();
    }
    else
    {
      Sub_801318C_WarChng_Other(v1);            // bouncing
    }
  }
}
