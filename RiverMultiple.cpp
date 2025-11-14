// RiverMultiple.cpp
#include <bits/stdc++.h>

//random 
#include <cstdlib> 

//time for random
#include <ctime> 


//for random 

#include <random> 

using namespace std;
int main() {
    
    srand(time(0));
    //Amount of rivers (rows)
    int R = 3;
    //how long the river is (columns)
    int C;
    
    // example 1
    
    //Number of columns
    C = 4;
    
    
    //predetermined grid: 
    
    vector<vector<int>> grid = {
        
        {0, 0, 3, 0},
        {0, 2, 1, 0},
        {0, 0, 0, 3}
    
        
    };
    
    
    cout<<"This are the basic rivers and their areas of interest: "<<endl;
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
    
    vector<vector<int>> dp(R, vector<int>(C, 0));
    
    
    //goes through each row until it reaches the last row, "R"
    for (int r=0;r<R;++r) {
        
    //goes through eahc column within that row, until it reaches the last column "C"
        for (int c=0;c<C;++c) {
    
            int best = 0;
    //if  there is a value right to the fisher
            if (r > 0) {
        
        //check whats best, if the new value or the old
                best = max(best, dp[r-1][c]);
            
                
            }
           
    //if there is a value below the fisher
    
            if (c > 0){ 
        
        //check whats best, if the new value or the the old
                best = max(best, dp[r][c-1]);
                
            }
            
        //initializes/updates possible value for new square meter
            if (best == 0){
                
              dp[r][c] = grid[r][c];  
            
            //if new better value is found, add the current value to it
            } else {
                
                
                dp[r][c] = grid[r][c] + best;
                
            } 
    
    
    
        }
    }
    
    //since there are three rivers, find the max between the three of them
    int answer = max({dp[0][C-1], dp[1][C-1], dp[2][C-1]});
    
    
    cout << "Dynnamic Programming result with 4 kilometers: " << answer << "\n";



    // example 2
    
    //the rivers are longer
    C = rand() % 10 + 5; 
    
    cout<< "\n\nThe new length of the river, from west to east, is: "<< C <<" kilometers"<< endl;
   //Talk to computer and obtain different random numbers     
   random_device DifferentNumber; 
   
   //Mersenne Twiter Random Number engine (this to make the second scenario have random nunmbers from 0-3)
   
   mt19937 gen(DifferentNumber()); 

   uniform_int_distribution<> dis(0, 3); 

//reasign the different dimentions of the new grid, "river"
    grid.assign(R, vector<int>(C));
    
//assign the random numbers (places of interest) to the different grids, the different 1x1 "boxes" of the rivers

    for (int i = 0; i < R; ++i) {
        
        for (int j = 0; j < C; ++j) {
        
            grid[i][j] = dis(gen); 
        
            
            
        }
    }   
        
    
    //print the new 3 rivers
    cout<<endl;
    for (int rivers = 0; rivers < grid.size(); ++rivers ) { 
        
        //this prints out all the elements in the row
        
        for (int columns = 0; columns < grid[rivers].size(); ++columns) { 
        
            cout << grid[rivers][columns] << " "; 
        
            
            
        }
        
        //when row is done, print the next one
        cout << endl; 
    }
     
    cout << endl; 
    
    
    dp.assign(R, vector<int>(C, 0));
    

    for (int r=0;r<R;++r) {
    
        for (int c=0;c<C;++c) {
    
            int best = 0;
    //if  there is a value right to the fisher
            if (r > 0) {
        
        //check whats best, if the new value or the old
                best = max(best, dp[r-1][c]);
            
                
            }
           
    //if there is a value below the fisher
    
            if (c > 0){ 
        
        //check whats best, if the new value or the the old
                best = max(best, dp[r][c-1]);
                
            }
            
        //initializes/updates possible value for new square meter
            if (best == 0){
                
              dp[r][c] = grid[r][c];  
            
            //if new better value is found, add the current value to it
            } else {
                
                
                dp[r][c] = grid[r][c] + best;
                
            }
                
    
        }
    
       
    }
 
    answer = max({dp[0][C-1], dp[1][C-1], dp[2][C-1]});
    
    
    
    cout << "Dynnamic Programming result (with "<< C << " kilometers): "<< answer << " (computed in O(R*C) )\n";
    return 0;
}
