#include "Singleton.h"
#ifndef _GAME_MANAGER_H_
#define _GAME_MANAGER_H_

namespace FSM_SPACE
{
	class GameManager : public Singleton<GameManager>
	{
	public:
		void OnTick(float fFrameTime);
	};
}

#endif