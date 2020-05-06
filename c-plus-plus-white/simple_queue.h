#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using queue = std::vector<bool>;

void Worry(queue& peoples, int index)
{
	for (int i = 0; i < peoples.size(); i++)
	{
		if (i == index)
			peoples[i] = false;
	}
}

void Quiet(queue& peoples, int index)
{
	for (int i = 0; i < peoples.size(); i++)
	{
		if (i == index)
			peoples[i] = true;
	}
}

void Come(queue& peoples, int k)
{
	for (int i = 0; i < k; i++)
	{
		peoples.push_back(true);
	}
}

void Remove(queue& peoples, int k)
{
	for (int i = 0; i < k; i++)
	{
		peoples.pop_back();
	}
}

void WorryCount(const queue& peoples)
{
	int count = 0;
	for (int i = 0; i < peoples.size(); i++)
	{
		if (peoples[i] == false)
			count++;
	}
	std::cout << count << std::endl;
}

void RunQueue()
{
	queue peoples;
	std::string command;
	int num, limit;

	std::cin >> limit;
	while (limit > 0)
	{
		std::cin >> command;
		if (command == "WORRY_COUNT")
		{
			WorryCount(peoples);
			limit--;
			continue;
		}
		else
			std::cin >> num;

		if (command == "WORRY" && num >= 0)
			Worry(peoples, num);
		else if (command == "QUIET" && num >= 0)
			Quiet(peoples, num);
		else if (command == "COME" && num > 0)
			Come(peoples, num);
		else if (command == "COME" && num < 0)
			Remove(peoples, abs(num));

		limit--;
	}
}