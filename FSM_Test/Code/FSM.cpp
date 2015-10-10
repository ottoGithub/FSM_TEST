#include "stdafx.h"
#include "FSM.h"
#include "FSMDefine.h"
#include "FSMParam.h"

namespace FSM_SPACE
{
	FSM::FSM():FSMMgr(FSMManager::Instance())
	{
		m_pOwner = NULL;
		m_pCurBehaviour = NULL;
		m_pPrevBehaviour = NULL;


	}

	FSM::~FSM()
	{

	}

	void FSM::Tick(float fFrameTime)
	{
		if(!m_pCurBehaviour)
		{
			return;
		}
		bool bReturn = m_pCurBehaviour->Tick(fFrameTime);
		if(m_pCurBehaviour->IsFinished())
		{
			bReturn = false;
		}

		if(!bReturn)
		{
			EnterDefaultBehaviour();
		}
	}

	void FSM::EnterDefaultBehaviour()
	{
		FSMParam* pParam = FSMMgr.MakeParam(Behaviour_Idle);
		if(!pParam)
		{
			return;
		}
		FSMBehaviour* pBehaviour = FSMMgr.MakeBehaviour(Behaviour_Idle, State_Idle);
		if(!pBehaviour)
		{
			return;
		}
		pBehaviour->SetOwner(m_pOwner);
		if(!pBehaviour->InitialBehaviour(pParam))
		{
			return;
		}
		ChangeBehaviour(pBehaviour,pParam,true);
		FACTORY_DELETE(pParam);
	}

	bool FSM::ChangeBehaviour(FSMBehaviour* pNextBehaviour, FSMParam* pBehaviourParam, bool bIgnoreRule)
	{
		if(!pNextBehaviour)
		{
			return false;
		}
		if(!pNextBehaviour->CheckEnterCondition())
		{
			return false;
		}
		if( !bIgnoreRule && m_pCurBehaviour!= NULL && !m_pCurBehaviour->IsFinished())
		{
			if(!FSMMgr.CanEnterToNextState(m_pCurBehaviour->StateID(),pNextBehaviour->StateID()))
			{
				return false;
			}
		}
		LeaveCurrentBehaviour(pNextBehaviour);
		m_pCurBehaviour = pNextBehaviour;
		EnterCurrentBehaviour();
		return true;
	}

	void FSM::LeaveCurrentBehaviour(FSMBehaviour* pNextBehaviour)
	{
		if(m_pCurBehaviour)
		{
			m_pCurBehaviour->Leave(pNextBehaviour);
		}

		if(m_pPrevBehaviour)
		{
			FACTORY_DELETE(m_pPrevBehaviour);
		}
		m_pPrevBehaviour = m_pCurBehaviour;
		m_pCurBehaviour = NULL;
	}

	void FSM::EnterCurrentBehaviour()
	{
		//重置同步时间戳
		if(!m_pCurBehaviour->Enter())
		{
			m_pCurBehaviour->Finish();
		}
	}
}