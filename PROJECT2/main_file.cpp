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
	//n.print_clients(filename);

	
	n.log_in("Dragan", "1asdada");
	n.log_in("Maria", "19.02.2000");
	n.log_in("Maria", "19.02.2000");
	n.log_in("Maria", "19dad");
	n.log_in("Maria", "19dad");


	




	return 0;
}