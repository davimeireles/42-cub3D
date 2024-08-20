# Project: Cub3D - Creating a 3D Game Engine with Raycasting

## Project Overview

The primary objective of Cub3D was to develop a dynamic view inside a maze, creating the illusion of 3D graphics in a 2D environment. This project deepened my understanding of graphics programming, mathematical concepts in computer graphics, and game development principles.

### Raycasting Explained

Raycasting is a rendering technique used to simulate a 3D perspective in a 2D environment. It works by casting rays from the player's viewpoint into the game world to detect walls and other objects. Each ray calculates the distance to the nearest wall, and this information is used to determine the height of the wall slice to be drawn on the screen. The result is a pseudo-3D effect that gives the illusion of depth and perspective, allowing for immersive environments in games. This technique is computationally efficient and was popularized by early 3D games like Wolfenstein 3D.

## Key Features

### 3D Rendering

- Implemented raycasting algorithm to create a 3D perspective
- Smooth wall rendering with proper shading based on distance
- Textured walls for enhanced visual appeal

### Map Parsing and Validation

- Ability to read and parse map files with a custom format
- Validation of map integrity and structure

### Player Movement

- Smooth player movement (forward, backward, strafe left, right)
- Rotation of the player's view (left and right)

### Graphical Interface

- Window management using the MiniLibX library
- Handling of keyboard inputs for player control

## Technical Implementation

### Raycasting Algorithm

- Implemented DDA (Digital Differential Analyzer) algorithm for efficient ray calculations
- Calculated wall heights and positions based on ray intersections

### Texture Mapping

- Applied textures to walls based on their orientation and position
- Implemented texture scaling and proper alignment

### Map Management

- Created a 2D array representation of the map
- Implemented collision detection for player movement
