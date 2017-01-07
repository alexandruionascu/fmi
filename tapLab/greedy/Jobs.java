import java.io.IOException;
import java.io.FileNotFoundException;
import java.io.File;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.TreeSet;
import java.util.Set;
import java.util.Collections;
import java.util.Comparator;

public class Jobs {
  public static void main(String[] args) throws FileNotFoundException {
    Scanner scanner = new Scanner(new File("jobs.txt"));
    int n = scanner.nextInt();
    ArrayList<Job> jobs = new ArrayList<Job>();

    int x, y;
    for (int i = 1; i <= n; i++) {
        x = scanner.nextInt(); // read profit
        y = scanner.nextInt(); // read deadline
        Job job = new Job(i, x, y);
        jobs.add(job);
    }

    Collections.sort(jobs, new Comparator<Job>() {
      public int compare(Job x, Job y) {
        if (x.getProfit() < y.getProfit()) {
          return 1;
        } else if (x.getProfit() == y.getProfit()) {
          return -1;
        } else {
          return -1;
        }
      }
    });

    int total = 0;
    ArrayList<Job> jobSet = new ArrayList<Job>();
    for (Job job : jobs) {
      int count =  (int)jobSet.stream()
        .filter(e -> e.getDeadline() <= job.getDeadline()).count();
      if (count < job.getDeadline()) {
        total += job.getProfit();
        jobSet.add(job);
      }
    }

    System.out.println(total);
    for(Job job : jobSet) {
      System.out.print(job.getId() + " ");
    }
    System.out.print("\n");
  }
}
