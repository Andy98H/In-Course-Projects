package ConstructedClasses;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class City{
	
	
	//condenses optimal meals in city as one restaurant 
	private Restaurant OptimalMeals = new Restaurant("all"); 
	
	//Status tokens used to update status on restaurant availability 
	private  boolean MC = false;
	private boolean BK = false;
	private boolean WEND = false;

	private String CityMeal;
	private String name;
	private double lat;
	private double lon;

	/**
	 * Constructor for City
	 * 
	 * @param name of city
	 * @param lat latitude measurement
	 * @param lon longitude measurement
	 */
	public City(String name, double lat, double lon) {
		this.name = name;
		this.lat = lat;
		this.lon = lon;
	}
	
	/**
	 * Finds most optimal meals available within a city based on status tokens
	 * 
	 */
	public void addOptimalMeal() {
		Restaurant m = ReadMenu.getMC();
		Restaurant b = ReadMenu.getBK();
		Restaurant w = ReadMenu.getWEND();
		
		//Append top two meals from each restaurant is they are valid in the city 
		if (MC) {OptimalMeals.addMeal(m.meal(0));OptimalMeals.addMeal(m.meal(1));}
		if (BK) {OptimalMeals.addMeal(b.meal(0));OptimalMeals.addMeal(b.meal(1));}
		if (WEND) {OptimalMeals.addMeal(w.meal(0));OptimalMeals.addMeal(w.meal(1));}
		OptimalMeals.PlaceTopMeals();
		//initially set to automatically pick best meal in Main implementation
		setCityMeal("");
	}
	
	/**
	 * @return the name of City
	 * 
	 */
	public String getName() {
		return name;
	}

	/**
	 * @return the latitude
	 * 
	 */
	public double getLat() {
		return lat;
	}

	/**
	 * @return the longitude
	 * 
	 */
	public double getLon() {
		return lon;
	}
	
	/**
	 * @return the best meal available in the city
	 * 
	 */
	public Meal bestMeal() {
		return OptimalMeals.meal(0);
	}
	
	/**
	 * @return the second best meal
	 * 
	 */
	public Meal secondBestMeal() {
		return OptimalMeals.meal(1);
	}
	
	/**
	 * @return the the name of the meal ordered at the city
	 * 
	 */
	public String getCityMeal() {
		return CityMeal;
	}
	
	/**
	 * the set the City meal order
	 * 
	 */
	public void setCityMeal(String y) {
		CityMeal = y;
	}
	
	/**
	 * Update status of restaurant availability tokens
	 * 
	 */
	public void setStatus(String rest) {
		
		if (rest.equals("BK")) BK = true;
		if (rest.equals("MC")) MC = true;
		if (rest.equals("WEND")) WEND = true;
		
	}
	

}
