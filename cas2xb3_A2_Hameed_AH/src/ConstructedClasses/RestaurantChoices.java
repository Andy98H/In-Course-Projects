package ConstructedClasses;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * Checks for which Restaurant Brands are within a City
 * @author Andy
 *
 */
public class RestaurantChoices {
	
	//Measure the latitude and longitude of the restaurants.
	// Can be reused once one restaurant is done
	private List<Double> lat = new ArrayList<>();
	private List<Double> lon = new ArrayList<>();
	
	/**
	 * Enter valid restaurants for each 
	 */
	public RestaurantChoices() {
			ValidRestaurant("burgerking.csv", "BK");
			ValidRestaurant("mcdonalds.csv", "MC");
			ValidRestaurant("wendys.csv", "WEND");
			
	}
	
	//checks for availability of a restaurant in a city 
	public void ValidRestaurant(String Restaurant, String tag) {
		String[] temp;
		File file = new File(Restaurant);
		Scanner sc;
		try {
			sc = new Scanner(file);
			while (sc.hasNext()) {
				temp = sc.nextLine().split(",");
				lon.add(Double.parseDouble(temp[0]));
				lat.add(Double.parseDouble(temp[1]));
				}
			
			sc.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		
		
		/**
		 * Sets status for valid restaurants to true based on latitude and longitude tolerance
		 */
		for (int i = 0; i < Gen.cities.length; i++) {
			for (int j = 0; j < lon.size(); j++) {
				if(Math.abs(lon.get(j) - Gen.cities[i].getLon()) < 0.5 && 
				(Math.abs(lat.get(j) - Gen.cities[i].getLat())) < 0.5) {
					
					switch(tag) {
					case "BK": Gen.cities[i].setStatus("BK");
					case "MC": Gen.cities[i].setStatus("MC");
					case "WEND": Gen.cities[i].setStatus("WEND");
					}
					break; 
				}	
				
			}
		}
		
		//Clear the arrays 
		lon.clear();
		lat.clear();
	}

}
