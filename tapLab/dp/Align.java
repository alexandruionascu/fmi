import java.util.HashMap;
import java.util.Scanner;
import java.util.Stack;

import java.io.File;
import java.io.IOException;


/**
 * Created by Narcis on 05.01.2017.
 */
public class Align {
    public enum turn {
      right,
      down,
      both
    }
    public static void main(String[] args){
		try {
			Scanner scanner = new Scanner(new File("date.in"));
			HashMap<String, Integer> hmap = new HashMap<String, Integer>();

			String wordOne = scanner.next();
			String wordTwo = scanner.next();
			int space = scanner.nextInt();
			int n = scanner.nextInt();
			for(int i = 0; i < n; i++){
				String rule = scanner.next();
				int score = scanner.nextInt();
				hmap.put(rule, score);
        rule = new StringBuffer(rule).reverse().toString();
        hmap.put(rule, score);
			}
      int score = scanner.nextInt();

      int[][] matrix = new int[wordOne.length() + 1][wordTwo.length() + 1];
			turn[][] next = new turn[wordOne.length()][wordTwo.length()];

			for(int i = 0; i <= wordOne.length(); i++) {
				matrix[i][wordTwo.length()] = (wordOne.length() - i) * space;
			}
			for(int i = 0; i <= wordTwo.length(); i++) {
				matrix[wordOne.length()][i] = (wordTwo.length() - i) * space;
			}

			for(int i = wordOne.length() - 1; i >= 0 ; i--) {
				for(int j = wordTwo.length() - 1; j >= 0; j--) {
              String rule = "";
    					int points = 0;
    					rule = "" + wordTwo.charAt(j) + wordOne.charAt(i);
              if(hmap.get(rule) != null)
              {
                points = hmap.get(rule);
              }
              else
                points = score;

              if(wordTwo.charAt(j) == wordOne.charAt(i))
                points = 0;

              next[i][j] = turn.both;
              matrix[i][j] = matrix[i + 1][j + 1] + points;

              if(matrix[i][j] > matrix[i + 1][j] + space) {
                matrix[i][j] = matrix[i + 1][j] + space;
                next[i][j] = turn.down;
              }

              if(matrix[i][j] > matrix[i][j + 1] + space) {
                matrix[i][j] = matrix[i][j + 1] + space;
                next[i][j] = turn.right;
              }
				}
			}
      System.out.println(matrix[0][0]);
			String stringOne = "";
			String stringTwo = "";
			int i = 0;
			int j = 0;
      while(i < wordOne.length() || j < wordTwo.length()) {
          if(j == wordTwo.length() || next[i][j] == turn.down)
          {
            stringOne += wordOne.substring(i,i + 1);
            stringTwo += "-";
            i += 1;
          }
          else
            if(i == wordOne.length() || next[i][j] == turn.right)
            {
              stringOne += "-";
              stringTwo += wordTwo.substring(j,j + 1);
              j += 1;
            }
            else
            {
              stringOne += wordOne.substring(i,i + 1);
              stringTwo += wordTwo.substring(j,j + 1);
              i += 1;
              j += 1;
            }
      }
      System.out.println(stringOne);
      System.out.println(stringTwo);
		}
		catch(IOException ex) {
            ex.printStackTrace();
        }
    }
}
