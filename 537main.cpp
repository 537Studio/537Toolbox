#include <windows.h>
#include <ShellAPI.h>
#include <string>


NOTIFYICONDATA nid;
HMENU hPopupMenu;

char AppClassName[] = "537Toolbox";
HINSTANCE g_hInst;
HWND g_hMainWindow;
HBITMAP hBitmap;

int WIN_WIDTH = 800,WIN_HEIGHT = 600;

// 获取屏幕尺寸
int screenWidth = GetSystemMetrics(SM_CXSCREEN);//屏幕宽 
int screenHeight = GetSystemMetrics(SM_CYSCREEN);//屏幕高 

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    	case WM_SIZE:
        	WIN_WIDTH = LOWORD(lParam);
        	WIN_HEIGHT = HIWORD(lParam);
        	break;
    	case WM_GETMINMAXINFO: {
    		//窗口尺寸不小于640*480 
        	MINMAXINFO* lpMMI = (MINMAXINFO*)lParam;
        	lpMMI->ptMinTrackSize.x = 640;
        	lpMMI->ptMinTrackSize.y = 480;
        	break;    
    	}
    	
        case WM_CREATE:
            // 创建系统托盘图标
            nid.cbSize = sizeof(NOTIFYICONDATA);
            nid.hWnd = hwnd;
            nid.uID = 1;
            nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
            nid.uCallbackMessage = WM_USER + 1;
            nid.hIcon = LoadIcon(g_hInst,"A");
            lstrcpy(nid.szTip, AppClassName);
            Shell_NotifyIcon(NIM_ADD, &nid);

            // 创建右键菜单
            hPopupMenu = CreatePopupMenu();
            AppendMenu(hPopupMenu, MF_STRING, 1, "打开");
            AppendMenu(hPopupMenu, MF_SEPARATOR, 0, NULL);
            AppendMenu(hPopupMenu, MF_STRING, 2, "首页");
            AppendMenu(hPopupMenu, MF_STRING, 3, "系统");
            AppendMenu(hPopupMenu, MF_STRING, 4, "网络");
            AppendMenu(hPopupMenu, MF_STRING, 5, "存储");
            AppendMenu(hPopupMenu, MF_STRING, 6, "文件");
            AppendMenu(hPopupMenu, MF_STRING, 7, "更多");
            AppendMenu(hPopupMenu, MF_SEPARATOR, 0, NULL);
            AppendMenu(hPopupMenu, MF_STRING, 8, "帮助");
            AppendMenu(hPopupMenu, MF_STRING, 9, "更新");
            AppendMenu(hPopupMenu, MF_STRING, 10, "关于");
            AppendMenu(hPopupMenu, MF_STRING, 11, "退出");
            // 加载软件图标
            hBitmap = LoadBitmap(GetModuleHandle(NULL),"A");
            break;
        case WM_COMMAND:
        	switch(LOWORD(wParam)){
        		case 1:
        			// 打开操作
                	ShowWindow(g_hMainWindow,1);
					UpdateWindow(g_hMainWindow);
                	break;
                case 2:
                	//打开首页
                	MessageBox(hwnd, "按下了托盘“首页”按钮", "提示", MB_OK+64);
                	break;
				case 3:
					//打开系统面板
					MessageBox(hwnd, "按下了托盘“系统”按钮", "提示", MB_OK+64);
					break;
				case 4:
					//打开网络面板
					MessageBox(hwnd, "按下了托盘“网络”按钮", "提示", MB_OK+64);
					break;
				case 5:
					//打开存储面板	 
					MessageBox(hwnd, "按下了托盘“存储”按钮", "提示", MB_OK+64);
					break;
				case 6:
					//打开文件面板
					MessageBox(hwnd, "按下了托盘“文件”按钮", "提示", MB_OK+64);
					break;
				case 7:
					//打开更多面板
					MessageBox(hwnd, "按下了托盘“更多”按钮", "提示", MB_OK+64);
					break;
				case 8:
					//打开帮助面板
					ShellExecute(hwnd,"open","https://www.537studio.com/help",NULL,NULL,SW_SHOWNORMAL);
					break;
				case 9:
					//打开更新窗口 
					ShellExecute(hwnd,"open","update.exe",NULL,NULL,SW_SHOWNORMAL);
					break;
				case 10:
					//打开关于窗口 
					ShellAbout(hwnd, "537工具箱", "537工具箱	版本1.0(Beta)\n537工作室版权所有。该版本为内测版本，非内部人员请勿使用。", NULL);
					break;
				case 11:
                	// 退出操作
                	DestroyWindow(hwnd);
                default:
                	break;
        	}
            break;
        case WM_USER + 1:
            // 处理托盘图标的消息
            switch (lParam) {
                case WM_RBUTTONDOWN:
        		case WM_CONTEXTMENU:
            		POINT pt;
           		 	GetCursorPos(&pt);
           			SetForegroundWindow(hwnd);
            		TrackPopupMenu(hPopupMenu, TPM_RIGHTBUTTON, pt.x, pt.y, 0, hwnd, NULL);
            		break;
        		case WM_MOUSEMOVE:
            		Shell_NotifyIcon(NIM_MODIFY, &nid);
            		break;
        		case WM_LBUTTONDOWN:
            		// 单击托盘图标打开软件
            		MessageBox(hwnd, "点击了托盘图标", "提示", MB_OK+64);
           		 	break;
           		}
            	break;
        case WM_PAINT:
            {
                
				PAINTSTRUCT ps;
                HDC hdc = BeginPaint(hwnd, &ps);
                // 设置背景色为黑色
                SetBkColor(hdc, RGB(0, 0, 0));
                HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 0));
                FillRect(hdc, &ps.rcPaint, hBrush);
                DeleteObject(hBrush);
                
                SetBkMode(hdc, TRANSPARENT);

                // 绘制白色圆形
                HBRUSH hWhiteBrush = CreateSolidBrush(RGB(255, 255, 255));
                SelectObject(hdc, hWhiteBrush);
                Ellipse(hdc, 200, 200, 400, 400);
				
				HBRUSH hFTSBlueBrush = CreateSolidBrush(RGB(20, 126, 255));
				SelectObject(hdc, hFTSBlueBrush);
                // 绘制蓝色矩形
                Rectangle(hdc, 500, 200, 700, 400);
                
                // 创建字体
    			HFONT hFont = CreateFont(300, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "analogue.ttf");
    			SelectObject(hdc, hFont);
				
    			// 设置文本颜色
    			SetTextColor(hdc, RGB(255, 255, 255));

    			// 显示文本
    			TextOut(hdc, 100, 100, "Hello world!", 12);
            	// 释放资源
    			DeleteObject(hFont);
    			ReleaseDC(NULL, hdc);
                EndPaint(hwnd, &ps);
            }
            break;
        case WM_DESTROY:
            // 移除系统托盘图标
            Shell_NotifyIcon(NIM_DELETE, &nid);
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	
	WNDCLASSEX WndClassEx;
	
	g_hInst = hInstance;
	
	WndClassEx.cbSize          = sizeof(WNDCLASSEX);
	WndClassEx.style           = CS_HREDRAW | CS_VREDRAW;
	WndClassEx.lpfnWndProc     = WndProc;
	WndClassEx.cbClsExtra      = 0;
	WndClassEx.cbWndExtra      = 0;
	WndClassEx.hInstance       = hInstance;
	WndClassEx.hIcon           = LoadIcon(hInstance, "A");
	WndClassEx.hCursor         = LoadCursor(hInstance, IDC_ARROW);
	WndClassEx.hbrBackground   = (HBRUSH)(COLOR_3DSHADOW+1);
	WndClassEx.lpszClassName   = g_szAppName;
	WndClassEx.hIconSm         = LoadIcon(hInstance,"A");
	
	if(!RegisterClassEx(&WndClassEx)) {
		MessageBox(0, "无法注册窗口。请检查系统环境是否正常或寻求技术帮助。", "错误",MB_ICONEXCLAMATION | MB_OK);
		return -1;
	}

    // 计算窗口左上角坐标使其位于屏幕中心
    int init_x = (screenWidth - WIN_WIDTH) / 2;
    int init_y = (screenHeight - WIN_HEIGHT) / 2;
    
	g_hMainWindow = CreateWindowEx(WS_EX_APPWINDOW,AppClassName,"537工具箱",WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN,
		init_x,
		init_y,
		WIN_WIDTH,
		WIN_HEIGHT,
		0, 0, hInstance, NULL);

	if (g_hMainWindow == NULL){
		MessageBox(0, "无窗口。请检查系统环境是否正常或寻求技术帮助。", "错误", MB_ICONEXCLAMATION | MB_OK);
		return -1;
	}

	ShowWindow(g_hMainWindow, nCmdShow);
	UpdateWindow(g_hMainWindow);
	/*
	
    HWND hwnd = CreateWindow("Win32Window", "Win32 Window", WS_OVERLAPPEDWINDOW, 100, 100, 800, 600, NULL, NULL, hInstance, NULL);

    // 显示窗口
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
*/
    // 消息循环
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}

