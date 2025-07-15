const readline = require("readline");
const rl = readline.createInterface({input: process.stdin, output: process.stdout})
let inputs = [];
rl.on("line", function(line){
    inputs = line.split(" "),
    rl.close();
}).on("close", function(){
    console.log(`a = ${inputs[0]}`);
    console.log(`b = ${inputs[1]}`);
});