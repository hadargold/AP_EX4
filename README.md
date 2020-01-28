# AP_EX4
This repository holds a CPP code that handles a server-client connection.
The purpose of the connection is calculating the best route between source and destination
based on several known search algorithms (e.g. DFS, BFS and more).

The code demonstrating a seperation between an abstract solution and concrete implementation of it, i.e. 
seperation between the pseudo-solution of data structure that holds the next node to develop
and BFS that uses a stack to choose which is the next node to develop.

Another seperation is between a method of connection to a specific one, i.e. one vs multi connection to the server.

# Collaborators
Yuval Regev and Hadar Goldberger, students towards CS B.A in the Bar Ilan University, Israel.

# Description
The program handles requests of a client to a server.
The server is a graph search engine that for an input of a *graph*, *source* and *destination*,
finds the best route between them, where best route is defined as the shortest path in the graph.

The code is written according to SOLID principles and especially open to extension and closed to modifications.
in our implementation, the client sends the graph as text file and by matrix representaion, we can obviously
extent it to any other types of files (JSON, csv and so) and graph representations.

# Server
We considered which search method will return the best results.
The parameters we chose to consider to compare are the cost of the path and 

We chose to examine the following algorithms:
@ BFS
@ DFS
@ Beset First Search
@ A-star

As we knew the ranges of the graphs are to be of range 10X10 - 50X50, we implemented them
and tested which is best for each size.
Suprisingly, we found out the Best First Search is the best algorithm for all sizes,
and setted it to be the algorithm that the server uses.
