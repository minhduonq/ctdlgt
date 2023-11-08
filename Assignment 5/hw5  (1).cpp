#include<iostream>
#include<map>
using namespace std;

struct Student
{
    int id;
    string name;
    string class_;
};

map<int,Student> students;

void Insert(int id, string name, string class_)
{
    students[id] = {id, name, class_};
}

void Delete(int id)
{
    students.erase(id);
}

string Infor(int id)
{
    if(students.count(id)==0) {
        return "NA,NA";
    }

    const Student& student = students[id];
    return student.name + "," + student.class_;
}

int main()
{
    string op;
    while(cin >> op)
    {
        if(op == "Insert") {
            int id; string name; string class_;
            cin >> id >> name >> class_;
            Insert(id,name,class_);
        } else if(op == "Delete") {
            int id;
            cin >> id;
            Delete(id);
        } else if(op == "Infor") {
            int id;
            cin >> id;
            cout << Infor(id);
        } else {
            cout << "Invalid operation";
        }
    }
}
