#pragma once
#include"GlobalVar.h"
#include<stdio.h>
#define WenJianName ""
void EndsPage() {
	// ��ȡĬ�ϻ�ͼ���ڵ� HDC ���
	HDC hdc = GetImageHDC();
	IMAGE img(WIDTH, HEIGHT);
	IMAGE img_temp;
	const char mulu[6][60] = { "C:\\Users\\kingxue\\Desktop\\��Ϸ\\sucai\\endsbeijing.jpg" ,"C:\\Users\\kingxue\\Desktop\\��Ϸ\\sucai\\2.png","C:\\Users\\kingxue\\Desktop\\��Ϸ\\sucai\\3.png","C:\\Users\\kingxue\\Desktop\\��Ϸ\\sucai\\4.png","C:\\Users\\kingxue\\Desktop\\��Ϸ\\sucai\\5.png","C:\\Users\\kingxue\\Desktop\\��Ϸ\\sucai\\6.png" };
	// ��ȡͼƬ����ͼ����
	loadimage(&img, _T("C:\\Users\\kingxue\\Desktop\\��Ϸ\\sucai\\endsbeijing.jpg"));
	putimage(0, 0, &img);
	FlushBatchDraw();
	Sleep(1000);
	for (int i = 0; i < 6; i++)
	{

	}
}
