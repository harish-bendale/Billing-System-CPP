#include<iostream>
#include<fstream>
using namespace std;
class Shopping{
    protected:
        int pcode;
        string pname;
        float p;
        float d;
    
    public :
        void menu();
        void administrator();
        void buyer(){
            
        } 
        void add();
        void edit();
        void rem();
        void list();
        void reciept();
};

void Shopping :: menu(){
    m:
    int choice ;
    string email;
    string password;
    cout<<"Select the choice \n";
    cout<<"\t\t\t\t\t 1) Administrator \n";
    cout<<"\t\t\t\t\t 2) Buyer \n";
    cout<<"\t\t\t\t\t 3) exit \n";
    cin>>choice;

    switch(choice){
        case 1 :
            cout<<" Please Login ";
            cout<<" Enter email \n";
            cin>>email;
            cout<<" Enter Password \n";
            cin>>password;
            if(email == "harishbendale80@gmail.com" and password == "123"){
                administrator();
            }else{
                cout<<"Invalid email/password\n";
            }
            break;
        
        case 2:
            buyer();
        case 3 :
            exit(0);
        default : 
            cout<<"Please select from the given options \n";
    }
    goto m;
}
void Shopping :: administrator(){
    m :
    int ch;
    cout<<"Administrator Menu \n";
    cout<<"Please select the following choice to perform operations "<<endl;
    cout<<"\t\t\t 1) Add the product \n";
    cout<<"\t\t\t 2) Modify the product \n";
    cout<<"\t\t\t 3) Delete the product \n";

    cin>>ch;
    switch(ch){
        case 1 : 
            add();
            break;
        case 2:
            edit();
            break;
        case 3:
            rem();
            break;
        case 4: 
            menu();
            break;
        default : 
            cout<<"Invalid Choice!\n";
            break;
    }

    goto m;
}
void Shopping :: add(){
    m :
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;
    
    cout<<"Add new product \n";
    cout<<"Enter the product code \t";
    cin>>pcode;
    cout<<"Enter the name of the code \t";
    cin>>pname;
    cout<<"Enter the price of the product \t";
    cin>>p;
    cout<<"Enter the discount on the product \t";
    cin>>d;
    data.open("/Users/harishyashwantbendale/Desktop/OOP Git 2/Billing-System-CPP/data.txt", ios::in);
    if(!data){
        data.open("/Users/harishyashwantbendale/Desktop/OOP Git 2/Billing-System-CPP/data.txt", ios::app|ios::out);
        data<<pcode<<" "<<pname<<" "<<p<<" "<<d<<"\n";
        data.close();
    }else{
        data>>c>>n>>p>>d;
        while(!data.eof()){
            if(c == pcode){
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();

        if(token == 1)
            goto m;
        else{
            data.open("/Users/harishyashwantbendale/Desktop/OOP Git 2/Billing-System-CPP/data.txt",ios::app|ios::out);
            data<<pcode<<" "<<pname<<" "<<p<<" "<<" "<<d<<"\n";
            data.close();
        }
    }
    cout<<"Record inserted !\n";
}

void Shopping :: edit(){
    fstream data , data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;
    cout<<"Modify the record";
    cout<<"Product code ";
    cin>>pkey;
    data.open("/Users/harishyashwantbendale/Desktop/OOP Git 2/Billing-System-CPP/data.txt",ios::in);

    if(!data){
        cout<<"File doesnt exist \n";
    }else{
        data1.open("/Users/harishyashwantbendale/Desktop/OOP Git 2/Billing-System-CPP/data1.txt",ios::app|ios::out);
        data>>pcode>>pname>>p>>d;
        while(!data.eof()){
            if(pkey == pcode){
                cout<<"\t\tProduct new code\n";
                cin>>c;
                cout<<"\t\tName of the product\n";
                cin>>n;
                cout<<"\t\t Price\n";
                cin>>p;
                cout<<"\t\t Discount\n";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"Record edited\n";
                token++;
            }else{
                data1<<pcode<<" "<<pname<<" "<<p<<" "<<d<<"\n";
            }
            data>>pcode>>pname>>p>>d;
        }
    }
    data.close();
    data1.close();

    remove("/Users/harishyashwantbendale/Desktop/OOP Git 2/Billing-System-CPP/data.txt");
    rename("/Users/harishyashwantbendale/Desktop/OOP Git 2/Billing-System-CPP/data1.txt","/Users/harishyashwantbendale/Desktop/OOP Git 2/Billing-System-CPP/data.txt");
    if(token == 0){
        cout<<"\t\t Record not found sorry \n";
    }
}

void Shopping::rem()
{
    
    fstream data,data1;
    int pkey;
    int token=0;
    cout<<"\n\n\t Delete product";
    cout<<"\n\n\t Product code :";
    cin>>pkey;
    data.open("/Users/harishyashwantbendale/Desktop/OOP Git 2/Billing-System-CPP/data.txt", ios::in);
    if(!data)
    {
        cout<<"File doesnt exist";
        
    }
    
    else{
        data1.open("/Users/harishyashwantbendale/Desktop/OOP Git 2/Billing-System-CPP/data1.txt",ios::app|ios::out);
        data>>pcode>>pname>>p>>d;
        while(!data.eof())
        {
            if(pcode==pkey)
            {
                cout<<"\n\n\t Product deleted succesfully";
                token++;
            }
            else 
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<p<<" "<<d<<"\n";
                
            }
            data>>pcode>>pname>>p>>d;
        }
        data.close();
        data1.close();
        remove("/Users/harishyashwantbendale/Desktop/OOP Git 2/Billing-System-CPP/data.txt");
        rename("/Users/harishyashwantbendale/Desktop/OOP Git 2/Billing-System-CPP/data1.txt","/Users/harishyashwantbendale/Desktop/OOP Git 2/Billing-System-CPP/data.txt");
        
        if(token==0)
        {
            cout<<"\n\n Record not found";
        }
    }
}

void Shopping :: list(){

}
int main(){
    Shopping s;
    s.menu();
}
