#include <iostream>
#include <exception>

#ifdef _WIN32
#include <windows.h>    // for win32 API functions
#include <io.h>         // for _get_osfhandle()
#else
#ifndef _POSIX_SOURCE
#define _POSIX_SOURCE   // enable POSIX extensions in standard library headers
#endif
#include <unistd.h>     // for isatty()
#endif

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>


#define TERMINATOR '\0'


using namespace std;



typedef struct Employee{
	string name;
	int code;
	int salary;
}Employee;


class Stack{
private:
    int top;
    int size;
    Employee *emp;
    static int counter;
public:
    Stack(int size){
        this->size=size;
        top=-1;
        emp=new Employee[size];
        counter++;
    }
    ///////////////////////////////////
    ~Stack(){
        delete[] emp;
    }
    ///////////////////////////////////
    int push(Employee employee){
        if(top==size-1)
        {
            return 0;
        }
        top++;
        emp[top].code=employee.code;
        emp[top].name=employee.name;
        emp[top].salary=employee.salary;
        return 1;
    }
    ////////////////////////////////////
    Employee pop()
    {
        if(top==-1)
        {
            throw exception();
        }
        Employee data=emp[top];
        top--;
        return data;
    }
    ////////////////////////////////////
    int display()
    {
        if(top==-1){
           return 0;
        }
        else
        {
            for(int i=0;i<=top;i++)
            {
                cout<<"Employee number"<<i+1<<": \n";
                cout<<"code:"<<emp[i].code<<"\t name:"<<emp[i].name<<"\t salary:"<<emp[i].salary<<endl;
            }
            return 1;
        }
    }
    ////////////////////////////////////
    Employee* getEmployees(){
        return emp;
    }
    ////////////////////////////////////
    int getTop(){
        return top;
    }
};

int Stack::counter=0;


// use an enum for platform-independent interface:
typedef enum TextColor
{
    TC_BLACK = 0,
    TC_BLUE = 1,
    TC_GREEN = 2,
    TC_CYAN = 3,
    TC_RED = 4,
    TC_MAGENTA = 5,
    TC_BROWN = 6,
    TC_LIGHTGRAY = 7,
    TC_DARKGRAY = 8,
    TC_LIGHTBLUE = 9,
    TC_LIGHTGREEN = 10,
    TC_LIGHTCYAN = 11,
    TC_LIGHTRED = 12,
    TC_LIGHTMAGENTA = 13,
    TC_YELLOW = 14,
    TC_WHITE = 15
} TextColor;

// set output color on the given stream:
void setTextColor(FILE *stream, TextColor color);

void gotoxy(int,int);
int pushEmployee(Stack &);
void popEmployee(Stack &);


