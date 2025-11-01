Problem 1700 
Approach:
– Used custom stack and circular queue classes, no STL.\n
– Stack holds sandwiches, queue holds student preferences.
– Inputs are validated, max 50 entries, only 0 or 1 allowed.
– Sandwiches are pushed in order, so last entered is served first (LIFO).
– Students are processed in queue order. If front student matches top sandwich, both are removed.
– If not, student is rotated to the back.
– studentsRejoined counts how many students skipped the current sandwich.
– If all current students rejoin without eating, simulation stops.
– Final output is number of students left in queue.


Problem 121
Approach:
– Takes input of stock prices for n days.
– Uses traversal technique to find the best day to buy and sell.
– minPrice stores the lowest price seen so far.
– maxProfit stores the highest profit possible at any point.
– For each day, if current price is lower than minPrice, update minPrice.
– Else, check if selling today gives better profit than current maxProfit.
– Final result is the maximum profit achievable with one buy and one sell.
