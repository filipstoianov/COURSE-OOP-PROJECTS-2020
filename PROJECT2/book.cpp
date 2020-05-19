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
void Book::book_add(std::string filename,std::string s1, std::string s2, std::string s3, std::string s4, std::string s5, std::string s6, std::string s7, std::string s8)
{
	std::string st;
	std::string s;
	std::string all;
	this->author = s1;
	author_.push_back(this->author);
	all += this->author;
	st += this->author;
	st += '\n';
	s += this->author;
	s += '\n';
	this->title = s2;
	st += this->title;
	st += '\n';
	s += this->title;
	s += '\n';
	all += '\n';
	all+= this->title;
	title_.push_back(this->title);
	this->genre = s3;
	st += this->genre;
	st += '\n';
	s += this->genre;
	s += '\n';
	all += '\n';
	all += this->genre;
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
	all += '\n';
	all += this->isbn;
	all += '\n';
	all_content.push_back(st);
	st.clear();
	save.push_back(s);
	s.clear();
	all_.push_back(all);
	all.clear();
	std::fstream my_file;
	my_file.open(filename, std::ios::out|std::ios::trunc);

	for (int i = 0; i < all_content.size(); i++)
	{
		my_file << all_content[i];
	}
	my_file.close();
}
void Book::sort_asc(std::vector < std::string> v)
{
	std::string swap;
	for (int i = 0; i < v.size()-1; i++)
	{
		for (int j = i + 1; j < v.size(); j++)
		{
			if (v[i]>v[j])
			{
				swap = v[i];
				v[i]= v[j];
				v[j] = swap;
			}
		}
	}
}
void Book::sort_desc(std::vector < std::string> v)
{
	std::string swap;
	for (int i = 0; i < v.size() - 1; i++)
	{
		for (int j = i + 1; j < v.size(); j++)
		{
			if (v[i] < v[j])
			{
				swap = v[i];
				v[i] = v[j];
				v[j] = swap;
			}
		}
	}
}
void Book::remove_book(std::string filename, std::string title)
{
	std::fstream my_file;
	std::string res;
	size_t found = 0;
	for (int i = 0; i < all_content.size(); i++)
	{
		found = all_content[i].find(title);
		if (found != std::string::npos)
		{
			all_content.erase(all_content.begin()+i);
			all_.erase(all_.begin()+i);
			ibn.erase(ibn.begin()+i);
			title_.erase(title_.begin()+i);
			author_.erase(author_.begin() + i);
			tag_.erase(tag_.begin() + i);
			year_.erase(year_.begin() + i);
			rating_.erase(rating_.begin() + i);
		}
	}
	my_file.open(filename, std::ios::out | std::ios::trunc);

	for (int i = 0; i < all_content.size(); i++)
	{
		my_file << all_content[i];
	}
	my_file.close();

}
void Book::books_all() 
{
	for (int i = 0; i < all_.size(); i++)
	{
		std::cout << "Information about the following book:" << std::endl;
		std::cout << all_[i];
	}
}
void Book::print_all()
{
	for (int i = 0; i <tag_.size(); i++)
	{
		std::cout << tag_[i] << std::endl;
	}
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
	bool f = false;
	for (int i = 0; i < ibn.size(); i++)
	{
		if (ibn[i] == ISBN)
		{
			f = true;
		}
		if (f)
		{
			std::cout << "Info book::" << std::endl;
			std::cout << all_content[i] << std::endl;
			break;
		}
		else
		{
			std::cout << "The book is not available in this library.";
		    std::cout<< "Check your ISBN."<< std::endl;
		}
	}
}
void Book::books_find(std::string s1,std::string s2)
{
	bool f1 = false;
	bool f2 = false;
	bool f3 = false;
	int index = 0;
	if (s1 == "author")
	{
		for (int i = 0; i < author_.size(); i++)
		{
			if (author_[i]==s2)
			{
				f1 = true;
				index = i;
				break;
			}
		}
		if (f1)
		{
			std::cout << "YES, THIS BOOK IS ACCEPTABLE" << "\n" << all_content[index] << std::endl;
		}
		else
		{
			std::cout << "NO,THIS BOOK IS NOT ACCEPTABLE IN OUR LIBRARY" << std::endl;
		}
	}
	if (s1 == "title")
	{
		for (int i = 0; i < title_.size(); i++)
		{
			if (title_[i]==s2)
			{
				f2 = true;
				index = i;
				break;
			}
		}
		if (f2)
		{
			std::cout << "YES, THIS BOOK IS ACCEPTABLE" << "\n" << all_content[index] << std::endl;
		}
		else
		{ 
			std::cout << "NO,THIS BOOK IS NOT ACCEPTABLE IN OUR LIBRARY" << std::endl;
		}
	}
	if (s1 == "tag")
	{
		for (int i = 0; i < tag_.size(); i++)
		{
			if (tag_[i]==s2)
			{
				f3 = true;
				index = i;
				break;
			}
		}
		if (f3)
		{
			std::cout << "YES, THIS BOOK IS ACCEPTABLE" << "\n" << all_content[index] << std::endl;
		}
		else
		{
			std::cout << "NO,THIS BOOK IS NOT ACCEPTABLE IN OUR LIBRARY" << std::endl;
		}
	}
}


void Book::books_sort(std::string s1,std::string s2)
{
	if (s1=="asc" || s1=="\0")
	{
		if (s2 == "title")
		{
			sort_asc(all_content);
			for (int i = 0; i < title_.size(); i++)
			{
				std::cout << all_content[i] << std::endl; 
			}
		}
		if (s2 == "author")
		{
			sort_asc(all_content);
			for (int i = 0; i < author_.size(); i++)
			{
				std::cout << all_content[i] << std::endl;
			}
		}
		if (s2 == "year")
		{
			sort_asc(all_content);
			for (int i = 0; i < year_.size(); i++)
			{
				std::cout << all_content[i] << std::endl;
			}
		}
		if (s2 == "rating")
		{
			sort_asc(all_content);
			for (int i = 0; i <rating_.size(); i++)
			{
				std::cout << all_content[i] << std::endl;
			}
		}
	}
	if (s1 == "desc")
	{
		if (s2 == "title")
		{
			sort_desc(all_content);
			for (int i = 0; i < title_.size(); i++)
			{
				std::cout << all_content[i] << std::endl; 
			}
		}
		if (s2 == "author")
		{
			sort_desc(all_content);
			sort_desc(all_content);
			for (int i = 0; i < author_.size(); i++)
			{
				std::cout << all_content[i] << std::endl; 
			}
		}
		if (s2 == "year")
		{
			sort_desc(all_content);
			for (int i = 0; i < year_.size(); i++)
			{
				std::cout << all_content[i] << std::endl; 
			}
		}
		if (s2 == "rating")
		{
			sort_desc(all_content);
			for (int i = 0; i < rating_.size(); i++)
			{
				std::cout << all_content[i] << std::endl; 
 			}
		}
	}
}
