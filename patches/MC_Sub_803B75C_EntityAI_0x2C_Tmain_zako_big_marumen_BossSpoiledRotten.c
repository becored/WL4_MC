// @Description MC_Sub_803B75C_EntityAI_0x2C_Tmain_zako_big_marumen_BossSpoiledRotten
// @HookAddress 0x78E8B0
// @HookString P
// @EntryFunctionSymbol Sub_803B75C_EntityAI_0x2C_Tmain_zako_big_marumen_BossSpoiledRotten
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

#define zako_big_marumen_Anm_00 0x83C2C14
#define zako_big_marumen_Anm_02 0x83C2C84
#define zako_big_marumen_Anm_04 0x83C2CBC
#define zako_big_marumen_Anm_05 0x83C2CEC
#define zako_big_marumen_Anm_07 0x83C2D5C
#define zako_big_marumen_Anm_09 0x83C2D94
#define zako_big_marumen_Anm_10 0x83C2DC4
#define zako_big_marumen_Anm_12 0x83C2E34
#define zako_big_marumen_Anm_14 0x83C2E6C
#define zako_big_marumen_Anm_15 0x83C2E9C
#define zako_big_marumen_Anm_17 0x83C2F0C
#define zako_big_marumen_Anm_19 0x83C2F44
#define zako_big_marumen_Anm_20 0x83C2F74
#define zako_big_marumen_Anm_22 0x83C2FE4
#define zako_big_marumen_Anm_25 0x83C302C
#define zako_big_marumen_Anm_26 0x83C303C
#define zako_big_marumen_Anm_27 0x83C304C
#define zako_big_marumen_Anm_28 0x83C305C
#define zako_big_marumen_Anm_29 0x83C306C
#define zako_big_marumen_Anm_30 0x83C307C
#define zako_big_marumen_Anm_31 0x83C3094
#define zako_big_marumen_Anm_32 0x83C30AC
#define zako_big_marumen_Anm_33 0x83C30C4
#define zako_big_marumen_Anm_34 0x83C30DC

#define CurrentRoomId (*(volatile unsigned char*) 0x3000024)
#define ucTimeUp (*(volatile unsigned char*) 0x3000047)
#define EntityLeftOverStateList ((volatile unsigned char*) 0x3000564)
#define CurrentEnemyData (*(volatile struct EnemyDataStructure*) 0x3000A24)
#define ucThit1 (*(volatile unsigned char*) 0x3000A50)
#define ucThit2 (*(volatile unsigned char*) 0x3000A51)
#define HasKeyzer (*(volatile signed short*) 0x3000C0C)
#define Wario_ucReact (*(volatile unsigned char*) 0x3001898)
#define Wario_ucStat (*(volatile unsigned char*) 0x3001899)
#define Wario_usPosX (*(volatile unsigned short*) 0x30018AA)
#define usWarStopFlg (*(volatile unsigned char*) 0x30019F6)

#define Sub_8001DA4_m4aSongNumStart ((void (*)(int)) 0x8001DA5)
#define Sub_8023BFC_T_NoCorrectionBgAttack ((void (*)(unsigned short, unsigned short)) 0x8023BFD)
#define Sub_80766E8_TOptObjSet ((int (*)(int,int,char)) 0x80766E9)
#define Sub_8088620_WarioVoiceSet ((void (*)(int)) 0x8088621)

#define Sub_8023B88_T_DivaBellyAttactCheck ((void (*)()) 0x8023B89)
#define Sub_806ACA0_BgShakingInit ((void (*)(unsigned char, char)) 0x806ACA1)
#define Sub_801E328_EnemyChildSet ((void (*)(char, char, char, int, int)) 0x801E329)

