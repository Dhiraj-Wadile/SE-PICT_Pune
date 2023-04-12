//23361_Dhiraj Mangaldas Wadile
//SE-11(G-11)
//Assignment No.6
//OOP LAB
import java.util.*;
class exception
{
    Scanner sc = new Scanner(System.in);
    void arithmetic_exception()
    {
        try {
            System.out.print("\nEnter Number 1 : ");
            int num1 = sc.nextInt();
            System.out.print("Enter Number 2 : ");
            int num2 = sc.nextInt();
            System.out.println("Division of " + num1 + " and " + num2 + " is : " + num1/num2);
        }
        catch (ArithmeticException e) {
            System.out.println("\nException : " + e.getMessage());
        }
    }
    void array_out_of_bound(int arr[])
    {
        try{
            System.out.print("\nEnter the Index of the Element you want to Access : ");
            int i = sc.nextInt();
            System.out.println(arr[i] + " is present at Index " + i);
        }
        catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("\nException : " + e.getMessage());
        }
    }
    void number_format()
    {
        try {
            System.out.print("\nEnter the Number : ");
            String no = sc.next();
            System.out.println("\nNumber in Integer Format : " + Integer.parseInt(no));
        }
        catch (NumberFormatException e) {
            System.out.println("\nException : " + e.getMessage());
        }
    }
}
class assignment6 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        exception e1 = new exception();
        boolean ch = true;
        while(ch)
        {
            System.out.println("\n------------Menu------------");
            System.out.println("1.Arithmetic Exception");
            System.out.println("2.Array Out of Bound");
            System.out.println("3.Number Format");
            System.out.println("4.Exit");
            System.out.print("\nEnter Your Choice : ");
            int choice = sc.nextInt();
            switch (choice)
            {
                case 1:
                    e1.arithmetic_exception();
                    break;
                case 2:
                    System.out.print("\nEnter the Size of the Array : ");
                    int size = sc.nextInt();
                    int[] arr = new int[size];
                    for (int i=0; i<size; i++)
                    {
                        System.out.print("Enter the Element at " + i + " Position : ");
                        arr[i] = sc.nextInt();
                    }
                    e1.array_out_of_bound(arr);
                    break;
                case 3:
                    e1.number_format();
                    break;
                case 4:
                    ch = false;
                    System.out.println("\n-------------Thank You-------------");
                    break;
                default:
                    System.out.println("Invalid Option");
            }
        }
    }
}