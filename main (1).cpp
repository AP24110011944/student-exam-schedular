#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Exam {
    string name;
    int start;
    int end;
};
bool compare(Exam a, Exam b) {
    return a.end < b.end;
}
int main() {
    int n;
    cout << "Enter number of exams: ";
    cin >> n;

    vector<Exam> exams(n);
    cout << "Enter exam name, start time, end time:\n";
    for (int i = 0; i < n; i++) {
        cin >> exams[i].name >> exams[i].start >> exams[i].end;
    }

    sort(exams.begin(), exams.end(), compare);
    cout << "\nScheduled Exams (No Conflict):\n";
    int lastEnd = -1;
    for (int i = 0; i < n; i++) {
        if (exams[i].start >= lastEnd) {
            cout << exams[i].name << " (" << exams[i].start 
                 << " - " << exams[i].end << ")\n";
            lastEnd = exams[i].end;
        }
    }

    return 0;
}