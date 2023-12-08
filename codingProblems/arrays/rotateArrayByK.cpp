#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;


class Solution {
public:
    void swap(vector<int>& nums, int sourceIndex, int destIndex, int len){
        for(int i = 0; i<len; i++){
            int temp = nums[sourceIndex+i];
            nums[sourceIndex+i] = nums[destIndex+i];
            nums[destIndex+i] = temp;
        }
    }
    void displayNums(vector<int>& nums){
        for(int i = 0; i<nums.size(); i++)
            cout<<nums[i]<<" ";
        cout<<endl; 
    }
    void rotateByK(vector<int>& nums, int startIndex, int lastIndex, int k){
        cout<<"startIndex:"<<startIndex<<" lastIndex:"<<lastIndex<<" k:"<<k<<endl;
        if(startIndex >= lastIndex)
            return;
        int arraySize = lastIndex - startIndex + 1;
        int swapDiff = arraySize - k;
        cout<<"arraySize:"<<arraySize<<" swapDiff:"<<swapDiff<<endl;
        
        if(swapDiff >= k){
            swap(nums, startIndex, lastIndex-k+1, k);
            displayNums(nums);
            rotateByK(nums, startIndex+k, lastIndex, k);
        }
        else{
            swap(nums, startIndex, lastIndex-k+1,swapDiff);
            displayNums(nums);
            rotateByK(nums, startIndex+swapDiff, lastIndex, k-swapDiff);
        }
    }
    void rotatebySlice(vector<int>& nums, int k){
        cout<<"rotating by slicing"<<endl;
        nums.insert(nums.begin(), nums.end() - k, nums.end());
        displayNums(nums);
        nums.erase(nums.end() - k, nums.end());
        displayNums(nums);
        
    }
    void rotate(vector<int>& nums, int k){
        int n = k % nums.size();
        //rotateByK(nums, 0, nums.size() - 1, n);
        nums.insert(nums.begin(), nums.end() - k, nums.end());
        nums.erase(nums.end() - k, nums.end());
    }
   
};

int main(){
    vector<int> gas{1,2,3};
    Solution sl;
    sl.rotate(gas, 1);
    sl.displayNums(gas);
}