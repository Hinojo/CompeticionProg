#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int SAFE = 0;
const int MINED = -1;

struct point {
    int x,y;
};

void updateAdjacentCells(vector<vector<int>> & grid, const point & cell, const int & HORIZONTAL_SIZE, const int & VERTICAL_SIZE){
    for (int i = -1; i <= 1; i++){
        if(cell.x + i < 0 || cell.x + i >= HORIZONTAL_SIZE){
            continue;
        }
        for(int j = -1; j <= 1; j++){
            if(cell.y + j < 0 || cell.y + j >= VERTICAL_SIZE){
                continue;
            }
            if(grid[cell.x + i][cell.y + j] != -1){
                grid[cell.x + i][cell.y + j] ++;
            }
        }
    }
}

void printGrid(const vector<vector <int>> & grid, const int & fieldCounter){
    cout << "Field #" << fieldCounter << endl;
    for(vector<int> v : grid){
        for(int cell : v){
            if (cell == -1){
                cout << '*' << ' ';
            }
            else{
                cout << cell << ' ';
            }
        }
        cout << endl;
    }
}
//%asdf

int main(){
    int fieldCounter = 0;
    while(true){       
        int HORIZONTAL_SIZE, VERTICAL_SIZE;
        cin >> HORIZONTAL_SIZE;
        cin >> VERTICAL_SIZE;
        if(HORIZONTAL_SIZE > 0 && VERTICAL_SIZE > 0){
            fieldCounter++;
            vector<vector<int>> grid(HORIZONTAL_SIZE, vector<int>(VERTICAL_SIZE, SAFE));
            vector<point> mineList;

            for (int x = 0; x < HORIZONTAL_SIZE; x++){
                for (int y = 0; y < VERTICAL_SIZE; y++){
                    char input;
                    cin >> input;
                    if (input == '*'){
                        
                        grid[x][y] = MINED;
                        point mine;
                        mine.x = x;
                        mine.y = y;
                        mineList.push_back (mine);
                    }
                }
            }
            for (point cell: mineList){
                updateAdjacentCells(grid, cell, HORIZONTAL_SIZE, VERTICAL_SIZE);
            }
            printGrid(grid, fieldCounter);
        }
    }
}