

def PowerSet(nums):
    

    Output = [] ##creates an array for the output, the finalized array of subsets
    
    PossibleSubset = [] ##placeholder array, stores all of the possible sets


##function for the backtracking step

    def backtrack(start):

        Output.append(list(PossibleSubset)) ##appends the possible subset to the output
    
        for i in range(start, len(nums)): ##checks for possible subsets starting form a given key
    
            PossibleSubset.append(nums[i]) ##appends the current value to the subset
    
            backtrack(i+1) ##recursively moves the list down the house
    
            PossibleSubset.pop() ##Pops the top of the array to then continue the possible subsets.
            ##Prevents duplicates

    
    backtrack(0)
    
    
    ##bug fix to sort the subsets by size every time the function subsets is called.  
    Output.sort(key=lambda x: (len(x), x))
    
    ##returns the outputs, all of the found possible subsets
    ##AFTER they've been sorted
    return Output


firstArray = [1, 2, 3]

firstSolution = PowerSet(firstArray)

print (f"Output for first test:", firstSolution)


secondArray = [0]

secondSolution = PowerSet(secondArray)

print (f"\nOutput for second test:", secondSolution)




