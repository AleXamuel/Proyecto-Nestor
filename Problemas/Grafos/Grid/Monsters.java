/*https://vjudge.net/problem/CSES-1194*/
import java.util.*;
import java.io.*;


public class MonstersIan {
	static char[][] grid;

	static int[][] dA, dM;
	static boolean[][] stateA, stateM;
	static Queue<int[]> Q;

	static int[][][] pi;

	static int n, m;

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(in.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		grid = new char[n][m];
		dM = new int[n][m];
		dA = new int[n][m];
		stateA = new boolean[n][m];
		stateM = new boolean[n][m];
		for (int i = 0; i < n; i++)
			grid[i] = in.readLine().toCharArray();
		for (int[] is : dA)
			Arrays.fill(is, Integer.MAX_VALUE);
		for (int[] is : dM)
			Arrays.fill(is, Integer.MAX_VALUE);
		int[] me = new int[2];
		List<int[]> salidas = new ArrayList<>();
		Q = new LinkedList<>();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 'M') {
					Q.add(new int[] { i, j });
					dM[i][j] = 0;
					stateM[i][j] = true;
				}
				if (grid[i][j] == 'A') {
					me[0] = i;
					me[1] = j;
				}
				if (grid[i][j] == '.' && (i == 0 || i == n - 1 || j == 0 || j == m - 1))
					salidas.add(new int[] { i, j });
			}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (grid[i][j] == 'A' && (i == 0 || i == n - 1 || j == 0 || j == m - 1)) {
					System.out.println("YES");
					System.out.println(0);
					return;
				}
		if (salidas.isEmpty()) {
			System.out.println("NO");
			return;
		}
		bfsM();
		bfsA(me[0], me[1]);
		boolean cond = false;
		for (int[] i : salidas) {
			int r = i[0];
			int c = i[1];
			if (dA[r][c] < dM[r][c]) {
				System.out.println("YES");
				System.out.println(dA[r][c]);
				cond = true;
				List<int[]> path = buildPath(r, c);
				path.remove(0);
				System.out.println(printPath(path, me[0], me[1]));
				break;
			}
		}
		if (!cond) {
			System.out.println("NO");
		}

	}

	static String printPath(List<int[]> path, int si, int sj) {
		StringBuffer buf = new StringBuffer();
		for (int[] i : path) {
			int r = i[0];
			int c = i[1];
			if (r == si)
				buf.append(c > sj ? "R" : "L");
			else if (c == sj)
				buf.append(r < si ? "U" : "D");
			else
				buf.append(r > si ? "D" : "U");
			si = r;
			sj = c;
		}
		return new String(buf);

	}

	static List<int[]> buildPath(int ti, int tj) {
		List<int[]> path = new LinkedList<>();
		path.add(new int[] { ti, tj });
		while (ti != -1 && tj != -1) {
			int aux = ti;
			ti = pi[ti][tj][0];
			tj = pi[aux][tj][1];
			path.add(0, new int[] { ti, tj });
		}
		path.remove(0);
		return path;
	}

	static void bfsA(int i, int j) {
		pi = new int[n][m][2];
		for (int[][] u : pi)
			for (int[] v : u)
				Arrays.fill(v, -1);
		Q = new LinkedList<>();
		dA[i][j] = 0;
		stateA[i][j] = true;
		Q.add(new int[] { i, j });
		while (!Q.isEmpty()) {
			int[] e = Q.poll();
			int r = e[0];
			int c = e[1];
			if (r - 1 >= 0 && !stateA[r - 1][c] && grid[r - 1][c] == '.') {
				stateA[r - 1][c] = true;
				dA[r - 1][c] = dA[r][c] + 1;
				pi[r - 1][c] = new int[] { r, c };
				Q.add(new int[] { r - 1, c });
			}
			if (r + 1 < n && !stateA[r + 1][c] && grid[r + 1][c] == '.') {
				stateA[r + 1][c] = true;
				dA[r + 1][c] = dA[r][c] + 1;
				pi[r + 1][c] = new int[] { r, c };
				Q.add(new int[] { r + 1, c });
			}
			if (c - 1 >= 0 && !stateA[r][c - 1] && grid[r][c - 1] == '.') {
				stateA[r][c - 1] = true;
				dA[r][c - 1] = dA[r][c] + 1;
				pi[r][c - 1] = new int[] { r, c };
				Q.add(new int[] { r, c - 1 });
			}
			if (c + 1 < m && !stateA[r][c + 1] && grid[r][c + 1] == '.') {
				stateA[r][c + 1] = true;
				dA[r][c + 1] = dA[r][c] + 1;
				pi[r][c + 1] = new int[] { r, c };
				Q.add(new int[] { r, c + 1 });
			}
		}
	}

	static void bfsM() {
		while (!Q.isEmpty()) {
			int[] e = Q.poll();
			int r = e[0];
			int c = e[1];
			if (r - 1 >= 0 && !stateM[r - 1][c] && grid[r - 1][c] != '#') {
				stateM[r - 1][c] = true;
				dM[r - 1][c] = dM[r][c] + 1;
				Q.add(new int[] { r - 1, c });
			}
			if (r + 1 < n && !stateM[r + 1][c] && grid[r + 1][c] != '#') {
				stateM[r + 1][c] = true;
				dM[r + 1][c] = dM[r][c] + 1;
				Q.add(new int[] { r + 1, c });
			}
			if (c - 1 >= 0 && !stateM[r][c - 1] && grid[r][c - 1] != '#') {
				stateM[r][c - 1] = true;
				dM[r][c - 1] = dM[r][c] + 1;
				Q.add(new int[] { r, c - 1 });
			}
			if (c + 1 < m && !stateM[r][c + 1] && grid[r][c + 1] != '#') {
				stateM[r][c + 1] = true;
				dM[r][c + 1] = dM[r][c] + 1;
				Q.add(new int[] { r, c + 1 });
			}
		}
	}

	static String print(int[][] A) {
		StringBuffer buf = new StringBuffer();
		for (int[] i : A)
			buf.append("[" + i[0] + ", " + i[1] + "]" + ", ");
		return new String(buf);
	}

}


