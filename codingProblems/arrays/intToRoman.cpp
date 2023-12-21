
#include<iostream>
#include<map>
#include<string>
using namespace std;
class Solution {
public:
    


    string intToRoman(int num) {
        string result;
        map<int, string> numMap = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
        };
        for(map<int, string>::reverse_iterator mit = numMap.rbegin(); mit != numMap.rend(); mit++){   
            if(!num)
                break;
            int divider = (*mit).first;
            int divisor = num / divider;
            if(divisor){
                for(int i=0;i<divisor;i++)
                    result.append(numMap[divider]);
                num %= divider;
            }
        }
        return result;
    }
};

int main(){
    Solution sl;
    string result = sl.intToRoman(58);
    cout<<"result:"<<result<<endl;
}