#include <graphics.h>
void card1(){
	setfillcolor(RGB(255,255,255));
	fillroundrect(400, 15, 580, 120, 30, 30);  // ��Բ�Ǿ����������ɫ
	setbkcolor(RGB(255, 255, 255));
	settextcolor(RGB(0,122,255));  // �����ı���ɫΪRGB(0,122,255)
    roundrect(400,15,580,120,30,30);//����Բ�Ǿ���
    outtextxy(450,50, _T("Button1"));  // �ڴ�������ʾ�ı�
}
void fillcard1(){
	setfillcolor(RGB(0,122,255));
	settextcolor(RGB(255,255,255));  // �����ı���ɫΪRGB(0,122,255)
	setbkcolor(RGB(0,122,255));  // ���ñ���ɫΪRGB(0,122,255)
    fillroundrect(400, 15, 580, 120, 30, 30);  // ��Բ�Ǿ����������ɫ
    outtextxy(450,50, _T("Button1"));  // �ڴ�������ʾ�ı�
}
//card2:180*120
//�������600px�����붥��15px�� 
void card2(){
	setfillcolor(RGB(255,255,255));
	fillroundrect(600,15,780,120,30,30);  // ��Բ�Ǿ����������ɫ
	setbkcolor(RGB(255, 255, 255));
	settextcolor(RGB(0,122,255));  // �����ı���ɫΪRGB(0,122,255)
    roundrect(600,15,780,120,30,30);
    outtextxy(650,50, _T("Button2"));  // �ڴ�������ʾ�ı�
}
void fillcard2(){
	setfillcolor(RGB(0,122,255));
	settextcolor(RGB(255,255,255));  // �����ı���ɫΪRGB(0,122,255)
	setbkcolor(RGB(0, 122, 255));  // ���ñ���ɫΪRGB(0,122,255)
    fillroundrect(400, 15, 580, 120, 30, 30);  // ��Բ�Ǿ����������ɫ
    outtextxy(650,50, _T("Button2"));  // �ڴ�������ʾ�ı�
}
