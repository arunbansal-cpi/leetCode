#include<iostream>
#include<string>
#include<vector>
using namespace std;


class Solution {
public:
    int majorityelement(vector<int>& nums) {
        int majorityElement;
        int n = nums.size();
        int j = 0;
        int k = n-1;
        int startPos=0;
        while(j < n){   
            while(j<k){
                //cout<<"j:"<<j<<" k:"<<k<<endl;
                if(nums[j] == nums[j+1])
                    j++;
                else if(nums[j] == nums[k]){
                    int temp = nums[j+1];
                    nums[j+1] = nums[k];
                    nums[k] = temp;
                    j++;
                    k--;
                }
                else
                    k--;
            }
            cout<<"j - startPos + 1"<<j - startPos + 1<<endl;
            if((j - startPos + 1) >= (n/2+1)){
                majorityElement = j;
                break;
            }
            k = n - 1;
            startPos = j;
        }
    return nums[majorityElement];
    }
};

int main(){
    vector<int> gas{3,2,3};
    Solution sl;
    int result = sl.majorityelement(gas);
    cout<<result<<endl;
}