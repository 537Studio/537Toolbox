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
	card3();
	card4();
	card5();
	card6();
	 
	RECT rect1 = {400,15,580,120};  // ������ʾ1�ſ�ƬԲ�Ǿ��������RECT�ṹ�����
	RECT rect2 = {600,15,780,120};
	RECT rect3 = {400,135,580,240};  // ������ʾԲ�Ǿ��������RECT�ṹ�����
	RECT rect4 = {600,135,780,240};
	RECT rect5 = {400,255,580,360};
	RECT rect6 = {600,255,780,360};
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
			if (PtInRect(&rect1, pt)){// �ж�����Ƿ���Բ�Ǿ�����
				button1_mousemode=1;//��ͼ���� 
			}else{
				button1_mousemode=0;
			}
			
			if (PtInRect(&rect2, pt)){
				button2_mousemode=1;
			}else{
				button2_mousemode=0;
			}
			
			if (PtInRect(&rect3, pt)){
				button3_mousemode=1;
			}else{
				button3_mousemode=0;
			}
			
			if (PtInRect(&rect4, pt)){
				button4_mousemode=1;
			}else{
				button4_mousemode=0;
			}
			
			if (PtInRect(&rect5, pt)){
				button5_mousemode=1;
			}else{
				button5_mousemode=0;
			}
			
			if (PtInRect(&rect6, pt)){
				button6_mousemode=1;
			}else{
				button6_mousemode=0;
			}
			
			
			if(button1_mousemode!=button1_mousemodeex){
				//std::cout<<"�����\n";
				if(button1_mousemode==1){
					fillcard1();
					//std::cout<<"�����\n\n";
				}
				else card1();
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
				else card2();
				button2_mousemodeex=button2_mousemode;
			}
			if(button3_mousemode!=button3_mousemodeex){
				if(button3_mousemode==1){
					fillcard3();
				}
				else card3();
				button3_mousemodeex=button3_mousemode;
			}
			if(button4_mousemode!=button4_mousemodeex){
				if(button4_mousemode==1){
					fillcard4();
				}
				else card4();
				button4_mousemodeex=button4_mousemode;
			}
			if(button5_mousemode!=button5_mousemodeex){
				if(button5_mousemode==1){
					fillcard5();
				}
				else card5();
				button5_mousemodeex=button5_mousemode;
			}
			if(button6_mousemode!=button6_mousemodeex){
				if(button6_mousemode==1){
					fillcard6();
				}
				else card6();
				button6_mousemodeex=button6_mousemode;
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

