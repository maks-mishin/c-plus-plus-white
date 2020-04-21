#pragma once
#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

using dict_item = pair<string, string>;

dict_item make_sorted_pair(const std::string& word1, const string& word2)
{
	return (word1 <= word2) ? make_pair(word1, word2) : make_pair(word2, word1);
}

bool check(const set<dict_item>& synonyms, const string& word1, const string& word2)
{
	return synonyms.count(make_sorted_pair(word1, word2)) != 0;
}

void add_item_to_dict(set<dict_item>& synonyms, map<string, unsigned>& synonyms_count, const string& word1, const string& word2)
{
	if (check(synonyms, word1, word2))
		return;

	// add plus synomym to each word
	++synonyms_count[word1];
	++synonyms_count[word2];

	synonyms.insert(make_sorted_pair(word1, word2)); // insert pair
}

void example_dict()
{
	set<dict_item> synonyms;
	/*
		Other conatainer for keep of variables:
			map<string word, set<string> syn_word> synonyms;
		where key = user word,
			  value = set of synonyms of this word.
	*/

	map<string, unsigned> synonyms_count;

	string command;

	int limit;
	cin >> limit;

	while (limit > 0)
	{
		cin >> command;
		if (command == "ADD")
		{
			string word1, word2;
			cin >> word1 >> word2;
			add_item_to_dict(synonyms, synonyms_count, word1, word2);
		}
		else if (command == "COUNT")
		{
			string word;
			cin >> word;
			cout << synonyms_count[word] << endl;
		}
		else if (command == "CHECK")
		{
			string word1, word2;
			cin >> word1 >> word2;

			if (check(synonyms, word1, word2))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
		limit--;
	}
}