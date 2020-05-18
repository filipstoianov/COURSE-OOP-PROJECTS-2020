#include"table.h"

table::table()
{
	init_file("");
	index = new int[1];
	index[0] = 1;
	this->size = 1;
	this->max_rps = 0;
	this->max_word = 0;
}
table::table(std::string str_new)
{
	init_file(str_new);
}
table::~table()
{
	str.clear();
	index = nullptr;
	delete[]index;

}
int table::position_of_cell(std::string cell_ind)
{
	int pos_of_cell = 0;
	int k = 1;
	std::string s;
	while (cell_ind[k] != 'C')
	{
		s += cell_ind[k];
		k++;
	}
	pos_of_cell = convert_string(s);
	pos_of_cell = (pos_of_cell - 1) * (this->max_rps + 1);
	s.clear();
	k++;
	while (k <= cell_ind.length())
	{
		s += cell_ind[k];
		k++;
	}
	pos_of_cell += convert_string(s);
	return pos_of_cell;
}

int table::point(std::string s)
{
	int br_point = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '.')
		{
			br_point++;
		}
	}

	return br_point;
}

double table::convert_string(std::string s)
{
	std::stringstream geek(s);
	double x = 0;
	geek >> x;
	return x;
}
std::string table::convert_again(double degree)
{
	std::ostringstream sstream;
	sstream << degree;
	std::string varAsString = sstream.str();
	return varAsString;
}

int table::count_symbol1(std::string s)
{
	int count = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '|')
		{
			count++;
		}
	}
	return count;
}
int table::count_symbol2()
{
	int count = 0;
	for (int i = 0; i < this->str.length(); i++)
	{
		if (this->str[i] == '\n')
		{
			count++;
		}
	}
	return count;
}
bool table::is_digit(std::string str)
{
	int ind = 0;
	int br_point = 0;
	for (size_t i = 0; i < str.length(); ++i)
	{
		if ((int(str[i]) - '0' >= 0 && (int)str[i] - '0' <= 9) || str[i] == '-' || str[i] == '+' || str[i] == '\0' || str[i] == '.')
		{
			ind++;
		}
	}
	if (ind == str.length())
	{
		return true;
	}
	return false;
}


void table::print()
{
	int t = 0;
	std::string space;
	for (int i = 0; i < this->size - 1; i++)
	{
		if (index[i + 1] - index[i] - 1 < this->max_word)
		{
			t = this->max_word - (index[i + 1] - index[i]) + 1;
			if (i == 0)
			{
				t--;
			}
			for (int k = 0; k < t; k++)
			{
				space += " ";
			}
		}
		init_index();
		this->str.insert(index[i + 1], space);
		space.clear();
	}

	std::cout << std::endl;
	std::cout << this->str;
	std::cout << std::endl;



}

void table::max_len()
{
	for (int i = 0; i < sizeof(index) - 1; i++)
	{
		if ((index[i + 1] - index[i] - 1) > this->max_word)
		{
			this->max_word = (index[i + 1] - index[i] - 1) + 1;
		}
	}
}
void table::init_file(std::string filename)
{
	std::fstream file(filename);
	std::string words;
	if (file.is_open())
	{
		while (getline(file, words, ','))
		{
			this->str += words;
			this->str += '|';
		}
		file.close();
	}
	insert_to();
}

void table::init_index()
{
	int ind = 0;
	for (int i = 0; i < this->str.length(); i++)
	{
		if (this->str[i] == '|' || this->str[i] == '\n')
		{
			ind++;
		}
	}
	index = new int[ind];
	int br = 1;
	index[0] = 0;
	for (int i = 0; i < this->str.length(); i++)
	{
		if (this->str[i] == '|' || this->str[i] == '\n')
		{
			index[br] = i;
			br++;
		}
	}
	this->size = ind + 1;
	index[ind] = this->str.length() - 1;
	max_len();
}
void  table::insert_to()
{
	int* save;
	int sv_br = count_symbol2() + 2;
	save = new int[sv_br];
	save[0] = 0;
	int sv = 1;
	for (int i = 0; i < this->str.length(); i++)
	{
		if (this->str[i] == '\n')
		{
			save[sv] = i;
			sv++;
		}
	}
	save[sv] = this->str.length();
	int diff = 0;
	int max_ = 0;
	int br_ = 0;


	std::string helper;
	std::string s_new;
	for (int i = 1; i < sv_br; i++)
	{
		if (i != 1)
		{
			save[i - 1] = save[i - 1] + 1;
		}
		br_ = 0;
		for (int j = save[i - 1]; j < save[i]; j++)
		{
			s_new += this->str[j];
		}
		br_ = count_symbol1(s_new);
		if (br_ > max_)
		{
			max_ = br_;
		}
		this->max_rps = max_;
		s_new.clear();
	}



	for (int i = 1; i < sv_br; i++)
	{

		for (int j = save[i - 1]; j < save[i]; j++)
		{
			helper += this->str[j];
		}
		diff = max_ - count_symbol1(helper);
		int sz = this->str.length();
		if (count_symbol1(helper) < max_)
		{
			for (int p = 0; p < diff; p++)
			{
				this->str.insert(save[i] - 1, "|", 1);
			}
			for (int k = i; k < sv_br; k++)
			{
				save[k] = save[k] + diff;
			}
		}
		helper.clear();
	}
}

