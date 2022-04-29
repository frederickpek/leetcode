import java.util.*;

class Solution {
	public int lengthOfLongestSubstring(String s) {
		if (s.length() == 0) return 0;
		if (s.length() == 1) return 1;

		HashSet<Character> hm = new HashSet<>();

		int left = 0; int longest = 1;
		hm.add(s.charAt(0));
		for (int right = 1; right < s.length(); right++) {
			char rightMost = s.charAt(right);
			if (hm.contains(rightMost)) {
				while (hm.contains(rightMost)) {
					char leftMost = s.charAt(left);
					hm.remove(leftMost);
					left++;
				}
			} 
			hm.add(rightMost);
			longest = Math.max(hm.size(), longest);
		}
		return longest;
	}
}