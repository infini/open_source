
#pragma once

#include "ADOBase.h"

// template< bool >
// struct CompileTimeChecker
// {
// 	CompileTimeChecker( ... );
// };
// 
// template<>
// struct CompileTimeChecker< false >	{};
// 
// #define STATIC_CHECK( expr, msg )	\
// {	\
// 	class ERROR_##msg {};	\
// 	(void)sizeof( CompileTimeChecker< ( expr ) != 0 >( ( ERROR_##msg() ) ) );	\
// }



//////////////////////////////////////////////////////////////////////////
template<bool>
struct CompileTimeChecker
{
	CompileTimeChecker(...);
};
template<> struct CompileTimeChecker<false> {};


#define STATIC_CHECKER( expr, msg )\
{\
class ERROR_##msg {}; \
	( void )sizeof( ( CompileTimeChecker< ( expr ) >( ERROR_##msg() ) ) );\
}


//////////////////////////////////////////////////////////////////////////

namespace wrapper {

	template< typename _Type >
	_ParameterPtr createParameter( DBConnection & connection, _bstr_t Name, enum ParameterDirectionEnum Direction, const _Type & value )
	{
		return NULL;
	};

	template<>
	_ParameterPtr createParameter( DBConnection & connection, _bstr_t Name, enum ParameterDirectionEnum Direction, const int & value )
	{
		//return connection.command->CreateParameter( Name, adInteger, Direction, 4, value );
		return 1;
	};

	template<>
	_ParameterPtr createParameter( DBConnection & connection, _bstr_t Name, enum ParameterDirectionEnum Direction, const __int64 & value )
	{
		//return connection.command->CreateParameter( Name, adBigInt, Direction, 8, value );
		return 2;
	};
}

