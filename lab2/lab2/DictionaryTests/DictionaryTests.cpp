#include "stdafx.h"
#include "../Dictionary/Dictionary.h"

TEST_CASE("work?")
{

	CHECK(Translate("Word") == "Word");
	CHECK(Translate("") == "");
	CHECK(Translate(" ") == " ");
	CHECK(Translate("cat") == "кошка");
}
