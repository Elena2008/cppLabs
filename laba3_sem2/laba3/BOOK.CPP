#include "Book.h"
#include "HelpUtils.h"

string Book::get_author(){
	return author;
}

string Book::get_title() {
	return title;
}

int Book::get_year_book() {
	return year_book;
}

string Book::get_pub_house() {
	return pub_house;
}

int Book::get_price() {
	return price;
}

int  Book::get_available() {
	return is_available;
}

void Book::set_available(int  av) {
	is_available = av;
}

void Book::set_author(string author_) {
	author = author_;
}

void Book::set_title(string title_) {
	title = title_;
}

void Book::set_year_book(int year_) {
	year_book = year_;
}

void Book::set_pub_house(string pub_house_) {
	pub_house = pub_house_;
}

void Book::set_price(int price_) {
	price = price_;
}
  
bool search_element_year(Book first, Book second){
	return (first.get_year_book() == second.get_year_book());
}

bool search_element_author(Book first, Book second){
	return (first.get_author() == second.get_author());
}

bool search_element_title(Book first, Book second) {
	return (first.get_title() == second.get_title());
}

bool search_element_availability(Book first, Book second) {
	return (first.get_available() == second.get_available());
}

Book search_type(int type_search){
	Book result;
	switch (type_search)
	{

	case 1:
	{
		cout << "������� ��������: " << endl;
		string title;
		cin >> title;
		result.set_title(title);
		return result;
		break;
	}
	case 2:
	{
		cout << "������� ������: " << endl;
		string auth;
		cin >> auth;
		result.set_author(auth);
		return result;
		break;
	}
	case 3:
	{		
		result.set_year_book(input_number(1500, 2018, "������� ��� ������� (1500 - 2018): "));
		return result;
		break;
	}
	case 4:
	{
		result.set_available (0);
		return result;
		break;
	}
	default:
		return result;
	}
}

bool sort_availability(Book first, Book second) {
	return (first.get_available() < second.get_available());
}

bool search_non_available(Book first, Book second) {
	return (first.get_available() > second.get_available());
}

Book::Book(){
	author = "";
	title = "";
	year_book = 0;
	pub_house = "";
	price = 0;
	is_available = 0;
}

Book from_string_record(ifstream& input) {
	Book result;
	string s;
	try
	{		
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "�����: ";
			result.set_author(s.substr(wrd.length(), s.length()));
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "��������: ";
			result.set_title(s.substr(wrd.length(), s.length()));
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "��� �������: ";
			result.set_year_book(atoi(s.substr(wrd.length(), s.length()).c_str()));
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "������������: ";
			result.set_pub_house(s.substr(wrd.length(), s.length()));
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "����: ";
			result.set_price(atoi(s.substr(wrd.length(), s.length()).c_str()));
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "�����������: ";
			result.set_available(atoi(s.substr(wrd.length(), s.length()).c_str()));
		}
		/*if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "������� ������: ";
			Date date;
			s = s.substr(wrd.length(), s.length());
			while (s.length()) {
				result.history_get_book.push_back(date.from_string_date(s.substr(0, 10)));
				s = s.substr(11, s.length());
			}		
		}*/
	}
	catch (...)
	{
		cout << "������ ������ �� �����!" << endl;
	}
	return result;
}

string to_string_record(Book record, int count) {
	string info ="\n �����: " + record.author + "\n �������� : " + record.title + 
		"\n ��� �������: " + to_string(record.year_book) + "\n �����������: " +
		record.pub_house + "\n ����: " + to_string(record.price) + "\n�������: "+ to_string(record.is_available)/* + record.print_history_book()*/;

	return info;
}

void print_record(Book c)
{
	cout << "�����: " << c.get_author() << endl;
	cout << "��������: " << c.get_title() << endl;
	cout << "��� �������: " << to_string(c.get_year_book()) << endl;
	cout << "�����������: " << c.get_pub_house() << endl;
	cout << "����: " << to_string(c.get_price()) << endl;
	if (c.is_available){
		cout << "�������: �� ��������." << endl;
	}
	else{
		cout << "�������: ��������." << endl;
	}
}

Book& Book::operator = (Book c)
{
	author = c.author;
	title = c.title;
	year_book = c.year_book;
	pub_house = c.pub_house;
	price = c.price;
	is_available = c.is_available;
	return *this;
}

Book Book::add_book() {
	Book rec;
	cout << "������� ���������� � �����." << endl;

	cout << "�����: " << endl;
	string author_;
	cin >> author_;
	rec.set_author(author_);
	cout << endl;

	cout << "��������: " << endl;
	string title_;
	cin >> title_;
	rec.set_title(title_);
	cout << endl;

	int year_;
	year_ = input_number(1400, 2018, "������� ��� ������� �����: ");
	rec.set_year_book(year_);

	cout << "������� �������� ������������:" << endl;
	string house_;
	cin >> house_;
	rec.set_pub_house(house_);
	cout << endl;

	int price_;
	price_ = input_number(1, 10000, "������� ���� ����� � ������: ");
	rec.set_price(price_);

	rec.set_available(0);

	return rec;

}

void Book::WriteBookToFile(Book a, ofstream& os)
{
	StringInBinFile(os, a.author);
	StringInBinFile(os, a.title);
	os.write((char*)&a.year_book, sizeof(int));
	StringInBinFile(os, a.pub_house);
	os.write((char*)&a.price, sizeof(int));
	os.write((char*)&a.is_available, sizeof(int));
}

Book Book::ReadBookFromFile(ifstream& in)
{
	Book b;

	b.author = StringFromBinFile(in);
	b.title = StringFromBinFile(in);
	in.read((char*)&b.year_book, sizeof(int));
	b.pub_house = StringFromBinFile(in);
	in.read((char*)&b.price, sizeof(int));
	in.read((char*)&b.is_available, sizeof(int));

	return b;
}

bool Book::operator == (const Book& c) {
	return (author == c.author && title == c.title && year_book == c.year_book && pub_house == c.pub_house && price == c.price);

}

