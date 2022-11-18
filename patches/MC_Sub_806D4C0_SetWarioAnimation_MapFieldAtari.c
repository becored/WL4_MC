// @Description modify Sub_806D4C0_SetWarioAnimation_MapFieldAtari
// @HookAddress 0x6D4C2
// from 0x6D4C2 to 0x6D5B4, 2 passed-in params for the vanilla function
// @HookString 024a 9646024a 10470000 b5d50608 P

/* Patch & Hook details

 .thumb
    .dcb 1
    ldr r2, .DATA
    mov lr, r2
    ldr r2, .DATA + 4
    bx r2
    .dcb 1
  .DATA:
    .word 0x0806D5B5
    .word 0xAAAAAAAA
 */

/**
 * changelog:
 * directly modified from the IDA pro's generated C code.
 *            ---- by ssp (shinespeciall), 2021/12/12
 * add more infos of strust and functions ref from the leaks.
 *            ---- by ssp (shinespeciall), 2022/01/24
 * add custom code to let wario run on water surface.
 *            ---- by ssp (shinespeciall), 2022/01/27
 * add custom code for layer 2 one-way tiles, since the game has
 * already supported upwards one-way tiles, i only added the logic for the other 3.
 * they are still buggy on some edge cases but can work most of the time.
 *            ---- by ssp (shinespeciall), 2022/03/08
 * add one missing entry into pPanel_Atari_Main_tbl to fix a crash case in the patch.
 *            ---- by ssp (shinespeciall), 2022/08/19
 */

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

#define Layer0_DecompressedDataPointer (*(volatile unsigned short**) 0x3000054)
#define Layer0_Width (*(volatile unsigned short*) 0x3000058)
#define Layer0_Height (*(volatile unsigned short*) 0x300005a)
#define Layer1_DecompressedDataPointer (*(volatile unsigned short**) 0x300005c)
#define Layer1_Width (*(volatile unsigned short*) 0x3000060)
#define Layer1_Height (*(volatile unsigned short*) 0x3000062)
#define Layer2_DecompressedDataPointer (*(volatile unsigned short**) 0x3000064)

#define CurrentRoomHeader_Layer2MappingType (*(volatile unsigned char*) 0x3000077)

#define Wario_ucReact (*(volatile char*) 0x3001898)
#define Wario_ucStat (*(volatile char*) 0x3001899)

#define Wario_usMukiX  (*(volatile short*) 0x30018A6) // face right: 0x10, face left: 0x20
#define Wario_usPosX  (*(volatile short*) 0x30018AA) // rightwards positive
#define Wario_usPosY  (*(volatile short*) 0x30018AC) // downwards positive
#define Wario_speed_X (*(volatile short*) 0x30018AE)
#define Wario_speed_Y (*(volatile short*) 0x30018B0)
#define Wario_sHitDX1 (*(volatile short*) 0x30018CA) // seems always negative
#define Wario_sHitDY1 (*(volatile short*) 0x30018CC) // seems always negative
#define Wario_sHitDX2 (*(volatile short*) 0x30018CE)

#define CurrentTileset_TerrainTypeTablePointer (*(volatile unsigned char**) 0x30031F8)
#define CurrentTileset_EventIdTablePointer (*(volatile unsigned short**) 0x30031FC)

// #define Tile_collision_fucntionTable ((volatile unsigned int*) 0x878F2E4)
/** pPanel_Atari_Main_tbl[13] =  // found in /src/gmap/atari.o
   Atari_NASHI, Atari_ALL, Atari_45LU, Atari_45RU, Atari_30LU2
   Atari_30LU1, Atari_30RU1, Atari_30RU2, Atari_WaDamege_ALL
   Atari_TekiOnly_ALL, Atari_WaDTe_ALL, Atari_DUMMY, Atari_NASHI
 */
const unsigned int pPanel_Atari_Main_tbl[13] = {0x806D731, 0x806D735, 0x806D741, 0x806D75D, 0x806D77D,
                                                0x806D799, 0x806D7B9, 0x806D7D9, 0x806D7F9, 0x806D82D,
                                                0x806D855, 0x806D88D, 0x806D731};

