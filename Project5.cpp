#include<iostream>
#include<string>
#include<fstream> 
using namespace std;

string password[10];
string admin[10];
string studentPassword[10];
string studentId[10];
string bookName[30];
string authorName[30];
int totalCopies[30];
int availableCopies[30];
int allotedBook[30] = {0};
int bookReference[30]; // bookReference[i] stores index of book issued to student i


//--------------------FUNCTION DECLARATION--------------------
//UI
void showlogInPage();
void showSigUpPage();
void showMainMenuPage();
void showAdminAuthenticationPage();
void showStudentAuthenticationPage();
void showAdminMenuHeading();
void showStudentMenuHeading();
void availableBooksAdmin(int bookCount);

//Student
void showStudentMenuPage();
void viewIssuedBooks();
void viewAvailableBooks();
void studentIssuedBook(int bookCount, int studentCount);
void studentReturnBook(int bookCount, int studentCount);
void availableBooksStudent(int bookCount);

//Admin 
void showAdminMenuPage();
void showAddBook();
void showIssueBook();
void showReturnBookAdmin();
void showStudentRecords();
void showOverdueBooks();
void addBook(int &bookCount);
void issueBook(int studentCount, int bookCount);
void returnBook(int studentCount, int bookCount);
void studentRecord(int studentCount, int bookCount);
void overDueBooks(int bookCount);
void availableBooksAdmin(int bookCount);

//File Handling
void loadAllStudents(int &studentCount);
void loadAllAdmins(int &adminCount);
void loadAllBooks(int &bookCount);
void updateAllBooks(int &bookCount);

//Idhr zyada Pyary lg rhy hain
void signIn(string password[], string admin[],int &adminCount, int &bookCount, int studentCount );
int signUp(string password[],string admin[],int &adminCount);
void studentSignIn(string studentPassword[], string studentId[], int &bookCount, int studentCount);
int studentSignUp(string studentPassword[],string studentId[], int &studentCount);
void mainMenu(int &adminCount, int &studentCount, int &bookCount);
void adminAuthenticationMenu(int &adminCount, int &bookCount, int &studentCount);
void studentAuthenticationMenu(int &studentCount, int &bookCount);
void adminMainMenu(int &bookCount, int &studentCount);
void studentMainMenu(int &bookCount, int &studentCount);



//----------------------Main----------------------
int main()
{
    int adminCount = 0, studentCount = 0, bookCount = 0;
    loadAllAdmins(adminCount);
    loadAllStudents(studentCount);
    loadAllBooks(bookCount);

    mainMenu(adminCount, studentCount, bookCount); 
     
    return 0;
}


//--------------------Main Menu Page--------------------
void showMainMenuPage()
{
    cout<<"\n-----------------------------\n";
    cout<<"         Main Menu\n";
    cout<<"-----------------------------\n";
    cout<<"1. Admin.\n";
    cout<<"2. Student.\n";
    cout<<"3. Exit.\n";
}

//--------------------SIGN IN Page--------------------
void showlogInPage()
{
    cout << "\n-----------------------------\n";
    cout << "         LOGIN PAGE\n";
    cout << "-----------------------------\n";
}

//--------------------SIGN Up Page--------------------
void showSigUpPage()
{
    cout << "\n-----------------------------\n";
    cout << "         SignUp PAGE\n";
    cout << "-----------------------------\n";
}

//--------------------Student Menu Heading--------------------
void showStudentMenuHeading()
{
    cout<<"\n-----------------------------\n";
    cout<<"         Student Menu\n";
    cout<<"-----------------------------\n";
}

//--------------------Admin Menu Page--------------------
void showAdminMenuHeading()
{
    cout<<"\n-----------------------------\n";
    cout<<"         Admin Menu\n";
    cout<<"-----------------------------\n";
}

//--------------------Admin Authentication Page--------------------
void showAdminAuthenticationPage()
{
    showAdminMenuHeading();
    cout<<"1. Sign In.\n";
    cout<<"2. Sign Up.\n";
    cout<<"3. Exit.\n";
}

//--------------------Student Authentication Page--------------------
void showStudentAuthenticationPage()
{
    showStudentMenuHeading();
    cout<<"1. Sign In.\n";
    cout<<"2. Sign Up.\n";
    cout<<"3. Exit.\n";
}

//-----------------------------------------------------------------------------------------------------------------------------

