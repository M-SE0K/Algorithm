
function solution(n, w, num) {
    var answer = 0;
    var index = 1;

    const board = [];
    var flag = false;
    for (let i = 0; i < n; i++){
        board[i] = index;
        if (!flag) {
            index++;
        }
        else {
            index--;
        }
        if (index % w === 1){
            flag = !flag;
        }
        
    }

    var target = board[num];
    console.log(`target: ${target}`);
    console.log(`board[]: ${board}`);

    for (let i = n - 1; 0 <= i; i--){
        if (target === board[i]) {  answer++;   }
        if (i === num)            {  return answer; }
    }
}

console.log(solution(22,6,8));
console.log(solution(13,3,6));

