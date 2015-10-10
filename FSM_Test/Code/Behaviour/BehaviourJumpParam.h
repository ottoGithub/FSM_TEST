#ifndef _BEHAVIOUR_JUMP_PARAM_H_
#define _BEHAVIOUR_JUMP_PARAM_H_
#include "FSMParam.h"

namespace FSM_SPACE
{
	class BehaviourJumpParam : public FSMParam
	{
		DECLARE_CLASS(BehaviourJumpParam)
	public:
		BehaviourJumpParam();

		int nAnimID;
	};

}
#endif