/*
There is a two dimensional array where each row and each column is sorted. 
You are given an element K. 
Find the element in the array with an efficient time complexity.
*/

//Time Complexity : O(n)
#include <iostream>
#include <vector>
bool binarySearch(std::vector<std::vector<int>>& matrix, int target) {
        int rows = matrix.size(),
			cols = matrix[0].size(),
            row = 0, col = cols - 1;
			
        while (row < rows && col > -1) {
            int cur = matrix[row][col];
            if (cur == target) return true;
            if (target > cur) row++;
            else col--;
        }
        
        return false;
    }
int main(int argc, const char** argv) {

    int target;
    std::vector<std::vector<int>> vect
    {
        {3, 5, 7, 25},
        {17, 20, 24, 36},
        {21, 23, 27, 38},
        {28, 29, 30, 40}
    };
    std::cout << "Enter element to find: ";
    std::cin >> target;
    if(binarySearch(vect, target))
    {
    std::cout << "Element found.\n";
    }
    else
    {
        std::cout<<"Element not found.\n";
    }
    return 0;
}

