import java.util.Scanner;
class Publication
{
    String title;
    int price, copies;
}
class Book extends Publication
{
    String Author;
    void ordercopies()
    {
        Scanner SC = new Scanner(System.in);
        System.out.println("Enter the title of book : ");
        title = SC.nextLine();
        System.out.println("________________________________________");
        System.out.println("Enter the Author of book : ");
        Author = SC.nextLine();
        System.out.println("________________________________________");
        System.out.println("Enter the Price of book : ");
        price = SC.nextInt();
        System.out.println("________________________________________");
        System.out.println("Enter the Copies of book : ");
        copies = SC.nextInt();
    }
    int saleCopy()
    {   System.out.println("________________________________________");
        System.out.println("Total sale of Book is : "+(price*copies));
        return copies*price;
    }
}
class Magazine extends Publication
{
    String current_issue;
    int order_quantity;
    void recevie_newissue()
    {
        Scanner SC =new Scanner(System.in);
        System.out.println("Enter the current issue of magazine:-");
        current_issue = SC.nextLine();
        System.out.println("________________________________________");
        System.out.println("Enter the order quantity of magazine:-");
        order_quantity = SC.nextInt();
        System.out.println("________________________________________");
        System.out.println("Enter price of magazine:-");
        price = SC.nextInt();
        System.out.println("________________________________________");
    }
    int saleCopy()
    {
        System.out.println("Total sale of Magazine is : "+(order_quantity*price));
        System.out.println("________________________________________");
        return order_quantity*price;
    }
}
class orderr
{
    public static void main(String[]args)
    {
        Book B1 = new Book();
        Magazine M1 = new Magazine();
        B1.ordercopies();
        int a = B1.saleCopy();
        M1.recevie_newissue();
        int b = M1.saleCopy();
        int total = a+b;
        System.out.println(" TOTAL SALE OF BOOK AND MAGAZINE IS  : "+total);
    }
}
