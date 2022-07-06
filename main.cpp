#include <bits/stdc++.h>
using namespace std;

class user
{
        public:
                string name;
                string uid;
                string password;
                string level;
};
vector <user> userDB;
class userData{
    public:
        userData(){
                ifstream inp;
                string data;
                inp.open("./UserData.csv");

                user item;
                while(getline(inp,data, ',')){
                        item.name = data;
                        getline(inp,data, ',');
                        item.uid = data;
                        getline(inp,data, ',');
                        item.password = data;
                        getline(inp,data, '\n');
                        item.level = data;

                        userDB.push_back(item);
                }
                inp.close();
        };
        ~userData(){
                ofstream onp;
                string data = "";
                onp.open("./userData.csv");
                for(int i=0; i<userDB.size(); i++){
                        onp << userDB[i].name << "," << userDB[i].uid << "," << userDB[i].password << "," << userDB[i].level << "\n";
                }
                onp.close();
        };
        void Add(){
                string wait;
                user addUser;
                cout << "Enter the New Username\n";
                cin >> addUser.name;
                cout << "Enter the UID of User\n";
                cin >> addUser.uid;
                cout << "Enter the password\n";
                cin >> addUser.password;
                cout << "Enter the Level 0f User\n";
                cin >> addUser.level;

                userDB.push_back(addUser);
                cout << "New User has been added to the Database\n";
                cout << "Press any key to exit\n";
                cin >> wait;
        };
        void Update(){
                string checkUID;
                cout << "Enter the UID\n";
                cin >> checkUID;
                auto it = find_if(userDB.begin(), userDB.end(), [&checkUID](const user& obj) {return obj.uid == checkUID;});
                if(it != userDB.end()){
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << "Update the UID(if required)\n";
                        if (cin.peek() != '\n')
                                cin >> (*it).uid;
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << "Update the Name(if required)\n";
                        if (cin.peek() != '\n')
                                cin >> (*it).name;
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << "Update the password(if required)\n";
                        if (cin.peek() != '\n')
                                cin >> (*it).password;
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                else{
                        cout << "User not found and can't be updated! :(\n";
                }
        };
        void Delete(){
                string checkTitle;
                cout << "Enter the UID\n";
                cin >> checkTitle;
                auto it = find_if(userDB.begin(), userDB.end(), [&checkTitle](const user& obj) {return obj.uid == checkTitle;});
                if(it != userDB.end()){
                        userDB.erase(it);
                        cout << "User is Deleted\n\n";
                }
                else{
                        cout << "User not found and cannot be deletd! :(\n";
                }
        };
        void Search(){
                string checkUID;
                cout << "Enter your UID\n";
                cin >> checkUID;
                auto it = find_if(userDB.begin(), userDB.end(), [&checkUID](const user& obj) {return obj.uid == checkUID;});
                if(it != userDB.end()){
                        cout << "User found! :)\n\n";
                        cout << "UID : " << (*it).uid << "\n";
                        cout << "Name : " << (*it).name << "\n";
                }
                else{
                        cout << "User not found! :(\n";
                }
        };
};

class book
{
        public:
        string title;
        string author;
        string isbn;
        string publication;

        string current_user;
        string due_time;

        string Show_duedate(int d){
                time_t due_date = time(0);
                due_date = due_date + 3600*24*30*(d-1);
                tm abc = *localtime(&due_date);
                string duedate = "";
                duedate += to_string(abc.tm_mday) + "/" + to_string(abc.tm_mon+1) + "/" + to_string(abc.tm_year+1900);
                return duedate;
        };
};
vector <book> bookDB;
class bookData{
        
