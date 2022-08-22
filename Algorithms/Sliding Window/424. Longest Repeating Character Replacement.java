class Solution {
    public int characterReplacement(String s, int k) {
        int[] cnt = new int[26];
        int maxLen = 0, maxCnt = 0;
        int left = 0;
        for(int right = 0; right < s.length(); ++right) {
            maxCnt = Math.max(maxCnt, ++cnt[s.charAt(right) - 'A']);
            if(right - left + 1 > maxCnt + k) {
                cnt[s.charAt(left) - 'A'] -= 1;
                left += 1;
            }
            maxLen = Math.max(maxLen, right - left + 1);
        }
        return maxLen;
    }
}
