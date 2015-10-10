#ifndef _BEHAVIOUR_IDLE_PARAM_H_
#define _BEHAVIOUR_IDLE_PARAM_H_
#include "FSMParam.h"
namespace FSM_SPACE
{
	class BehaviourIdleParam : public FSMParam
	{
		DECLARE_CLASS(BehaviourIdleParam)
	public:
		BehaviourIdleParam();

		int nAnimID;
	};

}
#endif