#define Sub_803AB4C_Q_INITIAL_zako_big_marumen ((void (*)()) 0x803AB4D)
#define Sub_803ABD8_Q_INITIAL2_zako_big_marumen ((void (*)()) 0x803ABD9)
#define Sub_803AC38_Q_INITIAL3_zako_big_marumen ((void (*)()) 0x803AC39)
#define Sub_803AD2C_Q_K0_WALK_zako_big_marumen ((void (*)()) 0x803AD2D)
#define Sub_803AE30_K0_WALK_zako_big_marumen ((void (*)()) 0x803AE31)
#define Sub_803AF50_Q_K0_TURN1_zako_big_marumen ((void (*)()) 0x803AF51)
#define Sub_803AFE4_K0_TURN12_zako_big_marumen ((void (*)()) 0x803AFE5)
#define Sub_803B0A0_Q_JITTO_zako_big_marumen ((void (*)()) 0x803B0A1)
#define Sub_803B13C_JITTO_zako_big_marumen ((void (*)()) 0x803B13D)
#define Sub_803B49C_Q_K2_COM_zako_big_marumen ((void (*)()) 0x803B49D)
#define Sub_803B538_K2_COM_zako_big_marumen ((void (*)()) 0x803B539)
#define Sub_803B6C8_Q_K1_COM_zako_big_marumen ((void (*)()) 0x803B6C9)
#define Sub_803B1F8_K5_HIP_zako_big_marumen ((void (*)()) 0x803B1F9)
#define Sub_803B2A0_K5_HIP2_zako_big_marumen ((void (*)()) 0x803B2A1)
#define Sub_803B2EC_Q_T_AUX_3_zako_big_marumen ((void (*)()) 0x803B2ED)
#define Sub_803B36C_T_AUX_3_zako_big_marumen ((void (*)()) 0x803B36D)
#define Sub_803B3E0_Q_T_AUX_4_zako_big_marumen ((void (*)()) 0x803B3E1)
#define Sub_803B454_T_AUX_4_zako_big_marumen ((void (*)()) 0x803B455)
#define Sub_803B608_Q_T_AUX_5_zako_big_marumen ((void (*)()) 0x803B609)
#define Sub_803B680_T_AUX_5_zako_big_marumen ((void (*)()) 0x803B681)
#define Sub_803B164_Q_K5_HIP_zako_big_marumen ((void (*)()) 0x803B165)

const unsigned short T_AUX_5_jump_YPos[] =
{
 	0x0640,	0x0630, 0x0620, 0x0610, 0x0600, 0x05F8, 0x05F0, 0x05EC,
  0x05E8, 0x05E4, 0x05E0, 0x05E0, 0x05E0, 0x05E0, 0x05E0, 0x05E0,
  0x05E0, 0x05E0, 0x05E4, 0x05E8, 0x05EC, 0x05F0, 0x05F8, 0x0600,
  0x0610, 0x0620, 0x0630, 0x0640, 0xFFFF
};

const unsigned short T_AUX_5_child_XPos[] =
{
 	0x03D0,	0x05F0
};

void Sub_803B75C_EntityAI_0x2C_Tmain_zako_big_marumen_BossSpoiledRotten() {
  switch ( CurrentEnemyData.CurEnemy_CurrentAnimationId )
  {
    case Q_INITIAL:
      Sub_803AB4C_Q_INITIAL_zako_big_marumen();
      return;
    case Q_INITIAL2:
      Sub_803ABD8_Q_INITIAL2_zako_big_marumen();
      return;
    case Q_INITIAL3:
      Q_INITIAL3_zako_big_marumen();
      return;
    case Q_K0_WALK:
      Q_K0_WALK_zako_big_marumen();
    case K0_WALK:
      K0_WALK_zako_big_marumen();
      return;
    case Q_K0_TURN1:
      Q_K0_TURN1_zako_big_marumen();
    case K0_TURN1:
    case K0_TURN2:
      Sub_803AFE4_K0_TURN12_zako_big_marumen();
      return;
    case Q_JITTO:
      Q_JITTO_zako_big_marumen();
    case JITTO:
      Sub_803B13C_JITTO_zako_big_marumen();
      return;
    case Q_K2_LEFT:
    case Q_K2_RIGHT:
    case Q_K2D_LEFT:
    case Q_K2D_RIGHT:
      Sub_803B49C_Q_K2_COM_zako_big_marumen();
    case K2_LEFT:
      K2_COM_zako_big_marumen();
      return;
    case Q_K1_LEFT:
    case Q_K1_RIGHT:
    case Q_K4_LEFT:
    case Q_K4_RIGHT:
      Q_K1_COM_zako_big_marumen();
      return;
    case K5_HIP:
      Sub_803B1F8_K5_HIP_zako_big_marumen();
      return;
    case K5_HIP2:
      Sub_803B2A0_K5_HIP2_zako_big_marumen();
      return;
    case Q_T_AUX_3:
      Sub_803B2EC_Q_T_AUX_3_zako_big_marumen();
      return;
    case T_AUX_3:
      Sub_803B36C_T_AUX_3_zako_big_marumen();
      return;
    case Q_T_AUX_4:
      Sub_803B3E0_Q_T_AUX_4_zako_big_marumen();
    case T_AUX_4:
      Sub_803B454_T_AUX_4_zako_big_marumen();
      return;
    case Q_T_AUX_5:
      Q_T_AUX_5_zako_big_marumen();
    case T_AUX_5:
      T_AUX_5_zako_big_marumen();
      return;
    case Q_TOBIOKI:
      Q_TOBIOKI_zako_big_marumen();
      return;
    default:
      Sub_803B164_Q_K5_HIP_zako_big_marumen();
      return;
  }
}

