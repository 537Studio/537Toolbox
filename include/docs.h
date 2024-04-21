//���ǿ���ʱ������Ҫʹ�õĺ������ĵ�
//�������ø��ĵ�
//Copyright(C)537 Studio 2023-2024.All rights reserved.

/*
Windows GDI��ͼ���豸�ӿڣ��ṩ�˷ḻ�ĺ������ڻ��Ƹ���ͼ�κ�������������һЩ���õĻ��ƺ�����

����ֱ�ߣ�

MoveToEx(hdc, x1, y1, NULL): ����ͼ���ƶ���ָ��λ�á�
LineTo(hdc, x2, y2): �ӵ�ǰ��ͼ�����һ��ֱ�ߵ�ָ��λ�á�
���ƾ��Σ�

Rectangle(hdc, left, top, right, bottom): ����һ�����Ρ�
����Բ�Σ�

Ellipse(hdc, left, top, right, bottom): ����һ����Բ��Բ�Ρ�
���ƶ���Σ�

Polygon(hdc, points, numPoints): ����һ������Σ�pointsΪһ��POINT�ṹ���飬numPointsΪ���������
���ƻ��ߣ�

Arc(hdc, left, top, right, bottom, xStart, yStart, xEnd, yEnd): ����һ�����ߡ�
���Ʊ��������ߣ�

PolyBezier(hdc, points, numPoints): ����һ�����������ߣ�pointsΪһ��POINT�ṹ���飬numPointsΪ���������
��Щ����������WM_PAINT��Ϣ��ʹ�ã�ͨ����ȡ�豸�����ģ�HDC����������Ӧ�Ļ�ͼ���������������ͼ�κ������������Ը�����Ҫѡ����ʵĺ��������Ʋ�ͬ��ͼ�Ρ�

������һЩ���õ�������ɫ�ĺ�����

�����ı���ɫ��

SetTextColor(hdc, RGB(r, g, b)): �����ı�����ɫΪRGB(r, g, b)��
���ñ�����ɫ��

SetBkColor(hdc, RGB(r, g, b)): ���ñ�������ɫΪRGB(r, g, b)��
���û�����ɫ��

SetDCPenColor(hdc, RGB(r, g, b)): ���û��ʵ���ɫΪRGB(r, g, b)��
����ˢ����ɫ��

SetDCBrushColor(hdc, RGB(r, g, b)): ����ˢ�ӵ���ɫΪRGB(r, g, b)��
��Щ���������ڻ���ͼ��֮ǰ���ã�������������ͼ�ε���ɫ��RGB(r, g, b)�������ڴ���RGB��ɫֵ������r��g��b�ֱ��ʾ��ɫ����ɫ����ɫ��ֵ��0-255֮�䣩��

ͨ�����ú��ʵ���ɫ��������Ϊ���Ƶ�ͼ�κ��ı���ӷḻ��ʵ���ۡ�

��ʾ�ı�����غ�����Ҫ����TextOut��DrawText�ȡ���������Щ�����ļ�Ҫ���ܣ�

TextOut��

����ԭ�ͣ�BOOL TextOut(HDC hdc, int x, int y, LPCTSTR lpString, int c)��
���ܣ���ָ�����豸�����ģ�HDC���л����ı���
������
hdc��Ŀ���豸�����ľ����
x��y���ı�����ʼ���ꣻ
lpString��Ҫ���Ƶ��ı����ݣ�
c��Ҫ���Ƶ��ַ�����
ʾ����TextOut(hdc, 100, 100, "Hello, World!", 13);

DrawText��

����ԭ�ͣ�int DrawText(HDC hdc, LPCTSTR lpchText, int nCount, LPRECT lpRect, UINT uFormat)��
���ܣ���ָ���ľ��������ڻ��Ƹ�ʽ���ı���
������
hdc��Ŀ���豸�����ľ����
lpchText��Ҫ���Ƶ��ı����ݣ�
nCount��Ҫ���Ƶ��ַ�����
lpRect��ָ�������ı��ľ�������
uFormat�������ı��ĸ�ʽ��־��
ʾ����DrawText(hdc, "Hello, World!", 13, &rc, DT_CENTER | DT_VCENTER);

ѡ�����壺

����ԭ�ͣ�HFONT SelectObject(HDC hdc, HGDIOBJ h)��
���ܣ����豸��������ѡ��ָ�����������
������
hdc��Ŀ���豸�����ľ����
h��Ҫѡ��������������
ʾ����HFONT hFont = CreateFont(20, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, TEXT("Arial")); SelectObject(hdc, hFont);
������һЩ���õ�Windows GDI�����������Ը��ݾ�������ѡ����ʵĺ�������ʾ�ı���ѡ�����塣
*/

