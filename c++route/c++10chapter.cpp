#include<iostream>
using namespace std;
/* class Phone
{
public:
    Phone(string name);
    ~Phone();
    string Pname;
};

Phone::Phone(string name)
{ 
    cout<<"Phone构造函数的调用"<<endl;
    Pname = name;
}

Phone::~Phone()
{
    cout<<"Phone析造函数的调用"<<endl;
}

class Person
{
public:
    string m_name;
    Phone m_phone;

    Person(string name ,string p_name );
    ~Person();
};

Person::Person(string name ,string p_name ):m_name(name),m_phone(p_name)
{
    cout<<"Person构造函数的调用"<<endl;
}

Person::~Person()
{
    cout<<"Person析构函数的调用"<<endl;
}
void test01(){
    Person w ("张三","小米");
    cout<<w.m_name<<"  "<<w.m_phone.Pname<<endl;
}
int main(){
    test01();
} */
//指针
/*
class Person{
public:

   Person (int age){
    this->age = age;
   }
   //P298
   //&符号使得返回值为指针指向的Person本体，
   //没有&的话，会发生值传递，使用默认拷贝构造，会产生新的对象进行计算
   //即返回的是调用对象本身，而不是其副本
   Person& PersonAdd (Person p){
    this->age += p.age;
    //this是指向p2的指针，值为地址，而*this就是p2，使用解引用运算符指向其值
    return *this;
   }

   int age;
};
void test01(){
    Person p1(10);
    Person p2(10);
    p2.PersonAdd(p1).PersonAdd(p1).PersonAdd(p1);
    cout<< " p2.age:  "<<p2.age<<endl;

}
int main(){
    test01();
    system("pause");
}
*/
//对象数组
class Stock
{
private:
    double total_val;
public:
    Stock(double val);
    ~Stock();
    const Stock& topval(const Stock& s) const;
    void show() const;
};

Stock::Stock(double val)
{
    total_val=val;
}

Stock::~Stock()
{
}
const Stock& Stock::topval(const Stock& s) const
{
    if (s.total_val > total_val)
        return s;
    else 
        return *this;
}
void Stock::show() const{
    cout<<total_val<<endl;
}
int main(){
    Stock stock[4]={
        Stock(10),Stock(19),Stock(1),Stock(6)
    };

    const Stock* top = &stock[0];
    for(int st; st < 4; st++){
        top = &top->topval(stock[st]);
        //topval返回对象本体，然后取地址符&，将地址（引用）赋给top
    }
    top->show();
    system("pause");
}
