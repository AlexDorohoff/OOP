#include "stdafx.h"
#include "../htmlEncode/EncodeHTML.h"

TEST_CASE("work?")
{
	CHECK(HtmlDecode("") == "");
	CHECK(HtmlDecode("ABC") == "ABC");
	CHECK(HtmlDecode("&apos;") == "'");
	CHECK(HtmlDecode("&quot;&apos;&lt;&gt;&amp;") == "\"'<>&");
	CHECK(HtmlDecode("apos;") == "apos;");
	CHECK(HtmlDecode("one two three four five six") == "one two three four five six");
	CHECK(HtmlDecode("one &amp; two &apos;three ") == "one & two 'three ");
	CHECK(HtmlDecode("&amp; apos;") == "& apos;");
	CHECK(HtmlDecode("&amp;quot;") == "&quot;");
	CHECK(HtmlDecode("&amp;apos;") == "&apos;");
}
