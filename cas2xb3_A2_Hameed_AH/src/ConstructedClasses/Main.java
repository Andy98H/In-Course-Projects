package ConstructedClasses;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

import HelperClasses.DirectedEdge;

/**
 *Main runs searching and shortest paths algorithms used. The results are 
 *printed in the text file a2_out.txt
 *
 * @author Andy Hameed
 *
 */

public class Main {
	
	public static DepthFirstPath pthDFS;
	public static BreadthFirstPaths pthBFS;
	public static int boston = Digraph.search("BOSTON");
	public static int Minn = Digraph.search("MINNEAPOLIS");
	public static Digraph routes = new Digraph(32);

	public Main() throws IOException {
		
		/**
		 * Reading Connected Cities and adding weighted edges
		 */
    	String[] temp;
    	File file = new File("connectedCities.txt");
    	Scanner sc;
		try {
			sc = new Scanner(file);
			
			while (sc.hasNext()) {
	    		temp= sc.nextLine().split(",");
	    		//find weight based on the cheapest meal satisfying conditons
	    		float weight = CheapestMeal(Digraph.search(temp[0]), Digraph.search(temp[1].substring(1)));
	    		routes.addEdge(new DirectedEdge(Digraph.search(temp[0]),Digraph.search(temp[1].substring(1)),weight));
	    		
	    	}
			
	    	sc.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		//Perform BFS and DFS at Boston and print results
		
		pthDFS = new DepthFirstPath(routes, boston);
		pthBFS = new BreadthFirstPaths(routes, boston);
		
		
		//Write into results file	
		WriteResults();
		
		
}
	private float CheapestMeal(int tail, int head) {
		// TODO Auto-generated method stub
		City prev = Gen.cities[tail];
		City current = Gen.cities[head];
		
		if (prev.getCityMeal().equals("")) {current.setCityMeal(current.bestMeal().name());return current.bestMeal().price();}
		
		//if the previous meal matches the best meal in the current city,
		//pick the next best meal in the city
		if (prev.getCityMeal().equals(current.bestMeal().name())){current.setCityMeal(current.secondBestMeal().name());return current.secondBestMeal().price();}
		
		return current.bestMeal().price();
	}
	
	public static void WriteResults() throws IOException {
		FileWriter fw = new FileWriter("a2_out.txt");
		BufferedWriter results;
			results = new BufferedWriter(fw);
			//BFS results
			results.write("BFS: ");
			for (Integer w : pthBFS.pathTo(Minn)) {
				results.append(" " +  Gen.cities[w].getName() + ",");	
			}
			//DFS results
			results.newLine();
			results.write("DFS: ");
			for (Integer w : pthDFS.pathTo(Minn)) {
				results.append(" " +  Gen.cities[w].getName() + ",");
			}
			
			//Printing out results for shortest path
			Dijkstras shortestPath = new Dijkstras(routes, boston);
			
			results.newLine();
			results.newLine();
			results.append(" City | Meal Choice | Meal Cost");
			results.newLine();
			results.append(" BOSTON ");
			for (DirectedEdge w : shortestPath.pathTo(Minn)) {
				results.newLine();
				results.append(" " +  Gen.cities[w.to()].getName() + "|" + Gen.cities[w.to()].getCityMeal() + " | $" + w.weight());	
			}
			results.newLine();
			results.append(" Total Cost: $" + shortestPath.distTo(Minn));
			results.close();
			
			results.close();
			
	}
}