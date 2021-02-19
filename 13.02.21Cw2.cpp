#include <iostream>
#include <vector>

class BankCell{
private:
    int money;
public:
    BankCell(int m):money(m){}
    ~BankCell(){std::cout<<"I am destroyed"<<std::endl;};
    void printMoney(){std::cout<<"Money printer go brrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr"<<std::endl;}
};

class Human{
public:
    void setBank(int money){pointer=std::make_shared<BankCell>(money);}
    void setAnother(std::shared_ptr<BankCell> p){pointer=p;}
    Human(unsigned int num, int money=0,std::shared_ptr<BankCell> p = nullptr){
        if (num==0)
            setBank(money);
        else
            setAnother(p);
    }
    std::shared_ptr<BankCell>& getPointer(){return pointer;}
private:
    std::shared_ptr<BankCell> pointer;
};
int main()
{
    Human a(0,5);
    Human b(1,0,a.getPointer());

    a.getPointer()->printMoney();
    return 0;
}