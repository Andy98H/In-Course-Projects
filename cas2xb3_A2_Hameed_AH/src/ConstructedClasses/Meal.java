package ConstructedClasses;

/**
 * @brief Simple ADT for Meals
 * 
 */
public class Meal {

	private String meal;
	private float price;

	/**
	 * Constructor takes in a meal and price and sets them as object variables
	 * 
	 */
	public Meal(String meal, float price) {
		this.meal = meal;
		this.price = price;
	}

	/**
	 * gets meal name
	 */
	public String name() {
		return this.meal;
	}

	/**
	 * gets meal price
	 */
	public float price() {
		return this.price;
	}

}
