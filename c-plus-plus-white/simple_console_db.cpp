#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

class Date {
public:
	Date(int new_year, int new_month, int new_day) {
		year = new_year;
		if (new_month > 12 || new_month < 1) {
			throw logic_error("Month value is invalid: " + to_string(new_month));
		}
		month = new_month;
		if (new_day > 31 || new_day < 1) {
			throw logic_error("Day value is invalid: " + to_string(new_day));
		}
		day = new_day;
	}

	int GetYear() const {
		return year;
	}
	int GetMonth() const {
		return month;
	}
	int GetDay() const {
		return day;
	}

private:
	int year;
	int month;
	int day;
};

bool operator<(const Date& lhs, const Date& rhs)
{
	return vector<int> {lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} <
		vector<int> {rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

ostream& operator<<(ostream& stream, const Date& date) {
	stream << setw(4) << setfill('0') << date.GetYear() <<
		"-" << setw(2) << setfill('0') << date.GetMonth() <<
		"-" << setw(2) << setfill('0') << date.GetDay();
	return stream;
}

class Database {
public:
	/*
	Add one event to particular date
	*/
	void AddEvent(const Date& date, const string& event) {
		db_container[date].insert(event);
	}

	/*
	Delete particular event from date
	*/
	bool DeleteEvent(const Date& date, const string& event) {
		if (db_container.count(date) > 0 && db_container[date].count(event) > 0) {
			db_container[date].erase(event);
			return true;
		}
		return false;
	}

	/*
	Delete all events from date
	*/
	int DeleteDate(const Date& date) {
		if (db_container.count(date) == 0) {
			return 0;
		}
		else {
			const int event_count = db_container[date].size();
			db_container.erase(date);
			return event_count;
		}
	}

	/*
	Find all events to particular date
	*/
	set<string> Find(const Date& date) const {
		if (db_container.count(date) > 0) {
			return db_container.at(date);
		}
		else {
			return{};
		}
	}

	/*
	Print all date base
	*/
	void Print() const {
		for (const auto& item : db_container) {
			for (const string& event : item.second) {
				cout << item.first << " " << event << endl;
			}
		}
	}

private:
	map<Date, set<string>> db_container;
};

/*
Function for checking date format
*/
Date ParseDate(const string& date) {
	istringstream date_stream(date);
	bool flag = true;

	int year;
	flag = flag && (date_stream >> year);
	flag = flag && (date_stream.peek() == '-');
	date_stream.ignore(1);

	int month;
	flag = flag && (date_stream >> month);
	flag = flag && (date_stream.peek() == '-');
	date_stream.ignore(1);

	int day;
	flag = flag && (date_stream >> day);
	flag = flag && date_stream.eof();

	if (!flag) {
		throw logic_error("Wrong date format: " + date);
	}
	return Date(year, month, day);
}

int main() {
	try {
		Database db;
		string command_line;

		while (getline(cin, command_line)) {
			stringstream ss(command_line);

			string command;
			ss >> command;

			if (command == "Add") {

				string date_str, event;
				ss >> date_str >> event;
				const Date date = ParseDate(date_str);
				db.AddEvent(date, event);

			}
			else if (command == "Del") {
				string date_str;
				ss >> date_str;
				string event;
				if (!ss.eof()) {
					ss >> event;
				}
				const Date date = ParseDate(date_str);
				if (event.empty()) {
					const int count = db.DeleteDate(date);
					cout << "Deleted " << count << " events" << endl;
				}
				else {
					if (db.DeleteEvent(date, event)) {
						cout << "Deleted successfully" << endl;
					}
					else {
						cout << "Event not found" << endl;
					}
				}

			}
			else if (command == "Find") {
				string date_str;
				ss >> date_str;
				const Date date = ParseDate(date_str);
				for (const string& event : db.Find(date)) {
					cout << event << endl;
				}

			}
			else if (command == "Print") {

				db.Print();

			}
			else if (!command.empty()) {

				throw logic_error("Unknown command: " + command);

			}
		}
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}
	return 0;
}