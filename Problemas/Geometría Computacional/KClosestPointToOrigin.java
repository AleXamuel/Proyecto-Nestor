//leetocde 973
import java.awt.*;
class Solution {
    public int[][] kClosest(int[][] points, int k) {
        int n = points.length;
        Point[] puntos = new Point[n];
        for(int i = 0;i<n;i++)
            puntos[i] = new Point(points[i][0],points[i][1]);
        Arrays.sort(puntos,(p1,p2)->{
            if(p1.distance(new Point(0,0))<p2.distance(new Point(0,0)))
                return -1;
            return 1;
        });
        int[][] res = new int[k][2];
        for(int i = 0;i<k;i++){
            res[i][0] = puntos[i].x;
            res[i][1] = puntos[i].y;
        }
        return res;
    }
}
