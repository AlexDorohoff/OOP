#include "../../Catch/catch.hpp"
#include "../lab6/CHttpUrl.h"

TEST_CASE("check base functional")
{
	CHttpUrl url("https://google.ru:55/index.html");
	CHECK(url.GetURL() == "https://google.ru:55/index.html");
	CHECK(url.GetPort() == 55);
	CHECK(url.GetDomain() == "google.ru");
	CHECK(url.GetDocument() == "/index.html");
	CHECK(url.GetProtocol() == Protocol::HTTPS);
}

TEST_CASE("check base functional2")
{
	CHttpUrl url("https://ya.ru");
	CHECK(url.GetURL() == "https://ya.ru");
	CHECK(url.GetPort() == 443);
	CHECK(url.GetDomain() == "ya.ru");
	CHECK(url.GetDocument() == "");
	CHECK(url.GetProtocol() == Protocol::HTTPS);
}

TEST_CASE("do not a show default port")
{
	CHttpUrl url("https://google.ru:443/index.html");
	CHECK(url.GetURL() == "https://google.ru/index.html");
	CHECK(url.GetPort() == 443);
	CHECK(url.GetDomain() == "google.ru");
	CHECK(url.GetDocument() == "/index.html");
	CHECK(url.GetProtocol() == Protocol::HTTPS);
}

TEST_CASE("do not a show default port2")
{
	CHttpUrl url("https://google.ru/index.html");
	CHECK(url.GetURL() == "https://google.ru/index.html");
	CHECK(url.GetPort() == 443);
	CHECK(url.GetDomain() == "google.ru");
	CHECK(url.GetDocument() == "/index.html");
	CHECK(url.GetProtocol() == Protocol::HTTPS);
}

TEST_CASE("not correct port for http")
{
	CHttpUrl url("http://google.ru:443/index.html");
	CHECK(url.GetURL() == "http://google.ru:443/index.html");
	CHECK(url.GetPort() == 443);
	CHECK(url.GetDomain() == "google.ru");
	CHECK(url.GetDocument() == "/index.html");
	CHECK(url.GetProtocol() == Protocol::HTTP);
}

TEST_CASE("not correct port for https")
{
	CHttpUrl url("https://google.ru:80/index.html");
	CHECK(url.GetURL() == "https://google.ru:80/index.html");
	CHECK(url.GetPort() == 80);
	CHECK(url.GetDomain() == "google.ru");
	CHECK(url.GetDocument() == "/index.html");
	CHECK(url.GetProtocol() == Protocol::HTTPS);
}

TEST_CASE("max port value")
{
	CHttpUrl url("http://line.ru:65535/index");
	CHECK(url.GetPort() == 65535);
}

TEST_CASE("min port value")
{
	CHttpUrl url("http://line.ru:1/index");
	CHECK(url.GetPort() == 1);
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
	CHECK_NOTHROW(CHttpUrl("http://line.ru/index"));
}

TEST_CASE("can't set a not valid protocol")
{
	CHECK_THROWS_WITH(CHttpUrl("htttp://line.ru:90/index"), "Uknown protocol");
}

TEST_CASE("default port number HTTP")
{
	CHttpUrl url("google.ru", "index.html", HTTP);
	CHECK(url.GetURL() == "http://google.ru/index.html");
	CHECK(url.GetPort() == 80);
	CHECK(url.GetPort() != 81);
	CHECK(url.GetPort() != 79);
}

TEST_CASE("default port number HTTPS")
{
	CHttpUrl url("google.ru", "index.html", HTTPS);
	CHECK(url.GetURL() == "https://google.ru/index.html");
	CHECK(url.GetPort() == 443);
	CHECK(url.GetPort() != 442);
	CHECK(url.GetPort() != 444);
}

TEST_CASE("Set not default port for https")
{
	CHttpUrl url("google.ru", "index.html", HTTPS, 444);
	CHECK(url.GetURL() == "https://google.ru:444/index.html");
	CHECK(url.GetPort() == 444);
	CHECK(url.GetPort() != 442);
	CHECK(url.GetPort() != 445);
}

TEST_CASE("Set not default port for http")
{
	CHttpUrl url("google.ru", "index.html", HTTP, 444);
	CHECK(url.GetURL() == "http://google.ru:444/index.html");
	CHECK(url.GetPort() == 444);
	CHECK(url.GetPort() != 442);
	CHECK(url.GetPort() != 445);
}
