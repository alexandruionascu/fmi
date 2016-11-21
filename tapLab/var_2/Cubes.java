import java.io.IOException;
import java.io.FileNotFoundException;
import java.io.File;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class Cubes {
  public static void main(String[] args) throws FileNotFoundException {
    Scanner scanner = new Scanner(new File("data.txt"));
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
        if (x.getSize() < y.getSize())
          return 1;
        else if(x.getSize() > y.getSize())
          return -1;
        else return 0;
      }
    });

    ArrayList<Cube> tower = new ArrayList<Cube>();
    tower.add(cubes.get(0));

    for(Cube cube : cubes) {
      if(tower.get(tower.size() - 1).getColor() != cube.getColor()) {
        tower.add(cube);
      }
    }

    int towerHeight = 0;
    for(Cube cube : tower) {
      towerHeight += cube.getSize();
    }

    System.out.println(towerHeight);

    for(Cube cube : tower) {
      System.out.print(cube.getIndex() + " ");
    }
    System.out.print("\n");
  }
}
