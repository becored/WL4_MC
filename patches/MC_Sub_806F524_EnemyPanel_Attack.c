// @Description MC_Sub_806F524_EnemyPanel_Attack
// @HookAddress 0x6F526
// @HookString  024d ae46024d 28470000 49f60608 P
// Rewritten by beco

#define BLUE_CRYSTAL_MAX 3
#define RED_CRYSTAL_MAX 3
#define PRIZE_EMPBLK_ID 5

// ワリオボイス用
enum
{
	WV_HAPPY_1,			WV_HAPPY_2,			WV_HAPPY_3,
	WV_FIGHT,			WV_ANXIETY,			WV_HURRY,
	WV_CIRCLE,			WV_GOAL,			WV_PYRAMID_CAT,
	WV_COME_BACK,		WV_ANXIETY_2,		WV_GAMEOVER,
	BV_MOUSE_DAMAGE,	BV_KONDOKE_DAMAGE,	BV_DORAMORI_DAMAGE,
	BV_FLOWERNA_DAMAGE,	BV_PINKY_DAMAGE,	BV_YOKI_DAMAGE,
	SV_SMILE,			TS_BOX_UP1,			TS_BOX_UP2,
	TS_BOX_POP,			TS_BOX_BUMP
};
enum MAP_YAKUWARI {
	YNASHI,				//00:なし
	YDAMAGE,			//01:ダメージ
	YNTOBIRA,			//02:扉
	YNWARP,				//03:触れたらワープ
	YTUBE_UL,			//04:土管↑（左）
	YTUBE_UR,			//05:土管↑（右）
	YTUBE_DL,			//06:土管↓（左）
	YTUBE_DR,			//07:土管↓（右）
	YTOMAP,				//08:触れたらTo Map(BOSS STAGE)
	YGWARP,				//09:ワープ(隠しゲーム内用)
	YYOKIYUKA,			//0A:大ボス床壊れ
	YBLOCK_NA_1,		//0B:壊B（岩）（11）→00				//--- NOMAL BLOCK ---
	YBLOCK_NA_1C,		//0C:壊B（岩）（11）→00（C）
	YBLOCK_NA_2LU,		//0D:壊B（岩）（22左上）→00
	YBLOCK_NA_2LUC,		//0E:壊B（岩）（22左上）→00（C）
	YBLOCK_NA_2,		//0F:壊B（岩）（22他）→00
	YBLOCK_NB_1,		//10:壊B（草）（11）→00
	YBLOCK_NB_1C,		//11:壊B（草）（11）→00（C）
	YBLOCK_NB_2LU,		//12:壊B（草）（22左上）→00
	YBLOCK_NB_2LUC,		//13:壊B（草）（22左上）→00（C）
	YBLOCK_NB_2,		//14:壊B（草）（22他）→00
	YBLOCK_NC_1,		//15:壊B3（11）→00
	YBLOCK_NC_1C,		//16:壊B3（11）→00（C）
	YBLOCK_NC_2LU,		//17:壊B3（22左上）→00
	YBLOCK_NC_2LUC,		//18:壊B3（22左上）→00（C）
	YBLOCK_NC_2,		//19:壊B3（22他）→00
    YBLOCK_ND_1,		//1A:壊B4（11）→00
	YBLOCK_ND_1C,		//1B:壊B4（11）→00（C）
	YBLOCK_ND_2LU,		//1C:壊B4（22左上）→00
	YBLOCK_ND_2LUC,		//1D:壊B4（22左上）→00（C）
	YBLOCK_ND_2,		//1E:壊B4（22他）→00
	YBLOCK_HA_2LU,		//1F:堅い壊B(岩)(22左上)→00
	YBLOCK_HA_2LUC,		//20:堅い壊B(岩)(22左上)→00(C)			//--- HARD BLOCK ---
	YBLOCK_HA_2,		//21:堅い壊B(岩)(22他)→00
	YBLOCK_HB_2LU,		//22:堅い壊B(草)(22左上)→00
	YBLOCK_HB_2LUC,		//23:堅い壊B(草)(22左上)→00(C)
	YBLOCK_HB_2,		//24:堅い壊B(草)(22他)→00
	YBLOCK_HC_2LU,		//25:堅い壊B(鉄)(22左上)→00
	YBLOCK_HC_2LUC,		//26:堅い壊B(鉄)(22左上)→00(C)
	YBLOCK_HC_2,		//27:堅い壊B(鉄)(22他)→00
	YBLOCK_HD_2LU,		//28:堅い壊B(木)(22左上)→00
	YBLOCK_HD_2LUC,		//29:堅い壊B(木)(22左上)→00(C)
	YBLOCK_HD_2,		//2A:堅い壊B(木)(22他)→00
	YBLOCK_FA_1,		//2B:火壊B(11)							//--- FIRE BLOCK ---
	YBLOCK_FA_1C,		//2C:火壊B(11)(C)
	YBLOCK_FA_2LU,		//2D:火壊B(22左上)
	YBLOCK_FA_2LUC,		//2E:火壊B(11左上)(C)
	YBLOCK_FA_2,		//2F:火壊B(22他)
	YBLOCK_SA_2LU,		//30:雪だるま壊れ･弱(22左上)			//--- SNOW BLOCK ---
	YBLOCK_SA_2,        //31:雪だるま壊れ･弱(22左上)
	YBLOCK_SB_2LU,      //32:雪だるま壊れ･強(22左上)
	YBLOCK_SB_2,        //33:雪だるま壊れ･強(22左上)
	YBLOCK_RA_2LU,		//34:ゲート復活壊れブロック(22左上)		//--- RE BLOCK ---
	YBLOCK_RA_2,		//35:ゲート復活壊れブロック(22他)
	YBLOCK_TA_1,		//36:敵指定壊れブロック(パターンなし)	//--- TEKI BLOCK ---
		Yrese37,		//37:
	YSW1_TOBIRA_N,		//38:S1 OFF扉 ON なし
	YSW2_TOBIRA_N,		//39:S2 OFF扉 ON なし
	YSW3_TOBIRA_N,		//3A:S3 OFF扉 ON なし
	YSW4_TOBIRA_N,		//3B:S4 OFF扉 ON なし
	YSW1_N_TOBIRA,		//3C:S1 OFFなし ON 扉
	YSW2_N_TOBIRA,		//3D:S2 OFFなし ON 扉
	YSW3_N_TOBIRA,		//3E:S3 OFFなし ON 扉
	YSW4_N_TOBIRA,		//3F:S4 OFFなし ON 扉
	YSW1N,				//40:スイッチ1本体(初期OFF)
	YSW2N,				//41:スイッチ2本体(初期OFF)
	YSW3N,				//42:スイッチ3本体(初期OFF)
	YSW4N,				//43:スイッチ4本体(初期OFF)
		Yrese44,		//44
		Yrese45,		//45
		Yrese46,		//46
		Yrese47,		//47
	YSW1_N_COIN,		//48:S1 OFF透明コイン ONコイン
	YSW1_N_RCOIN,		//49:S1 OFF透明コイン ON赤コイン
	YSW4_N_COIN,		//4A:S4 OFF	 ONコイン
	YSW4_N_RCOIN,		//4B:S4 OFF	 ON赤コイン
	YSW4_MIZU_FR_NOR,	//4C:S4 OFF水流れ→(速) ON水
	YSW4_MIZU_FL_NOR,	//4D:S4 OFF水流れ←(速) ON水
	YSW4_MIZU_FU_NOR,	//4E:S4 OFF水流れ↑(速) ON水
	YSW4_MIZU_FD_NOR,	//4F:S4 OFF水流れ↓(速) ON水
	YMIZU_NOR,			//50:水
	YMIZU_SR,			//51:水流れ→
	YMIZU_SL,			//52:水流れ←
	YMIZU_SU,			//53:水流れ↑
	YMIZU_SD,			//54:水流れ↓
	YMIZU_FR,			//55:水流れ→（速い）
	YMIZU_FL,			//56:水流れ←（速い）
	YMIZU_FU,			//57:水流れ↑（速い）
	YMIZU_FD,			//58:水流れ↓（速い）
	YBLOCK_IA_1,		//59:滑る壊れ1×1						//--- ICE BLOCK ---
	YBLOCK_IA_1C,		//5A:滑る壊れ1×1(C)
	YBLOCK_IA_2LU,		//5B:滑る壊れ2×2(左上)
	YBLOCK_IA_2LUC,		//5C:滑る壊れ2×2(左上C)
	YBLOCK_IA_2,		//5D:滑る壊れ2×2(その他)
			//5E:
			//5F:
	YWASHIBA_RST =0x60,	//60:大滑車･右へ停止
	YWASHIBA_LST,		//61:大滑車･左へ停止
	YWASHIBA_RUP,		//62:大滑車･左水平/右斜め上
	YWASHIBA_RDW,		//63:大滑車･左水平/右斜め下
	YWASHIBA_LUP,		//64:大滑車･左斜め上/右水平
	YWASHIBA_LDW,		//65:大滑車･左斜め下/右水平
	YWASHIBA_RST2,		//66:大滑車･高得点/右へ停止
	YWASHIBA_LST2,		//67:大滑車･高得点/左へ停止
	YSLIP,				//68:滑る
	YFIRE,				//69:炎パネル
	YBELT_L,			//6A:ベルトコンベア←左
	YBELT_R,			//6B:ベルトコンベア→右
			//6C:
			//6D:
			//6E:
			//6F:
	YCOIN_NOR =0x70,	//70:コイン→00
			//71:
	YCOIN_RED =0x72,	//72:赤コイン→00
			//73:
	YKAIFUKU_A =0x74,	//74:ハート1
	YKAIFUKU_B,			//75:ハート3
	YKAIFUKU_C,			//76:ハート5
			//77:
			//78:
	YHASHIGO_M =0x79,	//79:はしご
	YHASHIGO_U,			//7A:はしご上
	YAMI,				//7B:アミ
	YHIKARI,			//7C:光り(ゾンビ用)
	YTUBUEND,			//7D:つぶれもどし
	YDAMAGE_L,			//7E:パネルの右から指定ﾄﾞｯﾄにダメージ
	YDAMAGE_R,			//7F:パネルの左から指定ﾄﾞｯﾄにダメージ
	YDAMAGE_U,			//80:パネルの下から指定ﾄﾞｯﾄにダメージ
	YDAMAGE_D,			//81:パネルの上から指定ﾄﾞｯﾄにダメージ
			//82:
			//83:
	YDOMINO_R4 =0x84,	//84:ドミノ右へ4パネル(40F		84:ドミノ右へ4パネル
	YDOMINO_L4,			//85:ドミノ左へ4パネル(40F		85:ドミノ左へ4パネル
	YDOMINO_R5D1,		//86:ドミノ右へ5,下へ1(50F		86:ドミノ右へ5,下へ1
	YDOMINO_L5D1,		//87:ドミノ左へ5,下へ1(50F		87:ドミノ左へ5,下へ1
	YDOMINO_R5U1,		//88:ドミノ右へ5,上へ1(50F		88:ドミノ右へ5,上へ1
	YDOMINO_L5U1,		//89:ドミノ左へ5,上へ1(50F		89:ドミノ左へ5,上へ1
	YDOMINO_R3D3,		//8A:ドミノ右へ3,下へ3(60F		8A:ドミノ左へ1,下へ3
	YDOMINO_L3D3,		//8B:ドミノ左へ3,下へ3(60F		8B:ドミノ右へ1,下へ3
	YDOMINO_R3U3,		//8C:ドミノ右へ3,上へ3(60F		8C:ドミノ左へ1,上へ3
	YDOMINO_L3U3,		//8D:ドミノ左へ3,上へ3(60F		8D:ドミノ右へ1,上へ3
	YDOMINO_STP ,		//8E:ドミノストップ				8E:ドミノストップ
			//8F:
	YSW1_DAMAGE_N=0x90,	//90:S1 OFFダメージONなし
	YSW2_DAMAGE_N,		//91:S2 OFFダメージONなし
	YSW3_DAMAGE_N,		//92:S3 OFFダメージONなし
	YSW4_DAMAGE_N,		//93:S4 OFFダメージONなし
	YSW1_N_DAMAGE,		//94:S1 OFFなしONダメージ
	YSW2_N_DAMAGE,		//95:S2 OFFなしONダメージ
	YSW3_N_DAMAGE,		//96:S3 OFFなしONダメージ
	YSW4_N_DAMAGE,		//97:S4 OFFなしONダメージ
	YSW1_HASHIGOM_N,	//98:S1 OFFはしご ON なし
	YSW1_HASHIGOU_N,	//99:S1 OFFはしご ON なし
	YSW1_N_HASHIGOM,	//9A:S1 OFFなし ON はしご
	YSW1_N_HASHIGOU,	//9B:S1 OFFなし ON はしご
	YSW2_DAMAGE_U_N,	//9C:S2 OFF下4ドットダメージONなし
			//9D:
			//9E:
			//9F:
	YSETUP_KEY_PRI0 = 0xA0,	//A0:SETUP役割	カギOBJ優先=0

