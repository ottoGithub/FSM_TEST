#include "stdafx.h"
#include "FSMManager.h"
#include "FSMDefine.h"
#include "FSMStateInfo.h"
#include "FSMBehaviour.h"
#include "FSMParam.h"

#include "ClassFactory/FactoryManager.h"

#include "Behaviour\BehaviourIdleParam.h"
#include "Behaviour\BehaviourJumpParam.h"
#include "Behaviour\BehaviourMoveParam.h"
#include "Behaviour\BehaviourBeatBackParam.h"

namespace FSM_SPACE
{
	FSMRegInfo::FSMRegInfo(const char* strClassName, const char* strParamName):strBehaviourClassName(strClassName),strBehaviourParamName(strParamName)
	{
	}

	FSMManager::FSMManager()
	{
		InitialFSMState();
		InitialFSMEnterRule();

		RegFSMInfo();
	}


	FSMManager::~FSMManager()
	{
	}
	
	bool FSMManager::InitialFSMState()
	{
		//Load From Table
		m_StateInfoMap[Behaviour_Idle] = new FSMStateInfo(Behaviour_Idle,0,0);
		m_StateInfoMap[Behaviour_Move] = new FSMStateInfo(Behaviour_Move,0,0);
		m_StateInfoMap[Behaviour_Jump] = new FSMStateInfo(Behaviour_Jump,0,0);
		m_StateInfoMap[Behaviour_BeatBack] = new FSMStateInfo(Behaviour_BeatBack,0,0);
		return true;
	}

	bool FSMManager::InitialFSMEnterRule()
	{
		//Load From Table
		std::vector<int> vec_IdleRule;
		vec_IdleRule.push_back(State_Move);
		vec_IdleRule.push_back(State_Jump);
		m_StateEnterRuleMap[State_Idle] = vec_IdleRule;

		std::vector<int> vec_MoveRule;
		vec_MoveRule.push_back(State_Idle);
		vec_MoveRule.push_back(State_Jump);
		m_StateEnterRuleMap[State_Move] = vec_MoveRule;

		std::vector<int> vec_JumpRule;
		vec_JumpRule.push_back(State_Idle);
		m_StateEnterRuleMap[State_Jump] = vec_JumpRule;

		return true;
	}
	void FSMManager::RegFSMInfo()
	{
		m_RegInfoMap[Behaviour_Idle] = new FSMRegInfo("BehaviourIdle","BehaviourIdleParam");
		m_RegInfoMap[Behaviour_Move] = new FSMRegInfo("BehaviourMove","BehaviourMoveParam");
		m_RegInfoMap[Behaviour_Jump] = new FSMRegInfo("BehaviourJump","BehaviourJumpParam");
		m_RegInfoMap[Behaviour_BeatBack] = new FSMRegInfo("BehaviourBeatBack","BehaviourBeatBackParam");
	}

	bool FSMManager::CanEnterToNextState(int nCurStateID, int nNextStateID)
	{
		std::map<int, std::vector<int> >::iterator iter = m_StateEnterRuleMap.find(nCurStateID);
		if(iter != m_StateEnterRuleMap.end())
		{
			std::vector<int>::iterator iterVec = (iter->second).begin();
			for(;iterVec!=(iter->second).end();iterVec++)
			{
				if((*iterVec) == nNextStateID)
				{
					return true;
				}
			}
		}
		return false;
	}

	FSMBehaviour* FSMManager::MakeBehaviour(int nBehaviourID, int nDefaultStateID)
	{
		FSMRegInfo* pRegInfo = GetRegInfo(nBehaviourID);
		if(!pRegInfo)
		{
			return NULL;
		}
		FSMBehaviour* pBehaviour = (FSMBehaviour*)FactoryManager::Instance().New((pRegInfo->strBehaviourClassName).c_str());
		pBehaviour->SetStateID(nDefaultStateID);
		return pBehaviour;
	}

	FSMParam* FSMManager::MakeParam(int nBehaviourID)
	{
		FSMRegInfo* pRegInfo = GetRegInfo(nBehaviourID);
		if(!pRegInfo)
		{
			return NULL;
		}
		FSMParam* pParam = (FSMParam*)FactoryManager::Instance().New((pRegInfo->strBehaviourParamName).c_str());
		return pParam;
	}

	FSMRegInfo* FSMManager::GetRegInfo(int nBehaviourID)
	{
		std::map<int, FSMRegInfo* >::const_iterator iter = m_RegInfoMap.find(nBehaviourID);
		if(iter!=m_RegInfoMap.end())
		{
			return iter->second;
		}
		return NULL;
	}
}