void Q_INITIAL3_zako_big_marumen() {
  CurrentEnemyData.CurEnemy_TWork1 = 0;
  CurrentEnemyData.CurEnemy_TWork2 = 0;
  CurrentEnemyData.CurEnemy_RealFrameCountForCurrentAnimationFrame = 0;
  if ( !usWarStopFlg && ucTimeUp == 1 )
  {
    CurrentEnemyData.CurEnemy_Prio &= 0x7F;
    CurrentEnemyData.CurEnemy_CurrentAnimationId = Q_K0_WALK;
    /*
    Sub_801E328_EnemyChildSet(11, 0, 0, CurrentEnemyData.CurEnemy_YPos - 272, CurrentEnemyData.CurEnemy_XPos + 144);
    Sub_801E328_EnemyChildSet(11, 0, 0, CurrentEnemyData.CurEnemy_YPos - 256, CurrentEnemyData.CurEnemy_XPos + 128);
    Sub_801E328_EnemyChildSet(11, 0, 0, CurrentEnemyData.CurEnemy_YPos - 288, CurrentEnemyData.CurEnemy_XPos + 112);
    Sub_801E328_EnemyChildSet(169, 0, 0, CurrentEnemyData.CurEnemy_YPos - 256, CurrentEnemyData.CurEnemy_XPos + 128);
    Sub_801E328_EnemyChildSet(11, 0, 0, CurrentEnemyData.CurEnemy_YPos - 272, CurrentEnemyData.CurEnemy_XPos - 144);
    Sub_801E328_EnemyChildSet(11, 0, 0, CurrentEnemyData.CurEnemy_YPos - 256, CurrentEnemyData.CurEnemy_XPos - 128);
    Sub_801E328_EnemyChildSet(11, 0, 0, CurrentEnemyData.CurEnemy_YPos - 288, CurrentEnemyData.CurEnemy_XPos - 112);
    Sub_801E328_EnemyChildSet(169, 0, 0, CurrentEnemyData.CurEnemy_YPos - 256, CurrentEnemyData.CurEnemy_XPos - 128);
    Sub_8001DA4_m4aSongNumStart(157);
    */
  }
}

void Q_K0_TURN1_zako_big_marumen() {
  CurrentEnemyData.CurEnemy_GuardAndDamageParam = BIG_MARUMEN_H;
  CurrentEnemyData.CurEnemy_RealFrameCountForCurrentAnimationFrame = 0;
  CurrentEnemyData.CurEnemy_CurrentAnimationFrameId = 0;
  CurrentEnemyData.CurEnemy_CurrentAnimationId = K0_TURN1;
  CurrentEnemyData.CurEnemy_TWork0 = 13;
  switch ( CurrentEnemyData.CurEnemy_Life )
  {
    case 0:
    case 1:
    case 2:
    case 3:
      CurrentEnemyData.CurEnemy_GuardAndDamageParam = BIG_MARUMEN_H3;
      CurrentEnemyData.OAMDataPackPointerForCurrentAnimation = zako_big_marumen_Anm_22;
      break;
    case 4:
    case 5:
      CurrentEnemyData.OAMDataPackPointerForCurrentAnimation = zako_big_marumen_Anm_17;
      break;
    case 6:
    case 7:
      CurrentEnemyData.OAMDataPackPointerForCurrentAnimation = zako_big_marumen_Anm_12;
      break;
    case 8:
    case 9:
      CurrentEnemyData.OAMDataPackPointerForCurrentAnimation = zako_big_marumen_Anm_07;
      break;
    default:
      CurrentEnemyData.OAMDataPackPointerForCurrentAnimation = zako_big_marumen_Anm_02;
      break;
  }
}

