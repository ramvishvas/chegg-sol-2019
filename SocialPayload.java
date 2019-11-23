import java.util.Scanner;
public class SocialPayload {
	public static void cumputeAndPrintTax(double amount, double taxRate)
	{
		double totalTax = (amount * taxRate) / 100;
		System.out.println("You will pay $"+totalTax+" in Social Security tax");
	}

	public static double camputeTotalEarn(double hourlyWage, double hourPerWeek)
	{
		return (hourlyWage*hourPerWeek*52);
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		System.out.print("Enter hourly wage: ");
		double hourlyWage = in.nextDouble();

		System.out.print("Enter your hour per week: ");
		double hourPerWeek = in.nextDouble();

		double totalEarn = camputeTotalEarn(hourlyWage, hourPerWeek);

		System.out.println("You will earn $"+totalEarn+" per week");

		cumputeAndPrintTax(totalEarn, 6.2);

		in.close();
	}
}