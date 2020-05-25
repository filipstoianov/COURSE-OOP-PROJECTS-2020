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
/*!
Functions which separate the enter string in words
*/

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



int main()
{
	User n;
	std::string str;
	/*!
	Commands:
	*/
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
	std::string s1;
	std::string s2;
	std::string s3;
	std::string s4;
	std::string s5;
	std::string s6;
	std::string s7;
	std::string s8;;
	std::string filename;
	file.open("Users.txt", std::ios::out);
	file << "admin"<<" "<< "i<3c++"<< std::endl;
	file.close();
	/*!
	Enter command
	*/
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
				filename = word2;

			}
			else
			{
				n.init_file_book(word2);
				std::cout << "Succesfully opened!" << std::endl;
				filename = word2;

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
			file.open(filename, std::ios::out | std::ios::trunc);
			std::string s;
			s = n.copy();
			file << s;
			file.close();
			std::cout << "Successfully saved in the same file" << std::endl;
		}
		if (strcmp(word1, command4) == 0)
		{
			file.close();
			std::fstream new_file;
			new_file.open(word2, std::ios::out);
			std::string s;
			s = n.copy();
			new_file << s;
			new_file.close();
			std::cout << "Successfully saved in the another file" << std::endl;
			s.clear();
		}
		if (strcmp(word1, command5) == 0)
		{
			std::cout << "The following commands are supported :" << std::endl;
			std::cout << "open <file>	opens <file>" << std::endl;
			std::cout << "close 	    closes currently opened file" << std::endl;
			std::cout << "save	     	saves the currently open file" << std::endl;
			std::cout << "saveas <file>	saves the currently open file in <file>" << std::endl;
			std::cout << "help\" \"			prints this information" << std::endl;
			std::cout << "exit\" \"			exists the program" << std::endl;
			std::cout << "login <username> <password>  login the program" << std::endl;
			std::cout << "logout <username>           logout the program" << std::endl;
			std::cout << "books_all\" \"  the whole information about the books" << std::endl;
			std::cout << "books_info <isbn_value>    prints the information about the book with this isbn " << std::endl;
			std::cout << "books_find <option><option_string>  prints the information about this book" << std::endl;
			std::cout << "books_sort <option> <(asc)|desc>    sort the books" << std::endl;
			std::cout << "users_add <username> <password> the administrator adds a new user in the system" << std::endl;
			std::cout << "users_remove <username> the administrator removes the user from the system" << std::endl;
			std::cout << "books_add <author> <title> <genre> <desription> <published year> <key_words> <rating> <isbn>       add book in the library" << std::endl;
			std::cout << "books_remove <title>          the administrator removes this book from the library" << std::endl;

		}
		if (strcmp(word1, command6) == 0)
		{
			std::cout << "EXITING THE PROGRAM..." << std::endl;
			break;

		}
		if (strcmp(word1, command7) == 0)
		{
			word2 = separate_string1(word2);
			word3 = separate_string2(word2);
			n.init_file("Users.txt");
			n.log_in(word2, word3);
		}
		if (strcmp(word1, command8) == 0)
		{
			n.log_out(word2);

		}
		if (strcmp(word1, command9) == 0)
		{
			n.books_all();
		}
		if (strcmp(word1, command10) == 0)
		{
			n.book_info(filename, word2);

		}
		if (strcmp(word1, command11) == 0)
		{
			word3 = separate_string2(word2);
			word2 = separate_string1(word2);
			n.books_find(filename, word2, word3);

		}
		if (strcmp(word1, command12) == 0)
		{
			word3 = separate_string2(word2);
			word2 = separate_string1(word2);
			n.books_sort(filename, word2, word3);

		}
		if (strcmp(word1, command13) == 0)
		{
			word3 = separate_string2(word2);
			word2 = separate_string1(word2);
			n.add_users("Users.txt", word2, word3);

		}
		if (strcmp(word1, command14) == 0)
		{
			n.remove_users("Users.txt", word2);
		}
		if (strcmp(word1, command15) == 0)
		{

			std::getline(std::cin, s1);
			std::getline(std::cin, s2);
			std::getline(std::cin, s3);
			std::getline(std::cin, s4);
			std::getline(std::cin, s5);
			std::getline(std::cin, s6);
			std::getline(std::cin, s7);
			std::getline(std::cin, s8);
			n.book_add(filename, s1, s2, s3, s4, s5, s6, s7, s8);
		}
		if (strcmp(word1, command16) == 0)
		{
			n.remove_book(filename, word2);

		}


		if (strcmp(word1, command1) != 0 && strcmp(word1, command2) != 0 && strcmp(word1, command3) != 0 && strcmp(word1, command4) != 0 && strcmp(word1, command5) != 0
			&& strcmp(word1, command6) != 0 && strcmp(word1, command7) != 0 && strcmp(word1, command8) != 0 && strcmp(word1, command9) != 0 && strcmp(word1, command10) != 0 &&
			strcmp(word1, command11) != 0 && strcmp(word1, command12) != 0 && strcmp(word1, command13) != 0 && strcmp(word1, command14) != 0 && strcmp(word1, command15) != 0
			&& strcmp(word1, command16) != 0)
		{
			std::cout << "Invalid input. Please,enter help\" \"" << std::endl;
		}
	}


	return 0;
}