void Q_K0_WALK_zako_big_marumen() {
  CurrentEnemyData.CurEnemy_RealFrameCountForCurrentAnimationFrame = 0;
  CurrentEnemyData.CurEnemy_CurrentAnimationFrameId = 0;
  CurrentEnemyData.CurEnemy_CurrentAnimationId = K0_WALK;
  switch ( CurrentEnemyData.CurEnemy_Life )
  {
    case 0:
    case 1:
    case 2:
    case 3:
      CurrentEnemyData.CurEnemy_GuardAndDamageParam = BIG_MARUMEN_H3;
      CurrentEnemyData.OAMDataPackPointerForCurrentAnimation = zako_big_marumen_Anm_20;
      break;
    case 4:
    case 5:
      CurrentEnemyData.OAMDataPackPointerForCurrentAnimation = zako_big_marumen_Anm_15;
      break;
    case 6:
    case 7:
      CurrentEnemyData.OAMDataPackPointerForCurrentAnimation = zako_big_marumen_Anm_10;
      break;
    case 8:
    case 9:
      CurrentEnemyData.OAMDataPackPointerForCurrentAnimation = zako_big_marumen_Anm_05;
      break;
    default:
      CurrentEnemyData.OAMDataPackPointerForCurrentAnimation = zako_big_marumen_Anm_00;
      break;
  }
}

void K0_WALK_zako_big_marumen() {
  int v0; // r0

  Sub_8023B88_T_DivaBellyAttactCheck();
  if ( !(CurrentEnemyData.CurEnemy_usStatus & 0x40) )
  {
    if ( !(ucThit1 & 0xF0)
      || (Sub_8023BFC_T_NoCorrectionBgAttack(
            CurrentEnemyData.CurEnemy_YPos,
            CurrentEnemyData.CurEnemy_XPos - CurrentEnemyData.CurEnemy_HitboxX0),
          ucThit2 & 0xF0)
      && (Sub_8023BFC_T_NoCorrectionBgAttack(
            CurrentEnemyData.CurEnemy_YPos - 32,
            CurrentEnemyData.CurEnemy_XPos - CurrentEnemyData.CurEnemy_HitboxX0 - 160),
          !(ucThit2 & 0xF)) )
    {
      if ( CurrentEnemyData.CurEnemy_GuardAndDamageParam == BIG_MARUMEN_H3 )
        v0 = CurrentEnemyData.CurEnemy_XPos - 8;
      else
        v0 = CurrentEnemyData.CurEnemy_XPos - 4;
      goto LABEL_15;
    }
LABEL_11:
    CurrentEnemyData.CurEnemy_CurrentAnimationId = Q_K0_TURN1;
    return;
  }
  if ( ucThit1 & 0xF0 )
  {
    Sub_8023BFC_T_NoCorrectionBgAttack(
      CurrentEnemyData.CurEnemy_YPos,
      CurrentEnemyData.CurEnemy_XPos + CurrentEnemyData.CurEnemy_HitboxX1);
    if ( !(ucThit2 & 0xF0) )
      goto LABEL_11;
    Sub_8023BFC_T_NoCorrectionBgAttack(
      CurrentEnemyData.CurEnemy_YPos - 32,
      CurrentEnemyData.CurEnemy_XPos + CurrentEnemyData.CurEnemy_HitboxX1 + 160);
    if ( ucThit2 & 0xF )
      goto LABEL_11;
  }
  if ( CurrentEnemyData.CurEnemy_GuardAndDamageParam == BIG_MARUMEN_H3 )
    v0 = CurrentEnemyData.CurEnemy_XPos + 8;
  else
    v0 = CurrentEnemyData.CurEnemy_XPos + 4;
LABEL_15:
  CurrentEnemyData.CurEnemy_XPos = v0;
  if ( (*&CurrentEnemyData.CurEnemy_CurrentAnimationFrameId & 0xFFFFFF) == 0x10005 )
    Sub_8001DA4_m4aSongNumStart(156);
}

