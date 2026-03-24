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
        // void value_setter(Grid obj){
        //     obj.arr[3][5] = 'X';
        //     obj.arr[7][1] = 'X';
        // }
        
        void grid_disp_logic(Grid obj){
            // For user input based obstacle course , uncomment it 


            // // First taking input from the user to place the obstacles on the map 
            // cout<<"Please enter the number of obstacles you want in the course :"<<endl;
            // cin>>obst;
            // int h = 0;
            // int k = 0;
            // cout<<"Please enter the cordinates for the obstacles in X and Y :"<<endl;
            // // This will display the obstacle acording to the user input 
            // for (int i = 0; i < obst; i++)
            // {
            //     cout<<"Row "<<i+1<<" : ";
            //     cin>>h;
            //     cout<<"Column "<<i+1<<" : ";
            //     cin>>k;
            //     cout<<endl;
            //     obj.arr[h][k] = 'X';
            // }
            

            // Hardcoded map for testing 

            obj.arr[0][0] = 'S';

            obj.arr[1][3] = 'X';
            obj.arr[2][3] = 'X';
            obj.arr[3][3] = 'X';
            obj.arr[4][3] = 'X';
            obj.arr[4][4] = 'X';
            obj.arr[4][5] = 'X';

            obj.arr[2][7] = 'X';
            obj.arr[3][7] = 'X';
            obj.arr[3][6] = 'X';

            obj.arr[7][8] = 'X';
            obj.arr[8][8] = 'X';

            obj.arr[9][9] = 'E';


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