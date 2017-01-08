import java.io.IOException;
import java.io.FileNotFoundException;
import java.io.File;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;

public class Cubes {
  public static void main(String[] args) throws FileNotFoundException {
    Scanner scanner = new Scanner(new File("cubes.txt"));
    int n = scanner.nextInt();
    int p = scanner.nextInt();

    ArrayList<Cube> cubes = new ArrayList<Cube>();

    int x, y;
    for(int i = 1; i <= n; i++) {
        x = scanner.nextInt();
        y = scanner.nextInt();

        Cube cube = new Cube(x, y, i);
        cubes.add(cube);
    }

    Collections.sort(cubes, new Comparator<Cube>(){
      public int compare(Cube x, Cube y) {
        if (x.getSize() > y.getSize())
          return 1;
        else if(x.getSize() < y.getSize())
          return -1;
        else return 0;
      }
    });

    int dp[] = new int[n];
    for(int i = 0; i < n; i++) {
      dp[i] = cubes.get(i).getSize();
    }

    for(int i = 0; i < n; i++) {
      int max = 0;
      for(int j = 0; j < i; j++) {
        if(cubes.get(i).getColor() != cubes.get(j).getColor() && cubes.get(i).getSize() > cubes.get(j).getSize()) {
          if(max < dp[j]) {
            max = dp[j];
          }
        }
      }

      dp[i] += max;
    }

    for(int i = 0; i < n; i++) {
      System.out.print(dp[i] + " ");
    }
    System.out.print("\n");
  }
}
