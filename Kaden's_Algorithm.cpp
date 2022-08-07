#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main()
{
	
	vector<int> arr={1,2,3,4,5,-6,7,8,-9,-10};
	int current_sum=0,max_sum=INT_MIN;
	for(int i=0;i<arr.size();i++)
	{
		current_sum=max(current_sum+arr[i],arr[i]);
		max_sum=max(current_sum,max_sum);
	}
	cout<<"Maximum Sum of subA="<<max_sum<<endl;
	return 0;
}
