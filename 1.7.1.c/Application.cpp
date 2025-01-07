#include "Application.h"

static Application* global_app = nullptr;//��ʼ��Ϊ��ָ��//����ȫ�־�̬����

//��Ӧ�ĳ��򲿷�

Application::Application()
{

	if (!global_app)
	{
		global_app = this;
	}
	//������Ϸ����
	initgraph(1080,640);
	this->is_running = true;//��ʾ������������
}

Application* Application::instance()
{
	return global_app;
}

int Application::run()
{
	float fps = 1000 / 120.0;//����֡��//������SLEEP�����Ե���֡��
	DWORD startTick = 0;//��ʼʱ��
	//��Ϸ��ѭ��
	while (this->is_running)
	{
		//��ȡϵͳʱ�䣬���Ⱥ���
		startTick=GetTickCount();
		//������Ϣ(������Ա������
		handleMsg();
		//����˫�����ͼ��Ϊ�˷�ֹ��Ϸ���ֿ��٣�
		BeginBatchDraw();
		if (this->scene)
			this->scene->draw();
		//�ر�˫����
		EndBatchDraw();//����˫�����ͼ֮������ͼ����Ȼ��Ƶ��ڴ����棬�����ڴ治������ˢ�µ������ϣ�������Ҫ���õ����棬����Ҫ���ùر�˫���壬�������ܿ������档
		//��Ϸ���ݵĸ���
		if (this->scene)
			this->scene->updata();
		auto diff = GetTickCount() - startTick;//��ȡʱ���
		if (fps > diff)
		{
			Sleep(fps - diff);
		}
		//����ɵ���Ϣ
		msg = { 0 };
	}
	return 0;
}
//����
//float fps = 1000 / 120.0; :
//
//����ÿ֡��ʱ������Ŀ��֡��Ϊ 120 FPS��ÿ�� 120 ֡����������Ϊÿ֡Լ 8.33 ���루1000 ���� / 120����
//DWORD startTick = 0; :
//
//	����һ������ startTick�����ڴ洢��ǰʱ��ĺ�����������Ϊ DWORD���޷��ų����ͣ���
//	while (true) :
//
//		��ʼһ������ѭ����������Ϸ����ѭ������������ֱ�����������
//		startTick = GetTickCount(); :
//
//		��ȡ��ǰϵͳʱ�䣨�Ժ���Ϊ��λ�������洢�� startTick �С�GetTickCount() �� Windows API ���������ڻ�ȡϵͳ����������ʱ�䡣
//		handleMsg(); :
//
//		���� handleMsg ����������ϵͳ��Ϣ���������¼���������Ϣ�ȣ����������ͨ����Ӧ�ó������Ϣѭ����һ���֡�
//		BeginBatchDraw(); :
//
//		��ʼ˫�����ͼ���Լ��ٻ��濨������˫���弼��ͨ�����ڴ��л���ͼ��Ȼ��һ���Խ�����ʾ����Ļ�ϣ��Ӷ������ȾЧ�ʡ�
//		if (this->scene) this->scene->draw(); :
//
//			�����ǰ�������ڣ����øó����� draw �������л��ơ�this->scene ָ��ǰ���еĳ�������
//			EndBatchDraw(); :
//
//			����˫�����ͼ�����ڴ��е�ͼ��ˢ�µ���Ļ�ϣ�ʹ�û��ܹ��������º�Ļ��档
//			if (this->scene) this->scene->updata(); :
//
//				�����ǰ�������ڣ����øó����� updata ����������Ϸ״̬�����ɫλ�á�����״̬�ȣ�����������Ǹ�ƴд����Ӧ���� update��
//				auto diff = GetTickCount() - startTick; :
//
//				���㵱ǰ֡��ִ��ʱ�䣨���룩�����ӿ�ʼ�����ڵ�ʱ��
//				if (fps > diff) { Sleep(fps - diff); } :
//
//					�����ǰ֡��ִ��ʱ��С��Ŀ��֡ʱ�䣨fps��������� Sleep ����ʹ��ǰ�߳����ߣ�ȷ����Ϸ��֡���ȶ���Sleep �Ĳ�����ʣ���ʱ�䣬��ȷ��ÿ֡��ʱ�����ﵽ�趨ֵ��
//					msg = { 0 }; :
//
//					����ɵ���Ϣ��ͨ���ǽ���Ϣ�ṹ������Ϊ�㣬�Ա�Ϊ��һ�δ���׼����
//					return 0; :
//
//					�˳�ѭ���󣬷��� 0����Ȼ���������ѭ����ʵ���ϲ���ִ�е���һ�У�
void Application::handleMsg()
{
	if (peekmessage(&msg))
	{
		if (msg.message == WM_KEYDOWN && msg.vkcode == VK_ESCAPE)
		{
			quit();
		}
	}//�ж��Ƿ���ESC��
}

void Application::quit()
{
	this->is_running = false;
}
//����������
void Application::runScene(GoldMinerScene* scene)
{
	if (scene)//��鴫��� scene ָ���Ƿ�Ϊ�ǿ�
	{
		this->scene = scene;
		this->scene->init();
	}
}