//--------------------Student Menu Page--------------------
void showStudentMenuPage()
{
    showStudentMenuHeading();
    cout<<"1. My Issued Book.\n";
    cout<<"2. Return Book.\n";
    cout<<"3. Available Books.\n";
    cout<<"4. Exit.\n";
}

//--------------------Return Book--------------------
void returnBook() {
    cout << "\n-----------------------------\n";
    cout << "         Return Book\n";
    cout << "-----------------------------\n";
    cout << "Enter the book ID or name to return.\n";
}

//--------------------Issued Books--------------------
void viewIssuedBooks() {
    cout << "\n-----------------------------\n";
    cout << "       My Issued Books\n";
    cout << "-----------------------------\n";
    cout << "Here are the books you have currently issued:\n";
}

//--------------------Available Books--------------------
void viewAvailableBooks() {
    cout << "\n-----------------------------\n";
    cout << "       Available Books\n";
    cout << "-----------------------------\n";
    cout << "List of all books currently available in the library:\n";
}


//-----------------------------------------------------------------------------------------------------------------------------

//--------------------Admin Menu Page--------------------
void showAdminMenuPage()
{
    showAdminMenuHeading();
    cout << "1. Add Book.\n";
    cout << "2. Issue Book.\n";
    cout << "3. Return Book.\n";
    cout << "4. Student Records.\n";
    cout << "5. Overdue Books.\n";
    cout << "6. Available Books.\n";
    cout << "7. Exit.\n";
}

//--------------------Add Book--------------------
void showAddBook() {
    cout << "\n-----------------------------\n";
    cout << "           Add Book\n";
    cout << "-----------------------------\n";
    cout << "Enter book details to add to the library.\n";
}

//--------------------Issue Book--------------------
void showIssueBook() {
    cout << "\n-----------------------------\n";
    cout << "          Issue Book\n";
    cout << "-----------------------------\n";
    cout << "Enter Student Password and book No. to issue a book.\n";
}

//--------------------Return Book--------------------
void showReturnBookAdmin() {
    cout << "\n-----------------------------\n";
    cout << "          Return Book\n";
    cout << "-----------------------------\n";
    cout << "Enter the student ID and book ID to return a book.\n";
}

//--------------------Student Records--------------------
void showStudentRecords() {
    cout << "\n-----------------------------\n";
    cout << "       Student Records\n";
    cout << "-----------------------------\n";
}

//--------------------Overdue Books--------------------
void showOverdueBooks() {
    cout << "\n-----------------------------\n";
    cout << "        Overdue Books\n";
    cout << "-----------------------------\n";
    cout << "List of all books that are overdue.\n";
}


//-----------------------------------------------------------------------------------------------------------------------------

//----------------------Load Books----------------------
void loadAllBooks(int &bookCount)
{
    ifstream in("books.txt");
    string import;

    while(getline(in, import))
    {
        int coma1, coma2, coma3;
        coma1 = import.find(",");
        coma2 = import.find(",", coma1 + 1);
        coma3 = import.find(",", coma2 + 1);

        bookName[bookCount] = import.substr(0 , coma1);
        authorName[bookCount] = import.substr(coma1 +1, coma2 - coma1 - 1);
        totalCopies[bookCount] = stoi(import.substr(coma2 + 1, coma3 - coma2 - 1));
        availableCopies[bookCount] = stoi(import.substr(coma3 + 1));

        bookCount++;
        
    }
}

//----------------------Upload Updated Books----------------------
void updateAllBooks(int &bookCount)
{
    ofstream out("books.txt" , ios::trunc);

    for(int i = 0 ; i < bookCount ; i++)
    {
        out << bookName[i] << "," << authorName[i] << "," << totalCopies[i] 
        << "," << availableCopies[i] << endl;
    }

    out.close();
}

//----------------------MENU----------------------
void mainMenu(int &adminCount, int &studentCount, int &bookCount)
{
    while(true)
    {
        string i;

        showMainMenuPage();

        cout<<"Enter Your Choice: ";
        cin>>i;

        if(i == "1")
        {
            adminAuthenticationMenu(adminCount, bookCount, studentCount);
        }

        else if(i == "2")
        {
            studentAuthenticationMenu(studentCount, bookCount);
        }

        else if(i == "3")
        {
            cout<<"Bye!!";
            break;
        }

        else
        {
            cout<<"Wrong Input try again!";
        }
    
    }  
}

