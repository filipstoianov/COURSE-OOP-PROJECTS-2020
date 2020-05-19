#include<iostream>
#include"user.h"
#include"book.h"
#include<string>
#include<fstream>
char* separate_string2(std::string str1)
{
	size_t len = str1.length();
	char* new_buffer = (char*)(malloc(sizeof(char)));
	size_t ind = 0;
	int save = 0;
	for (int i = 0; i < len; i++)
	{
		if (str1[i] == ' ')
		{
			save = i;
			break;
		}
	}
	new_buffer = new char[len - save];
	for (size_t j = save + 1; j < len; ++j)
	{
		new_buffer[ind] = str1[j];
		ind++;
	}
	new_buffer[ind] = '\0';
	return new_buffer;
}

char* separate_string1(std::string str1)
{
	size_t len = str1.length();
	char* new_buffer = (char*)(malloc(sizeof(char)));
	size_t ind = 0;
	size_t new_length = 0;
	for (size_t i = 0; i < len; ++i)
	{
		if (str1[i] == ' ' || str1[i] == '\0')
		{
			new_length = i;
			break;
		}
	}
	new_buffer = new char[new_length];
	for (size_t j = 0; j < new_length; ++j)
	{
		new_buffer[j] = str1[j];
		ind++;
	}
	new_buffer[new_length] = '\0';
	return new_buffer;
}
char* separate_arg1(std::string str1)
{
	size_t len = str1.length();
	char* new_buffer = (char*)(malloc(sizeof(char)));
	size_t ind = 0;
	size_t new_length = 0;
	for (size_t i = 0; i < len; ++i)
	{
		if (str1[i] == 'R')
		{
			new_length = i;
			break;
		}
	}
	new_buffer = new char[new_length];
	for (size_t j = 0; j < new_length; ++j)
	{
		new_buffer[ind] = str1[j];
		ind++;
	}
	new_buffer[new_length] = '\0';
	return new_buffer;
}
char* separate_arg2(std::string str1)
{
	size_t len = str1.length();
	char* new_buffer = (char*)(malloc(sizeof(char)));
	size_t ind = 0;
	size_t new_length = 0;
	for (size_t i = 0; i < len; ++i)
	{
		if (str1[i] == 'R')
		{
			new_length = i;
			break;
		}
	}
	new_buffer = new char[len - new_length];
	for (size_t j = new_length; j < len; ++j)
	{
		new_buffer[ind] = str1[j];
		ind++;
	}
	new_buffer[len - new_length] = '\0';
	return new_buffer;
}


