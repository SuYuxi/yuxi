class Solution {
    public double average(int[] salary) {
        int number = salary.length;
        if(number <= 2) return 0;
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        double sum = 0;
        for(int s : salary) {
            sum += s;
            min = Math.min(min, s);
            max = Math.max(max, s);
        }
        return (sum - min - max) / (number - 2);
    }
}
