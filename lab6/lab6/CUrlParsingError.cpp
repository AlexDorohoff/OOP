#include "stdafx.h"
#include "CUrlParsingError.h"

CUrlParsingError::CUrlParsingError(std::string const& error)
	: invalid_argument(error)
{
}
