This exercise helped me understand the following:

- These are the factors that could affect the process scheduling:
    - Process Switch Behaviour: If a process has gone for I/O, your strategy to switch to another process/stay can matter
    - Sequence of processes: If a process is going through I/O, run it before the non I/O process, as during I/O non I/O process can run
    - During process execution, priority could kick in

- I/O
    - Multiple processes can go for I/O at the same time
    - This is limited at the hardware side, OS should not block it