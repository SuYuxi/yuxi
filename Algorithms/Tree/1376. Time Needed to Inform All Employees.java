class Solution {
    public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {
        List<List<Integer>> tree = new ArrayList();
        for(int i = 0; i < n; ++i) {
            tree.add(new ArrayList());
        }
        for(int i = 0; i < n; ++i) {
            if(i == headID) continue;
            tree.get(manager[i]).add(i);
        }
        int time = dfs(headID, tree, informTime);
        
        return time;
    }
    
    private int dfs(int id, List<List<Integer>> tree, int[] informTime) {
        if(tree.get(id).isEmpty()) return 0;
        int time = 0;
        List<Integer> children = tree.get(id);
        for(int i = 0; i < children.size(); ++i) {
            time = Math.max(time, dfs(children.get(i), tree, informTime));
        }
        return informTime[id] + time;
    }
}
