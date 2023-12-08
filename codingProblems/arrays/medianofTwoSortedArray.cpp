#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    double getMedian(vector<int> v1, vector<int> v2, int s1, int s2){
        int st = 0;
        int end = s1;    //length of smallest vector
        int realMedian = (s1+s2+1)/2;
        int l1, l2, r1, r2, m1, m2, la, lb;
        while(true){    
            cout<<"st:"<<st<<" end:"<<end<<endl;
            m1 = (st+end)/2;        //left half of small vector
            la = m1;
            lb = realMedian - la;   //remaining part of left partition
            cout<<"la:"<<la<<" lb:"<<lb<<endl;
            l1 = la>0 ? v1[la-1]: INT_MIN;
            r1 = la<s1 ? v1[la]:  INT_MAX;
            l2 = lb>0? v2[lb-1] : INT_MIN;
            r2 = lb<s2?v2[lb]:INT_MAX;
            cout<<"l1:"<<l1<<" r1:"<<r1;
            cout<<" l2:"<<l2<<" r2:"<<r2<<endl;
            if((l1 <= r2 ) && (l2 <= r1)){
                if((s1+s2)%2==0){
                    double m = max(l1,l2);
                    m += min(r1, r2);
                    cout<<"m:"<<m<<endl;
                    return m/2.000000;
                }
                else
                     return max(l1,l2)/1.000000;
            }
            else if(l1<r2)
                st = m1+1;
            else
                end = m1-1;
        }
    }     
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m<n)
            return getMedian(nums1, nums2, m, n);
        else
            return getMedian(nums2, nums1, n, m);
    }
};

int main(){
    vector<int> gas{}, cost{1};
    Solution sl;
    double result = sl.findMedianSortedArrays(gas, cost);
    cout<<result<<endl;
}