#pragma once
#pragma comment(lib,"Winmm.lib")
#include"GlobalVar.h"
void LoadStartPage() {
	// ��ȡĬ�ϻ�ͼ���ڵ� HDC ���
	mciSendStringW(L"open music\\EndsPage.mp3 alias jpmusic", NULL, 0, NULL);
	mciSendString(L"play jpmusic repeat", NULL, 0, NULL);

}
