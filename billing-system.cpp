#include "billing-system.hpp"
#include<iostream>
#include<fstream>
#include<vector>
void Shopping :: menu(){
    m:
    int choice ;
    std::string email;
    std::string password;
    std::cout<<"Select the choice \n";
    std::cout<<"\t\t\t\t\t 1) Administrator \n";
    std::cout<<"\t\t\t\t\t 2) Buyer \n";
    std::cout<<"\t\t\t\t\t 3) exit \n";
    std::cin>>choice;

    switch(choice){
        case 1 :
            std::cout<<" Please Login ";
            std::cout<<" Enter email \n";
            std::cin>>email;
            std::cout<<" Enter Password \n";
            std::cin>>password;
            if(email == "harishbendale80@gmail.com" and password == "123"){
                administrator();
            }else{
                std::cout<<"Invalid email/password\n";
            }
            break;
        
        case 2:
            buyer();
        case 3 :
            exit(0);
        default :
            std::cout<<"Please select from the given options \n";
    }
    goto m;
}
void Shopping :: administrator(){
    m :
    int ch;
    std::cout<<"Administrator Menu \n";
    std::cout<<"Please select the following choice to perform operations "<<std::endl;
    std::cout<<"\t\t\t 1) Add the product \n";
    std::cout<<"\t\t\t 2) Modify the product \n";
    std::cout<<"\t\t\t 3) Delete the product \n";

    std::cin>>ch;
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
            std::cout<<"Invalid Choice!\n";
            break;
    }

    goto m;
}
void Shopping :: add(){
    m :
    std::fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    std::string n;
    
    std::cout<<"Add new product \n";
    std::cout<<"Enter the product code \t";
    std::cin>>pcode;
    std::cout<<"Enter the name of the code \t";
    std::cin>>pname;
    std::cout<<"Enter the price of the product \t";
    std::cin>>p;
    std::cout<<"Enter the discount on the product \t";
    std::cin>>d;
    data.open("/Users/harishyashwantbendale/Desktop/OOP Git 2/Billing-System-CPP/data.txt", std::ios::in);
    if(!data){
        data.open("/Users/harishyashwantbendale/Desktop/OOP Git 2/Billing-System-CPP/data.txt", std::ios::app|std::ios::out);
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
            data.open("/Users/harishyashwantbendale/Desktop/OOP Git 2/Billing-System-CPP/data.txt",std::ios::app|std::ios::out);
            data<<pcode<<" "<<pname<<" "<<p<<" "<<" "<<d<<"\n";
            data.close();
        }
    }
    std::cout<<"Record inserted !\n";
}

