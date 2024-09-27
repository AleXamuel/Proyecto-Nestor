//https://leetcode.com/problems/word-search/?source=submission-noac
class Solution {
    public boolean exist(char[][] map, String word) {
        char c=word.charAt(0);
        int n=map.length;
        int m=map[0].length;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(map[i][j]==c&&dfs(map,i,j,word,0,new boolean[n][m]))
                    return true;
        return false;
    }
    public boolean dfs(char[][] map, int a, int b,String t,int i,boolean[][] state){
        int n=map.length;
        int m=map[0].length;
        if(i==t.length())
            return true;
        if(a<0||a>=n||b<0||b>=m)
            return false;
        if(t.charAt(i)!=map[a][b])
            return false;
        if(state[a][b])
            return false;
        state[a][b]=true;
        if(dfs(map,a+1,b,t,i+1,state)||dfs(map,a-1,b,t,i+1,state)||dfs(map,a,b+1,t,i+1,state)||dfs(map,a,b-1,t,i+1,state))
            return true;
        state[a][b]=false;
        return false;
    }
}