	/* Custom Enums */
	YBLOCK_TA_2LU = 0x5E,	//5E:敵指定壊れブロック(岩,左上)
	YBLOCK_TA_2 = 0x5F,	//5F:敵指定壊れブロック(岩,他)
	YCOIN_C50 = 0x71,	//71:50コイン→00
	YBLOCK_TNA_1 = 0x73,	//73:壊B（岩）→右隣ID
	YBLOCK_RNA_2LU = 0x77,	//77:ゲート復活壊れブロック(岩,左上)
	YBLOCK_RNA_2 = 0x78,		//78:ゲート復活壊れブロック(岩,他)
	YBLOCK_KA_2LU = 0x82,	//82:鍵ブロック(岩,左上)
	YBLOCK_KA_2 = 0x83,	//83:鍵ブロック(岩,他)
	YBLOCK_HA_1 = 0x8F,	//8F:壊B(岩,1x1)
	YBLOCK_HID_1 = 0x9D,	//9D:隠しB→右隣ID
	YBLOCK_RNA_1 = 0x9E,	//9E:ゲート復活壊れブロック(岩)
	YBLOCK_RNA_1NG = 0x9F,	//9F:Failゲート復活壊れブロック(岩)

	YBLOCK_NA_AW_L = 0xA1,	//A1:壊B(岩,ANYx1,左)
	YBLOCK_NA_AW = 0xA2,	//A2:壊B(岩,ANYx1,他)
	YBLOCK_HA_AW_L = 0xA3,	//A3:堅い壊B(岩,ANYx1,左)
	YBLOCK_HA_AW = 0xA4,	//A4:堅い壊B(岩,ANYx1,他)
	YBLOCK_NA_AH_U = 0xA5,	//A5:壊B(岩,1xANY,上)
	YBLOCK_NA_AH = 0xA6,	//A6:壊B(岩,1xANY,他)
	YBLOCK_HA_AH_U = 0xA7,	//A7:堅い壊B(岩,1xANY,上)
	YBLOCK_HA_AH = 0xA8,	//A8:堅い壊B(岩,1xANY,他)

