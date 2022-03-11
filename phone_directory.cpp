#include<iostream>
#include<string>
using namespace std;
struct node{
string firstname;
string lastname;
string contact;
node*next;

};
class list{
    private:
    node*head;
    node*tail;
    public :
    list(){
        head=NULL;
        tail=NULL;

    }

void create(string first,string last,string contact){
    struct node*temp=new node;
    temp->firstname=first;
    temp->lastname=last;
    temp->contact=contact;
    temp->next=NULL;
    if (head==NULL){
        head=temp;
        tail=temp;
        temp=NULL;
  }
  else{
      tail->next=temp;
      tail=temp;

  }
    
}
void display_all(){
  struct node *temp=head;

  int contactno=1;
 // struct node*p=head;
while(temp!=NULL){
cout<<contactno<<endl;
cout<<"eneter the first name"<<temp->firstname<<endl;
cout<<"eneter the last name"<<temp->lastname<<endl;
cout<<"contact number"<<temp->contact<<endl;
++contactno;
temp=temp->next;
}    
    
}
void delete_pos(int pos){
    node*current=new node;
    node*previous=new node;
    node*next=new node;
    current=head;
    
    for(int i=1; i<pos-1; i++){
    if(current==NULL)
    return ;
        previous=current;
        current=current->next;
    }
    next=current->next;
    previous->next=current->next;
    delete current;
}
void delete_head(){
    struct node*temp=new node;
    temp=head;
    head=head->next;
    delete temp;
}
    

};
int main(){
    list cont;
int choice,position;
string first;
string last;
string contact;

while(1){
    cout<<"what should like to do?"<<endl;
    cout<<"1.show all conatcts"<<endl;
    cout<<"2. add a contact"<<endl;
    cout<<"3.remove a contact"<<endl;
    cout<<"4.search contact(comming soon)"<<endl;
    cout<<"5.exit the progarmme"<<endl;
    cin>>choice;
    switch(choice){
        case 1:
        cout<<endl;
        cont.display_all();
        cout<<endl;
        break;
        case 2:
        cout<<"enter your first name"<<endl;
        cin>>first;
        cout<<"enter your last name"<<endl;
        cin>>last;
        cout<<"enter contact no"<<endl;
        cin>>contact;
        cont.create(first,last,contact);
        cout<<endl;
        break;
        case 3:
        cout<<"enter the contact number of the contact you should want to remove :";
        cin>>position;
        if(position==1)
        cont.delete_head();
        else
        cont.delete_pos(position);
        break;
        case 5:
        exit(1);
        default:
        cout<<"\n"<<"choice is not valid please select a valid option ";
        break;
    }
    }
    return 0; 
}

        