#include "stdafx.h"
#include "BehaviourIdle.h"
#include "FSMDefine.h"

namespace FSM_SPACE
{
	IMPLEMENT_CLASS(BehaviourIdle)

	BehaviourIdle::BehaviourIdle():FSMBehaviour(Behaviour_Idle)
	{

	}
	BehaviourIdle::~BehaviourIdle()
	{

	}
	bool BehaviourIdle::KeyEvent(int nKeyID, int nKeyMode)
	{
		return true;
	}
	bool BehaviourIdle::Tick(float fTime)
	{
		if(!FSMBehaviour::Tick(fTime))
		{
			return false;
		}
		return true;
	}
	bool BehaviourIdle::CheckEnterCondition()
	{
		if(!FSMBehaviour::CheckEnterCondition())
		{
			return false;
		}
		return true;
	}
	bool BehaviourIdle::InitialBehaviour(FSMParam* pFSMParam)
	{
		if(!FSMBehaviour::InitialBehaviour(pFSMParam))
		{
			return false;
		}
		return true;
	}
	bool BehaviourIdle::Enter()
	{
		return true;
	}
	void BehaviourIdle::Leave(FSMBehaviour* pNextBehaviour)
	{
	}
}