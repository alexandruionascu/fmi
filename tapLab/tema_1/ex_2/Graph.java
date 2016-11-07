import java.util.ArrayDeque;
import java.util.HashMap;
import java.util.HashSet;

class Graph<T> {
  private HashMap<T, ArrayDeque<T>> graph = new HashMap<T, ArrayDeque<T>>();

  public void addEdge(T a, T b) {
    append(a, b);
    append(b, a);
  }

  private void append(T a, T b) {
    ArrayDeque<T> adjacentVerticies;
    if(graph.containsKey(a) == false)
      adjacentVerticies = new ArrayDeque<T>();
    else
      adjacentVerticies = graph.get(a);

    adjacentVerticies.push(b);
    graph.put(a, adjacentVerticies);
  }

  public void printElements() {
    if(graph.size() == 0)
      return;

    ArrayDeque<T> queue = new ArrayDeque<T>();
    HashSet<T> visited = new HashSet<T>();
    T source = graph.entrySet().iterator().next().getKey();
    queue.push(source);
    visited.add(source);

    while(queue.isEmpty() == false) {
      T vertex = queue.peekFirst();
      System.out.println("Current node " + vertex);

      for(T adjacentVertex : graph.get(vertex)) {
        if(visited.contains(adjacentVertex) == false) {
          queue.addLast(adjacentVertex);
          visited.add(adjacentVertex);
        }
      }

      queue.pop();
    }
  }
}
