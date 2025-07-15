const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let input = [];

rl.on('line', function (line) {
    input = [line];
}).on('close',function(){
    str = input[0];
    var answer = '';
    
    for (let i = 0; i < str.length; i++){
        const code = str[i].charCodeAt();
        if (code >= 65 && code <= 90) {
            answer += String.fromCharCode(code + 32);
        }
        else {
            answer += String.fromCharCode(code - 32);
        }
    }
    console.log(answer);
});