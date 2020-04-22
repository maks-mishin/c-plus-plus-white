#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Person {
public:
	void ChangeFirstName(int year, const string& first_name)
	{
		m_years.push_back(year);
		sort(m_years.begin(), m_years.end());
		m_first_name = first_name;
		m_changes[year].first = m_first_name;
		m_changes[year].second = m_last_name;
	}
	void ChangeLastName(int year, const string& last_name)
	{
		m_years.push_back(year);
		sort(m_years.begin(), m_years.end());

		m_last_name = last_name;
		m_changes[year].first = m_first_name;
		m_changes[year].second = m_last_name;
	}
	
	string GetFullName(int year)
	{
		pair<string, string> people;
		string info_people = "";
		
		if (year > m_years.back())
			people = m_changes[m_years.back()];

		else if (find(m_years.begin(), m_years.end(), year) != m_years.end())
			people = m_changes[year];
		
		else if (year > m_years.front() && year < m_years.back() &&
				find(m_years.begin(), m_years.end(), year) == m_years.end())
		{
			for (int i = 0; i < m_years.size(); i++)
			{
				if (m_years[i] > year)
				{
					people = m_changes[m_years[i-1]];
					break;
				}
			}
			//int temp = *lower_bound(m_years.begin(), m_years.end(), year) - 1;
			//people = m_changes[temp];
		}


		if (people.first.empty() && people.second.empty())
		{
			info_people += "Incognito";
		}
		else if (!people.first.empty() && people.second.empty())
		{
			info_people += people.first;
			info_people += " with unknown last name";
		}
		else if (people.first.empty() && !people.second.empty())
		{
			info_people += people.second;
			info_people += " with unknown first name";
		}
		else
		{
			info_people += people.first + " ";
			info_people += people.second;
		}
		return info_people;
	}
private:
	string m_first_name = "";
	string m_last_name = "";

	vector<int> m_years = {};

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
	return 0;
}