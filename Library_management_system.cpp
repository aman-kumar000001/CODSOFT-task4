#include <iostream>
using namespace std;
const int max_num = 100;
int count =0;
int max_days=15;
int fine = 10;  //Fine per day 10 rupees 

typedef struct book{
    int id;
    string title;
    string author;
    string isbn;
    bool in_lib;
}bk;

void add(bk lib[]);
void search(bk lib[]);
void checkout(bk lib[]);
void book_return(bk lib[]);
void book_fine();
void display(bk lib[]);

int main() {
      bk lib[max_num];
      int choice;
 do{
    cout<<"     ___Library management system___     \n"<<endl;
    
    cout<<"1.Add book.\n";
    cout<<"2.Book search.\n";
    cout<<"3.Book checkout.\n";
    cout<<"4.Book return.\n";
    cout<<"5.Fine calculation.\n";
    cout<<"6.Display all books.\n";
    cout<<"7.Exit.\n"<<endl;
    cout<<"Enter your choice:";
    cin>>choice;
    switch(choice){
        case 1: add(lib);
                break;
        case 2: search(lib);
                break;
        case 3: checkout(lib);
                break;
       case 4: book_return(lib);
               break;
       case 5: book_fine();
               break;
       case 6: display(lib); 
               break;  
       case 7:
               cout<<"You are exit successfully."<<endl;
               break;  
       default:
       cout<<"Invalid input!!"<<endl;
       cout<<"Please try again->\n"<<endl;
    }
   } while(choice!=7);
    return 0;
}

void add(bk lib[]){
    if(count>=max_num){
        cout<<"Space is not available."<<endl;
    }
    else{
        cout<<"Enter book ID:";
        cin>> lib[count].id;
        cin.ignore();
        cout<<"Enter book Title:";
        getline(cin,lib[count].title);
        cout<<"Enter book Author:";
        getline(cin,lib[count].author);
        cout<<"Enter book ISBN:";
        getline(cin,lib[count].isbn);
        lib[count].in_lib=true;
        count++;
        cout<<"Book add successfully."<<endl;
    }
}

void search(bk lib[]){
    int found=0;
    string search;
    cout<<"Enter book title, author or ISBN:";
    cin.ignore();
    getline(cin,search);
    for(int i=0;i<count;i++){
    if(search==lib[i]. title||search==lib[i].author||search ==lib[i].isbn)
    {
        cout<<endl;
        cout<<"Book ID: "<<lib[i].id<<endl;
        cout<<"Book title: "<<lib[i].title<<endl;
        cout<<"Book author: "<<lib[i].author<<endl;
        cout<<"Book ISBN: "<<lib[i].isbn<<endl;
       
        if(lib[i].in_lib){
          cout<<"Book is available.\n"<<endl;
        }else{
          cout<<"Book is not available.\n"<<endl;
        }
        found++;
    }
    }
    if(found==0){
 cout<<"\nBook not found.\n"<<endl;
    }
}

void checkout(bk lib[]){
    int id;
    cout<<"Enter book ID:";
    cin>>id;
    for(int i=0;i<count;i++){
        if(id==lib[i].id)
        {
          cout<<"Book title: "<<lib[i].title<<endl;
         cout<<"Book author: "<<lib[i].author<<endl;
         cout<<"Book ISBN: "<<lib[i].isbn<<"\n"<<endl;
         
          if(lib[i].in_lib)
          {
            lib[i].in_lib=false;
            cout<<"Book checkout successfully."<<endl;
          }
           else{
               cout<<"Book already checkout."<<endl;
           }
               return;
        }
    }
    cout<<"Book not found.\n"<<endl;
}

void book_fine(){
    int days,f; // f stands for fine
    cout<<"Enter the number of days the book was kept:";
    cin>>days;
    if(days>max_days){
        f=fine*(days-max_days);
        cout<<"Total fine on this book is Rs. "<<f<<endl<<endl;
    }
    else{
        cout<<"No fine.\n"<<endl;
    }
}

void book_return(bk lib[]){
    int id;
    cout<<"Enter book ID:";
    cin>>id;
    for(int i=0;i<count;i++){
        if(id==lib[i].id)
        {
            if(!lib[i].in_lib){
                lib[i].in_lib=true;
                cout<<"Book return successfully.\n"<<endl;
                 book_fine();
                 return;
           }
           else{
               cout<<"This book was not checked out.\n"<<endl;
               return;
           }
        }
    }
        cout<<"Book ID not found.\n"<<endl;
}

void display(bk lib[]){
    if(count==0){
        cout<<"Library is empty.\n"<<endl;
        return;
    }
      cout<<"\nLibrary book list:\n"<<endl;
    
    for(int i=0; i<count;i++)
    {
        cout<<"Book ID: "<<lib[i].id<<endl;
        cout<<"Book title: "<<lib[i].title<<endl;
        cout<<"Book author: "<<lib[i].author<<endl;
        cout<<"Book ISBN: "<<lib[i].isbn<<endl;
      
        if(lib[i].in_lib){
          cout<<"Book is available.\n"<<endl;
        }else{
          cout<<"Book is not available.\n"<<endl;
        }
       
        cout<<endl;
    }
}