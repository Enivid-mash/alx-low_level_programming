#!/usr/bin/python3


def island_perimeter(grid):
    """
    Calculate the perimeter of the island described in the grid.

    Args:
        grid (List[List[int]]): A list of lists representing the grid where:
            0 represents a water zone
            1 represents a land zone

    Returns:
        int: The perimeter of the island.

    Note:
        - One cell is a square with side length 1.
        - Grid cells are connected horizontally/vertically (not diagonally).
        - The grid is rectangular, and width and height don't exceed 100.
        - The grid is completely surrounded by water, and there is one
          island (or nothing).
        - The island doesn't have "lakes" (water inside that isn't connected
          to the water around the island).
    """
    perimeter = 0

    # Define directions: Up, Down, Left, Right
    directions = [(0, 1), (0, -1), (-1, 0), (1, 0)]

    # Iterate through the grid
    for row in range(len(grid)):
        for col in range(len(grid[0])):
            if grid[row][col] == 1:
                for dr, dc in directions:
                    r, c = row + dr, col + dc
                    # Check if the neighbor is out of bounds or water (0)
                    if r < 0 or r >= len(grid) or c < 0 or c >= len(grid[0])
                    or grid[r][c] == 0:
                        perimeter += 1

    return perimeter
