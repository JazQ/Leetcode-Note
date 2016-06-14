#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int> > threeSum(vector<int> &nums) {
    vector<vector<int> > result;
	if(nums.size()<3)
		return result;
	sort(nums.begin(),nums.end());
	vector<int> v;
    for (int i = 0; i < nums.size(); i++) {
	  if(i>0)
	  	while(nums[i]==nums[i-1])
	  		i++;
	  int j=i+1,k=nums.size()-1;
	  while(j<k)
	  {
		  if(nums[i]+nums[j]+nums[k]<0)
		  {
			  j++;
			  while(nums[j]==nums[j-1])
			  	j++;
		  }
		  else if(nums[i]+nums[j]+nums[k]>0)
		  {
			  k--;
			  while(nums[k]==nums[k+1])
			  	k--;
		  }
		  else
		  {
			  v.push_back(nums[i]);
			  v.push_back(nums[j]);
			  v.push_back(nums[k]);
			  result.push_back(v);
			  v.clear();
			  j++;
			  k--;
			  while(nums[j]==nums[j-1]&&nums[k]==nums[k+1]&&j<k)
			  	j++;
		  }
	  }
    }
    return result;
  }
};

int main() {
  vector<int> nums;
  int a[] = {-1, 0,1,2,-1,-4};
  for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    nums.push_back(a[i]);
  Solution S;
  vector<vector<int> > result;
  result = S.threeSum(nums);
  for (int i = 0; i < result.size(); i++) {
    for (int j = 0; j < result[i].size(); j++)
      cout << result[i][j] << " ";
    cout << endl;
  }
  cout<<"=============================";
}
