// Golliath.cpp
#include <bits/stdc++.h>
using namespace std;

int R = 3;
int C;
vector<vector<int>> grid;
long long loop = 0;

//Depth First Search to brute force each row

int dfs(int r, int c) {
    
    
//this counts the amount of times that the call loops

    loop++;
    
    int CurrentValue = grid[r][c];
    
    
    //the "best" possible value
    
    
    int best = 0;
    
    
    // move right recursively
    if (c + 1 < C){ 
        
        best = max(best, dfs(r, c+1));
        
    }
    // move down recursively
    if (r + 1 < R){
        
        best = max(best, dfs(r+1, c));
        
        
    }
    //if no moves possible (dead end), return current cell value
    if (best == 0){
        return CurrentValue;

    }
    
    return CurrentValue + best;
}

int main() {
    //example 1 (small):
    
 
    
    //grid sample (River x Column)
    
    C = 2;
    
    grid = vector<vector<int>>(R, vector<int>(C, 0));
    
    
    
    
    //sample values
    
    grid = {
        {1, 2},
        {0, 2},
        {1, 0}
    };
    
    cout<<"These are the basic rivers and their areas of interest: \n"<<endl;
    //print the 3 rivers
    
    for (int rivers = 0; rivers < grid.size(); ++rivers ) { 
        
        //this prints out all the elements in the row
        
        for (int columns = 0; columns < grid[rivers].size(); ++columns) { 
        
            cout << grid[rivers][columns] << " "; 
        
            
            
        }
        
        //when row is done, print the next row
        cout << endl; 
    }
    
    cout << endl; 
    
    loop = 0;
    
    int FirstExpedition = dfs(0,0);
    
    cout << "Brute force result with 2 Kilometers: " << FirstExpedition << ", loops =" << loop << "\n"<<endl;

    //example 2 (larger):
    
    C = 8;
    
    grid = vector<vector<int>>(R, vector<int>(C, 1)); 
    
    loop = 0;
    
    int SecondExpedition = dfs(0,0);
    
    cout<<"These are the new set of rivers and their areas of interest: \n"<<endl;
    //print the 3 rivers
    
    for (int rivers = 0; rivers < grid.size(); ++rivers ) { 
        
        //this prints out all the elements in the row
        
        for (int columns = 0; columns < grid[rivers].size(); ++columns) { 
        
            cout << grid[rivers][columns] << " "; 
        
            
            
        }
        
        //when row is done, print the next row
        cout << endl; 
    }
    
    cout << endl; 
    
    cout << "Brute force result with 8 kilometers: " << SecondExpedition << ", loops =" << loop << "\n"<<endl;
    
    cout << "\nComputed in O(2^(R*C)) since you check every column and row."<<endl;
    
    return 0;

    
    
}