#define Sub_806D89C_Panel_Atari_SW_tbl ((int (*)(int*)) 0x806D89D) // can be found in /src/gmap/atari.o, if you want to change the switches mechanism
#define Sub_8094E00_call_via_r1 ((int (*)(int*, int)) 0x8094E01)
#define Sub_8001DA4_m4aSongNumStart ((int (*)(int)) 0x8001DA5) // to produce various sound effects
#define Sub_8088620_WarioVoiceSet ((void (*)(int)) 0x8088621)

struct Mhitdef // found in /src/gmap/atari.o
{
    int anum;
    unsigned int x_0x3F;
    unsigned int y_0x3F;
    int swnum;
    int swtype;
    int who; // Wario: 0, Enemy: 1
};

#define WHit (*(volatile struct WHitDef*) 0x3001918)

struct WHitDef {
	unsigned short usMukiX;   //Ｘ移動方向
	unsigned short usMukiY;   //Ｙ移動方向
	unsigned char ucFront;   //前方当りポジション
	unsigned char ucBack;    //後方当りポジション
	unsigned short sDX;    //当りによる補正Ｘ

	unsigned char ucSide;    //横壊れ有り
	unsigned char ucHead;    //頭壊れ有り
	unsigned char ucYuka;    //床壊れ有り
	unsigned char ucSPow;    //横壊しのパワー
	unsigned char ucHPow;    //頭
	unsigned char ucYPow;    //床
	unsigned char ucWSide;   //横当りで壊れたとき立てる
	unsigned char ucWHead;   //頭
	unsigned char ucWYuka;   //床
	unsigned char ucPlace;

