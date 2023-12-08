#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        /*
        Given an array of integers citations where citations[i] is the 
        number of citations a researcher received for their ith paper, return 
        the researcher's h-index.

        According to the definition of h-index on Wikipedia: The h-index is defined 
        as the maximum value of h such that the given researcher has published at 
        least h papers that have each been cited at least h times.

        Constraints:
        n == citations.length
        1 <= n <= 5000
        0 <= citations[i] <= 1000

        Args
            citations (vector<int> &): given citations
        
        Returns:
            maxH (int): highest H index from citations among n papers.
        */
        int hIndexCountArr[1001] = {0};
        int maxH = -1;
        //Calculate the number of citation for each index and also maximum citation 
        for(int i=0;i<citations.size();i++){
            hIndexCountArr[citations[i]]++;
            if(citations[i]>maxH){
                maxH = citations[i];
            }
        }
        if(hIndexCountArr[maxH] >= maxH)
            return maxH;
        // Add the citations  of current index and next index to 
        // get total number of citation for index
        // If total number of citiation is greater than index value then
        // return that index
        for(int i = maxH - 1; i >= 0; i--){
            hIndexCountArr[i] += hIndexCountArr[i+1];
            if(hIndexCountArr[i] >= i){
                maxH = i;
                break;
            }
        }
        return maxH;
    }
};