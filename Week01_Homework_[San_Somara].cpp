

#include<iostream>
using namespace std;
typedef struct{
    string tName;
    int tAge;
    int ID_course;
    int totalStudent;


}Teacher;

typedef struct{
    string sName;
    int sAge;
    int ID_course;
    double score;

}Student;
typedef struct{
    string cName;
    int ID_Course;

}Course;
bool CheckID(int input,int ID_course){
    for(int i=0;i<4;i++){
        if(input==ID_course){
            return true;
        }
    }
    return false;
}
void printOutPut(Student s){
   cout << "Name:"<< s.sName<<endl;
   cout <<"Age"<<s.sAge<<endl;
   cout << "Score:"<<s.score<<endl;

}

int main(){
    Course course[4]={{"WebDesign",1},{"Algorithm",2},{"Database",3},{"JavaStript",4}};//array of course
    int sizeOfstudent=5;
    int inputCourseIdOfTeacher;
    Student student[sizeOfstudent]={{"Dara",20,1,85.5},{"Mara",19,3,82.4},{"Lisa",21,1,91.0},{"Sophea",20,1,78.5},{"Ous",21,4,75.8}};//array of student
    int sizeOfTeacher=2;
    Teacher teacher[sizeOfTeacher]={{"Mr.Sok",35,1,3},{"Mr.Sor",32,2,4}}; // array of teacher
     
    


    cout<<"Enter Course ID ";
    cin>>inputCourseIdOfTeacher; 

    for(int i=0;i<4;i++){ //4 is total of course
        if(inputCourseIdOfTeacher==course[i].ID_Course){
            cout<<"-------------------------------------------------------------------"<<endl;
            cout<<"-------------------------------------------------------------------"<<endl;
            cout<<"                          COURSE IFORMATION                        "<<endl;
            cout<<"-------------------------------------------------------------------"<<endl;
            cout<<"-------------------------------------------------------------------"<<endl;

            cout << "Course Name: " << course[i].cName << endl;
            cout << "Course ID: " << course[i].ID_Course << endl;

            cout<<"Teacher"<<endl;
            cout<<"----------------------------------------"<<endl;
            
            for(int j=0;j<sizeOfTeacher;j++){
                if(course[i].ID_Course==teacher[j].ID_course){
                   cout<<"Name:"<<teacher[j].tName<<endl;
                   cout<<"Age:"<<teacher[j].tAge<<endl;
                   cout <<endl; 
                }

            }
            
            int studentCount = 0;
            for(int k=0;k<sizeOfstudent;k++){
                if(student[k].ID_course==inputCourseIdOfTeacher){
                    studentCount++;
                }
            }

            cout << "\nStudents (" << studentCount << ")" << endl;
            cout << "----------------------------------------" << endl;
            for (int k = 0; k < sizeOfstudent; k++) {

                if (student[k].ID_course == inputCourseIdOfTeacher) {

                    printOutPut(student[k]);

                    cout << "----------------------------------------" << endl;
                }
            }
        }
    }

     
    

 return 0;
}