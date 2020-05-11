#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <numeric>

using namespace std;

/*
Function for searching full history of changes of a name (last_name)
@param names - last_names or first_names
*/
vector<string> FindNamesHistory(const map<int, string>& changes, int year) {
	vector<string> names;
	for (const auto& item : changes)
	{
		if (item.first <= year && (names.empty() || names.back() != item.second))
		{
			names.push_back(item.second);
		}
	}
	return names;
}

/*
Function make the history of changes of vector "names"
@param names - first_names / last_names
*/
string BuildJoinedName(vector<string> names)
{
	reverse(begin(names), end(names));
	string joined_name = names[0];
	for (size_t i = 1; i < names.size(); ++i) {
		if (i == 1) {
			joined_name += " (";
		}
		else {
			joined_name += ", ";
		}
		joined_name += names[i];
	}
	if (names.size() > 1) {
		joined_name += ")";
	}
	return joined_name;
}

class Person
{
public:
	Person(const string& first, const string& last, int _year_birth)
	{
		year_birth = _year_birth;
		first_names[year_birth] = first;
		last_names[year_birth] = last;
	}

	void ChangeFirstName(int year, const string& first_name)
	{
		if (year >= year_birth)
		{
			first_names[year] = first_name;
		}
	}
	void ChangeLastName(int year, const string& last_name)
	{
		if (year >= year_birth)
		{
			last_names[year] = last_name;
		}
	}

	/*
	Function get full name at the end of the year "year"
	*/
	std::string GetFullName(int year) const
	{
		if (year < year_birth)
			return "No person";

		const vector<string> first_names = FindFirstNamesHistory(year);
		const vector<string> last_names = FindLastNamesHistory(year);

		return first_names.back() + " " + last_names.back();
	}

	/*
	Function get full name with all changes in time at the end of the year "year"
	*/
	string GetFullNameWithHistory(int year) const
	{
		if (year < year_birth)
			return "No person";

		const string first_name = BuildJoinedName(FindFirstNamesHistory(year));
		const string last_name = BuildJoinedName(FindLastNamesHistory(year));

		return first_name + " " + last_name;
	}
private:
	vector<string> FindFirstNamesHistory(int year) const
	{
		return FindNamesHistory(first_names, year);
	}

	vector<string> FindLastNamesHistory(int year) const
	{
		return FindNamesHistory(last_names, year);
	}

	int year_birth;
	map<int, string> first_names;
	map<int, string> last_names;
};