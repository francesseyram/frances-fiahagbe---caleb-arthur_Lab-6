#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


// A struct to represent a student
struct Student{
    string id; // their Id
    char grade; //the students grade
    double score = 0; //the students scores
    string ans;
    bool hasPassed; //a bool to represent whether the student has passed
};

vector<Student> processResults(string filename){
    vector <Student> studentList;
    string line;
    string answers;
    ifstream student_file (filename);

    if(student_file.is_open()){
        getline(student_file,answers);

        while(getline(student_file,line)){
            Student person;
            int index = line.find(' ');
            person.id = line.substr(0,index);
            string studentAnswers = line.substr(index+1,20);
            person.ans = line.substr(index+1,20);
            for(int i = 0; i< 20 ;i++){
                if(studentAnswers[i] == answers[i]){
                    person.score += 2;
                }else if(studentAnswers[i] == ' '){
                    person.score += 0;
                }else if(studentAnswers[i] != answers[i] ){
                    person.score -= 1;
                }
            }
            
            person.score = (person.score/40)*100;
            if(person.score >= 90){
                person.grade = 'A';
                person.hasPassed = true;
            }else if(person.score >= 80){
                person.grade = 'B';
                person.hasPassed = true;
            }else if(person.score >= 70){
                person.grade = 'C';
                person.hasPassed = true;
            }else if(person.score >= 60){
                person.grade = 'D';
                person.hasPassed = true;
            }else {
                person.grade = 'F';
                person.hasPassed = false;
            }

           studentList.push_back(person); 
        }

    }else{
        cout << "Unable to open transactions file." << endl; // Error message if file can't be opened
    }

return studentList;   
}

int main(){
    string fileName;
    cout << "Kindly enter the name of the file containing the students: ";
    cin >> fileName;
    vector <Student> studentList = processResults(fileName);
    for (Student student: studentList){
        cout << "Student id: " << student.id <<endl;
        cout<< "Student answers: " << student.ans <<endl;
        cout <<"student test score: "<< student.score <<endl;
        cout <<"Student test grade: " << student.grade <<endl;
    }
    return 0;
}
