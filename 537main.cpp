#include <iostream>
#include <windows.h>
#include <graphics.h>
#include <conio.h>
#include "include\about.h"
#include "include\card.h"
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
	init();//��ʼ��
	 
	IMAGE image_homeLogo;//������ҳLogo 
	loadimage(&image_homeLogo, _T("images/537Toolbox_Logo_512x512.png"),384,384,false);//��384*384�ֱ��ʼ��أ�ͼƬ����λ�ڸõ�ַ�� 
	putimage(10, 20, &image_homeLogo);//��ʾͼƬ 
	
	
    card1();//����1�ſ�Ƭ
	card2();
	 
	RECT rect1 = {400, 15, 580, 120};  // ������ʾ1�ſ�ƬԲ�Ǿ��������RECT�ṹ�����
	RECT rect2 = {600, 15, 780, 120};  // ������ʾԲ�Ǿ��������RECT�ṹ�����
	int button1_mousemode=0,button1_mousemodeex=0;
	int button2_mousemode=0,button2_mousemodeex=0;
	while (true)
	{
		MOUSEMSG msg = GetMouseMsg();
			POINT pt = {msg.x, msg.y};  // ��ȡ�������
			if (PtInRect(&rect1, pt))  // �ж�����Ƿ���Բ�Ǿ�����
			{
				//std::cout<<"��⵽�����Բ�Ǿ�����\n";
				button1_mousemode=1;
			}else{
				//std::cout<<"��⵽��겻��Բ�Ǿ�����\n";
				button1_mousemode=0;
			}
			std::cout<<"����ѭ��\n"; 
			std::cout<<"button1_mousemode:"<<button1_mousemode<<"\tbutton1_mousemodeex:"<<button1_mousemodeex<<"\n"; 
			if(button1_mousemode!=button1_mousemodeex){
				std::cout<<"�����\n";
				if(button1_mousemode==1){
					fillcard1();
					std::cout<<"�����\n\n";
				}
				else card1();
				
				button1_mousemodeex=button1_mousemode;
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

