#include "stdafx.h"
#include "../htmlEncode/EncodeHTML.h"

TEST_CASE("work?")
{
	CHECK(HtmlDecode("") == "");
	CHECK(HtmlDecode("ABC") == "ABC");
	CHECK(HtmlDecode("&quot;&apos;&lt;&gt;&amp;") == "\"'<>&");
}
