#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    struct Student{
        string id;
        char grade;
        double score;
        string answers;
        bool hasPassed;
    };

    vector<Student> students_;

    string answers;
    ifstream myfile ("text.txt");
    if(myfile.is_open()){
        getline(myfile, answers);

        string otherLines;
        while (getline(myfile, otherLines))
        {
            Student student;
            student.score = 0;
            int index = otherLines.find(" ");
            student.id = otherLines.substr(0, index);
            string stdentAnswers = otherLines.substr(index+1, 20);
            student.answers = stdentAnswers;

            for(int i = 0; i < 20; i++){
                if(stdentAnswers[i] == answers[i]){
                    student.score += 2;
                }
                else if(stdentAnswers[i] == ' '){
                    student.score -= 1;
                }
                else if(stdentAnswers[i] != answers[i]){
                    student.score += 0;
                }
            }
            student.score = (student.score / 40) * 100;

            if(student.score >= 80){
                student.grade = 'A';
                student.hasPassed = true;
            }
            else if (student.score>= 70){
                student.grade = 'B';
                student.hasPassed = true;
            }
            else if(student.score >= 60){
                student.grade = 'C';
                student.hasPassed = true;
            }
            else if(student.score >= 50){
                student.grade = 'D';
                student.hasPassed = false;
            }
            else{
                student.grade = 'F';
                student.hasPassed = false;
            }

            students_.push_back(student);
        }


    }

    for(Student stud : students_){
        cout <<"Student ID: " << stud.id << " Student Answers: " <<stud.answers << " Test Score: " << stud.score << " Test Grade: " << stud.grade<<"\n";
    }
    return 0;
}