//----------------------Admin File----------------------
void loadAllAdmins(int &adminCount)
{
    ifstream in("admin.txt");
    string import;

    while(getline(in, import))
    {
        int find = import.find(",");

        admin[adminCount] = import.substr(0, find);
        password[adminCount] = import.substr(find + 1);

        adminCount++;
    }

}


//----------------------ADMIN Authentication MENU----------------------
void adminAuthenticationMenu(int &adminCount, int &bookCount, int &studentCount)
{
    while(true)
    {
        string i;

        showAdminAuthenticationPage();

        cout<<"Enter Your Choice: ";
        cin>>i;

        if(i == "1")
        {
            signIn(password, admin, adminCount, bookCount, studentCount);
        }

        else if(i == "2")
        {
            signUp(password,admin, adminCount);
        }

        else if(i == "3")
        {
            cout<<"Bye!!";
            break;
        }

        else
        {
            cout<<"Wrong Input try again!";
        }
    
    }  
}

//------------------ADMIN SIGN IN-------------------
void signIn(string password[], string admin[],int &adminCount, int &bookCount, int studentCount )
{
 string user, pass;
 bool isIt = true;

    

    while(isIt)
    {
        showlogInPage();

        cout << "Enter Username: ";
        cin.ignore();
        getline(cin,user);

        cout << "Enter Password: ";
        cin>>pass;

        for(int i =0; i<=adminCount; i++)
        {
            if(pass == password[i] && user == admin[i])
            {
                cout<<"Login Successful!\n";
                adminMainMenu(bookCount, studentCount);
                isIt = false;
                break;
            }

        }

        if(isIt)
            {
                cout<<"Wrong Credentials!!!";
                cout<<"Press E to Exist and Y to try Again:";
                string opt;
                cin>>opt;
                if(opt == "Y" || opt == "y")
                {
                    isIt = true;
                }

                else
                {
                    isIt = false;
                }

            }
    }
}

//----------------------ADMIN SIGN UP----------------------
int signUp(string password[],string admin[],int &adminCount)
{

    showSigUpPage();

    cout<<"Enter User Name:";
    cin.ignore();
    getline(cin,admin[adminCount]);

    cout<<"Enter password:";
    cin>>password[adminCount];  

    cout<<"Signed Up Successfully!\n";

    ofstream out("admin.txt" , ios::app);
    out << admin[adminCount]<<","<<password[adminCount]<<endl;
    out.close();

    adminCount++;

    return adminCount;
    
}

//----------------------Admin MENU----------------------
void adminMainMenu(int &bookCount, int &studentCount)
{
    while(true)
    {
        string i;

        showAdminMenuPage();

        cout<<"Enter Your Choice: ";
        cin>>i;

        if(i == "1")
        {
            addBook(bookCount);
        }

        else if(i == "2")
        {
            issueBook(studentCount, bookCount);
        }

        else if(i == "3")
        {
            returnBook(studentCount, bookCount);
        }

        else if(i == "4")
        {
            studentRecord(studentCount, bookCount);
        }

        else if(i == "5")
        {
            overDueBooks(bookCount);
        }

        else if(i == "6")
        {
            availableBooksAdmin(bookCount);
        }

        else if(i == "7")
        {
            cout<<"Bye!!";
            break;
        }

        else
        {
            cout<<"Wrong Input try again!";
        }
    
    } 
}

//----------------------Add Book----------------------
void addBook(int &bookCount)
{
    bool cond = true;
    string choice = "y";
    while(cond)
    {
        if(choice == "y" || choice == "Y")
        {
            showAddBook();
            cout<<"Enter Book Name: ";
            cin.ignore();
            getline(cin, bookName[bookCount]);
            cout<<"Enter Aurthor Name: ";
            getline(cin, authorName[bookCount]);
            cout<<"Enter Number of Copies: ";
            cin>> totalCopies[bookCount];
            availableCopies[bookCount] = totalCopies[bookCount];
            ofstream out("books.txt" , ios::app);
            out << bookName[bookCount] << "," << authorName[bookCount] << "," << totalCopies[bookCount] 
            << "," << availableCopies[bookCount] << endl;
            out.close();

            bookCount++;
        }
        else if(choice == "E" || choice == "e")
        {
            cond = false;
            break;
        }
        else
        {
            cout<<"Wrong Input try again!";
        }
        cout<<"To Add Books Enter Y and To Exit Enter E: ";
        cin>>choice;
    }

}

