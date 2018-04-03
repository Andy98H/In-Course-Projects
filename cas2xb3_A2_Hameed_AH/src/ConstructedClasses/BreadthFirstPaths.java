package ConstructedClasses;


import HelperClasses.DirectedEdge;
import HelperClasses.Queue;
import HelperClasses.Stack;


/**
 * @brief Breadth First Paths implements BFS to find a path form a source node
 * to every other node in a given digraph
 *
 */
public class BreadthFirstPaths {

	private boolean[] marked;// Is a shortest path to vertex known?
	private int[] edgeTo; // last vertex on known path to this vertex
	private final int s; // source: Starting point of BFS

	/**
	 * @brief Constructor creats an array for vertices that are marked and an
	 * edgeTo[] array for the last vertex used to reach a node
	 *
	 * @param G is the Digraph for which a BFPath is being found
	 * @param s is the source node at which the bfs is performed 
	 */
	public BreadthFirstPaths(Digraph G, int s) {
		marked = new boolean[G.V()];
		edgeTo = new int[G.V()];
		this.s = s;
		bfs(G, s); //run bfs on source node s
	}

	/**
	 * @brief Implements BFS using an iterative method and a queue to keep track of
	 * vertices where a bfs needs to occur
	 * 
	 * @param G is the Digraph for which a BFPath is being found
	 * @param s is the source node at which the bfs is performed
	 */
	private void bfs(Digraph G, int s) {
		Queue<Integer> queue = new Queue<Integer>();
		marked[s] = true; // Mark the source
		queue.enqueue(s); // and put it on the queue.
		while (!queue.isEmpty()) {
			int v = queue.dequeue();// Remove next vertex from queue
			for (DirectedEdge w : G.adj(v))
				if (!marked[w.to()]) { // For every unmarked adjacent vertex,
					edgeTo[w.to()] = v;// save last edge on shortest path,
					marked[w.to()] = true;// mark it because path is known,
					queue.enqueue(w.to());// and add it to the queue.
				}
		}
	}

	
	/**
	 * @brief Returns true if a path exists to some vertex from s
	 * 
	 * @param v is the end node, the destination for the path
	 */
	public boolean hasPathTo(int v) {
		return marked[v];
	}

	/**
	 * @brief Returns a stack containing the vertices used to reach a vertex v from
	 * source vertex s. The bottom element is the source and the top is the destination
	 * 
	 * @param v is the end node, the destination for the path
	 */
	public Iterable<Integer> pathTo(int v) {
		if (!hasPathTo(v))
			return null;
		Stack<Integer> path = new Stack<Integer>();
		//check latest vertex used to reach v and push it onto stack, repeat until source is reached  
		for (int x = v; x != s; x = edgeTo[x])
			path.push(x);
		path.push(s);
		return path;
	}
}