    public:
        bookData(){
                ifstream inp;
                string data;
                inp.open("./BookData.csv");

                book item;
                while(getline(inp,data, ',')){
                        item.title = data;
                        getline(inp,data, ',');
                        item.author = data;
                        getline(inp,data, ',');
                        item.isbn = data;
                        getline(inp,data, ',');
                        item.publication = data;
                        getline(inp,data, ',');
                        item.current_user = data;
                        getline(inp,data, '\n');
                        item.due_time = data;

                        bookDB.push_back(item);
                }
                inp.close();
        };
        ~bookData(){
                ofstream onp;
                string data = "";
                onp.open("./BookData.csv");
                for(int i=0; i<bookDB.size(); i++){
                        onp << bookDB[i].title << "," << bookDB[i].author << "," << bookDB[i].isbn << "," << bookDB[i].publication << "," << bookDB[i].current_user << "," << bookDB[i].due_time << "\n";
                }
                onp.close();
        };
        void Add(){
                string wait;
                book addBook;
                cout << "Enter the Title of Book\n";
                cin >> addBook.title;
                cout << "Enter the Author of Book\n";
                cin >> addBook.author;
                cout << "Enter the ISBN of Book\n";
                cin >> addBook.isbn;
                cout << "Enter the Publication of Book\n";
                cin >> addBook.publication;

                bookDB.push_back(addBook);
                cout << "Book has been added to the Database\n";
                cout << "Press any key to exit\n";
                cin >> wait;
        };
        void Update(){
                string checkTitle,wait;
                cout << "Enter the Title of Book\n";
                cin >> checkTitle;
                auto it = find_if(bookDB.begin(), bookDB.end(), [&checkTitle](const book& obj) {return obj.title == checkTitle;});
                if(it != bookDB.end()){
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << "Update the Title of Book(if required)\n";
                        if (cin.peek() != '\n')
                                cin >> (*it).title;
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << "Update the Author of Book(if required)\n";
                        if (cin.peek() != '\n')
                                cin >> (*it).author;
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << "Update the ISBN of Book(if required)\n";
                        if (cin.peek() != '\n')
                                cin >> (*it).isbn;
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << "Update the Publication of Book(if required)\n";
                        if (cin.peek() != '\n')
                                cin >> (*it).publication;
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                else{
                        cout << "Book not found and cannot be deletd! :(\n";
                }
                cout << "Press any key to exit\n";
                cin >> wait;
        };
        void Delete(){
                string checkTitle,wait;
                cout << "Enter the Title of Book\n";
                cin >> checkTitle;
                auto it = find_if(bookDB.begin(), bookDB.end(), [&checkTitle](const book& obj) {return obj.title == checkTitle;});
                if(it != bookDB.end()){
                        bookDB.erase(it);
                        cout << "Book is Deleted\n\n";
                }
                else{
                        cout << "Book not found and cannot be deletd! :(\n";
                }
                cout << "Press any key to exit\n";
                cin >> wait;
        };
        void Search(){
                string checkTitle,wait;
                cout << "Enter the Title of Book\n";
                cin >> checkTitle;
                auto it = find_if(bookDB.begin(), bookDB.end(), [&checkTitle](const book& obj) {return obj.title == checkTitle;});
                if(it != bookDB.end()){
                        cout << "A Book is found! :)\n\n";
                        cout << "Title : " << (*it).title << "\n";
                        cout << "Author : " << (*it).author << "\n";
                        cout << "ISBN : " << (*it).isbn << "\n";
                        cout << "Publication : " << (*it).publication << "\n";
                }
                else{
                        cout << "Book not found! :(\n";
                }
                cout << "Press any key to exit\n";
                cin >> wait;
        };
        void userCheck(){
                string checkTitle,wait;
                cout << "Enter the Title of Book\n";
                cin >> checkTitle;
                auto it = find_if(bookDB.begin(), bookDB.end(), [&checkTitle](const book& obj) {return obj.title == checkTitle;});
                if(it != bookDB.end()){
                        if((*it).current_user==""){
                                cout << "Book is not issued to anyone" << endl;
                        }
                        else{
                                cout << "Book has been issued to:" << (*it).current_user << endl;
                        }
                }
                else{
                        cout << "Book not found! :(\n";
                }
                cout << "Press any key to exit\n";
                cin >> wait;
        }
};

void Display_book(){
        char a;
        for(int i=0; i<bookDB.size(); i++){
                        cout << i+1 << ". " << bookDB[i].title << endl;
        }
        cout << "Press any key to exit\n";
        cin >> a;
};
void Display_user(){
        char a;
        for(int i=0; i<userDB.size(); i++){
                        cout << userDB[i].uid << "-----" << userDB[i].name << endl;
        }
        cout << "Press any key to exit\n";
        cin >> a;
};
bookData Books;
userData testUser;
void BooklistCheck(){
                string name,wait;
                int i=1;
                cout << "Enter User Name" << endl;
                cin >> name;
                for(auto it = bookDB.begin(); it != bookDB.end(); it++){
                        if((*it).current_user==name){
                                cout << i << '.' << (*it).title << endl;
                        }
                }
                cout << "Press any key to exit\n";
                cin >> wait;
        };
void Welcome();
class Student:public user
{
    public:
    vector <book> BookList;
        Student(string x){
                name = x;
                
                for(auto it = bookDB.begin(); it != bookDB.end(); it++){
                        if((*it).current_user==name){
                                BookList.push_back(*it);
                        }
                }
        };
        void Issue_request(){
                string checkTitle;
                cout << "Enter the name of book you want to Issue" << endl;
                cin >> checkTitle;
                auto it = find_if(bookDB.begin(), bookDB.end(), [&checkTitle](const book& obj) {return obj.title == checkTitle;});
                if(BookList.size()==5){
                        cout << "You can't issue more than 5 books at a time.\n";
                }
                else if(it==bookDB.end()){
                        cout << "Book doesn't exist.\n";
                }
                else if((*it).current_user != ""){
                        cout << "Book has already been issued.\n";
                }
                else{
                        (*it).current_user = name;
                        string testname = name;
                        auto rt = find_if(userDB.begin(), userDB.end(), [&testname](const user& obj) {return obj.name == testname;});
                        (*it).due_time = (*it).Show_duedate(stoi((*rt).level));
                        BookList.push_back(*it);
                        cout << "Book has been issued to you.\n";
                }
                cout << "Press any key to exit\n";
                cin >> checkTitle;
        };
        void print_booklist(){
                string wait;
                for(int i=0; i<BookList.size(); i++){
                        cout << i+1 << "." << BookList[i].title << "------" << "Due Date-" << BookList[i].due_time << endl;
                }
                cout << "Press any key to exit\n";
                cin >> wait;
        };
        void Display_due(){
                string checkTitle,wait;
                cout << "Enter the book for due" << endl;
                cin >> checkTitle;
                auto it = find_if(BookList.begin(), BookList.end(), [&checkTitle](const book& obj) {return obj.title == checkTitle;});
                if(it != bookDB.end()){
                        cout << (*it).due_time << endl;
                }
                else{
                        cout << "Book not found! :(\n";
                }
                cout << "Press any key to exit\n";
                cin >> wait;
        };
        void fine(int d,int m,int y,int dd,int mm,int yy)
                {
                long int n1,n2;
                int years,l,i;
                const int monthDays[12] = {31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31};
                n1 = y*365 + d;
                for (i=0; i<m - 1; i++)
                        n1 += monthDays[i]; //fn1353
                years = y;
                if (m <= 2)
                years--;
                l= years / 4 - years / 100 + years / 400;
                n1 += l;
                n2 = yy*365 + dd;
                for (i=0; i<mm - 1; i++)
                        n2 += monthDays[i];
                years = yy;
                if (m <= 2)
                years--;
                l= years / 4 - years / 100 + years / 400;
                n2 += l;
                n1=n2-n1;
                n2 = n1;
                if(n2>0){
                cout<<"\n\t\tThe Total Fine is : "<<n2*2 << endl;
                }
                else {cout<<"No fine overdue" << endl;}
                }
        void Calculate_fine(){
                int d,m,y,dd,mm,yy;
                string checkTitle,wait;
                cout << "Enter the book for fine" << endl;
                cin >> checkTitle;
                auto it = find_if(BookList.begin(), BookList.end(), [&checkTitle](const book& obj) {return obj.title == checkTitle;});
                if(it != bookDB.end()){
                        istringstream ss((*it).due_time);
                        string token;
                        getline(ss,token, '/');
                        d = stoi(token);
                        getline(ss,token, '/');
                        m = stoi(token);
                        getline(ss,token);
                        y = stoi(token);
                        time_t timenow = time(0);
                        tm nw = *localtime(&timenow);
                        fine(d,m,y,nw.tm_mday,nw.tm_mon+1,nw.tm_year+1900);
                }
                else{
                        cout << "Book not found! :(\n";
                }
                cout << "Press any key to exit\n";
                cin >> wait;
        };
        void Clear_fine_amount(){
                string checkTitle,wait;
                cout << "Enter the book for returning" << endl;
                cin >> checkTitle;
                auto it = find_if(BookList.begin(), BookList.end(), [&checkTitle](const book& obj) {return obj.title == checkTitle;});
                if(it != bookDB.end()){
                        BookList.erase(it);
                        auto rt = find_if(bookDB.begin(), bookDB.end(), [&checkTitle](const book& obj) {return obj.title == checkTitle;});
                        (*rt).current_user = "";
                        (*rt).due_time = "";
                        cout << "Book has been Returned" << endl;
                }
                else{
                        cout << "Book not found! :(\n";
                }
                cout << "Press any key to exit\n";
                cin >> wait;
        };
        void page(){
                system("cls");
                int i;
                cout<<"\n\t*********** LIBRARY MANAGEMENT SYSTEM ***********\n"<<"\n\t\t\t    L M S C++\n";
                cout<<"\n\t\tWELCOME\t" << name << ":STUDENT USER PAGE";
                cout<<"\n\t\t1.Display all Books\n\n\t\t2.Display your Issued Books\n\n\t\t3.Request to Issue book\n\n\t\t4.Calculate your Fine amount\n\n\t\t5.Display Due Date\n\n\t\t6.Clear Fine amount\n\n\t\t7.Logout\n";
                cout<<"\n\t\tEnter your choice : ";
                cin >> i;
                switch (i)
                {
                        case 1:
                                Display_book();
                                page();
                                break;
                        case 2:
                                print_booklist();
                                page();
                                break;
                        case 3:
                                Issue_request();
                                page();
                                break;
                        case 4:
                                Calculate_fine();
                                page();
                                break;
                        case 5:
                                Display_due();
                                page();
                                break;
                        case 6:
                                Clear_fine_amount();
                                page();
                                break;
                        case 7:
                                system("cls");
                                Welcome();
                                break;
                        default:
                                page();
                }
        };
};

class Professor:public user
{
        public:
    int Fine_amount;
    vector <book> BookList;
        Professor(string x){
                name = x;
                
                for(auto it = bookDB.begin(); it != bookDB.end(); it++){
                        if((*it).current_user==name){
                                BookList.push_back(*it);
                        }
                }
        };
        void Issue_request(){
                string checkTitle;
                cout << "Enter the name of book you want to Issue" << endl;
                cin >> checkTitle;
                auto it = find_if(bookDB.begin(), bookDB.end(), [&checkTitle](const book& obj) {return obj.title == checkTitle;});
                if(it==bookDB.end()){
                        cout << "Book doesn't exist.\n";
                }
                else if((*it).current_user != ""){
                        cout << "Book has already been issued.\n";
                }
                else{
                        (*it).current_user = name;
                        string testname = name;
                        auto rt = find_if(userDB.begin(), userDB.end(), [&testname](const user& obj) {return obj.name == testname;});
                        (*it).due_time = (*it).Show_duedate(stoi((*rt).level));
                        BookList.push_back(*it);
                        cout << "Book has been issued to you.\n";
                }
                cout << "Press any key to exit\n";
                cin >> checkTitle;
        };
        void print_booklist(){
                string wait;
                for(int i=0; i<BookList.size(); i++){
                        cout << i+1 << "." << BookList[i].title << "------" << "Due Date-" << BookList[i].due_time << endl;
                }
                cout << "Press any key to exit\n";
                cin >> wait;
        };
        void Display_due(){
                string checkTitle,wait;
                cout << "Enter the book for due" << endl;
                cin >> checkTitle;
                auto it = find_if(BookList.begin(), BookList.end(), [&checkTitle](const book& obj) {return obj.title == checkTitle;});
                if(it != bookDB.end()){
                        cout << (*it).due_time << endl;
                }
                else{
                        cout << "Book not found! :(\n";
                }
                cout << "Press any key to exit\n";
                cin >> wait;
        };
        void fine(int d,int m,int y,int dd,int mm,int yy)
                {
                long int n1,n2;
                int years,l,i;
                const int monthDays[12] = {31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31};
                n1 = y*365 + d;
                for (i=0; i<m - 1; i++)
                        n1 += monthDays[i]; //fn1353
                years = y;
                if (m <= 2)
                years--;
                l= years / 4 - years / 100 + years / 400;
                n1 += l;
                n2 = yy*365 + dd;
                for (i=0; i<mm - 1; i++)
                        n2 += monthDays[i];
                years = yy;
                if (m <= 2)
                years--;
                l= years / 4 - years / 100 + years / 400;
                n2 += l;
                n1=n2-n1;
                n2 = n1;
                if(n2>0){
                cout<<"\n\t\tThe Total Fine is : "<<n2*5 << endl;
                }
                else {cout<<"No fine overdue" << endl;}
                }
        void Calculate_fine(){
                int d,m,y,dd,mm,yy;
                string checkTitle,wait;
                cout << "Enter the book for fine" << endl;
                cin >> checkTitle;
                auto it = find_if(BookList.begin(), BookList.end(), [&checkTitle](const book& obj) {return obj.title == checkTitle;});
                if(it != bookDB.end()){
                        istringstream ss((*it).due_time);
                        string token;
                        getline(ss,token, '/');
                        d = stoi(token);
                        getline(ss,token, '/');
                        m = stoi(token);
                        getline(ss,token);
                        y = stoi(token);
                        time_t timenow = time(0);
                        tm nw = *localtime(&timenow);
                        fine(d,m,y,nw.tm_mday,nw.tm_mon+1,nw.tm_year+1900);
                }
                else{
                        cout << "Book not found! :(\n";
                }
                cout << "Press any key to exit\n";
                cin >> wait;
        };
        void Clear_fine_amount(){
                string checkTitle,wait;
                cout << "Enter the book for returning" << endl;
                cin >> checkTitle;
                auto it = find_if(BookList.begin(), BookList.end(), [&checkTitle](const book& obj) {return obj.title == checkTitle;});
                if(it != bookDB.end()){
                        BookList.erase(it);
                        auto rt = find_if(bookDB.begin(), bookDB.end(), [&checkTitle](const book& obj) {return obj.title == checkTitle;});
                        (*rt).current_user = "";
                        (*rt).due_time = "";
                }
                else{
                        cout << "Book not found! :(\n";
                }
                cout << "Press any key to exit\n";
                cin >> wait;
        };
        void page2(){
                system("cls");
                int i;
                cout<<"\n\t*********** LIBRARY MANAGEMENT SYSTEM ***********\n"<<"\n\t\t\t    L M S C++\n";
                cout<<"\n\t\tWELCOME\t" << name << ":PROFESSOR USER PAGE";
                cout<<"\n\t\t1.Display all Books\n\n\t\t2.Display your Issued Books\n\n\t\t3.Request to Issue book\n\n\t\t4.Calculate your Fine amount\n\n\t\t5.Display Due Date\n\n\t\t6.Clear Fine amount\n\n\t\t7.Logout\n";
                cout<<"\n\t\tEnter your choice : ";
                cin >> i;
                switch (i)
                {
                        case 1:
                                Display_book();
                                page2();
                                break;
                        case 2:
                                print_booklist();
                                page2();
                                break;
                        case 3:
                                Issue_request();
                                page2();
                                break;
                        case 4:
                                Calculate_fine();
                                page2();
                                break;
                        case 5:
                                Display_due();
                                page2();
                                break;
                        case 6:
                                Clear_fine_amount();
                                page2();
                                break;
                        case 7:
                                system("cls");
                                Welcome();
                                break;
                        default:
                                page2();
                }
        };
};

class Librarian:public user
{
    public:
        void page1(){
                system("cls");
                int i;
                cout<<"\n\t*********** LIBRARY MANAGEMENT SYSTEM ***********\n"<<"\n\t\t\t    L M S C++\n";
                cout<<"\n\t\tWELCOME\t" << name << ":Librarian USER PAGE";
                cout<<"\n\t\t1.Display all Books\n\n\t\t2.Display all users\n\n\t\t3.Add new Book\n\n\t\t4.Update existing Book\n\n\t\t5.Delete existing Book\n\n\t\t6.Add new User\n\n\t\t7.Update existing User\n\n\t\t8.Delete existing User\n\n\t\t9.Check book issued to whom\n\n\t\t10.Check all book issued to particular user\n\n\t\t11.Logout\n";
                cout<<"\n\t\tEnter your choice : ";
                cin >> i;
                switch (i)
                {
                        case 1:
                                Display_book();
                                page1();
                                break;
                        case 2:
                                Display_user();
                                page1();
                                break;
                        case 3:
                                Books.Add();
                                page1();
                                break;
                        case 4:
                                Books.Update();
                                page1();
                                break;
                        case 5:
                                Books.Delete();
                                page1();
                                break;
                        case 6:
                                testUser.Add();
                                page1();
                                break;
                        case 7:
                                testUser.Update();
                                page1();
                                break;
                        case 8:
                                testUser.Delete();
                                page1();
                                break;
                        case 9:
                                Books.userCheck();
                                page1();
                                break;
                        case 10:
                                BooklistCheck();
                                page1();
                                break;
                        case 11:
                                system("cls");
                                Welcome();
                                break;
                        default:
                                page1();
                }
        }
};
void Login(){
        system("cls");
        cout<<"\n\t*********** LIBRARY MANAGEMENT SYSTEM ***********\n"<<"\n\t\t\t    L M S C++\n";
        cout<<"\n\t\tLOGIN PAGE\n";
        string loginUID,loginPass;
        cout<<"Enter your UID\n";
        cin>> loginUID;
        cout<<"Enter your Password\n";
        cin>> loginPass;
        auto it = find_if(userDB.begin(), userDB.end(), [&loginUID](const user& obj) {return obj.uid == loginUID;});
        if(it!=userDB.end()){
                int count=0;
                while(count<3){
                        if((*it).password==loginPass){
                                if((*it).level=="1"){
                                        cout << "Hey";
                                        Librarian result;
                                        result.uid = (*it).uid;
                                        result.name = (*it).name;
                                        result.password = (*it).password;
                                        result.level = (*it).level;
                                        result.page1();
                                }
                                else if((*it).level=="2"){
                                        Student result((*it).name);
                                        result.uid = (*it).uid;
                                        result.password = (*it).password;
                                        result.level = (*it).level;
                                        result.page();
                                }
                                else{
                                        Professor result((*it).name);
                                        result.uid = (*it).uid;
                                        result.name = (*it).name;
                                        result.password = (*it).password;
                                        result.level = (*it).level;
                                        result.page2();
                                }
                        }
                        else{
                                count++;
                                cout<<"\n\t\tPlease enter correct password:\n";
                                cin>>loginPass;
                        }
                }
                cout<<"3 wrong Attempts\n";
                return Login();
        }
        else{
                cout<<"\n\t\tPlease enter correct option :(";
                        
                        system("cls");
                        return Login();
        }
};
void Welcome(){
        int i;
        cout<<"\n\t*********** LIBRARY MANAGEMENT SYSTEM ***********\n"<<"\n\t\t\t    L M S C++\n";
        cout<<"\n\t\t1.Login\n\n\t\t2.Close App\n";
        cout<<"\n\t\tEnter your choice : ";
        cin >> i;
        switch(i){
                case 1:
                        Login();
                case 2:
                        exit(0);
                default:
                        cout<<"\n\t\tPlease enter correct option :(";
                        system("cls");
                        Welcome();
        }
}

int main(){
        
        
        // cout << bookDB[1].Show_duedate();
        Welcome();
        // bookData Books;
        // Books.Add();
        // Books.Delete();
        // Books.Search();
        // Books.Update();
        // Books.bookDB[1].Book_Request();
        // Books.bookDB[1].Show_duedate();

        return 0;
}