import java.util.Scanner;
public class employee_3 {
    int emp_id;
    double da,hra,pf,club_fund,gross,net,basicpay;
    String mno,name,mail,type,address;
    employee_3()
    {
        emp_id=0;
        name="  ";
        address="  ";
        mail="  ";
    }
    Scanner sc=new Scanner(System.in);
    void getdata(employee_3 e1[],int j)
    {
        System.out.println("Enter employee details");
        System.out.println("Enter employee ID");
        sc.nextLine();
        System.out.println("Enter employee name ");
        name=sc.nextLine();
        System.out.println("Enter employee Mail");
        mail=sc.nextLine();
        System.out.println("Enter employee Address");
        address=sc.nextLine();
    }
    void displaydata()
    {
        System.out.println("Employee details are:");
        System.out.println("Employee ID is "+emp_id);
        System.out.println("Employee name is "+name);
        System.out.println("Employee mail_ID is "+mail);
        System.out.println("Employee address is "+address);
    }
    void cal_salary(double basicpay){
        da=basicpay*0.97;
        hra=basicpay*0.1;
        pf=basicpay*0.12;
        club_fund=basicpay*0.001;
        gross=basicpay+da+hra;
        net=gross-pf-club_fund;
    }
    void displaysalary(String type)
    {
        System.out.println("DA of basic pay is "+da);
        System.out.println("HRA of basic pay is "+hra);
        System.out.println("PF of basic pay is "+pf);
        System.out.println("Club fund of basic pay is"+club_fund);
        System.out.println("Gross salary is "+gross);
        System.out.println("Net salary is "+net);
    }
}
class programmer extends employee_3 {
    Scanner sc = new Scanner(System.in);

    void bp_pgm(employee_3 e1) {
        double basicpay;
        System.out.println("Enter basic pay of programmer");
        basicpay = sc.nextDouble();
        e1.cal_salary(basicpay);
        type = "PROGRAMMER";
        e1.displaydata();
        e1.displaysalary(type);
    }
}

class teamlead extends employee_3{
    Scanner sc = new Scanner(System.in);

    void bp_tl(employee_3 e1) {
        double basicpay;
        System.out.println("Enter basic pay Team Lead");
        basicpay = sc.nextDouble();
        e1.cal_salary(basicpay);
        type = "TEAM LEAD";
        e1.displaydata();
        e1.displaysalary(type);
    }
}

class assistant extends employee_3 {
    Scanner sc = new Scanner(System.in);

    void bp_as(employee_3 e1) {
        double basicpay;
        System.out.println("Enter basic pay of Assistant manager ");
        basicpay = sc.nextDouble();
        e1.cal_salary(basicpay);
        type = "ASSISTANT";
        e1.displaydata();
        e1.displaysalary(type);
    }
}

class project extends employee_3 {
    Scanner sc = new Scanner(System.in);

    void bp_pj(employee_3 e1) {
        double basicpay;
        System.out.println("Enter basic pay Project manager");
        basicpay = sc.nextDouble();
        e1.cal_salary(basicpay);
        type = "PROJECT MANAGER";
        e1.displaydata();
        e1.displaysalary(type);
    }
}

class Salary{
    public static void main(String args[]) {
        int n;
        int flag = 0;
        int ch = 0;
        System.out.println("Enter number of employee");
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        employee_3 e[] = new employee_3[n];
        for (int i=0;i<n;i++)
        {
            e[i]=new employee_3();
            e[i].getdata(e,i);
            while(flag==0){
                System.out.println("Enter the choice ");
                System.out.println("1.PROGRAMMER ");
                System.out.println("2.TEAMLEAD");
                System.out.println("3.ASSISTANT ");
                System.out.println("4.PROJECT MANAGER ");
                ch=sc.nextInt();
                switch(ch){
                    case 1:
                        programmer p=new programmer();
                        p.bp_pgm(e[i]);
                        flag=1;
                        break;
                    case 2:
                        teamlead d=new teamlead();
                        d.bp_tl(e[i]);
                        flag=1;
                        break;
                    case 3:
                        assistant a=new assistant();
                        a.bp_as(e[i]);
                        flag=1;
                        break;
                    case 4:
                        project m=new project();
                        m.bp_pj(e[i]);
                        flag=1;
                        break;
                }
            }

        }
    }
}

