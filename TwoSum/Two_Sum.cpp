#include <stdlib.h>
#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	const int max_num = 0xFFFF;
	const int min_num = -0xFFFF;
	/*
	for (auto e : nums) {
		max_num = e > max_num ? e : max_num ;
		min_num = e < min_num ? e : min_num ;
	}
	*/
	bitset<max_num-min_num> hashmap;
	for(auto e : nums) 
		hashmap[e-min_num] = true;

	vector<int> index;
	target = target - 2 *  min_num;
	for(int i=0; i!=nums.size(); i++) {
		if (hashmap[target - (nums[i] - min_num)]) {
			for(int j=i+1; j!=nums.size(); j++) {
				if (nums[j] == target - nums[i] + 2 * min_num) {
					index.push_back( i > j ? j : i);
					index.push_back( i > j ? i : j);
					return index;
				}
			}
		}
	}
}

int main() {
	int x;
	vector<int> nums;
	vector<int> index;
	while(cin >> x) 
		nums.push_back(x);	
	int target = nums.back();
	nums.pop_back();
	index = twoSum(nums, target);
	for(auto e : index)
		cout<<e<<endl;
		
}
