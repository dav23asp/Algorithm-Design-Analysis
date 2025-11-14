# Algorithm-Design-Analysis

1. Project:

Fisher goes fishing, he wants to get the most possible profit in the least amount of time, he tries two approaches:

Golliath.cpp - Brute force algorithm, using depth first search, to find the "best possible path" between 3 horizontal rivers, computed as a grid with columns and rows. Takes really long, not efficient, and not highest possible value. O(2^(R*C))

RiverMultiple.cpp - Dynnamic Programming approach to better the time complexity. Computes the best path with the highest profit for the fisher, and in efficient time.  O(R*C)
