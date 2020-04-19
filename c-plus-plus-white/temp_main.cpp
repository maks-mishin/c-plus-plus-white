#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;
typedef map<string, vector<string>> routes_list;

void all_buses(const routes_list& routes)
{
	if (routes.empty() == true)
		cout << "No buses" << endl;
	else
	{
		for (const auto& route : routes)
		{
			cout << "Bus " << route.first << ": ";
			for (auto stop : route.second)
				cout << stop << " ";
			cout << endl;
		}
	}
}

void stop_for_bus(const routes_list& routes, string bus)
{

}

void buses_for_stop(const routes_list& routes, string bus)
{

}

void new_bus(const routes_list& routes, string new_bus, int stop_count)
{

}

int main()
{
	int limit, stop_count;
	string command, bus, stop_bus;
	routes_list route_list = {};

	cin >> limit;
	while (limit > 0)
	{
		cin >> command;
		if (command == "ALL_BUSES")
		{
			all_buses(route_list);
		}
		else if (command == "NEW_BUS")
		{
			cin >> bus >> stop_count;
			for (int i = 0; i < stop_count; i++)
			{
				cin >> stop_bus;
				route_list[bus].push_back(stop_bus);
			}
		}
		else if (command == "BUSES_FOR_STOP")
		{
			cin >> stop_bus;
			int count = 0;
			vector<string> temp;

			for (auto route : route_list)
			{
				for (auto stop : route.second)
				{
					if (stop == stop_bus)
					{
						temp.push_back(route.first);
						count++;
					}
				}
			}
			if (count == 0)
			{
				cout << "No stop" << endl;
			}
			else
			{
				for (auto route : route_list)
				{
					for (auto item : temp)
					{
						if (item == route.first)
							cout << item << " ";
					}
				}
				cout << endl;
			}
		}
		else if (command == "STOPS_FOR_BUS")
		{
			cin >> bus;

			if (route_list.count(bus) == 0)
				cout << "No bus" << endl;

			int count = 0;
			for (auto route : route_list)
			{
				if (route.first == bus)
				{
					for (auto stop : route.second)
					{
						cout << "Stop " << stop << ":";
						int count_other = 0;
						vector<string> temp;
						for (auto _route : route_list)
						{
							for (auto _stop : _route.second)
							{
								if (_stop == stop && _route.first != bus)
								{
									temp.push_back(_route.first);
									count_other++;
								}
							}
						}

						if (count_other == 0)
							cout << " no interchange";
						else if (count_other > 0)
						{
							for (auto item : route_list)
							{
								for (auto _item : temp)
								{
									if (_item == item.first)
										cout << " " << item.first;
								}
							}
						}
						cout << endl;
					}
				}
			}

		}
		limit--;
	}

	return 0;
}