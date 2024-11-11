//https://leetcode.com/problems/house-robber/

import java.util.*;
class Solution {
    private HashMap<Integer, Integer> memo;
    public int rob(int[] nums) {
        int n = nums.length;
        if (n == 1) return nums[0];
        if (n == 2) return Math.max(nums[0], nums[1]);

        memo = new HashMap<>();
        memo.put(0, nums[0]);
        memo.put(1, Math.max(nums[0], nums[1]));

        return solve(n-1, nums);
    }

    private int solve(int i, int[] nums){
        if (memo.containsKey(i)) return memo.get(i);
        else{
            int result = Math.max(solve(i-2, nums) + nums[i], solve(i-1, nums));
            memo.put(i, result);
            return result;
        }
    }
}
