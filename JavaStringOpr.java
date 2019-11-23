import java.util.Scanner;
class JavaStringOpr 
{
	public static void printReverseString(String s)
	{
		if (s.length() != 0) 
		{
			printReverseString(s.substring(1));
			System.out.print(s.charAt(0));
		}
	}

	public static void printString(String s)
	{
		if (s.length() != 0) 
		{
			System.out.print(s.charAt(0));
			printString(s.substring(1));
		}
	}
	public static void main(String[] args) 
	{
		Scanner in = new Scanner(System.in);
		System.out.print("Enter String: ");
		String s = in.nextLine();

		printString(s);
		System.out.println();

		printReverseString(s);
		System.out.println();

		in.close();
	}	
}