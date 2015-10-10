#include "stdafx.h"
#include "BehaviourIdleParam.h"
#include "FSMDefine.h"

namespace FSM_SPACE
{
	IMPLEMENT_CLASS(BehaviourIdleParam)
	BehaviourIdleParam::BehaviourIdleParam() : FSMParam(Behaviour_Idle)
	{
		nAnimID = -1;
	}
}