import java.util.Scanner;

class MergeTest 
{
	public static int[] getArray(String s)
	{
		Scanner in = new Scanner(System.in);

		String tag = (s.split(" "))[1];
		System.out.println(tag +" "+ tag.equals("one"));
		if (tag.equals("one")) 
		{
			System.out.print("Enter size of list 1: ");
			int n = in.nextInt();
			int[] arr = new int[n];

			System.out.print("Enter items in list 1: ");
			for (int i = 0; i < n ; i++ ) 
			{
				arr[i] = in.nextInt();
			}

			return arr;
		}
		else if(tag.equals("two"))
		{

		}
		return null;
	}

	public static void printArray(int[] a)
	{
		for (int x : a) 
		{
			System.out.print(x+" ");	
		}
		System.out.println();
	}

	public static void main(String[] args) 
	{
		int[] arr1 = getArray("list one");
	}	
}