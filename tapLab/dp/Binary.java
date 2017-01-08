import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.Stack;
import java.util.StringJoiner;

import java.io.File;
import java.io.IOException;

public class Binary {

    public static class Element{
        private int length;
        private int last;

        public Element(int length, int last) {
            this.length = length;
            this.last = last;
        }

        public int getLength() {
            return length;
        }

        public void setLength(int length) {
            this.length = length;
        }

        public int getLast() {
            return last;
        }

        public void setLast(int last) {
            this.last = last;
        }

        @Override
        public String toString() {
            return length + "-" + last;
        }
    }

    public static void main(String[] args) throws FileNotFoundException {
        try {
			Scanner scanner = new Scanner(new File("date.in"));
			Scanner scan = new Scanner(new File("cod.in"));

			int m = scanner.nextInt();
			String code = scan.next();

			String[] worlds = new String[m + 2];

			for(int i = 0; i < m; i++){
				worlds[i] = scanner.next();
			}
      worlds[m] = "0";
			worlds[m + 1] = "1";
      m += 2;
      int n  = code.length();
			int[] dp = new int[n + 1];
      int[] next = new int[code.length()];
			for(int i = 0; i < n; i++){
				dp[i] = n + 1;
        next[i] = n;
			}
      dp[n] = 0;
      for(int i = n - 1; i >= 0; i--){
          String word = new String();
          for(int j = i;j < n; j++)
          {
            word += code.substring(j,j + 1);
            boolean found = false;
            for(int k = 0; k < m; ++k)
            {
                if(word.equals(worlds[k]))
                {
                  found = true;
                  break;
                }
            }
            if(found == true && (dp[i] > dp[j + 1] + 1))  {
                dp[i] = dp[j + 1] + 1;
                next[i] = j + 1;
              }
            }
      }
      int i = 0;
      while(i < code.length())
      {
        if(i > 0)
          System.out.print("+");
        System.out.print(code.substring(i,next[i]));
        i = next[i];
      }
      System.out.print("\n");
    }
		catch(IOException ex) {
            ex.printStackTrace();
        }
    }
}
