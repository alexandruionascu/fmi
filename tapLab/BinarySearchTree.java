public class BinarySearchTree<KeyType extends Comparable<KeyType>, ValueType> {

    private Node<KeyType, ValueType> root;

    public BinarySearchTree() {
        System.out.println("BST Constructor");
        root = null;
    }

    public void insert(KeyType key, ValueType value) {
      if(root == null)
        root = new Node(key, value);
      else
        insert(root, key, value);
    }

    private void insert(Node<KeyType, ValueType> rootNode, KeyType key, ValueType value) {
      if(rootNode.getKey().compareTo(key) >= 0 ) {
        if(rootNode.left == null)
          rootNode.left = new Node(key, value);
        else
          insert(rootNode.left, key, value);
      } else {
        if(rootNode.right == null)
          rootNode.right = new Node(key, value);
        else
          insert(rootNode.right, key, value);
      }
    }


    public void printTree() {
      printTree(root);
      System.out.print("\n");
    }

    private void printTree(Node<KeyType, ValueType> rootNode) {
      if(rootNode != null) {
        printTree(rootNode.getLeft());
        System.out.print(rootNode.getKey() + " " + rootNode.getValue() + " -> ");
        printTree(rootNode.getRight());
      }
    }

    public int compareTo(BinarySearchTree<KeyType, ValueType> node) {
        return 0;
    }

    private class Node<KeyType, ValueType> {
      private KeyType key;
      private ValueType value;
      private Node<KeyType, ValueType> left;
      private Node<KeyType, ValueType> right;

      public Node(KeyType key, ValueType value) {
        this.key = key;
        this.value = value;
        left = null;
        right = null;
      }

      public KeyType getKey() {
        return key;
      }

      public ValueType getValue() {
        return value;
      }

      public Node<KeyType, ValueType> getLeft() {
        return left;
      }

      public Node<KeyType, ValueType> getRight() {
        return right;
      }

    }
}
