import java.util.*;
class Bank
{
    int mobileno,adharno,age;
    String name;
    double balance, totalbalance,deposit,withdraw;

    Bank()
    {
        mobileno = 0;
        adharno = 0;
        age = 0;
        name = " ";
        balance = 0;
    }

    void createaccount()
    {
        Scanner sc = new Scanner (System.in);
        System.out.println("Enter Your name:");
        name = sc.nextLine();
        System.out.println("Enter Your age:");
        age = sc.nextInt();
        System.out.println("Enter Your mobile no:");
        mobileno = sc.nextInt();
        System.out.println("Enter Your adhar no:");
        adharno = sc.nextInt();
        System.out.println("****Successfully created account****");
        System.out.println("Your account details:");
        System.out.println("Name: "+name);
        System.out.println("Age: "+age);
        System.out.println("Mobile no: "+mobileno);
        System.out.println("Adhar no: "+adharno);
        System.out.println("Your Account no:xxxxxxx7865");
    }
    //1) Banking system having following operations :
//        1. Create an account
//        2. Deposit money
//        3. Withdraw money
//        4. Honor daily withdrawal limit
//5. Check the balance
// 6. Display Account information
    void deposit()
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Amount to deposit:");
        deposit = sc.nextDouble();
        totalbalance = balance + deposit;
        System.out.println("Rs "+deposit+" successfully deposited");
        System.out.println("Total balance: "+totalbalance);

    }

    void withdraw()
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter amount to withdraw: ");
        withdraw = sc.nextDouble();
        if(withdraw <= totalbalance)
        {
            totalbalance = totalbalance - withdraw;
            System.out.println(withdraw+" deducted successfully");
            System.out.println("Total balance: "+totalbalance);
        }
        else
        {
            System.out.println("Insufficient balance");
        }
    }


    void checkbalance()
    {
//        totalbalance = totalbalance + deposit - withdraw;
        System.out.println("Total balance: "+totalbalance);
    }

    void accountdetails()
    {
        System.out.println("Name: "+name);
        System.out.println("Age: "+age);
        System.out.println("Mobile no: "+mobileno);
        System.out.println("Adhar no: "+adharno);
        System.out.println("Your Account no:xxxxxxx7865");
    }
}

public class Casestudy_9
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int sel;
        Bank b = new Bank();
        for(int i=0;i<6;i++)
        {
            System.out.println("****WELCOME****\n1.Create Account\n2.Deposit Money\n3.Withdraw Money\n4.Check Balance\n5.Account details\n6.Exit\nEnter your choice:\n");
            sel = sc.nextInt();
            switch(sel)
            {
                case 1:
                    b.createaccount();
                    break;
                case 2:
                    b.deposit();
                    break;
                case 3:
                    b.withdraw();
                    break;
                case 4:
                    b.checkbalance();
                    break;
                case 5:
                    b.accountdetails();
                    break;
                case 6:
                    System.out.println("Thank You");
                    break;

            }
        }


    }
}