	unsigned char ucSStop;   //横かべのとき立てる
	unsigned char ucHStop;   //上
	unsigned char ucYStop;   //床
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
#define atariFrom (*(volatile unsigned char*) 0x3006F15) // 1: Side, 2: Head, 3: Yuka
#define debugger1 (*(volatile unsigned short*) 0x3006F20)
#define debugger2 (*(volatile unsigned short*) 0x3006F22)

int MC_Sub_806D4C0_SetWarioAnimation_MapFieldAtari(unsigned short Wario_y, unsigned short Wario_x)
{
    unsigned int x_grid_pos;
    unsigned int y_grid_pos;

    int tile_id;
    int result;
    unsigned char L1_tile_terrain_type;
    unsigned char L2_tile_terrain_type;
    unsigned short L0_tile_event_id;
    struct Mhitdef v11;

    if ( Wario_x >= (Layer1_Width << 6) )
        return /* (Mhitdef *) */0x1000001;
    if ( Wario_y >= (Layer1_Height << 6) )
        return 0;
    y_grid_pos = (Wario_y << 16) >> 22;
    x_grid_pos = (Wario_x << 16) >> 22;
    int y_grid_pos_wario = ((Wario_usPosY) << 16) >> 22;
    int y_grid_pos_wario_head = ((Wario_usPosY + Wario_sHitDY1) << 16) >> 22;
    int y_grid_pos_wario_head_squad = ((Wario_usPosY + Wario_sHitDY1 - 5) << 16) >> 22;
    int x_grid_pos_wario_rightside_hitbox = ((Wario_usPosX + Wario_sHitDX2) << 16) >> 22;
    int x_grid_pos_wario_leftside_hitbox = ((Wario_usPosX + Wario_sHitDX1) << 16) >> 22;
    int y_grid_pos_wario_hip = ((Wario_usPosY - 22) << 16) >> 22;
    int y_grid_pos_wario_top = ((Wario_usPosY + Wario_sHitDY1 + 20) << 16) >> 22;
    tile_id = y_grid_pos * Layer1_Width + x_grid_pos;
    L1_tile_terrain_type = CurrentTileset_TerrainTypeTablePointer[Layer1_DecompressedDataPointer[tile_id]];
    L2_tile_terrain_type = CurrentTileset_TerrainTypeTablePointer[Layer2_DecompressedDataPointer[tile_id]];
    v11.anum = L1_tile_terrain_type;
    v11.x_0x3F = Wario_x & 0x3F;
    v11.y_0x3F = Wario_y & 0x3F;
    v11.swnum = 0;
    v11.swtype = 0;
    v11.who = 0;
    result = 0;

    // Custom Code
    switch ( L1_tile_terrain_type )
    {
      case AWARIOALL:
          return 0x1000001;
			case AALL_HIT:
					if ( (WHit.ucSPow && (y_grid_pos <= y_grid_pos_wario_hip)) \
					  || (WHit.ucHPow && (y_grid_pos < y_grid_pos_wario_top)) \
					  || (WHit.ucYPow && (y_grid_pos > y_grid_pos_wario_hip)) )
		      	return 0x1000001;
					break;
      default:
          break;
    }

    if ( L1_tile_terrain_type > 12 )
    {
        if ( (L1_tile_terrain_type - 0x14) > 0x2B )
        {
            v11.anum = 0;
        }
        else
        {
            result = /* (Mhitdef *) */Sub_806D89C_Panel_Atari_SW_tbl(&(v11.anum));
        }
    }
    else
    {
        // L1_tile_terrain_type <= 12
        result = /* (Mhitdef *) */Sub_8094E00_call_via_r1(&(v11.anum), pPanel_Atari_Main_tbl[L1_tile_terrain_type]);
    }
    if ( !v11.anum ) // if nothing in Layer 1
    {
        // ------------------custom code----------------------------
        // let Wario be able to run on water surface
        // tile_id = y_grid_pos * Layer0_Width + x_grid_pos;
        // L0_tile_event_id = CurrentTileset_EventIdTablePointer[Layer0_DecompressedDataPointer[tile_id]];
        // if (L0_tile_event_id == 0x50) // water
        // {
        //     if ((Wario_speed_X >= 96 || Wario_speed_X <= -96) && Wario_ucReact == 0)
        //     {
        //         v11.anum = 12; // platform
        //         result = Sub_8094E00_call_via_r1(&v11, pPanel_Atari_Main_tbl[12]);
        //         return result;
        //     }
        // }
        // ----------------custom code end--------------------------

				// Custom Code
				L0_tile_event_id = CurrentTileset_EventIdTablePointer[Layer0_DecompressedDataPointer[tile_id]];
        if ( L0_tile_event_id == 0x50 ) // Water tiles (remove crystal power)
				{
					if ( airJumpNum || airAttackNum )
					{
						airJumpNum = 0;
						airAttackNum = 0;
						crystal_Tflg = 1;
						Sub_8001DA4_m4aSongNumStart(243);
						// Sub_8088620_WarioVoiceSet(11);
					}
				}

        v11.anum = L2_tile_terrain_type;
        if (CurrentRoomHeader_Layer2MappingType != 16)
        {
            if ((v11.anum - 38) > 7)
            {
                return result;
            }
        }
        else
        {
            if (L2_tile_terrain_type == 0x0B || L2_tile_terrain_type == 0x0F || L2_tile_terrain_type == 0x10)
            { // custom downwards one-way, 0x0B, 0x0F, 0x10
                // when wario goes up and his head is lower than the current input position
                if (Wario_speed_Y > 0 && (y_grid_pos_wario_head_squad >= y_grid_pos))
                {
                    return 0x1000001;
                }
                else
                {
                    if (Wario_ucStat < 10 && \
                        Wario_ucStat > 4 && \
                        y_grid_pos_wario_head_squad >= y_grid_pos)
                    {
                        return 0x1000001;
                    }
                    // return 0;
                }
            }
            if (L2_tile_terrain_type == 0x0D || L2_tile_terrain_type == 0x0F)
            { // custom leftwards one-way, 0x0D, 0x0F
                if (Wario_speed_X >= 0 && \
                    Wario_usMukiX == 0x10 && \
                    (x_grid_pos_wario_rightside_hitbox <= x_grid_pos) && \
                    (y_grid_pos_wario >= y_grid_pos))
                {
                    return 0x1000001;
                }
                // else
                // {
                //     return 0;
                // }
            }
            if (L2_tile_terrain_type == 14 || L2_tile_terrain_type == 0x10)
            { // custom rightwards one-way, 0x0E, 0x10
                if (Wario_speed_X <= 0 && \
                    Wario_usMukiX == 0x20 && \
                    (x_grid_pos_wario_leftside_hitbox >= x_grid_pos) && \
                    (y_grid_pos_wario >= y_grid_pos))
                {
                    return 0x1000001;
                }
                // else
                // {
                //     return 0;
                // }
            }
            if (L2_tile_terrain_type == 12) // vanilla upwards one-way
            {
                return 12;
            }
            else
            {
                return Sub_806D89C_Panel_Atari_SW_tbl(&(v11.anum));
            }
        }
    }
    return result;
}
