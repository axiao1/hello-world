#ifndef STACK_H_
#define STACK_H_

typedef unsigned long Item;
//如果需要别的数据类型的栈，只需要在这里修改即可
class stack
{
private:
    enum{MAX=10};
    Item items[MAX];
    int top;
public:
    stack();
    bool isempty() const;
    bool isfull() const;
    bool push(const Item & item );
    bool pop(Item & item);
};
#endif