const fs = require("fs");
const file = process.platform === "linux" ? "/dev/stdin" : "./example.txt";
const input = fs.readFileSync(file).toString().trim().split("\n");

const N = +input[0];
const H = input[1].split(" ").map(Number);

function solution(N, H) {
  let answer = 0;
  let arrows = Array(1000000).fill(0);

  for (let i of H) {
    if (arrows[i]) {
      arrows[i]--;
      arrows[i - 1]++;
    } else {
      answer++;
      arrows[i - 1]++;
    }
  }

  return answer;
}

console.log(solution(N, H));
