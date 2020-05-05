#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>

using namespace std;

/*struct Day
{
int value;
Day(int _value)
{
value = _value;
}
};
struct Month
{
int value;
Month(int _value)
{
value = _value;
}
};
struct Year
{
int value;
Year(int _value)
{
value = _value;
}
};*/

struct Student
{
	string first_name;
	string last_name;
	int day;
	int month;
	int year;

	Student(string name, string l_name, int _day, int _month, int _year)
	{
		first_name = name;
		last_name = l_name;
		day = _day;
		month = _month;
		year = _year;
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
		students.push_back({ name, last_name, day, month, year });
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
			cout << students[key - 1].day << "." <<
				students[key - 1].month << "." << students[key - 1].year << endl;
		}
		else
		{
			cout << "bad request" << endl;
		}

	}
}

