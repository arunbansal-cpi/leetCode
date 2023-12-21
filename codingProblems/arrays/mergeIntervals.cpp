#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int findOverlappingNodeIndex(vector<vector<int>> merged, vector<int> v, int which){
        int st = 0;
        int end = merged.size()-1;
        int mid = -1;
        int element = v[which];
        while(st<=end){
            mid = (st+end)/2;
            int midElement = merged[mid][which];
            if(midElement == element)
                break;
            else if(midElement > element)  
                end = mid -1;
            else
                st = mid + 1;
        }
        return mid;
    }

    void updateMerged(vector<vector<int> >& merged, int st, int end, vector<int> v){
        vector<vector<int> >::iterator begin;
        if(st == end){
                begin = merged.begin() + st;
                if(begin->at(0) > v[1]){
                    if(begin  == merged.begin())
                        merged.insert(begin, v);
                    else{
                        *(begin - 1)[0] = min(begin->at(0), v[0]);
                        *(begin - 1)[1] = max(begin->at(1), v[1]);
                    }

                    
                }
                else if(v[0] > begin->at(1)){
                    if(begin + 1  == merged.end())
                        merged.push_back(v);
                    else
                        merged.insert(begin+1, v);
                }
                else {
                    (*begin)[0] = min(begin->at(0), v[0]);
                    (*begin)[1] = max(begin->at(1), v[1]);
                } 
        }
        else{
            vector<vector<int> >::iterator begin = st == 0 ? merged.begin() + st :  merged.begin() + st - 1, it, delete_node, last = merged.begin() + end;
            delete_node = last;
            for( it = begin+1; it < last; it++){
                delete_node = merged.erase(it);
            } 
            if(begin->at(1) < v[0] && delete_node->at(0) > v[1])
                merged.insert(delete_node, v);
            else if(begin->at(0) > v[0] && delete_node->at(0) > v[1]){
                (*begin) = v;
            }
            else{
                (*begin)[0] = min(begin->at(0), v[0]);
                (*begin)[1] =  max(delete_node->at(1), v[1]);
                merged.erase(delete_node);
            }

        }   

    }   
    vector<vector<int> > mergeIntervals(vector<vector<int> >& intervals) {
        int intvSize = intervals.size();
        vector<vector<int> > mergedIntervals;
        mergedIntervals.push_back(intervals[0]);
        if(intvSize > 1){
            for(vector<vector<int> >::iterator it = intervals.begin() + 1; it != intervals.end(); it++){
                int start = findOverlappingNodeIndex(mergedIntervals, *it, 0);
                int end = findOverlappingNodeIndex(mergedIntervals, *it, 1);
                updateMerged(mergedIntervals, start, end, *it);
            }
        }
        return mergedIntervals;
    }
};

int main(){
    vector<vector<int> > gas{
        {1,5},
        {10,15},
        {20,50},
        {80, 100},
        {85,95},
        {55,75},
        {45,85},
        {0, 16},
        {16, 17},
        {17, 18},
        {19, 101}
    };
    Solution sl;
    vector<vector<int> > result = sl.mergeIntervals(gas);
}