	YBLOCK_NA_AWH_LU = 0xA9,	//A9:壊B(岩,ANYxANY,左上)
	YBLOCK_NA_AWH_L = 0xAA,	//AA:壊B(岩,ANYxANY,左)
	YBLOCK_NA_AWH = 0xAB,	//AB:壊B(岩,ANYxANY,他)
	YBLOCK_HA_AWH_LU = 0xAC,	//AC:堅い壊B(岩,ANYxANY,左上)
	YBLOCK_HA_AWH_L = 0xAD,	//AD:堅い壊B(岩,ANYxANY,左)
	YBLOCK_HA_AWH = 0xAE,	//AE:堅い壊B(岩,ANYxANY,他)
	YDAMAGE_WARP = 0xAF,	//AF:ダメージ＋ワープ

	YBLOCK_NA_1_B = 0xB0,	//B0:クリスタルブロック(青)
	YBLOCK_NA_1_R = 0xB1,	//B1:クリスタルブロック(赤)
	YBLOCK_NA_2LU_B = 0xB2,	//B2:クリスタルブロック(青,左上)
	YBLOCK_NA_2_B = 0xB3,	//B3:クリスタルブロック(青,他)
	YBLOCK_NA_2LU_R = 0xB4,	//B4:クリスタルブロック(赤,左上)
	YBLOCK_NA_2_R = 0xB5,	//B5:クリスタルブロック(赤,他)

	YBLOCK_RNA_2NG = 0xC0,	//C0:Failゲート復活壊れブロック(岩,左上)
	YBLOCK_RHA_2LU = 0xC1,	//C1:ゲート復活堅い壊れブロック(岩,左上)
	YBLOCK_RHA_2 = 0xC2,		//C2:ゲート復活堅い壊れブロック(岩,他)
	YBLOCK_SNA_2LU = 0xC3,	//C3:スカル壊れブロック(岩,左上)
	YBLOCK_SNA_2 = 0xC4,		//C4:スカル壊れブロック(岩,他)

	PBLOCK_C_1_10 = 0xD0, //D0:？ブロック(10コイン,1x1)
	PBLOCK_C_1_50 = 0xD1, //D1:？ブロック(50コイン,1x1)
	PBLOCK_C_1_100 = 0xD2, //D2:？ブロック(100コイン,1x1)
	PBLOCK_C_1_500 = 0xD3, //D3:？ブロック(500コイン,1x1)
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
  KN_TSCORE10A_JUMP = 0x5A,
  KN_TSCORE100A_DASH = 0x5B,
};

struct BgBDdef { // found in /src/gmap/Wario_bg_atari.o (gigaleak)
	short xp;
	short yp;
	short part;
	char dir;
	char coin;
	char hit;
	char obop;
	char SE;
	//char undefined;
};

#define MEMORY_2039F00 (*(volatile unsigned short*) 0x2039F00)

#define CurrentTileset_EventIdTablePointer (*(volatile unsigned int*) 0x30031FC)
#define CurrentRoomHeader_TilesetId (*(volatile unsigned char*) 0x3000074)

#define CurrentRoomHeader_Layer0MappingType (*(volatile unsigned char*) 0x3000075)
#define CurrentRoomHeader_Layer1MappingType (*(volatile unsigned char*) 0x3000076)
#define CurrentRoomHeader_Layer2MappingType (*(volatile unsigned char*) 0x3000077)
#define CurrentRoomHeader_Layer3MappingType (*(volatile unsigned char*) 0x3000078)

#define CurrentRoomHeader_LayerPriorityALphaParam (*(volatile unsigned char*) 0x300008e)

#define Layer0_DecompressedDataPointer (*(volatile unsigned int*) 0x3000054)
#define Layer0_Width (*(volatile unsigned short*) 0x3000058)
#define Layer0_Height (*(volatile unsigned short*) 0x300005a)

#define Layer1_DecompressedDataPointer (*(volatile unsigned int*) 0x300005c)
#define Layer1_Width (*(volatile unsigned short*) 0x3000060)
#define Layer1_Height (*(volatile unsigned short*) 0x3000062)

#define Layer2_DecompressedDataPointer (*(volatile unsigned int*) 0x3000064)
#define Layer2_Width (*(volatile unsigned short*) 0x3000068)
#define Layer2_Height (*(volatile unsigned short*) 0x300006a)

