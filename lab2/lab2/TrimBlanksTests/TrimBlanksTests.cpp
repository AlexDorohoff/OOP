#include "stdafx.h"

#include "../TrimBlanks/TrimBlanks.h"
TEST_CASE("TrimBlanks tests")
{
	CHECK(TrimBlanks("") == "");
	CHECK(TrimBlanks("HELLO") == "HELLO");
	CHECK(TrimBlanks(" Hello") == "Hello");
	CHECK(TrimBlanks("  Hello    ") == "Hello");
	CHECK(TrimBlanks("    ") == "");
	CHECK(TrimBlanks("a") == "a");
}
