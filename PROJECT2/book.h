#pragma once
#include<iostream>
class Book
{
	private:
	std::string author;
	std::string title;
	std::string genre;
	std::string description;
	std::string year_published;
	std::string key_words;
	std::string rating;
	std::string isbn;
	std::vector<std::string>save;
	std::vector<std::string>all_content;
	std::vector<std::string>ibn;
	std::vector<std::string>title_;
	std::vector<std::string>author_;
	std::vector<std::string>tag_;
	std::vector<std::string>year_;
	std::vector<std::string>rating_;
	

public:
	Book();
	~Book();
	Book(std::string s1, std::string s2, std::string s3, std::string s4, std::string s5, std::string s6, std::string s7, std::string s8);
	void book_add(std::string s1, std::string s2, std::string s3, std::string s4, std::string s5, std::string s6, std::string s7, std::string s8);
	void init_book(std::string s1, std::string s2, std::string s3, std::string s4, std::string s5, std::string s6, std::string s7, std::string s8);
	void init_file_book(std::string filename);
	void book_info(std::string ISBN);
	void books_find(std::string s1, std::string s2);
	void books_sort(std::string s1, std::string s2);
};