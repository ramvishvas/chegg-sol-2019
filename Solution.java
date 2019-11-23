import java.util.Scanner;
class Solution {

	public static double cToF(float c){
		float F = (((c*9) / 5) + 32);
		return F;
	}

	public static double fToC(float f){
		float C = (((f - 32)*5) / 9);
		return C;
	}

	public static double moneyJar(int quiart, int dimes, int nickels, int pennies)
	{
		double dollor = (quiart * 0.25) + (dimes * 0.1) + (nickels * 0.05) + (pennies * 0.01);
		return dollor;
	}

	public static int getRandomInteger(int minimum, int maximum){
		return ((int) (Math.random()*(maximum - minimum))) + minimum;
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		float temp, loop;

		System.out.print("Enter Tempreture in C : ");
		temp = in.nextFloat();

		System.out.println(temp+" C = "+cToF(temp)+" F");

		System.out.print("\nEnter Tempreture in F : ");
		temp = in.nextFloat();

		System.out.println(temp+" F = "+fToC(temp)+" C");

		System.out.print("\nHow many times you want to loop : ");
		loop = in.nextFloat();

		for (int i = 1; i <= loop ; i++ ) 
		{
			int quarters = getRandomInteger(0, 5);
			int dimes = getRandomInteger(5, 10);
			int nickels = getRandomInteger(3, 8);
			int pennies = getRandomInteger(0, 20);

			double dollor = moneyJar(quarters, dimes, nickels, pennies);
			System.out.println(quarters+ " quarters + "+dimes+" dimes + "+ nickels +" nickels + " + pennies + " pennies : $"+dollor);
		}
	}
}