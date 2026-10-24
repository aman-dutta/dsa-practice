#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// Time Complexity:  O(N) - single pass to place non-zeros, followed by filling zeros
// Space Complexity: O(1) - in-place modification
void moveZerosToEnd(vector<int>& nums){
    int pointer = 0;

    for(int i=0; i<nums.size(); i++){
        if(nums[i] != 0){
            nums[pointer] = nums[i];
            pointer++;
        }
    }
    while(pointer != nums.size()){
        nums[pointer] = 0;
        pointer++;
    }
}

int main(){
    vector<int> nums = {0,1,4,0,5,2};

    moveZerosToEnd(nums);
    for(auto it: nums){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}
