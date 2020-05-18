#include<iostream>
#include"user.h"
#include<string>
#include<vector>
#include<fstream>

User::User()
{

}
User::User(std::string s, std::string passw, std::string type)
{
	init(s,passw,type);
}
User::User(std::string name)
{
	init_file(name);
}



User::~User()
{
	
}
void User::init(std::string s, std::string passw,std::string type)
{
	this->username = s;
	this->password = passw;
	this->access = type;
	if (type == "administrator")
	{
		names_administrator.push_back(this->username);
	}
	if (type == "client")
	{
		names_client.push_back(this->username);
	}
	
}
void User::print_clients(std::string filename)
{
	for (int i = 0; i < names_client.size(); i++)
	{
		std::cout << names_client[i] << std::endl;
	}
	std::cout << std::endl;
	names_client.clear();
}
void User::print_administrator()
{
	for (int i = 0; i < names_administrator.size(); i++)
	{
			std::cout << names_administrator[i] << std::endl;
	}
		std::cout << std::endl;
	}
void User::init_file(std::string filename)
{
	std::fstream file;
	std::string object;
	std::string str;
	std::string type1 = "client";
	std::string type2 = "administrator";
	std::size_t found1;
	std::size_t found2;
	file.open(filename, std::ios::in);
	if (file.good())
	{
		while (getline(file,object,'\n'))
		{
			str = object;
			found1 = str.find(type1);
			if (found1 != std::string::npos)
			{
				names_client.push_back(object);
			}
			found2 = str.find(type2);
			if (found2 != std::string::npos)
			{
				names_administrator.push_back(object);
			}
		}
	}
	file.close();
		
	}
 void User::add_users(std::string filename, std::string str1,std::string str2)
 {
	 std::fstream file;
	 std::string str3="client";
	 str1 += " ";
	 str1 += str2;
	 str1 += " ";
	 str1 += str3;
	 std::string res = copy_file(filename);
	 res += " ";
	 res += str1;
	 file.open(filename,std::ios::out|std::ios::trunc);
	 file.close();
	 file.open(filename,std::ios::out|std::ios::app);
	 if (file.is_open())
	 {
		 file <<res<< std::endl;
	 }
		 file.close();
		 return;
 }
 std::string User:: copy_file(std::string filename)
 {
	 std::fstream file;
	 std::string name;
	 std::string res;
	 file.open(filename, std::ios::in);
	 if (file.good())
	 {
		 while (getline(file, name,'\n'))
		 {
			 res += name;
			 res += '\n';
		 }
	 }
	 file.close();
	 file.open(filename,std::ios::trunc);
	 file.close();
	 return res;
 }
 void User::remove_users(std::string filename, std::string name)
 {
	 std::fstream file;
	 std::string res;
	 file.open(filename, std::ios::in);
	 res = copy_file(filename);
	 file.close();
	 std::string s;
	 int start = 0;
	 int finish = 0;
	 int rps = 0;
	 int i = 0;
	 int k = 0;
	 while(i<res.length())
	 {
		 if (res[i] == name[0])
		 {
			 start = i;
			 rps = 0;
			 for (int t = start; t < start + name.length(); t++)
			 {
				 for (int j = 0; j < name.length(); j++)
				 {
					 if (res[i] == name[j])
					 {
						 rps++;
					 }
				 }
			 }
				 if (rps == name.length())
				 {
					 k = i;
					 while (res[k] != '\n')
					 {
						 k++;
					 }
					 finish = k;
					 res.erase(res.begin()+start, res.begin()+finish);
				 }
		 }
		 i++;
	 }
	 file.open(filename,std::ios::out|std::ios::trunc);
	 file << res;
	 file.close();
 }

void User::log_in(std::string s, std::string passw)
{
	
	std::string str;
	reps++;
	for (int i = 0; i < names_client.size(); i++)
	{
		str += names_client[i];
	}
	if (reps>1)
	{
		names_client.push_back(s);
		std::cout << "You are already logged in." << std::endl;
		reps = 0;
		enter_client = true;
	}
	if (reps==1)
	{
			std::size_t found1  = str.find(s);
			std::size_t found2 = str.find(passw);
			if (found1!=std::string::npos && found2!=std::string::npos)
			{
				std::cout << "Welcome," << s << "!" << std::endl;
				enter_client = true; 
				reps = 0;
			}
			else
			{
				std::cout << "Error username or password!Try again!" << std::endl;
				enter_client = false;
				reps = 2;
			}
		}
	}
void User::log_out(std::string s)
{
	std::cout << "You leave the system!" << " Enter new name:" << std::endl;
	enter_client = false;
}
void User::user_add(std::string s, std::string passw)
{
	if (enter_client == true && enter_administrator==true)
	{
		names_client.push_back(s);
	}
	else
	{

		std::cout << "You must be logged in the system!"<< std::endl;
	}
}
