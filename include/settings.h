#include <windows.h>
#define APP_VERSION	1.0

struct MOUSE{
	int x;
	int y;
}mouse;

struct SYSTEM_IMFORMATION{
	int arrange;//ϵͳ������С�����ڵķ�ʽ 
	int cleanboot;//ϵͳ������ʽ��0Ϊ����������1Ϊ��ȫ��ʽ��2Ϊ��ȫ��ʽ�������繦��
	int cmonitors;//��WindowsNT5.0��ָ��������������
	int cmousebuttons;//����ϰ�ť�ĸ�����0��ʾû�а�װ��� 
	int cxborder;//���ڱ߿�Ŀ�ȣ�������Ϊ��λ������3D��ʾ��ʽ�¸�ֵ��cxedge��ͬ
	int cyborder;//���ڱ߿�ĸ߶ȡ�ͬ�ϡ�
	int cxcursor;//����ȣ�������Ϊ��λ��
	int cycursor;//���߶ȣ�������Ϊ��λ��
	int cxdlgframe;//��cxfixedflame��ͬ
	int cydlgframe;//��cyfixedflame��ͬ
	int cxdoubleclk;//���˫��ʱ���εĿ��
	int cydoubleclk;//���˫��ʱ���εĸ߶�
	int cxdrag;//���ϷŲ������εĿ��
	int cydrag;//���ϷŲ������εĸ߶�
	int cxedge;//3D��ʽ�Ĵ��ڱ߿��ȣ���һ�㴰�ڵ�cxborder��Ӧ
	int cyedge;//3D��ʽ�Ĵ��ڱ߿�߶ȣ���һ�㴰�ڵ�cyborder��Ӧ
	int cxfullscreen;//��Ļ���
	int cyfullscreen;//��Ļ�߶�
	/* TODO (Sean537#1#): ��Ӹ������ */
	
	int swapbutton;//ָ��ϵͳ�Ƿ񽻻����������Ҽ����ܡ���0��ʾ������0��ʾδ���� 
	
	char computername[128];//ϵͳ���� 
}sys;
