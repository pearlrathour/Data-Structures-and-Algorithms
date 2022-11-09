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
    // struct student info[100];
    student *info = new student[l];

    // Taking INPUT of Information:
    for (int i = 0; i < l; i++)
    {
        cout << "For Student : " << i + 1 << endl;
        cout << "Enter name : ";
        cin >> info[i].name;
        cout << "Enter Roll no. : ";
        cin >> info[i].rollno;
        cout << "Enter CGPI : ";
        cin >> info[i].CGPI;
        cout << "Enter Semester : ";
        cin >> info[i].Semester;
    }

    // Printing the info of students with CGPI over k
    float k;
    cout << "Enter the value of K" << endl;
    cin >> k;
    cout << "Student with CGPI greater than " << k << endl;
    for (int i = 0; i < l; i++)
    {
        if (info[i].CGPI > k)
        {
            cout << i + 1 << " " << info[i].name << " " << info[i].rollno << " " << info[i].CGPI << " " << info[i].Semester << endl;
        }
    }

    // Insert at kth position
    // Shifting elements of the info array
    int k1;
    cout << "Enter the value of K1" << endl;
    cin >> k1;
    student *info1 = new student[l + 1];
    for (int i = 0; i < l; i++)
    {
        info1[i].name = info[i].name;
        info1[i].rollno = info[i].rollno;
        info1[i].CGPI = info[i].CGPI;
        info1[i].Semester = info[i].Semester;
    }
    info = info1;
    if (k1 < l)
    {
        for (int i = l - 1; i >= k1 - 1; i--)
        {
            info[i + 1] = info[i];
        }
        cout << "Enter the info of the New Student" << endl<< endl;
        cout << "For Student " << k1 << endl;
        cout << "Enter name" << endl;
        cin >> info[k1 - 1].name;
        cout << "Enter Roll no." << endl;
        cin >> info[k1 - 1].rollno;
        cout << "Enter CGPI" << endl;
        cin >> info[k1 - 1].CGPI;
        cout << "Enter Semester" << endl;
        cin >> info[k1 - 1].Semester;

        cout << "Updated Record:" << endl;
        for (int i = 0; i <= l; i++)
        {
            cout << i + 1 << " " << info[i].name << " " << info[i].rollno << " " << info[i].CGPI << " " << info[i].Semester << endl;
        }
    }

    else
    {
        cout << "Enter the info of the New Student" << endl;
        cout << "For Student" << k << endl;
        cout << "Enter name" << endl;
        cin >> info[k1 - 1].name;
        cout << "Enter Roll no." << endl;
        cin >> info[k1 - 1].rollno;
        cout << "Enter CGPI" << endl;
        cin >> info[k1 - 1].CGPI;
        cout << "Enter Semester" << endl;
        cin >> info[k1 - 1].Semester;

        cout << "Updated Record:" << endl;
        for (int i = 0; i < l; i++)
        {
            cout << i + 1 << " " << info[i].name << " " << info[i].rollno << " " << info[i].CGPI << " " << info[i].Semester << endl;
        }
        cout << k << " " << info[k1 - 1].name << " " << info[k1 - 1].rollno << " " << info[k1 - 1].CGPI << " " << info[k1 - 1].Semester << endl;
    }
    return 0;
}