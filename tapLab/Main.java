public class Main {
  public static void main(String[] args) {
    BinarySearchTree tree = new BinarySearchTree<Integer, String>();
    tree.insert(new Integer(10), new String("BOSS"));
    tree.insert(new Integer(20), new String("LOL"));
    tree.insert(new Integer(15), new String("NELSON"));
    tree.printTree();
  }
}
