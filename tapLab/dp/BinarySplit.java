import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class BinarySplit {
    public static void main(String[] args) throws FileNotFoundException {
      Scanner scanner = new Scanner(new File("date.in"));
      Scanner binaryScanner = new Scanner(new File("cod.in"));

      int m = scanner.nextInt();
      String binarySequence = binaryScanner.next();
      int n = binarySequence.length();
      String[] sequences = new String[m + 5];
      //Read binary sequences
      for(int i = 0; i < m; i++){
      	sequences[i] = scanner.next();
      }
      //Set 0 and 1 default sequences
      sequences[m] = "0";
      sequences[m + 1] = "1";
      m += 2;

      //Initialize structure for DP
      int[] dp = new int[n + 1];
      int[] forward = new int[binarySequence.length()];
      for(int i = 0; i < n; i++) {
      	dp[i] = n + 1;
        forward[i] = n;
      }
      dp[n] = 0;
      for(int i = n - 1; i >= 0; i--){
          String sequence = new String();
          for(int j = i; j < n; j++) {
            sequence += String.valueOf(binarySequence.charAt(j));
            boolean found = false;
            for(int k = 0; k < m; k++) {
                if(sequence.equals(sequences[k])) {
                  found = true;
                  break;
                }
            }
            if(found) {
              if((dp[i] > dp[j + 1] + 1))  {
                dp[i] = dp[j + 1] + 1;
                forward[i] = j + 1;
              }
            }
        }
      }
      //Print the splitted binary sequence
      int index = 0;
      while(index < binarySequence.length()) {
        if(index > 0) {
          System.out.print(" + ");
        }
        System.out.print(binarySequence.substring(index, forward[index]));
        index = forward[index];
      }
      System.out.print("\n");
    }
}
