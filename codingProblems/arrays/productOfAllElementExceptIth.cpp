#include<iostream>
#include<string>
#include<vector>
using namespace std;


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prev; 
        vector<int> next(n,1);
        int start = 0, end = n - 1, j;
        //cout<<start<<" "<<n<<" "<<end<<endl;
        for(j=0;j<n;j++)
            next[end-j] = ((end - j == end) ? 1 : (next[end-j+1] * nums[end-j+1])); 
            
        for(j=0;j<n;j++){
            prev= (j==start)? 1 : prev*nums[j-1];
            next[j] *= prev;
        }
        return next;
    }
};

int main(){
    vector<int> gas{1,2,3, 4 ,5};
    Solution sl;
    vector<int> result = sl.productExceptSelf(gas);
}