void table::check_for()
{
	std::string s;
	double d = 0;
	bool f = false;
	std::cout << std::endl;
	std::string new_str;
	int p = 0;
	int j = 0;
	for (int i = 0; i < this->str.length() - 1; i++)
	{
		f = false;
		if (this->str[i] == '=')
		{
			j = i + 1;
			while (this->str[j] != '|' && this->str[j] != '\n')
			{
				s += this->str[j];
				j++;
			}
			for (int p = 0; p < s.length() - 1; p++)
			{
				if (s[p] == '/' && s[p + 1] == '0')
				{
					f = true;
					p = s.length();
				}
			}

			if (f) { new_str = "ERROR"; }
			else
			{
				d = formula_degree(s);
				new_str = convert_again(d);
			}
			this->str.erase(i, j - i);
			this->str.insert(i, new_str);
		}
		s.clear();
	}
}
int table::line()
{
	int br = 0;
	for (int i = 0; i < this->str.length(); i++)
	{
		if (this->str[i] == '\n')
		{
			br++;
		}
	}
	return br;
}
std::string table::call_to(int counter_cell)
{
	std::string res;
	init_index();
	if (counter_cell == 1)
	{
		res += this->str[0];
	}

	for (int i = index[counter_cell - 1] + 1; i < index[counter_cell]; i++)
	{
		res += this->str[i];
	}
	return res;
}
void  table::change_value(std::string new_str, std::string cell_number)
{
	std::string res;
	if (point(new_str) > 1)
	{
		std::cout << "The input is incorrect!Try again!" << std::endl;
		return;
	}
	init_index();
	int number = position_of_cell(cell_number);
	if (new_str.length() > this->max_word) this->max_word = new_str.length();
	if (point(new_str) > 1) std::cout << "Not valid input" << std::endl;
	if (number > 1)
	{
		this->str.replace(this->str.begin() + index[number - 1] + 1, this->str.begin() + index[number], new_str);
	}
	else
	{
		init_index();
		this->str.replace(this->str.begin() + index[number - 1], this->str.begin() + index[number], new_str);
	}
	std::cout << "The change is being done succesfully!" << std::endl;
}
void table::recognize_fdegree(std::string input)
{

	if (input[0] == '=')
	{
		input.erase(input.begin() + 1, input.end());
	}
	double value = formula_degree(input);
	std::string new_str;
	new_str = std::to_string(value);

}


void table::formula(std::string input, std::string cell_ind)
{

	int pos_of_cell = position_of_cell(cell_ind);
	std::string res;
	double new_value = 0;
	std::string change_str;

	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == 'R')
		{
			res += '|';
		}
		if (input[i] == 'C')
		{
			res += ' ';
		}
		if (input[i] != 'C' && input[i] != 'R' && input[i] != '=')
		{
			res += input[i];
		}
	}
	res += '|';
	double number1 = 0;
	double number2 = 0;
	std::string s_new1;
	std::string s_new2;
	int* array1;
	int* array2;
	int ind1 = 0;
	int ind2 = 0;
	int br1 = 0;
	int br2 = 0;
	for (int i = 0; i < res.length(); i++)
	{
		if (res[i] == '|')
		{
			br1++;
		}
		if (res[i] == ' ')
		{
			br2++;

		}

	}
	array1 = new int[br1];
	array2 = new int[br2];
	for (int i = 0; i < res.length(); i++)
	{
		if (res[i] == '|')
		{
			array1[ind1] = i;
			ind1++;
		}
		if (res[i] == ' ')
		{
			array2[ind2] = i;
			ind2++;

		}
	}
	std::string new_str;
	std::string cell;
	bool b = 0;
	bool f = 0;
	for (int i = 0; i < ind1 - 1; i++)
	{
		for (int j = array1[i] + 1; j < array1[i + 1]; j++)
		{
			if (j <= array2[i])
			{
				s_new1 += res[j];
			}
			if (j > array2[i])
			{
				s_new2 += res[j];
			}
		}
		number1 = convert_string(s_new1);
		number1 = (number1 - 1) * (this->max_rps + 1);
		number2 = convert_string(s_new2);
		number1 = number1 + number2;
		if (number2 > (this->max_rps + 1) || ((number1 - number2) / (this->max_rps + 1) - 1) > line())
		{
			cell = '0';
		}

		else
		{
			cell = call_to(number1);
		}

		if (cell.length() < 1 || point(cell) > 1)
		{
			cell = '0';
		}
		s_new1.clear();
		s_new2.clear();
		if (cell == "ERROR")
		{
			new_str = "ERROR";
			b = true;
		}
		else
		{
			new_str += cell;
			if (i < ind1 - 2)
			{
				new_str += input[array1[i + 1]];
			}

		}
	}
	for (int k = 0; k < new_str.length() - 2; k++)
	{
		if ((new_str[k] == '/' && new_str[k + 2] == '0') || (new_str[k] == '/' && ((int)new_str[k + 2] - '0' > 9 || (int)new_str[k + 2] - '0' < 0)) || new_str[k] == 'E')
		{
			f = true;
		}
	}

	if (f == true)
	{
		change_str = "ERROR";
	}
	else
	{
		new_value = formula_degree(new_str);
		change_str += convert_again(new_value);
	}
	if (pos_of_cell > 1)
	{
		this->str.erase(index[pos_of_cell - 1] + 1, index[pos_of_cell] - index[pos_of_cell - 1] - 1);
		this->str.replace(index[pos_of_cell - 1] + 1, 0, change_str);
		std::cout << "The change is being done successfully!" << std::endl;
	}
	else
	{
		this->str.erase(index[pos_of_cell - 1], index[pos_of_cell] - index[pos_of_cell - 1]);
		this->str.replace(index[pos_of_cell - 1], 0, change_str);
		std::cout << "The change is being done successfully!" << std::endl;
	}
	if (pos_of_cell == 1) index[pos_of_cell - 1]++;
	if (change_str.length() > this->max_word) this->max_word = change_str.length();
	array1 = nullptr;
	delete[]array1;
	array2 = nullptr;
	delete[]array2;
}


