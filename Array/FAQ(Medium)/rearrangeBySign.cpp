#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// Approach 1: Using Simple BruteForce
// Time Complexity:  O(N)
// Space Complexity: O(N)

void rearrangeBySign_brute(const vector<int>& nums){
    int positiveIndex = 0;
    while(nums[positiveIndex] < 0)positiveIndex++;

    int negativeIndex=0;
    while(nums[negativeIndex] > 0)negativeIndex++;

    int i=0;
    vector<int> result;
    while(result.size() != nums.size()){
        result.push_back(nums[positiveIndex]);
        positiveIndex++;
        while(nums[positiveIndex] < 0 && positiveIndex < nums.size())positiveIndex++;

        result.push_back(nums[negativeIndex]);
        negativeIndex++;
        while(nums[negativeIndex] >0 &&  negativeIndex <nums.size())negativeIndex++;

        i++;
    }
}

// Approach 2: Optimal Solution
// Time Complexity:  O(N)
// Space Complexity: O(N)
void rearrangeBySign_optimal(const vector<int>& nums){
    vector<int> result(nums.size(),0);

    int positiveIndex = 0;
    int negativeIndex = 1;

    for(int i=0; i<nums.size(); i++){
        if(nums[i] < 0){
            result[negativeIndex] = nums[i];
            negativeIndex += 2;
        }else{
            result[positiveIndex] = nums[i];
            positiveIndex += 2;
        }
    }

    for(auto it: result){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> nums = {2,4,5,-1,-3,-4};

    rearrangeBySign_brute(nums);
    rearrangeBySign_optimal(nums);
    return 0;
}
