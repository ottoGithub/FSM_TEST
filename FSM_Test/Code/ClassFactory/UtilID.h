#ifndef _UTIL_ID_H_
#define _UTIL_ID_H_

#include <string>

namespace FSM_SPACE
{
	class UtilID
	{
	public:
		UtilID();
		UtilID(const char* _string);
		UtilID(std::size_t id);
		~UtilID();

		static std::size_t CreateFromString(const std::string & str) { return CreateFromString(str.c_str());}
		static std::size_t CreateFromString(const char* _string);

		operator int() const { return m_id; }
		bool operator < ( const UtilID& rhs ) const;
		bool operator > ( const UtilID& rhs ) const;
		bool operator == ( const UtilID& rhs ) const;
		bool operator != (const UtilID& rhs ) const;

		UtilID& operator = ( UtilID& rhs);
		UtilID& operator = ( const char* _string );
		UtilID& operator = ( char* _string);
		UtilID& operator = ( int id );
	private:
		std::size_t m_id;
	};
}

#endif