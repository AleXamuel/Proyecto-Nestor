static Edge[] edges;
static int[] d;
static int n;
public static void bellmanFord() {
      Arrays.fill(d, Integer.MAX_VALUE);
      d[0] = 0;
      boolean hayCambios = true;
      while (hayCambios) {
          hayCambios = false;
          for (Edge e : edges) {
              if(d[e.u]<30000)
                  if(d[e.v]>d[e.u]+e.w){
                      d[e.v]=d[e.u]+e.w;
                      hayCambios = true;
                  }
          }
      }

  }
  private static class Edge implements Comparable<Edge> {
      int u;
      int v;
      int w;
      Edge(int uu,int vv, int ww) {
          u=uu;
          v = vv;
          w = ww;
      }
      public boolean equals(Object o) {
          if (o instanceof Edge)
              return (v==((Edge)o).v && w==((Edge)o).w);
          return false;
      }
      public int compareTo(Edge o) {
          if (w < o.w) return -1;
          if (w > o.w) return 1;
          if (v < o.v) return -1;
          if (v > o.v) return 1;
          return 0;
      }
  }
