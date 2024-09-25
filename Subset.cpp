#include <iostream>
#include <vector>

using namespace std;

bool hasSubsetSum(const vector<int>& nums, int target, int currentSum = 0, int index = 0) {
    if (currentSum == target) {
        return true;
    }

    if (currentSum > target || index == nums.size()) {
        return false;
    }

    // Try including the current element in the subset
    if (hasSubsetSum(nums, target, currentSum + nums[index], index + 1)) {
        return true;
    }

    // Try excluding the current element from the subset
    if (hasSubsetSum(nums, target, currentSum, index + 1)) {
        return true;
    }

    return false;
}

int main() {
    int n, targetSum;
    
    cout << "Enter number of elements in the set: ";
    cin >> n;
    
    vector<int> set(n);
    
    cout << "Enter the elements of the set:\n";
    for (int i = 0; i < n; i++) {
        cin >> set[i];
    }

    cout << "Enter the target sum: ";
    cin >> targetSum;

    if (hasSubsetSum(set, targetSum)) {  // Corrected call
        cout << "Subset with target sum exists." << endl;
    } else {
        cout << "Subset with target sum does not exist." << endl;
    }

    return 0;
}
