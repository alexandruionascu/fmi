import java.util.HashMap;
import java.util.Scanner;
import java.util.Stack;

import java.io.File;
import java.io.FileNotFoundException;
 

public class AlignDna {
    public static void main(String[] args) throws FileNotFoundException {
      Scanner scanner = new Scanner(new File("dna.txt"));
      HashMap<String, Integer> hashMap = new HashMap<String, Integer>();

			String firstSequence = scanner.next();
			String secondSequence = scanner.next();
			int space = scanner.nextInt();
			int n = scanner.nextInt();
			for(int i = 0; i < n; i++){
				String rule = scanner.next();
				int penalty = scanner.nextInt();
				hashMap.put(rule, penalty);
        rule = new StringBuffer(rule).reverse().toString();
        hashMap.put(rule, penalty);
			}
      int penalty = scanner.nextInt();

      int[][] M = new int[firstSequence.length() + 1][secondSequence.length() + 1];
			String[][] next = new String[firstSequence.length()][secondSequence.length()];

			for(int i = 0; i <= firstSequence.length(); i++) {
				M[i][secondSequence.length()] = (firstSequence.length() - i) * space;
			}
			for(int i = 0; i <= secondSequence.length(); i++) {
				M[firstSequence.length()][i] = (secondSequence.length() - i) * space;
			}

      for(int i = firstSequence.length() - 1; i >= 0 ; i--) {
        for(int j = secondSequence.length() - 1; j >= 0; j--) {
          String rule = "";
          int currentPenalty = 0;
          rule = "" + secondSequence.charAt(j) + firstSequence.charAt(i);
          if(hashMap.get(rule) != null) {
            currentPenalty = hashMap.get(rule);
          } else {
            currentPenalty = penalty;
          }
          if(secondSequence.charAt(j) == firstSequence.charAt(i)) {
            currentPenalty = 0;
          }
          next[i][j] = "both";
          M[i][j] = M[i + 1][j + 1] + currentPenalty;

          if(M[i][j] > M[i + 1][j] + space) {
            M[i][j] = M[i + 1][j] + space;
            next[i][j] = "down";
          }

          if(M[i][j] > M[i][j + 1] + space) {
            M[i][j] = M[i][j + 1] + space;
            next[i][j] = "right";
          }
				}
			}
      System.out.println(M[0][0]);
			String firstString = "";
			String secondString = "";
			int i = 0;
			int j = 0;
      while(i < firstSequence.length() || j < secondSequence.length()) {
          if(j == secondSequence.length() || next[i][j] == "down") {
            firstString += firstSequence.substring(i,i + 1);
            secondString += "-";
            i += 1;
          }
          else {
            if(i == firstSequence.length() || next[i][j] == "right") {
              firstString += "-";
              secondString += secondSequence.substring(j,j + 1);
              j += 1;
            } else {
              firstString += firstSequence.substring(i, i + 1);
              secondString += secondSequence.substring(j,j + 1);
              i += 1;
              j += 1;
            }
          }
      }
      System.out.println(firstString);
      System.out.println(secondString);
    }
}
