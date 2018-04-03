package ConstructedClasses;

import java.util.ArrayList;
import java.util.List;
/**
 * Restaurant ADT
 * Used to represent a restaurant brand and the meals it offers
 * @author Andy
 *
 */
public class Restaurant{
	
	private String name;
	private List<Meal> meals = new ArrayList<>();
	
	/**
	 * Restaurant ADT Constructor
	 *
	 */
	public Restaurant(String name){
		this.name = name;
	}
	
	/**
	 * Add meal to the restaurant's meals list
	 *
	 */
	public void addMeal(Meal m) {
		this.meals.add(m);
	}
	

	/**
	 * Get meal found at the ith index
	 *
	 */
	public Meal meal(int i) {
		return meals.get(i);
	}
	
	/**
	 * Get meal name at index i
	 *
	 */
	public String getMeal(int i) {
		return this.meals.get(i).name();
	}
	
	/**
	 * Get meal price at index i
	 *
	 */
	public float getPrice(int i) {
		return this.meals.get(i).price();
	}
	
	/**
	 * Get number of meals offered/ size of meals array
	 *
	 */
	public int menuSize() {
		return this.meals.size();
	}
	
	
	
	/**
	 * PlaceTopMeals: Helper Method
	 * Sets top 2 meals at the beginning of the meals list for a restaurant
	 */
	public void PlaceTopMeals() {
		
		//sets cheapest meal at the beginning of meals array
		float low = getPrice(0);
		Meal temp = meals.get(0);
		for (int i = 1; i < menuSize(); i++) {
			//some meal in the list is cheaper
			if (getPrice(i) < low) {
				low = getPrice(i);
				temp = meals.get(0);
				meals.set(0, meals.get(i));
				meals.set(i, temp);
			}
		}
		
		//omits first meal from comparison
		low = this.getPrice(1);
		
		//sets second cheapest meal at the second index of meals array
		for (int i = 2; i < menuSize(); i++) {
			if (this.getPrice(i) < low) {
				low = this.getPrice(i);
				meals.set(1, meals.get(i));
			}
		}
		
	}
	
}
