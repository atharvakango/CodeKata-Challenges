#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;

//Finding insertion point using tail recursive binary search
int findInsertionPoint(vector<int> numbers, int target, int start, int end)
{
    if (end <= start)
        return (target > numbers[start])?  (start + 1): start;
 
    int mid = start + (end-start)/2;
 
    if(target == numbers[mid])
        return mid+1;
 
    if(target > numbers[mid])
        return findInsertionPoint(numbers, target, mid+1, end);
        
    return findInsertionPoint(numbers, target, start, mid-1);
}
 
void insertArray(vector<int>& numbers, int size)
{
    int selected;
 
    int index=size-1;
    selected = numbers[index];
    int temp=index-1;
    int loc = findInsertionPoint(numbers, selected, 0, temp);
    while (temp >= loc)
    {
        numbers[temp+1] = numbers[temp];
        temp--;
    }
    numbers[temp+1] = selected;     
}

bool checkEqualVectors(vector<int> a, vector<int>& b)
{
	if(a.size()!=b.size())
		return false;

	for(int i=0; i<a.size(); i++)
		if(a[i]!=b[i])
			return false;

	return true;
}


int main()
{
	vector<int> numbers;
	
	assert(checkEqualVectors({}, numbers));
	
	//Add Code
	numbers.push_back(20);
	insertArray(numbers,numbers.size());
	
	//Assert	
	assert(checkEqualVectors({20}, numbers));
	
	//Add Code
	numbers.push_back(10);
	insertArray(numbers,numbers.size());		
	
	//Assert
	assert(checkEqualVectors({10, 20}, numbers));
	
	//Add Code
	numbers.push_back(30);
	insertArray(numbers,numbers.size());	
	
	//Assert
	assert(checkEqualVectors({10, 20, 30}, numbers));
	 
    return 0;
} 
