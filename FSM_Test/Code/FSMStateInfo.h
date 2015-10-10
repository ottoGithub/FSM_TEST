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

		float m_fApproachPeriod;	//�ƽ�����
		float m_fSyncValuePeriod;	//ͬ������

		std::string m_StrClassName;
		std::string m_StrParamName;
	};

}

#endif