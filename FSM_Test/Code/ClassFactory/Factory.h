#ifndef _FACTORY_CLASS_H_
#define _FACTORY_CLASS_H_

#include <string>
#include <memory>

namespace FSM_SPACE
{
	class FactoryBase_Arg0
	{
	public:
		FactoryBase_Arg0(){}
		virtual ~FactoryBase_Arg0(){}

		virtual void* NewClass(){ return NULL;}
		virtual const char* ClassName(){ return NULL;}
	};

	template<class T>
	class Factory_Arg0 : public FactoryBase_Arg0
	{
	public:
		Factory_Arg0(){};
		virtual ~Factory_Arg0(){}

		void* NewClass(void){ return new T();};

		void Free(void* ptr) { }

		const char* ClassName(){ return m_Name.c_str(); }
	protected:
		void SetClassName(const char* Name) { m_Name = Name; }
	private:
		std::string m_Name;
		//int index; //类标记，可用于内存收集时使用
	};
}

#endif