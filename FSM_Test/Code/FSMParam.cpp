#include "stdafx.h"
#include "FSMParam.h"
#include "FSMDefine.h"

namespace FSM_SPACE
{
	FSMParam::FSMParam(int nBehaviourID):m_nBehaviourID(nBehaviourID)
	{
		m_nStateID = State_Unknow;
	}
	
	FSMParam::~FSMParam()
	{
	}
}