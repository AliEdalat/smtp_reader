#include "SMTPDissector.h"

void update_state_of_connection(std::string source_mac, std::string source_ip,
	 std::string source_port, std::string dest_mac, std::string dest_ip, std::string dest_port, std::string raw_data)
{

	std::string input = source_mac+std::string("::")+
		source_ip+std::string(":")+source_port+std::string("->")+dest_mac+
		std::string("::")+dest_ip+std::string(":")+dest_port;
	ConnectionMap::const_iterator got_init = initialized_.find (input);

	std::string state = find_state_from_raw_data(raw_data, Ccs_, source_name_, source_email_, email_txt_);
	
	if ( got_init == mymap.end() && state == "DATA" )
	{
		initialized_[input] = new Connection(source_mac, source_ip, source_port,
		 dest_mac, dest_ip, dest_port);
		initialized_[input]->set_is_data_ready(true);
		initialized_[input]->set_is_established(true);


	}else if( got_init != mymap.end() && state == "QUIT" )
	{
		got_init->second->set_is_terminated(true);
		terminated_.push_back(got_init->second);
		initialized_.erase (got_init);

	}else if( got_init != mymap.end() && got_init->second->get_is_data_ready() && state == "append" )
	{
		got_init->second->append_data(email_txt_);
	}
}

std::string find_state_from_raw_data(std::string raw_data, std::vector<std::string>& Ccs_
		, std::string& source_name_, std::string& source_email_, std::string& email_txt_)
{
	std::string data_prefix = "DATA";
	std::string quit_prefix = "QUIT";
	if(raw_data.substr(0, data_prefix.size()) == data_prefix && raw_data.size() == data_prefix.size())
	{
	    return "DATA";
	}else if(raw_data.substr(0, quit_prefix.size()) == quit_prefix && raw_data.size() == quit_prefix.size())
	{
		return "QUIT";
	}else
	{
		std::stringstream ss(raw_data);
		std::string temp;

		if (sentence != NULL)
		{
			while(std::getline(ss,temp,'\n')){
				if (temp.substr(0, quit_prefix.size()) == quit_prefix)
				{
					/* code */
				}
			}
		}

		email_txt_ = raw_data;
		return "append";
	}

}