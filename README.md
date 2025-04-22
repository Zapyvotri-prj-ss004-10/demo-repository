# Branch `an-moi` 

This branch focuses on the **fruit-eating logic** of the Snake game.

## Goals:
- Generate a fruit at a random position within the game area.
- Detect when the snake's head touches the fruit.
- Increase the score and grow the snake's length after eating.
- Generate a new fruit after the previous one is eaten.

## Why a separate branch?
Separating the fruit-eating feature helps to:
- Isolate and test fruit collision and random generation without interfering with other logic.
- Ensure the game reacts correctly when the snake eats a fruit.
- Prepare the core gameplay loop for the full experience.
---
📌 Note:  
This branch builds upon a base version that already includes the frame and snake movement. Make sure those parts are working before testing this one.
