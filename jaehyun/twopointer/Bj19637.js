const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "example.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

const [N, M] = input[0].split(" ").map(Number);
const attack = new Map();

for (let i = 1; i <= N; i++) {
  const [name, val] = input[i].split(" ");
  if (!attack.get(val)) attack.set(val, name);
}

const realAttack = [...attack].sort((a, b) => a[0] - b[0]);

for (let i = N + 1; i < N + M + 1; i++) {
  const target = +input[i];
  let start = 0;
  let end = realAttack.length - 1;
  let ans;

  while (start <= end) {
    let mid = Math.floor((start + end) / 2);
    if (realAttack[mid][0] == target) {
      ans = realAttack[mid][1];
      break;
    } else if (realAttack[mid][0] < target) {
      start = mid + 1;
      ans = realAttack[start][1];
    } else {
      end = mid - 1;
      ans = realAttack[mid][1];
    }
  }

  console.log(ans);
}
