#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>

using namespace std;

struct Day
{
	int value;
	explicit Day(int _value)
	{
		value = _value;
	}
};
struct Month
{
	int value;
	explicit Month(int _value)
	{
		value = _value;
	}
};
struct Year
{
	int value;
	explicit Year(int _value)
	{
		value = _value;
	}
};

struct Date
{
	int day;
	int month;
	int year;

	Date() {};
	Date(Day new_day, Month new_month, Year new_year)
	{
		day = new_day.value;
		month = new_month.value;
		year = new_year.value;
	}
};

struct Student
{
	string first_name;
	string last_name;
	Date date_of_birth;

	Student(string f_name, string l_name, Date new_date)
	{
		first_name = f_name;
		last_name = l_name;

		date_of_birth.day = new_date.day;
		date_of_birth.month = new_date.month;
		date_of_birth.year = new_date.year;
	};
};

void run_example()
{
	int lim_in, lim_questions;
	vector<Student> students;

	cin >> lim_in;
	for (size_t i = 0; i < lim_in; i++)
	{
		string name, last_name;
		int day, month, year;

		cin >> name >> last_name >> day >> month >> year;
		Date new_date( Day{ day }, Month{ month }, Year{ year } );

		students.push_back({ name, last_name, new_date });
	}

	cin >> lim_questions;
	for (int i = 0; i < lim_questions; i++)
	{
		string command;
		int key;

		cin >> command >> key;

		if (students.size() < key || key <= 0)
			cout << "bad request" << endl;
		else if (command == "name")
		{
			cout << students[key - 1].first_name << " " <<
				students[key - 1].last_name << endl;
		}
		else if (command == "date")
		{
			cout << students[key - 1].date_of_birth.day << "." <<
				students[key - 1].date_of_birth.month << "." << students[key - 1].date_of_birth.year << endl;
		}
		else
		{
			cout << "bad request" << endl;
		}

	}
}

