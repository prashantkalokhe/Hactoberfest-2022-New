# The problem is, we should return true if parenthesis matches with its opening and closing
# else we should return false.

# Stack implemented using LinkedList


#Algo:
# We iterate through each of the character in the string and if any open Parantheses is encountered
# then we push it to the stack and if any closing paranthesis is found we pop element from stack and 
# compare the parenthesis type if so we delete that from stack..if not we just pass to next iteration.

import sys
class node: 

    def __init__(self, info): 
        self.info = info  
        self.next = None 


class Stack: 

    def __init__(self): 
        self.top = None
        
    
    def isEmpty(self):
        if self.top is None:
            return True
        return False
    
    def push(self,data):
        self.temp=node(data)
        if self.temp is None:
            print("Stack overflow")
            return
        self.temp.next=self.top
        self.top=self.temp
    
    def pop(self):
        if self.isEmpty():
            print("Stack Underflow")
            sys.exit(0)
        d=self.top.info
        self.top=self.top.next    
        return d
    
    def peek(self):
        if self.isEmpty():
            print("Stack Underflow")
            sys.exit(0)
        d=self.top.info
        return d
    def display(self):
        if self.isEmpty():
            print("Stack Underflow")
            sys.exit(0)
        self.p=self.top
        while self.p is not None:
            print(self.p.info)
            self.p=self.p.next
            
def match(a,b):
    if(a=='[' and b==']'):
        return 1
    if(a=='{' and b=='}'):
        return 1
    if(a=='(' and b==')'):
        return 1
    return 0
def checkParantheses(s):
    stack=Stack()
    for i in range(len(s)):
        if s[i]=='(' or s[i]=='[' or s[i]=='{':
            stack.push(s[i])
        if s[i]==')' or s[i]==']' or s[i]=='}':
            if stack.isEmpty():
                print("Right parentheses are more than left parentheses")
                return 0
            else:
                temp=stack.pop()
                if match(temp,s[i]) != 1:
                    print("Mismatched parentheses are : {} {}".format(temp,s[i]))
                    return 0
        
    if stack.isEmpty() is True:
        print("Balanced Parentheses")
        return 1
    else:
        print("Left parentheses more than right parentheses")
        return 0

            
if __name__=='__main__':
    s="((a+b)+(c+d))"
    valid=checkParantheses(s)
    if valid==1:
        print("Valid Expression")
    else:
        print("Invalid Expression")