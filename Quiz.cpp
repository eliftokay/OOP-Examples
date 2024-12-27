#include <iostream>
#include <string>

using namespace std;

class Quiz {
private:
    string questions[2];
    string answers[2];

public:
    Quiz(const string questions[2]) {
        for (int i = 0; i < 2; ++i) {
            this->questions[i] = questions[i];
        }
    }

    Quiz(const Quiz& other) {
        for (int i = 0; i < 2; ++i) {
            questions[i] = other.questions[i];
            answers[i] = other.answers[i];
        }
    }

    void addAnswers(const string answers[2]) {
        for (int i = 0; i < 2; ++i) {
            this->answers[i] = answers[i];
        }
    }

    void printQuiz() const {
        cout << "Questions and Answers:" << endl;
        for (int i = 0; i < 2; ++i) {
            cout << "Q: " << questions[i];
            if (!answers[i].empty()) {
                cout << " - A: " << answers[i];
            }
            else {
                cout << " - A: (No answer)";
            }
            cout << endl;
        }
    }
};

int main() {
    string questions[2] = { "What is Java?", "What is inheritance?" };
    Quiz quiz1(questions);

    Quiz quiz1WithAnswers(quiz1);

    string answers[2] = { "A programming language.", "A concept in OOP." };
    quiz1WithAnswers.addAnswers(answers);

    cout << "Quiz 1:" << endl;
    quiz1.printQuiz();

    cout << "\nQuiz 1 with Answers:" << endl;
    quiz1WithAnswers.printQuiz();

    return 0;
}