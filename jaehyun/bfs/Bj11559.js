const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "example.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

const colorMap = input.map((row) => row.split(""));
const ds = [
  [-1, 0],
  [1, 0],
  [0, 1],
  [0, -1],
];

let stage = 0;

while (true) {
  let isYeonSwae = false;
  const visited = Array.from({ length: 12 }, () => Array(6).fill(false));

  for (let i = 0; i < 12; i++) {
    for (let j = 0; j < 6; j++) {
      if (!visited[i][j] && colorMap[i][j] !== ".") {
        const arr = bfs(j, i, visited);
        if (arr.length >= 4) {
          isYeonSwae = true;
          arr.forEach(([x, y]) => {
            colorMap[y][x] = ".";
          });
        }
      }
    }
  }

  toGround();
  if (isYeonSwae) stage++;
  else break;
}

console.log(stage);

function bfs(startX, startY, visited) {
  const q = [[startX, startY]];
  visited[startY][startX] = true;

  const ansXY = [[startX, startY]];

  while (q.length) {
    const [X, Y] = q.shift();
    for (let i = 0; i < 4; i++) {
      const dx = X + ds[i][0];
      const dy = Y + ds[i][1];
      if (
        dx >= 0 &&
        dx < 6 &&
        dy >= 0 &&
        dy < 12 &&
        !visited[dy][dx] &&
        colorMap[dy][dx] == colorMap[Y][X]
      ) {
        visited[dy][dx] = true;
        ansXY.push([dx, dy]);
        q.push([dx, dy]);
      }
    }
  }

  return ansXY;
}

function toGround() {
  for (let i = 0; i < 6; i++) {
    for (let j = 11; j >= 0; j--) {
      if (colorMap[j][i] == ".") {
        for (let k = j - 1; k >= 0; k--) {
          if (colorMap[k][i] !== ".") {
            colorMap[j][i] = colorMap[k][i];
            colorMap[k][i] = ".";
            break;
          }
        }
      }
    }
  }
}
