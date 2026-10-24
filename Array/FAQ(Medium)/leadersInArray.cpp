#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// Approach 1: Traversing from the right
// Time Complexity:  O(N)
// Space Complexity: O(1) auxiliary space (O(N) to store result)

vector<int> leadersInArray(const vector<int>& nums){
    int n = nums.size();
    int currentLeader = nums[n-1];

    vector<int> result;
    result.push_back(currentLeader);

    for(int i=n-2; i>=0; i--){
        if(nums[i] > currentLeader){
            currentLeader = nums[i];
            result.push_back(currentLeader);
        }
    }

    reverse(result.begin(), result.end());
    return result;
}

int main(){
    vector<int> nums = {1,2,5,3,1,2};

    vector<int> result = leadersInArray(nums);
    for(auto it: result){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}
