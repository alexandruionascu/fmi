class Program {
  public static void main(String[] args) {
    Graph<Integer> graph = new Graph<Integer>();
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(2, 5);
    graph.printElements();
  }
}
