// https://leetcode.com/problems/number-of-islands/
import java.util.*;
class Solution {
	public static void main(String[] args) {
		char[][] grid = { { '1', '1', '0', '0', '0' }, { '1', '1', '0', '0', '0' }, { '0', '0', '1', '0', '0' },
				{ '0', '0', '0', '1', '1' } };
		Solution p = new Solution();
		System.out.println(p.numIslands(grid));
	
	}
	public int numIslands(char[][] grid) {
		boolean[][] state=new boolean[grid.length][grid[0].length];
		int c=0;
		for(int i=0; i<grid.length;i++){
		    for(int j=0; j<grid[0].length;j++)
			if(!state[i][j]&&grid[i][j]=='1'){
			    c++;
			    bfs(state,grid,i,j);
			}
		}
		return c;
	}
	public void bfs(boolean[][] state,char[][] grid,int a, int b){
		int[] s={a,b};
		Queue<int[]> q=new LinkedList<>();
		q.add(s);
		while(!q.isEmpty()){
		    int[] act=q.poll();
		    int i=act[0];
		    int j=act[1];
		    if(i+1<grid.length&&grid[i+1][j]=='1'&&!state[i+1][j]){
			state[i+1][j]=true;
			q.add(new int[]{i+1,j});
		    }
		    if(j+1<grid[0].length&&grid[i][j+1]=='1'&&!state[i][j+1]){
			state[i][j+1]=true;
			q.add(new int[]{i,j+1});
		    }
		    if(i-1>=0&&grid[i-1][j]=='1'&&!state[i-1][j]){
			state[i-1][j]=true;
			q.add(new int[]{i-1,j});
		    }
		    if(j-1>=0&&grid[i][j-1]=='1'&&!state[i][j-1]){
			state[i][j-1]=true;
			q.add(new int[]{i,j-1});
		    }
		}
	}

}
