import java.io.*;
import java.util.Scanner;

class StudentRecords {
    String name, address, Class;
    int marks, Roll_no;
    long student_id;
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public void addRecords(){
        try {
            //Writing in a file
            PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("StudentRecords.txt")));
            boolean flag = false;
            do {
                System.out.print("Enter name of Student: ");
                name = br.readLine();
                System.out.print("Enter address: ");
                address = br.readLine();
                System.out.print("Student ID: ");
                student_id = Integer.parseInt(br.readLine());
                System.out.print("Enter Class: ");
                Class = br.readLine();
                System.out.print("Enter marks obtained: ");
                marks = Integer.parseInt(br.readLine());
                while (marks < 0) {
                    System.out.println("Invalid");
                    System.out.print("Please Enter marks obtained: ");
                    marks = Integer.parseInt(br.readLine());
                }
                System.out.print("Enter Roll no: ");
                Roll_no = Integer.parseInt(br.readLine());
                while (Roll_no < 0) {
                    System.out.println("Invalid");
                    System.out.print("Please Enter Roll no: ");
                    Roll_no = Integer.parseInt(br.readLine());
                }
                pw.println(name);
                pw.println(address);
                pw.println(student_id);
                pw.println(Class);
                pw.println(marks);
                pw.println(Roll_no);
                System.out.println("Records are added successfully!");
                System.out.println("Do you want to add more records? (y/n)");
                String ch = br.readLine();
                if(ch.equals("y")){
                    flag = true;
                }
                else{
                    flag = false;
                }
            }while(flag);
            pw.close();
        } catch (IOException e) {
            System.out.println("Error while writing in a file.");
        }
    }

    public void displayRecords(){
        try {
            BufferedReader br = new BufferedReader((new FileReader("StudentRecords.txt")));

            while((name = br.readLine()) != null){
                System.out.println("--------------------------------------------------");
                System.out.println("\nName: "+name);
                System.out.println("Address: "+br.readLine());
                System.out.println("Student ID: "+Integer.parseInt(br.readLine()));
                System.out.println("Class: "+br.readLine());
                System.out.println("Marks: "+Integer.parseInt(br.readLine()));
                System.out.println("Roll no: "+Integer.parseInt(br.readLine()));
                System.out.println("--------------------------------------------------");
            }
            br.close();
        } catch (FileNotFoundException e) {
            System.out.println("Error while reading in a file.");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public void searchRecords() throws IOException {
        String str;
        BufferedReader file = null;
        System.out.print("\nEnter name of student you want to search: ");
        str = br.readLine();
        file = new BufferedReader((new FileReader("StudentRecords.txt")));
        boolean flag = false;

        while((name = file.readLine()) != null){
            if(str.equals(name.toString())) {
                flag = true;
                System.out.println("--------------------------------------------------");
                System.out.println("\nName: " + name);
                System.out.println("Address: " + file.readLine());
                System.out.println("Student ID: " + Integer.parseInt(file.readLine()));
                System.out.println("Class: " + file.readLine());
                System.out.println("Marks: " + Integer.parseInt(file.readLine()));
                System.out.println("Roll no: " + Integer.parseInt(file.readLine()));
                System.out.println("--------------------------------------------------");
            }
        }
        file.close();
        if(flag == false){
            System.out.println("\nNo record found for"+str);
        }
    }

    public void deleteRecords() throws IOException {
        String str;
        System.out.print("\nEnter name of student you want to delete: ");
        str = br.readLine();
        boolean flag = false;
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("StudentRecords1.txt",false)));
        BufferedReader file1 = new BufferedReader((new FileReader("StudentRecords.txt")));

        while((name = file1.readLine()) != null){
            if(str.equals(name.toString())) {
                flag = true;
                System.out.println("Record found Deleting Record");
                System.out.println("--------------------------------------------------");
                System.out.println("\nName: " + name);
                System.out.println("Address: " + file1.readLine());
                System.out.println("Student ID: " + Integer.parseInt(file1.readLine()));
                System.out.println("Class: " + file1.readLine());
                System.out.println("Marks: " + Integer.parseInt(file1.readLine()));
                System.out.println("Roll no: " + Integer.parseInt(file1.readLine()));
                System.out.println("--------------------------------------------------");
            }
            else {
                pw.println(name);
                pw.println(file1.readLine());
                pw.println(Integer.parseInt(file1.readLine()));
                pw.println(file1.readLine());
                pw.println(Integer.parseInt(file1.readLine()));
                pw.println(Integer.parseInt(file1.readLine()));
            }
        }
        file1.close();
        pw.close();
        if(flag == false){
            System.out.println("No record found for "+str);
        }
        File f = new File("StudentRecords.txt");
        f.delete();
        //renaming the file
        File oldName = new File("StudentRecords1.txt");
        File newName = new File("StudentRecords.txt");
        oldName.renameTo(newName);
    }

    public void modifyRecords() throws IOException {
        String str;
        System.out.print("\nEnter name of student you want to modify: ");
        str = br.readLine();
        boolean flag = false;
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("StudentRecords1.txt",false)));
        BufferedReader file1 = new BufferedReader((new FileReader("StudentRecords.txt")));

        while((name = file1.readLine()) != null){
            if(str.equals(name.toString())) {
                flag = true;
                System.out.println("Record found with following data\nCurrent Record");
                System.out.println("--------------------------------------------------");
                System.out.println("\nName: " + name);
                System.out.println("Address: " + file1.readLine());
                System.out.println("Student ID: " + Integer.parseInt(file1.readLine()));
                System.out.println("Class: " + file1.readLine());
                System.out.println("Marks: " + Integer.parseInt(file1.readLine()));
                System.out.println("Roll no: " + Integer.parseInt(file1.readLine()));
                System.out.println("--------------------------------------------------");
                System.out.println();
                System.out.println("-----Enter new Information-----");

                System.out.print("Enter name of Student: ");
                name = br.readLine();
                System.out.print("Enter address: ");
                address = br.readLine();
                System.out.print("Student ID: ");
                student_id = Integer.parseInt(br.readLine());
                System.out.print("Enter Class: ");
                Class = br.readLine();
                System.out.print("Enter marks obtained: ");
                marks = Integer.parseInt(br.readLine());
                while (marks < 0) {
                    System.out.println("Invalid");
                    System.out.print("Please Enter marks obtained: ");
                    marks = Integer.parseInt(br.readLine());
                }
                System.out.print("Enter Roll no: ");
                Roll_no = Integer.parseInt(br.readLine());
                while (Roll_no < 0) {
                    System.out.println("Invalid");
                    System.out.print("Please Enter Roll no: ");
                    Roll_no = Integer.parseInt(br.readLine());
                }
                pw.println(name);
                pw.println(address);
                pw.println(student_id);
                pw.println(Class);
                pw.println(marks);
                pw.println(Roll_no);

            }
            else {
                pw.println(name);
                pw.println(file1.readLine());
                pw.println(Integer.parseInt(file1.readLine()));
                pw.println(file1.readLine());
                pw.println(Integer.parseInt(file1.readLine()));
                pw.println(Integer.parseInt(file1.readLine()));
            }
        }
        file1.close();
        pw.close();
        if(flag == false){
            System.out.println("No record found for "+str);
        }
        File f = new File("StudentRecords.txt");
        f.delete();
        //renaming the file
        File oldName = new File("StudentRecords1.txt");
        File newName = new File("StudentRecords.txt");
        oldName.renameTo(newName);

    }
}

public class FileHandling_8 {

    int menu(){
        int choice = 0;
        System.out.println("==== File Handling ====");
        System.out.println("-----------------------------");
        System.out.println("1.Add Records");
        System.out.println("2.Display Records");
        System.out.println("3.Delete Records");
        System.out.println("4.Search Records");
        System.out.println("5.Modify Records");
        System.out.println("6.Exit");
        System.out.println("-----------------------------");
        return choice;
    }
    public static void main(String []args) throws IOException {
        StudentRecords obj = new StudentRecords();
        int choice = 0;
        Scanner sc = new Scanner(System.in);
        FileHandling_8 a = new FileHandling_8();
        do{
            a.menu();
            System.out.print("\nEnter your choice: ");
            choice = sc.nextInt();

            switch (choice) {
                case 1:
                    obj.addRecords();
                    break;
                case 2:
                    obj.displayRecords();
                    break;
                case 3:
                    obj.deleteRecords();
                    break;
                case 4:
                    obj.searchRecords();
                    break;
                case 5:
                    obj.modifyRecords();
                    break;
            }
        }while(choice < 6);
    }
}
