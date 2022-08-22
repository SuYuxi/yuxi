class Solution {
    public String getHint(String secret, String guess) {
        int[] cnt = new int[10];
        int bulls = 0, cows = 0;
        for(int i = 0; i < secret.length(); ++i) {
            if(secret.charAt(i) == guess.charAt(i)) ++bulls;
            else { 
                if(cnt[guess.charAt(i) - '0']-- > 0) ++cows;
                if(cnt[secret.charAt(i) - '0']++ < 0) ++cows;
            }
        }
        return bulls + "A" + cows + "B";
    }
}
