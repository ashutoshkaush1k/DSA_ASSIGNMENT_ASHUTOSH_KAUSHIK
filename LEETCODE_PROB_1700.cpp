#include<iostream>
using namespace std;

class stck {
private:
    int top,asize,stk[50];
public:
    stck() {
        top=-1;
        asize=50;
    }

    void push(int ele)
    {
        if(top==-1)
        {
            top=0;
        }
        else if(top==asize-1)
        {
            cout<<"Stack Overflow"<<endl;
            return;
        }
        else
        {
            top++;
        }
        stk[top]=ele;
    }

    int pop()
    {
        if(top==-1)
        {
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
        else
        {
            return stk[top--];
        }
    }

    int peek() {
        if(top==-1)
        {
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
        else
        {
            return stk[top];
        }
    }

    bool isEmpty()
    {
        return top==-1;
    }
};

class circularqueues {
private:
    int q[50],Rear,Front,MAX;
public:
    circularqueues()
    {
        Rear=-1;
        Front=-1;
        MAX=50;
    }

    void enqueue(int ele)
    {
        if((Front==Rear+1)||(Front==0&&Rear==MAX-1))
        {
            cout<<"Queue Overflow"<<endl;
            return;
        }
        if(Rear==-1&&Front==-1)
        {
            Front=Rear=0;
        }
        else if(Rear==MAX-1)
        {
            Rear=0;
        }
        else
        {
            Rear++;
        }
        q[Rear]=ele;
    }

    int dequeue()
    {
        if(Rear==-1&&Front==-1)
        {
            cout<<"Queue Underflow"<<endl;
            return -1;
        }
        int ele=q[Front];
        if(Rear==Front)
        {
            Rear=Front=-1;
        }
        else if(Front==MAX-1)
        {
            Front=0;
        }
        else
        {
            Front++;
        }
        return ele;
    }

    int From_Front()
    {
        if(Rear==-1&&Front==-1)
        {
            cout<<"Queue Underflow"<<endl;
            return -1;
        }
        return q[Front];
    }

    bool isEmpty()
    {
        return Rear==-1&&Front==-1;
    }

    int Size() {
        if(Rear==-1&&Front==-1) return 0;
        if(Front>Rear) return (MAX-Front+Rear+1);
        return (Rear-Front+1);
    }
};

int countStudents(circularqueues& students,stck& sandwiches) {
    int studentsRejoined=0;
    while(!students.isEmpty()&&(studentsRejoined<students.Size())) {
        int studentPref=students.From_Front();
        int sandwichType=sandwiches.peek();
        if(studentPref==sandwichType)
        {
            students.dequeue();
            sandwiches.pop();
            studentsRejoined=0;
        }
        else
        {
            int temp=students.dequeue();
            students.enqueue(temp);
            studentsRejoined++;
        }
    }
    return students.Size();
}

int main() {
    circularqueues students;
    stck sandwiches;
    int n;
    cout<<"Enter number of students (max 50): ";
    cin>>n;
    if(n>50||n<=0)
    {
        cout<<"Invalid input. Please enter a number between 1 and 50."<<endl;
        return 0;
    }

    cout<<"Enter student preferences (0 for circular, 1 for square):"<<endl;
    for(int i=0;i<n;i++)
    {
        int pref;
        cin>>pref;
        if(pref!=0&&pref!=1)
        {
            cout<<"Invalid preference. Only 0 or 1 allowed."<<endl;
            return 0;
        }
        students.enqueue(pref);
    }

    cout<<"\nNote: Since sandwiches are pushed into a stack (LIFO), the last entered sandwich will be served first."<<endl;
    cout<<"Enter sandwich types (0 for circular, 1 for square):"<<endl;
    int sandwichTypes[50];
    for(int i=0;i<n;i++)
    {
        cin>>sandwichTypes[i];
        if(sandwichTypes[i]!=0&&sandwichTypes[i]!=1)
        {
            cout<<"Invalid sandwich type. Only 0 or 1 allowed."<<endl;
            return 0;
        }
    }
    for(int i=0;i<n;i++)
    {
        sandwiches.push(sandwichTypes[i]);
    }
    int result=countStudents(students,sandwiches);
    cout<<"\nNumber of students unable to eat: "<<result<<endl;
    return 0;
}
