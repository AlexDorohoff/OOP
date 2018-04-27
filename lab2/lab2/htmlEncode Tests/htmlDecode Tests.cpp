#include "stdafx.h"
#include "../htmlEncode/EncodeHTML.h"

TEST_CASE("work?")
{
	CHECK(HtmlDecode("") == "");
	CHECK(HtmlDecode("ABC") == "ABC");
	CHECK(HtmlDecode("&apos;") == "'");
	CHECK(HtmlDecode("&apos;&lt;&gt;&amp;&quot;") == "\"'<>&");
}