#define MapSwitch1 (*(volatile unsigned char*) 0x300002f)
#define MapSwitch2 (*(volatile unsigned char*) 0x3000030)
#define MapSwitch3 (*(volatile unsigned char*) 0x3000031)
#define MapSwitch4 (*(volatile unsigned char*) 0x3000032) // frog blocks, etc (see WL4 RAM record)

#define Sub_806EE98_PanelPartWork_Broken_Main ((int (*)(struct BgBDdef*)) 0x806EE99)
#define Sub_806F424_PanelPartWork_Switch_Main ((int (*)(struct BgBDdef*,int)) 0x806F425)
#define Sub_806F4BC_PanelPartWork_YokiDiva_Main ((int (*)(struct BgBDdef*)) 0x806F4BD)

#define Sub_8001DA4_m4aSongNumStart ((void (*)(int)) 0x8001DA5)
#define Sub_801E328_EnemyChildSet ((void (*)(char, char, char, int, int)) 0x801E329)
#define Sub_806ACA0_BgShakingInit ((void (*)(unsigned char, char)) 0x806ACA1)
#define Sub_806F2AC_BgBrokenBlock_ObjSet ((void (*)(struct BgBDdef*)) 0x806F2AD)
#define Sub_806FFB0_Panel_PutBG_Save ((int (*)(int,int,int)) 0x806FFB1)
#define Sub_8070098_Panel_PutBG_Only ((int (*)(int,int,int)) 0x8070099)
#define Sub_80766E8_TOptObjSet ((void (*)(int,int,unsigned char)) 0x80766E9)
#define Sub_8088620_WarioVoiceSet ((void (*)(int)) 0x8088621)

#define ucEnemyBrokenFlag (*(volatile unsigned char*) 0x3000028)
#define ucThit1 (*(volatile unsigned char*) 0x3000A50)
#define ucThit2 (*(volatile unsigned char*) 0x3000A51)
#define ucHasKeyzer (*(volatile signed char*) 0x3000C0C)

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

struct EmpBlkdef {
	short position;
	short tileID;
};