int main()
{
    setTextColor(stdout,TC_BROWN); // Light BROWN color as a default

    cout<<"please enter Stack size:";
    int size;
    cin>>size;
    if(size<1){
        cout<<"this is not valid size";
        return 0;
    }
    Stack s(size);
    system("cls");


    int employeesCreated=0;
    int flag=1,row=1,col=1;
    gotoxy(col*55,row*10);
    setTextColor(stdout,TC_YELLOW); // Light BROWN color as a default
    printf("Push Employee");
    gotoxy(col*55,(row*10)+4); //5
    setTextColor(stdout,TC_BROWN); // Light BROWN color as a default
    printf("Pop Employee");
    gotoxy(col*55,(row*10)+8); //9
    printf("Display Employees");
    gotoxy(col*55,(row*10)+12); //13
    printf("Exit");
    row=1;
    gotoxy(col*55,row*10);

    ////////////////////////////////////////////////////

    while(flag)
    {
        char click=0;
        click=getch();
        if(click==-32) // extended keys
        {
            click=getch();
            if(click==72) // up
            {
                if(row==1) //first row
                {
                    row=13;
                }
                else
                {
                    row-=4;  // Move up
                }
            }
            else if(click==80) // down
            {
                if(row==13)
                {
                    row=1;
                }
                else
                {
                    row+=4;
                }
            }
            else if(click==71) // home button
            {
                row=1;  //will go to new
            }
            else if(click==79) // end button
            {
                row=13;  //will go to exit
            }
            //going to the place i chose (up 2w down)
            if(row==1)
            {
                setTextColor(stdout,TC_YELLOW);
                system("cls");
                gotoxy(55,10);
                printf("Push Employee");
                setTextColor(stdout,TC_BROWN);
                gotoxy(55,15);
                printf("Pop Employee");
                gotoxy(55,19);
                printf("Display Employees");
                gotoxy(55,23);
                printf("Exit");

            }
            else if(row==5)
            {
                system("cls");
                setTextColor(stdout,TC_BROWN);
                gotoxy(55,10);
                printf("Push Employee");
                setTextColor(stdout,TC_YELLOW);
                gotoxy(55,15);
                printf("Pop Employee");
                setTextColor(stdout,TC_BROWN);
                gotoxy(55,19);
                printf("Display Employees");
                gotoxy(55,23);
                printf("Exit");

            }
            else if(row==9)
            {
                setTextColor(stdout,TC_BROWN);
                system("cls");
                gotoxy(55,10);
                printf("Push Employee");
                gotoxy(55,15);
                printf("Pop Employee");
                setTextColor(stdout,TC_YELLOW);
                gotoxy(55,19);
                printf("Display Employees");
                setTextColor(stdout,TC_BROWN);
                gotoxy(55,23);
                printf("Exit");
            }
            else if(row==13){
                setTextColor(stdout,TC_BROWN);
                system("cls");
                gotoxy(55,10);
                printf("Push Employee");
                gotoxy(55,15);
                printf("Pop Employee");
                gotoxy(55,19);
                printf("Display Employees");
                setTextColor(stdout,TC_YELLOW);
                gotoxy(55,23);
                printf("Exit");

            }
        }
        else if (click==13) // enter button
        {
            char choice;
            system("cls");
            setTextColor(stdout,TC_BROWN);
            if (row==1)  // push
            {
                int result=pushEmployee(s);
                if(result==1)
                {
                    setTextColor(stdout,TC_GREEN);
                    cout<<"\nyou inserted Employee into the stack successfully ";
                    flag=0;
                    setTextColor(stdout,TC_BROWN);
                }
                else if(result==0)
                {
                    setTextColor(stdout,TC_RED);
                    cout<<"\nStack is full ,Please Go POP an Employee First";
                    flag=0;
                    setTextColor(stdout,TC_BROWN);
                }
                row=1;
                Sleep(4000);
                choice=83;
            }
            else if(row==5) // pop
            {
                popEmployee(s);
                row=5;
                Sleep(4000);
                choice=83;
            }
            else if(row==9) // Display
            {
                if(!s.display())
                {
                    setTextColor(stdout,TC_RED);
                    cout<<"NO Employees Found"<<endl;
                    setTextColor(stdout,TC_BROWN);
                }
                row=9;
            }
            else // Exit
            {
                gotoxy(col*45,10);
                setTextColor(stdout,TC_LIGHTCYAN);
                printf("THANKS FOR TRYING MY PROGRAM!");
                setTextColor(stdout,TC_BROWN);
                Sleep(1500);
                gotoxy(col*45,13);
                //s.~Stack();
                return 0;
            }





            if(choice==83 || row==9) //delete button on keyboard
            {
                if(row==1)
                {
                    setTextColor(stdout,TC_YELLOW);
                    system("cls");
                    gotoxy(55,10);
                    printf("Push Employee");
                    setTextColor(stdout,TC_BROWN);
                    gotoxy(55,15);
                    printf("Pop Employee");
                    gotoxy(55,19);
                    printf("Display Employees");
                    gotoxy(55,23);
                    printf("Exit");
                    flag=1;
                }
                else if(row==5)
                {
                    system("cls");
                    setTextColor(stdout,TC_BROWN);
                    gotoxy(55,10);
                    printf("Push Employee");
                    setTextColor(stdout,TC_YELLOW);
                    gotoxy(55,15);
                    printf("Pop Employee");
                    setTextColor(stdout,TC_BROWN);
                    gotoxy(55,19);
                    printf("Display Employees");
                    gotoxy(55,23);
                    printf("Exit");
                }
                else if(row==9)
                {
                    char click;
                    click=getch();

                    setTextColor(stdout,TC_BROWN);
                    system("cls");
                    gotoxy(55,10);
                    printf("Push Employee");
                    gotoxy(55,15);
                    printf("Pop Employee");
                    setTextColor(stdout,TC_YELLOW);
                    gotoxy(55,19);
                    printf("Display Employees");
                    setTextColor(stdout,TC_BROWN);
                    gotoxy(55,23);
                    printf("Exit");
                }
            }
        }
        else if(click==8) //backspace button
        {
            flag=0;
        }
    }
     return EXIT_SUCCESS;
}

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X= x ;
    coord.Y = y ;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
////////////////////////////////////////////////////////////////////////
int isValidName(string name) {
    char flag=1;
    for (int i = 0; name[i] != TERMINATOR && flag; i++) {
        if (!((name[i] >= 'A' && name[i] <= 'Z') || (name[i] >= '0' && name[i] <= '9') || (name[i] >= 'a' && name[i] <= 'z') || name[i] == ' ')) {
            flag= 0;
        }
    }
    return flag;
}

