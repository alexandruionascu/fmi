class Node {
  Node left;
  Node right;
  String value;

  public Node(String value) {
    this.value = value;
  }

  public Node getLeft() {
    return left;
  }

  public Node getRight() {
    return right;
  }

  public void setLeft(Node node) {
    left = node;
  }

  public void setRight(Node node) {
    right = node;
  }

  public String getValue() {
    return value;
  }

  public void setValue(String value) {
    this.value = value;
  }
}
