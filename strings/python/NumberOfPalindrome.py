'''
    Write a Python Program to count palindrome words from the given space seperated string.

    Input:
    Enter a string: radar level singh abhay

    Output:
    Number of Palindrome string is 2.
'''

#one-liner
(lambda x: print(sum([1 for i in x if(i==i[::-1])])))(input("Enter a string: ").strip().split())

#expansion
'''
list_of_words = input("").strip().split()
count_of_palindromes = sum([1 for i in list_of_words if(i==i[::-1])])
print(count_of_palindromes)
'''

#detailed code
'''
list_of_words = input("").strip().split() #to strip to remove space at end and split to get space seperated words
count_of_palindromes = 0
for i in list_of_words:
    if(i==i[::-1]): # ::-1 is a slice/range operation to reverse the value (quite handy guy)
        count_of_palindromes+=1 #add palindromic word count
print(count_of_palindromes)
'''