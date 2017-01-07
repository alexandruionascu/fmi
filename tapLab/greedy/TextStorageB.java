import java.util.Collections;
import java.util.ArrayList;
import java.util.Scanner;
import java.io.FileNotFoundException;
import java.io.File;
import java.io.IOException;

public class TextStorageB {

  public static void main(String[] args) throws FileNotFoundException {

    Scanner scanner = new Scanner(new File("texts.txt"));
    int n = scanner.nextInt();
    int p = scanner.nextInt();

    ArrayList<TextB> texts = new ArrayList<TextB>();
    int length;
    int frequency;

    for(int i = 1; i <= n; i++) {
      length = scanner.nextInt();
      texts.add(new TextB(length, i));
    }

    Collections.sort(texts);

    int count = 0;
    int index = 0;
     while(count < n){
       for(int i = index; i < n; i = i + p){
         System.out.print(texts.get(i).getIndex() + " ");
         count++;
       }
       index++;
       System.out.print("\n");
     }

      System.out.print("\n");
    }
}
