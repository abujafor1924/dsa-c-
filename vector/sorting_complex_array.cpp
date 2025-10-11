#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric> // for accumulate

using namespace std;

int totalMarks(const vector<int> &marks) {
    return accumulate(marks.begin(), marks.end(), 0);
}

double averageMarks(const vector<int> &marks) {
    if (marks.empty()) return 0.0;
    return static_cast<double>(totalMarks(marks)) / marks.size();
}

// Compare by name (ascending)
bool compareByName(const pair<string, vector<int>> &a, const pair<string, vector<int>> &b) {
    return a.first < b.first;
}

// Compare by total marks (descending)
bool compareByTotalMarks(const pair<string, vector<int>> &a, const pair<string, vector<int>> &b) {
    return totalMarks(a.second) > totalMarks(b.second);
}

// Compare by average marks (descending)
bool compareByAverage(const pair<string, vector<int>> &a, const pair<string, vector<int>> &b) {
    return averageMarks(a.second) > averageMarks(b.second);
}

void printStudents(const vector<pair<string, vector<int>>> &students) {
    cout << "\nStudent Records:\n";
    cout << "----------------\n";
    for (const auto &student : students) {
        cout << "Name: " << student.first << "\n";
        cout << "Marks: ";
        for (int mark : student.second) {
            cout << mark << " ";
        }
        cout << "\nTotal: " << totalMarks(student.second);
        cout << ", Average: " << averageMarks(student.second) << "\n";
        cout << "----------------\n";
    }
}

int main() {
    vector<pair<string, vector<int>>> student_marks = {
        {"Abu", {90, 80, 70}},
        {"Jafor", {85, 75, 65}},
        {"Khan", {88, 78, 68}},
        {"David", {92, 82, 72}},
        {"Charlie", {87, 77, 67}}
    };

    // Sort by name (ascending)
    cout << "=== Sorted by Name (Ascending) ===";
    sort(student_marks.begin(), student_marks.end(), compareByName);
    printStudents(student_marks);

    // Sort by total marks (descending)
    cout << "\n=== Sorted by Total Marks (Descending) ===";
    sort(student_marks.begin(), student_marks.end(), compareByTotalMarks);
    printStudents(student_marks);

    // Sort by average marks (descending) using lambda
    cout << "\n=== Sorted by Average Marks (Descending) using Lambda ===";
    sort(student_marks.begin(), student_marks.end(), [](const auto &a, const auto &b) {
        return averageMarks(a.second) > averageMarks(b.second);
    });
    printStudents(student_marks);

    // Find student with highest total marks
    auto highestScorer = max_element(student_marks.begin(), student_marks.end(),
        [](const auto &a, const auto &b) {
            return totalMarks(a.second) < totalMarks(b.second);
        });
    
    if (highestScorer != student_marks.end()) {
        cout << "\n=== Highest Scorer ===" << endl;
        cout << "Name: " << highestScorer->first << endl;
        cout << "Total Marks: " << totalMarks(highestScorer->second) << endl;
        cout << "Average: " << averageMarks(highestScorer->second) << endl;
    }

    // Calculate class average
    double classTotal = 0;
    int totalSubjects = 0;
    for (const auto &student : student_marks) {
        classTotal += totalMarks(student.second);
        totalSubjects += student.second.size();
    }
    double classAverage = classTotal / totalSubjects;
    cout << "\nClass Average: " << classAverage << endl;

    return 0;
}