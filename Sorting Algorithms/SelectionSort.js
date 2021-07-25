/*SELECTION SORT: 
    * inplace comparison-based sorting algorithm.
    * list is divided into two parts, the sorted part at the left end and the unsorted part at the right end. 
    * The smallest element from the unsorted array is found and swapped with the leftmost element.
      ie, added to the sorted array. 
    * This process continues moving unsorted array boundary by one element to the right.
*/

//importing readline module for dynamic input 
var readline = require('readline');
//initialising inputstream and outstream to process.stdin and process.stdout respectively.
var rl = readline.createInterface(
    process.stdin, process.stdout);

const selectionSort = (arr) => {
    let n = arr.length;
    // i is the current index
    for(let i=0; i<n-1; i++){
        //minPos stores the position of smallest element
        let minPos = i;

        //finding the minimum element from arr.
        for(let j=i+1; j<n; j++){
            if(arr[j] < arr[minPos]){
                minPos = j;
            }
        }
        //swapping current element and smallest element;
        let temp = arr[minPos];
        arr[minPos] = arr[i];
        arr[i] = temp;
    }
    return arr;
}

//Reading input from console as a string and converting it to array 
rl.question('Enter array elements comma separated: ', (input) => {
    let numbers = input.split(",");
    numbers = numbers.map( (x) => parseInt(x));
    console.log(selectionSort(numbers));
    rl.close();
});

/*
INPUT
Enter array elements comma separated: 
1, 8, 7, 61, 5, 4, 11
OUTPUT
1,4,5,7,8,11,61

    Time Complexity - O(n^2)
    Space Complexity - O(1)
*/