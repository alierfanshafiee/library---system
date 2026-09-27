#include<iostream>
#include<string>
#include<fstream>
using namespace std;
void numloangiven(fstream& a,int n){
    fstream b;
    a.open("studentlist.txt",ios::in);
    b.open("temp-studentlist.txt",ios::out);
    if(!a.is_open()){
        cout<<"Error,didn't open"<<endl;
        return;
    }
    if(!b.is_open()){
        cout<<"Error,didn't open"<<endl;
        return;
    }
    int studentcode;
    string k;
    while(true){
        if(a>>studentcode && n==studentcode){
            string name,fieldofstudy;
            int yearofarrival,currentloanamount;
            a>>name>>fieldofstudy>>yearofarrival>>currentloanamount;
            currentloanamount+=1;
            b<<studentcode<<" "<<name<<" "<<fieldofstudy<<" "<<yearofarrival<<" "<<currentloanamount<<endl;
        }
        else if(!a.eof()){
            b<<studentcode<<" ";
            getline(a,k);
            b<<k<<endl;
        }
        else break;
    }
    a.close();
    b.close();
    remove("studentlist.txt");
    rename("temp-studentlist.txt","studentlist.txt");
}
void lendingtool(fstream& a,string m,int n){
    fstream b;
    a.open("equipmentlist.txt",ios::in);
    b.open("temp-equipmentlist.txt",ios::out);
    if(!a.is_open()){
        cout<<"Error,didn't open"<<endl;
        return;
    }
    if(!b.is_open()){
        cout<<"Error,didn't open"<<endl;
        return;
    }
    string name,k;
    int inventorynumber;
    while(true){
        if(a>>name && m==name){
            a>>inventorynumber;
            inventorynumber-=1;
            b<<name<<" "<<inventorynumber<<endl;
        }
        else if(!a.eof()){
            b<<name<<" ";
            getline(a,k);
            b<<k<<endl;
        }
        else break;
    }
    a.close();
    b.close();
    remove("equipmentlist.txt");
    rename("temp-equipmentlist.txt","equipmentlist.txt");


    a.open("loans.txt",ios::in);
    b.open("temp-loans.txt",ios::out);
    if(!a.is_open()){
        cout<<"Error,didn't open"<<endl;
        return;
    }
    if(!b.is_open()){
        cout<<"Error,didn't open"<<endl;
        return;
    }
    string nam,h;
    int numloan;
    while(true){
        if(a>>nam && nam==m){
            a>>numloan;
            numloan+=1;
            b<<nam<<" "<<numloan<<endl;
        }
        else if(!a.eof()){
            b<<nam<<" ";
            getline(a,h);
            b<<h<<endl;
        }
        else {
            numloan=1;
            b<<m<<" "<<numloan<<endl;
            break;
        }
    }
    a.close();
    b.close();
    remove("loans.txt");
    rename("temp-loans.txt","loans.txt");

    a.open("history.txt",ios::app);
    string date;
    cout<<"enter today's history :"<<endl;
    cin>>date;
    a<<"equipment"<<" "<<n<<" "<<m<<" "<<date<<endl;
    a.close();
    numloangiven(a,n);
}
void addstudent(fstream& a, string m,int n){
    a.open("studentlist.txt", ios::app);
    if(!a.is_open()){
        cout<<"Error,didn't open"<<endl;
        return;
    }
    int studentcode;//?? ????????
    string name;
    string fieldofstudy;//???? ??????
    int yearofarrival;//??? ????
    int currentloanamount;//// ????? ????? ????
    cout<<"enter your studentcode: ";
    cin>>studentcode;
    cout<<"enter your name:";
    cin>>name;
    cout<<"enter  your field of  study :";
    cin>>fieldofstudy;
    cout<<"enter  your year of arrival :"; 
    cin>>yearofarrival;
    currentloanamount=0;
    a<<studentcode<<" "<<name<<" "<<fieldofstudy<<" "<<yearofarrival<<" "<<currentloanamount<<endl;
    a.close();
    cout<<"registration completed"<<endl;
    lendingtool(a,m,n);
}
void checkstudent(fstream& a,string m){
    a.open("studentlist.txt", ios::in);
    if(!a.is_open()){
        cout<<"Error,didn't open"<<endl;
        return;
    }
    string p;//??? ?????
    int n,studentcode;
    bool found =false;
    cout<<"enter your studentcode:"<<endl;
    cin>>n;
    while(a>>studentcode){
        if(studentcode==n){
            found =true;
            cout<<"you were on the list student"<<endl;
            string name,fieldofstudy;
            int yearofarrival,currentloanamount;
            a>>name>>fieldofstudy>>yearofarrival>>currentloanamount;
            if(currentloanamount<2){
            a.close();
            lendingtool(a,m,n);
            return;
            }else { 
                cout<<"you can't borrow more than 2 equipment"<<endl;
                return;
            }
        }
        else{
            getline(a,p);
        }
    }
    if(!found){
        cout<<"you are not on the list"<<endl;
        a.close();
        addstudent(a,m,n);
        return;
    }
}
void checkinginventory(fstream& a){
    a.open("equipmentlist.txt", ios::in);
    if(!a.is_open()){
        cout<<"Error,didn't open"<<endl;
        return;
    }
    string name,m;
    int inventorynumber;
    cout<<"what device do you want ?"<<endl;
    cin>>m;
    bool found = false;
    while(a>>name>>inventorynumber){
        if(m==name){
            found =true;
            if(inventorynumber!=0){
            cout<<"available"<<endl;
            a.close();
            checkstudent(a,m);
            return;
            }else{
                cout<<"unavailable"<<endl;
            a.close();
            return;
            }
        }
    }
    if(!found){
       cout<<"unavailable"<<endl; 
    }
    a.close();
}
void backequipment(fstream& a){
    fstream b;
    a.open("studentlist.txt",ios::in);
    b.open("temp-studentlist.txt",ios::out);
    if(!a.is_open()){
        cout<<"Error,didn't open"<<endl;
        return;
    }
    if(!b.is_open()){
        cout<<"Error,didn't open"<<endl;
        return;
    }
    int studentcode;
    string k;
    int n;
    cout<<"please enter your studentcode ?"<<endl;
    cin>>n;
    while(true){
        if(a>>studentcode && n==studentcode){
            string name,fieldofstudy;
            int yearofarrival,currentloanamount;
            a>>name>>fieldofstudy>>yearofarrival>>currentloanamount;
            currentloanamount-=1;
            b<<studentcode<<" "<<name<<" "<<fieldofstudy<<" "<<yearofarrival<<" "<<currentloanamount<<endl;
        }
        else if(!a.eof()){
            b<<studentcode<<" ";
            getline(a,k);
            b<<k<<endl;
        }
        else break;
    }
    a.close();
    b.close();
    remove("studentlist.txt");
    rename("temp-studentlist.txt","studentlist.txt");
        a.open("equipmentlist.txt",ios::in);
        b.open("temp-equipmentlist.txt",ios::out);
        if(!a.is_open()){
            cout<<"Error,didn't open"<<endl;
            return;
        }
        if(!b.is_open()){
            cout<<"Error,didn't open"<<endl;
            return;
        }
        string name,p;
        int inventorynumber;
        string m;
        cout<<"which equipment do you want to give back ?"<<endl;
        cin>>m;
        while(true){
            if(a>>name && m==name){
                a>>inventorynumber;
                inventorynumber+=1;
                b<<name<<" "<<inventorynumber<<endl;
            }
            else if(!a.eof()){
                b<<name<<" ";
                getline(a,p);
                b<<p<<endl;
            }
            else break;
        }
        a.close();
        b.close();
        remove("equipmentlist.txt");
        rename("temp-equipmentlist.txt","equipmentlist.txt");

        
    a.open("loans.txt",ios::in);
    b.open("temp-loans.txt",ios::out);
    if(!a.is_open()){
        cout<<"Error,didn't open"<<endl;
        return;
    }
    if(!b.is_open()){
        cout<<"Error,didn't open"<<endl;
        return;
    }
    string nam,h;
    int numloan;
    while(true){
        if(a>>nam && nam==m){
            a>>numloan;
            numloan-=1;
            if(numloan!=0){
                b<<nam<<" "<<numloan<<endl;
            }
        }
        else if(!a.eof()){
            b<<nam<<" ";
            getline(a,h);
            b<<h<<endl;
        }
        else break;
    }
    a.close();
    b.close();
    remove("loans.txt");
    rename("temp-loans.txt","loans.txt");

    a.open("history.txt",ios::app);
    string date;
    cout<<"enter today's history"<<endl;
    cin>>date;
    a<<"back-equipment"<<" "<<n<<" "<<m<<" "<<date<<endl;
    a.close();
}
void appinformationstudent(fstream& a){
    fstream b;
    a.open("studentlist.txt",ios::in);
    b.open("temp-studentlist.txt",ios::out);
    if(!a.is_open()){
        cout<<"Error,didn't open"<<endl;
        return;
    }
    if(!b.is_open()){
        cout<<"Error,didn't open"<<endl;
        return;
    }
    int code;
    string k;
    int n;
    cout<<"please enter your studentcode ?"<<endl;
    cin>>n;
    while(true){
        if(a>>code && n==code){
            int studentcode;
            string name,q;
            string fieldofstudy,w;
            int yearofarrival,e;
            int currentloanamount,r;
            cout<<"enter your new studentcode: ";
            cin>>studentcode;
            cout<<"enter your new name:";
            cin>>name;
            cout<<"enter  your new field of  study :";
            cin>>fieldofstudy;
            cout<<"enter  your new year of arrival :"; 
            cin>>yearofarrival;
            a>>q>>w>>e>>r;
            currentloanamount=r;
            b<<studentcode<<" "<<name<<" "<<fieldofstudy<<" "<<yearofarrival<<" "<<currentloanamount<<endl;
            getline(a,k);
        }
        else if(!a.eof()){
            b<<code<<" ";
            getline(a,k);
            b<<k<<endl;
        }
        else break;
    }
    a.close();
    b.close();
    remove("studentlist.txt");
    rename("temp-studentlist.txt","studentlist.txt");
}
void increaseinventory(fstream& a){
    fstream b;
    a.open("equipmentlist.txt", ios::in);
    b.open("temp-equipmentlist.txt", ios::out);
    if(!a.is_open()){
        cout<<"Error,didn't open"<<endl;
        return;
    }
    if(!b.is_open()){
        cout<<"Error,didn't open"<<endl;
        return;
    }
    string name;
    int m,n,x;
    while(!a.eof()){
        a>>name>>m;
        cout<<"number of "<<name<<" added :"<<endl;
        cin>>n;
        x=m+n;
        b<<name<<" "<<x<<endl;
    }
    a.close();
    b.close();
    remove("equipmentlist.txt");
    rename("temp-equipmentlist.txt","equipmentlist.txt");
}
void newdevice(fstream& a){
    a.open("equipmentlist.txt",ios::app);
    string name;
    int m;
    cout<<"device name :"<<endl;
    cin>>name;
    cout<<"number of inventories :"<<endl;
    cin>>m;
    a<<name<<" "<<m<<endl;
    a.close();
}
void deletedigit(fstream& a){
    fstream b;
    a.open("equipmentlist.txt", ios::in);
    b.open("temp-equipmentlist.txt", ios::out);
    if(!a.is_open()){
        cout<<"Error,didn't open"<<endl;
        return;
    }
    if(!b.is_open()){
        cout<<"Error,didn't open"<<endl;
        return;
    }
    string name,p;
    int inventorynumber;
    string m;
    cout<<"which device had been destroyed ?"<<endl;
    cin>>m;
    while(true){
        if(a>>name && m==name){
            a>>inventorynumber;
            inventorynumber-=1;
            b<<name<<" "<<inventorynumber<<endl;
        }
        else if(!a.eof()){
            b<<name<<" ";
            getline(a,p);
            b<<p<<endl;
        }
        else break;
    }
    a.close();
    b.close();
    remove("equipmentlist.txt");
    rename("temp-equipmentlist.txt","equipmentlist.txt");

}
int main(){
    fstream a;
    int e;
    cout<<"enter 1 (for taking equipment):\nenter 2 (for taking back equipment):\nenter 3 (for append information student):\nenter 4 (for increased availability of equipment):\nenter 5 (for log new device):\nenter 6 (for log equipment failure):"<<endl;
    cin>>e;
    switch(e){
        case(1):checkinginventory(a);break;//?? ???? ?????? ????? ?????? ???
        case(2):backequipment(a);break;//???? ?? ???? ????? 
        case(3):appinformationstudent(a);break;//?????? ??????? ?????? 
        case(4):increaseinventory(a);break;//?????? ?????? ????? ??
        case(5):newdevice(a);break;//??? ????? ????
        case(6):deletedigit(a);break;//????? ? ??? ?????
    }
}