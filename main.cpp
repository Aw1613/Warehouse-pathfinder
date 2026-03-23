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
        char arr[10][10];   // matrix size defined 
        // void value_setter(Grid obj){
        //     obj.arr[3][5] = 'X';
        //     obj.arr[7][1] = 'X';
        // }
        
        // void gird_display(void){
        // cout<<"     |  .  .  .  .  .  .  .  .  .  .  |\n"
        // <<"     |  .  .  .  .  .  .  .  .  .  .  |\n"
        // <<"     |  .  .  .  .  .  .  .  .  .  .  |\n"
        // <<"     |  .  .  .  .  .  .  .  .  .  .  |\n"
        // <<"     |  .  .  .  .  .  .  .  .  .  .  |\n"
        // <<"     |  .  .  .  .  .  .  .  .  .  .  |\n"
        // <<"     |  .  .  .  .  .  .  .  .  .  .  |\n"
        // <<"     |  .  .  .  .  .  .  .  .  .  .  |\n"
        // <<"     |  .  .  .  .  .  .  .  .  .  .  |\n"
        // <<"     |  .  .  .  .  .  .  .  .  .  .  |\n";
        // }
        void grid_disp_logic(Grid obj){
            obj.arr[3][5] = 'X';
            obj.arr[7][1] = 'X';
            for (int i = 0; i < 10; i++)
            {
                cout<<"| ";
                for (int j = 0; j < 10; j++)
                {
                    if (obj.arr[i][j] == 'S')
                    {
                        obj.arr[i][j] = 'S';
                        cout<<" S ";
                    }
                    else if (obj.arr[i][j] == 'E'){
                        obj.arr[i][j] = 'E';
                        cout<<" E ";
                    }
                    else if(obj.arr[i][j] == 'X'){
                        obj.arr[i][j] = 'x';
                        cout<<" X ";
                    }
                    else{
                        obj.arr[i][j] = '.';
                        cout<<" . ";
                    }
                    
                }
                cout<<"|"<<endl;
                
            }
            
        }
};

int main(){
    Grid g1;
    cout<<"This is the grid \n\n\n\n";
    g1.grid_disp_logic(g1);
    cout<<"\n\n\n\n";
    return 0;
}