int MC_Sub_806F524_EnemyPanel_Attack(unsigned short y_grid_pos, unsigned short x_grid_pos, unsigned char L1_tile_ID)
{
	signed int v3;
	signed int v6 = 0;
	signed int v7;
	int v8;
	int v9;
	int v10;
	int v11;
	int v12;
	int v13;
	int i;
  struct BgBDdef pDestroy;

	unsigned short Xpos = (x_grid_pos << 22) >> 16;
	unsigned short Ypos = (y_grid_pos << 22) >> 16;

	pDestroy.xp = x_grid_pos;
	pDestroy.yp = y_grid_pos;
	pDestroy.part = *(unsigned short*)((2 * L1_tile_ID & 0x1FFFF) + CurrentTileset_EventIdTablePointer);
	pDestroy.dir = 4;
	pDestroy.coin = 0;
	pDestroy.obop = 0;
	pDestroy.hit = 1;
	v3 = 0;
	if ( ucEnemyBrokenFlag == 2 )
	{
		v8 = 0x2039F00;
		v9 = 0;
		if ( MEMORY_2039F00 == ((x_grid_pos << 8) | y_grid_pos) )
		{
			MEMORY_2039F00 = 0;
		}
		else
		{
			while ( 1 )
			{
				++v8;
				if ( ++v9 > 63 )
					break;
				if ( *(int*)v8 == ((x_grid_pos << 8) | y_grid_pos) )
				{
					*(int*)v8 = 0;
					v6 = 1;
					break;
				}
			}
			if ( !v6 )
			return 1;
		}
		Sub_8070098_Panel_PutBG_Only(0, pDestroy.yp, pDestroy.xp);
		return 1;
	}
	if ( ucEnemyBrokenFlag <= 2 )
	{
		if ( ucEnemyBrokenFlag == 1 )
		{
			// Custom Code
		  switch (pDestroy.part)
		  {
				// Hard block (1 x 1)
				case YBLOCK_HA_1:
						break;

				// Enemy block (1 x 1)
				case YBLOCK_TA_1:
						Sub_806F2AC_BgBrokenBlock_ObjSet(&pDestroy);
						Sub_806FFB0_Panel_PutBG_Save(0, pDestroy.yp, pDestroy.xp);
						Sub_8001DA4_m4aSongNumStart(252);
						return 1; // No knock-back

				// Enemy block (2 x 2)
				case YBLOCK_TA_2LU:
						goto YBLOCK_TA_2_BREAK;
				case YBLOCK_TA_2:
						--pDestroy.xp;
						pDestroy.part = *(unsigned short*)(2 * *(unsigned short*)(2 * (pDestroy.yp * Layer1_Width + pDestroy.xp) + Layer1_DecompressedDataPointer) + CurrentTileset_EventIdTablePointer);
						if ( pDestroy.part == YBLOCK_TA_2LU )
							goto YBLOCK_TA_2_BREAK;
						++pDestroy.xp;
						--pDestroy.yp;
						pDestroy.part = *(unsigned short*)(2 * *(unsigned short*)(2 * (pDestroy.yp * Layer1_Width + pDestroy.xp) + Layer1_DecompressedDataPointer) + CurrentTileset_EventIdTablePointer);
						if ( pDestroy.part == YBLOCK_TA_2LU )
							goto YBLOCK_TA_2_BREAK;
						--pDestroy.xp;
						pDestroy.part = *(unsigned short*)(2 * *(unsigned short*)(2 * (pDestroy.yp * Layer1_Width + pDestroy.xp) + Layer1_DecompressedDataPointer) + CurrentTileset_EventIdTablePointer);
YBLOCK_TA_2_BREAK:
						Sub_806F2AC_BgBrokenBlock_ObjSet(&pDestroy);
						Sub_806FFB0_Panel_PutBG_Save(0, pDestroy.yp, pDestroy.xp);
						++pDestroy.yp;
						Sub_806F2AC_BgBrokenBlock_ObjSet(&pDestroy);
						Sub_806FFB0_Panel_PutBG_Save(0, pDestroy.yp, pDestroy.xp);
						++pDestroy.xp;
						Sub_806F2AC_BgBrokenBlock_ObjSet(&pDestroy);
						Sub_806FFB0_Panel_PutBG_Save(0, pDestroy.yp, pDestroy.xp);
						--pDestroy.yp;
						Sub_806F2AC_BgBrokenBlock_ObjSet(&pDestroy);
						Sub_806FFB0_Panel_PutBG_Save(0, pDestroy.yp, pDestroy.xp);
						Sub_8001DA4_m4aSongNumStart(253);
						return 1;

				// WL1 soft block (1 x 1)
				case YBLOCK_TNA_1:
						pDestroy.part = YBLOCK_NA_1C;
						break;

				// Hidden block (1 x 1)
				case YBLOCK_HID_1:
						Sub_806F2AC_BgBrokenBlock_ObjSet(&pDestroy);
						EXBACKUP_FIELD_EMPBLK[usDisConR_EmpBlk].tileID = *(unsigned short*)(2 * (pDestroy.yp * Layer1_Width + pDestroy.xp) + Layer1_DecompressedDataPointer) + 1;
						EXBACKUP_FIELD_EMPBLK[usDisConR_EmpBlk].position = (2 * (pDestroy.xp + pDestroy.yp * Layer1_Width) & 0x1FFFF) + Layer1_DecompressedDataPointer >> 1;
						Sub_8070098_Panel_PutBG_Only(EXBACKUP_FIELD_EMPBLK[usDisConR_EmpBlk].tileID, pDestroy.yp, pDestroy.xp);
						++usDisConR_EmpBlk;
						Sub_8001DA4_m4aSongNumStart(252);
						Sub_8088620_WarioVoiceSet(SV_SMILE);
						return 1;

				// Reblock (1 x 1)
				case YBLOCK_RNA_1:
						Sub_806F2AC_BgBrokenBlock_ObjSet(&pDestroy);
						Sub_8070098_Panel_PutBG_Only(0, pDestroy.yp, pDestroy.xp); // Re-block
						Sub_8001DA4_m4aSongNumStart(252);
						if ( reblockBrokenCnt != 0xFF )
							reblockBrokenCnt++;
						return 1;

				// Fail Reblock (1 x 1)
				case YBLOCK_RNA_1NG:
						Sub_806F2AC_BgBrokenBlock_ObjSet(&pDestroy);
						Sub_8070098_Panel_PutBG_Only(0, pDestroy.yp, pDestroy.xp); // Re-block
						Sub_8001DA4_m4aSongNumStart(252);
						if ( reblockBrokenFail != 0xFF )
							reblockBrokenFail++;
						return 1;

				// Reblock (2 x 2), Fail Reblock (2 x 2)
				case YBLOCK_RNA_2LU:
						goto YBLOCK_RNA_2_BREAK;
				case YBLOCK_RNA_2:
						--pDestroy.xp;
						pDestroy.part = *(unsigned short*)(2 * *(unsigned short*)(2 * (pDestroy.yp * Layer1_Width + pDestroy.xp) + Layer1_DecompressedDataPointer) + CurrentTileset_EventIdTablePointer);
						if ( pDestroy.part == YBLOCK_RNA_2LU || pDestroy.part == YBLOCK_RNA_2NG )
							goto YBLOCK_RNA_2_BREAK;
						++pDestroy.xp;
						--pDestroy.yp;
						pDestroy.part = *(unsigned short*)(2 * *(unsigned short*)(2 * (pDestroy.yp * Layer1_Width + pDestroy.xp) + Layer1_DecompressedDataPointer) + CurrentTileset_EventIdTablePointer);
						if ( pDestroy.part == YBLOCK_RNA_2LU || pDestroy.part == YBLOCK_RNA_2NG  )
							goto YBLOCK_RNA_2_BREAK;
						--pDestroy.xp;
						pDestroy.part = *(unsigned short*)(2 * *(unsigned short*)(2 * (pDestroy.yp * Layer1_Width + pDestroy.xp) + Layer1_DecompressedDataPointer) + CurrentTileset_EventIdTablePointer);
		YBLOCK_RNA_2_BREAK:
						Sub_806F2AC_BgBrokenBlock_ObjSet(&pDestroy);
						Sub_8070098_Panel_PutBG_Only(0, pDestroy.yp, pDestroy.xp);
						++pDestroy.yp;
						Sub_806F2AC_BgBrokenBlock_ObjSet(&pDestroy);
						Sub_8070098_Panel_PutBG_Only(0, pDestroy.yp, pDestroy.xp);
						++pDestroy.xp;
						Sub_806F2AC_BgBrokenBlock_ObjSet(&pDestroy);
						Sub_8070098_Panel_PutBG_Only(0, pDestroy.yp, pDestroy.xp);
						--pDestroy.yp;
						Sub_806F2AC_BgBrokenBlock_ObjSet(&pDestroy);
						Sub_8070098_Panel_PutBG_Only(0, pDestroy.yp, pDestroy.xp);
						Sub_8001DA4_m4aSongNumStart(253);
						if ( pDestroy.part == YBLOCK_RNA_2LU )
							if ( reblockBrokenCnt != 0xFF )
								reblockBrokenCnt++;
						else if ( pDestroy.part == YBLOCK_RNA_2NG )
							if ( reblockBrokenFail != 0xFF )
								reblockBrokenFail++;
						return 1;

				// Keyzer block (2 x 2)
				case YBLOCK_KA_2LU:
						goto YBLOCK_KA_2_BREAK;
				case YBLOCK_KA_2:
						--pDestroy.xp;
						pDestroy.part = *(unsigned short*)(2 * *(unsigned short*)(2 * (pDestroy.yp * Layer1_Width + pDestroy.xp) + Layer1_DecompressedDataPointer) + CurrentTileset_EventIdTablePointer);
						if ( pDestroy.part == YBLOCK_KA_2LU )
							goto YBLOCK_KA_2_BREAK;
						++pDestroy.xp;
						--pDestroy.yp;
						pDestroy.part = *(unsigned short*)(2 * *(unsigned short*)(2 * (pDestroy.yp * Layer1_Width + pDestroy.xp) + Layer1_DecompressedDataPointer) + CurrentTileset_EventIdTablePointer);
						if ( pDestroy.part == YBLOCK_KA_2LU )
							goto YBLOCK_KA_2_BREAK;
						--pDestroy.xp;
						pDestroy.part = *(unsigned short*)(2 * *(unsigned short*)(2 * (pDestroy.yp * Layer1_Width + pDestroy.xp) + Layer1_DecompressedDataPointer) + CurrentTileset_EventIdTablePointer);
YBLOCK_KA_2_BREAK:
						if ( ucHasKeyzer ) {
							Sub_806F2AC_BgBrokenBlock_ObjSet(&pDestroy);
							Sub_806FFB0_Panel_PutBG_Save(0, pDestroy.yp, pDestroy.xp);
							++pDestroy.yp;
							Sub_806F2AC_BgBrokenBlock_ObjSet(&pDestroy);
							Sub_806FFB0_Panel_PutBG_Save(0, pDestroy.yp, pDestroy.xp);
							++pDestroy.xp;
							Sub_806F2AC_BgBrokenBlock_ObjSet(&pDestroy);
							Sub_806FFB0_Panel_PutBG_Save(0, pDestroy.yp, pDestroy.xp);
							--pDestroy.yp;
							Sub_806F2AC_BgBrokenBlock_ObjSet(&pDestroy);
							Sub_806FFB0_Panel_PutBG_Save(0, pDestroy.yp, pDestroy.xp);
							Sub_8001DA4_m4aSongNumStart(253);
							Sub_8088620_WarioVoiceSet(WV_GOAL);
							ucHasKeyzer = 0;
						} else {
							break;
						}
						return 1;

		// Skull block (2 x 2) Warp(respawn)
		case YBLOCK_SNA_2LU:
				goto YBLOCK_SNA_2_BREAK;
		case YBLOCK_SNA_2:
				--pDestroy.xp;
				pDestroy.part = *(unsigned short*)(2 * *(unsigned short*)(2 * (pDestroy.yp * Layer1_Width + pDestroy.xp) + Layer1_DecompressedDataPointer) + CurrentTileset_EventIdTablePointer);
				if ( pDestroy.part == YBLOCK_SNA_2LU )
					goto YBLOCK_SNA_2_BREAK;
				++pDestroy.xp;
				--pDestroy.yp;
				pDestroy.part = *(unsigned short*)(2 * *(unsigned short*)(2 * (pDestroy.yp * Layer1_Width + pDestroy.xp) + Layer1_DecompressedDataPointer) + CurrentTileset_EventIdTablePointer);
				if ( pDestroy.part == YBLOCK_SNA_2LU )
					goto YBLOCK_SNA_2_BREAK;
				--pDestroy.xp;
				pDestroy.part = *(unsigned short*)(2 * *(unsigned short*)(2 * (pDestroy.yp * Layer1_Width + pDestroy.xp) + Layer1_DecompressedDataPointer) + CurrentTileset_EventIdTablePointer);
YBLOCK_SNA_2_BREAK:
				// Sub_806F2AC_BgBrokenBlock_ObjSet(&pDestroy);
				Sub_806FFB0_Panel_PutBG_Save(0, pDestroy.yp, pDestroy.xp);
				++pDestroy.yp;
				// Sub_806F2AC_BgBrokenBlock_ObjSet(&pDestroy);
				Sub_806FFB0_Panel_PutBG_Save(0, pDestroy.yp, pDestroy.xp);
				++pDestroy.xp;
				// Sub_806F2AC_BgBrokenBlock_ObjSet(&pDestroy);
				Sub_806FFB0_Panel_PutBG_Save(0, pDestroy.yp, pDestroy.xp);
				--pDestroy.yp;
				// Sub_806F2AC_BgBrokenBlock_ObjSet(&pDestroy);
				Sub_806FFB0_Panel_PutBG_Save(0, pDestroy.yp, pDestroy.xp);
				Sub_80766E8_TOptObjSet((((pDestroy.yp << 22) >> 16) + 64), ((pDestroy.xp << 22) >> 16), KN_ATKSTAR2);
				Sub_8001DA4_m4aSongNumStart(253);
				Sub_8088620_WarioVoiceSet(WV_ANXIETY);
				restartFlag = 1;
				return 1;

				// Crystal blocks (1 x 1)
				case YBLOCK_NA_1_B:
						Sub_80766E8_TOptObjSet(((pDestroy.yp << 22) >> 16), ((pDestroy.xp << 22) >> 16), KN_TSCORE10A_JUMP);
						if ( airJumpNum < BLUE_CRYSTAL_MAX ) {
							++airJumpNum;
							crystal_Tflg = 1;
						}
						Sub_806F2AC_BgBrokenBlock_ObjSet(&pDestroy);
						Sub_8070098_Panel_PutBG_Only(0, pDestroy.yp, pDestroy.xp); // Re-block
						Sub_8001DA4_m4aSongNumStart(252);
						return 1;
				case YBLOCK_NA_1_R:
						Sub_80766E8_TOptObjSet(((pDestroy.yp << 22) >> 16), ((pDestroy.xp << 22) >> 16) - 20, KN_TSCORE100A_DASH);
						if ( airAttackNum < RED_CRYSTAL_MAX ) {
							++airAttackNum;
							crystal_Tflg = 1;
						}
						Sub_806F2AC_BgBrokenBlock_ObjSet(&pDestroy);
						Sub_8070098_Panel_PutBG_Only(0, pDestroy.yp, pDestroy.xp); // Re-block
						Sub_8001DA4_m4aSongNumStart(252);
						return 1;

				// Crystal blocks (2 x 2)
				case YBLOCK_NA_2LU_B:
						goto YBLOCK_NA_2_B_BREAK;
				case YBLOCK_NA_2_B:
						--pDestroy.xp;
						pDestroy.part = *(unsigned short*)(2 * *(unsigned short*)(2 * (pDestroy.yp * Layer1_Width + pDestroy.xp) + Layer1_DecompressedDataPointer) + CurrentTileset_EventIdTablePointer);
						if ( pDestroy.part == YBLOCK_NA_2LU_B )
							goto YBLOCK_NA_2_B_BREAK;
						++pDestroy.xp;
						--pDestroy.yp;
						pDestroy.part = *(unsigned short*)(2 * *(unsigned short*)(2 * (pDestroy.yp * Layer1_Width + pDestroy.xp) + Layer1_DecompressedDataPointer) + CurrentTileset_EventIdTablePointer);
						if ( pDestroy.part == YBLOCK_NA_2LU_B )
							goto YBLOCK_NA_2_B_BREAK;
						--pDestroy.xp;
						pDestroy.part = *(unsigned short*)(2 * *(unsigned short*)(2 * (pDestroy.yp * Layer1_Width + pDestroy.xp) + Layer1_DecompressedDataPointer) + CurrentTileset_EventIdTablePointer);
YBLOCK_NA_2_B_BREAK:
						Sub_80766E8_TOptObjSet(((pDestroy.yp << 22) >> 16) + 38, ((pDestroy.xp << 22) >> 16) + 38, KN_TSCORE10A_JUMP);
						if ( airJumpNum < BLUE_CRYSTAL_MAX ) {
							++airJumpNum;
							crystal_Tflg = 1;
						}
						Sub_806F2AC_BgBrokenBlock_ObjSet(&pDestroy);
						Sub_8070098_Panel_PutBG_Only(0, pDestroy.yp, pDestroy.xp); // Re-block
						++pDestroy.yp;
						Sub_806F2AC_BgBrokenBlock_ObjSet(&pDestroy);
						Sub_8070098_Panel_PutBG_Only(0, pDestroy.yp, pDestroy.xp); // Re-block
						++pDestroy.xp;
						Sub_806F2AC_BgBrokenBlock_ObjSet(&pDestroy);
						Sub_8070098_Panel_PutBG_Only(0, pDestroy.yp, pDestroy.xp); // Re-block
						--pDestroy.yp;
						Sub_806F2AC_BgBrokenBlock_ObjSet(&pDestroy);
						Sub_8070098_Panel_PutBG_Only(0, pDestroy.yp, pDestroy.xp); // Re-block
						Sub_8001DA4_m4aSongNumStart(253);
						return 1;
				case YBLOCK_NA_2LU_R:
						goto YBLOCK_NA_2_R_BREAK;
				case YBLOCK_NA_2_R:
						--pDestroy.xp;
						pDestroy.part = *(unsigned short*)(2 * *(unsigned short*)(2 * (pDestroy.yp * Layer1_Width + pDestroy.xp) + Layer1_DecompressedDataPointer) + CurrentTileset_EventIdTablePointer);
						if ( pDestroy.part == YBLOCK_NA_2LU_R )
							goto YBLOCK_NA_2_R_BREAK;
						++pDestroy.xp;
						--pDestroy.yp;
						pDestroy.part = *(unsigned short*)(2 * *(unsigned short*)(2 * (pDestroy.yp * Layer1_Width + pDestroy.xp) + Layer1_DecompressedDataPointer) + CurrentTileset_EventIdTablePointer);
						if ( pDestroy.part == YBLOCK_NA_2LU_R )
							goto YBLOCK_NA_2_R_BREAK;
						--pDestroy.xp;
						pDestroy.part = *(unsigned short*)(2 * *(unsigned short*)(2 * (pDestroy.yp * Layer1_Width + pDestroy.xp) + Layer1_DecompressedDataPointer) + CurrentTileset_EventIdTablePointer);
YBLOCK_NA_2_R_BREAK:
						Sub_80766E8_TOptObjSet(((pDestroy.yp << 22) >> 16) + 38, ((pDestroy.xp << 22) >> 16) + 4, KN_TSCORE100A_DASH);
						if ( airAttackNum < RED_CRYSTAL_MAX ) {
							++airAttackNum;
							crystal_Tflg = 1;
						}
						Sub_806F2AC_BgBrokenBlock_ObjSet(&pDestroy);
						Sub_8070098_Panel_PutBG_Only(0, pDestroy.yp, pDestroy.xp); // Re-block
						++pDestroy.yp;
						Sub_806F2AC_BgBrokenBlock_ObjSet(&pDestroy);
						Sub_8070098_Panel_PutBG_Only(0, pDestroy.yp, pDestroy.xp); // Re-block
						++pDestroy.xp;
						Sub_806F2AC_BgBrokenBlock_ObjSet(&pDestroy);
						Sub_8070098_Panel_PutBG_Only(0, pDestroy.yp, pDestroy.xp); // Re-block
						--pDestroy.yp;
						Sub_806F2AC_BgBrokenBlock_ObjSet(&pDestroy);
						Sub_8070098_Panel_PutBG_Only(0, pDestroy.yp, pDestroy.xp); // Re-block
						Sub_8001DA4_m4aSongNumStart(253);
						return 1;

				// Breakable block (Any x 1)
				case YBLOCK_HA_AW_L:
						break;
				case YBLOCK_NA_AW_L:
						goto YBLOCK_NA_AW_BREAK;
				case YBLOCK_HA_AW:
						break;
				case YBLOCK_NA_AW:
					while ( pDestroy.part != YBLOCK_NA_AW_L && pDestroy.part != YBLOCK_HA_AW_L ) {
						--pDestroy.xp;
						pDestroy.part = *(unsigned short*)(2 * *(unsigned short*)(2 * (pDestroy.yp * Layer1_Width + pDestroy.xp) + Layer1_DecompressedDataPointer) + CurrentTileset_EventIdTablePointer);
					}
YBLOCK_NA_AW_BREAK:
						Sub_806F2AC_BgBrokenBlock_ObjSet(&pDestroy);
						Sub_806FFB0_Panel_PutBG_Save(0, pDestroy.yp, pDestroy.xp);
						while ( 1 ) {
							++pDestroy.xp;
							pDestroy.part = *(unsigned short*)(2 * *(unsigned short*)(2 * (pDestroy.yp * Layer1_Width + pDestroy.xp) + Layer1_DecompressedDataPointer) + CurrentTileset_EventIdTablePointer);
							if ( pDestroy.part != YBLOCK_NA_AW && pDestroy.part != YBLOCK_HA_AW )
								break;
							Sub_806F2AC_BgBrokenBlock_ObjSet(&pDestroy);
							Sub_806FFB0_Panel_PutBG_Save(0, pDestroy.yp, pDestroy.xp);
						}
						Sub_8001DA4_m4aSongNumStart(253);
						return 1;

				// Breakable block (1 x Any)
				case YBLOCK_HA_AH_U:
						break;
				case YBLOCK_NA_AH_U:
						goto YBLOCK_NA_AH_BREAK;
				case YBLOCK_HA_AH:
						break;
				case YBLOCK_NA_AH:
					while ( pDestroy.part != YBLOCK_NA_AH_U && pDestroy.part != YBLOCK_HA_AH_U ) {
						--pDestroy.yp;
						pDestroy.part = *(unsigned short*)(2 * *(unsigned short*)(2 * (pDestroy.yp * Layer1_Width + pDestroy.xp) + Layer1_DecompressedDataPointer) + CurrentTileset_EventIdTablePointer);
					}
YBLOCK_NA_AH_BREAK:
					Sub_806F2AC_BgBrokenBlock_ObjSet(&pDestroy);
					Sub_806FFB0_Panel_PutBG_Save(0, pDestroy.yp, pDestroy.xp);
					while ( 1 ) {
						++pDestroy.yp;
						pDestroy.part = *(unsigned short*)(2 * *(unsigned short*)(2 * (pDestroy.yp * Layer1_Width + pDestroy.xp) + Layer1_DecompressedDataPointer) + CurrentTileset_EventIdTablePointer);
						if ( pDestroy.part != YBLOCK_NA_AH && pDestroy.part != YBLOCK_HA_AH )
							break;
						Sub_806F2AC_BgBrokenBlock_ObjSet(&pDestroy);
						Sub_806FFB0_Panel_PutBG_Save(0, pDestroy.yp, pDestroy.xp);
					}
					Sub_8001DA4_m4aSongNumStart(253);
					return 1;

				// Breakable block (Any x Any)
				case YBLOCK_HA_AWH:
						break;
				case YBLOCK_NA_AWH:
						while ( 1 ) {
							--pDestroy.xp;
							pDestroy.part = *(unsigned short*)(2 * *(unsigned short*)(2 * (pDestroy.yp * Layer1_Width + pDestroy.xp) + Layer1_DecompressedDataPointer) + CurrentTileset_EventIdTablePointer);
							if ( pDestroy.part == YBLOCK_NA_AWH_LU || pDestroy.part == YBLOCK_HA_AWH_LU )
								goto YBLOCK_NA_AWH_BREAK;
							if ( pDestroy.part == YBLOCK_NA_AWH_L || pDestroy.part == YBLOCK_HA_AWH_L )
								goto YBLOCK_NA_AWH_SEARCH;
						}
						break;
				case YBLOCK_HA_AWH_L:
						break;
				case YBLOCK_NA_AWH_L:
YBLOCK_NA_AWH_SEARCH:
						while ( 1 ) {
							--pDestroy.yp;
							pDestroy.part = *(unsigned short*)(2 * *(unsigned short*)(2 * (pDestroy.yp * Layer1_Width + pDestroy.xp) + Layer1_DecompressedDataPointer) + CurrentTileset_EventIdTablePointer);
							if ( pDestroy.part == YBLOCK_NA_AWH_LU || pDestroy.part == YBLOCK_HA_AWH_LU )
								goto YBLOCK_NA_AWH_BREAK;
						}
				case YBLOCK_HA_AWH_LU:
							break;
				case YBLOCK_NA_AWH_LU:
YBLOCK_NA_AWH_BREAK:
						int blk_width = 0;
						while ( 1 ) {
							while ( 1 ) {
								Sub_806F2AC_BgBrokenBlock_ObjSet(&pDestroy);
								Sub_806FFB0_Panel_PutBG_Save(0, pDestroy.yp, pDestroy.xp);
								++blk_width;
								++pDestroy.xp;
								pDestroy.part = *(unsigned short*)(2 * *(unsigned short*)(2 * (pDestroy.yp * Layer1_Width + pDestroy.xp) + Layer1_DecompressedDataPointer) + CurrentTileset_EventIdTablePointer);
								if ( pDestroy.part != YBLOCK_NA_AWH && pDestroy.part != YBLOCK_HA_AWH )
									break;
							}
							pDestroy.xp -= blk_width;
							blk_width = 0;
							++pDestroy.yp;
							pDestroy.part = *(unsigned short*)(2 * *(unsigned short*)(2 * (pDestroy.yp * Layer1_Width + pDestroy.xp) + Layer1_DecompressedDataPointer) + CurrentTileset_EventIdTablePointer);
							if ( pDestroy.part != YBLOCK_NA_AWH_L && pDestroy.part != YBLOCK_HA_AWH_L )
								break;
						}
						Sub_8001DA4_m4aSongNumStart(253);
						return 1;

				// Prize blocks
				case PBLOCK_C_1_10:
				    Sub_801E328_EnemyChildSet(0x81, 0, 0, ((pDestroy.yp << 22) >> 16) + 20, ((pDestroy.xp << 22) >> 16) + 32);
						goto PBLOCK_C_1_BREAK;
				case PBLOCK_C_1_50:
				    Sub_801E328_EnemyChildSet(0x82, 0, 0, ((pDestroy.yp << 22) >> 16) + 20, ((pDestroy.xp << 22) >> 16) + 32);
						goto PBLOCK_C_1_BREAK;
				case PBLOCK_C_1_100:
				    Sub_801E328_EnemyChildSet(0x83, 0, 0, ((pDestroy.yp << 22) >> 16) + 20, ((pDestroy.xp << 22) >> 16) + 32);
						goto PBLOCK_C_1_BREAK;
				case PBLOCK_C_1_500:
						Sub_801E328_EnemyChildSet(0x84, 0, 0, ((pDestroy.yp << 22) >> 16) + 20, ((pDestroy.xp << 22) >> 16) + 32);
PBLOCK_C_1_BREAK:
						EXBACKUP_FIELD_EMPBLK[usDisConR_EmpBlk].tileID = PRIZE_EMPBLK_ID;
						EXBACKUP_FIELD_EMPBLK[usDisConR_EmpBlk].position = (2 * (pDestroy.xp + pDestroy.yp * Layer1_Width) & 0x1FFFF) + Layer1_DecompressedDataPointer >> 1;
						Sub_8070098_Panel_PutBG_Only(EXBACKUP_FIELD_EMPBLK[usDisConR_EmpBlk].tileID, pDestroy.yp, pDestroy.xp);
						++usDisConR_EmpBlk;
						Sub_8001DA4_m4aSongNumStart(228);
						Sub_806ACA0_BgShakingInit(0x14,0);
						return 0;
				default:
						break;
			}

			v7 = Sub_806EE98_PanelPartWork_Broken_Main(&pDestroy);
			v6 = v7;
			if ( v7 != 1 )
			{
				if ( v7 == 2 )
					v6 = 0;
				else
					Sub_806F424_PanelPartWork_Switch_Main(&pDestroy, 0);
			}
		}
		return v6;
	}
	if ( ucEnemyBrokenFlag != 3 )
	{
		if ( ucEnemyBrokenFlag == 4 )
			Sub_806F4BC_PanelPartWork_YokiDiva_Main(&pDestroy);
		return v6;
	}
	v10 = 0x2039F00;
	v11 = 0;
	v12 = x_grid_pos << 8;
	if ( MEMORY_2039F00 == ((x_grid_pos << 8) | y_grid_pos) )
		return 1;
	while ( 1 )
	{
		++v10;
		if ( ++v11 > 63 )
			break;
		if ( *(int*)v10 == (v12 | y_grid_pos) )
		{
			v6 = 1;
			break;
		}
	}
	if ( !v6 )
	{
		v13 = 0x2039F00;
		for ( i = 0; i <= 63; ++i )
		{
			if ( !*(int*)v13 )
			{
				*(int*)v13 = v12 | y_grid_pos;
				Sub_8070098_Panel_PutBG_Only(1, pDestroy.yp, pDestroy.xp);
				return 1;
			}
			++v13;
		}
	}
	return v6;
}
