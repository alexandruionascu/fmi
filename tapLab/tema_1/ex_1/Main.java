import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.stream.Stream;

public class Main {
  public static void main(String[] args) {
    String fileName = "./doc1.txt";


		try (Stream<String> stream = Files.lines(Paths.get(fileName))) {

      //iterate through each line
			stream.forEach((string)->{
        //split words
        String[] words = string.split(" ");
        for(String s : words) {
          System.out.println(s);
        }
      });

		} catch (IOException e) {
			e.printStackTrace();
		}
  }
}
