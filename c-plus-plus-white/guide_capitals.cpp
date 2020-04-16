#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

void change_capital(map<string, string>& guide, string country, string new_capital)
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

void rename(map<string, string>& guide, string old_country, string new_country)
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

void about(map<string, string>& guide, string country)
{
	if (guide.count(country) == 0)
		cout << "Country " << country << " doesn't exist" << endl;
	else
		cout << "Country " << country << " has capital " << guide[country] << endl;
}

void dump(map<string, string>& guide)
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

void main_function()
{
	int limit = 0;
	string command, sub_command_1, sub_command_2;
	cin >> limit;
	map<string, string> guide = {};

	while (limit > 0)
	{
		cin >> command;
		if (command == "DUMP")
			dump(guide);
		else if (command == "ABOUT")
		{
			cin >> sub_command_1;
			about(guide, sub_command_1);
		}
		else if (command == "RENAME")
		{
			cin >> sub_command_1 >> sub_command_2;
			rename(guide, sub_command_1, sub_command_2);
		}
		else if (command == "CHANGE_CAPITAL")
		{
			cin >> sub_command_1 >> sub_command_2;
			change_capital(guide, sub_command_1, sub_command_2);
		}
		limit--;
	}
}