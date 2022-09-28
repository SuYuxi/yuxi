class Solution {
    public int minimumJumps(int[] forbidden, int a, int b, int x) {
        Queue<Pair<Integer, Integer>> queue = new LinkedList();
        queue.offer(new Pair(0, 0));
        Set<Pair<Integer, Integer>> visited = new HashSet(queue);
        int boundary = a + b + x;
        for(int num : forbidden) {
            visited.add(new Pair(0, num));
            visited.add(new Pair(1, num));
            boundary = Math.max(boundary, a + b + num);
        }
        int steps = 0;
        while(!queue.isEmpty()) {
            for(int i = queue.size(); i > 0; --i) {
                Pair<Integer, Integer> p = queue.poll();
                int dir = p.getKey();
                int val = p.getValue();
                if(val == x) return steps;
                if(val + a <= boundary && visited.add(new Pair(0, val + a))) {
                    queue.offer(new Pair(0, val + a));
                }
                if(dir == 0 && val - b > 0 && visited.add(new Pair(1, val - b))) {
                    queue.offer(new Pair(1, val - b));
                }
            }
            steps++;
        }
        return -1;
    }
}
