/*
    Given an unsorted integer array nums, return the smallest missing positive integer.
    You must implement an algorithm that runs in O(n) time and uses constant extra space.
Test case 1:
    Input:
    Enter space seperated integers:-
    1 2 0
    Output: 3
Test case 2:
    Input:
    Enter space seperated integers:-
    3 4 -1 1
    Output: 2
Test case 3:
    Input:
    Enter space seperated integers:-
    7 8 9 11 12
    Output: 1
*/

// to read input from command line using node
const readline = require("readline");
const input = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

input.question("Enter space seperated integers:-\n", function (string) {
    const array = string.split(' ');
    for (var i = 1; i < array.length+2; i++){
    if (!array.includes(i+"")) {
        console.log("the missing number is", i);
        input.close();
        return;
    }
}
input.close();
});