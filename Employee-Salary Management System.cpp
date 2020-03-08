#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;

class employee
{
public:

    int empid;
    char name[50];
    char lastname[50];
    float salary;
    char post[50];

public:

    void accept()
    {
        cout<<endl<<"Enter Employee ID: ";
        cin >> empid;
        cout<<endl<<"Enter Employee Name: ";
        cin >> name;
        cout<<endl<<"Enter Employee Last Name: ";
        cin >>lastname;
        cout<<endl<<"Enter Salary: ";
        cin >>salary;
        cout<<endl<<"Enter Post: ";
        cin >>post;
    }

    void display()
    {
        cout<<endl<<"Employee ID: "<<empid;
        cout<<endl<<"Employee Name: "<<name;
        cout<<endl<<"Employee Last Name: "<<lastname;
        cout<<endl<<"Salary: "<<salary;
        cout<<endl<<"Post: "<<post;
    }
};

employee obj;  //employee class global object!!!

class salary
{
private:

    int empid;
    float sal_given;

public:

    char month[50];
    char year[4];

    void accept()
    {
        cout<<endl<<"Enter Employee ID: ";
        cin>>empid;

        fstream rd;
        rd.open("E:\\project\\empdata.txt",ios::in);

        rd.seekg(0,ios::end);
        int n = rd.tellg();
        n = n/sizeof(obj);

        rd.seekg(0,ios::beg);
        for (int i = 1; i <= n; i++)
        {
            rd.read((char *)&obj, sizeof(obj));
            if(empid == obj.empid)
            {
                obj.display();
            }
        }
        cout<<endl<<"Enter Salary: ";
        cin>>sal_given;
        cout<<endl<<"Enter Month: ";
        cin>>month;
        cout<<endl<<"Enter Year: ";
        cin>>year;
    }

    int digit(int n)
    {
        int count=0;
        while(n!=0)
            {
                n=n/10;
                count++;
            }
        return count;
    }


    void display()
    {
        cout<<endl<<empid<<"\t\t   ";
        cout<<sal_given;
        int p=digit(sal_given);
        for(int i=1;i<=(11-p);i++)
            {
                cout<<" ";
            }
        cout<<"\t"<<month<<"\t"<<year;
    }
};

