#include "stdafx.h"
#include "GameManager.h"

#include "ActorManager.h"

namespace FSM_SPACE
{
	void GameManager::OnTick(float fFrameTime)
	{
		ActorManager::Instance().Tick(fFrameTime);
	}
}