///////////////////////////////////////////////////////////////////////
int pushEmployee(Stack &stackk)
{

    Employee employee;
    Employee * employees=stackk.getEmployees();

    char check;


    int intSalaryChecker=1,intCodeChecker=1;
    cout<<"\nplease enter Employee's code: ";
    while(intCodeChecker)
     {
        int num=0;
        if((scanf("%d%c",&num,&check)==2 && check=='\n'))
        {
            if(num<=0)
            {
                cout<<"\nplease enter a positive number of code: ";
                fflush(stdin);
            }
            else
            {
                int isUnique=1;
                for(int j=0;j<stackk.getTop() && isUnique ;j++){
                    if(employees[j].code==num)
                    {
                        isUnique=0;
                        cout<<"\nThis code is already taken,please enter another one: ";
                    }
                }
                if(isUnique)
                {
                    employee.code=num;
                    intCodeChecker=0;
                }
                else
                {
                    fflush(stdin);
                }
            }
        }
        else
        {
            cout<<"\nplease enter only numbers for code: ";
            fflush(stdin);
        }
    }
    int valid=0;
    do {
        cout<<"Please enter Employee's name: ";
        cin>>employee.name;
        valid = isValidName(employee.name);

        if (!valid)
        {
            cout<<"Invalid name,Please use only alphabetic characters and numbers.\n";
        }
    } while (!valid);


     cout<<"please enter Employee's salary: ";
     while(intSalaryChecker)
    {
            if((scanf("%d%c", &employee.salary, &check)==2 && check=='\n')){
                if(employee.salary<=0){
                    cout<<"\nplease enter a positive number of salary: ";
                     fflush(stdin);
                }
                else{
                    intSalaryChecker=0;
                }
            }
            else{
                cout<<"\nplease enter only numbers for salary: ";
                fflush(stdin);
            }
    }
    int result=stackk.push(employee);
    return result;

}

//////////////////////////////////////////////////////////////////////
void popEmployee(Stack &stackk){

   try
    {
        Employee emp;
        emp=stackk.pop();
        cout<<"Employee Data:"<<endl;
        cout<<"code:"<<emp.code<<"\t name:"<<emp.name<<"\t salary:"<<emp.salary<<endl;

        setTextColor(stdout,TC_GREEN);
        cout<<"\nEmployee is popped out Successfully"<<endl;
        setTextColor(stdout,TC_BROWN);
    }
    catch(exception& e)
    {
        setTextColor(stdout,TC_RED);
        cout<<"the stack is already empty"<<endl;
        setTextColor(stdout,TC_BROWN);
    }
}










#ifdef _WIN32

void setTextColor(FILE *stream, TextColor color)
{
    int outfd = fileno(stream);
    HANDLE out = (HANDLE)_get_osfhandle(outfd);
    DWORD outType = GetFileType(out);
    DWORD mode;
    if (outType == FILE_TYPE_CHAR && GetConsoleMode(out, &mode))
    {
        // we're directly outputting to a win32 console if the file type
        // is FILE_TYPE_CHAR and GetConsoleMode() returns success

        SetConsoleTextAttribute(out, color);
        // the enum constants are defined to the same values
        // SetConsoleTextAttribute() uses, so just pass on.
    }
}

#else

static const char *ansiColorSequences[] =
{
    "\x1B[0;30m",
    "\x1B[0;34m",
    "\x1B[0;32m",
    "\x1B[0;36m",
    "\x1B[0;31m",
    "\x1B[0;35m",
    "\x1B[0;33m",
    "\x1B[0;37m",
    "\x1B[1;30m",
    "\x1B[1;34m",
    "\x1B[1;32m",
    "\x1B[1;36m",
    "\x1B[1;31m",
    "\x1B[1;35m",
    "\x1B[1;33m",
    "\x1B[1;37m"
};

static const char *ansiColorTerms[] =
{
    "xterm",
    "rxvt",
    "vt100",
    "linux",
    "screen",
    0
    // there are probably missing a few others
};

// get current terminal and check whether it's in our list of terminals
// supporting ANSI colors:
static int isAnsiColorTerm(void)
{
    char *term = getenv("TERM");
    for (const char **ansiTerm = &ansiColorTerms[0]; *ansiTerm; ++ansiTerm)
    {
        int match = 1;
        const char *t = term;
        const char *a = *ansiTerm;
        while (*a && *t)
        {
            if (*a++ != *t++)
            {
                match = 0;
                break;
            }
        }
        if (match) return 1;
    }
    return 0;
}

void setTextColor(FILE *stream, TextColor color)
{
    int outfd = fileno(stream);
    if (isatty(outfd) && isAnsiColorTerm())
    {
        // we're directly outputting to a terminal supporting ANSI colors,
        // so send the appropriate sequence:
        fputs(ansiColorSequences[color], stream);
    }
}

#endif

