#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// Time Complexity:  O(N) - single pass through the array
// Space Complexity: O(1) - only two counter variables used
int findMaxConsecutiveOnes(const vector<int>& nums){ 
    int maxOnes = 0;
    int localOnes = 0;
    for(int i=0; i<nums.size(); i++){
        if(nums[i] ==1){
            localOnes++;
            maxOnes = max(maxOnes,localOnes);
        }else{
            localOnes = 0;
        }
    }

    return maxOnes;
}

int main(){
    vector<int> nums = {1,1,0,0,1,1,1,0};

    cout<<findMaxConsecutiveOnes(nums)<<endl;
    return 0;
}