public class MonstersSamu {

    static int[][] d;
    static int[][] da;
    static int n;
    static int m;

    static ArrayList<int[]> inicios=new ArrayList<>();
    static ArrayList<int[]> mon=new ArrayList<>();
    static char[][] map;
    static char[][]pi;

    public static void main(String[] args) throws IOException {
        BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
        String[] l1=bf.readLine().split(" ");
        n=Integer.parseInt(l1[0]);
        m=Integer.parseInt(l1[1]);
        map=new char[n][m];
        d=new int[n][m];
        da=new int[n][m];
        pi=new char[n][m];
        int[] ini=new int[2];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char a= (char) bf.read();
                map[i][j]=a;
                if((i==0||i==n-1||j==0||j==m-1)&&(a!='#'&&a!='M'))
                    inicios.add(new int[]{i,j});
                if(a=='M')
                    mon.add(new int[]{i,j});
                if(a=='A')
                    ini=new int[]{i,j};

            }
            bf.readLine();
        }
        bfs();
        bfs2(ini);
        //System.out.println(Arrays.deepToString(pi));
        for (int[] x: inicios){
            int i=x[0];
            int j=x[1];
            if(da[i][j]<d[i][j]){
                System.out.println("YES");
                System.out.println(da[i][j]);
                char[] res=new char[da[i][j]];
                int index=da[i][j]-1;
                while (index>=0){
                    char c=pi[i][j];
                    res[index]=c;
                    index--;
                    //System.out.println(c);
                    if(c=='+')
                        break;
                    if(c=='D')
                        i--;
                    else if(c=='R')
                        j--;
                    else if(c=='U')
                        i++;
                    else if(c=='L')
                        j++;
                }
                System.out.println(new String(res));
                return;
            }
        }
        System.out.println("NO");
    }

    static void bfs() {
        boolean[][] state=new boolean[n][m];
        for (int i = 0; i < map.length; i++) {
            for (int j = 0; j < map[0].length; j++) {
                d[i][j]= Integer.MAX_VALUE;
            }
        }
        Queue<int[]> q=new LinkedList<>();
        for(int[] i: mon){
            int x=i[0];
            int y=i[1];
            d[x][y]=0;
            state[x][y]=true;
            q.add(i);
        }
        while (!q.isEmpty()){
            int[] a=q.poll();
            int i=a[0];
            int j=a[1];
            if(i+1<n&&map[i+1][j]!='#'&&!state[i+1][j]) {
                q.add(new int[]{i + 1, j});
                d[i + 1][j] = d[i][j] + 1;
                state[i+1][j]=true;
            }
            if(i-1>=0&&map[i-1][j]!='#'&&!state[i-1][j]) {
                q.add(new int[]{i - 1, j});
                d[i - 1][j] = d[i][j] + 1;
                state[i-1][j]=true;
            }
            if(j+1<m&&map[i][j+1]!='#'&&!state[i][j+1]) {
                q.add(new int[]{i , j+1});
                d[i][j+1] =d[i][j] + 1;
                state[i][j+1]=true;
            }
            if(j-1>=0&&map[i][j-1]!='#'&&!state[i][j-1]) {
                q.add(new int[]{i , j-1});
                d[i][j-1] =  d[i][j] + 1;
                state[i][j-1]=true;
            }
        }
    }
    
    static void bfs2(int[] ini) {
        boolean[][] state=new boolean[n][m];
        for (int i = 0; i < map.length; i++) {
            for (int j = 0; j < map[0].length; j++) {
                da[i][j]=Integer.MAX_VALUE;
            }
        }
        Queue<int[]> q=new LinkedList<>();
        int x=ini[0];
        int y=ini[1];
        pi[x][y]='+';
        q.add(ini);
        da[x][y]=0;
        state[x][y]=true;
        while (!q.isEmpty()){
            int[] a=q.poll();
            int i=a[0];
            int j=a[1];
            if(i+1<n&&map[i+1][j]!='#'&&!state[i+1][j]) {
                q.add(new int[]{i + 1, j});
                da[i + 1][j] = da[i][j] + 1;
                state[i+1][j]=true;
                pi[i+1][j]='D';
            }
            if(i-1>=0&&map[i-1][j]!='#'&&!state[i-1][j]) {
                q.add(new int[]{i - 1, j});
                da[i - 1][j] = da[i][j] + 1;
                state[i-1][j]=true;
                pi[i-1][j]='U';
            }
            if(j+1<m&&map[i][j+1]!='#'&&!state[i][j+1]) {
                q.add(new int[]{i , j+1});
                da[i][j+1] =da[i][j] + 1;
                state[i][j+1]=true;
                pi[i][j+1]='R';
            }
            if(j-1>=0&&map[i][j-1]!='#'&&!state[i][j-1]) {
                q.add(new int[]{i , j-1});
                da[i][j-1] =  da[i][j] + 1;
                state[i][j-1]=true;
                pi[i][j-1]='L';
            }
        }
    }
}
