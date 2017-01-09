import java.io.File;
import java.io.FileNotFoundException;
import java.sql.Array;
import java.util.Arrays;
import java.util.Scanner;
import java.io.IOException;

public class TaskScheduler {
    private static int[][] dp;
    private static Task[] tasks;

    public static void main(String[] args) throws FileNotFoundException {
			Scanner scanner = new Scanner(new File("tasks.txt"));
			int n = scanner.nextInt();
			tasks = new Task[n];
			int maxDeadline = 0;
			for(int  i =0 ;i < n; i++){
				int p = scanner.nextInt();
				int deadline = scanner.nextInt();
				int duration = scanner.nextInt();
				tasks[i] = new Task(p,deadline,duration, i + 1);

				if(maxDeadline < deadline){
					maxDeadline = deadline;
				}
			}
			Arrays.sort(tasks);

			dp = new int[ n + 1][ maxDeadline + 1];

			for(int i = 0; i <= maxDeadline; i++){
				dp[0][i] = 0;
			}
			for(int i = 1; i <= n; i++){
				for(int j = 0; j<= maxDeadline; j++){
					int time = Math.min(j, tasks[i - 1].getDeadline()) - tasks[i - 1].getDuration();
					if(time < 0) {
						dp[i][j] = dp[i - 1][j];
					}
					else{
						dp[i][j] = Math.max(dp[i - 1][j], tasks[i - 1].getProfit() + dp[i - 1][time]);
					}
				}
			}

			System.out.println(dp[n][maxDeadline]);
			traceBack(n,maxDeadline);
      System.out.print("\n");
    }

    static void traceBack(int i, int j){
        if(i == 0) {
            return;
        }
        if(dp[i][j] == dp[i - 1][j]){
            traceBack(i - 1, j);
        }
        else{
            int time = Math.min(j, tasks[i - 1].getDeadline()) - tasks[i - 1].getDuration();
            traceBack(i - 1, time);
            System.out.print(tasks[i -1 ].getIndex() + " ");
        }
    }
}
