#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// A struct to represent a student
struct Student{
    string id;      // The student's ID
    char grade;     // The student's grade
    double score = 0; // The student's score (initialized to 0)
    string ans;     // The student's answers
    bool hasPassed; // A boolean indicating whether the student has passed
};

// Function to process the results from a file and return a list of students
vector<Student> processResults(string filename){
    vector<Student> studentList;  // Vector to store all students
    string line;                  // To hold each line from the file
    string answers;               // To hold the correct answers from the file
    ifstream student_file(filename);  // Open the file for reading

    // Check if the file opened successfully
    if(student_file.is_open()){
        getline(student_file, answers); // First line of the file is the correct answers

        // Read each line containing student ID and answers
        while(getline(student_file, line)){
            Student person;  // Create a Student object
            int index = line.find(' '); // Find the space between student ID and answers

            // Extract the student ID (everything before the space)
            person.id = line.substr(0, index);
            
            // Extract student answers (everything after the space)
            string studentAnswers = line.substr(index + 1, 20); 
            person.ans = line.substr(index + 1, 20);

            // Loop through all answers and calculate the score
            for(int i = 0; i < 20; i++){
                if(studentAnswers[i] == answers[i]){ // Correct answer
                    person.score += 2;  // Award 2 points for correct answers
                } else if(studentAnswers[i] == ' '){ // No answer (skipped)
                    person.score += 0;  // No change in score
                } else if(studentAnswers[i] != answers[i]){ // Wrong answer
                    person.score -= 1;  // Deduct 1 point for wrong answers
                }
            }
            
            // Calculate percentage score (out of 100)
            person.score = (person.score / 40) * 100;

            // Determine grade based on score
            if(person.score >= 90){
                person.grade = 'A';
                person.hasPassed = true; // Passed
            }else if(person.score >= 80){
                person.grade = 'B';
                person.hasPassed = true; // Passed
            }else if(person.score >= 70){
                person.grade = 'C';
                person.hasPassed = true; // Passed
            }else if(person.score >= 60){
                person.grade = 'D';
                person.hasPassed = true; // Passed
            }else {
                person.grade = 'F';
                person.hasPassed = false; // Failed
            }

            // Add the student to the student list
            studentList.push_back(person); 
        }

    } else {
        // Display an error message if the file cannot be opened
        cout << "Unable to open transactions file." << endl; 
    }

    return studentList;  // Return the list of students
}

int main(){
    string fileName; // To store the filename entered by the user
    cout << "Kindly enter the name of the file containing the students: ";
    cin >> fileName; // Take the filename as input from the user

    // Process the student results from the file
    vector<Student> studentList = processResults(fileName);

    // Output each student's details
    for (Student student : studentList){
        cout << "Student id: " << student.id << endl;
        cout << "Student answers: " << student.ans << endl;
        cout << "Student test score: " << student.score << endl;
        cout << "Student test grade: " << student.grade << endl;
    }

    return 0;  // End of the program
}
