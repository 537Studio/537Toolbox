#include <windows.h>
#define APP_VERSION	1.0

struct MOUSE{
	int x;
	int y;
}mouse;

struct SYSTEM_IMFORMATION{
	int arrange;//系统排列最小化窗口的方式 
	int cleanboot;//系统启动方式：0为正常启动，1为安全方式，2为安全方式且有网络功能
	int cmonitors;//在WindowsNT5.0中指定监视器的数量
	int cmousebuttons;//鼠标上按钮的个数，0表示没有安装鼠标 
	int cxborder;//窗口边框的宽度（以像素为单位）。在3D显示方式下该值与cxedge相同
	int cyborder;//窗口边框的高度。同上。
	int cxcursor;//鼠标宽度（以像素为单位）
	int cycursor;//鼠标高度（以像素为单位）
	int cxdlgframe;//和cxfixedflame相同
	int cydlgframe;//和cyfixedflame相同
	int cxdoubleclk;//鼠标双击时矩形的宽度
	int cydoubleclk;//鼠标双击时矩形的高度
	int cxdrag;//非拖放操作矩形的宽度
	int cydrag;//非拖放操作矩形的高度
	int cxedge;//3D方式的窗口边框宽度，与一般窗口的cxborder对应
	int cyedge;//3D方式的窗口边框高度，与一般窗口的cyborder对应
	int cxfullscreen;//屏幕宽度
	int cyfullscreen;//屏幕高度
	/* TODO (Sean537#1#): 添加更多变量 */
	
	int swapbutton;//指定系统是否交换了鼠标的左右键功能。非0表示交换，0表示未交换 
	
	char computername[128];//系统名称 
}sys;
