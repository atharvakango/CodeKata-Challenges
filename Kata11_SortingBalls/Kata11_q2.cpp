#include<iostream>
using namespace std;


int main()
{
	string message="When not studying nuclear physics, Bambi likes to play beach volleyball.";
	int cnt[26];
	for(int i=0;i<26;i++)
		cnt[i] = 0;

	for(char c:message) { 		
		if(c >= 'A'&& c <= 'Z')
			c -= 32;
		
		if( c >='a'&& c <='z')
			cnt[c-'a']++;
	}
	
	for (int i=0;i<26;i++) {
		if(cnt[i]!=0){
			for(int j=0;j<cnt[i];j++)
				cout<<char(i+'a');
		}
    }
    
    return 0;
}

