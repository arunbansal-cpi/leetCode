#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    int cornerCheck(int start, int n, int pos){
        /*
        Check whether given position lies outside or not of given interior matrix

        Args:
            start (int): starting row or edge of interior edge

        Returns:
            (int):  return the current position or exterior edge of internal matrix
        */
        int leftTop = start - 1, rightBottom = start + n;
        if (pos <= leftTop)
            return start;
        else if (pos >= rightBottom)
            return rightBottom - 1;
        else
            return pos;
    }
    void rotatebyN(vector<vector<int>>& matrix, int start, int n){
        /*
        Recursive method to rotate the exterior edge of interior matrix with reducing size and increasing
        starting point i.e [0][0], [1][1], [2][2], ....
        e.g.
            Input:
            {
                {5,1,9,11},
                {2,4,8,10},
                {13,3,6,7},
                {15,14,12,16}
            }
            Output:
                start = 0, n = 4
                    15 13 2 5
                    14 4 8 1
                    12 3 6 9
                    16 7 10 11

                start = 1, n = 2
                    15 13 2 5
                    14 3 4 1
                    12 6 8 9
                    16 7 10 11

        Args
            matrix (vector<vector<int>> &): given image matrix
            start (int): starting of exterior edge of interior matrix
            n (int): reducing size of interior matrix
        
        Returns:
            (void)
        */
        if( n < 2)
            return;
        // Rotate the exterior edge of interior matrix
        for(int i = 0; i < n - 1; i++){
            int currRow = start, currCol = start + i, nextRow, nextCol;
            // Preserve the first row elements of exterior edge
            int temp = matrix[currRow][currCol];
            int diff = n - i - 1;
            for(int j=0; j<4; j++){
                // Get the next rotated position for 4 rotations
                if(j == 0){
                    nextRow = currRow + diff;
                    nextCol = start;
                }
                if(j == 1){
                    nextRow = n - 1 + start;
                    nextCol = currCol + diff;
                }
                if(j == 2){
                    nextRow = cornerCheck(start, n, currRow - diff);
                    nextCol = n - 1 + start;
                }
                if(j == 3){
                    nextRow = cornerCheck(start, n, currRow - diff);
                    nextCol = currCol - diff;
                }
                // Replace the current position wih next position in rotation
                if(j == 3)
                    matrix[currRow][currCol] = temp;
                else
                    matrix[currRow][currCol] = matrix[nextRow][nextCol];
                // Change the current pos with next position in iteration
                currRow = nextRow;
                currCol = nextCol;
            }       
        }
        // Rotate the interior matrix by increasing starting edge and reducing size
        rotatebyN(matrix, start + 1, n - 2);
        
    }
    void rotate(vector<vector<int>>& matrix) {
        /*
        You are given an n x n 2D matrix representing an image, rotate the image 
        by 90 degrees (clockwise).
        Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
        Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

        Args:
            matrix (vector<vector<int>> &): give image matrix
        
        Returns:
            (void)
        */
        int n = matrix.size();
        rotatebyN(matrix, 0, n);
    }
};

int main(){
    //vector<vector<int>> image{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    vector<vector<int>> image{{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    Solution sl;
    sl.rotate(image);
}