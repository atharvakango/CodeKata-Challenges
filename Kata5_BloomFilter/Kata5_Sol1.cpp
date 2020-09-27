#include<iostream>
#include<unordered_map>
#include<bitset>
#include<fstream>

#define MAX 1000000
using namespace std;

int getIndex(string hash)
{
	hash = hash.substr(0, 9);
	return stoi(hash) % MAX;
}

void takeInput(bitset<MAX> &bt)
{
	string word;
	ifstream input_file ("wordlist.txt");
	if (input_file.is_open())
	{
		while(getline(input_file, word))
		{			
			hash<string> hasher;
			size_t hash = hasher(word);			
			int index = getIndex(to_string(hash));			
			bt.set(index, 1);			
		}
		input_file.close();
	}
	else 
		cout << "Error while opening the file!";
	
}

bool checkIfExists(string target, bitset<MAX>& bt) {
	hash<string> hasher;
	size_t hash = hasher(target);
	return bt[getIndex(to_string(hash))];
}



int main()
{
	bitset<MAX> bt;
	
	takeInput(bt);
	
	cout<<checkIfExists("Abbeville", bt)<<endl;
	cout<<checkIfExists("Abbevfdsfd", bt)<<endl;

}
