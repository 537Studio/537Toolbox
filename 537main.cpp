#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include "about.h"
#include "card.h"
int main(){
	// ��ʼ����ͼ����
	initgraph(800,600);
	// ���ñ�����ɫΪ��ɫ
	setbkcolor(WHITE);
	// �ñ���ɫ�����Ļ
	cleardevice();
	
	// ��ô��ھ��
	HWND hWnd = GetHWnd();
	// ʹ�� Windows API �޸Ĵ�������
	SetWindowText(hWnd, "537������");
	IMAGE image_homeLogo;
	loadimage(&image_homeLogo, _T("images/537Toolbox_Logo_512x512.png"),384,384,false);
	putimage(10, 20, &image_homeLogo);
	// ���û�ͼɫΪ537�� 
	setlinecolor(RGB(0,122,255));
	setfillcolor(RGB(0,122,255));
	roundrect(400,15,580,120,30,30);
	settextstyle(25,0,_T("΢���ź�"));  // ��������ʹ�С
	settextcolor(RGB(0,122,255));  // �����ı���ɫΪRGB(0,122,255)
	setbkcolor(RGB(255, 255, 255));
    outtextxy(440,50, _T("����Test"));  // �ڴ�������ʾ�ı�
	RECT rect = {400, 15, 580, 120};  // ������ʾԲ�Ǿ��������RECT�ṹ�����
	int mousemode=0,mousemodeex=0;
	while (true)
	{
		MOUSEMSG msg = GetMouseMsg();
			POINT pt = {msg.x, msg.y};  // ��ȡ�������
			if (PtInRect(&rect, pt))  // �ж�����Ƿ���Բ�Ǿ�����
			{
				std::cout<<"��⵽�����Բ�Ǿ�����\n";
				mousemode=1;
			}else{
				std::cout<<"��⵽��겻��Բ�Ǿ�����\n";
				mousemode=0;
			}
			std::cout<<"����ѭ��\n"; 
			std::cout<<"mousemode:"<<mousemode<<"\tmousemodeex:"<<mousemodeex<<"\n"; 
			if(mousemode!=mousemodeex){
				std::cout<<"�����\n";
				if(mousemode==1){
					fillcard();
					std::cout<<"�����\n\n";
				}
				else card();
				outtextxy(440,50, _T("����Test"));  // �ڴ�������ʾ�ı�
				mousemodeex=mousemode;
			}
	}

	about_thisapp();
	
	/*
	// �����ַ������������������û�����
	char s[10];
	InputBox(s, 10, "������뾶");

	// ���û�����ת��Ϊ����
	int r = atoi(s);;
	std::cout<<r;
	// ��Բ
	circle(320, 240, r);
	
	// ��������˳�
	_getch();
	closegraph();
	*/
	// ��������˳�
	_getch();
	closegraph();
	return 0;
}

