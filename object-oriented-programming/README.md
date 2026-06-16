# Object-Oriented Programming (POO)

Java coursework demonstrating core OOP concepts: classes, inheritance, polymorphism, and encapsulation.

**Author:** Kevin Kurpias Rodrigues

## Project overview

A simplified university management demo that models people, students, and employees with a salary control system.

### Class hierarchy

```
Pessoa
├── Aluno
└── Funcionario
    ├── Chefe
    └── Professor
```

### Source files (`src/`)

| File | Role |
|------|------|
| `Pessoa.java` | Base class — name, phone, birth date |
| `Data.java` | Date value object |
| `Aluno.java` | Student — enrollment and weekly course load |
| `Funcionario.java` | Employee — registry number and base salary |
| `Chefe.java` | Manager — role title and bonus calculation |
| `Professor.java` | Professor — hourly rate and teaching load |
| `ControleSalario.java` | Static helpers to sum base and bonus-adjusted salaries |
| `Principal.java` | Entry point — creates sample objects and prints results |

### Documentation

- [`docs/TrabalhoBimestre1.pdf`](docs/TrabalhoBimestre1.pdf) — 1º Bimestre assignment write-up

## Run

```bash
cd src
javac *.java
java Principal
```
