package ConstructedClasses;

import static org.junit.jupiter.api.Assertions.*;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

import org.junit.BeforeClass;
import org.junit.jupiter.api.Test;

import HelperClasses.Stack;

/**
 * Testing validity of route obtained by BFS and DFS. We can test for validity and correctness
 * by checking to see if there is a connection between cities based on the notation in the
 * connectedCities files and the corresponding connections displayed by DFS and BFS results
 * @author Andy Hameed
 *
 */

class MainTest {


	@Test
	void testDFS() throws IOException {
		/**
		 * Generating cities, available restaurants in the cities and menu items for
		 * restaurants. Then testing 3.2 and 3.4 implementation
		 */
		Gen gen = new Gen();
		Main main = new Main();
		
		File file = new File("connectedCities.txt");
		Scanner all = new Scanner(file);
		String allLines = "";
		while (all.hasNext()) {
			allLines += all.nextLine();
		}
		allLines = allLines.toLowerCase();
		
		List<Integer> path = new ArrayList<>();
		
		for  (Integer w : Main.pthDFS.pathTo(Main.Minn)) {
			path.add(w);
		}
		
		//connection is a string that mirrors the formatting used in the original read file
		for (int i = 0; i < path.size() - 1; i++) {
			String connection = Gen.cities[path.get(i)].getName() + ", " + Gen.cities[path.get(i+1)].getName();
			
			//Check if connection exists somewhere in the file provided. Should be true for all
			assert (allLines.contains(connection.toLowerCase()));
			
		}
		
		//clear for BFS test
		path.clear();
		
		/**
		 * BFS test 
		 */
		for  (Integer w : Main.pthBFS.pathTo(Main.Minn)) {
			path.add(w);
		}
		
		
		for (int i = 0; i < path.size() - 1; i++) {
			String connection = Gen.cities[path.get(i)].getName() + ", " + Gen.cities[path.get(i+1)].getName();
			//Check if connection exists somewhere in the file provided. Should be true for all
			assert (allLines.contains(connection.toLowerCase()));
			
		}
		
		all.close();
	}
}
