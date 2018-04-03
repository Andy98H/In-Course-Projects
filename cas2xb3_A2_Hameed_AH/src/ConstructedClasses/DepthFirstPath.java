package ConstructedClasses;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import HelperClasses.DirectedEdge;
import HelperClasses.Stack;

public class DepthFirstPath {

	private boolean[] marked;// Has dfs() been called for this vertex? Keeps track of nodes that have been marked.  
							//Shows that there is a path from Source to some vertex
	private int[] edgeTo; // last vertex on known path to this vertex
	private final int s; // source vertex

	//perform dfs from source to every other vertex in the digraph
	public DepthFirstPath(Digraph G, int s) {
		marked = new boolean[G.V()];
		edgeTo = new int[G.V()];
		this.s = s;
		dfs(G, s);
	}

	//performs DFS starting at v 
	private void dfs(Digraph G, int v) {
		//current node gets marked since it has been called recursively and found in adjacency list
		marked[v] = true;
		//for any w in adjacency list, if not marked, make the latest edge to w
		for (DirectedEdge w : G.adj(v))
			if (!marked[w.to()]) {
				edgeTo[w.to()] = v; //means s->w->v
				//recursively call dfs for adjacent nodes w until all nodes are found 
				dfs(G, w.to());
			}
	}

	//returns true if there is a path to v
	public boolean hasPathTo(int v) {
		return marked[v];
	}

	/**
	 * @brief Returns a stack containing the vertices used to reach a vertex v from
	 * source vertex s. The bottom element is the source and the top is the destination
	 * 
	 * @param v is the end node, the destination for the path
	 */
	public Stack<Integer> pathTo(int v) {
		if (!hasPathTo(v))
			return null;
		//stack of integers takes in latest vertex stemming from x - w and pushes w on, continues until all vertices are listed.
		Stack<Integer> path = new Stack<Integer>();
		for (int x = v; x != s; x = edgeTo[x])
			path.push(x);
		path.push(s);
		return path;
	}
	
}
