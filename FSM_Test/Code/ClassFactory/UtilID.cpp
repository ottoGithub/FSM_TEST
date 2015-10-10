#include "stdafx.h"
#include "utilid.h"
#include <functional>
namespace FSM_SPACE
{
#define CRC_INIT				0xFFFF
#define CRC_XOR				0x0000

#define M_CRCValid(crc)		(crc!=0 && crc != 0xffffffff)

	static unsigned int crc_table[256] =
	{               /* CRC��ʽ�� */
		0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50a5, 0x60c6, 0x70e7,
		0x8108, 0x9129, 0xa14a, 0xb16b, 0xc18c, 0xd1ad, 0xe1ce, 0xf1ef,
		0x1231, 0x0210, 0x3273, 0x2252, 0x52b5, 0x4294, 0x72f7, 0x62d6,
		0x9339, 0x8318, 0xb37b, 0xa35a, 0xd3bd, 0xc39c, 0xf3ff, 0xe3de,
		0x2462, 0x3443, 0x0420, 0x1401, 0x64e6, 0x74c7, 0x44a4, 0x5485,
		0xa56a, 0xb54b, 0x8528, 0x9509, 0xe5ee, 0xf5cf, 0xc5ac, 0xd58d,
		0x3653, 0x2672, 0x1611, 0x0630, 0x76d7, 0x66f6, 0x5695, 0x46b4,
		0xb75b, 0xa77a, 0x9719, 0x8738, 0xf7df, 0xe7fe, 0xd79d, 0xc7bc,
		0x48c4, 0x58e5, 0x6886, 0x78a7, 0x0840, 0x1861, 0x2802, 0x3823,
		0xc9cc, 0xd9ed, 0xe98e, 0xf9af, 0x8948, 0x9969, 0xa90a, 0xb92b,
		0x5af5, 0x4ad4, 0x7ab7, 0x6a96, 0x1a71, 0x0a50, 0x3a33, 0x2a12,
		0xdbfd, 0xcbdc, 0xfbbf, 0xeb9e, 0x9b79, 0x8b58, 0xbb3b, 0xab1a,
		0x6ca6, 0x7c87, 0x4ce4, 0x5cc5, 0x2c22, 0x3c03, 0x0c60, 0x1c41,
		0xedae, 0xfd8f, 0xcdec, 0xddcd, 0xad2a, 0xbd0b, 0x8d68, 0x9d49,
		0x7e97, 0x6eb6, 0x5ed5, 0x4ef4, 0x3e13, 0x2e32, 0x1e51, 0x0e70,
		0xff9f, 0xefbe, 0xdfdd, 0xcffc, 0xbf1b, 0xaf3a, 0x9f59, 0x8f78,
		0x9188, 0x81a9, 0xb1ca, 0xa1eb, 0xd10c, 0xc12d, 0xf14e, 0xe16f,
		0x1080, 0x00a1, 0x30c2, 0x20e3, 0x5004, 0x4025, 0x7046, 0x6067,
		0x83b9, 0x9398, 0xa3fb, 0xb3da, 0xc33d, 0xd31c, 0xe37f, 0xf35e,
		0x02b1, 0x1290, 0x22f3, 0x32d2, 0x4235, 0x5214, 0x6277, 0x7256,
		0xb5ea, 0xa5cb, 0x95a8, 0x8589, 0xf56e, 0xe54f, 0xd52c, 0xc50d,
		0x34e2, 0x24c3, 0x14a0, 0x0481, 0x7466, 0x6447, 0x5424, 0x4405,
		0xa7db, 0xb7fa, 0x8799, 0x97b8, 0xe75f, 0xf77e, 0xc71d, 0xd73c,
		0x26d3, 0x36f2, 0x0691, 0x16b0, 0x6657, 0x7676, 0x4615, 0x5634,
		0xd94c, 0xc96d, 0xf90e, 0xe92f, 0x99c8, 0x89e9, 0xb98a, 0xa9ab,
		0x5844, 0x4865, 0x7806, 0x6827, 0x18c0, 0x08e1, 0x3882, 0x28a3,
		0xcb7d, 0xdb5c, 0xeb3f, 0xfb1e, 0x8bf9, 0x9bd8, 0xabbb, 0xbb9a,
		0x4a75, 0x5a54, 0x6a37, 0x7a16, 0x0af1, 0x1ad0, 0x2ab3, 0x3a92,
		0xfd2e, 0xed0f, 0xdd6c, 0xcd4d, 0xbdaa, 0xad8b, 0x9de8, 0x8dc9,
		0x7c26, 0x6c07, 0x5c64, 0x4c45, 0x3ca2, 0x2c83, 0x1ce0, 0x0cc1,
		0xef1f, 0xff3e, 0xcf5d, 0xdf7c, 0xaf9b, 0xbfba, 0x8fd9, 0x9ff8,
		0x6e17, 0x7e36, 0x4e55, 0x5e74, 0x2e93, 0x3eb2, 0x0ed1, 0x1ef0
	};
	
	static unsigned char case_table[256] = 
	{
		16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,
		32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,
		48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,
		64,65 + 32,66 + 32,67 + 32,68 + 32,69 + 32,70 + 32,71 + 32,72 + 32,73 + 32,74 + 32,75 + 32,76 + 32,77 + 32,78 + 32,79 + 32,
		80 + 32,81 + 32,82 + 32,83 + 32,84 + 32,85 + 32,86 + 32,87 + 32,88 + 32,89 + 32,90 + 32,91,92,93,94,95,
		96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,
		112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,
		128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,
		144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,
		160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,
		176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,
		192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,
		208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,
		224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,
		240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255,
	};

	UtilID::UtilID()
	{
		m_id = 0;
	}

	UtilID::UtilID(const char* _string)
	{
		m_id = CreateFromString(_string);
		//std::hash<std::string> h;
		//m_id = h(_string);
	}

	UtilID::UtilID(std::size_t id)
	{
		m_id = id;
	}

	UtilID::~UtilID()
	{

	}

	std::size_t UtilID::CreateFromString(const char* _string)
	{
		if(!_string)
		{
			return 0;
		}
		unsigned short crc_16s[2];
		int pos = 0;
		unsigned int crc_final;
		unsigned char data;

		crc_16s[0] = CRC_INIT;
		crc_16s[1] = CRC_INIT;

		while(_string[pos])
		{
			data = case_table[ unsigned char(_string[pos]) ];
			unsigned short& _v = crc_16s[pos&1];
			_v = (_v << 8) ^ crc_table[ (_v >> 8) ^ data];
			pos++;
		}
		crc_final = ( crc_16s[0] << 16 ) | crc_16s[1];
		return crc_final;
	}

	bool UtilID::operator < ( const UtilID& rhs ) const
	{
		return m_id < rhs.m_id;
	}
	bool UtilID::operator > ( const UtilID& rhs ) const
	{
		return m_id > rhs.m_id;
	}
	bool UtilID::operator == ( const UtilID& rhs ) const
	{
		return m_id == rhs.m_id;
	}
	bool UtilID::operator != (const UtilID& rhs ) const
	{
		return m_id != rhs.m_id;
	}

	UtilID& UtilID::operator = ( UtilID& rhs)
	{
		m_id = rhs.m_id;
		return *this;
	}
	UtilID& UtilID::operator = ( const char* _string )
	{
		m_id = CreateFromString(_string);
		return *this;
	}
	UtilID& UtilID::operator = ( char* _string)
	{
		m_id = CreateFromString(_string);
		return *this;
	}
	UtilID& UtilID::operator = ( int id )
	{
		m_id = (std::size_t)id;
		return *this;
	}
}