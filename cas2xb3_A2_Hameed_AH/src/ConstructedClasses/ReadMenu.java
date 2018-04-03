package ConstructedClasses;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 * 
 * @author Andy
 *
 * Reads menu items for each restaurant and adds the menu items 
 * to corresponding restaurant ADT
 * 
 */
public class ReadMenu {

	
	//Initialize the three restaurants
	private static Restaurant MC = new Restaurant("McDonald's");
	private static Restaurant BK = new Restaurant("Burger King");
	private static Restaurant WEND = new Restaurant("Wendy's");
	
	// Getters for the Restaurants above
	public static Restaurant getMC() {
		return MC;
	}

	public static Restaurant getBK() {
		return BK;
	}

	public static Restaurant getWEND() {
		return WEND;
	}
	
	/**
	 * Reads menu items from menu.csv and appends them to the meals for each restaurant
	 */
	public ReadMenu() {
		
	String[] temp;
	File file = new File("menu.csv");
	
	try {
		
		Scanner menu = new Scanner(file);
		menu.nextLine(); //skip headers
		while (menu.hasNext()) {
			temp = menu.nextLine().split(","); //split at comma
			Meal newMeal = new Meal(temp[1],Float.parseFloat(temp[2].substring(1)));
			
			
			//Appending menu items to restaurant meals based on first letter of restaurant
			if (temp[0].charAt(0) == 'M')  MC.addMeal(newMeal);
			else if (temp[0].charAt(0) == 'B') BK.addMeal(newMeal);
			else if (temp[0].charAt(0) == 'W') WEND.addMeal(newMeal);
			
			}
		
		menu.close();
		
		//in case the file does not exist
	} catch (FileNotFoundException e) {
		e.printStackTrace();
	} 
	
	

	//Place top meals at the start of each restaurant meals array
	
	MC.PlaceTopMeals();
	BK.PlaceTopMeals();
	WEND.PlaceTopMeals();
	
	}
}
