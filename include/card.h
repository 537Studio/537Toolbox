#include <graphics.h>
/*
���˺�ɫRGB(216,19,29)
�ײ���ɫRGB(241,168,35)
���½��� 
����仯��G-5 B-5 

������ɫRGB(255,255,255) 
ѡ����ɫRGB(1,182,19) 
*/

/*
void card1(){
	setfillcolor(RGB(255,255,255));
	fillroundrect(400, 15, 580, 120, 30, 30);  // ��Բ�Ǿ����������ɫ
	setbkcolor(RGB(255, 255, 255));
	settextcolor(RGB(0,122,255));  // �����ı���ɫΪRGB(0,122,255)
    roundrect(400,15,580,120,30,30);//����Բ�Ǿ���
    outtextxy(470,50, _T("ϵͳ"));  // �ڴ�������ʾ�ı�
}
void fillcard1(){
	setfillcolor(RGB(0,122,255));
	settextcolor(RGB(255,255,255));  // �����ı���ɫΪRGB(0,122,255)
	setbkcolor(RGB(0,122,255));  // ���ñ���ɫΪRGB(0,122,255)
    fillroundrect(400, 15, 580, 120, 30, 30);  // ��Բ�Ǿ����������ɫ
    outtextxy(470,50, _T("ϵͳ"));  // �ڴ�������ʾ�ı�
}
//card2:280*105
//�������600px�����붥��15px�� 
void card2(){
	setfillcolor(RGB(255,255,255));
	fillroundrect(600,15,780,120,30,30);  // ��Բ�Ǿ����������ɫ
	setbkcolor(RGB(255, 255, 255));
	settextcolor(RGB(0,122,255));  // �����ı���ɫΪRGB(0,122,255)
    roundrect(600,15,780,120,30,30);
    outtextxy(670,50, _T("����"));  // �ڴ�������ʾ�ı�
}
void fillcard2(){
	setfillcolor(RGB(0,122,255));
	settextcolor(RGB(255,255,255));  // �����ı���ɫΪRGB(0,122,255)
	setbkcolor(RGB(0,122,255));  // ���ñ���ɫΪRGB(0,122,255)
    fillroundrect(600,15,780,120,30,30);  // ��Բ�Ǿ����������ɫ
    outtextxy(670,50, _T("����"));  // �ڴ�������ʾ�ı�
}
void card3(){
	setfillcolor(RGB(255,255,255));
	fillroundrect(400,135,580,240,30,30);  // ��Բ�Ǿ����������ɫ
	setbkcolor(RGB(255, 255, 255));
	settextcolor(RGB(0,122,255));  // �����ı���ɫΪRGB(0,122,255)
    roundrect(400,135,580,240,30,30);
    outtextxy(470,170, _T("����"));  // �ڴ�������ʾ�ı�
}
void fillcard3(){
	setfillcolor(RGB(0,122,255));
	settextcolor(RGB(255,255,255));  // �����ı���ɫΪRGB(0,122,255)
	setbkcolor(RGB(0,122,255));  // ���ñ���ɫΪRGB(0,122,255)
    fillroundrect(400,135,580,240,30,30);  // ��Բ�Ǿ����������ɫ
    outtextxy(470,170, _T("����"));  // �ڴ�������ʾ�ı�
}
void card4(){
	setfillcolor(RGB(255,255,255));
	fillroundrect(600,135,780,240,30,30);  // ��Բ�Ǿ����������ɫ
	setbkcolor(RGB(255, 255, 255));
	settextcolor(RGB(0,122,255));  // �����ı���ɫΪRGB(0,122,255)
    roundrect(600,135,780,240,30,30);
    outtextxy(670,170, _T("�ļ�"));  // �ڴ�������ʾ�ı�
}
void fillcard4(){
	setfillcolor(RGB(0,122,255));
	settextcolor(RGB(255,255,255));  // �����ı���ɫΪRGB(0,122,255)
	setbkcolor(RGB(0,122,255));  // ���ñ���ɫΪRGB(0,122,255)
    fillroundrect(600,135,780,240,30,30);  // ��Բ�Ǿ����������ɫ
    outtextxy(670,170, _T("�ļ�"));  // �ڴ�������ʾ�ı�
}
void card5(){
	setfillcolor(RGB(255,255,255));
	fillroundrect(400,255,580,360,30,30);  // ��Բ�Ǿ����������ɫ
	setbkcolor(RGB(255, 255, 255));
	settextcolor(RGB(0,122,255));  // �����ı���ɫΪRGB(0,122,255)
    roundrect(400,255,580,360,30,30);
    outtextxy(470,290, _T("����"));  // �ڴ�������ʾ�ı�
}
void fillcard5(){
	setfillcolor(RGB(0,122,255));
	settextcolor(RGB(255,255,255));  // �����ı���ɫΪRGB(0,122,255)
	setbkcolor(RGB(0,122,255));  // ���ñ���ɫΪRGB(0,122,255)
    fillroundrect(400,255,580,360,30,30);  // ��Բ�Ǿ����������ɫ
    outtextxy(470,290, _T("����"));  // �ڴ�������ʾ�ı�
}
void card6(){
	setfillcolor(RGB(255,255,255));
	fillroundrect(600,255,780,360,30,30);  // ��Բ�Ǿ����������ɫ
	setbkcolor(RGB(255, 255, 255));
	settextcolor(RGB(0,122,255));  // �����ı���ɫΪRGB(0,122,255)
    roundrect(600,255,780,360,30,30);
    outtextxy(670,290, _T("����"));  // �ڴ�������ʾ�ı�
}
void fillcard6(){
	setfillcolor(RGB(0,122,255));
	settextcolor(RGB(255,255,255));  // �����ı���ɫΪRGB(0,122,255)
	setbkcolor(RGB(0,122,255));  // ���ñ���ɫΪRGB(0,122,255)
    fillroundrect(600,255,780,360,30,30);  // ��Բ�Ǿ����������ɫ
    outtextxy(670,290, _T("����"));  // �ڴ�������ʾ�ı�
}
*/
