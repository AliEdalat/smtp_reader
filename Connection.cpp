#include "Connection.h"

Connection::Connection(std::string source_mac, std::string source_ip,
	 std::string source_port, std::string dest_mac, std::string dest_ip, std::string dest_port)
:source_mac_(source_mac), source_ip_(source_ip), source_port_(source_port), dest_mac_(dest_mac),
dest_ip_(dest_ip), dest_port_(dest_port)
{

}

void Connection::add_cc(std::string cc_email)
{
	Ccs.push_back(cc_email);
}

void append_data(std::string email_txt)
{
	data_ = data_ + email_txt;
}