#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

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

class Person {
public:
	void ChangeFirstName(int year, const string& first_name)
	{
		if (m_changes.count(year) == 0)
			m_changes[year].second = "";
		m_changes[year].first = first_name;
		
	}
	void ChangeLastName(int year, const string& last_name)
	{
		if (m_changes.count(year) == 0)
			m_changes[year].first = "";
		m_changes[year].second = last_name;
	}

	string GetFullName(int year)
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

		string first_name = "";
		string last_name = "";
		for (const auto& change : m_changes) 
		{
			pair<string, string> full_name = change.second;

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
private:
	pair<string, string> full_name = {};
	map<int, pair<string, string>> m_changes = {};
};

int main()
{
	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	
	for (int year : {1900, 1965, 1990}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeLastName(1968, "Volkova");
	
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}
	cout << endl;

	return 0;
}