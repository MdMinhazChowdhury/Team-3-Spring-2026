#include <iostream>
#include <vector>
#include <algorithm>

int main_backup() {
    std::cout << "PokerSim test build running!" << std::endl;

    // Simple test: sort a vector
    std::vector<int> nums = {5, 1, 4, 2, 3};
    std::sort(nums.begin(), nums.end());

    std::cout << "Sorted numbers: ";
    for (int n : nums) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    // Simple logic test
    int a = 7;
    int b = 3;
    std::cout << "a + b = " << (a + b) << std::endl;
    std::cout << "a * b = " << (a * b) << std::endl;

    return 0;
}
