#ifndef _FSM_BEHAVIOUR_H_
#define _FSM_BEHAVIOUR_H_

#include "ClassFactory/FactoryManager.h"
#include "FSMParam.h"

namespace FSM_SPACE
{
	class GActor;
	class FSMBehaviour
	{
	public:
		FSMBehaviour();
		explicit FSMBehaviour(int nBehaviourID);
		virtual ~FSMBehaviour();
		void SetOwner(GActor* pActor) { m_pOwner = pActor; }
		void SetStateID(int nStateID) { m_nStateID = nStateID; }
	public:
		virtual bool KeyEvent(int nKeyID, int nKeyMode) { return false; }

		virtual bool Tick(float fTime);
		virtual bool InitialBehaviour(FSMParam* pFSMParam);
		virtual bool CheckEnterCondition(){ return true; }//com功能位相关
		virtual bool Enter(){return true;}
		virtual void Leave(FSMBehaviour* pNextBehaviour){}

		bool IsFinished() { return m_bFinish;}
		void Finish() { m_bFinish = true;}

		int StateID(){ return m_nStateID; }
		int BehaviourID() { return m_nBehaviourID; }
	private:
		GActor* m_pOwner;
		bool m_bFinish;
		int m_nBehaviourID;
		int m_nStateID;
		int m_nStep;
		float m_fElapsedTimeTotal;
	};
}
#endif