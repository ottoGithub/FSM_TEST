#ifndef _ACTOR_MANAGER_H_
#define _ACTOR_MANAGER_H_

#include "Singleton.h"
#include <map>
#include "GActor.h"

namespace FSM_SPACE
{
	typedef std::map<int,GActor*> ActorMap;
	class ActorManager : public Singleton<ActorManager>
	{
	public:
		ActorManager();

		void CreateActor(int guid);

		void Tick(float fFrameTime);
	private:
		ActorMap m_ActorMap;
	};
}

#endif