import java.util.*;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> hm = new HashMap<>();
        for (int i = 0; i < nums.length; i++) hm.put(nums[i], i);
        for (int i = 0; i < nums.length; i++) {
            int curr = nums[i];
            int diff = target - curr;
            if (hm.get(diff) != null && hm.get(diff) != i) {
                return new int[] {i, hm.get(diff)};
            }
        }
        return new int[2];
    } 
}