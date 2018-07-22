#ifndef SMTP_DISSECTOR_H_
#define SMTP_DISSECTOR_H_

#include <string>
#include <map>
#include <sstream>
#include "Connection.h"

typedef std::map<std::string,Connection*> ConnectionMap;

class SMTPDissector
{
public:
	SMTPDissector() = default;
	void update_state_of_connection(std::string source_mac, std::string source_ip,
	 std::string source_port, std::string dest_mac, std::string dest_ip, std::string dest_port, std::string raw_data);
	//~SMTPDissector();
private:
	//std::string raw_data_;
	enum Prefix { DATA = "DATA", QUIT = "QUIT", From = "From: ", To = "To: ", Cc = "Cc: ", Date = "Date: ", Subject = "Subject: " };
	ConnectionMap initialized_;
	std::vector<Connection*> terminated_;
	std::string email_txt_;
	std::vector<std::string>& Ccs_;
	std::string source_name_;
	std::string source_email_;
	std::string dest_name_;
	std::string date_;	

	std::string find_state_from_raw_data(std::string raw_data, std::vector<std::string>& Ccs_
		, const std::string source_name_, const std::string source_email_, std::string email_txt_);

	void extract_data_from_data_packets();

	
};

#endif