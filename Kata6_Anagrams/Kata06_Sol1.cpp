#include<iostream>
#include<fstream>
#include<algorithm>
#include<map>
#include<set>
using namespace std;

int main()
{
    map<string, set<string> > mp ;    
	string word;
	ifstream myfile ("wordlist.txt");
	if (myfile.is_open())
	{
		while(getline(myfile,word))
		{
			string temp_string = word;
			sort(temp_string.begin(), temp_string.end());
			mp[temp_string].insert(word);    
		}
		myfile.close();
	}
	else 
		cout << "Unable to open file";
	
	int cnt=0;
    for(pair<string, set<string> > i: mp) {
        if(i.second.size()>1) {
        	for(string j : i.second) {
	            cout<<j<<" ";
	        }
	        cout<<endl;
	        cnt++;	
        }
        
    }
    
	cout<<"Count Of Anagrams Present in the file: "<<cnt<<endl;
    return 0;
}
