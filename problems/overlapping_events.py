"""
ThoughtWire: At-home assignment. 
Submitted by: Rajib Das

Problem Statement: Given a sequence of events, each having a start and end time,
write a program that will return the sequence of all pairs of overlapping events. 

Solution: The obvious solution of this problem is, for every event we need to
check whether there is any event start before the current event ends or not.
We can do that by checking if the current event end time is greater or equal 
to the start of any  event then there is an overlap; otherwise no overlap. 
For n-events (where 'n' is  the size of the given 2D list), we have to perform 
this checking. For any event, i, we need to check all events from (i+1) to n. 
That is why the time complexity of the brute force solution would be O(n^2).

My algorithm (find_overlapped_events() function)
    1. First, sort the given sequence list by the starting time. 
    2. For tracking the 'max_end_time', initially assigned the first end time.
    3. For 1 to n do (0-based)
        3a) if any particular event starts before the max_end_time
            3ai) store the event into a list as a part of the result.
            3aii) if the flag is set store the previous event too and make
                  toggle the flag to False. We need to maintain a flag to keep
                  for which there is an overlap and then append both events to 
                  the result list.
            3aiii) track the maximum between the max\_end\_time and current event 
                    end time.
        3c) else store the current event's end time as the max_end_time. 
            3ci) turn the flag to True.
    4. return the result list.

"""

def find_overlapped_events(sequence):
    overlapped = []
    max_end_time = sequence[0][1]
    flag = True
    for i in range(1,len(sequence)):
            if(max_end_time >= sequence[i][0]):
                if(flag):
                    overlapped.append(sequence[i-1])
                    flag = False
                overlapped.append(sequence[i])
                max_end_time = max(max_end_time, sequence[i][1])
            else:
                max_end_time = sequence[i][1]
                flag = True

    return overlapped


"""
The main() function (or driver function) will take user input. First, it expects the size
of the sequence of events. For every event, enter start time (space) end time in integer
format.
For example: 
sequence of events: [[1,100], [5, 10], [15, 20]]
then the size is 3 and in the next three lines enter
1 100
5 10
15 20

Finally our program will print the overlapped events. 
"""
if __name__ == "__main__":
    print("Enter the number/size of events: ")
    number_of_events = int(input())
    print("Enter the sequence of events (start end): ")
    sequence = []
    for i in range(number_of_events):
        start, end = input().split()
        sequence.append([int(start), int(end)])

    sequence = sorted(sequence)
    print(find_overlapped_events(sequence))


"""
Sample Test Cases

Input                                                           Output
-----------------------------------------------------------------------------------------------------
3
[[1, 100], [5, 10], [15, 20]]                                   [[1, 100], [5, 10], [15, 20]]
3
[[1,100], [101, 200], [201, 300]                                [] 
5
[[1, 100], [50, 100], [400, 500], [105, 200], [150, 160]]       [[1, 100], [50, 100],  [105, 200], [150, 160]] 
3
[[1, 10], [5, 10], [9, 10]]                                     [[1, 10], [5, 10], [9, 10]]
1
[[1, 10]]                                                       []
"""
