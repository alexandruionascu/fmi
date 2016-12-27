import java.io.IOException;
import java.io.FileNotFoundException;
import java.io.File;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class Chess {
  public static void main(String[] args) throws FileNotFoundException {
    Scanner scanner = new Scanner(new File("chess.txt"));
    int n = scanner.nextInt();
    int m = scanner.nextInt();
    int[][] chessBoard = new int[n + 2][m + 2];

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        chessBoard[i][j] = scanner.nextInt();
      }
    }

    for (int i = n; i >= 1; i--) {
      for (int j = 1; j <= m; j++) {
        chessBoard[i][j] += max(chessBoard[i][j - 1], chessBoard[i + 1][j]);
      }
    }

    System.out.println(chessBoard[1][m]);

    int length = m + n - 1;

    int x = 1;
    int y = m;

    int[] pathX = new int[length];
    int[] pathY = new int[length];

    for (int i = 0; i < length; i++) {
      pathX[i] = x;
      pathY[i] = y;
      if (chessBoard[x + 1][y] > chessBoard[x][y - 1]) {
        x++;
      } else {
        y--;
      }
    }

    for (int i = length - 1; i >= 0; i--) {
      System.out.println(pathX[i] + " " + pathY[i]);
    }
  }

  public static int max(int a, int b) {
    if(a >= b) {
      return a;
    } else {
      return b;
    }
  }
}
