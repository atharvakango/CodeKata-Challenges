#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;

//Iterative Binary Search
int chop(int target, vector<int> data) {

	int start = 0, end = data.size();

	while(start<end){
		int mid = start + (end-start)/2;

		if(data[mid] == target)
		    return mid;            
		else if(data[mid]>target)
		    end = mid;
		else
		    start = mid+1;
	}

	return -1;
}


int main()
{
	
	//vector<int> inp{};

	assert(0 == chop(1, {1, 3, 5}));
	assert(-1 == chop(3, {}));
	assert(-1 == chop(3, {1}));
	assert(0 == chop(1, {1}));
	assert(1 ==  chop(3, {1, 3, 5}));
	assert(2 ==  chop(5, {1, 3, 5}));
	assert(-1 == chop(0, {1, 3, 5}));
	assert(-1 == chop(2, {1, 3, 5}));
	assert(-1 == chop(4, {1, 3, 5}));
	assert(-1 == chop(6, {1, 3, 5}));
	assert(0 ==  chop(1, {1, 3, 5, 7}));
	assert(1 ==  chop(3, {1, 3, 5, 7}));
	assert(2 ==  chop(5, {1, 3, 5, 7}));
	assert(3 ==  chop(7, {1, 3, 5, 7}));
	assert(-1 == chop(0, {1, 3, 5, 7}));
	assert(-1 == chop(2, {1, 3, 5, 7}));
	assert(-1 == chop(4, {1, 3, 5, 7}));
	assert(-1 == chop(6, {1, 3, 5, 7}));
	assert(-1 == chop(8, {1, 3, 5, 7}));
	return 0;
}
