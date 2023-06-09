let fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim();

function solution(input) {
  input = input.split("");
  const N = input.length;
  const answer = [];
  let visited = Array(N).fill(false);

  function DFS(left, right) {
    if (left === right) return;

    let result = "";
    const minStr = input.slice(left, right).sort()[0];
    const minIdx = input.slice(left, right).indexOf(minStr) + left;
    visited[minIdx] = true;

    for (let i = 0; i < N; i++) {
      if (visited[i]) result += input[i];
    }
    answer.push(result);

    DFS(minIdx + 1, right);
    DFS(left, minIdx);
  }

  DFS(0, N);

  return answer.join("\n");
}

console.log(solution(input));
