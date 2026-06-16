<<<<<<< HEAD
# Kportfolio — University Projects

A curated collection of coursework and exercises from computer science studies, organized by subject area. Each folder contains source code, assets, and (where applicable) supporting documentation from original assignments.

**Author:** Kevin Kurpias Rodrigues

---

## Repository structure

| Folder | Course / topic | Description |
|--------|----------------|-------------|
| [`data-structures/`](data-structures/) | Estrutura de Dados I | C/C++ implementations of classic data structures, search algorithms, graphs, and hash tables |
| [`object-oriented-programming/`](object-oriented-programming/) | Programação Orientada a Objetos | Java class hierarchy demonstrating inheritance, polymorphism, and encapsulation |
| [`web-development/`](web-development/) | Desenvolvimento Web | Front-end exercises in HTML, CSS, and JavaScript |

---

## Data Structures

See [`data-structures/README.md`](data-structures/README.md) for the full index.

### Group project

| Project | Path | Summary |
|---------|------|---------|
| **Token Ring** | [`data-structures/projects/token-ring/`](data-structures/projects/token-ring/) | Multi-process token ring simulation using pipes, signals, and `fork()` (group work with Gustavo Guse Martins and Nicolas Folquenin) |

### Term assignment

| Assignment | Path | Summary |
|------------|------|---------|
| **1º Bimestre — Listas Sequenciais e Dinâmicas** | [`data-structures/assignments/bimestre-1-sequential-dynamic-lists/`](data-structures/assignments/bimestre-1-sequential-dynamic-lists/) | Sequential and dynamic linked lists with ordered insertion, search, and removal |

### Lab practices (Práticas)

| # | Topic | Path |
|---|-------|------|
| 01 | Stack (Pilha) | [`practices/01-stack/`](data-structures/practices/01-stack/) |
| 02 | Queue (Fila) | [`practices/02-queue/`](data-structures/practices/02-queue/) |
| 02 | Graphs — adjacency matrix | [`practices/02-graphs-adjacency-matrix/`](data-structures/practices/02-graphs-adjacency-matrix/) |
| 03 | Graphs — adjacency list (dynamic allocation) | [`practices/03-graphs-adjacency-list/`](data-structures/practices/03-graphs-adjacency-list/) |
| 03 | Linear list | [`practices/03-linear-list/`](data-structures/practices/03-linear-list/) |
| 04 | Dynamic stack | [`practices/04-dynamic-stack/`](data-structures/practices/04-dynamic-stack/) |
| 04 | Sequential and binary search | [`practices/04-sequential-binary-search/`](data-structures/practices/04-sequential-binary-search/) |
| 05 | Dynamic queue | [`practices/05-dynamic-queue/`](data-structures/practices/05-dynamic-queue/) |
| 05 | Search methods comparison | [`practices/05-search-comparison/`](data-structures/practices/05-search-comparison/) |
| 06 | Binary search tree | [`practices/06-binary-search-tree/`](data-structures/practices/06-binary-search-tree/) |
| 06 | Top-down tree vs. B-tree comparison | [`practices/06-b-tree-comparison/`](data-structures/practices/06-b-tree-comparison/) |
| 07 | String binary search tree | [`practices/07-string-bst/`](data-structures/practices/07-string-bst/) |
| 07 | Hash tables (tabelas de espalhamento) | [`practices/07-hash-tables/`](data-structures/practices/07-hash-tables/) |
| 08 | Chained hash tables | [`practices/08-chained-hash-tables/`](data-structures/practices/08-chained-hash-tables/) |

---

## Object-Oriented Programming

See [`object-oriented-programming/README.md`](object-oriented-programming/README.md).

Java application modeling a university payroll system with an inheritance hierarchy:

- **`Pessoa`** — base class (name, phone, birth date)
- **`Aluno`**, **`Funcionario`** — specialized subclasses
- **`Chefe`**, **`Professor`** — further specialization with salary bonuses
- **`ControleSalario`** — aggregates base and bonus-adjusted salaries

**Run:** compile all `.java` files in `src/` and execute `Principal`.

**Documentation:** [`docs/TrabalhoBimestre1.pdf`](object-oriented-programming/docs/TrabalhoBimestre1.pdf)

---

## Web Development

See [`web-development/README.md`](web-development/README.md).

| Project | Path | Summary |
|---------|------|---------|
| **CSS Grid Layout** | [`web-development/css-grid/`](web-development/css-grid/) | Responsive page layout built with CSS Grid, custom fonts, and animated elements |
| **DOM Video Player** | [`web-development/dom-video-player/`](web-development/dom-video-player/) | Custom HTML5 video player with play/pause, progress bar, volume, and fullscreen — built with vanilla JavaScript DOM APIs |
| **Intro to JavaScript** | [`web-development/intro-javascript/`](web-development/intro-javascript/) | Countdown timer with set/ start / pause / reset controls |

**Run:** open the `pagina.html` or `aulagrid.html` file in any modern browser.

---

## Building C/C++ projects

Most data-structure exercises are single-file programs. From any practice folder:

```bash
g++ -o program main.cpp && ./program
```

The token ring project requires a POSIX environment (Linux/macOS):

```bash
g++ -o token-ring main.cpp && ./token-ring 4
```

---

## License

Academic coursework — see individual files for authorship and course details.
=======
# Kportfolio
projects portfolio for job interviews and curriculum indexing
>>>>>>> 7cd7c1a76f29794d82ad1147cb39d851f898c812
