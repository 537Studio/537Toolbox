#include <graphics.h>
void init(){
	// ���û�ͼɫΪ537�� 
	setlinecolor(RGB(0,122,255));
	setfillcolor(RGB(0,122,255));
	setbkcolor(RGB(255, 255, 255));
	settextstyle(25,0,_T("΢���ź�"));  // ��������ʹ�С
	
	IMAGE image_homeLogo;//������ҳLogo 
	loadimage(&image_homeLogo, _T("images/537Toolbox_Logo_512x512.png"),350,350,false);//��384*384�ֱ��ʼ��أ�ͼƬ����λ�ڸõ�ַ�� 
	putimage(25, 20, &image_homeLogo);//��ʾͼƬ
} 
void about_thisapp(){
	// ���û�ͼɫΪƻ���� 
	setlinecolor(RGB(0,122,255));
	setfillcolor(RGB(0,122,255));
	fillcircle(40,550,20);
}
