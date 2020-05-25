#pragma once
#include<iostream>
#include<vector>
#include<string>
#include"book.h"
class User : public Book /*!
						 define class User
						 */
{
private:
	/*!
	Private members of class User
	*/
	std::string username;
	std::string password;
	std::string access;
	std::vector <std::string> names_client;
	std::vector <std::string> names_administrator;
	std::vector<std::string>all_users;
	bool enter_client = false;
	int reps = 0;
public:
	void log_in(std::string name, std::string pasw);
	User();
	/*!
	Constructor of class User
	*/
	User(std::string name);
	/*!
	The another constructor of class User
	*/
	User(std::string s, std::string passw, std::string type);
	/*!
	Constructor of class User
	*/
	~User();
	/*!
	Destructor of class User
	*/
	void init(std::string s, std::string passw, std::string access);
	/*!
	Initialize an object of class User
	*/
	void log_out(std::string s);
	/*!
	The user logs out from system
	*/
	void init_file(std::string filename);
	/*!
	Initialize private members of the class from file
	*/
	std::ofstream& output(std::fstream file, User u);
	/*!
	Output object method
	*/
	void add_users(std::string filename, std::string str1, std::string str2);
	/*!
	Add user in the system
	*/
	void remove_users(std::string filename, std::string str1);
	/*!
	Remove user from the system
	*/
};
