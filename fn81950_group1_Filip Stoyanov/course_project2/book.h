#pragma once
#include<iostream>
class Book /*!
		   define class Book
		   */
{
private:
	/*!
	Private members of class Book
	*/
	std::string author;
	std::string title;
	std::string genre;
	std::string description;
	std::string year_published;
	std::string key_words;
	std::string rating;
	std::string isbn;
	std::vector<std::string>save;
	std::vector <std::string>all_content;
	/*!
	Save all information about the books from the library
	*/

	std::vector<std::string>ibn;
	/*!
	Save the isbn of books from the library
	*/

	std::vector<std::string>title_;
	/*!
	Save the titles of books from the library
	*/

	std::vector<std::string>author_;
	/*!
	Save the authors of books from the library
	*/
	std::vector<std::string>tag_;
	/*!
	Save the key_words info of books from the library
	*/
	std::vector<std::string>year_;
	/*!
	Save the published_year of books from the library
	*/
	std::vector<std::string>rating_;
	/*!
	Save the rating of books from the library
	*/
	std::vector<std::string>all_;
	/*!
	Save author,title,genre and rating of books from the library
	*/


public:
	Book();
	/*!
	Constructor of class Book
	*/
	~Book();
	/*!
	Destructor of class Book
	*/
	Book(std::string s1, std::string s2, std::string s3, std::string s4, std::string s5, std::string s6, std::string s7, std::string s8);
	/*!
	The another constructor of class Book
	*/
	void book_add(std::string s, std::string s1, std::string s2, std::string s3, std::string s4, std::string s5, std::string s6, std::string s7, std::string s8);
	/*!
		This method adds book in library
	*/
	void init_book(std::string s1, std::string s2, std::string s3, std::string s4, std::string s5, std::string s6, std::string s7, std::string s8);
	/*!
	 The method initialize object from class Book
	*/
	void init_file_book(std::string filename);
	/*!
	 Read file and save its current indormation in string
	*/
	Book(std::string filename);
	/*!
	*/
	void book_info(std::string filename, std::string ISBN);
	/*!
	Print whole infor about book
	*/
	void books_find(std::string filename, std::string s1, std::string s2);
	/*!
	Find book in library
	*/
	void books_sort(std::string filename, std::string s1, std::string s2);
	/*!
	Sort all books in library (desc and asc sort)
	*/
	void remove_book(std::string filename, std::string title);
	/*!
	Remove book from library
	*/
	std::vector<std::string> sort_asc(std::vector < std::string> v);
	/*!
	Method for asc sort of vector<string>
	*/
	std::vector<std::string>sort_desc(std::vector < std::string> v);
	/*!
	Method for desc sort of vector<string>
	*/
	void books_all();
	/*!
	Print info about book
	*/
	std::string copy();
	/*!
	Copy string
	*/
};