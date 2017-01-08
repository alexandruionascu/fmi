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
      @Override
      public int compare(Cube x, Cube y) {
        if (x.getSize() > y.getSize())
          return 1;
        if(x.getSize() < y.getSize())
          return -1;
        return 0;
      }
    });

    int dp[] = new int[n];
    int count[] = new int[n];
    int next[] = new int[n];

    for(int i = 0; i < n; i++) {
      dp[i] = cubes.get(i).getSize();
      count[i] = 1;
    }

    for(int i = n - 1; i >= 0; i--) {
      int max = 0;
      for(int j = i + 1; j < n; j++) {
        if(cubes.get(i).getColor() != cubes.get(j).getColor() && cubes.get(i).getSize() < cubes.get(j).getSize()) {
          if(max < dp[j]) {
            max = dp[j];
            count[i] += count[j];
            next[i] = j;
          } else if(max == dp[j]) {
            count[i] = count[j];
          }
        }
      }
      dp[i] += max;
    }

    int max = 0;
    int index = 0;
    for(int i = 0; i < n; i++) {
      if(dp[i] >= max) {
        max = dp[i];
        index = i;
      }
    }

    int maxCount = count[index];
    while(index != 0) {
      System.out.println(cubes.get(index).getSize() + " " + cubes.get(index).getColor());
      index = next[index];
    }
    System.out.println(maxCount);
  }
}
