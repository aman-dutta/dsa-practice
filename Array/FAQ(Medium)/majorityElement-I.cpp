#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;


// Approach 1: Using Simple Hash map to calculate the number of occurance
// Time Complexity:  O(N)
// Space Complexity: O(N)
int findMajorityElement_Brute(const vector<int>& nums){
    unordered_map<int,int> mp;
    int n = nums.size();

    for(int i=0; i<nums.size(); i++){
        mp[nums[i]]++;
        if(mp[nums[i]] >= n/2){
            return nums[i];
        }
    }

    return -1;
}

// Approach 2: Using Boyer-Moore Algo
// Time Complexity:  O(N)
// Space Complexity: O(1)
int findMajorityElement_boyerMooreAlgo(const vector<int>& nums){ 
    int majorElement = nums[0];
    int count = 1;

    for(int i=1; i<nums.size(); i++){
        if(count == 0){
            majorElement = nums[i];
            count = 1;
        }else{
            if(nums[i] == majorElement){
                count++;
            }else{
                count--;
            }
        }
    }

    return majorElement;
}

int main(){
    vector<int> nums = {7,0,0,1,7,7,2,7,7};

    cout<<"Using Brute Force Approch: "<<findMajorityElement_Brute(nums)<<endl;
    cout<<"Using Boyer-Moore Algo approach: "<<findMajorityElement_boyerMooreAlgo(nums)<<endl;
    return 0;
}
