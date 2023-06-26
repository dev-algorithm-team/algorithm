const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "example.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

const [N, M] = input;
let arr = M.split(" ").map(Number);

const answer = [];

const set = Array.from(new Set([...arr])).sort((a, b) => a - b);
const obj = {};

set.forEach((item, idx) => (obj[item] = idx));
for (let i = 0; i < N; i++) {
  answer.push(obj[arr[i]]);
}
console.log(answer.join(" "));
