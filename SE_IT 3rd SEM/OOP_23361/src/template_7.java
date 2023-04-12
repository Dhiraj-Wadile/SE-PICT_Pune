import java.util.*;
import java.util.ArrayList;

class Collection
{
    Scanner sc = new Scanner(System.in);

    public <T> void inputArray(ArrayList<T> list)
    {
        System.out.print("\nEnter Size of Array : ");
        int size = sc.nextInt();

        System.out.print("\nEnter Array Elements : ");
        for(int i=0;i<size;i++) {
            T s = (T) sc.next();
            list.add(s);
        }
        System.out.print("\n--------------------------------");
        System.out.print("\nContent of  Array : ");
        for(int i=0;i<size;i++) {
            System.out.print(" " + list.get(i));
        }
        System.out.print("\n");
    }
    public <T> void evenOdd(T n)
    {
        if((int)n%2==0)
            System.out.println("\n" + n +" is Even Number");
        else
            System.out.println("\n" + n +" is Odd Number");
    }
    public <T> void evenNumbers(ArrayList<T> list)
    {
        int count=0;
        System.out.print("\nEven Numbers in List : ");
        for(int i=0;i<list.size();i++)
        {
            String a = (String) list.get(i);
            int b = Integer.parseInt(a);
            if(b%2==0)
            {
                System.out.print(list.get(i) + " ");
                count++;
            }
        }
        if(count==0)
            System.out.print("Zero Prime Numbers");
    }
    public <T> void oddNumbers(ArrayList<T> list)
    {
        int count=0;
        System.out.print("\n\nOdd Numbers in List : ");
        for(int i=0;i<list.size();i++)
        {
            String a = (String) list.get(i);
            int b = Integer.parseInt(a);
            if(b%2!=0)
            {
                System.out.print(list.get(i) + " ");
                count++;
            }
        }
        if(count==0)
            System.out.print("Zero Odd Numbers");
    }
    public boolean is_prime(int num)
    {
        if(num<=1)
            return false;
        for(int i=2;i<num;i++)
        {
            if(num%i==0)
                return false;
        }
        return true;
    }
    public <T> void primeNumbers(ArrayList<T> list)
    {
        int count=0;
        System.out.print("\n\nPrime Numbers in List : ");
        for(int i=0;i<list.size();i++)
        {
            String a = (String) list.get(i);
            int b = Integer.parseInt(a);
            if(is_prime(b) && b!=1)
            {
                System.out.print(list.get(i) + " ");
                count++;
            }
        }
        if(count==0)
            System.out.print("Zero Prime Numbers");
        System.out.print("\n");
    }
    public <T> boolean is_palindrome(T s)
    {
        String s1 = (String)s;
        s1=s1.toLowerCase();
        int start = 0;
        int end = s1.length()-1;
        while(start<=end)
        {
            if(s1.charAt(start) != s1.charAt(end) || s1.length()<=1)
            {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    public <T> void palindromes(ArrayList<T> list)
    {
        int count=0;
        System.out.print("\nPalindrome's in List : ");
        for(int i=0;i<list.size();i++)
        {
            String a = (String) list.get(i);
            if(is_palindrome(a))
            {
                System.out.print(a + " ");
                count++;
            }
        }
        if(count==0)
            System.out.print("Zero Palindrome");
        System.out.print("\n");
    }
}
class Assign7 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Collection c = new Collection();

        String str;

        boolean go=true;
        while(go)
        {
            System.out.println("\n--------------Menu--------------");
            System.out.println("\n\t1.String \n\t2.Integer \n\t3.String Array \n\t4.Integer Array \n\t5.Exit");
            System.out.print("\nChoose An Option : ");
            int choice = sc.nextInt();

            switch(choice)
            {
                case 1:
                    System.out.print("\nEnter the String : ");
                    str = sc.next();
                    System.out.print("\n--------------------------------");
                    if(c.is_palindrome(str))
                        System.out.println("\n" + str + " is Palindrome");
                    else
                        System.out.println("\n" + str + " is Not Palindrome");
                    System.out.println("--------------------------------");
                    break;
                case 2:
                    System.out.print("\nEnter the Integer : ");
                    str = sc.next();
                    System.out.print("\n--------------------------------");
                    c.evenOdd(Integer.parseInt(str));
                    if(c.is_prime(Integer.parseInt(str)))
                        System.out.println("\n" + str + " is Prime Number");
                    else
                        System.out.println("\n" + str + " is Not Prime Number");
                    if(c.is_palindrome(str))
                        System.out.println("\n" + str + " is Palindrome");
                    else
                        System.out.println("\n" + str + " is Not Palindrome");
                    System.out.println("--------------------------------");
                    break;
                case 3:
                    ArrayList<String> sl = new ArrayList<String>();
                    c.inputArray(sl);
                    c.palindromes(sl);
                    System.out.println("--------------------------------");
                    break;
                case 4:
                    ArrayList<Integer> il = new ArrayList<Integer>();
                    c.inputArray(il);
                    c.evenNumbers(il);
                    c.oddNumbers(il);
                    c.primeNumbers(il);
                    c.palindromes(il);
                    System.out.println("--------------------------------");
                    break;
                case 5:
                    go = false;
                    System.out.println("\n------------Thank You------------\n");
                    break;
                default:
                    System.out.println("\nInvalid Input");
            }
        }
    }
}
