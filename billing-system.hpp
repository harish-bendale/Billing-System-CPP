#include<string>
#include <stdio.h>
#ifndef billing_system_hpp
#define billing_system_hpp

class Shopping{
protected:
        int pcode;
        std::string pname;
        float p;
        float d;
    
    public :
        void menu();
        void administrator();
        void buyer();
        void add();
        void edit();
        void rem();
        void list();
        void reciept();
};
#endif /* billing_system_hpp */
