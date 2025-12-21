#include<iostream>
using namespace std;

string password[10];
string admin[10];
string studentPassword[10];
string studentId[10];

//--------------------FUNCTION DECLARATION--------------------
void showlogInPage();
void showSigUpPage();
void showMainMenuPage();
void showAdminAuthenticationPage();
void showStudentAuthenticationPage();


void signIn(string password[], string admin[] );
int signUp(string password[],string admin[],int &count);
void studentSignIn(string studentPassword[], string studentId[]);
int studentSignUp(string studentPassword[],string studentId[], int &count1);
void mainMenu(int &count, int &count1);
void adminAuthenticationMenu(int &count);
void studentAuthenticationMenu(int &count1);




//----------------------Main----------------------
int main()
{
    int count = 0, count1 = 0;

    password[0] = "1234";
    admin[0] = "admin";

    studentPassword[0] = "4321";
    studentId[0] = "student";

    mainMenu(count, count1); 
     
    return 0;
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

//--------------------Admin Menu Page--------------------
void showAdminAuthenticationPage()
{
    cout<<"\n-----------------------------\n";
    cout<<"         Admin Menu\n";
    cout<<"-----------------------------\n";
    cout<<"1. Sign In.\n";
    cout<<"2. Sign Up.\n";
    cout<<"3. Exit.\n";
}

//--------------------Student Menu Page--------------------
void showStudentAuthenticationPage()
{
    cout<<"\n-----------------------------\n";
    cout<<"         Student Menu\n";
    cout<<"-----------------------------\n";
    cout<<"1. Sign In.\n";
    cout<<"2. Sign Up.\n";
    cout<<"3. Exit.\n";
}

//------------------USER SIGN IN-------------------
void studentSignIn(string studentPassword[], string studentId[])
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
int studentSignUp(string studentPassword[],string studentId[], int &count1)
{
    count1++;

    showSigUpPage();

    cout<<"Enter User Name:";
    cin.ignore();
    getline(cin,studentId[count1]);

    cout<<"Enter password:";
    cin>>studentPassword[count1];  

    cout<<"Signed Up Successfully!\n";

    return count1;
    
}


//------------------ADMIN SIGN IN-------------------
void signIn(string password[], string admin[] )
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

        for(int i =0; i<10; i++)
        {
            if(pass == password[i] && user == admin[i])
            {
                cout<<"Login Successful!\n";
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
int signUp(string password[],string admin[],int &count)
{
    count++;

    showSigUpPage();

    cout<<"Enter User Name:";
    cin.ignore();
    getline(cin,admin[count]);

    cout<<"Enter password:";
    cin>>password[count];  

    cout<<"Signed Up Successfully!\n";

    return count;
    
}

//----------------------MENU----------------------
void mainMenu(int &count, int &count1)
{
    while(true)
    {
        string i;

        showMainMenuPage();

        cout<<"Enter Your Choice: ";
        cin>>i;

        if(i == "1")
        {
            adminAuthenticationMenu(count);
        }

        else if(i == "2")
        {
            studentAuthenticationMenu(count1);
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

//----------------------ADMIN MENU----------------------
void adminAuthenticationMenu(int &count)
{
    while(true)
    {
        string i;

        showAdminAuthenticationPage();

        cout<<"Enter Your Choice: ";
        cin>>i;

        if(i == "1")
        {
            signIn(password, admin);
        }

        else if(i == "2")
        {
            signUp(password,admin, count);
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

//----------------------STUDENT MENU----------------------
void studentAuthenticationMenu(int &count1)
{
    while(true)
    {
        string i;

        showStudentAuthenticationPage();

        cout<<"Enter Your Choice: ";
        cin>>i;

        if(i == "1")
        {
            studentSignIn(studentPassword, studentId);
        }

        else if(i == "2")
        {
            studentSignUp(studentPassword,studentId, count1);
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

