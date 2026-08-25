#include<iostream>
#include<iomanip>
#include<cstdio>
#include<fstream>
using namespace std;
int pin,pin1=0,pin2,accno,accno1,accnoc,pinc,i=0,chance=0,choic=0,j=0;
double bal,balc,bal1,bal2=0;
void end();
int main();
void login();
void invalid(ofstream &file);
void sublogin();
void create()
{
    cout<<"Enter 8-digit Account Number: ";
    cin>>accno;
    ifstream check("ATM.txt");  
 if(check)
 {
     while(check>>accnoc>>pinc>>balc)
        {
         if(accno==accnoc)
         {
          cout<<"Account number already exists!"<<endl;
          cout<<"Please try with a different account number."<<endl;
             check.close();
       return;
      }
     }
    }
 check.close();
    ofstream file("ATM.txt",ios::app);
    if(accno>9999999 && accno<100000000)
    {
        invalid(file);
       
    }
    else
    {
        cout<<"INVALID Account Number!"<<endl;
    }
    file.close();
}
void invalid(ofstream &file)
{
    j+=1;
  if(j!=4)
  {
    cout<<"Set 4-digit PIN: ";
    cin>>pin;
    if(pin>999 && pin<10000)
    {    
        cout<<"Enter Initial Balance: ";
        cin>>bal;
        file<<accno<<" "<<pin<<" "<<bal<<endl;
        cout<<"Account Created Successfully!"<<endl;
        j=0;
    }
    else
    {
        cout<<"INVALID PIN Number!"<<endl;
        invalid(file);
    }
  }
  else
  {
     cout<<" - Given no.of Chances Exceeded! - "<<endl;
      cout<<" - Go Back To The MAIN MENU! - "<<endl;
      return;
  }
}

void login()
{
 int found=0;
 ifstream file("ATM.txt");
 if(!file)
 {
  cout<<"NO Accounts Found"<<endl;
  return;
 }
    cout<<"Enter Account Number: ";
    cin>>accno1;
    cout<<"Enter PIN Number: ";
    cin>>pin1;
    while(file>>accno>>pin>>bal)
    {
        if(pin1==pin && accno==accno1)
        {
         found=1;
            break;
        }
    }
    if(found==0)
    {
        cout<<"INVALID Account Number or PIN!"<<endl;
        i+=1;
        if(i!=3)
        {
            login();
        }
        else
        {
            cout<<" - Given no.of Chances Exceeded! - "<<endl;
            cout<<" - Go Back To The MAIN MENU! - "<<endl;
            return;
        }
    }
    file.close();
    if(found==1)
    {
     i=0;
     sublogin();
 }
   
}
void sublogin()
{
     choic=0;
        chance=0;
  int opt=0;
        int acc;
        acc=accno1;
  cout<<endl<<"- - - - ATM MENU - - - - "<<endl<<"1. Check Balance "<<endl;
        cout<<"2. Deposit"<<endl<<"3. Withdraw"<<endl<<"4. Change PIN"<<endl<<"5. Exit"<<endl;
        cout<<"Enter choice: ";
        cin>>opt;
        bal2=bal;
        pin2=pin1;
            if(opt==1)
            {
                cout<<"Current Balance: "<<fixed<<setprecision(2)<<bal<<endl;
            }
            else if(opt==2)
            {
                cout<<"Enter Amount: ";
                cin>>bal1;
                bal2=bal+bal1;
                chance=1;
                cout<<"Amount Deposited Successfully!"<<endl;
                cout<<"Available Amount: "<<fixed<<setprecision(2)<<bal2<<endl;
            }
            else if(opt==3)
            {
                cout<<"Enter Amount: ";
                cin>>bal1;
                if(bal1<=bal)
                {
                    bal2=bal-bal1;
                    chance=1;
                    cout<<"Withdrawl is Successful!"<<endl;
                    cout<<"Remaining Balance: "<<fixed<<setprecision(2)<<bal2<<endl;
               
                }
                else
                {
                    cout<<"No Sufficient balance!"<<endl;
                    return;
                }
            }
            else if(opt==4)
            {
                cout<<"Enter NEW PIN: ";
                cin>>pin2;
                if(pin2>999 && pin2<10000)
                {
                 choic=1;
                    cout<<"PIN Changed Successfully!"<<endl;
    }
                else
                {
                 cout<<"INVALID PIN Number!"<<endl;
                 return;
    }
               
            }
            else if(opt>5)
            {
                cout<<"INVALID Choice!"<<endl;
                return;
            }
            else
            {
                return;
            }
    if(choic==1 || chance==1)
 {
     ifstream file("ATM.txt");
        ofstream temp("temp.txt");  
        if(!file)
     {
      cout<<"ERROR Opening File!"<<endl;
      return;
     }
  while(file>>accno>>pin>>bal)
        {
         if(accno==acc)
         {
          temp<<accno1<<" "<<pin2<<" "<<bal2<<endl;
      }
   else
   {
    temp<<accno<<" "<<pin<<" "<<bal<<endl;
   }
  }
  file.close();
  temp.close();
        remove("ATM.txt");
     rename("temp.txt","ATM.txt");      
    }
}

int main()
{
    int choice=0;
    while(choice!=5)
    {
        cout<<"= = = = = ATM SYSTEM = = = = = "<<endl;
        cout<<"1. Create Account"<<endl<<"2. Login"<<endl<<"3. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        if(choice==1)
        {
            create();
        }
        else if(choice==2)
        {
            login();
        }
        else if(choice==3)
        {
            cout<<"Thank You For Using This ATM!"<<endl;
            return 0;
        }
        else
        {
            cout<<"INVALID Choice!"<<endl;
        }
    }
   
    return 0;
   
}