// ��Ϣ
//
//	���	    ����				����
//
//	EX_MOUSE	WM_MOUSEMOVE		����ƶ� 
//				WM_MOUSEWHEEL		��������ת
//				WM_LBUTTONDOWN		���������� 
//				WM_LBUTTONUP		���������ͷ�
//				WM_LBUTTONDBLCLK	������˫�� 
//				WM_MBUTTONDOWN		����м����� 
//				WM_MBUTTONUP		����м����ͷ� 
//				WM_MBUTTONDBLCLK	����м�˫�� 
//				WM_RBUTTONDOWN		����Ҽ����� 
//				WM_RBUTTONUP		����Ҽ����ͷ�
//				WM_RBUTTONDBLCLK	����Ҽ�˫��
//
//	EX_KEY		WM_KEYDOWN			���̰������� 
//				WM_KEYUP			���̰������ͷ� 
//
//	EX_CHAR		WM_CHAR
//
//	EX_WINDOW	WM_ACTIVATE			�����Ѽ����ͣ��
//				WM_MOVE				���ڱ��ƶ� 
//				WM_SIZE				���ڴ�С�ı�


//����Ի���
//��easyx.h�� 
bool InputBox(LPTSTR pString, //������char string�� 
			int nMaxCount, //����ַ����� 
			LPCTSTR pPrompt = NULL,//������ʾ�ı� 
			LPCTSTR pTitle = NULL, //���ڱ��� 
			LPCTSTR pDefault = NULL, //�����Ĭ���ı������ܲ�֧��\n���� 
			int width = 0,  //�� 
			int height = 0, //�ߣ��߲�ͬ������ʾ��������� 
			bool bOnlyOK = true //�Ƿ�ֻ��һ��ȷ����ť����дfalse������ʾȷ����ȡ���� 
			);
//���� 
char test[400];
InputBox(test,400,"�����벻����400���ı����ݡ�ȷ����˵�����дһƪС����doge","537�Ի���","����Ĭ���ı��������޸�",640,480,false); 




//ֱ��
void line(
	int x1,
	int y1,
	int x2,
	int y2
);
/*
x1
ֱ�ߵ���ʼ��� x ���ꡣ

y1
ֱ�ߵ���ʼ��� y ���ꡣ

x2
ֱ�ߵ���ֹ��� x ���ꡣ

y2
ֱ�ߵ���ֹ��� y ���ꡣ
*/

//Բ�Ǿ��� 
//��easyx.h�� 
void roundrect(//������ 
	int left,
	int top,
	int right,
	int bottom,
	int ellipsewidth,
	int ellipseheight
);

void fillroundrect(//���� 
	int left,
	int top,
	int right,
	int bottom,
	int ellipsewidth,
	int ellipseheight
);
/*
left
Բ�Ǿ����� x ���ꡣ

top
Բ�Ǿ��ζ��� y ���ꡣ

right
Բ�Ǿ����Ҳ� x ���ꡣ

bottom
Բ�Ǿ��εײ� y ���ꡣ

ellipsewidth
����Բ�Ǿ��ε�Բ�ǵ���Բ�Ŀ�ȡ�

ellipseheight
����Բ�Ǿ��ε�Բ�ǵ���Բ�ĸ߶ȡ�
*/
