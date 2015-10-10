#ifndef _BEHAVIOUR_BEAT_BACK_PARAM_H_
#define _BEHAVIOUR_BEAT_BACK_PARAM_H_
#include "FSMParam.h"

namespace FSM_SPACE
{
	class BehaviourBeatBackParam : public FSMParam
	{
		DECLARE_CLASS(BehaviourBeatBackParam)
	public:
		BehaviourBeatBackParam();

		int nAnimID;
	};

}
#endif