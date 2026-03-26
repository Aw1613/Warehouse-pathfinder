# 🤖 Warehouse Robot Pathfinder

> Simulating how robots in large storage facilities like Amazon and Flipkart navigate through warehouse grids to pick up parcels and deliver them to drop-off points — using intelligent pathfinding.

---

## 🏭 Real World Inspiration

In large storage facilities like Amazon and Flipkart warehouses, hundreds of robots operate simultaneously on a grid-based floor. Each robot has to:
- Start from a base position
- Navigate through shelves and obstacles
- Reach the item location
- Deliver it to the drop-off point

This project simulates exactly that — a robot finding its way through a warehouse grid with obstacles, using the BFS (Breadth First Search) algorithm to find the most optimal path.

---

## 📌 Features

- 10x10 warehouse grid rendered on the terminal
- Obstacle placement support (hardcoded maps + user input mode)
- BFS algorithm to find the shortest path from Start to End
- Path backtracing using parent arrays to mark the optimal route
- Robot class that reads grid state and navigates accordingly
- Clean OOP structure with separated responsibilities per class

---

## 🧠 Concepts Used

### Object Oriented Programming
- Classes with public members — `Grid`, `Robot`, `BFS`
- Inheritance — `BFS` inherits from `Grid` to access the warehouse map
- Encapsulation — each class handles its own responsibility

### Data Structures & Algorithms
- **2D Arrays** — for grid representation and visited/parent tracking
- **Queue** — core data structure driving BFS (FIFO traversal)
- **BFS (Breadth First Search)** — explores the grid level by level to guarantee the shortest path
- **Path Backtracing** — uses `parentRow` and `parentCol` arrays to trace back from End to Start after BFS completes

---

## 🗺️ Grid Legend

| Symbol | Meaning |
|--------|---------|
| `S` | Start position |
| `E` | End / Drop-off point |
| `X` | Obstacle / Shelf |
| `.` | Free cell |
| `*` | Optimal path found by BFS |

---

## ⚙️ How It Works

```
1. Warehouse grid is initialized with obstacles, start and end points
2. BFS starts from S (0,0) and explores all reachable cells
3. For every cell visited, its parent coordinates are recorded
4. When E is reached, BFS stops
5. Path is traced back from E → S using the parent arrays
6. Traced path is marked with * and displayed on the grid
```

---

## 🏗️ Project Structure

```
warehouse-robot-pathfinder/
│
├── src/                  → source files
├── include/              → header files  
├── maps/                 → map configuration files
└── README.md
```

---

## 🚀 How To Run

```bash
g++ main.cpp -o warehouse
./warehouse
```

---

## 📚 Language & Tools

- **Language** — C++
- **Paradigm** — Object Oriented Programming
- **Algorithm** — Breadth First Search (BFS)
- **Platform** — CLI (Terminal)

---

## 🔮 Future Scope

- A* algorithm implementation for heuristic-based faster pathfinding
- Dynamic map randomizer that generates solvable maps every run
- Multiple robot simulation on the same grid
- Visual animation of robot movement step by step