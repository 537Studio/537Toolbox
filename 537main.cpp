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
	 
	
	
    card1();//����1�ſ�Ƭ
	card2();
	card3();
	card4();
	card5();
	card6();
	
	RECT card1_rect = {400,15,580,120};  // ������ʾ1�ſ�ƬԲ�Ǿ��������RECT�ṹ�����
	RECT card2_rect = {600,15,780,120};
	RECT card3_rect = {400,135,580,240};  // ������ʾԲ�Ǿ��������RECT�ṹ�����
	RECT card4_rect = {600,135,780,240};
	RECT card5_rect = {400,255,580,360};
	RECT card6_rect = {600,255,780,360};
	int button1_mousemode=0,button1_mousemodeex=0;
	int button2_mousemode=0,button2_mousemodeex=0;
	int button3_mousemode=0,button3_mousemodeex=0;
	int button4_mousemode=0,button4_mousemodeex=0;
	int button5_mousemode=0,button5_mousemodeex=0;
	int button6_mousemode=0,button6_mousemodeex=0;
	while (true)
	{
		MOUSEMSG msg = GetMouseMsg();
			POINT pt = {msg.x, msg.y};  // ��ȡ�������
			/*
			ԭ�����£� 
			if (PtInRect(&rect1, pt)){// �ж�����Ƿ���Բ�Ǿ�����
				button1_mousemode=1;//��ͼ���� 
			}else{
				button1_mousemode=0;
			}*/
			PtInRect(&card1_rect, pt)?button1_mousemode=1:button1_mousemode=0;
			PtInRect(&card2_rect, pt)?button2_mousemode=1:button2_mousemode=0;
			PtInRect(&card3_rect, pt)?button3_mousemode=1:button3_mousemode=0;
			PtInRect(&card4_rect, pt)?button4_mousemode=1:button4_mousemode=0;
			PtInRect(&card5_rect, pt)?button5_mousemode=1:button5_mousemode=0;
			PtInRect(&card6_rect, pt)?button6_mousemode=1:button6_mousemode=0;
			
			
			if(button1_mousemode!=button1_mousemodeex){
				//std::cout<<"�����\n";
				if(button1_mousemode==1){
					fillcard1();
					//std::cout<<"�����\n\n";
				}
				else unfillcard1();
				/*
				// ����������(ͨ������������)
				float H = 195;		// ɫ��
				float S = 1;		// ���Ͷ�
				float L = 0.5f;		// ����
				setlinestyle(PS_SOLID, 2);		// �����߿�Ϊ 2
				for(int r = 30; r > 1; r--){
					H += 1;
					setlinecolor(HSLtoRGB(H, S, L));
					circle(500, 480, r);
				
				}
				*/
				button1_mousemodeex=button1_mousemode;
			}
			if(button2_mousemode!=button2_mousemodeex){
				if(button2_mousemode==1){
					fillcard2();
				}
				else unfillcard2();
				button2_mousemodeex=button2_mousemode;
			}
			button3_mousemode!=button3_mousemodeex?(button3_mousemode==1?fillcard3():unfillcard3()),button3_mousemodeex=button3_mousemode:1;
			button4_mousemode!=button4_mousemodeex?(button4_mousemode==1?fillcard4():unfillcard4()),button4_mousemodeex=button4_mousemode:1;
			button5_mousemode!=button5_mousemodeex?(button5_mousemode==1?fillcard5():unfillcard5()),button5_mousemodeex=button5_mousemode:1;
			button6_mousemode!=button6_mousemodeex?(button6_mousemode==1?fillcard6():unfillcard6()),button6_mousemodeex=button6_mousemode:1;
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

