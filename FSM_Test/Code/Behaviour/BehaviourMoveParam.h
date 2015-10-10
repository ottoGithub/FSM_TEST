#ifndef _BEHAVIOUR_MOVE_PARAM_H_
#define _BEHAVIOUR_MOVE_PARAM_H_
#include "FSMParam.h"

namespace FSM_SPACE
{
	class BehaviourMoveParam : public FSMParam
	{
		DECLARE_CLASS(BehaviourMoveParam)
	public:
		BehaviourMoveParam();

		int nAnimID;
	};

}
#endif