int main()
{
	User n;
	std::string str;
	const char* command1 = "open";
	const char* command2 = "close";
	const char* command3 = "save";
	const char* command4 = "save-as";
	const char* command5 = "help";
	const char* command6 = "exit";
	const char* command7 = "login";
	const char* command8 = "logout";
	const char* command9 = "books_all";
	const char* command10 = "books_info";
	const char* command11 = "books_find";
	const char* command12 = "books_sort";
	const char* command13 = "users_add";
	const char* command14 = "users_remove";
	const char* command15 = "books_add";
	const char* command16 = "books_remove";
	std::fstream file;
	std::fstream file_new;
	char* word1 = (char*)(malloc(sizeof(char)));
	char* word2 = (char*)(malloc(sizeof(char)));
	char* word3 = (char*)(malloc(sizeof(char)));
	char* name = (char*)(malloc(sizeof(char)));
	while (true)
	{
		std::getline(std::cin, str);
		word1 = separate_string1(str);
		word2 = separate_string2(str);
		if (strcmp(word1, command1) == 0)
		{
			file.open(word2, std::ios::in);
			if (!file)
			{
				file_new.open(word2, std::ios::out);
				std::cout << "Succesfully created new file with the same name!" << std::endl;

			}
			else
			{
				n.init_file(word2);
				std::cout << "Succesfully opened!";

			}

		}
		if (strcmp(word1, command2) == 0)
		{

			file.close();
			std::cout << "Successfully closed" << std::endl;
		}
		if (strcmp(word1, command3) == 0)
		{
			file.close();
			file.open(word2, std::ios::out | std::ios::trunc);
			std::string s;
			for (int i = 0; i < s.length(); i++)
			{
				file << s[i];
			}
			file.close();
			std::cout << "Successfully saved in the same file" << std::endl;
		}
		if (strcmp(word1, command4) == 0)
		{
			file.close();
			std::fstream new_file;
			new_file.open(word2, std::ios::out);
			std::string s;
			for (int i = 0; i < s.length(); i++)
			{
				new_file << s[i];
			}
			new_file.close();
			std::cout << "Successfully saved in the another file" << std::endl;
			s.clear();
		}
		if (strcmp(word1, command5) == 0)
		{
			std::cout << "The following commands are supported :" << std::endl;
			std::cout << "open <file>	opens <file>" << std::endl;
			std::cout << "close <file>	closes currently opened file" << std::endl;
			std::cout << "save	<file>	saves the currently open file" << std::endl;
			std::cout << "saveas <file>	saves the currently open file in <file>" << std::endl;
			std::cout << "help\" \"			prints this information" << std::endl;
			std::cout << "exit\" \"			exists the program" << std::endl;

		}
		if (strcmp(word1, command6) == 0)
		{
			std::cout << "EXITING THE PROGRAM..." << std::endl;
			break;

		}
		if (strcmp(word1, command7) == 0 && word2=='\0')
		{
			std::cout << "Enter username:";
			std::cin >> word2;
			std::cout << "Enter password:";
			std::cin >> word3;
			n.log_in(word2,word3);
		}
		if (strcmp(word1, command8) == 0)
		{
			n.log_out(word2);
			std::cout << "This command is being done succesfully." << std::endl;
		}
		if (strcmp(word1, command9) == 0)
		{
			n.books_all();
			std::cout << "This command is being done succesfully." << std::endl;
		}
		if (strcmp(word1, command10) == 0)
		{
			n.book_info(word2);
			std::cout << "This command is being done succesfully." << std::endl;
		}
		if (strcmp(word1, command11) == 0)
		{
			word3 = separate_arg2(word2);
			n.books_find(word2,word3);
			std::cout << "This command is being done succesfully." << std::endl;
		}
		if (strcmp(word1, command12) == 0)
		{
			word3 = separate_arg2(word2);
			n.books_sort(word2, word3);
			std::cout << "This command is being done succesfully." << std::endl;
		}
		if (strcmp(word1, command13) == 0)
		{
			word3 = separate_arg2(word2);
			n.add_users("Users.txt",word2, word3);
			std::cout << "This command is being done succesfully." << std::endl;
		}
		if (strcmp(word1, command14) == 0)
		{
			n.remove_users("Users.txt", word2);
			std::cout << "This command is being done succesfully." << std::endl;
		}
		if (strcmp(word1, command15) == 0)
		{
			//n.book_add();
			std::cout << "This command does not work succesfully." << std::endl;
		}
		if (strcmp(word1, command16) == 0)
		{
			//n.remove_book("Users.txt", word2);
			std::cout << "This command does not work succesfully." << std::endl;
		}
		

		if (strcmp(word1, command1) != 0 && strcmp(word1, command2) != 0 && strcmp(word1, command3) != 0 && strcmp(word1, command4) != 0 && strcmp(word1, command5) != 0
			&& strcmp(word1, command6) != 0 && strcmp(word1, command7) != 0 && strcmp(word1, command8) != 0 && strcmp(word1,command9)!=0 && strcmp(word1, command10) != 0 && 
			strcmp(word1, command11) != 0 && strcmp(word1, command12) != 0 && strcmp(word1, command13) != 0 && strcmp(word1, command14) != 0)
		{
			std::cout << "Invalid input. Please,enter help\" \"" << std::endl;
		}
	}

	
	return 0;
}