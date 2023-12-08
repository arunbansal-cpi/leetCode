#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        int word_replace = 0;
        int j = s.size()-1;
        string temp;
        string space = " ";
        int word_r_start, word_r_end;
        while(j >= 0){
            //Removing spaces
            while(j>=0 && s[j] == ' '){
                j--;
            }
            word_r_end= j;
            //Getting the words
            while(j>= 0 && s[j] != ' '){
                j--;
            }
            word_r_start = j+1;
            if(word_r_start <= word_r_end){
                //Appendig the word from right and then a space
                temp.append(s, word_r_start, word_r_end - word_r_start+1);
                temp.append(space);
            }
        }
        //Removing the last space
        temp.pop_back();
        return temp;
    }
};

int main(){
    Solution sl;
    string result = sl.reverseWords("  hello world  ");
    cout<<result;
}