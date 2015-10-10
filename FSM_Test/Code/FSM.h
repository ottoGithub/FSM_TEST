#ifndef _FSM_H_
#define _FSM_H_
#include "FSMBehaviour.h"
#include "FSMManager.h"
//common lib

namespace FSM_SPACE
{
	class GActor;
	class FSM
	{
	public:
		FSM();
		virtual ~FSM();
		void Tick(float fFrameTime);
		void SetOwner(GActor* pOwner){ m_pOwner = pOwner; }
		GActor* GetOwner() { return m_pOwner; }

	public:
		void EnterDefaultBehaviour();
	protected:
		bool ChangeBehaviour(FSMBehaviour* pNextBehaviour, FSMParam* pBehaviourParam, bool bIgnoreRule);
		void LeaveCurrentBehaviour(FSMBehaviour* pNextBehaviour);
		void EnterCurrentBehaviour();
	protected:
		FSMBehaviour* m_pCurBehaviour;
		FSMBehaviour* m_pPrevBehaviour;
		FSMManager& FSMMgr;

	private:
		GActor* m_pOwner;

		//float m_fSyncTimeStamp;		//同步时间戳
	};
}

#endif