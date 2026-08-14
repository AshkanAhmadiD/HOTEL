#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
using namespace std;

class admin{
public:
    string name;
    string lastname;
    string username;
    string password;
    void toconfirm();
    void LoginAdmin();
    void showhotellist();
    void AddHotel();
    bool AdminCheck(string u , string p);

};
void admin::toconfirm(){
 string hotelname;
    cout << "enter hotel name" << '\n';
    cin >> hotelname;

    fstream file("HOTEL.txt", ios::in);
    fstream temp("temp.txt", ios::out);

    if(file.is_open() && temp.is_open()){
        string line;
        bool found = false;

        while(getline(file, line)){
            string name = "";
            string rest = "";
            int i = 0;
            while(i < line.length() && line[i] != ','){
                name += line[i];
                i++;
            }

            if(i < line.length()){
                rest = line.substr(i);
            }

            if(name == hotelname){
                found = true;


                string newLine = "";
                bool changed = false;

                for(int j = 0; j < line.length(); j++){
                    if(line[j] == '1' && !changed){
                        newLine += '2';
                        changed = true;
                    }else{
                        newLine += line[j];
                    }
                }

                temp << newLine << '\n';
            }else{
                temp << line << '\n';
            }
        }

        file.close();
        temp.close();

        remove("HOTEL.txt");
        rename("temp.txt", "HOTEL.txt");

        if(found){
            cout << "hotel selected successfully" << '\n';
        }else{
            cout << "hotel not found" << '\n';
        }
    }else{
        cout << "file problem" << '\n';
    }
}
void admin::showhotellist(){
fstream hotelsFile("HOTEL.txt", std::ios::in);
if(hotelsFile.is_open()){
    string line;
    cout << "hotels list(name,numbers room,is room full(2-yes ; 0-no ; 1-checking)?)" << '\n';
    while(getline(hotelsFile, line)){
        cout << line << '\n';
    }
    hotelsFile.close();
}else {
cout << "hotel list is not found" << '\n';
}

}
void admin::LoginAdmin(){
cout << "enter name " << '\n';
cin >> name ;
cout << "enter lastname" << '\n';
cin >> lastname;
cout << "enter username" << '\n';
cin >> username;
cout << "enter password" << '\n';
cin >> password;

}
void admin::AddHotel(){
string HotelName;
int numbersroom;
bool roomfull = 0;
cout << "enter hotel name " << '\n';
cin >> HotelName;
cout << "enter numbers room" << '\n';
cin >> numbersroom;
fstream hotelsFile("HOTEL.txt", ios::app);
if(hotelsFile.is_open()){
    hotelsFile << HotelName << "," << numbersroom <<" , " << roomfull << "\n";
    hotelsFile.close();
}else{
cout << "hotels file is not found!" << '\n';
}
}
bool admin::AdminCheck(string u , string p){
    fstream file("admin.txt");
    if(file.is_open()){
        string file_u , file_p;
        while(file >> file_u >> file_p){
            if(file_u == u && file_p == p){
                return true;
            }
        }
    }else{
        cout << "file not found" << '\n';
        return false;
        }

return false;

}
void MainMenue (){
cout << "1-admin" << '\n';
cout << "2-applicant" << '\n';
cout << "3-exit" << '\n';

}
void AdminMenue(){
cout << "1-show list of hotels" << '\n';
cout << "2-add a hotel" << '\n';
cout << "3-to confirm" << '\n';
cout << "4-exit" << '\n';

}
class applicant{
public:
    string name;
    string lastname;
    void addapplicant();
    void selecthotel();
    void showhotellist();

};
void applicant::addapplicant(){
cout << "enter name"<<'\n';
cin >> name;
cout << "enter lastname" << '\n';
cin >> lastname;

}
void applicant::selecthotel(){
    string hotelname;
    cout << "enter hotel name" << '\n';
    cin >> hotelname;

    fstream file("HOTEL.txt", ios::in);
    fstream temp("temp.txt", ios::out);

    if(file.is_open() && temp.is_open()){
        string line;
        bool found = false;

        while(getline(file, line)){
            string name = "";
            string rest = "";
            int i = 0;
            while(i < line.length() && line[i] != ','){
                name += line[i];
                i++;
            }

            if(i < line.length()){
                rest = line.substr(i);
            }

            if(name == hotelname){
                found = true;


                string newLine = "";
                bool changed = false;

                for(int j = 0; j < line.length(); j++){
                    if(line[j] == '0' && !changed){
                        newLine += '1';
                        changed = true;
                    }else{
                        newLine += line[j];
                    }
                }

                temp << newLine << '\n';
            }else{
                temp << line << '\n';
            }
        }

        file.close();
        temp.close();

        remove("HOTEL.txt");
        rename("temp.txt", "HOTEL.txt");

        if(found){
            cout << "hotel selected successfully" << '\n';
        }else{
            cout << "hotel not found" << '\n';
        }
    }else{
        cout << "file problem" << '\n';
    }
}
void applicant::showhotellist(){

fstream hotelsFile("HOTEL.txt", std::ios::in);
if(hotelsFile.is_open()){
    string line;
    cout << "hotels list(name,numbers room,is room full(2-yes ; 0-no ; 1-checking)?)" << '\n';
    while(getline(hotelsFile, line)){
        cout << line << '\n';
    }
    hotelsFile.close();
}else {
cout << "hotel list is not found" << '\n';
}

}
void applicantmenue(){
cout << "1- show a list of hotels" << '\n';
cout << "2- i want select a hotel" << '\n';
cout << "3- exit " << '\n';
}
int main (){
    bool exit = 0;
while(exit == 0){
system("cls");
MainMenue();
int num;
cin >> num;

 system("cls");
if(num == 1){
    admin a1;
    a1.LoginAdmin();
    bool tmp = a1.AdminCheck(a1.username , a1.password);
    if(tmp == 1){
         system("cls");
        AdminMenue();
        int sum;
        cin >> sum;
        system("cls");
        if(sum == 2){
            a1.AddHotel();
        }else if(sum == 1){
            system("cls");
        a1.showhotellist();
        int x;
        cout << "1-exit" << '\n';
        cin >> x;
        }else if(sum == 3){
        a1.toconfirm();
        }else if(sum == 4){}
        else{
            cout << "number is not enter correctly" << '\n';
        }
    }else{
        system("cls");
    cout << "admin is not fount " << '\n';
    }
}
else if(num == 2){

applicant a2;
a2.addapplicant();
system("cls");
applicantmenue();
int sum;
cin >> sum ;
system("cls");
if (sum == 2){
    a2.selecthotel();
}else if (sum == 1){
    a2.showhotellist();
    cout << "1-exit" << '\n';
    int tmp;
    cin >> tmp;
}else if(sum == 3){

        }else{
cout << "number is not enter correctly" << '\n';
}
}
else if (num == 3){
cout << "Do you want to exit?" << '\n';
cout << "1- YES" << '\n';
cout << "2-NO" << '\n';
int sum;
cin >> sum;
if (sum == 1){
    exit = 1;
}
}
}
}
