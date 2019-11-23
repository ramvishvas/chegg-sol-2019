class WhileLoop {
	public static void main(String[] args) {
		int num = 1;

		while(true) {
			// check is number 5 or not
			if (num == 5) 
			{
				// print 5 to 1
				while(num != 0)
				{
					System.out.print(num+ " ");
					num -= 1;
				}
				break;
			} 
			// if num < 5
			else 
			{
				System.out.print(num + " ");
				num += 2;
			}
		}
		// this is for new line at end
		System.out.println();
	}
}