#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

void ChangeCapital(  map<string, string>& guide, string country, string new_capital )
{
	// if "country" doesn't exist before this moment
	if (guide.count(country) == 0)
	{
		guide[country] = new_capital;
		cout << "Introduce new country " << country << " with capital " << new_capital << endl;
	}

	// if country already has capital with name "new_capital"
	else if (guide.count(country) == 1 && guide[country] == new_capital)
	{
		cout << "Country " << country << " hasn't changed its capital" << endl;
	}
	else
	{
		cout << "Country " << country << " has changed its capital from " << guide[country] << " to " << new_capital << endl;
		guide[country] = new_capital;
	}
}

void Rename( map<string, string>& guide, string old_country, string new_country )
{
	if (old_country == new_country || guide.count(old_country) == 0 || guide.count(new_country) == 1)
		cout << "Incorrect rename, skip" << endl;

	else if (guide.count(old_country) == 1)
	{
		string capital = guide[old_country];
		guide[new_country] = guide[old_country];
		guide.erase(old_country);
		cout << "Country " << old_country << " with capital " << capital << " has been renamed to " << new_country << endl;
	}
}

void About( map<string, string>& guide, string country )
{
	if (guide.count(country) == 0)
		cout << "Country " << country << " doesn't exist" << endl;
	else
		cout << "Country " << country << " has capital " << guide[country] << endl;
}

void Dump( map<string, string>& guide )
{
	if (guide.empty() == true)
	{
		cout << "There are no countries in the world" << endl;
	}
	else
	{
		for (const auto& item : guide)
			cout << item.first << "/" << item.second << " ";
	}
}

void RunExample()
{
	int limit = 0;
	string command, sub_command_1, sub_command_2;
	cin >> limit;
	map<string, string> guide = {};

	while (limit > 0)
	{
		cin >> command;
		if (command == "DUMP")
			Dump(guide);
		else if (command == "ABOUT")
		{
			cin >> sub_command_1;
			About(guide, sub_command_1);
		}
		else if (command == "RENAME")
		{
			cin >> sub_command_1 >> sub_command_2;
			Rename(guide, sub_command_1, sub_command_2);
		}
		else if (command == "CHANGE_CAPITAL")
		{
			cin >> sub_command_1 >> sub_command_2;
			ChangeCapital(guide, sub_command_1, sub_command_2);
		}
		limit--;
	}
}