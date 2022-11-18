// @Description MC_Sub_806D5C0_MapFieldAtari_Enemy
// @HookAddress 0x6D5CA
// from 0x6D5CA to 0x6D71C, 2 passed-in params for the vanilla function
// @HookString 024a 9646024a 10470000 1dd70608 P

/* Patch & Hook details

 .thumb
    .dcb 1
    ldr r2, .DATA
    mov lr, r2
    ldr r2, .DATA + 4
    bx r2
    .dcb 1
  .DATA:
    .word 0x0806D71D
    .word 0xAAAAAAAA
 */

/**
 * changelog:
 * directly modified from the IDA pro's generated C code.
 *            ---- by ssp (shinespeciall), 2022/03/01
 * fix a wrong param type in the declaration for function Sub_806F524_EnemyPanel_Attack(...).
 *            ---- by beco (becored), 2022/08/28
 * a little bit logic tweak to make block breaking logic looks better.
 *            ---- by ssp (shinespeciall), 2022/08/28
 */

#define ucEnemyBrokenFlag (*(volatile unsigned char*) 0x3000028)
// #define Layer0_DecompressedDataPointer (*(volatile unsigned short**) 0x3000054)
// #define Layer0_Width (*(volatile unsigned short*) 0x3000058)
// #define Layer0_Height (*(volatile unsigned short*) 0x300005a)
#define Layer1_DecompressedDataPointer (*(volatile unsigned short**) 0x300005c)
#define Layer1_Width (*(volatile unsigned short*) 0x3000060)
#define Layer1_Height (*(volatile unsigned short*) 0x3000062)
#define Layer2_DecompressedDataPointer (*(volatile unsigned short**) 0x3000064)
#define Layer2_Width (*(volatile unsigned short*) 0x3000068)

#define CurrentRoomHeader_Layer2MappingType (*(volatile unsigned char*) 0x3000077)

#define CurrentTileset_TerrainTypeTablePointer (*(volatile unsigned char**) 0x30031F8)
// #define CurrentTileset_EventIdTablePointer (*(volatile unsigned short**) 0x30031FC)

#define Tile_collision_fucntionTable ((volatile unsigned int*) 0x878F2E4)
/** pPanel_Atari_Main_tbl[13] =  // found in /src/gmap/atari.o
   Atari_NASHI, Atari_ALL, Atari_45LU, Atari_45RU, Atari_30LU2
   Atari_30LU1, Atari_30RU1, Atari_30RU2, Atari_WaDamege_ALL
   Atari_TekiOnly_ALL, Atari_WaDTe_ALL, Atari_DUMMY, Atari_NASHI
 */

#define Sub_806D89C_Panel_Atari_SW_tbl ((int (*)(int*)) 0x806D89D) // can be found in /src/gmap/atari.o, if you want to change the switches mechanism
#define Sub_806DAC0_PanelYakuAllNum_TileEventId ((int (*)(unsigned short, unsigned short)) 0x806DAC1)
#define Sub_806F524_EnemyPanel_Attack ((int (*)(unsigned short, unsigned short, unsigned short)) 0x806F525)

#define Sub_8094E00_call_via_r1 ((int (*)(int*, int)) 0x8094E01)

