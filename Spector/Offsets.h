#define ENTITY_SIZE_DEF			0x42E0		// biggest entity offset

#define OFFSET_ENTITYLIST		0x18eda78	// cl_entitylist
#define OFFSET_LOCAL_ENT		0x1c9d198	// LocalPlayer

#define OFFSET_ORIGIN			0x14C		// m_vecAbsOrigin
#define OFFSET_RENDER			0x40bf2e8	// ViewRender
#define OFFSET_MATRIX			0x1b3bd0	// ViewMatrix

#define OFFSET_NAME				0x589		// m_iName
#define OFFSET_TEAM				0x0448		// m_iTeamNum
#define OFFSET_VISIBLE_TIME		0x1ACC		// m_visibletime // 0x1A4c
#define OFFSET_BLEED_OUT_STATE	0x2688		// m_bleedoutState

#define OFFSET_ITEM_ID			0x1698		// m_customScriptInt

#define GLOW_CONTEXT			0x3C8		// Script_Highlight_SetCurrentContext
#define GLOW_LIFE_TIME			0x3A4		// Script_Highlight_SetLifeTime + 4
#define GLOW_DISTANCE			0x3B4		// Script_Highlight_SetFarFadeDist
#define GLOW_TYPE				0x2C4		// Script_Highlight_GetState + 4
#define GLOW_COLOR				0x1D0		// Script_CopyHighlightState
#define GLOW_VISIBLE_TYPE		0x3D0		// Script_Highlight_SetVisibilityType 5th mov
#define GLOW_FADE				0x388		// Script_Highlight_GetCurrentInsideOpacity 3rd result of 3 offsets consecutive or first + 8