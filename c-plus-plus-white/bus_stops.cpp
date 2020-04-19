#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;
typedef map<string, vector<string>> routes_list;

void PrintAllBuses(const routes_list& buses_to_stops)
{
	if (buses_to_stops.empty() == true)
		cout << "No buses" << endl;
	else
	{
		for (const auto& bus_item : buses_to_stops)
		{
			cout << "Bus " << bus_item.first << ": ";
			for (const string& stop : bus_item.second)
				cout << stop << " ";
			cout << endl;
		}
	}
}

void PrintStopsForBus(routes_list& buses_to_stops, routes_list& stops_to_buses, const string& bus)
{
	if (buses_to_stops.count(bus) == 0) {
		cout << "No bus" << endl;
	}
	else {
		for (const string& stop : buses_to_stops[bus]) {
			cout << "Stop " << stop << ": ";

			// если через остановку проходит ровно один автобус,
			// то это наш автобус bus, следовательно, пересадки тут нет
			if (stops_to_buses[stop].size() == 1) {
				cout << "no interchange";
			}
			else {
				for (const string& other_bus : stops_to_buses[stop]) {
					if (bus != other_bus) {
						cout << other_bus << " ";
					}
				}
			}
			cout << endl;
		}
	}
}

void PrintBusesForStop(const routes_list& stops_to_buses, const string& stop)
{
	if (stops_to_buses.count(stop) == 0) {
		cout << "No stop" << endl;
	}
	else {
		for (const string& bus : stops_to_buses.at(stop)) {
			cout << bus << " ";
		}
		cout << endl;
	}
}

int main()
{
	int limit, stop_count;
	routes_list buses_to_stops = {}, // bus - vector<stop> 
				stops_to_buses = {}; // stop - vector<bus>

	cin >> limit;
	while (limit > 0)
	{
		string command;
		cin >> command;
		if (command == "NEW_BUS")
		{
			string bus;
			cin >> bus;
			int stop_count;
			cin >> stop_count;

			// amount of stops for "bus"
			vector<string> stops_temp = buses_to_stops[bus];
			stops_temp.resize(stop_count);

			// add each stop to stops_to_buses
			for (auto& stop : stops_temp)
			{
				cin >> stop;
				stops_to_buses[stop].push_back(bus); // update dict stop : vector<bus>
			}

		}
		else if (command == "BUSES_FOR_STOP")
		{
			string stop;
			cin >> stop;
			PrintBusesForStop(stops_to_buses, stop);
		}
		else if (command == "STOPS_FOR_BUS")
		{
			string bus;
			cin >> bus;
			PrintStopsForBus(buses_to_stops, stops_to_buses, bus);
		}
		else if (command == "ALL_BUSES")
		{
			PrintAllBuses(buses_to_stops);
		}
		limit--;
	}

	return 0;
}