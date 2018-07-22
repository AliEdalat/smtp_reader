#ifndef CONNECTION_H_
#define CONNECTION_H_

#include <string>
#include <vector>

class Connection
{
public:
	Connection(std::string source_mac, std::string source_ip,
	 std::string source_port, std::string dest_mac, std::string dest_ip, std::string dest_port);
	bool get_is_terminated() const {return is_terminated_;}
	bool get_is_data_ready() const {return is_data_ready_;}
	bool get_is_established() const {return is_established_;}

	std::string get_source_email() const {return source_email_;}
	std::string get_source_name() const {return source_name_;}
	std::string get_dest_email() const {return dest_email_;}
	std::string get_dest_name() const {return dest_name_;}
	std::string get_date() const {return date_;}
	std::string get_data() const {return data_;}

	void set_is_terminated(bool is_terminated) {is_terminated_ = is_terminated;}
	void set_is_data_ready(bool is_data_ready) {is_data_ready_ = is_data_ready;}
	void set_is_established(bool is_established) {is_established_ = is_established;}

	void set_source_email(std::string source_email) {source_email_ = source_email;}
	void set_source_name(std::string source_name) {source_name_ = source_name;}
	void set_dest_email(std::string dest_email) {dest_email_ = dest_email;}
	void set_dest_name(std::string dest_name) {dest_name_ = dest_name;}
	void set_date(std::string date) {date_ = date;}
	void set_data(std::string data) {data_=data;}

	void add_cc(std::string cc_email);
	void append_data(std::string email_txt);
	//~Connection();
private:
	bool is_established_;
	bool is_data_ready_;
	bool is_terminated_;

	std::string data_;
	std::string date_;
	std::string source_email_;
	std::string source_name_;
	std::string dest_email_;
	std::string dest_name_;

	std::string source_mac_;
	std::string source_ip_;
	std::string source_port_;
	std::string dest_mac_;
	std::string dest_ip_;
	std::string dest_port_;

	std::vector<std::string> Ccs;
};

#endif