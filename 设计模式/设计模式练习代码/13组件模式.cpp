/*
组件模式  composite
在开发中，我们经常可能要递归构建树状的组合结构，Composite 模式则提供了很好的 解决方案。

Composite 模式在实现中有一个问题就是要提供对于子节点(Leaf)的管理策略，这里
使用的是 STL 中的 vector，可以提供其他的实现方式，如数组、链表、Hash 表等。


*/
#include<iostream>
#include<vector>
using namespace std;
class Component{
public:
    Component(){}
    ~Component(){}
    virtual void Operation()=0;
    virtual void Add(const Component& ){}
    virtual void Remove(const Component&){}
    virtual Component* GetChild(int){
        return 0;
    }
};

class Composite:public Component{
public:
    Composite(){

    }
    ~Composite(){}
    virtual void Operation(){
        vector<Component*>::iterator comIter=comVec.begin();
        for(;comIter!=comVec.end();++comIter){
            (*comIter)->Operation();
        }
    }
    virtual void Add(Component* com){
        comVec.push_back(com);
    }
    // virtual void Remove(Component* com){
    //     comVec.erase(&com);
    // }
    virtual Component* GetChild(int index){
        return comVec[index];
    }
private:
    vector<Component*> comVec;
};

class Leaf:public Component{
public:
    Leaf(){}
    ~Leaf(){}
    virtual void Operation(){
        cout<<"Leaf Operator()"<<endl;
    }
};

int main(){
    Component* leaf=new Leaf();
    leaf->Operation();
    Composite* composite=new Composite();
    composite->Add(leaf);
    composite->Operation();
    Component* child=composite->GetChild(0);
    child->Operation();
    return 0;
}