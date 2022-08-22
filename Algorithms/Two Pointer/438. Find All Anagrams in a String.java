class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        int[] cnt = new int[26];
        List<Integer> res = new ArrayList();
        for(int i = 0; i < p.length(); ++i) {
            cnt[p.charAt(i) - 'a'] += 1;
        }
        int count = p.length();
        int left = 0, right = 0;
        while(right < s.length()) {
            if(cnt[s.charAt(right++) - 'a']-- > 0) --count;
            if(right - left == p.length()) {
                if(count == 0) res.add(left);
                if(cnt[s.charAt(left++) - 'a']++ >= 0) ++count;
            }
        }
        return res;
    }
}
