#include "stdafx.h"
#include "CUrlParsingError.h"

CUrlParsingError::CUrlParsingError()
	: invalid_argument("Unknown error.")
{
}

CUrlParsingError::CUrlParsingError(std::string const& error)
	: invalid_argument(error)
{
}
