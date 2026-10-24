#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

/*
    3-ways to solve this:
        1) Simple math (calculate the total sum of the number and the indexes. The difference would be the missing number)
        2) XOR all the indexes and the values (XOR: a^a = 0 (property))
        3) Cyclic Sort (put the value in the same index as the value)
*/

// Approach 1: Simple Math (Sum of first N natural numbers)
// Time Complexity:  O(N)
// Space Complexity: O(1)
int findMissingNumber_Math(const vector<int>& nums){
    int n = nums.size();

    long long requiredSum = (n*(n+1))/2;
    long long currentSum = 0;
    
    for(int i=0; i<nums.size(); i++){
        currentSum += nums[i];
    }

    return requiredSum - currentSum;
}

// Approach 2: Cyclic Sort (Put each value at its matching index)
// Time Complexity:  O(N)
// Space Complexity: O(1)
// Note: nums is passed by value so caller's array is not mutated
int findMissingNumber_CyclicSort(vector<int> nums){
    int i=0; 
    int n = nums.size();

    while(i<n){
        if(i != nums[i] && nums[i] < n){
            swap(nums[i], nums[nums[i]]);
        }else{
            i++;
        }
    }

    for(int i=0; i<nums.size(); i++){
        if(nums[i] != i){
            return i;
        }
    }

    return nums.size();
}

// Approach 3: XOR Bit Manipulation
// Time Complexity:  O(N)
// Space Complexity: O(1)
int findMissingNumber_XOR(const vector<int>& nums){
    int xorSum = nums.size();

    for(int i=0; i<nums.size(); i++){
        xorSum ^= nums[i]^i;
    }

    return xorSum;
}

int main (){
    vector<int> nums = {0, 1, 2};

    cout << "Math sum method:    " << findMissingNumber_Math(nums) << endl;
    cout << "Cyclic sort method: " << findMissingNumber_CyclicSort(nums) << endl;
    cout << "XOR method:         " << findMissingNumber_XOR(nums) << endl;

    return 0;
}
