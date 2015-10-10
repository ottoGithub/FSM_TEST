#ifndef _BEHAVIOUR_MOVE_H_
#define _BEHAVIOUR_MOVE_H_
#include "FSMBehaviour.h"

namespace FSM_SPACE
{
	class BehaviourMove : public FSMBehaviour
	{
		DECLARE_CLASS(BehaviourMove)
	public:
		BehaviourMove();
		~BehaviourMove();
	};
}

#endif