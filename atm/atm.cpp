#include<iostream>
using namespace std;
class Bank
{
    private:
    string AHName;
    long int ANum; 
    string AType; 
    long int ABalance;
    
    public:
    Bank()
    {
        AHName = "Blank"; 
        ANum = 0; 
        AType = "Black"; 
        ABalance = 0;
    }

    void ShowData()
    {
        cout<<"Show Data"<<endl;
        cout<<"Name"<<AHName<<endl;
        cout<<"Account no."<<ANum<<endl;
        cout<<"Account Type"<<AType<<endl;
        cout<<"Balance"<<ABalance<<endl;
       
    }

    void ShowTotalBalance()
    {
        cout<<"Show Total Balance"<<endl;
        cout<<"\nTotal Balance is:"<<ABalance;
        
    }

    void AccountCreate()
    {
        cout<<"Create Account"<<endl;
        cout<<"Enter Name:";
        cin.ignore(); 
        getline(cin,AHName);
        cout<<"Enter Account Number\n"; 
        cin>>ANum;
        cout<<"Enter Account Type(Saving|Current)\n";
        cin>>AType;
        cout<<"Balance 500(Min)\n";
        ABalance=500;
    }

    void DepositMoney()
    {
        cout<<"Deposit Money"<<endl;
        cout<<"\nEnter Amount to be deposited\n";
        int amount;
        cin>>amount;
        ABalance= ABalance+amount;
    }

    void WithdrawMoney()
    {
        cout<<"WithdrawMoney"<<endl;
        int a, avail_balance;
        cout<<"Enter Amount to Withdraw\n";
        cin >>a;
        avail_balance=ABalance-a;
        if(avail_balance>=500)
        {
            ABalance=avail_balance;
            cout<<"Available Balance is "<<ABalance;
        }
        else
        cout<<"Minimum Amt must be Rs 500";
    }
};

int main()
{
    Bank BObj;
    char choice;
    do
    {
    cout<<"Welcome ATM Case Study\n";
    cout<<"ATM Operation Option\n";
    cout<<"\t1. Create Account\n";
    cout<<"\t2. Show Data\n";
    cout<<"\t3. Deposit money\n";
    cout<<"\t4. Show Total Balance\n";
    cout<<"\t5. Withdraw Money\n";
    cout<<"\t6. Exit\n";
    cout<<"Enter your choice\n";
    cin>>choice;
    switch (choice)
    {
    case'1' :   cout<<"\t1. create account";
    BObj.AccountCreate();
    break;
    case'2' :   cout<<"\t2. Show Data\n";
    BObj.ShowData();
    break;
    case'3' :   cout<<"\t3. Deposit money\n";
    BObj.DepositMoney();
    break;
    case'4' :   cout<<"\t4. Show Total Balance\n";
    BObj.ShowTotalBalance();
    break;
    case'5' :   cout<<"\t5. Withdraw Money\n";
    BObj.WithdrawMoney();
    break;
    case'6' :   cout<<"\t6. Exit\n";
    break;
    default :   cout<<"choice Error....Try again.."<<endl;
    break;
    }
    }
    while(choice!='6');
    
    cout<<"Closing ATM Case study"<<endl;
}