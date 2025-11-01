# My Approach to LeetCode Problems

## Problem 121: Best Time to Buy and Sell Stock

 [View Problem on LeetCode](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/?envType=problem-list-v2&envId=array)

### Problem Summary
Given an array of stock prices over `n` days, determine the maximum profit achievable with one buy and one sell.

### My Approach
– Takes input of stock prices for `n` days.  
– Uses traversal technique to find the best day to buy and sell.  
– `minPrice` stores the lowest price seen so far.  
– `maxProfit` stores the highest profit possible at any point.  
– For each day:  
  • If current price is lower than `minPrice`, update `minPrice`.  
  • Else, check if selling today gives better profit than current `maxProfit`.  
– Final result is the maximum profit achievable with one buy and one sell.

- Code File: `LEETCODE_PROB_121.cpp`

---

## Problem 1700: Number of Students Unable to Eat Lunch

[View Problem on LeetCode](https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/?envType=problem-list-v2&envId=stack)

### Problem Summary
Simulate a lunch queue where students have sandwich preferences (0 or 1). Sandwiches are served in stack order. If a student doesn’t want the top sandwich, they go to the back of the queue. The process stops when no student wants the current sandwich.

### My Approach
– Used custom stack and circular queue classes.  
– Stack holds sandwiches, queue holds student preferences.  
– Inputs only 0 or 1 allowed.  
– Sandwiches are pushed in order, so last entered is served first (**LIFO**).  
– Students are processed in queue order:  
  • If front student matches top sandwich, both are removed.  
  • If not, student is rotated to the back.  
– `studentsRejoined` counts how many students skipped the current sandwich.  
– If all current students rejoin without eating, simulation stops.  
– Final output is number of students left in queue.
