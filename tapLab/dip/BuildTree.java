import java.io.IOException;
import java.io.FileNotFoundException;
import java.io.File;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class BuildTree {

  static String[] values;
  static int index = 0;
  static ArrayList<Node> nodes = new ArrayList<Node>();

  public static void main(String[] args) throws FileNotFoundException {
    Scanner scanner = new Scanner(new File("tree.txt"));
    String line = scanner.nextLine();
    values = line.split(" ");

    for(String value : values) {
      nodes.add(new Node(value));
    }
    int rootIndex = 0;
    buildTree(-1, 0);
    System.out.println("IS BST: " + isBST(nodes.get(0)));
  }

  private static String nextValue() {
    String toReturn = values[index];
    index++;
    return toReturn;
  }

  private static void buildTree(int parentIndex, int direction) {
    if (parentIndex == -1) {
      if(!nodes.get(index).getValue().equals("null")) {
        int parent = index;
        buildTree(parent, -1);
        buildTree(parent, 1);
      }
    } else {
      index++;

      if(direction == -1) {
        nodes.get(parentIndex).setLeft(nodes.get(index));
        if(!nodes.get(index).getValue().equals("null")) {
          int parent = index;
          buildTree(parent, -1);
          buildTree(parent, 1);
        }
      }

      if(direction == 1) {
        nodes.get(parentIndex).setRight(nodes.get(index));
        if(!nodes.get(index).getValue().equals("null")) {
          int parent = index;
          buildTree(parent, -1);
          buildTree(parent, 1);
        }
      }
    }
  }

  private static void printTree(Node node) {
    if(node == null || node.getValue().equals("null"))
      return;
    System.out.println(node.getValue());
    printTree(node.left);
    printTree(node.right);
  }

  private static boolean isBST(Node node) {
    if(node.getValue().equals("null"))
      return true;
    if(!node.getLeft().getValue().equals("null")) {
      int rootValue = Integer.parseInt(node.getValue());
      int leftValue = Integer.parseInt(node.getLeft().getValue());

      if(leftValue > rootValue)
        return false;
    }

    if(!node.getRight().getValue().equals("null")) {
      int rootValue = Integer.parseInt(node.getValue());
      int rightValue = Integer.parseInt(node.getRight().getValue());

      if(rightValue < rootValue)
        return false;
    }
    return isBST(node.getLeft()) && isBST(node.getRight());
  }
}
