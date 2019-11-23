import java.util.Scanner;
class NumberOperation {

	public static int sum(int x, int y, int z)
	{
		return x+y+z;
	}


	public static int average(int x, int y, int z)
	{
		return (x+y+z)/3;
	}

	public static int product(int x, int y, int z)
	{
		return (x*y*z);
	}


	public static int largest(int x, int y, int z)
	{
		if(x > y && x > z)
		{
			return x;
		}
		else if(y > z)
		{
			return y;
		}
		else
		{
			return z;
		}
	}

	public static int smallest(int x, int y, int z){
		if(x < y && x < z)
		{
			return x;
		}
		else if(y < z)
		{
			return y;
		}
		else
		{
			return z;
		}
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int x, y, z;

		System.out.print("Enter 1st Integer: ");
		x = in.nextInt();

		System.out.print("Enter 2nd Integer: ");
		y = in.nextInt();

		System.out.print("Enter 3rd Integer: ");
		z = in.nextInt();

		in.close();

		System.out.println("\nEntered Number: "+x+", "+y+", "+z);

		System.out.println("\nSUM\t: "+sum(x,y,z));
		System.out.println("AVERAGE\t: "+average(x,y,z));
		System.out.println("Product\t: "+product(x,y,z));
		System.out.println("SMALLEST: "+smallest(x,y,z));
		System.out.println("LARGEST\t: "+largest(x,y,z));
	}
}