// During damaged
void K2_COM_zako_big_marumen() {
  int v2; // r0

  CurrentEnemyData.CurEnemy_TWork1++;
  if ( CurrentEnemyData.CurEnemy_TWork1 & 8 )
    CurrentEnemyData.CurEnemy_paletteId = 0;
  else
    CurrentEnemyData.CurEnemy_paletteId = 4;
  if ( CurrentEnemyData.CurEnemy_XPos <= Wario_usPosX )
  {
    Sub_8023BFC_T_NoCorrectionBgAttack(
      CurrentEnemyData.CurEnemy_YPos - 32,
      CurrentEnemyData.CurEnemy_XPos - CurrentEnemyData.CurEnemy_HitboxX0);
    if ( ucThit2 & 0xF )
    {
      CurrentEnemyData.CurEnemy_TWork2++;
      goto LABEL_7;
    }
    v2 = CurrentEnemyData.CurEnemy_XPos - 16;
  }
  else
  {
    Sub_8023BFC_T_NoCorrectionBgAttack(
      CurrentEnemyData.CurEnemy_YPos - 32,
      CurrentEnemyData.CurEnemy_XPos + CurrentEnemyData.CurEnemy_HitboxX1);
    if ( ucThit2 & 0xF )
    {
      CurrentEnemyData.CurEnemy_TWork2++;
      goto LABEL_7;
    }
    v2 = CurrentEnemyData.CurEnemy_XPos + 16;
  }
  CurrentEnemyData.CurEnemy_XPos = v2;
LABEL_7:
  if ( CurrentEnemyData.CurEnemy_TWork2 >= 8 )
  {
    if ( CurrentEnemyData.CurEnemy_Life )
    {
      CurrentEnemyData.CurEnemy_CurrentAnimationId = Q_T_AUX_5;
      CurrentEnemyData.CurEnemy_paletteId = 0;
      CurrentEnemyData.CurEnemy_TWork1 = 0;
      CurrentEnemyData.CurEnemy_TWork2 = 0;
    } else {
      Sub_803B164_Q_K5_HIP_zako_big_marumen(); // Dead if life is 0
    }
  }
}

void Q_T_AUX_5_zako_big_marumen() {
  CurrentEnemyData.CurEnemy_YPos = 0x640;
  CurrentEnemyData.OAMDataPackPointerForCurrentAnimation = zako_big_marumen_Anm_19;
  CurrentEnemyData.CurEnemy_GuardAndDamageParam = BIG_MARUMEN_H3;
  CurrentEnemyData.CurEnemy_RealFrameCountForCurrentAnimationFrame = 0;
  CurrentEnemyData.CurEnemy_CurrentAnimationFrameId = 2;
  CurrentEnemyData.CurEnemy_TWork0 = 0;
  CurrentEnemyData.CurEnemy_CurrentAnimationId = T_AUX_5;
  if ( CurrentEnemyData.CurEnemy_XPos <= Wario_usPosX )
  {
    if ( CurrentEnemyData.CurEnemy_usStatus & 0x40 )
    {
      return;
    }
  }
  else if ( !(CurrentEnemyData.CurEnemy_usStatus & 0x40) )
  {
    return;
  }
  CurrentEnemyData.CurEnemy_usStatus ^= 0x40;
}

// Turning around after damaged
void T_AUX_5_zako_big_marumen() {
  CurrentEnemyData.CurEnemy_YPos = T_AUX_5_jump_YPos[CurrentEnemyData.CurEnemy_TWork0];
  CurrentEnemyData.CurEnemy_TWork0++;
  if ( T_AUX_5_jump_YPos[CurrentEnemyData.CurEnemy_TWork0] == 0xFFFF )
  {
    Sub_806ACA0_BgShakingInit(0x30,129);
    Sub_8001DA4_m4aSongNumStart(62);
    Sub_801E328_EnemyChildSet(169, 0, 0, 0x0400, T_AUX_5_child_XPos[CurrentEnemyData.CurEnemy_Life & 1]);
    CurrentEnemyData.CurEnemy_CurrentAnimationId = Q_TOBIOKI;
  }
}

