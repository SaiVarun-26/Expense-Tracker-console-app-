// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
class Expense{
public:
    string category;
    double expense;
    string date;
    
    void input(){
        cout<<"enter category:";
        cin>>category;
        cout<<"Expenses:";
        cin>>expense;
        cout<<"Date:";
        cin>>date;
    }
    void display(){
        cout<<"Category:"<<category<<",Expenses:"<<expense<<",Date:"<<date<<endl;
    }
    
};
class ExpenseManager{
public:
    vector<Expense> expenses;
    void displaymenu(){
    cout<<"******Expense Tracker******\n\n";
    cout<<"1.Add expense\n";
    cout<<"2.View all expenses\n";
    cout<<"3.Save and Exit\n\n";
    
    
    cout<<"enter your choice:";
    }
    void addexpense(){
        Expense e;
        e.input();
        expenses.push_back(e);
        cout<<"expense added successfully\n";
        
    }
    void viewall(){
        cout<<"\n All Expenses\n";
        for(int i=0;i<expenses.size();i++){
            expenses[i].display();
        }
        
    }
    void savetofile(){
        ofstream file("expenses.csv");
        if(!file){
            cout<<"Error opening file";
            return;
        }
        file<<"Category,Expense,Date\n";
        for(int i=0;i<expenses.size();i++){
            file<<expenses[i].category<<","<<expenses[i].expense<<","<<expenses[i].date<<"\n";
        }
        file.close();
        cout<<"Expenses saved to expenses.csv\n";
    }
};
int main(){
     ExpenseManager manager;
     int choice;
     while(true){
         manager.displaymenu();
         cin>>choice;
        
        if(choice==1){
            manager.addexpense();
        }
        else if(choice==2){
            manager.viewall();
        }
        else if(choice==3){
            manager.savetofile();
            cout<<"Exiting Program...\n";
            break;
        }
        else{
            cout<<"Invalid input,Check again..";
        }
     }
     cout << endl;
    return 0;
}
