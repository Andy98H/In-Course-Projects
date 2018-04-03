package ConstructedClasses;

/**
 *  Implementation was built on provided walkthrough 10_2
 * 
 */

import HelperClasses.DirectedEdge;
import HelperClasses.IndexMinPQ;
import HelperClasses.Queue;
import HelperClasses.Stack;

public class Dijkstras {

	private DirectedEdge[] edgeTo;
	private double[] distTo;
	private IndexMinPQ<Double> pq;

	/**
	 * Relaxes edge v of a Digraph G
	 * 
	 * @param G Digraph
	 * @param v vertex being relaxed
	 */
	private void relax(Digraph G, int v) {
		for (DirectedEdge e : G.adj(v)) {
			int w = e.to();
			//If path through v and edge e is shorter to get to w, update the w's path 
			if (distTo[w] > distTo[v] + e.weight()) {
				distTo[w] = distTo[v] + e.weight();
				edgeTo[w] = e;
				//update the path in the PQ is w exists, otherwise as w and its distance
				if (pq.contains(w))
					pq.changeKey(w, distTo[w]);
				else
					pq.insert(w, distTo[w]);
			}
		}
	}

	/**
	 * @brief Constructor for Dijkstras shortest path algorithm 
	 * @param G Digraph being searched 
	 * @param s source vertex from which shortest path is taken
	 */
	public Dijkstras(Digraph G, int s) {
		edgeTo = new DirectedEdge[G.V()];
		distTo = new double[G.V()];
		pq = new IndexMinPQ<Double>(G.V());
		for (int v = 0; v < G.V(); v++)
			distTo[v] = Double.POSITIVE_INFINITY;
		distTo[s] = 0.0;
		pq.insert(s, 0.0);
		while (!pq.isEmpty())
			relax(G, pq.delMin()); //relax edge until PQ is empty
	}

	/**
	 * @brief returns distance to vertex v from source via shortest path 
	 */
	public double distTo(int v) {
        return distTo[v];
    }
	
	/**
	 * @brief Returns a stack containing the vertices used to reach a vertex v from
	 * source vertex s. The bottom element is the source and the top is the destination
	 * 
	 * @param v is the end node, the destination for the path
	 */
	 public Iterable<DirectedEdge> pathTo(int v) {
	        Stack<DirectedEdge> path = new Stack<DirectedEdge>();
	        for (DirectedEdge e = edgeTo[v]; e != null; e = edgeTo[e.from()]) {
	            path.push(e);
	        }
	        return path;
	    }
	

}
