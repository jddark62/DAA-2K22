// Find maximum and minimum of a set of elements using divide and conquer.

#include <iostream>
#include <vector>
#include <climits>

//divide and conquer approach

void findMinAndMax(std::vector<int> const &numbers, int low, int high, int &min, int &max)
{
    // if the array contains only one element
 
    if (low == high)                    // common comparison
    {
        if (max < numbers[low]) {           // comparison 1
            max = numbers[low];
        }
 
        if (min > numbers[high]) {          // comparison 2
            min = numbers[high];
        }
 
        return;
    }
 
    // if the array contains only two elements
 
    if (high - low == 1)                // common comparison
    {
        if (numbers[low] < numbers[high])       // comparison 1
        {
            if (min > numbers[low]) {       // comparison 2
                min = numbers[low];
            }
 
            if (max < numbers[high]) {      // comparison 3
                max = numbers[high];
            }
        }
        else {
            if (min > numbers[high]) {      // comparison 2
                min = numbers[high];
            }
 
            if (max < numbers[low]) {       // comparison 3
                max = numbers[low];
            }
        }
        return;
    }
 
    // find the middle element
    int mid = (low + high) / 2;
 
    // recur for the left subarray
    findMinAndMax(numbers, low, mid, min, max);
 
    // recur for the right subarray
    findMinAndMax(numbers, mid + 1, high, min, max);
}
int main(int argc, const char** argv) {

    std::vector<int> numbers = { 7, 2, 9, 3, 1, 6, 7, 8, 4 };
 
    // initialize the minimum element by INFINITY and the
    // maximum element by -INFINITY
    int max = INT_MIN, min = INT_MAX;
 
    int n = numbers.size();
    findMinAndMax(numbers, 0, n - 1, min, max);
 
    std::cout << "The minimum array element is " << min << std::endl;
    std::cout << "The maximum array element is " << max << std::endl;
 
    return 0;
}