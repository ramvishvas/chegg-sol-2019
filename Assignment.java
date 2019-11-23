import java.util.Arrays;

public class Assignment {
	public static double valRange(double[] list) 
	{
		// if only one elementt in list
		if (list.length <= 1) {
			return 0;
		} 
		else 
		{
			// consider 1 element as both max and min 
			double min = list[0];
			double max = list[0];

			for (int i = 1; i < list.length ; ++i ) 
			{
				// if new max found update max
				if(list[i] > max) 
				{
					max = list[i];
				}
				// if new min found update min
				else  if (list[i] < min) 
				{
					min = list[i];
				}
			}
			
			return (max - min);
		}
	}

	public static int posOfLargestElementLtOeT(double limit, double[] list) 
	{
		// consider initial index is -1
		int lastIndex = -1;
		for (int i = 0; i < list.length ; ++i) 
		{
			// if less number found then update index
			if(list[i] < limit)
			{
				lastIndex = i;
			}
		}
		// return index
		return lastIndex;
	}

	public static void main(String[] args) 
	{
		System.out.println("Value of valRange");
		System.out.println(valRange(new double[] { -7 }));
		System.out.println(valRange(new double[] { 1, 7, 8, 11 }));
		System.out.println(valRange(new double[] { 11, 7, 8, 1 }));
		System.out.println(valRange(new double[] { 1, -4, -7, 7, 8, 11 }));
		System.out.println(valRange(new double[] { -13, -4, -7, 7, 8, 11 }));

		System.out.println("\nValue of posOfLargestElementLtOeT");
		System.out.println(posOfLargestElementLtOeT(3, new double[] { -7 }));
		System.out.println(posOfLargestElementLtOeT(3, new double[] { 11, -4, -7, 7, 8, 1 }));
		System.out.println(posOfLargestElementLtOeT(-7, new double[] { 1, -4, -5, 7, 8, 11 }));
	}
}
