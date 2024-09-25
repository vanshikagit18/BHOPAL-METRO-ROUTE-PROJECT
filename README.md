# BHOPAL-METRO-ROUTE-PROJECT
# ABSTRACT
This project is a metro route optimization system designed for the Bhopal city metro. It helps users find the shortest path between two metro stations using Dijkstra's algorithm, along with other station-related utilities. This solution is implemented in C++ and uses data structures such as graphs, priority queues, and arrays to ensure efficient routing.

# Table of Contents
- [Features](#features)
- [Project Structure](#project-structure)
- [Station Details](#station-details)
- [Technologies](#technologies)
- [Future Scope](#future-scope)
- [Contributing](#contributing)
- [License](#license)

# Features

- **Shortest Path Calculation**: Calculates the shortest route between two metro stations using Dijkstra's algorithm.
- **Route Visualization**: Prints the route from the source station to the destination station, including station names and IDs.
- **Station Details**: Displays all available stations and their connectivity.
- **Multi-Destination Calculation**: Computes and prints the shortest paths from one source station to all other stations in the network.

# Project Structure

The project is organized into the following components:

1. **Metro Class**: This is the core of the project, representing the metro network using a graph data structure. It contains:
   - `SetStation()`: Sets up the adjacency list for station connectivity.
   - `TellMeRoute()`: Displays the optimal route from the source station to the destination station.
   - `AllPossibleDestination()`: Implements Dijkstra’s algorithm to calculate the shortest paths from a source to all other stations.
   - `ToDestination()`: Returns the minimum number of stations between a source and destination.
   - `showStation()`: Displays the list of all metro stations.

2. **CompareByValue Class**: A helper class used in Dijkstra's algorithm for priority queue comparison.

# Station Details

The project contains data for 53 metro stations in Bhopal, with connections between the stations represented in a graph. Each station has an ID and a corresponding name:

- `0`: Gandhi Nagar
- `1`: Karond
- `2`: Berasia
- ...
- `52`: Bairagarh Chichli

You can view the full list of stations using the `showStation()` method.

# Technologies

- **Programming Language**: C++
- **Key Data Structures**:
  - Graph (Adjacency List)
  - Priority Queue
  - Arrays and Stacks
- **Algorithms**: Dijkstra's Algorithm for finding the shortest path



# Future Scope

- **Interactive User Interface**: Build a graphical user interface (GUI) to make the system more user-friendly.
- **Real-Time Updates**: Integrate real-time metro scheduling or traffic information.
- **Route Optimization Algorithms**: Implement alternative algorithms like A* or Bellman-Ford to compare efficiency with Dijkstra’s algorithm.

# Contributing

Contributions are welcome! Feel free to fork this repository and submit pull requests for any improvements or bug fixes.

