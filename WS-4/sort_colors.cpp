#include <iostream>
#include <vector>

void sortColors(std::vector<int>& nums) {
    int l{}, mid{}, h{static_cast<int>(nums.size() - 1)};
    while (mid <= h)
        if (nums[mid] == 0)
            std::swap(nums[mid++], nums[l++]);
        else if (nums[mid] == 1)
            mid++;
        else 
            std::swap(nums[mid], nums[h--]);
}

