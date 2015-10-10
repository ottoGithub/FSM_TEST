#include "stdafx.h"
#include "FSMBehaviour.h"
#include "FSMDefine.h"
#include "GActor.h"

namespace FSM_SPACE
{
	FSMBehaviour::FSMBehaviour()
	{
		m_nStateID = State_Idle;
		m_nBehaviourID = Behaviour_Unknow;
		m_nStep = 0;
		m_pOwner = NULL;
		m_fElapsedTimeTotal = 0;
		m_bFinish = false;
	}

	FSMBehaviour::FSMBehaviour(int nBehaviourID)
	{
		m_nStateID = State_Unknow;
		m_nBehaviourID = nBehaviourID;
		m_nStep = 0;
		m_pOwner = NULL;
		m_fElapsedTimeTotal = 0;
		m_bFinish =false;
	}

	FSMBehaviour::~FSMBehaviour()
	{

	}

	bool FSMBehaviour::Tick(float fTime)
	{
		m_fElapsedTimeTotal += fTime;
		return true;
	}

	bool FSMBehaviour::InitialBehaviour(FSMParam* pFSMParam)
	{
		if(m_nBehaviourID != pFSMParam->m_nBehaviourID)
		{
			return false;
		}
		m_fElapsedTimeTotal = 0;
		return true;
	}
}