#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>

using namespace std;

map<string, double> grades = {
    {"A+", 4.00},
    {"A", 3.75},
    {"B+", 3.50},
    {"B", 3.00},
    {"C+", 2.50},
    {"C", 2.00},
    {"D+", 1.50},
    {"D", 1.00},
    {"F", 0}
};

struct Student {
    string lastname;
    string firstname;
    double gpa;
};

bool compareStudents(const Student &a, const Student &b) {
    if (a.gpa != b.gpa)
        return a.gpa < b.gpa;
    if (a.lastname != b.lastname)
        return a.lastname < b.lastname;
    return a.firstname < b.firstname;
}


int main() {
    int n;
    cin >> n;

    vector<Student> students(n);

    for (int i = 0; i < n; ++i) {
        cin >> students[i].lastname >> students[i].firstname;

        int m;
        cin >> m;
        double totalGrade = 0, totalCredits = 0;

        for (int j = 0; j < m; ++j) {
            string grade;
            int credit;
            cin >> grade >> credit;
            totalGrade += grades[grade] * credit;
            totalCredits += credit;
        }
        students[i].gpa = totalGrade / totalCredits;
    }

    sort(students.begin(), students.end(), compareStudents);

    for (const Student &student : students) {
        cout << student.lastname << " " << student.firstname << " " << fixed << setprecision(3) << student.gpa << endl;
    }

    return 0;
}



