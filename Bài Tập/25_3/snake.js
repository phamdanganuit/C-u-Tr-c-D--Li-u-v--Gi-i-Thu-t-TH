// Define the canvas and context
var canvas = document.getElementById("canvas");
var ctx = canvas.getContext("2d");

// Define the initial position of the snake
var snake = [
  { x: 10, y: 10 },
  { x: 10, y: 20 },
  { x: 10, y: 30 },
];

// Define the initial position of the food
var food = { x: 50, y: 50 };

// Define the size of the snake and food
var blockSize = 10;

// Define the current direction of the snake
var direction = "down";

// Define a function to draw the snake and food
function draw() {
  // Clear the canvas
  ctx.clearRect(0, 0, canvas.width, canvas.height);

  // Draw the food
  ctx.fillStyle = "red";
  ctx.fillRect(food.x, food.y, blockSize, blockSize);

  // Draw the snake
  ctx.fillStyle = "green";
  snake.forEach(function (block) {
    ctx.fillRect(block.x, block.y, blockSize, blockSize);
  });
}

// Define a function to update the position of the snake
function update() {
  // Move the snake in the current direction
  var head = { x: snake[0].x, y: snake[0].y };
  switch (direction) {
    case "up":
      head.y -= blockSize;
      break;
    case "down":
      head.y += blockSize;
      break;
    case "left":
      head.x -= blockSize;
      break;
    case "right":
      head.x += blockSize;
      break;
  }
  snake.unshift(head);

  // Check if the snake has collided with the food
  if (head.x === food.x && head.y === food.y) {
    // Move the food to a new position
    food.x = Math.floor(Math.random() * (canvas.width / blockSize)) * blockSize;
    food.y = Math.floor(Math.random() * (canvas.height / blockSize)) * blockSize;
  } else {
    // Remove the tail of the snake
    snake.pop();
  }
}

// Define a function to handle key presses
function handleKeyPress(event) {
  switch (event.keyCode) {
    case 38: // Up arrow
      direction = "up";
      break;
    case 40: // Down arrow
      direction = "down";
      break;
    case 37: // Left arrow
      direction = "left";
      break;
    case 39: // Right arrow
      direction = "right";
      break;
  }
}

// Start the game loop
setInterval(function () {
  update();
  draw();
}, 100);

// Add event listener for key presses
document.addEventListener("keydown", handleKeyPress);
