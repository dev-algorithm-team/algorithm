const fs = require("fs");
const file = process.platform === "linux" ? "/dev/stdin" : "./example.txt";
const input = fs.readFileSync(file).toString().trim().split("\n");

const N = +input[0];
const graph = Array.from({ length: 100001 }, () => {});
const visited = Array(100001).fill(false);
let ans = 0;
let endIdx;
let endFlag = false;

for (let i = 1; i <= N; i++) {
  const [node, left, right] = input[i].split(" ").map(Number);
  graph[node] = { left, right };
}

endIdx = findEnd(1);
solution(1, true);
if (N == 1) ans == 0;

console.log(ans);

// 가장 오른쪽에 있는 번호 찾기
function findEnd(top) {
  if (graph[top].right == -1) return top;
  return findEnd(graph[top].right);
}

// 중위 순회 재귀함수
function solution(x, first) {
  if (endFlag) return;

  // 왼쪽 자식 노드가 없거나 방문했다면 해당 노드 재귀X
  if (graph[x].left !== -1 && !visited[graph[x].left]) {
    ans++;
    solution(graph[x].left, false);
  }

  if (endFlag) return;

  // 오른쪽 자식 노드가 없거나 방문했다면 해당 노드 재귀X
  if (graph[x].right !== -1 && !visited[graph[x].right]) {
    ans++;
    solution(graph[x].right, false);
  }

  if (endFlag) return;

  // 해당 노드가 마지막임을 체크
  if (x == endIdx) {
    endFlag = true;
    return;
  }

  if (!first) ans++; // 루트 노드는 부모가 없기 때문에 재귀가 끝나도 이동횟수를 더하면 안된다
  visited[x] = true;
}
