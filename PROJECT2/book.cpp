#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include"book.h"

Book::Book()
{

}
Book::~Book()
{

}
Book::Book(std::string s1, std::string s2, std::string s3, std::string s4, std::string s5, std::string s6, std::string s7, std::string s8)
{
	init_book(s1,s2,s3,s4,s5,s6,s7,s8);
}
std::string storage;
void Book::book_add(std::string s1, std::string s2, std::string s3, std::string s4, std::string s5, std::string s6, std::string s7, std::string s8)
{
	std::string st;
	std::string s;
	this->author = s1;
	st += this->author;
	st += '\n';
	author_.push_back(this->author);
	st += this->author;
	st += '\n';
	s += this->author;
	s += '\n';
	this->title = s2;
	st += this->title;
	st += '\n';
	s += this->title;
	s += '\n';
	title_.push_back(this->title);
	this->genre = s3;
	st += this->genre;
	st += '\n';
	s += this->genre;
	s += '\n';
	this->description = s4;
	st += this->description;
	st += '\n';
	this->year_published = s5;
	st += this->year_published;
	st += '\n';
	year_.push_back(this->year_published);
	this->key_words = s6;
	st += this->key_words;
	st += '\n';
	tag_.push_back(this->key_words);
	this->rating = s7;
	st += this->rating;
	st += '\n';
	rating_.push_back(this->rating);
	this->isbn = s8;
	ibn.push_back(this->isbn);
	s += this->isbn;
	s += '\n';
	st += this->isbn;
	st += '\n';
	all_content.push_back(st);
	st.clear();
	save.push_back(s);
	s.clear();
}
void Book::init_book(std::string s1, std::string s2, std::string s3, std::string s4, std::string s5, std::string s6, std::string s7, std::string s8)
{
	std::string s;
	std::string st;
	this->author = s1;
	s += this->author;
	s += '\n';
	st += this->author;
	st += '\n';
	author_.push_back(this->author);
	this->title = s2;
	st += this->title;
	st += '\n';
	s += this->title;
	s += '\n';
	title_.push_back(this->title);
	this->genre = s3;
	st += this->genre;
	st += '\n';
	s += this->genre;
	s += '\n';
	this->description = s4;
    st += this->description;
	st += '\n';
	this->year_published = s5;
	st += this->year_published;
	st += '\n';
	year_.push_back(this->year_published);
	this->key_words = s6;
	st += this->key_words;
	st += '\n';
	tag_.push_back(key_words);
	this->rating = s7;
	st += this->rating;
	st += '\n';
	rating_.push_back(this->rating);
	this->isbn = s8;
	ibn.push_back(this->isbn);
	st += this->isbn;
	st += '\n';
	s += this->isbn;
	s += '\n';
	all_content.push_back(st);
	st.clear();
	save.push_back(s);
	s.clear();
}
void Book::init_file_book(std::string filename)
{
	storage.clear();
	std::fstream file;
	std::string object;
	std::string str;
	std::size_t found1;
	std::size_t found2;
	file.open(filename, std::ios::in);
	if (file.good())
	{
		while (getline(file, object, '\n'))
		{
			str = object;
			storage += str;
			storage += '\n';
			
		}
	}
	file.close();

}
void Book::book_info(std::string ISBN)
{
	for (int i = 0; i < ibn.size(); i++)
	{
		if (ibn[i] == ISBN)
		{
			std::cout << "Info book::" << all_content[i] << std::endl;
			break;
		}
	}
}
void Book::books_find(std::string s1,std::string s2)
{
	bool f1 = false;
	bool f2 = false;
	bool f3 = false;
	if (s1 == "author")
	{
		for (int i = 0; i < author_.size(); i++)
		{
			if (s2 == author_[i])
			{
				f1 = true;
				std::cout << "YES, THIS BOOK IS ACCEPTABLE" << "\n" << all_content[i] << std::endl;
				break;
			}
		}
		if (f1 == false)
		{
		
			std::cout << "NO" << std::endl;
		}
	}
	if (s1 == "title")
	{
		for (int i = 0; i < title_.size(); i++)
		{
			if (s2 == title_[i])
			{
				f2 = true;
				std::cout << "YES, THIS BOOK IS ACCEPTABLE" << "\n" << all_content[i] << std::endl;
				break;
			}
		}
		if (f2 == false)
		{

			std::cout << "NO" << std::endl;
		}
	}
	if (s1 == "tag")
	{
		for (int i = 0; i < tag_.size(); i++)
		{
			if (s2 == tag_[i])
			{
				f3 = true;
				std::cout << "YES, THIS BOOK IS ACCEPTABLE" << "\n" << all_content[i] << std::endl;
				break;
			}
		}
		if (f3 == false)
		{

			std::cout << "NO" << std::endl;
		}
	}
}


void Book::books_sort(std::string s1,std::string s2)
{
	if (s1=="asc" || s1=="\0")
	{
		if (s2 == "title")
		{
			for (int i = 0; i < title_.size(); i++)
			{
				//std::cout << all_content[i] << std::endl; sort asc  -> vector title_
			}
		}
		if (s2 == "author")
		{
			for (int i = 0; i < author_.size(); i++)
			{
				//std::cout << all_content[i] << std::endl; sort asc  -> vector author_
			}
		}
		if (s2 == "year")
		{
			for (int i = 0; i < year_.size(); i++)
			{
				//std::cout << all_content[i] << std::endl; sort asc  -> vector year_
			}
		}
		if (s2 == "rating")
		{
			for (int i = 0; i <rating_.size(); i++)
			{
				//std::cout << all_content[i] << std::endl; sort asc  -> vector rating_
			}
		}
	}
	if (s1 == "desc")
	{
		if (s2 == "title")
		{
			for (int i = 0; i < title_.size(); i++)
			{
				//std::cout << all_content[i] << std::endl; sort desc  -> vector title_
			}
		}
		if (s2 == "author")
		{
			for (int i = 0; i < author_.size(); i++)
			{
				//std::cout << all_content[i] << std::endl; sort desc  -> vector author_
			}
		}
		if (s2 == "year")
		{
			for (int i = 0; i < year_.size(); i++)
			{
				//std::cout << all_content[i] << std::endl; sort desc  -> vector year_
			}
		}
		if (s2 == "rating")
		{
			for (int i = 0; i < rating_.size(); i++)
			{
				//std::cout << all_content[i] << std::endl; sort desc  -> vector rating_
 			}
		}
	}
}
