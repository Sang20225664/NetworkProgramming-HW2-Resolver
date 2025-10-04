# HW2 - Network Programming (Resolver)


## Assignment Description
This program implements a simple **DNS Resolver** with the following features:
- Detect whether the input parameter is an IPv4 address or a domain name.
- If input is a domain name → perform **forward resolution** (domain → IP).
- If input is an IPv4 address → perform **reverse resolution** (IP → domain).
- If no information is found → output: `Not found information`.
- Handle invalid input (invalid IPv4 format or invalid domain).

---

## Source Code Organization
HW2/
├── main.c # Main program entry
├── resolver.c # Implementation of helper functions
├── resolver.h # Function prototypes
├── Makefile # Build configuration
└── README.md # Documentation


- `main.c`: Handle program flow and command line arguments.
- `resolver.c`: Implement helper functions (`isValidIPv4`, `resolveDomain`, `resolveIP`).
- `resolver.h`: Header file with function declarations.
- `Makefile`: Build script (output file: `resolver`).

---

## Build Instructions
Tested on **Ubuntu 20.04, GCC Compiler, C11 standard**.

make clean
make
./resolver <parameter>
Example:

bash
Copy code
./resolver google.com
./resolver 8.8.8.8
Example Outputs
shell
Copy code
$ ./resolver google.com
142.250.195.110
142.250.195.113
...

$ ./resolver 8.8.8.8
dns.google
If not found:

mathematica
Copy code
Not found information
Notes
Code follows modular design with separate .c and .h files.

All functions have English comments.

Variables and functions are named meaningfully.

Indentation and formatting are consistent.

No unused code remains.

