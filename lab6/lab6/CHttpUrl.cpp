#include "stdafx.h"
#include "CHttpUrl.h"

namespace
{
Protocol ParseProtocol(const std::string& protocol)
{
	//protocol = std::transform(protocol.begin(), protocol.end(), protocol.begin(), ::tolower);
	if (protocol == "http")
	{
		return HTTP;
	}
	else if (protocol == "https")
	{
		return HTTPS;
	}
	throw CUrlParsingError("Uknown protocol");
}

std::string ProtocolToString(Protocol protocol)
{
	if (protocol == HTTP)
	{
		return "http";
	}
	if (protocol == HTTPS)
	{
		return "https";
	}
}

std::string ParseDomain(const std::string& domain)
{
	if (domain.empty())
	{
		throw CUrlParsingError("Empty domain");
	}
	return domain;
}

unsigned short ParsePort(std::string const& inpPortNum, Protocol protocol)
{
	if (!inpPortNum.empty())
	{
		int port = std::stoi(inpPortNum);
		if (port > minPortNumber && port < maxPortNumber)
		{
			return port;
		}
	}
	else if (inpPortNum.empty())
	{
		if (protocol == HTTP)
		{
			return defaultHttpPort;
		}
		else if (protocol == HTTPS)
		{
			return defaultHttpsPort;
		}
	}

	throw CUrlParsingError("not valid port num");
}

} // namespace

CHttpUrl::CHttpUrl(std::string const& url)
{
	if (url.empty())
	{
		throw CUrlParsingError("Empty URL");
	}
	std::smatch result;
	std::regex reg(R"(^(\w+):\/\/([^\s:\/]+)(?::(\d+))?(?:\/(\S*))?$)", std::regex::icase);

	if (!regex_search(url, result, reg))
	{
		throw CUrlParsingError("Incorrect URL");
	}
	m_protocol = ParseProtocol(result[1]);
	m_domain = ParseDomain(result[2]);
	m_port = ParsePort(result[3], m_protocol);
	m_document = result[4];
};

CHttpUrl::CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol)
	: m_protocol(protocol)
	, m_document(document)
{
	if (!domain.empty())
		m_domain = domain;
	else
		throw CUrlParsingError("Domain can't be empty");
}

std::string CHttpUrl::GetURL() const
{
	std::string url;

	url.append(ProtocolToString(GetProtocol()) + "://");

	url.append(GetDomain());

	int port = GetPort();
	if (!((port == defaultHttpPort) || (port == defaultHttpsPort)))
	{
		url.append(":" + std::to_string(port));
	}

	std::string document = GetDocument();
	if (!(document.empty()))
	{
		url.append("/" + document);
	}

	return url;
}

std::string CHttpUrl::GetDomain() const
{
	return m_domain;
}

std::string CHttpUrl::GetDocument() const
{
	return m_document;
}

unsigned short CHttpUrl::GetPort() const
{
	return m_port;
}

Protocol CHttpUrl::GetProtocol() const
{
	return m_protocol;
}