void Shopping :: edit(){
    std::fstream data , data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    std::string n;
    std::cout<<"Modify the record";
    std::cout<<"Product code ";
    std::cin>>pkey;
    data.open("/Users/harishyashwantbendale/Desktop/OOP Git 2/Billing-System-CPP/data.txt",std::ios::in);

    if(!data){
        std::cout<<"File doesnt exist \n";
    }else{
        data1.open("/Users/harishyashwantbendale/Desktop/OOP Git 2/Billing-System-CPP/data1.txt",std::ios::app|std::ios::out);
        data>>pcode>>pname>>p>>d;
        while(!data.eof()){
            if(pkey == pcode){
                std::cout<<"\t\tProduct new code\n";
                std::cin>>c;
                std::cout<<"\t\tName of the product\n";
                std::cin>>n;
                std::cout<<"\t\t Price\n";
                std::cin>>p;
                std::cout<<"\t\t Discount\n";
                std::cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                std::cout<<"Record edited\n";
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
        std::cout<<"\t\t Record not found sorry \n";
    }
}

void Shopping::rem()
{
    
    std::fstream data,data1;
    int pkey;
    int token=0;
    std::cout<<"\n\n\t Delete product";
    std::cout<<"\n\n\t Product code :";
    std::cin>>pkey;
    data.open("/Users/harishyashwantbendale/Desktop/OOP Git 2/Billing-System-CPP/data.txt", std::ios::in);
    if(!data)
    {
        std::cout<<"File doesnt exist";
        
    }
    
    else{
        data1.open("/Users/harishyashwantbendale/Desktop/OOP Git 2/Billing-System-CPP/data1.txt",std::ios::app|std::ios::out);
        data>>pcode>>pname>>p>>d;
        while(!data.eof())
        {
            if(pcode==pkey)
            {
                std::cout<<"\n\n\t Product deleted succesfully";
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
            std::cout<<"\n\n Record not found";
        }
    }
}


void Shopping :: buyer(){
    m:
    int choice;
    std::cout<<"\t\t\t Buyer Menu\n";
    std::cout<<"\t\t\t 1) Buy Product\n";
    std::cout<<"\t\t\t 2) Go Back\n";
    std::cin>>choice;

    switch(choice){
        case 1:
            reciept();
            break;
        case 2:
            menu();
        default :
            std::cout<<"Invalid choice\n";
            break;
    }
    goto m;
}

void Shopping::reciept(){
    
    std::cout << "\033[2J\033[1;1H";
    std::fstream data;
    std::vector<int> arrc,arrq;

    char choice;
    float amount = 0;
    float dis = 0;
    float total = 0;
    std::cout<<"\t\t Reciept\n";
    data.open("/Users/harishyashwantbendale/Desktop/OOP Git 2/Billing-System-CPP/data.txt",std::ios::in);

    if(!data){
        std::cout<<"\tEmpty Database\n";
    }else{
        data.close();
        list();
        
        std::cout<<"\t\t Place the order\n";

        do{
            m:
            std::cout<<"\t\t Product code\n";
            int code;
            std::cin>>code;
            arrc.push_back(code);
            std::cout<<"\t\t Product Quantity\n";
            int qty;
            std::cin>>qty;
            arrq.push_back(qty);
            for(int i=0;i<(int)arrq.size()-1;i++){
                if(arrc.back() == arrc[i]){
                    std::cout<<"\tDuplicate Product code Try Again !\n";
                    goto m;
                }
            }

            std::cout<<"\tWant to buy any another product y for Yes n for No : \n";
            std::cin>>choice;
        }while(choice == 'y');

        std::cout << "\033[2J\033[1;1H";
        std::cout<<"\t\t Reciept \t\t\n";
        
        std::cout << "\nProduct num\tProduct Name\tQuantity\tPrice\td\tAmount\tAmount with discount\n";
        int size = (int)arrc.size();
    
        for (int i = 0; i < size; i++) {
            std::fstream data;
            data.open("/Users/harishyashwantbendale/Desktop/OOP Git 2/Billing-System-CPP/data.txt", std::ios::in);
            data >> pcode >> pname >> p >> d;
            while (!data.eof()) {
                if (pcode == arrc[i]) {
                    amount = p * arrq[i];
                    std::cout<<(amount*d)/100;
                    dis = amount - ((amount * d) / 100);
                    total = total + dis;
                    std::cout << "\n" << pcode << "\t\t" << pname << "\t\t\t" << arrq[i] << "\t" << p << "\t" << amount << "\t\t" << dis << "\n";
                }
                data >> pcode >> pname >> p >> d;
            }
            data.close();
        }

        std::cout << "\n\n\n-----------------------\n";
        std::cout << "\t\t Total Amount : \t" << total << "\n";
    }
    
}
void Shopping :: list(){
    std::fstream data;
    data.open("/Users/harishyashwantbendale/Desktop/OOP Git 2/Billing-System-CPP/data.txt",std::ios::in);
    std::cout<<"\n\n|___________________________________________________________\n";
    std::cout<<"ProNo\t\tName\t\tPrice\n";
    std::cout<<"\n\n|___________________________________________________________\n";
    data>>pcode>>pname>>p>>d;
    while(!data.eof())
    {
        std::cout<<pcode<<"\t\t"<<pname<<"\t\t"<<p<<"\n";
        data>>pcode>>pname>>p>>d;
    }
    data.close();
}
