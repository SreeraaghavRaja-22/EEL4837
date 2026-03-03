# Greedy Algorithm 

## Greedy Algorithm Basics

- An **optimization problem** is on

## Greedy Algorithm Example: Making Change

- Suppose you want to count out a certain amount of money, using the fewest possible bills and coins
- A greedy algorithm would do this: **At each step, take the largest possible bill or coin that does not overshoot**
  - Example: To make $6.39, you can choose
    - a $5 bill
    - a $1 bill, to make $6.39
    - a 25 cent coin, to make $6.25
    - a 10 cent coin, to make $6.35
    - four 1 cent coins, to make $6.39
- For US money, the greedy algorith always gives the **optimal solution**


## Greedy Algorithm Example: A Scheduling Problem

- You have to run nine jobs, with running times of 3, 5, 6, 10, 11, 14, 15, 18, and 20 minutes
- You have three processors on which you can run these jobs
- Optimal solutions require a brute force approach since processors need to try all possible combinations of jobs
