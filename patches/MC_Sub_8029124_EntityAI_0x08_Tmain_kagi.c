// @Description MC_Sub_8029124_EntityAI_0x08_Tmain_kagi
// @HookAddress 0x78E820
// @HookString P
// @EntryFunctionSymbol MC_Sub_8029124_EntityAI_0x08_Tmain_kagi
// Made by beco
// Verison 1.0

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

#define unk_83B492C 0x83B492C

#define CurrentRoomId (*(volatile unsigned char*) 0x3000024)
#define EntityLeftOverStateList ((volatile unsigned char*) 0x3000564)
#define CurrentEnemyData (*(volatile struct EnemyDataStructure*) 0x3000A24)
#define ucThit2 (*(volatile unsigned char*) 0x3000A51)
#define ucHasKeyzer (*(volatile signed char*) 0x3000C0C)
#define Wario_ucReact (*(volatile unsigned char*) 0x3001898)
#define Wario_ucStat (*(volatile unsigned char*) 0x3001899)

#define word_83B4A4C ((volatile signed short*) 0x83B4A4C)

#define Sub_8001DA4_m4aSongNumStart ((void (*)(int)) 0x8001DA5)
#define Sub_8023BFC_T_NoCorrectionBgAttack ((void (*)(unsigned short, unsigned short)) 0x8023BFD)
#define Sub_80766E8_TOptObjSet ((int (*)(int,int,char)) 0x80766E9)
#define Sub_8088620_WarioVoiceSet ((void (*)(int)) 0x8088621)
#define Sub_8026308_WarioOrientedStart ((void (*)()) 0x8026309)

void MC_Sub_8029124_EntityAI_0x08_Tmain_kagi() {
  char v0; // r2
  int v1; // r3
  int v2; // r0

  if ( CurrentEnemyData.CurEnemy_CurrentAnimationId )
  {
    if ( CurrentEnemyData.CurEnemy_CurrentAnimationId == Q_K5_HIP )
      Q_K5_HIP_kagi();
    v0 = CurrentEnemyData.CurEnemy_TWork3;
    v1 = word_83B4A4C[CurrentEnemyData.CurEnemy_TWork3];
    if ( v1 == 0x7FFF )
    {
      v1 = 0;
      v0 = 0;
    }
    CurrentEnemyData.CurEnemy_TWork3 = v0 + 1;
    CurrentEnemyData.CurEnemy_YPos += v1;
  }
  else
  {
    Q_INITIAL_kagi();
  }
  if ( CurrentEnemyData.CurEnemy_usStatus )
  {
    Sub_8023BFC_T_NoCorrectionBgAttack(CurrentEnemyData.CurEnemy_YPos, CurrentEnemyData.CurEnemy_XPos);
    if ( ucThit2 & 0xF )
      v2 = CurrentEnemyData.CurEnemy_usStatus | 4;
    else
      v2 = CurrentEnemyData.CurEnemy_usStatus & 0xFFFB;
    CurrentEnemyData.CurEnemy_usStatus = v2;
  }
}

void Q_INITIAL_kagi() {
  CurrentEnemyData.CurEnemy_usStatus |= 0x408u;
  CurrentEnemyData.CurEnemy_GuardAndDamageParam = L_COIN;
  CurrentEnemyData.CurEnemy_SizeY0_Bottom = 16;
  CurrentEnemyData.CurEnemy_SizeY1_Top = 16;
  CurrentEnemyData.CurEnemy_SizeX_LeftRight = 24;
  CurrentEnemyData.CurEnemy_HitboxY0 = 32;
  CurrentEnemyData.CurEnemy_HitboxY1 = 20;
  CurrentEnemyData.CurEnemy_HitboxX0 = 32;
  CurrentEnemyData.CurEnemy_HitboxX1 = 28;
  CurrentEnemyData.OAMDataPackPointerForCurrentAnimation = unk_83B492C;
  CurrentEnemyData.CurEnemy_RealFrameCountForCurrentAnimationFrame = 0;
  CurrentEnemyData.CurEnemy_CurrentAnimationFrameId = 0;
  CurrentEnemyData.CurEnemy_CurrentAnimationId = 16;
  CurrentEnemyData.CurEnemy_TWork3 = 0;
  CurrentEnemyData.CurEnemy_YPos -= 64;
  CurrentEnemyData.CurEnemy_XPos -= 32;
}

void Q_K5_HIP_kagi() {
  CurrentEnemyData.CurEnemy_usStatus = 0;
  EntityLeftOverStateList[64 * CurrentRoomId + CurrentEnemyData.CurEnemy_RoomEntitySlotId] = 2;
  ucHasKeyzer = 1;
  if ( Wario_ucReact == 1 )
    Sub_8001DA4_m4aSongNumStart(330);
  else
    Sub_8001DA4_m4aSongNumStart(309);
  Sub_80766E8_TOptObjSet(CurrentEnemyData.CurEnemy_YPos, CurrentEnemyData.CurEnemy_XPos, 75);
  Sub_8088620_WarioVoiceSet(2);
}
