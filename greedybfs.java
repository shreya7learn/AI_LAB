import java.util.*;

class GreedyBestFirstSearchNumbers {
    static class Node implements Comparable<Node> {
        int id;
        int heuristic;

        Node(int id, int heuristic) {
            this.id = id;
            this.heuristic = heuristic;
        }

        @Override
        public int compareTo(Node other) {
            return Integer.compare(this.heuristic, other.heuristic);
        }
    }

    static Map<Integer, List<Integer>> graph = new HashMap<>();
    static Map<Integer, Integer> heuristics = new HashMap<>();

    public static void greedyBestFirstSearch(int start, int goal) {
        PriorityQueue<Node> openList = new PriorityQueue<>();
        Set<Integer> visited = new HashSet<>();
        openList.add(new Node(start, heuristics.get(start)));

        System.out.println("Exploring path: ");
        while (!openList.isEmpty()) {
            Node current = openList.poll();
            if (visited.contains(current.id)) {
                continue;
            }

            System.out.println(current.id);
            visited.add(current.id);

            if (current.id == goal) {
                System.out.println("Goal reached: " + goal);
                return;
            }

            for (int neighbor : graph.getOrDefault(current.id, new ArrayList<>())) {
                if (!visited.contains(neighbor)) {
                    openList.add(new Node(neighbor, heuristics.get(neighbor)));
                }
            }
        }
        System.out.println("Goal not reachable.");
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of nodes: ");
        int nodes = scanner.nextInt();

        System.out.print("Enter the number of edges: ");
        int edges = scanner.nextInt();

        System.out.println("Enter the edges (format: from to):");
        for (int i = 0; i < edges; i++) {
            int from = scanner.nextInt();
            int to = scanner.nextInt();

            graph.putIfAbsent(from, new ArrayList<>());
            graph.get(from).add(to);
        }

        System.out.println("Enter heuristic values for each node (format: node value):");
        for (int i = 0; i < nodes; i++) {
            int node = scanner.nextInt();
            int heuristic = scanner.nextInt();
            heuristics.put(node, heuristic);
        }

        System.out.print("Enter the start node: ");
        int start = scanner.nextInt();
        System.out.print("Enter the goal node: ");
        int goal = scanner.nextInt();

        // Perform the search
        greedyBestFirstSearch(start, goal);

        scanner.close();
    }
}
