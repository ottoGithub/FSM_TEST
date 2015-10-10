#include "stdafx.h"
#include "BehaviourMoveParam.h"
#include "FSMDefine.h"

namespace FSM_SPACE
{
	IMPLEMENT_CLASS(BehaviourMoveParam)
	BehaviourMoveParam::BehaviourMoveParam() : FSMParam(Behaviour_Move)
	{
		nAnimID = -1;
	}
}