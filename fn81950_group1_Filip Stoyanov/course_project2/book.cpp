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
	this->author.clear();
	this->title.clear();
	this->genre.clear();
	this->description.clear();
	this->year_published.clear();
	this->key_words.clear();
	this->rating.clear();
	this->isbn.clear();
	save.clear();
	all_content.clear();
	ibn.clear();
	title_.clear();
	author_.clear();
	tag_.clear();
	year_.clear();
	rating_.clear();
	all_.clear();
}
Book::Book(std::string s1, std::string s2, std::string s3, std::string s4, std::string s5, std::string s6, std::string s7, std::string s8)
{
	init_book(s1, s2, s3, s4, s5, s6, s7, s8);
}
Book::Book(std::string filename)
{
	init_file_book(filename);
}
std::string storage;
void Book::book_add(std::string filename, std::string s1, std::string s2, std::string s3, std::string s4, std::string s5, std::string s6, std::string s7, std::string s8)
{
	this->author = "Author:";
	std::string st;
	std::string s;
	std::string all;
	this->author += s1;
	author_.push_back(this->author);
	all += this->author;
	st += this->author;
	st += '\n';
	s += this->author;
	s += '\n';
	this->title = "Title:";
	this->title += s2;
	st += this->title;
	st += '\n';
	s += this->title;
	s += '\n';
	all += '\n';
	all += this->title;
	title_.push_back(this->title);
	this->genre = "Genre:";
	this->genre += s3;
	st += this->genre;
	st += '\n';
	s += this->genre;
	s += '\n';
	all += '\n';
	all += this->genre;
	this->description = "Description:";
	this->description += s4;
	st += this->description;
	st += '\n';
	this->year_published = "Year:";
	this->year_published += s5;
	st += this->year_published;
	st += '\n';
	year_.push_back(this->year_published);
	this->key_words = "Key_words:";
	this->key_words += s6;
	st += this->key_words;
	st += '\n';
	tag_.push_back(this->key_words);
	this->rating = "Rating:";
	this->rating += s7;
	st += this->rating;
	st += '\n';

	rating_.push_back(this->rating);
	this->isbn = "ISBN:";
	this->isbn += s8;
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
	my_file.open(filename, std::ios::out | std::ios::app);
	my_file << all_content[all_content.size() - 1];
	std::cout << "This command is being done succesfully." << std::endl;
	my_file.close();

}
std::vector<std::string> Book::sort_asc(std::vector<std::string> v)
{
	std::string swap;
	for (int i = 0; i < v.size() - 1; i++)
	{
		for (int j = i + 1; j < v.size(); j++)
		{
			if (v[i] > v[j])
			{
				swap = v[i];
				v[i] = v[j];
				v[j] = swap;
			}
		}
	}
	return v;
}
std::vector<std::string> Book::sort_desc(std::vector< std::string> v)
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
	return v;
}
void Book::remove_book(std::string filename, std::string title)
{
	std::fstream my_file;
	std::string res;
	title.insert(0, "Title:");
	size_t found = 0;
	for (int i = 0; i < all_content.size(); ++i)
	{
		found = title_[i].find(title);
		if (found != std::string::npos)
		{
			all_content.erase(all_content.begin() + i);
			all_.erase(all_.begin() + i, all_.end());
			ibn.erase(ibn.begin() + i);
			title_.erase(title_.begin() + i);
			author_.erase(author_.begin() + i);
			tag_.erase(tag_.begin() + i);
		}
	}
	std::cout << "This command is being done succesfully." << std::endl;
	my_file.open(filename, std::ios::out | std::ios::trunc);
	for (int i = 0; i < all_content.size(); ++i)
	{
		my_file << all_content[i];
	}
	my_file.close();
}
void Book::books_all()
{
	std::cout << "Information about the books:" << std::endl;
	for (int i = 0; i < all_.size(); ++i)
	{
		std::cout << all_[i];
	}
	std::cout << std::endl;
}
std::string Book::copy()
{
	std::string res;
	for (int i = 0; i < all_content.size(); i++)
	{
		res += all_content[i];
	}
	return res;
}
void Book::init_book(std::string s1, std::string s2, std::string s3, std::string s4, std::string s5, std::string s6, std::string s7, std::string s8)
{

	this->author = s1;
	this->title = s2;
	this->genre = s3;
	this->description = s4;
	this->year_published = s5;
	this->key_words = s6;
	this->rating = s7;
	this->isbn = s8;


}
void Book::init_file_book(std::string filename)
{
	storage.clear();
	std::fstream file;
	std::string object;
	std::string str;
	std::size_t found1;
	std::size_t found2;
	std::size_t found3;
	std::size_t found4;
	std::size_t found5;
	std::size_t found6;
	size_t br = 0;
	std::string info;
	file.open(filename, std::ios::in);
	if (file.good())
	{
		while (getline(file, object, '\n'))
		{
			str = object;
			storage += str;
			br++;
			storage += '\n';
			found1 = object.find("Author:");
			found2 = object.find("Title:");
			found3 = object.find("Year:");
			found4 = object.find("Key_words:");
			found5 = object.find("ISBN:");
			if (found1 != std::string::npos)
			{
				author_.push_back(object);
				info += object;
				info += '\n';
			}
			if (found2 != std::string::npos)
			{
				title_.push_back(object);
				info += object;
				info += '\n';
			}
			if (found3 != std::string::npos)
			{
				year_.push_back(object);
			}
			if (found4 != std::string::npos)
			{
				tag_.push_back(object);
				info += object;
				info += '\n';
			}
			if (found5 != std::string::npos)
			{
				ibn.push_back(object);
				info += object;
				info += '\n';
			}
			all_.push_back(info);
			info.clear();
			if (br == 8)
			{
				all_content.push_back(storage);
				storage.clear();
				br = 0;
			}
		}
	}
	file.close();

}
void Book::book_info(std::string filename, std::string ISBN)
{
	bool f = false;
	ISBN.insert(0, "ISBN:");
	for (int i = 0; i < ibn.size(); ++i)
	{
		if (ISBN == ibn[i])
		{
			std::cout << "Info book:" << std::endl;
			std::cout << all_content[i] << std::endl;
			f = true;
		}
	}
	if (f == false)
	{
		std::cout << "The book is not available in this library.";
		std::cout << "Check your ISBN." << std::endl;
	}
}
void Book::books_find(std::string filename, std::string s1, std::string s2)
{
	init_file_book(filename);
	bool f1 = false;
	bool f2 = false;
	bool f3 = false;
	size_t found = 0;
	int index = 0;
	if (s1 == "author")
	{
		s2.insert(0, "Author:");
		for (int i = 0; i < author_.size(); i++)
		{
			found = author_[i].find(s2);
			if (found != std::string::npos)
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
		s2.insert(0, "Title:");
		for (int i = 0; i < title_.size(); i++)
		{
			if (title_[i] == s2)
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
		//s2.insert(0, "Key_words:");
		for (int i = 0; i < tag_.size(); i++)
		{
			found = tag_[i].find(s2);
			if (found != std::string::npos)
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


void Book::books_sort(std::string filename, std::string s1, std::string s2)
{
	std::vector<std::string>changed;
	if (s1 == "asc")
	{
		if (s2 == "title")
		{
			changed = sort_asc(title_);
			for (int i = 0; i < changed.size(); i++)
			{
				for (int j = 0; j < title_.size(); j++)
				{
					if (changed[i] == title_[j])
					{
						std::cout << all_content[j];
					}
				}
			}
			std::cout << "This command is being done succesfully." << std::endl;
		}
		if (s2 == "author")
		{
			changed = sort_asc(author_);
			for (int i = 0; i < changed.size(); i++)
			{
				for (int j = 0; j < author_.size(); j++)
				{
					if (changed[i] == author_[j])
					{
						std::cout << all_content[j];
					}
				}
			}
		}
		if (s2 == "year")
		{
			changed = sort_asc(year_);
			for (int i = 0; i < changed.size(); i++)
			{
				for (int j = 0; j < year_.size(); j++)
				{
					if (changed[i] == year_[j])
					{
						std::cout << all_content[j];
					}
				}
			}
			std::cout << "This command is being done succesfully." << std::endl;
		}
		if (s2 == "rating")
		{
			changed = sort_asc(rating_);
			for (int i = 0; i < changed.size(); i++)
			{
				for (int j = 0; j < rating_.size(); j++)
				{
					if (changed[i] == rating_[j])
					{
						std::cout << all_content[j];
					}
				}
			}
			std::cout << "This command is being done succesfully." << std::endl;
		}
	}
	if (s1 == "desc")
	{
		if (s2 == "title")
		{
			changed = sort_desc(title_);
			for (int i = 0; i < changed.size(); i++)
			{
				for (int j = 0; j < title_.size(); j++)
				{
					if (changed[i] == title_[j])
					{
						std::cout << all_content[j];
					}
				}
			}
			std::cout << "This command is being done succesfully." << std::endl;
		}
		if (s2 == "author")
		{
			changed = sort_desc(author_);
			for (int i = 0; i < changed.size(); i++)
			{
				for (int j = 0; j < author_.size(); j++)
				{
					if (changed[i] == author_[j])
					{
						std::cout << all_content[j];
					}
				}
			}
		}
		if (s2 == "year")
		{
			changed = sort_desc(year_);
			for (int i = 0; i < changed.size(); i++)
			{
				for (int j = 0; j < year_.size(); j++)
				{
					if (changed[i] == year_[j])
					{
						std::cout << all_content[j];
					}
				}
			}
			std::cout << "This command is being done succesfully." << std::endl;
		}
		if (s2 == "rating")
		{
			changed = sort_desc(rating_);
			for (int i = 0; i < changed.size(); i++)
			{
				for (int j = 0; j < rating_.size(); j++)
				{
					if (changed[i] == rating_[j])
					{
						std::cout << all_content[j];
					}
				}
			}
			std::cout << "This command is being done succesfully." << std::endl;
		}
	}
}