enum ATARI_enum {
	ANASHI,		//00:なし
	AALL,		//01:全面
	A45L,		//02:左上->右下斜め４５°
	A45R,		//03:右上->左下斜め４５°
	A30L2,		//04:左上->右下斜め３０°（左）
	A30L1,		//05:左上->右下斜め３０°（右）
	A30R1,		//06:右上->左下斜め３０°（左）
	A30R2,		//07:右上->左下斜め３０°（右）
	AWDALL,		//08:ワリオダメージ中アタリあり
	ATEKIALL,	//09:敵のみアタリあり
	AWADTALL,	//0A:ワリオダメージ中・敵アタリあり
		Arese0B,	//0B:下スルー
	AUTHR,		//0C:上スルー
		Arese0D,	//0D:左スルー
		Arese0E,	//0E:右スルー
		Arese0F,	//0F:左下スルー
		Arese10,	//10:右下スルー
		Arese11,	//11:
		Arese12,	//12:
		Arese13,	//13:
	ASW1_N_ALL,		//14:S1OFFなしON全面アタリ
	ASW2_N_ALL,		//15:S2OFFなしON全面アタリ
	ASW3_N_ALL,		//16:S3OFFなしON全面アタリ
	ASW4_N_ALL,		//17:S4OFFなしON全面アタリ
	ASW1_ALL_N,		//18:S1OFF全面アタリONなし
	ASW2_ALL_N,		//19:S2OFF全面アタリONなし
	ASW3_ALL_N,		//1A:S3OFF全面アタリONなし
	ASW4_ALL_N,		//1B:S4OFF全面アタリONなし
		Arese1C,	//1C:
	ASW1_N_WDALL,	//1D:S1OFFなしONワリオダメージ中アタリあり
	ASW2_N_WDALL,	//1E:S2OFFなしONワリオダメージ中アタリあり
	ASW3_N_WDALL,	//1F:S3OFFなしONワリオダメージ中アタリあり
	ASW4_N_WDALL,	//20:S4OFFなしONワリオダメージ中アタリあり
	ASW1_WDALL_N,	//21:S1OFFワリオダメージ中アタリありONなし
	ASW2_WDALL_N,	//22:S2OFFワリオダメージ中アタリありONなし
	ASW3_WDALL_N,	//23:S3OFFワリオダメージ中アタリありONなし
	ASW4_WDALL_N,	//24:S4OFFワリオダメージ中アタリありONなし
		Arese25,	//25:
	ASW1_N_UTHR,	//26:S1OFFなしON上スルー
	ASW2_N_UTHR,	//27:S2OFFなしON上スルー
	ASW3_N_UTHR,	//28:S3OFFなしON上スルー
	ASW4_N_UTHR,	//29:S4OFFなしON上スルー
	ASW1_UTHR_N,	//2A:S1OFF上スルーONなし
	ASW2_UTHR_N,	//2B:S2OFF上スルーONなし
	ASW3_UTHR_N,	//2C:S3OFF上スルーONなし
	ASW4_UTHR_N,	//2D:S4OFF上スルーONなし
		Arese2E,	//2E:
	ASW1_ALL_45LU,	//2F:S1OFF全面アタリON左上->右下斜め４５°
	ASW2_ALL_45LU,	//30:S2OFF全面アタリON左上->右下斜め４５°
	ASW3_ALL_45LU,	//31:S3OFF全面アタリON左上->右下斜め４５°
	ASW4_ALL_45LU,	//32:S4OFF全面アタリON左上->右下斜め４５°
	ASW1_45LU_ALL,	//33:S1OFF左上->右下斜め４５°ON全面アタリ
	ASW2_45LU_ALL,	//34:S2OFF左上->右下斜め４５°ON全面アタリ
	ASW3_45LU_ALL,	//35:S3OFF左上->右下斜め４５°ON全面アタリ
	ASW4_45LU_ALL,	//36:S4OFF左上->右下斜め４５°ON全面アタリ
		Arese37,	//37:
	ASW1_ALL_45RU,	//38:S1OFF全面アタリON右上->左下斜め４５°
	ASW2_ALL_45RU,	//39:S2OFF全面アタリON右上->左下斜め４５°
	ASW3_ALL_45RU,	//3A:S3OFF全面アタリON右上->左下斜め４５°
	ASW4_ALL_45RU,	//3B:S4OFF全面アタリON右上->左下斜め４５°
	ASW1_45RU_ALL,	//3C:S1OFF右上->左下斜め４５°ON全面アタリ
	ASW2_45RU_ALL,	//3D:S2OFF右上->左下斜め４５°ON全面アタリ
	ASW3_45RU_ALL,	//3E:S3OFF右上->左下斜め４５°ON全面アタリ
	ASW4_45RU_ALL,	//3F:S4OFF右上->左下斜め４５°ON全面アタリ
//
	ABLD_EVB16=0x80,	//80:XXX_0彩度1透明度16
	ABLD_EVB14,			//81:XXX_0彩度3透明度14
	ABLD_EVB12,			//82:XXX_0彩度5透明度12
	ABLD_EVB10,			//83:XXX_0彩度7透明度10
	ABLD_EVB07,			//84:XXX_0彩度10透明度7
	ABLD_EVB04,			//85:XXX_0彩度13透明度4
	ABLD_EVB01,			//86:XXX_0彩度16透明度1

