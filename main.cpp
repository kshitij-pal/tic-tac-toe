#include <iostream>

using namespace std;

char s[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row, column;
char token = 'X';
bool tie = false;
string n1, n2;
void func_1(){
    // print the diagram

    cout<<"\t\t\t|\t\t|\t\t\n";
    cout<<"\t\t"<<s[0][0]<<"\t|\t"<<s[0][1]<<"\t|\t"<<s[0][2]<<"\n";
    cout<<"\t\t\t|\t\t|\t\t\n";
    cout<<"\t\t------    ------------    ------\n";

    cout<<"\t\t\t|\t\t|\t\t\n";
    cout<<"\t\t"<<s[1][0]<<"\t|\t"<<s[1][1]<<"\t|\t"<<s[1][2]<<"\n";
    cout<<"\t\t\t|\t\t|\t\t\n";
    cout<<"\t\t------    ------------    ------\n";

    cout<<"\t\t\t|\t\t|\t\t\n";
    cout<<"\t\t"<<s[2][0]<<"\t|\t"<<s[2][1]<<"\t|\t"<<s[2][2]<<"\n";
    cout<<"\t\t\t|\t\t|\t\t\n";
}

void func_2(){
    int digit;
    if(token=='X'){
        cout<<"please enter "<<n1<<" :";
        cin>>digit;
    }
    if(token=='0'){
        cout<<"please enter "<<n2<<" :";
        cin>>digit;
    }
    if(digit==1)
        {row = 0; column = 0;}
    if(digit==2)
        {row = 0; column = 1;}
    if(digit==3)
        {row = 0; column = 2;}
    if(digit==4)
        {row = 1; column = 0;}
    if(digit==5)
        {row = 1; column = 1;}
    if(digit==6)
        {row = 1; column = 2;}
    if(digit==7)
        {row = 2; column = 0;}
    if(digit==8)
        {row = 2; column = 1;}
    if(digit==9)
        {row = 2; column = 2;}
    else if(digit<1 || digit>9) cout<<"Invalid Input !!!\n";

    if(token=='X' && s[row][column] != 'X' && s[row][column] != '0'){  //if place is unused or not, in player X's turn
        s[row][column] = 'X';
        token = '0';
    }
    else if(token=='0' && s[row][column] != 'X' && s[row][column] != '0'){
        s[row][column] = '0';
        token = 'X';
    }
    else{
        cout<<"No Empty Space !!"<<endl;
        func_2();
    }

    func_1();
}

bool func_3(){
    // funtion to check if the game is finished or not also someone won or not.
    for(int i=0; i<3; i++){

        if(s[i][0]==s[i][1] && s[i][0]==s[i][2] || s[0][i]==s[1][i] && s[0][i]==s[2][i]) // if vertical or horizontal elements are equl
            return true;
    }
    if(s[0][0]==s[1][1] && s[0][0]==s[2][2] || s[0][2]==s[1][1] && s[0][2]==s[2][0]) //if diagonal elements are equal
            return true;

     for(int i=0; i<3; i++)
            for(int j=0; j<3; j++)
                if(s[i][j] != 'X' && s[i][j] != '0')
                    return false;


    tie = true;
    return true;
}

int main(){

    cout<<"Enter Name _ First Player : ";
    getline(cin,n1);

    cout<<"Enter Name _ Second Player : ";
    getline(cin,n2);
    cout<<endl<<endl;

    cout<<"\t\tFirst Player : "<< n1<<"\t\t\t";
    cout<<"Second Player : "<< n2<<"\n\n";

    func_1();
    while(!func_3()){
        func_2();
        func_3();
    }
    if(token == 'X' && tie == false)
        cout<<n2<<" Wins!!"<<endl;

    if(token == '0' && tie == false)
        cout<<n1<<" Wins!!"<<endl;

    else
        cout<<"It's A Tie"<<endl;
}
