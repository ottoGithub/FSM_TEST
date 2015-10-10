#ifndef _FSM_STATE_INFO_H_
#define _FSM_STATE_INFO_H_
#include <string>
namespace FSM_SPACE
{
	class FSMParam;
	class FSMBehaviour;
	class FSMStateInfo
	{
	public:
		FSMStateInfo();
		FSMStateInfo(int nBehaviourID, float approachPeriod, float syncValuePeriod);
		//FSMBehaviourInfo(Row& rowData);
		~FSMStateInfo();

	public:
		int m_StateID;
		int m_BehaviourID;

		float m_fApproachPeriod;	//逼近周期
		float m_fSyncValuePeriod;	//同步周期

		std::string m_StrClassName;
		std::string m_StrParamName;
	};

}

#endif