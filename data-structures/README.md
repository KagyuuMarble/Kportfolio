# Data Structures (Estrutura de Dados I)

C/C++ coursework covering fundamental data structures and algorithms.  
**Instructor:** Prof. Albino Szesz Jr. · **Author:** Kevin Kurpias Rodrigues (RA: 22017826)

## Projects

| Folder | Description |
|--------|-------------|
| [`projects/token-ring/`](projects/token-ring/) | Token ring protocol simulation with multiple child processes, pipes, and signals. Group project (Kevin Kurpias, Gustavo Guse Martins, Nicolas Folquenin). |

## Assignments

| Folder | Description |
|--------|-------------|
| [`assignments/bimestre-1-sequential-dynamic-lists/`](assignments/bimestre-1-sequential-dynamic-lists/) | 1º Bimestre term paper — sequential lists and dynamically allocated ordered linked lists. Includes two submission versions (`main.cpp`, `main-v2.cpp`). |

## Practices

Each folder contains a self-contained `main.cpp` with an interactive menu unless noted otherwise.

| Folder | Original title | Topic |
|--------|----------------|-------|
| [`practices/01-stack/`](practices/01-stack/) | Prática 01 Pilha | Fixed-size stack (push, pop, peek) |
| [`practices/02-queue/`](practices/02-queue/) | Prática 02 Fila | Fixed-size queue |
| [`practices/02-graphs-adjacency-matrix/`](practices/02-graphs-adjacency-matrix/) | Prática 02 Grafos | Graph represented as adjacency matrix |
| [`practices/03-graphs-adjacency-list/`](practices/03-graphs-adjacency-list/) | Prática 03 Grafos | Graph with dynamically allocated adjacency list |
| [`practices/03-linear-list/`](practices/03-linear-list/) | Prática 03 Lista Linear | Linear list operations |
| [`practices/04-dynamic-stack/`](practices/04-dynamic-stack/) | Prática 04 Pilha Dinâmica | Stack with dynamic memory allocation |
| [`practices/04-sequential-binary-search/`](practices/04-sequential-binary-search/) | Prática 04 Busca | Sequential vs. binary search |
| [`practices/05-dynamic-queue/`](practices/05-dynamic-queue/) | Prática 05 Fila Dinâmica | Queue with dynamic memory allocation |
| [`practices/05-search-comparison/`](practices/05-search-comparison/) | Prática 05 Busca | Performance comparison of search methods |
| [`practices/06-binary-search-tree/`](practices/06-binary-search-tree/) | Prática 06 ABB | Binary search tree (insert, search, traverse) |
| [`practices/06-b-tree-comparison/`](practices/06-b-tree-comparison/) | Prática 06 Árvores | Top-down tree vs. B-tree comparison |
| [`practices/07-string-bst/`](practices/07-string-bst/) | Prática 07 ABB Strings | Binary search tree storing strings |
| [`practices/07-hash-tables/`](practices/07-hash-tables/) | Prática 07 Espalhamento | Hash table (open addressing) |
| [`practices/08-chained-hash-tables/`](practices/08-chained-hash-tables/) | Prática 08 Espalhamento Encadeada | Hash table with chaining |

## Build

```bash
g++ -o program main.cpp && ./program
```
