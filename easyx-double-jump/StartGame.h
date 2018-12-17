#pragma once

#include <string.h>
#include <time.h>
#include<math.h>
//#include"Character.h"
#pragma comment(lib,"Winmm.lib")
void StartPageUpdateWithInput();
void StartPageUpdateWithoutInput();
void ScandFangKuai();
void PrintGeZI();
void UpdateWeizhi();
void PrintScord();

IMAGE bkGround;
character my_character;
IMAGE diban;
int Record[2] = {0,19}; //��һ�����ּ�¼��λ�������ȣ��ڶ�����¼�Ϸ�����


int CheakContact() {		//�������������Ƿ�����ײ
	for (int i = 0; i < 80 && my_character.status; i++)
	{
		if (gezi[i].alive&&gezi[i].y >= 0)
		{
			if ((my_character.y + 58 >= gezi[i].y) && (my_character.y + 58 <= gezi[i].y + 17) && ((my_character.x + 6 > gezi[i].x&&my_character.x + 6 < gezi[i].x + 54) || (my_character.x + 45 > gezi[i].x&&my_character.x + 45 < gezi[i].x + 54)))
			{
				my_character.status = 0;
				return 1;
			}
		}

	}
	return 0;
}

void StartPageInit() {			//ҳ����س�ʼ��
	loadimage(&diban, L"source\\use-images\\normal.png", 60, 17, true);  //���ظ���ͼƬ
	IMAGE loading;
	memset(gezi, 30, sizeof(fangkuai)); //��ʼ����ո�������
	setbkcolor(RGB(247, 240, 233));
	clearrectangle(0, 0, WIDTH, HEIGHT);
	for (int i = 0; i < 1; i++)				//���ؽ�����������
	{
		loadimage(&loading, _T("source\\newimg\\loading1.png"));
		putimage(150, 250, &loading);
		FlushBatchDraw();
		Sleep(1000);

		loadimage(&loading, _T("source\\newimg\\loading2.png"));
		putimage(150, 250, &loading);
		FlushBatchDraw();
		Sleep(1000);

		loadimage(&loading, _T("source\\newimg\\loading3.png"));
		putimage(150, 250, &loading);
		FlushBatchDraw();
		Sleep(1000);
	}
	loadimage(&bkGround, L"source\\use-images\\store_bg.png");  //���ر���

	loadimage(&my_character.character, L"source\\newimg\\bunny\\rs.png");
	ScandFangKuai();     //��ʼ���������λ��
}

void StartGame() {    //��Ϸѭ��
	StartPageInit();     //��Ϸ���г�ʼ��
	while (my_character.alive)      //����������Ϸѭ������
	{
		StartPageUpdateWithInput();   //������ش���
		StartPageUpdateWithoutInput();			//�����޹صĴ���
	}
	running = 0;			//��Ϸѭ��ֹͣ��ȫ�ֱ���ѭ��״̬��Ϊ0 false
}

void StartPageUpdateWithInput() {

	if (kbhit()) // ̽���û��Ƿ�������
	{
		char ch_temp = _getch();				//AD�����ƶ�
		if (my_character.x + 60 <= WIDTH && my_character.x >= -2)            //����������ƶ�  ������������ƶ�
		{
			if (ch_temp == 'A' || ch_temp == 'a')
				for (int i = 0; i < 3; i++)
				{
					my_character.x -= 1; // ���ƶ�
					FlushBatchDraw();
				}
			if (ch_temp == 'D' || ch_temp == 'd')
				for (int i = 0; i < 3; i++)
				{
					my_character.x += 1; // ���ƶ�
					FlushBatchDraw();
				}
			if (my_character.x + 60 > WIDTH)
				my_character.x = WIDTH - 60;
			if (my_character.x < 0)
				my_character.x = 0;
		}
	}

}

void StartPageUpdateWithoutInput() {

	if (my_character.y<HEIGHT/2)		//����λ�ô�����Ļ1/2λ�ã�����Ļ����
	{
		UpdateWeizhi();
	}

	if (!CheakContact() && my_character.status)			//������ﴦ�����µ���״̬��status��������������ײ���Ϊ�٣������������ƶ��������˼��ٶ��㷨��ʹ
	{
		if (my_character.volocity < 6)
			my_character.volocity += 0.3;
		my_character.y += my_character.volocity;
	}
	else				//�������������ƶ����������ٴ����ﵽ��ߴ���״̬�ı�
	{
		my_character.y -= my_character.volocity;
		my_character.volocity -= 0.3;
		if (my_character.volocity <= 0)
		{
			my_character.volocity = 6;
			my_character.status = 1;
		}
	}
	putimage(0, 0, &bkGround);				//���ر���
	PrintGeZI();						//��ӡ����
	putimage(my_character.x, my_character.y, &my_character.character, SRCAND);		//��������
	PrintScord();						//��ӡ������
	FlushBatchDraw();			//������ˢ��

	if (my_character.y > HEIGHT )  //���������Ļ������������
	{
		my_character.alive = false;
	}
	Sleep(15);
}
void ScandFangKuai() {     //��ʼ�����ӣ���������أ��������Ӳ��ص����ص����������
	srand(time(NULL));
	int temp = 0;
	for (int i = 0; i < 20; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			gezi[temp].x = 100 * k + rand() % 100;
			gezi[temp].y = 60 * i + rand() % 60-HEIGHT;
			while (i > 0 && (gezi[temp].y - gezi[temp - 4].y < 17|| abs(gezi[temp].x - gezi[temp - 1].x) < 60))
			{
				gezi[temp].x = 100 * k + rand() % 100;
				gezi[temp].y = 60 * i + rand() % 60-HEIGHT;
			}
			gezi[temp].alive = 1;
			temp++;
		}
	}
}
void UpdateWeizhi() {			//���һ�ŵĸ���λ�õ�����Ļ�����������Ϊ��һ�ŵĸ��ӣ����¸���λ��
		Record[0] += 3;
		my_character.y += 3;
	
		for (int i = 0; i < 80; i++)
		{
			gezi[i].y += 3;

		}
		if (Record[0]>=60)
		{
			score++;
			for (int i = 0; i < 4; i++)
			{
				int temp = Record[1]*4 + i;
				gezi[temp].x = i*100 + rand() % 100;
				gezi[temp].y = rand() % 60 - HEIGHT;
				while ( i>0&&(abs(gezi[temp].x - gezi[temp - 1].x) < 60))
				{
					gezi[temp].x = i * 100 + rand() % 100;
				}
			}
			Record[1] = (Record[1]+19)%20;
			Record[0] = 0;
		}
}
void PrintGeZI() {		//��ӡ����ʮ������
	for (int i = 0; i < 80; i++)
	{
		if (gezi[i].y > 10)
		{
			putimage(gezi[i].x, gezi[i].y, &diban, SRCAND);
		}

	}
}
void PrintScord() {			//��ӡ�����壬��δʵ��͸��
	TCHAR  a[20];
	LOGFONT f;
	gettextstyle(&f);                     // ��ȡ��ǰ��������
	settextcolor(BLACK);
	f.lfHeight = 30;                      // ��������߶�Ϊ 48
	_tcscpy(f.lfFaceName, _T("����"));    // ��������Ϊ�����塱(�߰汾 VC �Ƽ�ʹ�� _tcscpy_s ����)
	f.lfQuality = ANTIALIASED_QUALITY;    // �������Ч��Ϊ�����  
	settextstyle(&f);                     // ����������ʽ

	wsprintf(a,L"Scorce:%d", score);
	outtextxy(0,0,a);
	
}