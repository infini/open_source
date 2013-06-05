// ADO.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
//#include "ADOBase.h"
#include "adowrapper.h"
#include <iostream>
#include <assert.h>


int _tmain(int argc, _TCHAR* argv[])
{
	DBConnection connection;

// 	_CommandPtr command;
// 	if( connection.CreateCommand( command ) == false ) {
// 		assert( 0 );
// 		return -1;
// 	}

	float var = 1;

	_ParameterPtr ptr = wrapper::createParameter( connection, "Test", adParamInput, var );

//	_ParameterPtr ptr = connection.createParameter( connection, "Test", adParamInput, var );


	STATIC_CHECKER( 1, INVALID );

	if( ptr ) {
		std::cout << "success" << std::endl;
	} else {
		std::cout << "failed" << std::endl;
	}



	return 0;
}

