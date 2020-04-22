#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using full_name = std::pair<std::string, std::string>;

class Person {
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
private:
	//full_name full_name = {};
	std::map<int, full_name> m_changes = {};
};