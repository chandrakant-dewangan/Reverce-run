#include <iostream>
#include <iomanip> 

using namespace std;
double calculateGradePoint(char grade) {
    switch (grade) {
        case 'A':
        case 'a':
            return 4.0;
        case 'B':
        case 'b':
            return 3.0;
        case 'C':
        case 'c':
            return 2.0;
        case 'D':
        case 'd':
            return 1.0;
        case 'F':
        case 'f':
            return 0.0;
        default:
            return -1.0; 
    }
}

int main() {
    int numCourses;
    cout << "\t\tEnter number of courses: ";
    cin >> numCourses;
    
    double totalCreditHours = 0.0;
    double totalGradePoints = 0.0;
    
    for (int i = 0; i < numCourses; ++i) {
        cout << "Course " << i + 1 << ":" << endl;
        
        char grade;
        cout << "\t\tEnter grade (A, B, C, D, F): ";
        cin >> grade;
        
        double gradePoint = calculateGradePoint(grade);
        if (gradePoint == -1.0) {
            cout << "\t\tInvalid grade entered. Exiting." << endl;
            return 1; 
        }
        
        int creditHours;
        cout << "\t\tEnter credit hours: ";
        cin >> creditHours;
        
        totalCreditHours += creditHours;
        totalGradePoints += gradePoint * creditHours;
    }
    
    
    if (totalCreditHours > 0) {
        double GPA = totalGradePoints / totalCreditHours;
        cout << fixed << setprecision(2); 
        cout << "\t\tGPA for this semester: " << GPA << endl;
    } else {
        cout << "\t\tError: Total credit hours cannot be zero." << endl;
        return 1; 
    }
    
    char calculateCGPA;
    cout << "\t\tDo you want to calculate CGPA (Y/N)? ";
    cin >> calculateCGPA;
    
    if (calculateCGPA == 'Y' || calculateCGPA == 'y') {
        double previousCGPA = 3.5; 
        int previousTotalCreditHours = 60; 
        
        double CGPA = (previousCGPA * previousTotalCreditHours + totalGradePoints) / (previousTotalCreditHours + totalCreditHours);
        cout << fixed << setprecision(2); 
        cout << "\t\tCGPA: " << CGPA << endl;
    } else {
        cout << "\t\tExiting without calculating CGPA." << endl;
    }
    
    return 0; 
}
