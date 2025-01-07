#include"Application.h"
#include"GoldMinerScene.h"
int main()
{
	Application app;//创建对象
	app.runScene(new GoldMinerScene);
	return app.run();
}