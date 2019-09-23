#include <stdio.h>
// return 0 if numberis invalid and 1 if number is valid
int isInputValid(int number)
{
  int temp;
  if (number < 0)
  {
    printf("Opps!!! Number is Negative\n");
    return 0;
  }
  else if (number > 99999)
  {
    printf("Opps!!! Number contain more than 5 digit\n");
    return 0;
  }
  // if number is greater than highest possible valid number
  else if (number > 11111)
  {
    printf("Opps!!! Invalid Number\n");
    return 0;
  }
  else
  {
    while (number != 0)
    {
      // take last digit
      temp = number % 10;
      number = number / 10;
      // check if digit is valid or not
      if (!(temp == 0 || temp == 1)) {
        printf("Opps!!! Invalid Number\n");
        return 0;
      }
    }
  }
  return 1;
}

int convertToDecimal(int number){
  int powerFactor = 1, temp, output = 0;
  while (number != 0)
  {
    temp = number % 10;
    number = number / 10;
    output = output + temp*powerFactor;
    powerFactor = powerFactor * 2;
  }
  return output;
}

int main() {
  int number;
  printf("Enter your number: ");
  scanf("%d",&number);

  if (isInputValid(number))
  {
    printf("Final Number: %d\n", convertToDecimal(number));
  }
  return 0;
}
