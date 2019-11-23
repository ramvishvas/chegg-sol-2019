class StringBuilderDrive {
	public static void main(String[] args) {
		// builder is mutable
		StringBuilder builder = new StringBuilder("We Are");

		// String is immutable
		String value = "Online Education";

		// printing builder
		System.out.println("builder Is\t\t\t: "+builder);

		// this will append "Family" at the end of builder
		builder.append("Family");

		// printing new builder
		System.out.println("builder.append(\"Family\") Is\t: "+ builder);
		
		//printing value
		System.out.println("\nvalue Is\t\t: "+value);

		// get required substring
		value = value.substring(0,8);

		System.out.println("value.substring(0,8) Is\t: "+value);
	}
}