#include<iostream>
#include"user.h"
#include"book.h"
#include<string>
#include<fstream>



int main()
{
	User n;
	std::fstream file;
	std::string filename = "Users.txt";
	file.open(filename, std::ios::in);
	file.close();
	n.print_administrator();
	n.init_file(filename);
	n.add_users(filename,"Maria","19.02.2000");
	n.add_users(filename, "Ivan", "19.02.2000");
	n.add_users(filename, "Dragan", "19.02.2000");
	n.add_users(filename, "Simona", "samolevski");
	n.add_users(filename, "Peter", "samolevski");
	n.remove_users(filename, "Ivan");
	n.remove_users(filename, "Simona");
	n.add_users(filename, "Gerge", "12314");

	

	Book h;
	std::fstream my_file;
	std::string book_filename="Library.txt";
	h.book_add(book_filename, "Filip", "Harry Potter", "fantasy", "This is the most interesting book in the world", "2020", "fantasy,magic,world", "7.00", "190");
	h.book_add(book_filename, "Filip", "LOVE AND LIVE", "fantasy", "This is the most interesting book in the world", "2020", "fantasy,magic,world", "7.00", "117");
	h.remove_book(book_filename,"Harry Potter");
	h.book_add(book_filename, "Steven King", "Star Wars", "action", "This is an amazing book","2021" ,"stars,world", "7.00", "203");
	h.print_all();
	h.books_all();
	h.book_info("203");
	h.books_find("tag","");
	




	return 0;
}