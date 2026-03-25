// Warehouse path finder 

/*
Frame-work 

1.  10 x 10 gird on CLI using array 
2.  cell type declaratin in bools
3.  neighbour accesing funciton (all 4 direction)

4. BFS algorthm implementaion
4(b).   {If BFS succesfull } A* implemtntaion 

5. Robot (location + path + cell type change)
6. Connecting algorithms to Robot

/////////  For later
Map randomizer :- genrates dynamic maps 

*/


#include<iostream>
#include<queue>
using namespace std;

// Grid setup
class Grid{
    public:
        int obst;
        char arr[10][10];   // matrix size defined 
        
        
        void girdSetup(void){
            for (int i = 0; i < 10; i++){
                for (int j = 0; j < 10; j++){
                    arr[i][j] = '.';
                }
            }

            // Hardcoded map for testing 

            arr[0][0] = 'S';
            
            arr[1][3] = 'X';
            arr[2][3] = 'X';
            arr[3][3] = 'X';
            arr[4][3] = 'X';
            arr[4][4] = 'X';
            arr[4][5] = 'X';

            arr[2][7] = 'X';
            arr[3][7] = 'X';
            arr[3][6] = 'X';

            arr[7][8] = 'X';
            arr[8][8] = 'X';

            arr[9][9] = 'E';
            
        }
        void gridDisplay(void){
            for (int i = 0; i < 10; i++)
            {
                cout<<"|";
                for (int j = 0; j < 10; j++)
                {
                    cout<<" "<<arr[i][j]<<" ";
                }
                cout<<"|"<<endl;
                
            }
            
        }
};

// Making the Robot and initalzing its postion 
class Robot{
    public:
    // Placing robot at 0,0
        int map_row = 0;
        int map_col = 9;

        char up = 'V';
        char down = 'V';
        char right = 'V';
        char left = 'V';

        // Stores the address of the grid 
        Grid& grid;

        Robot(Grid& g): grid(g){}
        
        void location_fetcher(void){
            cout<<"The location of the robot is "<<map_row<<" , "<<map_col<<endl;
            cout<<"And the staus is "<<grid.arr[map_row][map_col]<<endl;
        }

        void getNeighbour(void){
            
            if (map_row > 0)  up = grid.arr[map_row - 1][map_col]; 
            if (map_row < 9)  down = grid.arr[map_row +1][map_col];
            if (map_col > 0)  left = grid.arr[map_row][map_col - 1];
            if (map_col < 9)  right = grid.arr[map_row][map_col + 1]; 
            
            
            cout<<up<<endl<<down<<endl<<right<<endl<<left<<endl;

        }
        
};

class BFS : public Grid , public Robot{
    public:
        queue<pair<int,int>> q;
        
        // This is going to store the data if the cells are Visited or not and by default , all are set to zero
        bool visited[10][10] = {false};
        int parentRow[10][10];      // This is going to store the Row of the previos cell form which it came 
        int parentCol[10][10];      // same , stores col of previous cell and there will be a whole matrix for one cordinat (col here)
        // current row and col of the cell 
        int r;
        int c; 

        void pathFind(void){
            q.push({0,0});

            while (!q.empty())
            {
                if (arr[r][c] == 'E')
                {
                    break;
                }
                else {
                    q.pop();
                }
                if (up != 'V' && up != 'X' && visited[r-1][c] == false)
                { 
                    visited[r-1][c] = true;
                    parentRow[r-1][c] = r;
                    parentCol[r-1][c] = c; 
                    r = r-1;
                }
                if (down != 'V' && down != 'X' && visited[r+1][c] == false){
                    visited[r+1][c] = true;
                    parentRow[r+1][c] = r;
                    parentCol[r+1][c] = c; 
                    r = r+1;
                }
                if (right != 'V' && right != 'X' && visited[r][c+1] == false){
                    visited[r][c+1] = true;
                    parentRow[r][c+1] = r;
                    parentCol[r][c+1] = c;
                    c = c+1;
                } 
                if (left != 'V' && left != 'X' && visited[r][c-1] == false){ 
                    visited[r][c-1] = true;
                    parentRow[r][c-1] = r;
                    parentCol[r][c-1] = c;
                    c = c-1;
                }
                
            }
            
        }
};




int main(){
    Grid g1;
    cout<<"This is the grid \n\n\n\n";
    g1.girdSetup();
    g1.gridDisplay();
    cout<<"\n\n\n\n";
    Robot r1(g1);
    r1.location_fetcher();
    r1.getNeighbour();
    return 0;
}