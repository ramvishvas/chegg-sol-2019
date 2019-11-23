import java.util.Enumeration;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class Assignment6 {
	public static void main(String[] args) {
		testTwoStacksAreEqualMethod();
	}

	public static boolean twoStacksAreEqual(Stack<Integer> s1, Stack<Integer> s2)
	{
		if (s1.empty() && s2.empty()) 
		{
			return true;	
		}

		else if (s1.empty() && s2.empty()) 
		{
			return false;	
		}

		else
		{
			while(!(s1.empty() || s2.empty()))
			{
				if (s1.pop() != s2.pop()) 
				{
					return false;
				}
			}
			if (s1.empty() && s2.empty()) 
			{
				return true;	
			}
		}
		return false;
	}

	private static void testTwoStacksAreEqualMethod() 
	{
		Stack<Integer> myStack1 = new Stack<Integer>();
		Stack<Integer> myStack2 = new Stack<Integer>();
		Stack<Integer> myStack3 = new Stack<Integer>();
		Stack<Integer> myStack4 = new Stack<Integer>();

		for (int i = 0; i < 5; i++)
		{
			myStack1.push(i);
			myStack2.push(i);
			myStack4.push(i);
		}

		for (int i = 0; i < 6; i++)
		{
			myStack3.push(i);
		}

		System.out.println(twoStacksAreEqual(myStack1,myStack2) + " Same Stack");
		System.out.println(twoStacksAreEqual(myStack3, myStack4) + " Not Same Stack");
	}
} //end of Assignment6