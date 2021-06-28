'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.trim().split('\n').map(string => {
        return string.trim();
    });
    
    main();    
});

function readLine() {
    return inputString[currentLine++];
}

function getMaxLessThanK(n,k)
{
    let max=0
    for(let i=1;i<n;i++)
    for(let j=i+1;j<=n;j++)
    {
        let and=i&j
        
        if(and<k && and>max)
           max=and
    }
    return max
}

