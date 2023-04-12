import java.util.*;
class ComplexOperation{
    float real, img;
    public ComplexOperation(){
        real = 0;
        img = 0;
    }

    public ComplexOperation(float x){
        real = x;
        img = 0;
    }

    public ComplexOperation(float x, float y){
        real = x;
        img = y;
    }

    void addComplex(ComplexOperation c1, ComplexOperation c2){
        float real, img;
        this.real = c1.real + c2.real;
        this.img = c1.img + c2.img;
        System.out.println("Addition of the Given Complex Number is : "+ this.real + " + " + this.img + "i" );
        System.out.println();
    }

    void substractComplex(ComplexOperation c1, ComplexOperation c2){
        float real, img;
        this.real = c1.real - c2.real;
        this.img = c1.img - c2.img;
        if(this.img  >= 0){
            System.out.println("Substraction of the Given Complex Number is : "+ this.real + " + " + this.img  + "i" );
            System.out.println();

        }else{
            System.out.println("Substraction of the Given Complex Number is : "+ this.real +" - " +(-1*this.img ) + "i" );
            System.out.println();

        }

    }

    void multiplyComplex(ComplexOperation c1, ComplexOperation c2){
        float real, img;
        this.real = c1.real*c2.real - c1.img*c2.img;
        this.img = c1.real*c2.img + c1.img*c2.real;
        System.out.println("multiplication of the Given Complex Number is : "+ this.real  + " + " + this.img  + "i" );
        System.out.println();

    }

    void divideComplex(ComplexOperation c1, ComplexOperation c2){
        float real, img;
        this.real = ((c1.real*c2.real) + (c1.img*c2.img))/(c2.real * c2.real + c2.img * c2.img);
        this.img = (c1.img*c2.real) - (c1.real*c2.img)/(c2.real * c2.real + c2.img * c2.img);
        System.out.println("Division of the Given Complex Number is : "+ this.real  + " + " + this.real  + "i" );
        System.out.println();

    }

}

public class Complex_1
{
    public static void main(String[] args) {
        float a, b, c, d;

        Scanner sc = new Scanner(System.in);

        System.out.println("Complex number 1");
        System.out.println("Enter Real Part ");
        a = sc.nextFloat();

        System.out.println("Enter Imaginary Part ");
        b = sc.nextFloat();
        ComplexOperation c1 = new ComplexOperation(a, b);

        System.out.println("Complex number 2");
        System.out.println("Enter Real Part ");
        c = sc.nextFloat();

        System.out.println("Enter Imaginary Part ");
        d = sc.nextFloat();
        ComplexOperation c2 = new ComplexOperation(c, d);

        System.out.println();
        System.out.println("---------------------------------");
        System.out.println("Entered Complex numbers are : ");
        System.out.println(a+" + "+b+"i");
        System.out.println(c+" + "+d+"i");
        System.out.println("---------------------------------");

        System.out.println();

        ComplexOperation cal = new ComplexOperation();
        int ch;

        do{
            System.out.println("Enter the Choice From the following");
            System.out.println("1. Addition");
            System.out.println("2. Subtraction");
            System.out.println("3. Multiplication");
            System.out.println("4. Division");
            System.out.println("5. Repeat Input");
            System.out.println("6. Exit");
            ch = sc.nextInt();
            System.out.println();

            switch (ch) {
                case 1:
                    cal.addComplex(c1, c2);
                    break;

                case 2:
                    cal.substractComplex(c1, c2);
                    break;

                case 3:
                    cal.multiplyComplex(c1, c2);
                    break;

                case 4:
                    cal.divideComplex(c1, c2);
                    break;

                case 5:
                    main(args);
                    break;
            }
        }while(ch!=6);
    }
}