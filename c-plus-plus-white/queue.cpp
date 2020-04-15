#include <iostream>
#include <vector>
#include <string>

typedef std::vector<std::pair<int, bool>> queue;

void worry(queue& peoples, int index)
{
	for (int i = 0; i < peoples.size(); i++)
	{
		if(i == index)
			peoples[i].second = false;
	}
}

void quiet(queue& peoples, int index)
{
	for (int i = 0; i < peoples.size(); i++)
	{
		if (i == index)
			peoples[i].second = true;
	}
}

void come(queue& peoples, int k)
{
	for (int i = 0; i < k; i++)
	{
		peoples.push_back(std::make_pair(i, true));
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
		if (peoples[i].second == false)
			count++;
	}
	std::cout << count << std::endl;
}

void run_queue()
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