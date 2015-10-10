#ifndef _BEHAVIOUR_IDLE_H_
#define _BEHAVIOUR_IDLE_H_
#include "FSMBehaviour.h"

namespace FSM_SPACE
{
	class BehaviourIdle : public FSMBehaviour
	{
		DECLARE_CLASS(BehaviourIdle)
	public:
		BehaviourIdle();
		~BehaviourIdle();

		bool Tick(float fTime);
		bool KeyEvent(int nKeyID, int nKeyMode);
	public:
		bool CheckEnterCondition();
		bool InitialBehaviour(FSMParam* pFSMParam);
		bool Enter();
		void Leave(FSMBehaviour* pNextBehaviour);

	};
}

#endif