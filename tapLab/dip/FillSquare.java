import java.io.IOException;
import java.io.FileNotFoundException;
import java.io.File;
import java.util.Scanner;
import java.util.Collections;
import java.util.Comparator;

public class FillSquare {
  static int n;
  static int x, y;
  static Point gap;
  static int[][] square;
  static int count = 0;

  public static void main(String[] args) throws FileNotFoundException {
    Scanner scanner = new Scanner(new File("square.txt"));
    n = scanner.nextInt();
    x = scanner.nextInt();
    y = scanner.nextInt();
    gap = new Point(x, y);
    int length = (int)Math.pow(2, n);
    square = new int[length + 5][length + 5];
    solve(new Point(1, 1), length, gap);

    for(int i = 1; i <= length; i++) {
      for(int j = 1; j <= length; j++) {
        System.out.print(square[i][j] + " ");
      }
      System.out.print("\n");
    }
  }

  public static void solve(Point start, int length, Point gap) {
    count++;
    if(length == 1) {
      count--;
      return;
    }
    int midX = start.getX() + (length / 2) - 1;
    int midY = start.getY() + (length / 2) - 1;
    Point upLeft = new Point(midX, midY);
    Point upRight = new Point(midX, midY + 1);
    Point downLeft = new Point(midX + 1, midY);
    Point downRight = new Point(midX + 1, midY + 1);
    int toMark = count;

    if(gap.getX() <= upLeft.getX() && gap.getY() <= upLeft.getY()) {
      solve(start, length / 2, gap);
    } else {
      square[upLeft.getX()][upLeft.getY()] = toMark;
      solve(start, length / 2, upLeft);
    }

    if(gap.getX() <= upRight.getX() && gap.getY() >= upRight.getY()) {
      solve(new Point(start.getX(), start.getY() + (length / 2)), length / 2, gap);
    } else {
      square[upRight.getX()][upRight.getY()] = toMark;
      solve(new Point(start.getX(), start.getY() + (length / 2)), length / 2, upRight);
    }

    if(gap.getX() >= downLeft.getX() && gap.getY() <= downLeft.getY()) {
      solve(new Point(start.getX() + length / 2, start.getY()), length / 2, gap);
    } else {
      square[downLeft.getX()][downLeft.getY()] = toMark;
      solve(new Point(start.getX() + length / 2, start.getY()), length / 2, downLeft);
    }

    if(gap.getX() >= downRight.getX() && gap.getY() >= downRight.getY()) {
      solve(new Point(start.getX() + length / 2, start.getY() + length / 2), length / 2, gap);
    } else {
      square[downRight.getX()][downRight.getY()] = toMark;
      solve(new Point(start.getX() + length / 2, start.getY() + length / 2), length / 2, downRight);
    }
  }


}
