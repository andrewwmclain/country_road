# PROBLEM
Let’s consider a long, quiet country road with houses scattered very sparsely along it. (We can picture the road as a long line segment, with an eastern endpoint and a western endpoint.) Further, let’s suppose that despite the bucolic setting, the residents of all these houses are avid cell phone users. You want to place cell phone base stations at certain points along the road, so that every house is within four miles of one of the base stations. 
Give an efficient algorithm that achieves this goal, using as few base stations as possible. 
# SOLUTION
In order to minimize the number of base stations, we can move from west to east and try to place each new base station as far east as possible as we move along. This greedy algorithm would “stay ahead” of all other solutions by ensuring the number of base stations over a given distance is always minimized. In order to do this, while moving west to east, each time we encounter a house we place a base station 4 miles to the east of it. Unless, of course, the house is already in range of a base station, in which case we would move to the next house. 
# IMPLEMENTATION
This program takes user input for the number of houses, road length, and locations of each house. The locations of each house are represented as an integer distance (in miles) from the westmost point. It is assumed that the user does not try to enter invalid input to crash the program. The program sorts the houses by increasing distance from the westmost point after the user inputs the values, so that it can move from west to east as described in the solution. A base cannot be placed in a position that exceeds the road length, so if the house being checked does not have a base within 4 miles and is also less than 4 miles from the end of the road, then the base will be placed at the end of the road. 
# HOW TO RUN THE PROGRAM
This program was run on my device with the following specifications: <br>
gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04) <br><br>
Running in CLION <br>
I ran the program with all of the files in this repository as a project using the CLION IDE, which provides debugging and other functionality. Below is an image and video example of this method. <br>
<a href="https://youtu.be/mZ0JT0q4JOo">YouTube Running in CLION</a><br>
<img src="CLION_RUN.PNG"><br><br>
Running from Terminal <br>
Below is an image and video example of running from the terminal using the g++ compiler.<br>
<a href="https://youtu.be/JxLxvttnl28">YouTube Running from Command Line</a><br>
<img src="TERMINAL_RUN.PNG"><br>
# TIME COMPLEXITY
The run time of this algorithm is O(n<sup>2</sup>) where n is the number of houses. Initializing the house locations takes O(n) time (n houses are input in O(1) time each). The C++ sorting algorithm from the <algorithm> library sorts the houses in O(n log n) time. The bases are also initialized in O(n) time. The bottleneck of the program is the nested for-loop from line 30-49. This nested for-loop is O(n<sup>2</sup>) because it must iterate through n houses on the outer loop, and on the inner loop it must iterate through up to n bases. This is because in the worst case scenario, where every house is more than 4 miles apart, there must be one base for each house.