salary salobj; //salary class global object!!!

    void addemployee()
    {
        obj.accept();

        fstream wr;
        wr.open("E:\\project\\empdata.txt",ios::app);
        wr.write((char *)&obj, sizeof(obj));
        cout<<endl<<"Data written to file";
    }

    void showallemp()
    {
        fstream rd;
        rd.open("E:\\project\\empdata.txt",ios::in);

        rd.seekg(0,ios::end);
        int n = rd.tellg();
        n = n/sizeof(obj);

        rd.seekg(0,ios::beg);
        for(int i = 1; i <= n; i++)
        {
            rd.read((char *)&obj, sizeof(obj));
            obj.display();
            cout<<endl<<"***********************************************************"<<endl;
        }
    }

    void searchbyempid()
    {
        fstream rd;
        rd.open("E:\\project\\empdata.txt",ios::in);
        int sr;
        cout<<endl<<"Enter Employee ID to be searched: ";
        cin>>sr;
        rd.seekg(0,ios::end);
        int n = rd.tellg();
        int x = 0;
        n = n/sizeof(obj);
        rd.seekg(0,ios::beg);
        for(int i = 1; i <= n; i++)
        {
            rd.read((char *)&obj, sizeof(obj));
            if(obj.empid == sr)
            {
                x = 1;
                break;
            }
        }
        if(x == 1)
        {
            obj.display();
            cout<<endl<<"**************************************************";
        }
        else
        {
            cout<<"Enter Valid Employee ID!!!";
        }
    }

    void searchbyname()
    {
        fstream rd;
        rd.open("E:\\project\\empdata.txt",ios::in);
        char sr[50];
        cout<<endl<<"Enter Employee Name to be searched: ";
        cin>>sr;
        rd.seekg(0,ios::end);
        int n = rd.tellg();
        int x = 0;
        n = n/sizeof(obj);
        rd.seekg(0,ios::beg);
        for(int i = 1; i <= n; i++)
        {
            rd.read((char *)&obj, sizeof(obj));
            if(stricmp(obj.name,sr)==0)
            {
                x = 1;
                break;
            }
        }
        if(x == 1)
        {
            obj.display();
            cout<<endl<<"**************************************************";
        }
        else
        {
            cout<<"Enter Valid Employee Name!!!";
        }
    }

    void searchbylastname()
    {
        fstream rd;
        rd.open("E:\\project\\empdata.txt",ios::in);
        char sr[50];
        cout<<endl<<"Enter Employee Last Name to be searched: ";
        cin>>sr;
        rd.seekg(0,ios::end);
        int n = rd.tellg();
        int x = 0;
        n = n/sizeof(obj);
        rd.seekg(0,ios::beg);
        for(int i = 1; i <= n; i++)
        {
            rd.read((char *)&obj, sizeof(obj));
            if(stricmp(obj.lastname,sr)==0)
            {
                x = 1;
                break;
            }
        }
        if(x == 1)
        {
            obj.display();
            cout<<endl<<"**************************************************";
        }
        else
        {
            cout<<"Enter Valid Employee Last Name!!!";
        }
    }

     void searchbysalary()
    {
        fstream rd;
        rd.open("E:\\project\\empdata.txt",ios::in);
        float sr;
        cout<<endl<<"Enter Employee Salary to be searched: ";
        cin>>sr;
        rd.seekg(0,ios::end);
        int n = rd.tellg();
        int x = 0;
        n = n/sizeof(obj);
        rd.seekg(0,ios::beg);
        for(int i = 1; i <= n; i++)
        {
            rd.read((char *)&obj, sizeof(obj));
            if(obj.salary == sr)
            {
                x = 1;
                break;
            }
        }
        if(x == 1)
        {
            obj.display();
            cout<<endl<<"**************************************************";
        }
        else
        {
            cout<<"Enter Valid Employee Salary!!!";
        }
    }

    void searchbypost()
    {
        fstream rd;
        rd.open("E:\\project\\empdata.txt",ios::in);
        char sr[50];
        cout<<endl<<"Enter Employee Post to be searched: ";
        cin>>sr;
        rd.seekg(0,ios::end);
        int n = rd.tellg();
        int x = 0;
        n = n/sizeof(obj);
        rd.seekg(0,ios::beg);
        for(int i = 1; i <= n; i++)
        {
            rd.read((char *)&obj, sizeof(obj));
            if(stricmp(obj.post,sr)==0)
            {
                x = 1;
                break;
            }
        }
        if(x == 1)
        {
            obj.display();
            cout<<endl<<"**************************************************";
        }
        else
        {
            cout<<"Enter Valid Employee Post!!!";
        }
    }

    void removeemp()
    {
        fstream rd,wr;
        rd.open("E:\\project\\empdata.txt",ios::in);
        wr.open("E:\\project\\empdata_temp.txt",ios::out);
        int sr;
        cout<<endl<<"Enter Employee ID: ";
        cin>>sr;

        rd.seekg(0,ios::end);
        int n = rd.tellg();
        n = n/sizeof(obj);

        rd.seekg(0,ios::beg);
        for(int i = 1; i <= n; i++)
        {
            rd.read((char *)&obj, sizeof(obj));
            if(obj.empid == sr)
                {
                    cout<<endl<<"Employee Removed"<<endl;
                }
            else
                {
                    wr.write((char *)&obj,sizeof(obj));
                }
        }
        rd.close();
        wr.close();
        remove("E:\\project\\empdata.txt");
        rename("E:\\project\\empdata_temp.txt","E:\\project\\empdata.txt");
    }

    void updateemp()
    {
        fstream rd,wr;
        rd.open("E:\\project\\empdata.txt",ios::in);
        wr.open("E:\\project\\empdata_temp.txt",ios::out);

        int sr;
        cout<<endl<<"Enter Employee ID to be updated";
        cin>>sr;

        rd.seekg(0,ios::end);
        int n=rd.tellg();
        n=n/sizeof(obj);

        rd.seekg(0,ios::beg);
        for(int i=1;i<=n;i++)
            {
                rd.read((char *)&obj,sizeof(obj));
        if(obj.empid==sr)
            {
                obj.accept();
                wr.write((char *)&obj,sizeof(obj));
            }
            else
                {
                    wr.write((char *)&obj,sizeof(obj));
                }
            }
        rd.close();
        wr.close();
        remove("E:\\project\\empdata.txt");
        rename("E:\\project\\empdata_temp.txt","E:\\project\\empdata.txt");
    }

    void dispensesalary()
    {
        salobj.accept();
        fstream wr;
        wr.open("E:\\project\\salary.txt",ios::app);
        wr.write((char *)&salobj,sizeof(salobj));
        cout<<endl<<"Salary Recorded";
    }

    void searchsalary()
    {
        fstream rd;
        rd.open("E:\\project\\salary.txt",ios::in);

        char m[50],y[50];
        cout<<endl<<"Enter Month ";
        cin>>m;
        cout<<endl<<"Enter Year ";
        cin>>y;
        cout<<endl<<"Employee ID\tGiven Salary\tMonth\tYear";
        cout<<endl<<"***************************************";
        rd.seekg(0,ios::end);
        int n=rd.tellg()/sizeof(salobj);
        rd.seekg(0,ios::beg);

        for(int i=1;i<=n;i++)
            {
                rd.read((char *)&salobj,sizeof(salobj));
                if(strcmp(salobj.month,m)==0 && strcmp(salobj.year,y)==0)
                    {
                        salobj.display();
                    }
            }
    }

    int main()
    {
        int e = 0;
        while(e!=1)
        {
            cout<<endl<<endl<<"                                          SYSTEM LOGIN MENU";
            cout<<endl<<endl<<endl<<endl<<"  Enter 1 for Admin Access  ";
            cout<<endl<<"  Enter 2 for Guest Access  ";
            cout<<endl<<"  Enter 3 to EXIT  ";
            int choice;
            cin>>choice;
            if(choice==1)
            {
                system("cls");
                START:
                cout<<endl<<endl<<"Enter Password for Admin Access :";
                char pass[30];
                int i = 0;
                char a;
                char b[30] = "password";
                for(i = 0;;)
                    {
                        a=getch();
                        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
                        {
                            pass[i] = a;
                            ++i;
                            cout<<"*";
                        }
                        if(a=='\b'&&i>=1)
                        {
                            cout<<"\b \b";
                            --i;
                        }
                        if(a=='\r')
                        {
                            pass[i]='\0';
                            break;
                        }
                    }
                    if(strcmp(pass,b)==0)
                    {
                        system("cls");
                        int t = 0;
                        while(t!=1)
                        {
                        cout<<endl<<"                                              Welcome to Admin Access!!!";
                        cout<<endl<<endl<<endl<<"  Enter 1 to Add Employee ";
                        cout<<endl<<"  Enter 2 to Show all Employees ";
                        cout<<endl<<"  Enter 3 to Search Employee ";
                        cout<<endl<<"  Enter 4 to Remove Employee ";
                        cout<<endl<<"  Enter 5 to Update Employee ";
                        cout<<endl<<"  Enter 6 to Dispense Salary ";
                        cout<<endl<<"  Enter 7 to Search Salary ";
                        cout<<endl<<"  Enter 8 to Log Out ";
                        cout<<endl<<"  Enter 9 to Exit ";
                        int c;
                        cin>>c;
                        switch(c)
                        {
                            case 1:
                                {
                                    system("cls");
                                    addemployee();
                                    break;
                                }
                            case 2:
                                {
                                    system("cls");
                                    showallemp();
                                    break;
                                }
                            case 3:
                                {
                                    system("cls");
                                    int l = 0;
                                    while(l!=1)
                                    {
                                    cout<<endl<<endl<<endl<<endl<<endl<<"  Enter 1 to Search by ID ";
                                    cout<<endl<<"  Enter 2 to Search by Name ";
                                    cout<<endl<<"  Enter 3 to Search by Last Name ";
                                    cout<<endl<<"  Enter 4 to Search by Salary ";
                                    cout<<endl<<"  Enter 5 to Search by Post ";
                                    cout<<endl<<"  Enter 6 to Previous Menu ";
                                    cout<<endl<<"  Enter 7 to Main Menu ";
                                    cout<<endl<<"  Enter 8 to Exit ";
                                    int ch;
                                    cin>>ch;
                                    switch(ch)
                                    {
                                    case 1:
                                        {
                                            system("cls");
                                            searchbyempid();
                                            break;
                                        }
                                    case 2:
                                        {
                                            system("cls");
                                            searchbyname();
                                            break;
                                        }
                                    case 3:
                                        {
                                            system("cls");
                                            searchbylastname();
                                            break;
                                        }
                                    case 4:
                                        {
                                            system("cls");
                                            searchbysalary();
                                            break;
                                        }
                                    case 5:
                                        {
                                            system("cls");
                                            searchbypost();
                                            break;
                                        }
                                    case 6:
                                        {
                                            l = 1;
                                            break;
                                        }
                                    case 7:
                                        {
                                            t = 1;
                                            break;
                                        }
                                    case 8:
                                        {
                                            e = 1;
                                            break;
                                        }
                                    default:
                                        {
                                            cout<<"  Select from the Menu Only!!!";
                                            break;
                                        }
                                        break;
                                    }
                                    }
                                    break;
                                }
                            case 4:
                                {
                                    system("cls");
                                    removeemp();
                                    break;
                                }
                            case 5:
                                {
                                    system("cls");
                                    updateemp();
                                    break;
                                }
                            case 6:
                                {
                                    system("cls");
                                    dispensesalary();
                                    break;
                                }
                            case 7:
                                {
                                    system("cls");
                                    searchsalary();
                                    break;
                                }
                            case 8:
                                {
                                    system("cls");
                                    t = 1;
                                    break;

                                }
                            case 9:
                                {
                                    system("cls");
                                    e = 1;
                                    break;
                                }
                            default:
                                {
                                    cout<<"  Select from the Menu Only!!!";
                                }
                            }
                        }
                    }
                    else
                    {
                        system("cls");
                        cout<<"Wrong Password";
                    }
            }
            if(choice==2)
            {
                int b = 0;
                while(b!=1)
                {
                    system("cls");
                    cout<<endl<<"                                              Welcome to Guest Access!!!";
                    cout<<endl<<endl<<endl<<"  Enter 1 to Show all Employees ";
                        cout<<endl<<"  Enter 2 to Search Employee ";
                        cout<<endl<<"  Enter 3 to Search Salary ";
                        cout<<endl<<"  Enter 4 to Log Out ";
                        cout<<endl<<"  Enter 5 to Exit ";
                        int k;
                        cin>>k;
                        switch(k)
                        {
                            case 1:
                                {
                                    system("cls");
                                    showallemp();
                                    break;
                                }
                            case 2:
                                {
                                    system("cls");
                                    int s = 0;
                                    while(s!=1)
                                    {
                                    cout<<endl<<endl<<endl<<endl<<endl<<"  Enter 1 to Search by ID ";
                                    cout<<endl<<"  Enter 2 to Search by Name ";
                                    cout<<endl<<"  Enter 3 to Search by Last Name ";
                                    cout<<endl<<"  Enter 4 to Search by Salary ";
                                    cout<<endl<<"  Enter 5 to Search by Post ";
                                    cout<<endl<<"  Enter 6 to Previous Menu ";
                                    cout<<endl<<"  Enter 7 to Main Menu ";
                                    cout<<endl<<"  Enter 8 to Exit ";
                                    int cho;
                                    cin>>cho;
                                    switch(cho)
                                    {
                                    case 1:
                                        {
                                            system("cls");
                                            searchbyempid();
                                            break;
                                        }
                                    case 2:
                                        {
                                            system("cls");
                                            searchbyname();
                                            break;
                                        }
                                    case 3:
                                        {
                                            system("cls");
                                            searchbylastname();
                                            break;
                                        }
                                    case 4:
                                        {
                                            system("cls");
                                            searchbysalary();
                                            break;
                                        }
                                    case 5:
                                        {
                                            system("cls");
                                            searchbypost();
                                            break;
                                        }
                                    case 6:
                                        {
                                            s = 1;
                                            break;
                                        }
                                    case 7:
                                        {
                                            b = 1;
                                            break;
                                        }
                                    case 8:
                                        {
                                            e = 1;
                                            break;
                                        }
                                    default:
                                        {
                                            cout<<"  Select only from the Menu!!!";
                                            break;
                                        }
                                        break;
                                    }
                                    }
                                    break;
                                }
                            case 3:
                                {
                                    system("cls");
                                    searchsalary();
                                    break;
                                }
                            case 4:
                                {
                                    system("cls");
                                    b = 1;
                                    break;
                                }
                            case 5:
                                {
                                    system("cls");
                                    e = 1;
                                    break;

                                }
                            default:
                                {
                                    cout<<"  Select only from the Menu!!!";
                                    break;
                                }
                            }
                  break;
                }
            }
            if(choice==3)
            {
                e = 1;
                break;
            }
            else
            {
                cout<<"  Select from the menu only!!!";
                break;
            }
        }
    }