//----------------------Issue Book----------------------
void issueBook(int studentCount, int bookCount)
{
    string pass, sNumber;
    int number;
    showIssueBook();
    cout<< "Enter Student Password: ";
    cin.ignore();
    getline(cin, pass) ;
    cout<< "Enter Book Number: ";
    getline(cin, sNumber);
    number = stoi(sNumber);
    for (int i = 0; i <= studentCount; i++)
    {
        if(pass == studentPassword[i] && number <= bookCount )
        {
            if(availableCopies[number] > 0 && allotedBook[i] == 0)
            {
                cout<<"Book Alloted Successfully!";
                availableCopies[number]-- ;
                bookReference[i] = number ;
                allotedBook[i]++ ;
                updateAllBooks(bookCount);
                return;
            }
            else if (allotedBook[i] > 0)
            {
                cout<<"Book already alloted!";
                return;
            }
            else
            {
                cout<<"Book Not Available!";
                return;
            }
            
        }
    }
    cout<<"Wrong Credentials!!!";
      
}

//----------------------Return Book----------------------
void returnBook(int studentCount, int bookCount)
{
    string pass, sNumber;
    int number;
    showIssueBook();
    cout<< "Enter Student Password: ";
    cin.ignore();
    getline(cin, pass) ;
    cout<< "Enter Book Number: ";
    getline(cin, sNumber);
    number = stoi(sNumber);
    for (int i = 0; i <= studentCount; i++)
    {
        if(pass == studentPassword[i] && number <= bookCount )
        {
            if(availableCopies[number] > 0 && allotedBook[i] == 1)
            {
                cout<<"Book Returned Successfully!";
                availableCopies[number]++;
                allotedBook[i]--;
                updateAllBooks(bookCount);
                return;
            }
            else
            {
                cout<<"Book was never alloted!";
                return;
            }
            
        }
    }

    cout<<"Wrong Credentials!!!";
     
}

//----------------------Student Record----------------------
void studentRecord(int studentCount, int bookCount)
{
    string pass;
    showStudentRecords();
    cout<<"Enter student Pass: ";
    cin.ignore();
    getline(cin, pass);
    for (int i =0; i <= studentCount; i++)
    {
        if(pass == studentPassword[i])
        {
            if( allotedBook[i] > 0)
            {
                cout<<"Student Name: "<<studentId[i]<<endl;
                cout<<"The Alloted Book Is: \n";
                cout<< bookName[bookReference[i]]<<" ";
                cout<< "written by "<<authorName[bookReference[i]]<<".";
                return;  
            }
            else
            {
                cout<<"No Book Alloted.";
                return;
            }
            
        }
    }

}

//----------------------Over Due Books----------------------
void overDueBooks(int bookCount)
{
    bool check = true;
    showOverdueBooks();
    for(int i = 0; i<= bookCount; i++)
    {
        if(totalCopies[i] > availableCopies[i])
        {
            cout<<i<<". "<<bookName[i]<<" written by "<<authorName[i]<<". ";
            cout<<"No. of Over Due Copies "<<totalCopies[i] - availableCopies[i]<<".\n";
            check = false;
        }
    }
    if(check)
    {
        cout<<"No over due Books.";
    }
}

//----------------------Available Books----------------------
void availableBooksAdmin(int bookCount)
{
    bool check = true;
    viewAvailableBooks();
    for(int i = 0; i<= bookCount; i++)
    {
        if(availableCopies[i] > 0)
        {
            cout<<i<<". "<<bookName[i]<<" written by "<<authorName[i]<<". ";
            cout<<"No. of Available Copies "<<availableCopies[i]<<".\n";
            check = false;
        }
    }
    if(check)
    {
        cout<<"No Books Available";
    }
}

//----------------------STUDENT File----------------------
void loadAllStudents(int &studentCount)
{
    ifstream in("student.txt");
    string import;

    while(getline(in, import))
    {
        int find = import.find(",");
        studentId[studentCount] = import.substr(0, find);
        studentPassword[studentCount] = import.substr(find + 1);
        studentCount++;
    }
}

//----------------------STUDENT Authentication MENU----------------------
void studentAuthenticationMenu(int &studentCount, int &bookCount)
{
    while(true)
    {
        string i;

        showStudentAuthenticationPage();

        cout<<"Enter Your Choice: ";
        cin>>i;

        if(i == "1")
        {
            studentSignIn(studentPassword, studentId, bookCount, studentCount );
        }

        else if(i == "2")
        {
            studentSignUp(studentPassword,studentId, studentCount);
        }

        else if(i == "3")
        {
            cout<<"Bye!!";
            break;
        }

        else
        {
            cout<<"Wrong Input try again!";
        }
    
    }  
}