void Q_JITTO_zako_big_marumen() {
  CurrentEnemyData.CurEnemy_YPos = 0x640;
  CurrentEnemyData.CurEnemy_GuardAndDamageParam = BIG_MARUMEN_H;
  CurrentEnemyData.CurEnemy_RealFrameCountForCurrentAnimationFrame = 0;
  CurrentEnemyData.CurEnemy_CurrentAnimationFrameId = 0;
  CurrentEnemyData.CurEnemy_CurrentAnimationId = JITTO;
  CurrentEnemyData.CurEnemy_TWork0 = 8;
  switch ( CurrentEnemyData.CurEnemy_Life )
  {
    case 0:
    case 1:
    case 2:
    case 3:
      CurrentEnemyData.CurEnemy_GuardAndDamageParam = BIG_MARUMEN_H3;
      CurrentEnemyData.OAMDataPackPointerForCurrentAnimation = zako_big_marumen_Anm_29;
      break;
    case 4:
    case 5:
      CurrentEnemyData.OAMDataPackPointerForCurrentAnimation = zako_big_marumen_Anm_28;
      break;
    case 6:
    case 7:
      CurrentEnemyData.OAMDataPackPointerForCurrentAnimation = zako_big_marumen_Anm_27;
      break;
    case 8:
    case 9:
      CurrentEnemyData.OAMDataPackPointerForCurrentAnimation = zako_big_marumen_Anm_26;
      break;
    default:
      CurrentEnemyData.OAMDataPackPointerForCurrentAnimation = zako_big_marumen_Anm_25;
      break;
  }
}

void Q_TOBIOKI_zako_big_marumen() {
  CurrentEnemyData.CurEnemy_RealFrameCountForCurrentAnimationFrame = 0;
  CurrentEnemyData.CurEnemy_CurrentAnimationFrameId = 0;
  CurrentEnemyData.CurEnemy_CurrentAnimationId = K0_WALK;
  CurrentEnemyData.CurEnemy_GuardAndDamageParam = BIG_MARUMEN_H3;
  CurrentEnemyData.OAMDataPackPointerForCurrentAnimation = zako_big_marumen_Anm_20;
}

// Bonk
void Q_K1_COM_zako_big_marumen() {
  CurrentEnemyData.CurEnemy_YPos = 0x640;
  CurrentEnemyData.CurEnemy_GuardAndDamageParam = BIG_MARUMEN_H;
  CurrentEnemyData.CurEnemy_CurrentAnimationId = JITTO;
  CurrentEnemyData.CurEnemy_RealFrameCountForCurrentAnimationFrame = 0;
  CurrentEnemyData.CurEnemy_CurrentAnimationFrameId = 0;
  CurrentEnemyData.CurEnemy_TWork0 = 30;
  switch ( CurrentEnemyData.CurEnemy_Life )
  {
    case 0:
    case 1:
    case 2:
    case 3:
      CurrentEnemyData.CurEnemy_GuardAndDamageParam = BIG_MARUMEN_H3;
      CurrentEnemyData.OAMDataPackPointerForCurrentAnimation = zako_big_marumen_Anm_29;
      break;
    case 4:
    case 5:
      CurrentEnemyData.OAMDataPackPointerForCurrentAnimation = zako_big_marumen_Anm_33;
      break;
    case 6:
    case 7:
      CurrentEnemyData.OAMDataPackPointerForCurrentAnimation = zako_big_marumen_Anm_32;
      break;
    case 8:
    case 9:
      CurrentEnemyData.OAMDataPackPointerForCurrentAnimation = zako_big_marumen_Anm_31;
      break;
    case 0xA:
      CurrentEnemyData.OAMDataPackPointerForCurrentAnimation = zako_big_marumen_Anm_30;
      break;
    default:
      CurrentEnemyData.OAMDataPackPointerForCurrentAnimation = zako_big_marumen_Anm_34;
      break;
  }
  Sub_8001DA4_m4aSongNumStart(158);
}
