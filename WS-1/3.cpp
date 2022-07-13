#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
//Since the majority element appears more than n / 2 times, the n / 2-th element is the majority
//A partial sort by nth element is done.
int majorityElement(std::vector<int>& nums) 
{
        std::nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
        return nums[nums.size() / 2];
}
int main()

{
    std::vector<int> v{ 6, 9, 0, 1, 2, 7, 5, 8, 0, 0, 7, 7, 6, 6, 1 };
    std::cout << majorityElement(v) << std::endl;
}