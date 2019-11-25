"""
Assignment for: StorageVault Canada
Submitted by: Rajib Das

My Idea: By prohibiting the use of 'if-else' statement makes the problem more challenging and interesting.
In that case, I would love to solve the problem using regular expression algorithm. As per the problem
statement, we have two constraints: 
    a) postal code range should be in between 100000 to 999999
    b) alternating digit pair can not be more than one.
For these two constraints I will use two functions and if both of them satisfy the conditions only then 
my program will return 'True' as indicating the valid postal code; Otherwise 'False'; 
"""

# First, we need to import the regular expression (re) module.
import re 


"""
Following 'check_range()' function takes a string as input and validate whether the string is in between the 
above mentioned range or not. For this purpose the regular expression would be: "^[1-9]\d{5}$"
Where,
    ^ : Matches the start of the string
    [1-9]: First letter should be in between 1 to 9. No 'zero' is allowed. 
    \d : Any digit from 0 to 9.
    {5}: Any five digits from 0 to 9 (excluding first digit) 
    $ : Matches the end of the string
"""
def check_range(postal_code):
    regex = r"^[1-9]\d{5}$"
    return bool(re.match(regex, postal_code))

"""
The following 'count_of_alternating_digit_pair()' function will return the number of same digit pairs
that are one digit apart. The regular expression: "(\d)(?=\d\1)"
Here, 
    (\d) : Match and hold a digit
    (?= : Start to look ahead digit(s)
        \d : Match any digit
        \1 : Look ahead 1 digit 
    ): End of looking ahead
"""

def count_of_alternating_digit_pair(postal_code):
    regex = r"(\d)(?=\d\1)"
    print(len(re.findall(regex, postal_code)))
    return len(re.findall(regex, postal_code))

"""
The 'main()' function (driver function) is responsible for taking the input (postal codes as a string) from the user
and print the result of above implemented two functions.
"""
if __name__ == "__main__":
    print("Enter a postal code: ")
    postal_code = input()
    print(check_range(postal_code) and count_of_alternating_digit_pair(postal_code) < 2)



"""
Sample Test Cases that I tried: 

Input:      Output:     Explanation:
-------------------------------------------------------------------------------
123456      True        Distinct six digits.
012345      False       First digit should be more than 1
12345       False       Valid postal codes should be six digits long
1234567     False       Above the range
1a2b3c      False       Alphanumeric is not allowed
!@#$%^      False       Special characters are not allowed
qwerty      False       Characters are not allowed; only numbers are
121212      False       Four alternating digit pairs (two 1's and two 2's), at most 1 pair is allowed
111111      False       Four 1's alternating digit pairs, at most 1 pair is allowed

"""

