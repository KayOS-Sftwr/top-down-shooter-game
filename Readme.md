# 🧟‍♂️ 2D Top-Down Zombie Survival Shooter

This project is a top-down 2D survival arena shooter developed using C++ and SFML (Simple and Fast Multimedia Library). The player must survive endless waves of zombies, collect power-ups, and achieve the highest score possible.

## ✨ Features
* **Dynamic Aiming:** The player character and bullets dynamically rotate 360 degrees to face the mouse cursor in real-time.
* **Loot Drop System:** Defeated enemies have a chance to drop Speed, Health, and Damage power-ups based on a specific loot table.
* **Buff Timers:** Active power-ups last for a limited duration (e.g., 10 seconds), tracked independently via `sf::Clock` without frame-trap bugs.
* **Bullet Mechanics:** Damage buffs dynamically apply to both existing bullets in the air and newly fired bullets during the buff duration.
* **UI & Audio:** Integrated dynamic health bar, seamless map textures, and background/action sound effects using the `sfml-audio` module.
* **Screen Warping:** Pac-man style screen boundary warping for the player movement.

## 🎮 Controls
* **Movement:** `W`, `A`, `S`, `D` keys
* **Shoot:** `Left Mouse Button`
* **Aim:** `Mouse Cursor`

## 🛠️ Dependencies
To build and run this project, the following tools and libraries are required:
* A C++14 (or higher) compatible compiler (e.g., MinGW GCC)
* **SFML 2.5+** (Graphics, Window, System, and Audio modules)

## 🚀 Build Instructions
This project includes a `Makefile` for easy compilation. Open your terminal in the project directory and follow these steps:

1. **To compile the game:**
   ```bash
   make