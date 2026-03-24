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

        // Stores the address of the grid 
        Grid& grid;

        Robot(Grid& g): grid(g){}
        
        void location_fetcher(void){
            cout<<"The location of the robot is "<<map_row<<" , "<<map_col<<endl;
            cout<<"And the staus is "<<grid.arr[map_row][map_col]<<endl;
        }

        void getNeighbour(void){
            
            
            char up = 'V';
            char down = 'V';
            char right = 'V';
            char left = 'V';
            // up = grid.arr[map_row][map_col + 1];
            // down = grid.arr[map_row][map_col - 1];
            // right = grid.arr[map_row + 1][map_col];
            // left = grid.arr[map_row - 1][map_col];
            

            // 8,0
            if (map_row > 0)  up = grid.arr[map_row - 1][map_col]; 
            if (map_row < 9)  down = grid.arr[map_row +1][map_col];
            if (map_col > 0)  left = grid.arr[map_row][map_col - 1];
            if (map_col < 9)  right = grid.arr[map_row][map_col + 1]; 
            
            
            
            cout<<up<<endl<<down<<endl<<right<<endl<<left<<endl;

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