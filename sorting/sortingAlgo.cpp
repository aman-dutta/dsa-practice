#include <iostream>
using namespace std;

void bubbleSort(vector<int>& nums){
    for(int i=0; i<nums.size()-1; i++){
        for(int j=1; j<nums.size(); j++){
            if(nums[j] < nums[j-1]){
                swap(nums[j], nums[j-1]);
            }
        }
    }
}

void bubbleSortWithFlag(vector<int>& nums){
    bool isSwapped;                                     //Flag to stop running the loop if we find a pass with no swaps
    for(int i=0; i<nums.size()-1; i++){
        isSwapped = false;
        for(int j=1; j<nums.size()-i; j++){             //Stopping at nums.size()-i because the last i elements are already in their final sorted positions
            if(nums[j] < nums[j-1]){
                swap(nums[j], nums[j-1]);
                isSwapped = true;
            }
        }

        if(!isSwapped) break;
    }
}

void selectionSort(vector<int>& nums){
    for(int i=0; i<nums.size()-1; i++){
        int minIndex = i;
        for(int j=i; j<nums.size(); j++){
            if(nums[j] < nums[minIndex]){
                minIndex = j;
            }
        }

        if(minIndex != i){
            swap(nums[i], nums[minIndex]);
        }
    }
}

void insertionSort(vector<int>& nums){
    for(int i=1; i<nums.size();i++){
        int index = i;
        while(index >0 && nums[index] < nums[index-1]){
            swap(nums[index], nums[index-1]);
            index--;
        }
    }
}

void mergeSortAlgo(vector<int>& nums, int low, int mid, int high){
    vector<int> leftArray;
    vector<int> rightArray;
    int leftIndex = 0;
    int rightIndex = 0;

    for(int i=0; i<=mid; i++){
        leftArray.push_back(nums[i]);
    }
    for(int i=mid+1; i<=high; i++){
        rightArray.push_back(nums[i]);
    }

    int i=0;
    while(leftIndex < leftArray.size() && rightIndex < rightArray.size()){
        if(leftArray[leftIndex] <= rightArray[rightIndex]){
            nums[i] = leftArray[leftIndex];
            leftIndex++;
        }else{
            nums[i] = rightArray[rightIndex];
            rightIndex++;
        }
        i++;
    }

    while(leftIndex < leftArray.size()){
        nums[i] = leftArray[leftIndex];
        leftIndex++;
        i++;
    }

    while(rightIndex < rightArray.size()){
        nums[i] = rightArray[rightIndex];
        rightIndex++;
        i++;
    }
}

void mergeSortHelper(vector<int>& nums, int low, int high){
    if(low >= high){
        return;
    }

    int mid = low + (high-low)/2;
    mergeSortHelper(nums,low,mid);
    mergeSortHelper(nums,mid+1, high);
    mergeSortAlgo(nums,low,mid,high);
}

void mergeSort(vector<int>& nums){
    int n = nums.size();
    mergeSortHelper(nums,0,n-1);
}

int partitionIndex(vector<int>& nums, int low, int high){
    int pivot = nums[low];
    int i=low;
    int j=high;

    while(i<j){
        while(nums[i] <= pivot && i+1 < nums.size()){
            i++;
        }
        while(nums[j] > pivot && j-1 >0){
            j--;
        }

        if(i<j){
            swap(nums[i],nums[j]);
        }
    }

    swap(nums[low], nums[j]);
    return j;

}

void quickSortHelper(vector<int>& nums,int low, int high){
    if(low < high){
        int pi = partitionIndex(nums, low, high);
        quickSortHelper(nums,low, pi-1);
        quickSortHelper(nums,pi+1, high);
    }
}

void quickSort(vector<int>& nums){
    int n = nums.size();
    quickSortHelper(nums,0,n-1);
}

int main (){
    vector<int> nums = {7, 4, 1, 5, 3};

    // bubbleSort(nums);  
    // bubbleSortWithFlag(nums);
    // selectionSort(nums);
    // insertionSort(nums);
    // mergeSort(nums);
    quickSort(nums);

    for(auto it: nums){
        cout<<it<<" ";
    }
    cout<<endl;
}
