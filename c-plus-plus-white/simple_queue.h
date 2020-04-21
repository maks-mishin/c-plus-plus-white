#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

using queue = std::vector<bool>;

void worry(queue& peoples, int index)
{
	for (int i = 0; i < peoples.size(); i++)
	{
		if (i == index)
			peoples[i] = false;
	}
}

void quiet(queue& peoples, int index)
{
	for (int i = 0; i < peoples.size(); i++)
	{
		if (i == index)
			peoples[i] = true;
	}
}

void come(queue& peoples, int k)
{
	for (int i = 0; i < k; i++)
	{
		peoples.push_back(true);
	}
}

void remove(queue& peoples, int k)
{
	for (int i = 0; i < k; i++)
	{
		peoples.pop_back();
	}
}

void worry_count(const queue& peoples)
{
	int count = 0;
	for (int i = 0; i < peoples.size(); i++)
	{
		if (peoples[i] == false)
			count++;
	}
	std::cout << count << std::endl;
}

void queue_example()
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
			worry_count(peoples);
			limit--;
			continue;
		}
		else
			std::cin >> num;

		if (command == "WORRY" && num >= 0)
			worry(peoples, num);
		else if (command == "QUIET" && num >= 0)
			quiet(peoples, num);
		else if (command == "COME" && num > 0)
			come(peoples, num);
		else if (command == "COME" && num < 0)
			remove(peoples, abs(num));

		limit--;
	}
}

void queue_example_2()
{
	int q;
	cin >> q;
	vector<bool> is_nervous;

	for (int i = 0; i < q; ++i) {
		string operation_code;
		cin >> operation_code;

		if (operation_code == "WORRY_COUNT") {
			cout << count(begin(is_nervous), end(is_nervous), true) << endl;
		}
		else {
			if (operation_code == "WORRY" || operation_code == "QUIET") {
				int person_index;
				cin >> person_index;

				is_nervous[person_index] = (operation_code == "WORRY");
			}
			else if (operation_code == "COME") {
				int person_count;
				cin >> person_count;

				is_nervous.resize(is_nervous.size() + person_count, false);
			}
		}
	}
}