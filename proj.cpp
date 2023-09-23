#include<iostream>
#include<fstream>                         //Predefined C++ directives                                    
#include<cstdio>
//#include<process.h>
using namespace std;
char empty,ans='y';
int p;
void space()
{
    cout<<"\n Press any alphabet or number to continue\n";
    cin>>empty;
}

void line()                                     //add lines
{ 
    cout<<"\n_________________________________________________________";
    cout<<"______________________\n";
}

class Employee                                  //Class Employee created
{
    private:
        int id;
        char name[20];
        float salary;
         char dept[20];
  public:
    void input()                                   //Function to take Input from user
   {
        cout<<"******ENTER EMPLOYEE ID******\n";
        cin>>id;
        cin.ignore();
        cout<<"\n******ENTER EMPLOYEE NAME******\n";
        gets(name);
        cout<<"\n******ENTER DEPARTMENT OF EMPLOYEE******\n";
        gets(dept);
        cout<<"\n******ENTER EMPLOYEE SALARY******\n";
        cin>>salary;
        //cin.ignore();

   }

  void display()                             //Function to display a record
  {
        cout<<"\nEmployee Id is: ";
        cout<<id;
        cout<<"\nEmployee name is: ";
        cout<<name;
        cout<<"\nDepartment of Employee is: ";
        cout<<dept;
        cout<<"\n Salary of Employee is: ";
        cout<<salary;
  }

  int getid()                               //Function to use private data member in non member  functions
  {
    return id;
  }
  };

  Employee E1;


void search(int a)                             //Searching a Record
{
    line();
    char ch='n';
    ifstream fin("emp12345.dat",ios::binary);
    fin.seekg(0);

    if(!fin)
    {
        cout<<"\n !!!!!!!!!!!!!file cant be open!!!!!!!!!!!\n\tAborting\n";
        line();
        space();
        exit(0);
    }

  fin.seekg(0);
  while(!fin.eof())
  {
        fin.read((char*)&E1,sizeof(E1));
        if(a==E1.getid())
         {
            E1.display();
            line();
            ch='y';
            break;
         }
  }

  fin.close();
  if(ch=='n')
   {
        cout<<"\n no  match found\n";
        line();
        cout<<"\n\n\n\n\n\n";
        space();
   }

}


void append()                                  //Data Entry
{
  ofstream fout("emp12345.dat",ios::app);
   if(!fout)
    {
        cout<<"\n!!!!!!!!!file can't be opened!!!!!!!!!!\nAborting\n";
	    line();
        space();
        exit(0);
    }
  while(ans=='y')
  {
        system("cls");
        line();
        E1.input();
        fout.write((char*)&E1,sizeof(E1));
         cout<<"\n Record added";
        line();
        cout<<"\n Want to enter more Records? [y/n)...";
        cin>>ans;
  }
  fout.close();
  }


void modify(int a)                             //Modification of Records
{
    fstream fout("emp12345.dat",ios::binary|ios::in|ios::out);
    if(!fout)
    { 
        cout<<"\n!!!!!!!!!!!file can't be opened!!!!!!!!!!!\n\t\t Aborting!";
        line();
        space();
        exit(0);
    }

  char found='f';
  while(!fout.eof())
  {
        p=fout.tellg();
        fout.read((char*)&E1,sizeof(E1));
        if(E1.getid()==a)
        {
            E1.display();
            line();
            cout<<"Enter new details of Employee \n ";
            E1.input();
            fout.seekg(p);
            fout.write((char*)&E1,sizeof(E1));
            found='t';
            break;
        }
  }
  if(found=='f')
  {
        cout<<"\n!!!Record not found!!!\n";
        line();
        space();
  }
  else
  {
        cout<<"\n!!!Record Modified!!!";
        line();
        space();
  }
}

/*
void del(int a)                                //Deletion of Records
{
    ifstream fin("emp12345.dat",ios::in);
    ofstream file("temp.dat",ios::out);

    if((!fin)||(!file))
    {
        cout<<"\n!!!!!!!!file can't be opened!!!!!!!!!\nAborting\n";
        line();
        space();
        exit(0);
    }
    fin.seekg(0);
    file.seekp(0);
    char found='q';
    while(!fin.eof())
    {
        fin.read((char*)&E1,sizeof(E1));
        if(E1.getid()==a)
        {
            E1.display();
            found='t';
            line();
            cout<<"\n Are you sure to delete this record ? (y/n)....";
            cin>>empty;
            if(empty=='n')
            {
                file.write((char*)&E1,sizeof(E1));
                cout<<"\n Record not deleted";
            }
            else
            {
                cout<<"\n Record deleted....";
            }
        }
        else
            file.write((char*)&E1,sizeof(E1));
    }

    if(found=='q')
        cout<<"\n Record not found";

    line();
    space();

    fin.close();
    file.close();
    
    remove("emp12345.dat");
    if (rename("temp.dat","emp12345.dat") != 0)
		perror("Error renaming file");

    //rename("temp.dat","emp12345.dat");

}
*/

void show()                                    /*Function to display all records*/
{
    system("cls");
    ifstream fin("emp12345.dat",ios::binary);
    if(!fin)
    {
        cout<<"\n!!!!!!!!!file can't be opened!!!!!!!!\nAborting \n";
        space();
        exit(0);
    }
    fin.seekg(0);
    while(!fin.eof())
    {
        line();
        fin.read((char*)&E1,sizeof(E1));
        if(fin.eof())
            break;
        E1.display();
        line();
        space();
    }
    fin.close();
}

  int main()
  {
    system("cls");
    cout<<"\n******************** WELCOME TO  EMPLOYEE MANAGEMENT SYSTEM";
    cout<<"********************";
    start:
    cout<<"\n\t\t\t\tMAIN MENU";

    cout<<"\n 1. Enter a Record";
    cout<<"\n 2. Search a Record";
    cout<<"\n 3. Modify a record";
   // cout<<"\n 4. Delete a Record";
    cout<<"\n 4. Show all the Records";
    cout<<"\n 5. Exit!";

    line();
    cout<<"\n\n\n\n\nEnter your Choice......";
    int choice,number;
    cin>>choice;
    system("cls");

    switch(choice)
    {
        case 1:{
            line();
            append();
            system("cls");
            goto start;
            }

        case 2:{
            line();
            cout<<"\n Enter the Employee ID you want to search....";
            cin>>number;
            search(number);
            space();
            system("cls");
            goto start;
        }

        case 3:{
            line();
            cout<<"\n Enter the ID of the Employee, you want to modify....";
            cin>>number;
            modify(number);
            system("cls");
            goto start;
        }

        /*
        case 4:{
            line();
            cout<<"\nEnter theID of the Employee, you want to delete....";
            cin>>number;
            del(number);
            system("cls");
            goto start;
        }
        */
        case 4:{
            show();
            system("cls");
            goto start;
        }

        case 5:{ 
            exit(0);
        }

        default:{
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
            line();
            cout<<"\n!!!!Invalid input!!!!\n Enter again!";
            line();
            space();
            system("cls");
            goto start;
        }
    }
    return 0;
}

