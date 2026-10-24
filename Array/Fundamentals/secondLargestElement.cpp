#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <climits>
using namespace std;

/*
    priority_queue<int> pq;             <---- This is max-heap (Default)
    priority_queue<int,                 <---- This is min-heap (changing the order by providing a custom comparator)
                    vector<int>,
                    greater<int>> pq;
*/

// Approach 1: Using Max-Heap (Priority Queue)
// Time Complexity:  O(N log N)
// Space Complexity: O(N) auxiliary space
int findSecondLargestElement_PriorityQueue(vector<int> nums){ // This is using extra memory
    priority_queue<int> pq;
    for(int i=0; i<nums.size(); i++){
        pq.push(nums[i]);
    }

    if(nums.size() <= 1){
        return -1;
    }
    
    if(nums.size() == 2){
        if(nums[0] > nums[1]){
            return nums[1];
        }else if(nums[0] < nums[1]){
            return nums[0];
        }else{
            return -1;
        }
    }

    int largestNumber = pq.top();
    while(!pq.empty() && pq.top() == largestNumber){
        pq.pop();
    }

    if(pq.empty()){
        return -1;
    }
    
    return pq.top();
}

// Approach 2: Optimal (Single-pass linear scan)
// Time Complexity:  O(N)
// Space Complexity: O(1)
int findSecondLargestElement_Optimal(vector<int> nums){
    int largestElement = INT_MIN;
    int secondLargestElement = INT_MIN;

    for(int i=0; i<nums.size(); i++){
        if(nums[i] > largestElement){
            secondLargestElement = largestElement;
            largestElement = nums[i];
        }else if(nums[i] > secondLargestElement && nums[i] < largestElement){
            secondLargestElement = nums[i];
        }
    }

    if(secondLargestElement == INT_MIN) return -1;

    return secondLargestElement;
}


int main(){
    vector<int> nums = {8,8,7,6,5};
    vector<int> nums1 = {10,10,10,10};

    cout << "Priority Queue approach: " << findSecondLargestElement_PriorityQueue(nums) << endl;
    cout << "Optimal approach:        " << findSecondLargestElement_Optimal(nums) << endl;

    cout << "All equal elements (PQ):      " << findSecondLargestElement_PriorityQueue(nums1) << endl;
    cout << "All equal elements (Optimal): " << findSecondLargestElement_Optimal(nums1) << endl;
    return 0;
}
