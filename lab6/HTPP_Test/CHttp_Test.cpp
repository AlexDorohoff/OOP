#include "../../Catch/catch.hpp"
#include "../lab6/CHttpUrl.h"

TEST_CASE("check base functional")
{
	CHttpUrl url("https://google.ru:55/index.html");
	CHECK(url.GetURL() == "https://google.ru:55/index.html");
	CHECK(url.GetPort() == 55);
	CHECK(url.GetDomain() == "google.ru");
	CHECK(url.GetDocument() == "index.html");
	CHECK(url.GetProtocol() == Protocol::HTTPS);
}

TEST_CASE("do not a shoe default port")
{
	CHttpUrl url("https://google.ru:443/index.html");
	CHECK(url.GetURL() == "https://google.ru/index.html");
	CHECK(url.GetPort() == 443);
	CHECK(url.GetDomain() == "google.ru");
	CHECK(url.GetDocument() == "index.html");
	CHECK(url.GetProtocol() == Protocol::HTTPS);
}

TEST_CASE("can't set not valid port num")
{
	CHECK_THROWS_WITH(CHttpUrl("http://line.ru:90000000/index"), "not valid port num");
	CHECK_THROWS_WITH(CHttpUrl("http://line.ru:65536/index"), "not valid port num");
	CHECK_THROWS_WITH(CHttpUrl("http://line.ru:0/index"), "not valid port num");
}

TEST_CASE("can sat a valid port num")
{
	CHECK_NOTHROW(CHttpUrl("http://line.ru:9000/index"));
	CHECK_NOTHROW(CHttpUrl("http://line.ru:65535/index"));
}

TEST_CASE("can't set a not valid protocol")
{
	CHECK_THROWS_WITH(CHttpUrl("htttp://line.ru:90/index"), "Uknown protocol");
}

TEST_CASE("default port number")
{
	CHttpUrl url("google.ru", "index.html", HTTP);
	CHECK(url.GetURL() == "");
	CHECK(url.GetPort() == 80);
}
