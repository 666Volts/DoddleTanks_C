#pragma once

// 通用。
#define NULL					0
#define BOOLean					int
#define TRUE					1
#define FALSE					0
#define V6_PI					3.1415927
#define V6_SQRT2				1.4142136
#define V6_DRT_RIGHT			0.0
#define V6_DRT_UP				(V6_PI / 2)
#define V6_DRT_LEFT				(V6_PI)
#define V6_DRT_DOWN				(V6_PI * 3 / 2)
#define V6_DRT_RIGHTUP			(V6_PI / 4)
#define V6_DRT_LEFTUP			(V6_PI * 3 / 4)
#define V6_DRT_LEFTDOWN			(V6_PI * 5 / 4)
#define V6_DRT_RIGHTDOWN		(V6_PI * 7 / 4)
// 顺时针。
#define V6_CLOCKWISE					-1.0
#define V6_ANTICLOCKWISE				1.0

// 窗体信息。
#define V6_WINDOWWIDTH			1024
#define V6_WINDOWHEIGHT			768

// 逻辑引擎环境信息。
#define V6_UPDATE_MAX_INTERVAL		16

// 渲染引擎环境信息。

// 输入信息。
#define V6_MOUSE_LEFT			VK_LBUTTON
#define V6_KEY_LEFT				65
#define V6_KEY_RIGHT			68
#define V6_KEY_UP				87
#define V6_KEY_DOWN				83
#define V6_KEY_SHOOT			V6_MOUSE_LEFT
#define V6_KEY_SET_WALL			69
#define V6_KEY_PAUSE			2
#define V6_KEY_ESC				27
#define V6_KEY_SLOW				VK_SHIFT
#define V6_KEY_NUM1				49
#define V6_KEY_NUM2				50
#define V6_KEY_NUM3				51

// 游戏信息。
// 难度种类数目。
#define V6_DIFFICULTY_COUNT		3
// 最大波数。
#define V6_GAME_MAX_WAVE		30