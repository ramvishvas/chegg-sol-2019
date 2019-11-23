public class Ordered{
	public static void main(String[] args) {
		int w = Integer.parseInt(args[0]);
		int x = Integer.parseInt(args[1]);
		int y = Integer.parseInt(args[2]);
		int z = Integer.parseInt(args[3]);

		boolean isAscending = (w > x) && (x > y) && (y > z);
		boolean isDescending = (w < x) && (x < y) && (y < z);

		boolean val = isAscending || isDescending;

		// System.out.println("isAscending: "+isAscending);
		// System.out.println("isDescending: "+isDescending);
		System.out.println("Output: "+val);
	}
}