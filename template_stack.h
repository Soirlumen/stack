#ifndef TEMPLATE_STACK_H
#define TEMPLATE_STACK_H
#include "template_list.h"
#include <string>

template<typename D>
class Stack{
private:
    size_t size;
    SingleLinkedList<D> *things;
public:
    Stack(size_t number):size(number){
        things=new SingleLinkedList<D>;
    }
    Stack(const Stack<D>& other):size(other.getCapacity()){
        things=new SingleLinkedList<D>(other.getThings());
    }

    size_t getCapacity() const{return size;}

    void setCapacity(size_t _t){
        try{
            if(things->getNumberOfThings()>_t){
                throw std::out_of_range("Nemuzete zmensit velikost stacku, protoze tam jsou hodnoty");
            }
        }catch(const  std::out_of_range e){
            std::cout<<"chyceno: "<<e.what()<<std::endl;
            return;
        }
        size=_t;
    }
    void pop(){
        try{
            things->popFront();}
        catch(const  std::out_of_range e){
            std::cout<<"chyceno: "<<e.what()<<" ...nic se nestalo." <<std::endl;
            return;
        }
    }
    void push(D data){
        try{
            if(isFull()){
                throw std::out_of_range("Plny zasobnik!");
            }
        }catch(const  std::out_of_range e){
            std::cout<<"chyceno: "<<e.what()<<" dato: "<< std::to_string(data)<<" se nepridalo." <<std::endl;
            return;
        }

        things->pushFront(data);
    }

    const SingleLinkedList<D>& getThings() const {
        return *things;
    }

    bool isEmpty(){
        return (getCapacity()==0);
    }
    bool isFull(){
        return (getCapacity()==(getThings().getNumberOfThings()));
    }
    D top(){
        try{
            if(isEmpty()){
                throw std::out_of_range("nic neni na topu, zasobnik je prazdny!");
            }
        }
        catch(const std::out_of_range e){
            std::cout<<"chyceno: "<<e.what()<<"nic se nestalo."<<std::endl;
        }

        return things->firstNode()->getData();
    }

    void printy() const{
        getThings().printy();
    }

    ~Stack(){
        delete things;
        things=nullptr;
    }
};

#endif // TEMPLATE_STACK_H
