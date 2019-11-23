import java.util.Scanner;

class ArrayReverse 
{
	public static void arrayReverse(int array[])
	{
		int firstIndex = 0, lastIndex = array.length - 1;
		while(firstIndex < lastIndex)
		{
			int temp = array[firstIndex];
			array[firstIndex] = array[lastIndex];
			array[lastIndex] = temp;
			firstIndex += 1;
			lastIndex -= 1;
		}
	}

	public static void main(String[] args) 
	{
		Scanner in = new Scanner(System.in);
		//take the input in string array separated by whitespaces" "
		String[] strArr = in.nextLine().split(" ");

		int[] array = new int[strArr.length];

		System.out.print("Entered Number: ");

		for(int i=0;i<strArr.length;i++)
		{
			//each array indices parsed to integer
 			array[i] = Integer.parseInt(strArr[i]);
 			System.out.print(array[i]+" ");
 		}

 		arrayReverse(array);

 		System.out.print("\nReversed Number: ");
 		for(int i=0;i<array.length;i++)
		{
 			System.out.print(array[i]+" ");
 		}
 		System.out.println();
 	}
 }