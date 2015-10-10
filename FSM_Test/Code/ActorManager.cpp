#include "stdafx.h"
#include "ActorManager.h"
#include "GActor.h"

namespace FSM_SPACE
{
	ActorManager::ActorManager()
	{
		CreateActor(0);
	}
	void ActorManager::CreateActor(int guid)
	{
		ActorMap::const_iterator iter = m_ActorMap.find(guid);
		if(iter != m_ActorMap.end())
		{
			return;
		}
		GActor* pActor = new GActor();
		pActor->SetGuid(guid);
		pActor->InitialComponents();
		m_ActorMap.insert(ActorMap::value_type(guid,pActor));
	}

	void ActorManager::Tick(float fFrameTime)
	{
		ActorMap::const_iterator iter = m_ActorMap.begin();
		for(;iter!=m_ActorMap.end();++iter)
		{
			iter->second->Tick(fFrameTime);
		}
	}
}