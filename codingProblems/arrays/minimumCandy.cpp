#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    int candy1(vector<int>& ratings) {
       int sz = ratings.size();
       vector<int> minCandy(sz, 1);
       int minIndex = -1;
       int minRating = 20001;
       int minCandDist = 0;
       //minCandy += getMinCandy(0, sz-1, ratings);
       for(int i=0;i<sz-1;i++){
            if(ratings[i] < ratings[i+1])
                minCandy[i+1] = minCandy[i] + 1;
            else if(ratings[i] > ratings[i+1] && minCandy[i] == minCandy[i+1]){
                int j = i+1;
                while(ratings[j] < ratings[j-1] && minCandy[j] == minCandy[j-1]){
                    minCandy[j-1]++;
                    j--;
                }
            }  
       }
       for(int i=0;i<sz;i++)
            minCandDist+=minCandy[i];
       return minCandDist;
    }

    int consecutiveNumSum(int n){
        return (n*(n+1))/2;
    }

    int candy(vector<int> &ratings){
        /*
        There are n children standing in a line. Each child is assigned a rating value
        given in the integer array ratings. You are giving candies to these children 
        subjected to the following requirements:
        Each child must have at least one candy.
        Children with a higher rating get more candies than their neighbors.

        Args:
            ratings (vector<int> &): given ratings vector
        
        Returns:
            minCandy (int): minimum number of candies required for distribution
        */
        int sz = ratings.size();
        // Initialize the highest and lowest point count 
        int highStepCount = 1;
        int lowestStepCount = 1;
        // Initialize the candy count for 1 for leftmost element 
        int minCandy = 1;  
        int j = 0;
        while(j < sz-1){
            // Add candy count 1 if adjecent child has same rating
            if(ratings[j] == ratings[j+1]){
                highStepCount = 1;
                minCandy += highStepCount;
                j++;
            }
            else{
                // Add the candy count from lowest to highest ratings adjcent child
                while(j < sz - 1 && ratings[j] < ratings[j+1]){
                    highStepCount++;
                    j++;
                    minCandy+=highStepCount;
                }
                // Keep count from highest to lowest ratings adjcent child
                while(j < sz  -1 && ratings[j] > ratings[j+1]){
                    lowestStepCount++;
                    j++;
                }
                // Add the difference of lower side count and upper side movement 
                // if lower side is greater else no need
                int diff = highStepCount > lowestStepCount ? 0 : lowestStepCount - highStepCount;
                // Add conseecutive sum of lower side count value
                minCandy += (diff + consecutiveNumSum(lowestStepCount-1));
                highStepCount = 1;
                lowestStepCount = 1;
            }
        }
        return minCandy;
    }
    
};

int main(){
    vector<int> gas{1, 2, 87, 1, 0};
    Solution sl;
    int result = sl.candy(gas);
    cout<<result<<endl;


}