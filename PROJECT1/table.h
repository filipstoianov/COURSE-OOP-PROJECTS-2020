#pragma once
#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<fstream>
class table
{
private:
	std::string str;
	int* index = (int*)(malloc(sizeof(int)));
	int size = 0;
	int max_rps = 0;
	int max_word = 0;
public:
	table();
	table(std::string str_new);
	~table();
	std::string call_to(int conter_cell);
	int point(std::string s);
	int line();
	int position_of_cell(std::string cell_ind);
	void max_len();
	bool check_0(std::string my_str);
	std::string to_string(double value);
	std::string convert_again(double degree);
	void recognize_fdegree(std::string input);
	double convert_string(std::string s);
	void init_(std::string input);
	void change_value(std::string new_str, std::string cell_str);
	double formula_degree(std::string str);
	void check_for();
	int count_symbol1(std::string s);
	int count_symbol2();
	void  formula(std::string input, std::string cell);
	bool is_digit(std::string str);
	void edit_with(int number, std::string f);
	std::string copy();
	void print();
	void init_file(std::string filename);
	void save_file(std::fstream new_file, char* filename);
	void init_index();
	void insert_to();

};
