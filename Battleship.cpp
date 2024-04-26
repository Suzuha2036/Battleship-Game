#include <iostream>
#include <conio.h>
using namespace std;

void showBattleGroundStats(string battleGround[10][10],int currentShips, int hits);
int autoCountShips(string battleship[10][10]);

void battleShipGame(){

    string battleGround[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            battleGround[i][j] = " ";
        }
    }

    string battleship[10][10] = {
        {"o","o","o","o","o","o","o","o","o","o"},
        {"o","X","X","o","o","o","o","o","o","o"},
        {"o","X","o","X","o","o","o","o","o","o"},
        {"o","o","o","X","o","o","X","o","o","o"},
        {"o","o","o","o","o","o","X","o","o","o"},
        {"X","o","X","o","o","o","X","o","o","o"},
        {"X","o","X","o","o","o","o","o","o","o"},
        {"X","o","o","o","o","o","o","o","o","o"},
        {"o","o","o","o","o","o","o","o","o","X"},
        {"o","o","o","o","o","o","o","o","X","X"},
    };

    int currentBattleShips = autoCountShips(battleship);
    int hits = 0;
    int pos_y,pos_x;
    
    while(currentBattleShips != 0){
    showBattleGroundStats(battleGround, currentBattleShips,hits);
    cout<<"\nInput X:";
    cin>>pos_x;
    cout<<"Input Y:";
    cin>>pos_y;
    try{
    if (pos_x < 0 || pos_x >= 10 || pos_y < 0 || pos_y >= 10){
        cout<<"Error! Input 0-9 only! "<< endl;
        throw 77;
    }

    if(battleGround[pos_y][pos_x] != "o" && battleGround[pos_y][pos_x] !="X"){
    if(battleship[pos_y][pos_x] == "X"){
        battleGround[pos_y][pos_x] = "X";
            currentBattleShips--;
            hits++;
    }else{
    battleGround[pos_y][pos_x] = "o";
    }
    }else{
        cout<<"Already inputted!" << endl;
        throw 101;
    }
    }catch(...){
        cout<<"Press any key to continue";
        getch();   
    }
    system("cls");
    }

    cout<<"Congratulations, You've sunk all ships";

}

int main(){
    battleShipGame();
    return 0;
}

int autoCountShips(string battleship[10][10]){
    int count;
    for(int i = 0; i< 10; i++){
        for(int j = 0; j< 10; j++){
            if(battleship[i][j] == "X"){
                count++;
            }
        }
    }
    return count;
}

void showBattleGroundStats(string battleGround[10][10],int currentShips, int hits){

    cout<<"  ";
    for(int upperCoordinates = 0; upperCoordinates < 10; upperCoordinates++ ){
        cout<< "   " << upperCoordinates;
    }
    cout<<"   X  coordinate";
    cout<< endl;

    for(int rows = 0; rows <10;rows++){
        cout<<"   -----------------------------------------" << endl;
        cout<< rows << "  ";
        cout<<"| ";
        for(int column = 0 ; column < 10 ;column++){
            cout<<battleGround[rows][column] << " | ";
        }
        cout<<endl;
    }
    cout<<"   -----------------------------------------" << endl;
    cout<<"Y Coordinate                  o = no ship damaged" << endl;
    cout<< hits <<" sunk | "<< currentShips <<" ships left        X = ship sunk" << endl;

}
