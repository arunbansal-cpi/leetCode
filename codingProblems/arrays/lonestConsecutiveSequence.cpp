#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 1;
        map<int, bool> consecutiveMap;
        for(int j=0;j<nums.size();j++){
            if(consecutiveMap.find(nums[j]) == consecutiveMap.end()){
                consecutiveMap.insert(pair<int, bool>(nums[j], false));
                if(consecutiveMap.find(nums[j] - 1 ) != consecutiveMap.end()){
                    consecutiveMap[nums[j] - 1] = true;
                    consecutiveMap[nums[j]] = true;
                }
                if(consecutiveMap.find(nums[j] + 1) != consecutiveMap.end()){
                        consecutiveMap[nums[j]] = true;
                        consecutiveMap[nums[j] + 1] = true;
                }
            }
        }
        map<int, bool>::iterator it = consecutiveMap.begin();
        map<int, bool>::iterator prev = consecutiveMap.end();
        int count = 1;
        
        while(it != consecutiveMap.end()){
            cout<<it->first<<"->"<<it->second<<endl;
            if(prev != consecutiveMap.end() 
               && prev->first + 1 == it->first 
               && it->second){
                count++;
                if(maxLen<count)
                    maxLen = count;
                
            }
            else
                count= 1;
            prev = it;
            it++;
        }
        return maxLen;
    }
};

int main(){
    vector<int> gas{9,1,4,7,3,-1,0,5,8,-1,6};
    Solution sl;
    int result = sl.longestConsecutive(gas);
    cout<<"result:"<<result<<endl;
}