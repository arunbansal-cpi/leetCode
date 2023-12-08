#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;


class Solution {
public:
    void init(bool **visited, int n){
        /*
        Dynamic allocated visited 2D array for tracking subarray visits

        Args:
            visited (bool **): 2D Array for dynamic allocation
            n (int): size of string
        */
        for(int k=0;k<n;k++)
            visited[k] = new bool[n];
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++)
              visited[j][k] = false;
        }
    }
    string subStringPalindromic(int start, int end, bool **visited, int maxLen, const string &str){
        /*
        Return the palindromic part of substring

        Args:
            start (int): Mark the starting of substring
            end (int): end position of substring
            visited (bool) : 2D array for tracking visited substring
            maxLen (int) : Max length of palindromic substring
            str (string) : Given string
        
        Returns:
            result (string): palindromic of substring
        */

        int subLen = -1; 
        bool isPalindromic = false;
        int initPos = start;
        string result;
        while(start <= end){
            //Checking substring characters
            if(str[start] == str[end]){    
                if(!isPalindromic){
                    isPalindromic = true;
                    subLen = end - start + 1;
                    initPos = start;
                }
            }
            else{
                isPalindromic = false;
            }
            visited[start][end] = true;
            start++;
            end--;
        }
        if(isPalindromic && subLen >= maxLen)
            result = str.substr(initPos, subLen);
        return result;
    }

    string longestPalindrome(string& str) {
        /*
        Get the longest palindromic substring from given string

        Args:
            str (string &): given string
        
        Returns:
            result: longest palindromic string
        */
        int maxLen = 0;
        string result, res;
        int n = str.size();
        bool **visited = new bool *[n];
        int subLen = 0;
        init(visited, n);
        for(int i=0;i<=n-1;i++){
            for(int j=n-1;j>=i;j--){
                //Check whether substring from i to j visited or not
                subLen = j - i + 1; 
                if(visited[i][j])
                    continue;
                //Ignore the substring if already palindromic substring is greater then 
                if(maxLen > subLen)
                    break;
                res = subStringPalindromic(i, j, visited, maxLen, str);
                cout<<"res:"<<res<<endl;
                if(res.size() > maxLen){
                    maxLen = res.size();
                    result = res;
                }
            }
        }
       for(int i = 0; i < n;i++) 
        delete[] visited[i];
     delete []visited;
     return result;
    }
};

int main(){
    string s("cbbd");
    Solution sl;
    cout<<sl.longestPalindrome(s);
}