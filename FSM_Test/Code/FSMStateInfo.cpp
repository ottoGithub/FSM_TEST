#include "stdafx.h"
#include "FSMStateInfo.h"
#include "FSMBehaviour.h"
#include "FSMDefine.h"
#include "FSMParam.h"
#include "ClassFactory/FactoryManager.h"

namespace FSM_SPACE
{
	FSMStateInfo::FSMStateInfo()
	{
		m_StateID = State_Unknow;
		m_BehaviourID = Behaviour_Unknow;
		m_fApproachPeriod = 0;
		m_fSyncValuePeriod = 0;
	}

	FSMStateInfo::FSMStateInfo(int nBehaviourID, float approachPeriod, float syncValuePeriod)
	{
		m_BehaviourID = nBehaviourID;
		m_fApproachPeriod = approachPeriod;
		m_fSyncValuePeriod = syncValuePeriod;
	}

	FSMStateInfo::~FSMStateInfo()
	{

	}

}