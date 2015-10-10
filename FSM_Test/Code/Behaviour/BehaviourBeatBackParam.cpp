#include "stdafx.h"
#include "BehaviourBeatBackParam.h"
#include "FSMDefine.h"

namespace FSM_SPACE
{
	IMPLEMENT_CLASS(BehaviourBeatBackParam)
	BehaviourBeatBackParam::BehaviourBeatBackParam() : FSMParam(Behaviour_BeatBack)
	{
		nAnimID = -1;
	}
}