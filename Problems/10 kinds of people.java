import java.util.*;
class Main{
    public static void main(String[] args){
        Scanner tec=new Scanner(System.in);
        int r= tec.nextInt();
        int c= tec.nextInt();
        char[][] mapa=new char[r][c];
        int [][] grupos=new int[r][c];
        tec.nextLine();
        for (int i =0;i<r;i++){
            String a= tec.nextLine();
            for (int j = 0; j < c; j++) {
                mapa[i][j]=a.charAt(j);
            }
        }
        int n= tec.nextInt();
        for (int i = 0; i < n; i++) {
            int x1= tec.nextInt()-1;
            int y1= tec.nextInt()-1;
            int x2= tec.nextInt()-1;
            int y2= tec.nextInt()-1;
            System.out.println(alcanza(x1,y1,x2,y2,i+1,mapa,grupos));
        }
    }

    static String alcanza(int x1, int y1, int x2, int y2, int g, char[][] mapas,int[][] grupos){
        LinkedList<int[]> actual=new LinkedList<>();
        actual.add(new int[]{x1,y1});
        char numero=mapas[x1][y1];
        if(grupos[x1][y1]==0){
            while(actual.size()>0){
                int[] par=actual.remove();
                int r=par[0];
                int c=par[1];
                grupos[r][c]=g;
                if(r>0&&numero==mapas[r-1][c]&&grupos[r-1][c]==0){
                    grupos[r-1][c]=g;
                    actual.add(new int[]{r-1,c});
                }
                if(c>0&&numero==mapas[r][c-1]&&grupos[r][c-1]==0){
                    grupos[r][c-1]=g;
                    actual.add(new int[]{r,c-1});
                }
                if (r<mapas.length-1&&numero==mapas[r+1][c]&&grupos[r+1][c]==0){
                    grupos[r+1][c]=g;
                    actual.add(new int[]{r+1,c});
                }
                if(c<mapas[0].length-1&&numero==mapas[r][c+1]&&grupos[r][c+1]==0){
                    grupos[r][c+1]=g;
                    actual.add(new int[]{r,c+1});
                }
            }
        }
        if(grupos[x1][y1]==grupos[x2][y2]) {
            if (mapas[x1][y1] == '0')
                return "binary";
            else
                return "decimal";
        }
        else
            return "neither";
    }

}
