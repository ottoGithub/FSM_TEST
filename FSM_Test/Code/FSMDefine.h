#ifndef _FSM_DEFINE_H_
#define _FSM_DEFINE_H_

namespace FSM_SPACE
{
	enum eStateID
	{
		State_Unknow = -1,
		
		State_Idle,
		State_Move,
		State_Jump,
		State_BeatBack,
	};

	enum eBehaviourID
	{
		Behaviour_Unknow = -1,

		Behaviour_Idle,
		Behaviour_Move,
		Behaviour_Jump,
		Behaviour_BeatBack,
	};
}

#endif