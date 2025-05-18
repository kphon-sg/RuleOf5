
// ==============================
// 📘 TỔNG HỢP: CÁC HÀM ĐẶC BIỆT TRONG C++
// Constructor, Copy, Move, Destructor – Rule of 5
// ==============================

#include <iostream>
#include <cstring>
using namespace std;

class Student {
private:
    char* name;
    int* scores;
    int numScores;

public:
    // ✅ Constructor
    Student(const char* studentName, const int* inputScores, int count) {
        cout << "[Constructor] called\n";
        numScores = count;
        name = new char[strlen(studentName) + 1];
        strcpy(name, studentName);
        scores = new int[numScores];
        for (int i = 0; i < numScores; ++i)
            scores[i] = inputScores[i];
    }

    // ✅ Copy Constructor
    Student(const Student& other) {
        cout << "[Copy Constructor] called\n";
        numScores = other.numScores;
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        scores = new int[numScores];
        for (int i = 0; i < numScores; ++i)
            scores[i] = other.scores[i];
    }

    // ✅ Copy Assignment
    Student& operator=(const Student& other) {
        cout << "[Copy Assignment] called\n";
        if (this != &other) {
            delete[] name;
            delete[] scores;
            numScores = other.numScores;
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
            scores = new int[numScores];
            for (int i = 0; i < numScores; ++i)
                scores[i] = other.scores[i];
        }
        return *this;
    }

    // ✅ Move Constructor
    Student(Student&& other) noexcept {
        cout << "[Move Constructor] called\n";
        name = other.name;
        scores = other.scores;
        numScores = other.numScores;
        other.name = nullptr;
        other.scores = nullptr;
        other.numScores = 0;
    }

    // ✅ Move Assignment
    Student& operator=(Student&& other) noexcept {
        cout << "[Move Assignment] called\n";
        if (this != &other) {
            delete[] name;
            delete[] scores;
            name = other.name;
            scores = other.scores;
            numScores = other.numScores;
            other.name = nullptr;
            other.scores = nullptr;
            other.numScores = 0;
        }
        return *this;
    }

    // ✅ Destructor
    ~Student() {
        cout << "[Destructor] called for " << (name ? name : "[null]") << endl;
        delete[] name;
        delete[] scores;
    }

    // ✅ Display info
    void print() const {
        cout << "Name: " << (name ? name : "[null]") << " | Scores: ";
        for (int i = 0; i < numScores; ++i)
            cout << scores[i] << " ";
        cout << endl;
    }
};

// ==============================
// 🧪 TEST MAIN FUNCTION
// ==============================

int main() {
    int scores[] = {80, 90, 100};
    Student s1("Alice", scores, 3);
    Student s2 = s1;               // Copy Constructor
    Student s3 = Student("Bob", scores, 3); // Move Constructor

    s2 = s1;                       // Copy Assignment
    s2 = std::move(s3);            // Move Assignment

    cout << "\n-- INFO --\n";
    s1.print();
    s2.print();
    s3.print(); // s3 now empty

    return 0;
}
