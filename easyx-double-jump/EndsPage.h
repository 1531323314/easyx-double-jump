#pragma once
#include"GlobalVar.h"
#include<stdio.h>

#define WenJianName 
void EndsPage() {
	// ��ȡĬ�ϻ�ͼ���ڵ� HDC ���
	HDC hdc = GetImageHDC();
	IMAGE img(WIDTH, HEIGHT); 
	IMAGE img_temp;
	const TCHAR mulu[6][60] = { L"EndsPage1.png" ,L"EndsPage2.png",L"EndsPage3.png",L"EndsPage4.png",L"EndsPage5.png",L"EndsPage6.png" };
	// ��ȡͼƬ����ͼ����
	loadimage(&img,_T("endsbeijing.jpg"));
	putimage(0, 0, &img);
	FlushBatchDraw();
	Sleep(1000);
	for (int i = 0; i < 6; i++)
	{
		getimage(&img_temp, 0, 0,0,0 );
		loadimage(&img_temp, mulu[i]);
		putimage(70, i *80+50, &img_temp);
		FlushBatchDraw();
		Sleep(3000);
	}
}
