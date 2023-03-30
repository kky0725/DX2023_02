#include "framework.h"



int main()
{
	srand((unsigned int)time(nullptr));

	SoundManager::Create();
	shared_ptr<World> world = make_shared<World>();

	
	while (true)
	{
		world->Battle();
		if (world->End())
			break;
	}

	SoundManager::Delete();
	

	return 0;
}


