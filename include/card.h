#include <graphics.h>
#include <windows.h> 
void card1(){
	setfillcolor(RGB(255,255,255));
	fillroundrect(400, 15, 580, 120, 30, 30);  // ��Բ�Ǿ����������ɫ
	setbkcolor(RGB(255, 255, 255));
	settextcolor(RGB(0,122,255));  // �����ı���ɫΪRGB(0,122,255)
    roundrect(400,15,580,120,30,30);//����Բ�Ǿ���
    outtextxy(470,50, _T("ϵͳ"));  // �ڴ�������ʾ�ı�
}
void fillcard1(){
	double r=255.0,g=255.0,b=255.0;
	setfillcolor(RGB(int(r),int(g),int(b)));
	settextcolor(RGB(255,255,255));  // �����ı���ɫΪRGB(0,122,255)
	setbkcolor(RGB(int(r),int(g),int(b)));  // ���ñ���ɫΪRGB(0,122,255)
	double left=400.0,top=15.0,right=580.0,bottom=120.0;
	int ellipsewidth=30,ellipseheight=30;//left-=0.5,top-=0.5,right+=0.5,bottom+=0.5
	for(int i=0;i<51;i++,r-=(255/51),g-=(133/51)){
		setfillcolor(RGB(int(r),int(g),int(b)));
		setbkcolor(RGB(int(r),int(g),int(b)));
		fillroundrect(int(left),int(top),int(right),int(bottom),ellipsewidth,ellipseheight);  // ��Բ�Ǿ����������ɫ
		outtextxy(470,50, _T("ϵͳ"));  // �ڴ�������ʾ�ı�
		Sleep(5); 
	}
    
}
void unfillcard1(){
	double r=0.0,g=122.0,b=255.0;
	setfillcolor(RGB(255,255,255));
	setlinecolor(RGB(255,255,255));
	setbkcolor(RGB(255, 255, 255));
	fillroundrect(380,0,600,135,30,30);  // ��Բ�Ǿ����������ɫ
	setlinecolor(RGB(0,122,255));
	settextcolor(RGB(0,122,255));  // �����ı���ɫΪRGB(0,122,255)
	outtextxy(470,50, _T("ϵͳ"));  // �ڴ�������ʾ�ı�
	/*
	double left=390.0,top=5.0,right=590.0,bottom=130.0;
	int ellipsewidth=30,ellipseheight=30;//left+=0.5,top+=0.5,right-=0.5,bottom-=0.5
	*/
	double left=400.0,top=15.0,right=580.0,bottom=120.0;
	int ellipsewidth=30,ellipseheight=30;
	for(int i=0;i<51;i++,r+=(255/51),g+=(133/51)){
		setfillcolor(RGB(int(r),int(g),int(b)));
		setbkcolor(RGB(int(r),int(g),int(b)));
		setlinecolor(RGB(0,122,255));
		fillroundrect(int(left-0.5),int(top-0.5),int(right+0.5),int(bottom+0.5),30,30);
		
		roundrect(int(left),int(top),int(right),int(bottom),ellipsewidth,ellipseheight);  // ��Բ�Ǿ����������ɫ
		
		outtextxy(470,50, _T("ϵͳ"));
		
		Sleep(5); 
	}
    //roundrect(400,15,580,120,30,30);//����Բ�Ǿ���
    init();
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
void unfillcard2(){
	setfillcolor(RGB(255,255,255));
	fillroundrect(600,15,780,120,30,30);  // ��Բ�Ǿ����������ɫ
	setbkcolor(RGB(255, 255, 255));
	settextcolor(RGB(0,122,255));  // �����ı���ɫΪRGB(0,122,255)
    roundrect(600,15,780,120,30,30);
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
void unfillcard3(){
	setfillcolor(RGB(255,255,255));
	fillroundrect(400,135,580,240,30,30);  // ��Բ�Ǿ����������ɫ
	setbkcolor(RGB(255, 255, 255));
	settextcolor(RGB(0,122,255));  // �����ı���ɫΪRGB(0,122,255)
    roundrect(400,135,580,240,30,30);
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
void unfillcard4(){
	setfillcolor(RGB(255,255,255));
	fillroundrect(600,135,780,240,30,30);  // ��Բ�Ǿ����������ɫ
	setbkcolor(RGB(255, 255, 255));
	settextcolor(RGB(0,122,255));  // �����ı���ɫΪRGB(0,122,255)
    roundrect(600,135,780,240,30,30);
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
void unfillcard5(){
	setfillcolor(RGB(255,255,255));
	fillroundrect(400,255,580,360,30,30);  // ��Բ�Ǿ����������ɫ
	setbkcolor(RGB(255, 255, 255));
	settextcolor(RGB(0,122,255));  // �����ı���ɫΪRGB(0,122,255)
    roundrect(400,255,580,360,30,30);
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
void unfillcard6(){
	setfillcolor(RGB(255,255,255));
	fillroundrect(600,255,780,360,30,30);  // ��Բ�Ǿ����������ɫ
	setbkcolor(RGB(255, 255, 255));
	settextcolor(RGB(0,122,255));  // �����ı���ɫΪRGB(0,122,255)
    roundrect(600,255,780,360,30,30);
    outtextxy(670,290, _T("����"));  // �ڴ�������ʾ�ı�
}
