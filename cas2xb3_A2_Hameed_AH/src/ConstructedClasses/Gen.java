package ConstructedClasses;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 * Class calls for menu items to be generates into Restaurant ADTS, reads and loads
 * cities, and updates city status for restaurants brands available
 * 
 * @author Andy Hameed
 *
 */

public class Gen {			
	
	public static City[] cities= new City[32]; //Used to store the 32 cities
	
	public Gen(){
		String[] temp; 
		int i = 0; 
		
		//Read the menu items and place them in their corresponding restaurants
		ReadMenu menu = new ReadMenu();
		
		File file = new File("USCities.csv");
		
		//Load cities
		try {
			Scanner inputstream = new Scanner(file);
			inputstream.nextLine();
			while (inputstream.hasNext()) {
				temp = inputstream.nextLine().split(",");
				//create city object using values in the line
				City city = new City(
							temp[3],
							Double.parseDouble(temp[4]),
							Double.parseDouble(temp[5]));
				
				//insert city and increment index 
				cities[i] = city;
				i++;
			}
			
			inputstream.close(); //close file
			
			
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} 
		
		//Check which restaurants are valid in each city
		RestaurantChoices rest = new RestaurantChoices();
		
		//Add optimal meals for each city
		for (int j = 0; j < cities.length; j++) {
			cities[j].addOptimalMeal();
		}
		
		

	}

}
