import java.util.*;

public class bestfsh {
    // Node class representing a graph node with heuristic values
    static class Node {
        char vertex;
        int heuristic;

        Node(char vertex, int heuristic) {
            this.vertex = vertex;
            this.heuristic = heuristic;
        }
    }

    // PathNode class to store the path from source to destination
    static class PathNode {
        char vertex;
        PathNode parent;

        PathNode(char vertex, PathNode parent) {
            this.vertex = vertex;
            this.parent = parent;
        }
    }

    static Map<Character, List<Node>> adjList = new HashMap<>();

    static void addEdge(char u, char v, int weight) {
        adjList.computeIfAbsent(u, k -> new ArrayList<>()).add(new Node(v, weight));
    }

    private static List<Character> bestFirstSearch(Map<Character, Integer> heuristics, char src, char dest) {
        PriorityQueue<PathNode> openList = new PriorityQueue<>(Comparator.comparingInt(n -> heuristics.get(n.vertex)));
        Set<Character> closedList = new HashSet<>(); 

        openList.add(new PathNode(src, null));

        while (!openList.isEmpty()) {
            PathNode currentNode = openList.poll();

            if (currentNode.vertex == dest) {
          
                List<Character> path = new ArrayList<>();
                PathNode cur = currentNode;

                while (cur != null) {
                    path.add(cur.vertex);
                    cur = cur.parent;
                }

                Collections.reverse(path);
                return path;
            }

            closedList.add(currentNode.vertex);

            for (Node neighbor : adjList.getOrDefault(currentNode.vertex, new ArrayList<>())) {
                if (!closedList.contains(neighbor.vertex)) {
                    openList.add(new PathNode(neighbor.vertex, currentNode));
                }
            }
        }
        return new ArrayList<>();
    }

    public static void main(String[] args) {
        
        addEdge('P', 'A', 4);  // P -> A
        addEdge('P', 'C', 4);  // P -> C
        addEdge('P', 'R', 4);  // P -> R
        addEdge('R', 'C', 2);  // R -> C
        addEdge('R', 'E', 5);  // R -> E
        addEdge('C', 'U', 3);  // C -> U
        addEdge('E', 'S', 1);  // E -> S
        addEdge('U', 'S', 5);  // U -> S
        addEdge('U', 'N', 4);  // U -> N
        addEdge('M', 'P', 3);  // M -> P
        addEdge('M', 'L', 2);  // M -> L
        addEdge('N', 'S', 6);  // N -> S

        Map<Character, Integer> heuristics = new HashMap<>();
        heuristics.put('P', 10);
        heuristics.put('A', 6);
        heuristics.put('C', 3);
        heuristics.put('R', 8);
        heuristics.put('E', 11);
        heuristics.put('U', 4);
        heuristics.put('L', 9);
        heuristics.put('M', 9);
        heuristics.put('N', 6);
        heuristics.put('S', 0);

        List<Character> path = bestFirstSearch(heuristics, 'P', 'S');

        if (path.isEmpty()) {
            System.out.println("No path found.");
        } else {
            System.out.println(String.join(" -> ", path.stream().map(String::valueOf).toList()));
        }
    }
}
