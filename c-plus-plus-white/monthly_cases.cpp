/*
	Programm "Monthly cases"
	Available option:
	1. ADD i s (Assign a case with the name s to day i of the current month.)
	2. DUMP i (Display all cases scheduled for day i of the current month.)
	3. NEXT (Go to the to-do list for the new month.)
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef vector<vector<string>> month;

void add_case(month& current_month, string s, int num_day)
{
	num_day -= 1;
	current_month[num_day].push_back(s);
}

void dump_cases(month& current_month, int num_day)
{
	num_day -= 1;
	vector<string> cases_day = current_month[num_day];
	if (cases_day.empty() == true)
	{
		cout << 0 << endl;
	}
	else
	{
		cout << cases_day.size() << " ";
		for (int i = 0; i < cases_day.size(); i++)
		{
			cout << cases_day[i] << " ";
		}
		cout << endl;
	}
}

void next_month(month& current_month, const vector<int>& days_of_months, int& current_month_num)
{
	int days_current, //amout of days current month
		days_next; //amout of days next month
	
	days_current = days_of_months[current_month_num];

	//processing end of year
	if (current_month_num == 11)
	{
		current_month_num = -1;
		days_next = days_of_months[0];
	}
	else
	{
		days_next = days_of_months[current_month_num + 1];
	}


	// create new month
	month next_month = {};
	
	// task size of next month using amount days
	next_month.resize(days_next);

	if (days_next < days_current)
	{
		for (int i = 0; i < next_month.size(); i++)
		{
			//moving tasks from current month to next
			next_month[i].insert(end(next_month[i]), begin(current_month[i]), end(current_month[i]));
		}

		//last day of current month
		vector<string> last_day_next = next_month[next_month.size() - 1]; 
		
		//processing last days of current month
		for (int i = next_month.size(); i < current_month.size(); i++)
		{
			last_day_next.insert(end(last_day_next), begin(current_month[i]), end(current_month[i]));
		}
		next_month[next_month.size() - 1] = last_day_next;
	}
	else
	{
		for (int i = 0; i < current_month.size(); i++)
		{
			//moving tasks from current month to next
			next_month[i].insert(end(next_month[i]), begin(current_month[i]), end(current_month[i]));

		}

		//processing last days of current month
		for (int i = current_month.size(); i < next_month.size(); i++)
		{
			next_month[i] = {};
		}
	}
	current_month = next_month;
	current_month_num++; //go to next month in calendar

}

void main_example()
{
	// amount of days in months
	const vector<int> days_of_months{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	int current_month_number = 0; // number of current month in "days_of_months"
	month current_month(days_of_months[current_month_number]); // create current month

	int limit = 0, // amount of avaliable operation
		index_day = 0; // variable for index of day

	string command, task;
	cin >> limit;

	while (limit > 0)
	{
		cin >> command;
		if (command == "NEXT")
		{
			next_month(current_month, days_of_months, current_month_number);
		}
		else if (command == "DUMP")
		{
			cin >> index_day;
			dump_cases(current_month, index_day);
		}
		else if (command == "ADD")
		{
			cin >> index_day >> task;
			add_case(current_month, task, index_day);
		}
		limit--;
	}
}