package Java;

public class Matrices {

    public static void main(String[] args) {
        
        int x[][] = { {1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
        int y[][] = { {4, 4, 4}, {4, 4, 4}, {4, 4, 4}};

        int z[][] = new int[3][3];

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                z[i][j] = x[i][j] + y[i][j];

                System.out.println(z[i][j] + " ");
            }
            System.out.println();
        }
    }
}