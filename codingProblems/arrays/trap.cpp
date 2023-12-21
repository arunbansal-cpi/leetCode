#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int calculateArea(int tillHeight, int currentEnd, int currentStart,
                    vector<int> &height) {
    /*
    Calculate the trap area between starting and end index

    Args:
        tillHeight (int): total occupied space b/w starting and ending index
        currentEnd (int): area's ending index
        currentStart (int): area's starting index
        height (vector<int> &): given height vector

    Returns:
        currentTrapArea (int): area traped in betwwen given indices
    */
    int trapLength = (currentEnd - currentStart + 1);
    int areaMaxHeight = max(height[currentEnd], height[currentStart]);
    int areaMinHeight = min(height[currentEnd], height[currentStart]);
    int heightDiff = areaMaxHeight - areaMinHeight;
    int currentTrapArea =
        (trapLength * areaMinHeight) - tillHeight + heightDiff;
    return currentTrapArea;
  }
  int trap(vector<int> &height) {
    /*
    Given n non-negative integers representing an elevation map where the
    width of each bar is 1, compute how much water it can trap after raining.
    */
    int sz = height.size();
    int st = 0;
    int end = sz - 1;
    int trapArea = 0;
    // Eliminating increasing height from left, since there will be no water
    // trap
    for (int i = 0; i < sz - 1; i++) {
      st = i;
      if (height[i] > height[i + 1])
        break;
    }
    // Eliminating increasing height from right, since there will be no water
    // trap
    for (int i = sz - 1; i > 0; i--) {
      end = i;
      if (height[i] > height[i - 1])
        break;
    }
    int currentAreaStartingIndex = st;
    int currentAreaEndingIndex = 0;
    int currentAcucumalatedHeight = height[currentAreaStartingIndex];
    int currentIndex = st + 1;
    currentAreaStartingIndex = st;
    // Move from left to right, and get area between first 2 high bulding in
    // array
    while (currentIndex <= end) {
      currentAcucumalatedHeight += height[currentIndex];
      if (height[currentAreaStartingIndex] <= height[currentIndex]) {
        trapArea += calculateArea(currentAcucumalatedHeight, currentIndex,
                                  currentAreaStartingIndex, height);
        currentAreaStartingIndex = currentIndex;
        currentAreaEndingIndex = currentIndex;
        currentAcucumalatedHeight = height[currentAreaStartingIndex];
      }
      currentIndex++;
    }
    // Move right to left, and get area between first 2 high bulding in array
    if (currentAreaEndingIndex < end) {
      currentAreaStartingIndex = end;
      currentAcucumalatedHeight = height[currentAreaStartingIndex];
      currentIndex = end - 1;
      st = currentAreaEndingIndex;
      while (currentIndex >= st) {
        currentAcucumalatedHeight += height[currentIndex];
        if (height[currentAreaStartingIndex] <= height[currentIndex]) {
          currentAreaEndingIndex = currentIndex;
          trapArea +=
              calculateArea(currentAcucumalatedHeight, currentAreaStartingIndex,
                            currentIndex, height);
          currentAreaStartingIndex = currentIndex;
          currentAreaEndingIndex = currentIndex;
          currentAcucumalatedHeight = height[currentAreaStartingIndex];
        }
        currentIndex--;
      }
    }
    return trapArea;
  }
};
int main() {
  vector<int> gas{0, 2, 0};
  Solution sl;
  int result = sl.trap(gas);
  cout << "result:" << result << endl;
}