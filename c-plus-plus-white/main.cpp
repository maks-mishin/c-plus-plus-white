#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>

using namespace std;

class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {
		// добавить факт изменения имени на first_name в год year
	}
	void ChangeLastName(int year, const string& last_name) {
		// добавить факт изменения фамилии на last_name в год year
	}
	string GetFullName(int year) {
		// получить имя и фамилию по состоянию на конец года year
	}
private:
	string first_name;
	string last_name;
};


int main()
{
		
	return 0;
}