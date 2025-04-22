# Snake Game Repository

## Branch Structure

For modular development, the project is divided into:
- `ve-khung` - Draws the game frame
- `an-moi` - Implements fruit-eating functionality
- `di-chuyen` - Handles snake movement
- `menu-score` - Manages menu and scoring (current branch)
- `main` - Primary branch for tested features

## Current Branch: `menu-score`

### Menu & Score Implementation
- Displays game options: Start Game, Highscore, Exit
- Guides players through available options
- Shows game notifications

### Why Separate Branch?
- Isolated testing of menu functionality
- Easier debugging without affecting other components
- Simplified feature additions

📌 Note:  
Test thoroughly before merging with main branch.

## Repository Setup
- Includes `code-mau.exe` for C++ console rendering
- Contains GitHub Actions workflows
- Uses CSS stylesheet dependency

### Quick Start:
1. Clone repository:
   ```bash
   gh repo clone Zapyvotri-prj-ss004-10/demo-repository