//------------------USER SIGN IN-------------------
void studentSignIn(string studentPassword[], string studentId[], int &bookCount, int studentCount )
{
 string user, pass;
 bool isIt = true;


    while(isIt)
    {
        showlogInPage();

        cout << "Enter StudentID: ";
        cin.ignore();
        getline(cin,user);

        cout << "Enter Password: ";
        cin>>pass;

        for(int i =0; i<10; i++)
        {
            if(pass == studentPassword[i] && user == studentId[i])
            {
                cout<<"Login Successful!\n";
                studentMainMenu(studentCount, bookCount);
                isIt = false;
                break;
            }

        }

        if(isIt)
        {
            cout<<"Wrong Credentials!!!";
            cout<<"Press E to Exist and Y to try Again:";
            string opt;
            cin>>opt;
            if(opt == "Y" || opt == "y")
            {
                isIt = true;
            }
        
            else
            {
                isIt = false;
            }

        }
    }

}




//----------------------USER SIGN UP----------------------
int studentSignUp(string studentPassword[],string studentId[], int &studentCount)
{
    showSigUpPage();

    cout<<"Enter User Name:";
    cin.ignore();
    getline(cin,studentId[studentCount]);

    cout<<"Enter password:";
    cin>>studentPassword[studentCount]; 

    cout<<"Signed Up Successfully!\n";

    ofstream out("student.txt" , ios::app);
    out << studentId[studentCount] << "," << studentPassword[studentCount] << endl;
    out.close();

    studentCount++;

    return studentCount;
    
}


//----------------------STUDENT MENU----------------------
void studentMainMenu(int &bookCount, int &studentCount)
{
    while(true)
    {
        string i;

        showStudentMenuPage();

        cout<<"Enter Your Choice: ";
        cin>>i;

        if(i == "1")
        {
            studentIssuedBook(studentCount, bookCount);
        }

        else if(i == "2")
        {
            studentReturnBook(bookCount, studentCount);
        }

        else if(i == "3")
        {
            availableBooksStudent(bookCount);
        }

        else if(i == "4")
        {
            cout<<"Bye!!";
            break;
        }

        else
        {
            cout<<"Wrong Input try again!";
        }
    
    } 
}

//----------------------Issued Books By Student----------------------
void studentIssuedBook(int studentCount, int bookCount)
{
    string pass;
    viewIssuedBooks();
    cout<<"Enter Your Student Pass: ";
    cin.ignore();
    getline(cin, pass);
    for (int i =0; i < studentCount; i++)
    {
        if(pass == studentPassword[i])
        {
            if( allotedBook[i] > 0)
            {
                cout<<"The Alloted Book Is: \n";
                cout<< bookName[bookReference[i]]<<" ";
                cout<< "written by "<<authorName[bookReference[i]]<<".";
                return;  
            }
            else
            {
                cout<<"No Book Alloted.";
                return;
            }
            
        }
    }

    cout<<"Wrong Credentials!!!";

}

//----------------------Return Book By Student----------------------
void studentReturnBook(int bookCount, int studentCount)
{
    string pass, sNumber;
    int number;
    showIssueBook();
    cout<< "Enter Student Password: ";
    cin.ignore();
    getline(cin, pass) ;
    cout<< "Enter Book Number: ";
    getline(cin, sNumber);
    number = stoi(sNumber);
    for (int i = 0; i <= studentCount; i++)
    {
        if(pass == studentPassword[i] && number <= bookCount )
        {
            if(availableCopies[number] > 0 && allotedBook[i] == 1)
            {
                cout<<"Book Returned Successfully!";
                availableCopies[number]++;
                allotedBook[i]--;
                updateAllBooks(bookCount);
                return;
            }
            else
            {
                cout<<"Book was never alloted!";
                return;
            }
            
        }
    }

    cout<<"Wrong Credentials!!!";
 
}

//----------------------Available Book By Student----------------------
void availableBooksStudent(int bookCount)
{
    bool check = true;
    viewAvailableBooks();
    for(int i = 0; i< bookCount; i++)
    {
        if(availableCopies[i] >= 0)
        {
            cout<<i<<". "<<bookName[i]<<" written by "<<authorName[i]<<". ";
            cout<<"No. of Available Copies "<<availableCopies[i]<<".\n";
            check = false;
        }
    }
    if(check)
    {
        cout<<"No Books Available";
    }
}