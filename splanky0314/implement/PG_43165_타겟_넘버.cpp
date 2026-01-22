#include <string>
#include <vector>

using namespace std;

int ans = 0;

void dfs(int idx, int cur, int target, vector<int> nums) {
    if(idx >= nums.size()) {
        if(cur == target) ans++;
        return;
    }
    
    dfs(idx+1, cur+nums[idx], target, nums);
    dfs(idx+1, cur-nums[idx], target, nums);
}

int solution(vector<int> numbers, int target) {
    // 14:51 ~ 15:00 : 9min
    dfs(0, 0, target, numbers);
    
    return ans;
}