#pragma once
#ifndef CLIENT_H
#define CLIENT_H


#include <string>
class Client
{
public:
	Client();
private:
	std::string m_name;
	std::string m_firstname;
	std::vector <Product> m_panier;
	int m_id;
};

#endif // !CLIENT_H