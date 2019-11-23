class StringReverse 
{
  // reverse method
  public static String reverse(String str) 
  {
    String reversed = "";
    for (int i = str.length() - 1; i >= 0; i--)
    {
      reversed += str.charAt(i);
    }
    return reversed;
  }

  // main method
  public static void main(String[] args) 
  {
    String string = "asdf asdf";

    System.out.println("The Original sentence is : " + string);
    System.out.println("The reverse sentence is  : " + reverse(string));
    System.out.println("The reverse of reverse is: " + reverse(reverse(string)));
  }
}