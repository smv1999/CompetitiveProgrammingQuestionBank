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

/*
 * Complete the vowelsAndConsonants function.
 * Print your output using 'console.log()'.
 */
function vowelsAndConsonants(s) {
    //for vowels
    for(let ind=0; ind<s.length; ind++){
     if(s.charAt(ind).match(/[aeiou]/)){
         console.log(s.charAt(ind));
     }
}
//for consonants
    
    for(let ind=0; ind<s.length; ind++){
     if(s.charAt(ind).match(/[^aeiou]/)){
         console.log(s.charAt(ind));
     }
  }
}
 





function main() {
    const s = readLine();
    
    vowelsAndConsonants(s);
}
