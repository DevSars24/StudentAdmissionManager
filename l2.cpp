#include <iostream>
#include <string> 

 using namespace std;


 //base class for common attributes

 class person {
protected:
  string name;
  int age;

    public :
   

    //setter methods 
 void setpersondetails(string n, int a){
   
    name = n;
    age = a;

 }
    //getter method 

    string getname() {

        return name;

    }

 };



  //abstract class for admission process
  class admission {
   public :

      virtual  bool checkeligibility(float marks) = 0;
     virtual void processadmission() = 0;

  };



  class student : public person {
private : 
     
      int rollno;
      float marks;
       
      public: 
        void setstudentdetails(string n, int a, int r,float m){
       setpersondetails(n,a);
         rollno = r;
         marks = m;


        }


   float getmarks() {

   return marks;


   }


  };


class ugadmission : public admission {
public :

  bool checkeligibility(float marks) override {
    return marks >= 60;  //ug eligibility

  }


  void processadmission() override {
     cout << "processing ug admission\n";
     }
  };




  class pgadmission : public admission {
    public :
    
      bool checkeligibility(float marks) override {
        return marks >= 70;  //ug eligibility
    
      }
    
    
      void processadmission() override {
         cout << "processing pg admission\n";
         }
      };
    
    








  int main() {


student s1;

s1.setstudentdetails("rahul",18,101,85.5);

ugadmission ug;

if(ug.checkeligibility(s1.getmarks())) {

 cout << s1.getname() << " is eligible for ug admission\n";
   ug.processadmission();

} else {
cout << s1.getname() << " is not eligible for ug admission\n" ;

}




pgadmission pg;

if(pg.checkeligibility(s1.getmarks())) {

 cout << s1.getname() << " is eligible for pg admission\n";
   ug.processadmission();

} else {
cout << s1.getname() << " is not eligible for pg admission\n" ;

}


return 0;


  }