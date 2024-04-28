#include <windows.h>
#include <ShellAPI.h>
#include <string>
#include <mmsystem.h>
#include "include/about.h"
#include "include/card.h"
#include "include/music.h"
#include "include/settings.h"
#pragma comment(lib, "winmm.lib") // ʹ�����ֲ��ſ���Ҫ����-lwinmm 

NOTIFYICONDATA nid;
HMENU hPopupMenu;

char AppClassName[] = "537Toolbox";

HINSTANCE g_hInst;
HWND g_hMainWindow;
HBITMAP hBitmap;

int WIN_WIDTH = 800,WIN_HEIGHT = 600;

// ��ȡ��Ļ�ߴ�
int screenWidth = GetSystemMetrics(SM_CXSCREEN);//��Ļ�� 
int screenHeight = GetSystemMetrics(SM_CYSCREEN);//��Ļ�� 

// ���㴰�����Ͻ�����ʹ��λ����Ļ����
int init_x=(screenWidth-WIN_WIDTH)/2;
int init_y=(screenHeight-WIN_HEIGHT)/2;
    
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    	case WM_SIZE:
        	WIN_WIDTH = LOWORD(lParam);
        	WIN_HEIGHT = HIWORD(lParam);
        	break;
    	case WM_GETMINMAXINFO: {
    		//���ڳߴ粻С��640*480 
        	MINMAXINFO* lpMMI = (MINMAXINFO*)lParam;
        	lpMMI->ptMinTrackSize.x = 640;
        	lpMMI->ptMinTrackSize.y = 480;
        	break;    
    	}
    	
        case WM_CREATE:
            // ����ϵͳ����ͼ��
            nid.cbSize = sizeof(NOTIFYICONDATA);
            nid.hWnd = hwnd;
            nid.uID = 1;
            nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
            nid.uCallbackMessage = WM_USER + 1;
            nid.hIcon = LoadIcon(g_hInst,"A");
            lstrcpy(nid.szTip, AppClassName);
            Shell_NotifyIcon(NIM_ADD, &nid);

            // �����Ҽ��˵�
            hPopupMenu = CreatePopupMenu();
            AppendMenu(hPopupMenu, MF_STRING, 1, "��");
            AppendMenu(hPopupMenu, MF_SEPARATOR, 0, NULL);
            AppendMenu(hPopupMenu, MF_STRING, 2, "����");
            AppendMenu(hPopupMenu, MF_STRING, 3, "����");
            AppendMenu(hPopupMenu, MF_STRING, 4, "����");
            AppendMenu(hPopupMenu, MF_SEPARATOR, 0, NULL);
            AppendMenu(hPopupMenu, MF_STRING, 5, "�˳�");
            // �������ͼ��
            hBitmap = LoadBitmap(g_hInst,"A");
            break;
        case WM_COMMAND:
        	switch(LOWORD(wParam)){
        		case 1:
        			// �򿪲���
                	ShowWindow(g_hMainWindow,1);
					UpdateWindow(g_hMainWindow);
                	break;
                case 2:
                	//�򿪰������
					ShellExecute(hwnd,"open","https://www.537studio.com/help",NULL,NULL,SW_SHOWNORMAL);
					break;
					/*
                	//����ҳ
                	mciSendString("play audio/537Welcome.mp3",NULL,0,hwnd); //��������  
                	break;
                	*/
				case 3:
					//�򿪸��´��� 
					ShellExecute(hwnd,"open","update.exe",NULL,NULL,SW_SHOWNORMAL);
					break;
				case 4:
					//�򿪹��ڴ��� 
					ShellAbout(hwnd, "537������", "537������	�汾1.0(Beta)\n537�����Ұ�Ȩ���С��ð汾Ϊ�ڲ�汾�����ڲ���Ա����ʹ�á�", NULL);
					break;
				case 5:
					// �˳�����
                	DestroyWindow(hwnd);
                	break;
				default:
                	break;
        	}
            break;
        case WM_USER + 1:
            // ��������ͼ�����Ϣ
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
            		// ��������ͼ������
            		ShowWindow(g_hMainWindow,1);
					UpdateWindow(g_hMainWindow);
           		 	break;
           		}
            	break;
        case WM_PAINT:
            {
                
				PAINTSTRUCT ps;
                HDC hdc = BeginPaint(hwnd, &ps);
                // ���ñ���ɫΪ��ɫ
                SetBkColor(hdc, RGB(0, 0, 0));
                HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 0));
                FillRect(hdc, &ps.rcPaint, hBrush);
                DeleteObject(hBrush);
                
                SetBkMode(hdc, TRANSPARENT);

                // ���ư�ɫԲ��
                HBRUSH hWhiteBrush = CreateSolidBrush(RGB(255, 255, 255));
                SelectObject(hdc, hWhiteBrush);
                Ellipse(hdc, 200, 200, 400, 400);
				
				HBRUSH hFTSBlueBrush = CreateSolidBrush(RGB(20, 126, 255));
				SelectObject(hdc, hFTSBlueBrush);
                // ������ɫ����
                Rectangle(hdc, 500, 200, 700, 400);
                
                // ��������
    			HFONT hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "fonts/analogue.ttf");
    			SelectObject(hdc, hFont);
				
    			// �����ı���ɫ
    			SetTextColor(hdc, RGB(255, 255, 255));

    			// ��ʾ�ı�
    			TextOut(hdc, 100, 100, "Hello world!", 12);
    			
    			
            	// �ͷ���Դ
    			DeleteObject(hFont);
    			ReleaseDC(NULL, hdc);
                EndPaint(hwnd, &ps);
            }
            break;
        case WM_LBUTTONDOWN:
        	MessageBox(hwnd,"������������","��ʾ",MB_OK+64);
        	break;
        case WM_MOUSEMOVE:
        	/* TODO (Sean537#9#): ����Ӽ�����ָ��λ�� */
        	mouse.x=0;
			mouse.y=0;
        	break;
        case WM_DESTROY:
            // �Ƴ�ϵͳ����ͼ��
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
	WndClassEx.lpszClassName   = AppClassName;
	WndClassEx.hIconSm         = LoadIcon(hInstance,"A");
	
	if(!RegisterClassEx(&WndClassEx)) {
		MessageBox(0, "�޷�ע�ᴰ�ڡ�����ϵͳ�����Ƿ�������Ѱ����������", "����",MB_ICONEXCLAMATION | MB_OK);
		return -1;
	}

    
    
	g_hMainWindow = CreateWindowEx(WS_EX_APPWINDOW,AppClassName,"537������",WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN,
		init_x,
		init_y,
		WIN_WIDTH,
		WIN_HEIGHT,
		0, 0, hInstance, NULL);

	if (g_hMainWindow == NULL){
		MessageBox(0, "�޴��ڡ�����ϵͳ�����Ƿ�������Ѱ����������", "����", MB_ICONEXCLAMATION | MB_OK);
		return -1;
	}

	ShowWindow(g_hMainWindow, nCmdShow);
	UpdateWindow(g_hMainWindow);
    // ��Ϣѭ��
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}

