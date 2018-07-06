#pragma once
#include "CUrlParsingError.h"
#include <string>

constexpr int minPortNumber = 1;
constexpr int maxPortNumber = 65535;
constexpr unsigned short defaultHttpPort = 80;
constexpr unsigned short defaultHttpsPort = 443;

enum Protocol

{
	HTTP,
	HTTPS
};

class CHttpUrl
{
public:
	// ��������� ������� ���������� ������������� URL-�, � ������ ������ ��������
	// ���������� ���������� CUrlParsingError, ���������� ��������� �������� ������

	CHttpUrl(std::string const& url);

	/* �������������� URL �� ������ ���������� ����������.
	��� �������������� ������� ���������� ����������� ����������
	std::invalid_argument
	���� ��� ��������� �� ���������� � ������� /, �� ��������� / � ����� ���������
	*/

	CHttpUrl(
		std::string const& domain,
		std::string const& document,
		Protocol protocol = HTTP);

	/* �������������� URL �� ������ ���������� ����������.
	��� �������������� ������� ���������� ����������� ����������
	std::invalid_argument
	���� ��� ��������� �� ���������� � ������� /, �� ��������� / � ����� ���������
	*/

	CHttpUrl(
		std::string const& domain,
		std::string const& document,
		Protocol protocol,
		unsigned short port);

	// ���������� ��������� ������������� URL-�. ����, ���������� ����������� ���
	// ���������� ��������� (80 ��� http � 443 ��� https) � URL �� ������ ����������

	std::string GetURL() const;

	// ���������� �������� ���

	std::string GetDomain() const;

	/*
	���������� ��� ���������. �������:
	/
	/index.html
	/images/photo.jpg
	*/

	std::string GetDocument() const;

	// ���������� ��� ���������

	Protocol GetProtocol() const;

	// ���������� ����� �����

	unsigned short GetPort() const;

	void PrintInfo() const;

private:
	Protocol m_protocol;
	std::string m_domain;
	std::string m_url;
	std::string m_document;
	unsigned short m_port;
};
