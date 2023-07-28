#!/bin/bash      #specifies the interpreter (bash) that will be used to execute the script.

ADDRESS_BOOK_FILE="address_book.txt"  #assigned name and use this variable to refer to the address book file throughout the code.     

create_addressbook() {   #address book file using the touch command and prints a message indicating that the address book has been created.
    touch "$ADDRESS_BOOK_FILE"
    echo "Address book created successfully."
}

view_addressbook() {    #address book file exists and is not empty using the -s test. If it is not empty,
                        #it prints the contents of the file using the cat command. If it is empty, it indicates address book is empty.
    if [ -s "$ADDRESS_BOOK_FILE" ]; then
        cat "$ADDRESS_BOOK_FILE"
    else
        echo "Address book is empty."
    fi
}

insert_record() {      #user to enter a name, phone number, email, and address using the read command,
                       #then appends the record in the format name | phone | email | address to the address book file.
    echo "Enter Name: "
    read name
    echo "Enter Phone Number: "
    read phone
    echo "Enter Email: "
    read email
    echo "Enter Address: "
    read address

    echo "$name | $phone | $email | $address" >> "$ADDRESS_BOOK_FILE"
    echo "Record inserted successfully."
}

delete_record() {     #user to enter the name of the record they want to delete using the read command.
                      #It then checks if the name exists in the address book file using grep -q. If it finds the name, 
                      #it uses grep -v to remove the record from the file and stores the result in a temporary file (temp_file). 
                      #Finally, it replaces the original address book file with the temporary file using mv, effectively deleting the record.
    echo "Enter the Name of the record to delete: "
    read name_to_delete

    if grep -q "$name_to_delete" "$ADDRESS_BOOK_FILE"; then
        grep -v "$name_to_delete" "$ADDRESS_BOOK_FILE" > temp_file
        mv temp_file "$ADDRESS_BOOK_FILE"
        echo "Record deleted successfully."
    else
        echo "Record not found."
    fi
}

modify_record() {    # Instead of deleting the record, it modifies it. 
                     #The function prompts the user to enter the name of the record they want to modify using the read command. 
                     #It then checks if the name exists in the address book file using grep -q. 
                     #If it finds the name, it uses grep -v to remove the existing record from the file and 
                     #stores the result in a temporary file (temp_file). Then, it prompts the user to enter 
                     #the new name, phone number, email, and address, and appends the modified record to the temporary file. 
                     #Finally, it replaces the original address book file with the temporary file using mv, effectively modifying the record.
    echo "Enter the Name of the record to modify: "
    read name_to_modify

    if grep -q "$name_to_modify" "$ADDRESS_BOOK_FILE"; then
        grep -v "$name_to_modify" "$ADDRESS_BOOK_FILE" > temp_file

        echo "Enter Name: "
        read name
        echo "Enter Phone Number: "
        read phone
        echo "Enter Email: "
        read email
        echo "Enter Address: "
        read address

        echo "$name | $phone | $email | $address" >> temp_file
        mv temp_file "$ADDRESS_BOOK_FILE"
        echo "Record modified successfully."
    else
        echo "Record not found."
    fi
}

main() {     #It uses a while loop to repeatedly display a list of options to the user, 
             #and then takes user input to choose one of the options.Depending on the chosen option (a-f), 
             #it calls the corresponding function 
             #(create_addressbook, view_addressbook, insert_record, delete_record, modify_record) or exits the program 
             #if the user chooses to exit (f).
    while true; do
        echo -e "\nOptions:"
        echo "a) Create address book"
        echo "b) View address book"
        echo "c) Insert a record"
        echo "d) Delete a record"
        echo "e) Modify a record"
        echo "f) Exit"

        read -p "Enter your choice (a-f): " choice

        if [ "$choice" = "a" ]; then
            create_addressbook
        elif [ "$choice" = "b" ]; then
            view_addressbook
        elif [ "$choice" = "c" ]; then
            insert_record
        elif [ "$choice" = "d" ]; then
            delete_record
        elif [ "$choice" = "e" ]; then
            modify_record
        elif [ "$choice" = "f" ]; then
            echo "Exiting..."
            break
        else
            echo "Invalid choice. Please try again."
        fi
    done
}

main    #This line calls the main() function to start the address book program

