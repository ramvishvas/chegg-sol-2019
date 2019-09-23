public class StringOperation {
	public static String mySort(String s)
	{
		int N = s.length();
		char[] chars = s.toCharArray();

		for (int i = 0; i < N; i += 2) 
		{
			int minIndex = i;
			for (int j = i+2; j < N - 2 ; j += 2) 
			{
				if (chars[minIndex] > chars[j]) 
				{
					minIndex = j;
				}
			}
			char temp = chars[i];
			chars[i] = chars[minIndex];
			chars[minIndex] = temp;
		}

		for (int i = 1; i < N; i += 2) 
		{
			int minIndex = i;
			for (int j = i+2; j < N - 2 ; j += 2) 
			{
				if (chars[minIndex] > chars[j]) 
				{
					minIndex = j;
				}
			}
			char temp = chars[i];
			chars[i] = chars[minIndex];
			chars[minIndex] = temp;
		}

		return new String(chars);
	}
	// public static String[] twins(String[] a, String[] b)
	// {

	// }
	public static void main(String[] args) 
	{
		System.out.println(mySort("cdab"));	
	}
}