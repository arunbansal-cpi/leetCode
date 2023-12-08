class Solution {
public:
    string convert(string s, int numRows) {
        /*
        The string "PAYPALISHIRING" is written in a zigzag pattern on a given number 
        of rows like this: (you may want to display this pattern in a fixed font 
        for better legibility)

        P   A   H   N
        A P L S I I G
        Y   I   R
        And then read line by line: "PAHNAPLSIIGYIR"
        */
        int n = s.size();
        if(numRows == 1 || n <= numRows)
            return s;
        string res;
        // Loop through numRows
        for(int currentRow = 0; currentRow < numRows; currentRow++){
            int currentPos = currentRow;
            int dir = 1;
            // For numRows = 3, upOffset = 4, 2, 0
            int upoffset = (numRows - currentRow - 1) * 2;
            // For numRows = 3, downoffset = 0, 2, 4
            int downoffset = currentRow * 2;
            do{
                res.push_back(s[currentPos]);
                if(currentRow == 0)
                    currentPos += upoffset;
                else if(currentRow == numRows - 1)
                   currentPos += downoffset;
                else{
                    if(dir)
                      currentPos += upoffset;
                    else
                      currentPos += downoffset;
                    dir = !dir;
                }           
            }while(currentPos <= n - 1);
        }
        return res;
    }
};