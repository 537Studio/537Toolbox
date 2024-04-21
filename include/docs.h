//这是开发时可能需要使用的函数的文档
//不用引用该文档
//Copyright(C)537 Studio 2023-2024.All rights reserved.

/*
Windows GDI（图形设备接口）提供了丰富的函数用于绘制各种图形和线条。以下是一些常用的绘制函数：

绘制直线：

MoveToEx(hdc, x1, y1, NULL): 将绘图点移动到指定位置。
LineTo(hdc, x2, y2): 从当前绘图点绘制一条直线到指定位置。
绘制矩形：

Rectangle(hdc, left, top, right, bottom): 绘制一个矩形。
绘制圆形：

Ellipse(hdc, left, top, right, bottom): 绘制一个椭圆或圆形。
绘制多边形：

Polygon(hdc, points, numPoints): 绘制一个多边形，points为一个POINT结构数组，numPoints为点的数量。
绘制弧线：

Arc(hdc, left, top, right, bottom, xStart, yStart, xEnd, yEnd): 绘制一个弧线。
绘制贝塞尔曲线：

PolyBezier(hdc, points, numPoints): 绘制一条贝塞尔曲线，points为一个POINT结构数组，numPoints为点的数量。
这些函数可以在WM_PAINT消息中使用，通过获取设备上下文（HDC）并调用相应的绘图函数来绘制所需的图形和线条。您可以根据需要选择合适的函数来绘制不同的图形。

下面是一些常用的设置颜色的函数：

设置文本颜色：

SetTextColor(hdc, RGB(r, g, b)): 设置文本的颜色为RGB(r, g, b)。
设置背景颜色：

SetBkColor(hdc, RGB(r, g, b)): 设置背景的颜色为RGB(r, g, b)。
设置画笔颜色：

SetDCPenColor(hdc, RGB(r, g, b)): 设置画笔的颜色为RGB(r, g, b)。
设置刷子颜色：

SetDCBrushColor(hdc, RGB(r, g, b)): 设置刷子的颜色为RGB(r, g, b)。
这些函数可以在绘制图形之前调用，以设置所绘制图形的颜色。RGB(r, g, b)函数用于创建RGB颜色值，其中r、g、b分别表示红色、绿色和蓝色的值（0-255之间）。

通过设置合适的颜色，您可以为绘制的图形和文本添加丰富多彩的外观。

显示文本的相关函数主要包括TextOut和DrawText等。以下是这些函数的简要介绍：

TextOut：

函数原型：BOOL TextOut(HDC hdc, int x, int y, LPCTSTR lpString, int c)；
功能：在指定的设备上下文（HDC）中绘制文本；
参数：
hdc：目标设备上下文句柄；
x、y：文本的起始坐标；
lpString：要绘制的文本内容；
c：要绘制的字符数；
示例：TextOut(hdc, 100, 100, "Hello, World!", 13);

DrawText：

函数原型：int DrawText(HDC hdc, LPCTSTR lpchText, int nCount, LPRECT lpRect, UINT uFormat)；
功能：在指定的矩形区域内绘制格式化文本；
参数：
hdc：目标设备上下文句柄；
lpchText：要绘制的文本内容；
nCount：要绘制的字符数；
lpRect：指定绘制文本的矩形区域；
uFormat：绘制文本的格式标志；
示例：DrawText(hdc, "Hello, World!", 13, &rc, DT_CENTER | DT_VCENTER);

选择字体：

函数原型：HFONT SelectObject(HDC hdc, HGDIOBJ h)；
功能：在设备上下文中选择指定的字体对象；
参数：
hdc：目标设备上下文句柄；
h：要选择的字体对象句柄；
示例：HFONT hFont = CreateFont(20, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, TEXT("Arial")); SelectObject(hdc, hFont);
以上是一些常用的Windows GDI函数，您可以根据具体需求选择合适的函数来显示文本并选择字体。
*/

// 消息
//
//	类别	    类型				描述
//
//	EX_MOUSE	WM_MOUSEMOVE		鼠标移动 
//				WM_MOUSEWHEEL		鼠标滚轮旋转
//				WM_LBUTTONDOWN		鼠标左键按下 
//				WM_LBUTTONUP		鼠标左键被释放
//				WM_LBUTTONDBLCLK	鼠标左键双击 
//				WM_MBUTTONDOWN		鼠标中键按下 
//				WM_MBUTTONUP		鼠标中键被释放 
//				WM_MBUTTONDBLCLK	鼠标中键双击 
//				WM_RBUTTONDOWN		鼠标右键按下 
//				WM_RBUTTONUP		鼠标右键被释放
//				WM_RBUTTONDBLCLK	鼠标右键双击
//
//	EX_KEY		WM_KEYDOWN			键盘按键按下 
//				WM_KEYUP			键盘按键被释放 
//
//	EX_CHAR		WM_CHAR
//
//	EX_WINDOW	WM_ACTIVATE			窗口已激活或停用
//				WM_MOVE				窗口被移动 
//				WM_SIZE				窗口大小改变


//输入对话框
//在easyx.h内 
bool InputBox(LPTSTR pString, //可以是char string等 
			int nMaxCount, //最大字符长度 
			LPCTSTR pPrompt = NULL,//窗口提示文本 
			LPCTSTR pTitle = NULL, //窗口标题 
			LPCTSTR pDefault = NULL, //输入框默认文本（可能不支持\n符） 
			int width = 0,  //宽 
			int height = 0, //高（高不同将会显示多行输入框） 
			bool bOnlyOK = true //是否只有一个确定按钮（如写false将会显示确定和取消） 
			);
//样例 
char test[400];
InputBox(test,400,"请输入不长于400的文本内容。确切来说你可以写一篇小作文doge","537对话框","这是默认文本，可以修改",640,480,false); 




//直线
void line(
	int x1,
	int y1,
	int x2,
	int y2
);
/*
x1
直线的起始点的 x 坐标。

y1
直线的起始点的 y 坐标。

x2
直线的终止点的 x 坐标。

y2
直线的终止点的 y 坐标。
*/

//圆角矩形 
//在easyx.h内 
void roundrect(//无填充版 
	int left,
	int top,
	int right,
	int bottom,
	int ellipsewidth,
	int ellipseheight
);

void fillroundrect(//填充版 
	int left,
	int top,
	int right,
	int bottom,
	int ellipsewidth,
	int ellipseheight
);
/*
left
圆角矩形左部 x 坐标。

top
圆角矩形顶部 y 坐标。

right
圆角矩形右部 x 坐标。

bottom
圆角矩形底部 y 坐标。

ellipsewidth
构成圆角矩形的圆角的椭圆的宽度。

ellipseheight
构成圆角矩形的圆角的椭圆的高度。
*/
