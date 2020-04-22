#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <numeric>

using namespace std;

// если имя неизвестно, возвращает пустую строку
string FindNameByYear(const map<int, string>& names, int year) {
	string name;  // изначально имя неизвестно

				  // перебираем всю историю по возрастанию ключа словаря, то есть в хронологическом порядке
	for (const auto& item : names) {
		// если очередной год не больше данного, обновляем имя
		if (item.first <= year) {
			name = item.second;
		}
		else {
			// иначе пора остановиться, так как эта запись и все последующие относятся к будущему
			break;
		}
	}

	return name;
}

using full_name = std::pair<std::string, std::string>;

class Person
{
public:
	void ChangeFirstName(int year, const std::string& first_name)
	{
		if (m_changes.count(year) == 0)
			m_changes[year].second = "";
		m_changes[year].first = first_name;

	}
	void ChangeLastName(int year, const std::string& last_name)
	{
		if (m_changes.count(year) == 0)
			m_changes[year].first = "";
		m_changes[year].second = last_name;
	}

	/*
	Function get full name at the end of the year "year"
	*/
	std::string GetFullName(int year)
	{
		if (m_changes.size() == 0)
			return "Incognito";
		else
		{
			for (const auto& _pair : m_changes) {
				if (year < _pair.first)
					return "Incognito";
				break;
			}
		}

		std::string first_name = "";
		std::string last_name = "";
		for (const auto& change : m_changes)
		{
			full_name full_name = change.second;

			if (change.first <= year && !full_name.second.empty())
				last_name = full_name.second;

			if (change.first <= year && !full_name.first.empty())
				first_name = full_name.first;
		}
		if (first_name.empty())
			return last_name + " with unknown first name";
		else if (last_name.empty())
			return first_name + " with unknown last name";
		else
			return first_name + " " + last_name;
	}


	/*
	Function exclude duplicates from vector of names
	*/
	vector<string> unique_value(const vector<string>& names)
	{
		vector<string> temp;
		for (int i = 0; i < names.size() - 1; i++)
		{
			if (names[i] != names[i + 1])
				temp.push_back(names[i]);
		}
		temp.push_back(names.back());
		return temp;
	}

	/*
	Function make the history of changes of vector "names"
	@param names - first_names / last_names
	*/
	string make_history_changes(const vector<string>& names)
	{
		string name = names[0];
		if (names.size() == 2)
		{
			name += " (" + names[1] + ")";
		}

		if (names.size() > 2)
		{
			name += " (";
			for (size_t i = 1; i < names.size() - 1; i++)
			{
				name += names[i] + ", ";
			}
			name += names.back();
			name += ")";
		}
		return name;
	}

	/*
	Function get full name with all changes in time at the end of the year "year"
	*/
	string GetFullNameWithHistory(int year) {
		if (m_changes.size() == 0)
			return "Incognito";
		else
		{
			for (const auto& _pair : m_changes) {
				if (year < _pair.first)
					return "Incognito";
				break;
			}
		}

		std::string first_name = "";
		std::string last_name = "";

		vector<string> first_names;
		vector<string> last_names;

		for (const auto& change : m_changes)
		{
			full_name full_name = change.second;

			if (change.first <= year && !full_name.second.empty())
			{
				last_names.push_back(full_name.second);
			}

			if (change.first <= year && !full_name.first.empty())
			{
				first_names.push_back(full_name.first);
			}
		}

		reverse(last_names.begin(), last_names.end());
		reverse(first_names.begin(), first_names.end());



		if (first_names.empty())
		{
			last_names = unique_value(last_names);
			last_name += make_history_changes(last_names);

			return last_name + " with unknown first name";
		}
		else if (last_names.empty())
		{
			first_names = unique_value(first_names);
			first_name += make_history_changes(first_names);

			return first_name + " with unknown last name";
		}
		else
		{
			first_names = unique_value(first_names);
			last_names = unique_value(last_names);

			first_name += make_history_changes(first_names);
			last_name += make_history_changes(last_names);

			return first_name + " " + last_name;
		}
	}
private:
	std::map<int, full_name> m_changes = {};
};