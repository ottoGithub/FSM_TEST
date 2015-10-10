#ifndef _FSM_MANAGER_H_
#define _FSM_MANAGER_H_

#include "Singleton.h"
#include <map>
#include <vector>

namespace FSM_SPACE
{
	class FSMStateInfo;
	class FSMBehaviour;
	class FSMParam;

	class FSMRegInfo
	{
	public:
		FSMRegInfo(const char* strClassName, const char* strParamName);

	public:
		std::string strBehaviourClassName;
		std::string strBehaviourParamName;
	};
	class FSMManager : public Singleton<FSMManager>
	{
	public:
		FSMManager();
		~FSMManager();
	public:
		bool InitialFSMState();
		bool InitialFSMEnterRule();
		void RegFSMInfo();


		bool CanEnterToNextState(int nCurStateID, int nNextStateID);

		FSMBehaviour* MakeBehaviour(int nBehaviourID, int nDefaultStateID);
		FSMRegInfo* GetRegInfo(int nBehaviourID);

		FSMParam* MakeParam(int nBehaviourID);


	private:
		std::map<int, std::vector<int> > m_StateEnterRuleMap;
		std::map<int, FSMStateInfo* > m_StateInfoMap;
		std::map<int, FSMRegInfo* > m_RegInfoMap;
	};

}
#endif