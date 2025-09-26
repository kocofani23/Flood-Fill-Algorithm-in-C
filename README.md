# 🎨 Flood Fill Algorithm in C

This project is a **C implementation of the flood fill algorithm**, commonly used in image editing (e.g., the "paint bucket" tool).  
It fills all connected adjacent cells (up, down, left, right) of the same value, starting from a user-defined coordinate.

---

## 📌 Features
- Reads:
  - A **square matrix** from the user.
  - A starting coordinate `(x, y)`.
- Detects all **adjacent cells** with the same value as `(x, y)`.
- Recolors them with a new value (`newColor`).
- Uses **recursion** for traversal (depth-first search style).
- Handles **boundary checks** to avoid invalid accesses.

---

## ⚙️ How It Works
1. User provides:
   - Size of the matrix.
   - Matrix elements.
   - Coordinates `(x, y)` to flood fill.
2. Program:
   - Stores the starting value as `sourceColor`.
   - Calls `floodFill()` recursively to recolor connected cells.
   - Updates the matrix in place.
3. Prints the updated matrix.

---

## 🚀 Compilation & Execution

### Compile
```bash
gcc flood_fill.c -o flood_fill
