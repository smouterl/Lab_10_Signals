# Lab 10: Signals
These programs explore signal handlers, alarms, segmentation faults, and sending information between processes.

## Build

Run `make` to build all programs, or `make clean` to remove the executables.

## Programs

- `signal_handler`: Handles SIGINT and continues running.
- `signal_alarm`: Receives SIGALRM after five seconds.
- `signal_segfault`: Handles a segmentation fault caused by a null pointer. It repeats until stopped.
- `signal_sigaction`: Prints the PID of the process that sends SIGUSR1.
- `recv_signal` and `send_signal`: Send a random integer using SIGUSR1.

For the sender and receiver, run `./recv_signal` first. Then run `./send_signal <PID>` in another terminal, replacing `<PID>` with the receiver's displayed PID. Stop the receiver with Ctrl+C.
