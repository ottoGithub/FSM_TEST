#ifndef _G_ACTOR_H_
#define _G_ACTOR_H_

namespace FSM_SPACE
{
	class GActor
	{
	public:
		GActor();
		virtual ~GActor();

		void Tick(float fFrameTime);

		void SetGuid(int id) { m_Guid = id; }
		int GetGuid() { return m_Guid; }

		void InitialComponents();
		void ReleaseComponents();

	private:
		int m_Guid;
		class FSM* m_pFSMCom;
	};
}

#endif