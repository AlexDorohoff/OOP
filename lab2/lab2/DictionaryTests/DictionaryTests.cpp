#include "stdafx.h"
#include "../Dictionary/Dictionary.h"

TEST_CASE("work?")
{

	CHECK(Translate("cat", "test.txt") == "кошка");
	CHECK(Translate("") == "");
	CHECK(Translate(" ") == " ");
}
