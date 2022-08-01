class Solution {
    public boolean areAlmostEqual(String s1, String s2) {
        if(s1.length() != s2.length()) return false;
        int cnt = 0;
        int inx1 = -1, inx2 = -1;
        for(int inx = 0; inx < s1.length(); ++inx) {
            if(s1.charAt(inx) != s2.charAt(inx)) {
                ++cnt;
                if(inx1 != -1) inx2 = inx;
                else inx1 = inx;
            }
        }
        return cnt == 0 || (cnt == 2 && s1.charAt(inx1) == s2.charAt(inx2) && s2.charAt(inx1) == s1.charAt(inx2));
    }
}
