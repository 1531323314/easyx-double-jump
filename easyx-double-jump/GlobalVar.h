﻿#pragma once
#include <graphics.h>      // 引用图形库头文件
#include <conio.h>
#define WIDTH 400
#define HEIGHT 600
#define LOAD_START_PAGE_BUTTON_WIDTH 210
#define LOAD_START_PAGE_BUTTON_HEIGHT 46
#define LOAD_START_PAGE_BUTTON_1_X 100
#define LOAD_START_PAGE_BUTTON_1_Y 205
#define LOAD_START_PAGE_BUTTON_2_X 100
#define LOAD_START_PAGE_BUTTON_2_Y 315
#define LOAD_START_PAGE_NAME_1_X 180
#define LOAD_START_PAGE_NAME_1_Y 450
#define LOAD_START_PAGE_NAME_2_X 290
#define LOAD_START_PAGE_NAME_2_Y 500
#define LOAD_START_PAGE_NAME_3_X 290
#define LOAD_START_PAGE_NAME_3_Y 550
#define GEZI_WIDTH 60
#define GEZI_HEIGHT 17
int g_now_working_page =0;
int running=1;
int score =0 ;


struct character
{
	int x=0;
	int y=0;
	double volocity = 3;
	IMAGE character;
	int shut=0;
	int status=1;		//1为下落，0为上升
	int alive=1;
};
struct fangkuai {
	int x;
	int y;
	int alive=0;
};
fangkuai gezi[80];