  /* Custom Enums */
  AWARIOALL=0x90,  //90:ワリオのみアタリあり
  AALL_HIT=0x91,  //91:ヒット(アタック)判定中のみアタリあり
  ATEKI_UTHR=0x92,  //92:敵のみ上スルー
};

struct Mhitdef // found in /src/gmap/atari.o
{
    int anum;
    unsigned int x_0x3F;
    unsigned int y_0x3F;
    int swnum;
    int swtype;
    int who; // Wario: 0, Enemy: 1
};

#define Terrain_usField (*(volatile unsigned short*) 0x30000a0)
enum usField_enum{
    YF_Nothing,   //00:nothing in layer 1 and 2
    YF_Door,  //01:door
    YF_Ladder_M, //02:ladder
    YF_Ladder_U, //03:top of ladder
    YF_climbable_net, //04:climbable net
    YF_BELT_L,  //05:belt to left, only works on layer 1
    YF_BELT_R,  //06:belt to right
    YF_TUBE_UL,  //07:left part of go-up pipe
    YF_TUBE_UR,  //08:right part of go-up pipe
    YF_TUBE_DL,  //09:left part of go-down pipe
    YF_TUBE_DR,  //0A:right part of go-down pipe
    YF_SLIP,  //0B:slippery platforms
    YF_Water_SR,  //0C:slow current rightwards
    YF_Water_SL,  //0D:slow current leftwards
    YF_Water_SU,  //0E:slow current upwards
    YF_Water_SD,  //0F:slow current downwards
    YF_Water_FR,  //00:fact current rightwards
    YF_Water_FL,  //11:fast current leftwards
    YF_Water_FU,  //12:fast current upwards
    YF_Water_FD,  //13:fast current downwards
};

// 030000a2 : u16 Pyaku[1] - usKoka - 01(in water) 00(else) (from WL4 RAM record)
#define Terrain_usKoka_SolidOrWater (*(volatile unsigned short*) 0x30000a2)
enum uskoka_enum
{
    YK_Nothing,
    YK_Water,
};

#define CurrentEnemyData (*(volatile struct EnemyDataStructure*) 0x3000A24)

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

// My variables (perhaps unused in original)
#define usDisConR_EmpBlk (*(volatile unsigned short*) 0x3006F00)
#define crystal_Tflg (*(volatile unsigned char*) 0x3006F0E)
#define dashAttackFlag (*(volatile unsigned char*) 0x3006F0F)
#define airAttackNum (*(volatile unsigned char*) 0x3006F10)
#define airAttackStat (*(volatile unsigned char*) 0x3006F11)
#define airJumpNum (*(volatile unsigned char*) 0x3006F12)
#define aFlipFlag (*(volatile unsigned char*) 0x3006F13)
#define hFlipFlag (*(volatile unsigned char*) 0x3006F14)

