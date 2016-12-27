import java.io.IOException;
import java.io.FileNotFoundException;
import java.io.File;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class WeightedMedian {
  public static void main(String[] args) throws FileNotFoundException {
    Scanner scanner = new Scanner(new File("median.txt"));
    int n = scanner.nextInt();
    ArrayList<Element> elements = new ArrayList<Element>();
    ArrayList<Integer> values = new ArrayList<Integer>();
    ArrayList<Double> weights = new ArrayList<Double>();

    for (int i = 1; i <= n; i++) {
      values.add(scanner.nextInt()); // read value
    }

    for(int i = 1; i <= n; i++) {
      weights.add(scanner.nextDouble()); // read weight
    }

    for(int i = 0; i < n; i++) {
      elements.add(new Element(values.get(i), weights.get(i)));
    }

    boolean found = false;
    int left = -1;
    int right = elements.size() + 1;
    while (!found) {
      int mid = (left + right) / 2;

      double lowSum = getLowerWeightSum(elements.get(mid), elements);
      double upperSum = getUpperWeightSum(elements.get(mid), elements);

      if(lowSum < 0.5d && upperSum <= 0.5d) {
        System.out.println(elements.get(mid).getValue());
        found = true;
      }

      if (lowSum >= 0.5d) {
        right = mid;
      } else {
        left = mid;
      }
    }
  }

  private static double getLowerWeightSum(Element e, ArrayList<Element> elements) {
    double sum = 0;
    for (Element element : elements) {
      if (e.getValue() != element.getValue()) {
        if (element.getWeight() < e.getWeight()) {
          sum += element.getWeight();
        }
      }
    }

    return sum;
  }

  private static double getUpperWeightSum(Element e, ArrayList<Element> elements) {
    double sum = 0;
    for (Element element : elements) {
      if (e.getValue() != element.getValue()) {
        if (element.getWeight() >= e.getWeight()) {
          sum += element.getWeight();
        }
      }
    }

    return sum;
  }

}
