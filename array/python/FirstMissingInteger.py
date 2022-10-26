# Given an unsorted integer array nums, return the smallest missing positive integer.
# You must implement an algorithm that runs in O(n) time and uses constant extra space.
# Input: nums = [1,2,0]
# Output: 3
# Input: nums = [3,4,-1,1]
# Output: 2
# Input: nums = [7,8,9,11,12]
# Output: 1

"BRIEF METHOD"
def firstMissingPositive(nums: list) -> int:
    maximum=1
    numset=set(nums)
    while maximum in numset:
        maximum+=1
    return maximum

if __name__ == '__main__':
    a = firstMissingPositive([1,2,0])
    print(a)
    b = firstMissingPositive([3,4,-1,1])
    print(b)
    c = firstMissingPositive([7,8,9,11,12])
    print(c)

"short hand solution"
array = set(eval(input()))
#to handle input like this [1,2,3] (eval will convert the string into respective datatype)
([(print(i),exit()) for i in range(1,len(array)+1)if(i not in array)])
#the above loop will iterate from 1 to total number of unique elements in the list
# it will invoke the (print(i),exit()) part if the i not present in the list
# exit() will break the loop after printing the missed element