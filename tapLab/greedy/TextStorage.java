import java.util.Collections;
import java.util.ArrayList;
import java.util.Scanner;
import java.io.FileNotFoundException;
import java.io.File;
import java.io.IOException;

public class TextStorage {

  public static void main(String[] args) throws FileNotFoundException {

    Scanner scanner = new Scanner(new File("texts.txt"));
    int n = scanner.nextInt();

    ArrayList<Text> texts = new ArrayList<Text>();
    int length;
    int frequency;

    for(int i = 1; i <= n; i++) {
      length = scanner.nextInt();
      frequency = scanner.nextInt();
      texts.add(new Text(length, frequency, i));
    }

    Collections.sort(texts);

    for(Text text : texts) {
      System.out.print(text.getIndex() + " ");
    }

    System.out.print("\n");
  }
}
