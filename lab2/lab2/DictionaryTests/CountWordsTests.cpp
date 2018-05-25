#include "stdafx.h"
#include "../Dictionary/Dictionary.h"

TEST_CASE("work?")
{
	CHECK(Translate("", "test.txt") == "");
	CHECK(Translate(" ", "test.txt") == " ");
	CHECK(Translate("cat", "test.txt") == "кошка");
}
