#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using month = std::vector<std::vector<std::string>>;

void AddCase( month& current_month, std::string s, int num_day )
{
	num_day -= 1;
	current_month[num_day].push_back(s);
}

void DumpCases( month& current_month, int num_day )
{
	num_day -= 1;
	std::vector<std::string> daily_cases = current_month[num_day];
	if (daily_cases.empty() == true)
	{
		std::cout << 0 << std::endl;
	}
	else
	{
		std::cout << daily_cases.size() << " ";
		for (int i = 0; i < daily_cases.size(); i++)
		{
			std::cout << daily_cases[i] << " ";
		}
		std::cout << std::endl;
	}
}

void NextMonth( month& current_month, const std::vector<int>& days_of_months, int& current_month_num )
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
		std::vector<std::string> last_day_next = next_month[next_month.size() - 1];

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

void RunExample()
{
	// amount of days in months
	const std::vector<int> days_of_months{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	int current_month_number = 0; // number of current month in "days_of_months"
	month current_month(days_of_months[current_month_number]); // create current month

	int limit = 0, // amount of avaliable operation
		index_day = 0; // variable for index of day

	std::string command, task;
	std::cin >> limit;

	while (limit > 0)
	{
		std::cin >> command;
		if (command == "NEXT")
		{
			NextMonth(current_month, days_of_months, current_month_number);
		}
		else if (command == "DUMP")
		{
			std::cin >> index_day;
			DumpCases(current_month, index_day);
		}
		else if (command == "ADD")
		{
			std::cin >> index_day >> task;
			AddCase(current_month, task, index_day);
		}
		limit--;
	}
}