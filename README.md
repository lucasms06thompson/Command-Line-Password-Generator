# Command-Line Password Generator in C

![Language](https://img.shields.io/badge/language-C-blue.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)

A secure and customizable command-line password generator written in C. This tool allows you to quickly create strong, random passwords directly from your terminal.

This project demonstrates random number generation, string manipulation, and command-line option parsing in C.

## Features

- **Customizable Length:** Specify the exact length of the password.
- **Character Set Control:** Easily include or exclude character types (uppercase, lowercase, numbers, symbols).
- **Secure:** Uses `time()` to seed the pseudo-random number generator for varied results on each run.
- **Lightweight:** A single, small, and fast C executable with no external dependencies.

## Prerequisites

To compile and run this project, you will need:
- A C compiler (like `gcc`)
- `make` build automation tool

## How to Get Started

### 1. Clone the Repository

```bash
git clone https://github.com/YOUR_USERNAME/YOUR_REPOSITORY_NAME.git
cd YOUR_REPOSITORY_NAME
```

### 2. Compile the Program

Use the provided `Makefile` to compile the source code.

```bash
make
```
This will create an executable file named `passgen` in the project directory.

### 3. How to Use

The first argument is always the desired password length. Optional flags can be used to exclude character sets.

**Generate a 16-character password with all character types:**
```bash
./passgen 16
```
> Example output: `Generated Password: aK8!t@pX$zF3j&vE`

**Generate a 12-character password without symbols:**
```bash
./passgen 12 --no-symbols
```
> Example output: `Generated Password: 7gRzP4mYwE9N`

**Generate a 20-character password with only lowercase letters and numbers:**
```bash
./passgen 20 --no-upper --no-symbols
```
> Example output: `Generated Password: x4p0q9m2v3r8k1y5j7c6`

## License

This project is licensed under the MIT License.
