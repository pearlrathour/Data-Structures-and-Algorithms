// program to enter records of 5 students,which should contain fields like roll no,name,cgpi,semester.a.)list all ecord of all students having cgpi greater than k. b.)insert a new student at kth position and print tha final record.

#include <iostream>
using namespace std;

struct student
{
    string name;
    int rollno;
    float CGPI;
    int Semester;
};

int main()
{
    int l;
    cout << "Enter no of students :" << endl;
    cin >> l;
    struct student info[100];

    for (int i = 0; i < l; i++)
    {
        cout << "For Student" << i + 1 << endl;
        cout << "Enter name" << endl;
        cin >> info[i].name;
        cout << "Enter Roll no." << endl;
        cin >> info[i].rollno;
        cout << "Enter CGPI" << endl;
        cin >> info[i].CGPI;
        cout << "Enter Semester" << endl;
        cin >> info[i].Semester;
    }

    //Printing info of students with CGPI over k
    int k;
    cout << "Enter the value of K" << endl;
    cin >> k;

    cout<<"Student with CGPI greater than"<<k<<endl;
    for (int i = 0; i < l; i++)
    {
        if(info[i].CGPI>k)
        {
            cout<<i+1<<" "<<info[i].name<<" "<<info[i].rollno<<" "<<info[i].CGPI<<" "<<info[i].Semester<<endl;
        }

    }

//Insert at kth position
//Shifting elements of the info array
    if(k<l)
    {
        for(int i=l-1;i>=k-1;i--)
        {
            info[i+1]=info[i];
        }

        cout<<"Enter the info of the New Student"<<endl;
        cout << "For Student" << k  << endl;
        cout << "Enter name" << endl;
        cin >> info[k-1].name;
        cout << "Enter Roll no." << endl;
        cin >> info[k-1].rollno;
        cout << "Enter CGPI" << endl;
        cin >> info[k-1].CGPI;
        cout << "Enter Semester" << endl;
        cin >> info[k-1].Semester;
        

        cout<<"Updated Record:"<<endl;   
        for (int i = 0; i <=l; i++)
    {
        cout<<i+1<<" "<<info[i].name<<" "<<info[i].rollno<<" "<<info[i].CGPI<<" "<<info[i].Semester<<endl;
    }
    }

else{
        cout<<"Enter the info of the New Student"<<endl;
        cout << "For Student" << k  << endl;
        cout << "Enter name" << endl;
        cin >> info[k-1].name;
        cout << "Enter Roll no." << endl;
        cin >> info[k-1].rollno;
        cout << "Enter CGPI" << endl;
        cin >> info[k-1].CGPI;
        cout << "Enter Semester" << endl;
        cin >> info[k-1].Semester;

        cout<<"Updated Record:"<<endl;   
        for (int i = 0; i <l; i++)
    {
        cout<<i+1<<" "<<info[i].name<<" "<<info[i].rollno<<" "<<info[i].CGPI<<" "<<info[i].Semester<<endl;

    }
        cout<<k<<" "<<info[k-1].name<<" "<<info[k-1].rollno<<" "<<info[k-1].CGPI<<" "<<info[k-1].Semester<<endl; 

}
    return 0;
}