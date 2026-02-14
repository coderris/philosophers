*This project has been created as part of the 42 curriculum by lanton-m.*

# Philosophers

## Description

**Philosophers** is an implementation of the classic Dining Philosophers Problem, a synchronization problem proposed by Edsger Dijkstra in 1965.

The problem consists of N philosophers seated around a circular table, each with a plate of spaghetti and a fork between each pair of philosophers. To eat, a philosopher must pick up both adjacent forks. The goal is to design an algorithm that allows philosophers to eat and think without deadlock or starvation occurring.

### Objective

The main objective of this project is to learn and apply fundamental concepts of concurrent programming:

- **Threads**: Each philosopher is represented by an independent thread.
- **Mutex**: Forks are shared resources protected by mutexes.
- **Synchronization**: Preventing race conditions, deadlocks, and starvation.
- **Time management**: Precise control of philosophers' life, eating, and sleeping times.

## Instructions

### Compilation

```bash
make
```

Other available commands:
- `make clean` - Removes object files
- `make fclean` - Removes object files and executable
- `make re` - Recompiles the entire project

### Execution

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

#### Parameters

| Parameter | Description |
|-----------|-------------|
| `number_of_philosophers` | Number of philosophers (and forks) |
| `time_to_die` | Time in milliseconds before a philosopher dies if they don't eat |
| `time_to_eat` | Time in milliseconds it takes a philosopher to eat |
| `time_to_sleep` | Time in milliseconds a philosopher spends sleeping |
| `number_of_times_each_philosopher_must_eat` | (Optional) Number of times each philosopher must eat before the simulation ends |

#### Usage examples

```bash
# 5 philosophers, die in 800ms, eat 200ms, sleep 200ms
./philo 5 800 200 200

# 4 philosophers who must eat at least 7 times each
./philo 4 410 200 200 7

# Death test: the philosopher should die
./philo 1 800 200 200
```

### Output format

The program prints each philosopher's actions in the following format:
```
timestamp_in_ms X has taken a fork
timestamp_in_ms X is eating
timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X died
```

## Resources

### Official documentation

- [POSIX Threads Programming](https://computing.llnl.gov/tutorials/pthreads/) - Complete tutorial on pthreads
- [pthread_create man page](https://man7.org/linux/man-pages/man3/pthread_create.3.html)
- [pthread_mutex_lock man page](https://man7.org/linux/man-pages/man3/pthread_mutex_lock.3p.html)

### Articles and tutorials

- [Dining Philosophers Problem - Wikipedia](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
- [Understanding the Dining Philosophers Problem](https://www.geeksforgeeks.org/dining-philosopher-problem-using-semaphores/)
- [Deadlock and Starvation](https://www.geeksforgeeks.org/deadlock-starvation-and-livelock/)

### AI Usage

AI assistance (GitHub Copilot) was used in this project for the following tasks:

- **Debugging**: Identification of synchronization errors and race conditions.
- **Code formatting**: Indentation correction and norminette compliance.
- **Documentation**: Generation of this README.md file.
- **Doubt resolution**: Queries about correct use of double pointers, function return types, and C syntax.

The logical code and project structure were developed independently, using AI as a support and learning tool.

## Project structure

```
phi/
├── Makefile
├── README.md
├── include/
│   └── philosophers.h
└── srcs/
    ├── cleaners.c      # Cleanup and memory release functions
    ├── monitor.c       # Monitor thread that detects deaths
    ├── parser.c        # Argument parsing
    ├── philosophers.c  # Main function and core logic
    ├── rutine.c        # Philosopher routine (eat, sleep, think)
    ├── time.c          # Time management functions
    └── utils.c         # Utility functions and initialization
```

## Author

- **lanton-m** - [42 Málaga](https://www.42malaga.com/)