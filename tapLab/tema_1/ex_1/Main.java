import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.stream.Stream;
import java.util.HashMap;

public class Main {
  public static void main(String[] args) {
    double cosinusDistance = getCosinusDistance("./doc1.txt", "./doc2.txt");
    System.out.println("The word distance is " + cosinusDistance);
  }

  public static HashMap<String, Integer> getWordsFrequencies(String fileName) {
    HashMap<String, Integer> retValue = new HashMap<String, Integer>();
    try(Stream<String> stream = Files.lines(Paths.get(fileName))) {
      stream.forEach((string) -> {
          String[] words = string.split(" ");

          for(String str : words) {
            if(retValue.containsKey(str)) {
              int count = retValue.get(str);
              retValue.put(str, count + 1);
            } else {
              retValue.put(str, 1);
            }
          }
      });

    } catch(IOException e) {
      e.printStackTrace();
    }

    return retValue;
  }

  public static double getCosinusDistance(String firstFile, String secondFile) {
    HashMap<String, Integer> doc1 = getWordsFrequencies(firstFile);
    HashMap<String, Integer> doc2 = getWordsFrequencies(secondFile);

    double numerator = 0;
    for(String key : doc1.keySet()) {
      double count1 = doc1.get(key);
      double count2 = 0;
      if(doc2.containsKey(key))
        count2 = doc2.get(key);
      numerator += (count1 * count2);
    }

    double sum1 = 0;
    double sum2 = 0;

    for(Integer freq : doc1.values()) {
      sum1 += (freq * freq);
    }

    sum1 = Math.sqrt(sum1);

    for(Integer freq : doc2.values()) {
      sum2 += (freq * freq);
    }

    sum2 = Math.sqrt(sum2);

    return numerator / (sum1 * sum2);
  }

}
