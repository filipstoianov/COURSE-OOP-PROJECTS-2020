#pragma once
#include<iostream>
#include<vector>
#include<string>
class User
{
private:
	std::string username;
	std::string password;
	std::string access;
	std::vector <std::string> names_client;
	std::vector <std::string> names_administrator;
	std::vector<std::string>all_users;
	int reps = 0;
	bool enter_client = false;
	bool enter_administrator = false;
public:
	void log_in(std::string name,std::string pasw);
	User();
	User(std::string name);
	User(std::string s, std::string passw,std::string type);
	~User();
	void init(std::string s, std::string passw, std::string access);
	void log_out(std::string s);
	void user_add(std::string s,std::string passw);
	void init_file(std::string filename);
	std::ofstream& output(std::fstream file,User u);
	void add_users(std::string filename, std::string str1, std::string str2);
	void remove_users(std::string filename, std::string str1);
	void print_clients(std::string filename);
	void print_administrator();
};
