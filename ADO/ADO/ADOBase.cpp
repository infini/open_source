
#include "stdafx.h"
#include "ADOBase.h"
//#include "adowrapper.h"

namespace {
	bool	CreateDBCommand( _CommandPtr& cmd, _ConnectionPtr connection )
	{
		if( FAILED( cmd.CreateInstance(__uuidof(Command)) ) )
		{
			return false;
		}

		cmd->ActiveConnection = connection;
		return true;
	}
}


DBConnection::DBConnection()
{
}

DBConnection::~DBConnection()
{
}

bool	DBConnection::CreateCommand( _CommandPtr& cmd )
{
	return CreateDBCommand( cmd, connection );
}

_ParameterPtr	DBConnection::createParameter( DBConnection & connection, _bstr_t Name, enum ParameterDirectionEnum Direction, const _variant_t & value )
{
	connection.command->CreateParameter( Name, adDecimal, Direction, 8, value );
	return NULL;//wrapper::createParameter( connection, Name, Direction, value );
};
