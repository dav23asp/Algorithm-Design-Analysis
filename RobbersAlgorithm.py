##rules

##can't steal from houses that are next to each other, and the houses are in a circle

'''''
Good scenario (houses):


1-3-5-7

Bad scenario (houses):

1-2-3-4 ## cant take adjecent houses

scenario (array & money oriented):


arr [1,2,4]

Can only take $2, since the house with 1 and 4 dollars are next to each other (like a circular linked list)

'''''


def robbersAlgorithm(nums):
    ##treats the case that there is only one house,
    ##returns the first index, which is the only house present.

    if len(nums) == 1:
        return nums[0]

    ## Function:
    ## Finds the best path for the robbers, according to the cases given below as "case1" and "case2",

    def robbersPath(LineOfHouses):

        PreviousHouse, currentHouse = 0, 0

        for CurrentValue in LineOfHouses:
            # for each house, choose the max between current value of the house
            ## or the (current value plus the previous house), then move along the houses:
            PreviousHouse, currentHouse = currentHouse, max(currentHouse, PreviousHouse + CurrentValue)

        return currentHouse

    ##calls the helper function, rob the first house (call the first house)
    ##all the way up to the second to last house (do not include the last house)

    case1 = robbersPath(nums[:-1])

    ##calls the helper function, rob the second house (call the second house)
    ##all the way up to the last house (do include the last house)
    case2 = robbersPath(nums[1:])

    ##returns the best between the two paths, case1 or 2

    return max(case1, case2)


## provides the first scenario

##1st house has $2, 2nd house has $3, and 3rd has $2
firstHouses = [2, 3, 2]

## calls the robbersAlgorithm to compute what is the max
##amount of money they can catch without being caught


Robber1 = robbersAlgorithm(firstHouses)

## provides the second scenario

##1st house has $1, 2nd house has $2, 3rd has $3, and 4th house has $1

secondHouses = [1, 2, 3, 1]

## calls the robbersAlgorithm to compute what is the max
##amount of money they can catch without being caught

Robber2 = robbersAlgorithm(secondHouses)

print(f"Robber 1 stole the following amount: ", Robber1)  ##prints out the best option the first robber

print(f"\nRobber 2 stole the following amount: ", Robber2)  ## prints out the best option, but now for the second robber



