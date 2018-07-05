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
	std::string stringProtocol;
	if (protocol == HTTP)
	{
		stringProtocol = "http";
	}
	if (protocol == HTTPS)
	{
		stringProtocol = "https";
	}

	return stringProtocol;
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
	int port = 0;

	if (!inpPortNum.empty())
	{
		port = std::stoi(inpPortNum);
		if (port >= minPortNumber && port <= maxPortNumber)
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

std::string ParseDocument(std::string const& inputData)
{
	if (inputData.empty() || (inputData[0] != '/'))
	{
		return "/" + inputData;
	}
	return inputData;
};

unsigned short GetDeafaultPort(Protocol protocol)
{
	if (protocol == HTTP)
	{
		return defaultHttpPort;
	}
	return defaultHttpsPort;
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
{
	m_domain = ParseDomain(domain);
	m_document = ParseDocument(document);
	m_protocol = protocol;
	m_port = GetDeafaultPort(m_protocol);
	m_url = ProtocolToString(m_protocol) + "://" + m_domain + m_document;
}

CHttpUrl::CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol, unsigned short port){

};

std::string CHttpUrl::GetURL() const
{
	std::string url;
	Protocol protocol = GetProtocol();
	url.append(ProtocolToString(protocol) + "://");
	url.append(GetDomain());

	int port = GetPort();
	if (!((port == defaultHttpPort) || (port == defaultHttpsPort)))
	{
		url.append(":" + std::to_string(port));
	}

	std::string document = ParseDocument(GetDocument());
	std::cout << "document" << document;
	if (!(document.empty()))
	{
		url.append(document);
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
