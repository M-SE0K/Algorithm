const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let input = [];

rl.on('line', function (line) {
    input = line.split(' ');
    
}).on('close', function () {
    var answer = '';
    
    for (let i = 0; i < Number(input[1]); i++){
        answer += input[0];
    }
    
    console.log(answer);
});
