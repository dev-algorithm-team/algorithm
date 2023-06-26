const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./example.txt";
let input = fs
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n")
  .map((item) => item.split(" ").map((value) => +value));

const [N, M] = input[0];
const graph = Array.from({ length: N + 1 }, () => []);
let answer = [];

// 인접리스트
for (let i = 1; i <= M; i++) {
  let [a, b] = input[i];
  graph[b].push(a);
}

let max = 0; // 해킹할수 있는 컴퓨터의 최대 수
const DFS = (start) => {
  const stack = [start];
  const visited = Array.from({ length: N + 1 }, () => false);
  let count = 0; // 해킹 가능한 컴퓨터의 수 카운트
  while (stack.length) {
    let cur = stack.pop();
    visited[cur] = true;
    for (let i = 0; i < graph[cur].length; i++) {
      let value = graph[cur][i];
      if (visited[value]) continue;
      visited[value] = true;
      count += 1;
      stack.push(value);
    }
  }
  if (max < count) {
    // 현재 해킹할수 있는 컴퓨터의 최대 수보다 이번 컴퓨터의 해킹 가능한 최대 수가 크다면
    max = count;
    answer = []; // 초기화
    answer.push(start);
  } else if (max === count) {
    answer.push(start);
  }
};

for (let i = 1; i <= N; i++) {
  DFS(i);
}

console.log(answer.join(" "));
