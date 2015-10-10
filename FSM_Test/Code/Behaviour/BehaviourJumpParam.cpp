#include "stdafx.h"
#include "BehaviourJumpParam.h"
#include "FSMDefine.h"

namespace FSM_SPACE
{
	IMPLEMENT_CLASS(BehaviourJumpParam)
	BehaviourJumpParam::BehaviourJumpParam() : FSMParam(Behaviour_Jump)
	{
		nAnimID = -1;
	}
}