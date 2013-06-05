
#pragma once

#ifndef _PRECOMPILED_HEADER
#define no_implementation
#endif

#import "C:\Program Files (x86)\Common Files\System\ado\msado60_Backcompat.tlb" no_implementation no_namespace rename("EOF", "EndOfFile")

#ifndef _PRECOMPILED_HEADER
#undef no_implementation
#endif

#include <oledb.h>
#include <icrsint.h>

struct DBConnection
{
	DBConnection();
	virtual ~DBConnection();

	bool	CreateCommand( _CommandPtr& cmd );

	_ParameterPtr	createParameter( DBConnection & connection, _bstr_t Name, enum ParameterDirectionEnum Direction, const _variant_t & value );

	_ConnectionPtr	connection;
	_CommandPtr		command;
};
