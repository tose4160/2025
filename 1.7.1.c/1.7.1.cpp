#include"Application.h"
#include"GoldMinerScene.h"
int main()
{
	Application app;//��������
	app.runScene(new GoldMinerScene);
	return app.run();
}