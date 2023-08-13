//&Student Grading System

#include <iostream>
#include <string>

class GradingSystem{
    private:
        int number_of_students = 5;
        int total_grade = 0, average = 0, grade;
        int* averageGrade = new int[number_of_students];
        int* temp_storage = new int[number_of_students];

        std::string* name_of_students = new std::string[number_of_students];
        std::string name;

    public:
        void set_the_value(){
            for(int x=0;x<number_of_students;x++){
                averageGrade[x] = 0;
                name_of_students[x] = "0";
            }
        }
        void display(){
            std::cout << "\nNames --------------------- Grades";
            for(int x=0;x<number_of_students;x++){
                std::cout << "\nName of student: " << name_of_students[x] << "       Average: " << averageGrade[x];
            }
        }
        void Name_input(std::string x, int y){
            name_of_students[y] = x;
        }
        void student_grade_input(int x, int y){
            averageGrade[y]=x;
        }
        int Students_number(){
            return number_of_students;
        }
        int Grade_input(int n){
            if(n==0){
                return 0;
            }
            else{
                std::cout << "\nInput student grade: "; std::cin >> grade;
                temp_storage[n-1]=grade;
                return Grade_input(n-1);    
            }
        }
        int General_Average(int x){
            average = x;
            for(int x=0;x<5;x++){
                average += temp_storage[x];
            }
            return average/5;
        }
};

int main(){
    GradingSystem GS;

    GS.set_the_value();
    std::string name;
    int number = 0, num =0;

    std::cout << "\n--Student Grading System--";
    do{
        if(number==5){
            break;
        }
        else{
            std::cout << "\nInput student name: "; std::getline(std::cin, name);
            GS.Name_input(name, number);  

            int sn = GS.Students_number();
            int gi = GS.Grade_input(sn);
            int ga = GS.General_Average(num);

            GS.student_grade_input(ga, number);

            number++;
            std::cin.ignore();
        }
    }while(number!=5);

    GS.display();

}