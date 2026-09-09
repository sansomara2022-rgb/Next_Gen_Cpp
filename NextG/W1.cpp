// #include <iostream>
// using namespace std;
// int main(){
//     int age=20;
//     int *p=&age;
    
//     cout << "Age="<< age << " old." << endl;
//     *p=25;
//     cout << "Updated age="<< age << endl;

//     return 0;
// }

//Challenge o2
    // problem A

// #include <iostream>
// using namespace std;
//  int main(){
//     int* ptr;
//     *ptr=100;
//     cout <<*ptr<<endl;
//     return 0;
//  }


 //1.What is worng?
 // Initialize it with nullptr.
 //2.why is it dangerous?
 //program crash undefined behaver.
 //3. How can you fix it?
 // declard varible for store the value of ptr.
 

     //peblem B

// #include <iostream>
// using namespace std;
// int main() {
//   int* ptr = new int(50);
//   delete ptr;
//   cout << *ptr << endl;
//   return 0;
// }
  
  //1.what is worng?
  // pointer ptr is deleted, but the program tries to use it afterward.
  //2. why is it dangerous?
  // Using it can cause undefined behavior, crashes, or incorrect results.
  //3. How can you fix it?
  //cout << *ptr << endl;
  //delete ptr;

  //problem C
#include <iostream>
using namespace std;
  int main() {
  int* ptr = new int(100);
  cout << *ptr << endl;
  return 0;
}

     //problem D
 
// #include <iostream>
// using namespace std;
// int main() {
// int* ptr = new int(200);
// delete ptr;
// delete ptr;
// return 0;
// }
  
  //1.what is wrong?
  //  Freed a memory twice
  //2. why is it dangerous?
  //  After the first delete, the memory has already been released. Deleting it again causes undefined behavior and can crash the program or corrupt memory.
  //3.How can you fix it?
  //  Delete the pointer only once.