int MC_Sub_806D5C0_MapFieldAtari_Enemy(unsigned short Enemy_y, unsigned short Enemy_x)
{
    unsigned int x_grid_pos;
    unsigned int y_grid_pos;
    int tile_offset;
    int result;
    int tmp_result;
    unsigned char L1_tile_terrain_type;
    unsigned char L2_tile_terrain_type;
    unsigned short TileId_to_reset_TerrainType;
    int EnemyPanelAttack_result = 0;
    struct Mhitdef l_Mhit;

    int y_grid_pos_enemy_head = (CurrentEnemyData.CurEnemy_YPos << 16) >> 22;
    int x_grid_pos_enemy_side = (CurrentEnemyData.CurEnemy_XPos << 16) >> 22;

    if ( Enemy_x >= (Layer1_Width << 6) || Enemy_y >= (Layer1_Height << 6) )
    {
        result = 0;
        Terrain_usField = 0;
        Terrain_usKoka_SolidOrWater = 0;
        return result;
    }
    Sub_806DAC0_PanelYakuAllNum_TileEventId(Enemy_y, Enemy_x);
    y_grid_pos = (Enemy_y << 16) >> 22;
    x_grid_pos = (Enemy_x << 16) >> 22;
    tile_offset = y_grid_pos * Layer1_Width + x_grid_pos;
    TileId_to_reset_TerrainType = Layer1_DecompressedDataPointer[tile_offset];
    L1_tile_terrain_type = CurrentTileset_TerrainTypeTablePointer[TileId_to_reset_TerrainType];

    // Custom Code
    switch ( L1_tile_terrain_type )
    {
      default:
          break;
    }

    if ( ucEnemyBrokenFlag && 1 == 1 )
    {
        EnemyPanelAttack_result = Sub_806F524_EnemyPanel_Attack(y_grid_pos, x_grid_pos, TileId_to_reset_TerrainType);
        if ( EnemyPanelAttack_result )
        {
            L1_tile_terrain_type = (ucEnemyBrokenFlag == 3) ? 1 : 0;
        }
        ucEnemyBrokenFlag = 0;
    }
    tile_offset = y_grid_pos * Layer2_Width + x_grid_pos;
    L2_tile_terrain_type = CurrentTileset_TerrainTypeTablePointer[Layer2_DecompressedDataPointer[tile_offset]];
    l_Mhit.anum = L1_tile_terrain_type;
    l_Mhit.x_0x3F = Enemy_x & 0x3F;
    l_Mhit.y_0x3F = Enemy_y & 0x3F;
    l_Mhit.swnum = 0;
    l_Mhit.swtype = 0;
    l_Mhit.who = 1;
    if ( L1_tile_terrain_type > 12 )
    {
        if ( (L1_tile_terrain_type - 0x14) > 0x2B )
        {
            l_Mhit.anum = 0;
        }
        else
        {
            result = /* (Mhitdef *) */Sub_806D89C_Panel_Atari_SW_tbl(&(l_Mhit.anum));
        }
    }
    else
    {
        // L1_tile_terrain_type <= 12
        result = /* (Mhitdef *) */Sub_8094E00_call_via_r1(&(l_Mhit.anum), Tile_collision_fucntionTable[L1_tile_terrain_type]);
    }
    if ( !l_Mhit.anum ) // if nothing in Layer 1
    {

				// Custom Code
				switch ( L2_tile_terrain_type )
				{
					case Arese0B:
					case Arese0F:
					case Arese10:
						if ( y_grid_pos_enemy_head >= y_grid_pos )
						{
							return 0x1000001;
						}
						break;
					case Arese0D:
						if ( x_grid_pos > x_grid_pos_enemy_side )
						{
							return 0x1000001;
						}
						break;
					case Arese0E:
						if ( x_grid_pos < x_grid_pos_enemy_side )
						{
							return 0x1000001;
						}
						break;
					case ATEKI_UTHR:
						L2_tile_terrain_type = AUTHR;
						break;
					default:
						break;
				}

        l_Mhit.anum = L2_tile_terrain_type;
        if ( L2_tile_terrain_type == 12 && CurrentRoomHeader_Layer2MappingType == 16 )
        {
            tmp_result = Sub_8094E00_call_via_r1(&(l_Mhit.anum), 0x806D731 /*Tile_collision_fucntionTable[12]*/);
        }
        else
        {
            if ( (l_Mhit.anum - 38) > 7 || CurrentRoomHeader_Layer2MappingType != 16 )
            {
                return result;
            }
            tmp_result = Sub_806D89C_Panel_Atari_SW_tbl(&(l_Mhit.anum));
        }
				result = tmp_result;
    }
    return result;
}
