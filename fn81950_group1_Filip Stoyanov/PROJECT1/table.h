#pragma once
#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<fstream>
class table
{
	/*!
	my_class table
	*/
private:
	/*!
	 These are private members of the class Table
	*/
	std::string str; 
	/*!
	 Save content of file
	*/
	int* index = (int*)(malloc(sizeof(int)));
	/*
	Save positions of symbols '|' and '\n'
	*/
	int size = 0;
	int max_rps = 0;
	int max_word = 0;

public:
	/*!
	 All methods used in this prrogram
	*/
	table(); 
/*! 
 The constructor of class table
*/
	table(std::string str_new); 
	/*!
     The another constructor of class table
    */
	~table();
	/*!
      The destructor of class table
    */
	std::string call_to(int conter_cell);
	/*!
	Take value of this cell
	*/
	int point(std::string s);
	/*! 
	Return how many symbols '.' there are in the string's content
	*/
	int line();
	/*!
	Return number of lines in the current table
	*/
	void empty();
	/*!
      Delete content of the string "str"
    */
	void formula2(std::string input, std::string cell);
	int position_of_cell(std::string cell_ind);
	/*!
      Return the number of cell's position
    */
	void max_len();
	/*!
   Find the biggest amount of cells in a table's line
    */
	void is_valid();
	std::string convert_again(double degree);
	/*!
     Convert type "double" to type "string"
    */
	double convert_string(std::string s);
	/*!
      Convert type "string" to type "double"
    */
	void change_value(std::string new_str, std::string cell_str);
	/*!
     Change the value of the cell
    */


	double formula_degree(std::string str);
	void check_for();
	/*!
	Check for valid type
	*/
	int count_symbol1(std::string s);
	/*!
      Count the '|' symbols in "str"'
   */
	int count_symbol2();
	/*!
      Count the number of lines in "str"
     */
	void  formula(std::string input, std::string cell);
	/*!
      Change the cell's value with formula
     */
	bool is_digit(std::string str);
	/*!
     Check for whether it is number
    */

	std::string copy();
	/*
	*! Copy the current content of the string 'str'
	*/
	void print();
	/*! 
	Print the current content of the table,file,string
	*/
	void init_file(std::string filename);
	/*!
    This fragment initializes string "str" with the content of file
    */
	void save_file(std::fstream new_file, char* filename);
	/*!
	  Save the changed content in file
	*/
	void init_index();
	/*!
	Save the position of '|' and '\n' symbols in the string array
	Initialize save_index[] array
	*/
	void insert_to();
	/*!
	Add symbols '|' and ',' in string array
	*/

	

};