void table::edit_with(int number, std::string f)
{
	std::string cell = call_to(number);

}
double table::formula_degree(std::string my_str)
{
	bool f = 0;
	int* array_index;
	int br = 0;
	int index = 1;
	for (int i = 0; i < my_str.length(); i++)
	{
		if (my_str[i] == '+' || my_str[i] == '-' || my_str[i] == '*' || my_str[i] == '/')
		{
			br++;
		}
	}
	array_index = new int[br + 2];
	array_index[0] = 0;
	for (int i = 0; i < my_str.length(); i++)
	{
		if (my_str[i] == '+' || my_str[i] == '-' || my_str[i] == '*' || my_str[i] == '/')
		{
			array_index[index] = i;
			index++;
		}
	}
	array_index[br + 1] = my_str.length();

	double* degree = new double[br + 3];
	std::string convert;
	int degree_counter = 0;
	for (int i = 1; i < br + 2; i++)
	{
		if (i != 1)
		{
			array_index[i - 1] = array_index[i - 1] + 1;
		}
		for (int j = array_index[i - 1]; j < array_index[i]; j++)
		{
			convert += my_str[j];
		}
		degree[degree_counter] = convert_string(convert);
		degree_counter++;
		convert.clear();
	}



	double res = degree[0];
	if (my_str[array_index[1] - 1] == '*')
	{
		res = degree[0] * degree[1];
	}
	if (my_str[array_index[1] - 1] == '/')
	{
		res = degree[0] / degree[1];
	}
	double pr = 0;
	for (int i = 1; i < degree_counter; i++)
	{
		if (my_str[array_index[i] - 1] == '+' && my_str[array_index[i + 1] - 1] != '*' && my_str[array_index[i + 1] - 1] != '/')
		{
			res = res + degree[i];
		}
		if (my_str[array_index[i] - 1] == '-' && my_str[array_index[i + 1] - 1] != '*' && my_str[array_index[i + 1] - 1] != '/')
		{
			res = res - degree[i];
		}

		if (my_str[array_index[i + 1] - 1] == '*')
		{
			pr = degree[i] * degree[i + 1];
			if (my_str[array_index[i] - 1] == '+')
			{
				res = res + pr;
			}
			if (my_str[array_index[i] - 1] == '-')
			{
				res = res - pr;
			}
			if (my_str[array_index[i] - 1] == '*' || my_str[array_index[i] - 1] == '/')
			{
				res = res * pr / degree[i];
			}
		}
		if (my_str[array_index[i + 1] - 1] == '/' && degree[i + 1] != 0)
		{
			pr = degree[i] / degree[i + 1];
			if (my_str[array_index[i] - 1] == '+')
			{
				res = res + pr;
			}
			if (my_str[array_index[i] - 1] == '-')
			{
				res = res - pr;
			}
			if (my_str[array_index[i] - 1] == '*' || my_str[array_index[i] - 1] == '/')
			{
				res = res / pr / degree[i];
			}
		}
	}

	return res;

}

std::string table:: copy()
{
	std::string res;
	for (int i = 0; i < this->str.length(); i++)
	{
		res += this->str[i];
	}
	return res;
}
void table::save_file(std::fstream new_file,char* filename)
{
	new_file.open(filename,std::ios::out);
	for (int i = 0; i < this->str.length(); i++)
	{
		new_file << this->str[i];
	}
	new_file.close();
}