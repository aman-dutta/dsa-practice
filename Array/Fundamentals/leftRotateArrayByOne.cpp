#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

/*
    There are 2 ways to solve this problem:
        1) Since we just have to rotate this by 1, I can simply take 1 variable and store the first. 
            Then replace the current index with the next index value. (But what if we have to rotate by more than 1?)
        2) Thus, instead of using option-1, I will use the concept of reversing. 
                if k = 2, 
                    nums = {1,2,3,4,5}, ans = {3,4,5,1,2}
                         = {2,1,3,4,5}  (reverse the first k)
                         = {2,1,5,4,3}  (reverse the remaining)
                         = {3,4,5,1,2}  (reverse the whole array)
            This way we can rotate by k
*/

// Time Complexity:  O(N) - three reversals visit elements at most twice
// Space Complexity: O(1) - in-place reversal
void leftRotateByOne(vector<int>& nums, int k){
    reverse(nums.begin(), nums.begin()+k);
    reverse(nums.begin()+k, nums.end());
    reverse(nums.begin(),nums.end());
}

int main(){
    vector<int> nums = {1,2,3,4,5};

    leftRotateByOne(nums,1); // 1 because we need to rotate this array by 1
    for(auto it: nums){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}
