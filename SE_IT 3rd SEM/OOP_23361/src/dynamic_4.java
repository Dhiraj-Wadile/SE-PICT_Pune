import java.util.Scanner;
abstract class shape{
    double b,h,b1,h1;
    abstract void compute_area();

}
class triangle extends shape{
    double area_triangle;
    void compute_area()
    {
        System.out.println("FOR TRIANGLE ->");
        Scanner sc=new Scanner(System.in);
        System.out.println("BASE IS ");
        b=sc.nextDouble();
        System.out.println("HEIGHT IS ");
        h=sc.nextDouble();
        area_triangle=0.5*b*h;
        System.out.println("AREA OF TRIANGLE IS  "+area_triangle+ " units.");
        System.out.println("---------------------------------------------");
    }
}
class rectangle extends shape {
    double area_rectangle;

    void compute_area() {
        System.out.println("FOR RECTANGLE ->");
        Scanner sc = new Scanner(System.in);
        System.out.println("LENGTH IS ");
        b1 = sc.nextDouble();
        System.out.println("BREADTH IS ");
        h1 = sc.nextDouble();
        area_rectangle = b1 * h1;
        System.out.println("AREA OF RECTANGLE IS " +area_rectangle+" units.");
        System.out.println("---------------------------------------------");
    }
}
public class dynamic_4 {
    public static void main(String[] args) {
        shape t = new triangle();
        shape r = new rectangle();
        int ch;
        System.out.println("Enter the Choice\n1.For Area of Triangle\n2.For Area of Rectangle\n3.Exit");
        Scanner sc = new Scanner(System.in);
        int chs = sc.nextInt();
        switch (chs) {
            case 1:
                t.compute_area();
            case 2:
                r.compute_area();
        }
    }

}