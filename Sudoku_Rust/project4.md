# Project 4

## Name: Ayush Pathak
I worked on the project by myself.

## Instructions on how to install compiler/interpreter

I used Rust analyzer extension on vscode to help with writing the rust code.
[![Link Referenced for Rust analyzer]()](https://www.geeksforgeeks.org/how-to-setup-rust-in-vscode/#)
[![Link Referenced for interpreter]()](https://doc.rust-lang.org/cargo/getting-started/installation.html)

### For Interpreter and compiler install rustup
I used VScode as my IDE, which can be installed from google.
For interpreter:
#### For windows 
here's the link https://win.rustup.rs/

#### For Mac and linux
Here's the command to run in the terminal

```
curl https://sh.rustup.rs -sSf | sh
```

## Instructions on how to run (and test) program

#### To run the code
First build with:
```
cargo build
```
Then run:
```
cargo run
```
- Cargo run will run the main file and ask for a specific path that problem is located in.

In order to run the test file with three tests run the command below:
```
cargo test
```

## Questions

### 1. Did you use an LLM (e.g., ChatGPT) to assist you with the completion of this project?


### If yes, was it helpful or not? Provide a brief description of whether it was helpful or not. Also, provide a percentage of how much it helped you in each of the four main tasks (i.e., loading from a file, solving Sudoku, configuring the testing, configuring the GitHub Actions workflow).



### If no, did you search the Internet for solutions? If so, provide the website(s) where you copied a considerable amount of code. For example, the website that you copied the core Sudoku solver.

1) I utilized ChatGPT. It was helpful, I used CHATGpt to help with the loading from file, and formatting display in rust I didn't know how reading from file works in RUST and chatgpt helped with that. About 20% of the method was from ChatGPT. I asked chat GPT how to convert between C++ and RUST and used it to convert my previous C++ code into RUST code. Overall, Many clarifying questions were asked to ChatGPT inorder to understand workings of rust and writing code, but total help with writing code is around 10%.


### 2. Provide a description of two constructs/features of the language that you found interesting (or was new to you) that you liked. Do not just list the constructs/features, but provide a description and why you liked them.

2) One of the coolest features in rust is the automatically derivation for some things. #derive with debug parameter provides a clean mechanism for printing the sudoku class. This feature adds basic functionality to custom types, it made debugging process and inspecting the status of sudoku throughout the algorithm more clear and easy to implement. Deriving traits makes C++ inheritance look so much harder, it is a lot easier implementation, so no reason not to love it. Another cool feature is the error handling in rust. I used the built in Result error handling, and it made error handling simple compared to C++ and C(what I use). While loading file, the error handling was nice with no extra work,I just passed it into Result. If there were to be an issue it would return error or else pass the board, making it super easy to generate the robust code. 

### 3. Provide a description of two constructs/features of the language that you disliked or was hard to understand. Do not just list the constructs/features, but provide a description and why you disliked them.

3) One thing that I didn't like was the concept of lifetime. My display function wasn't working properly and while debugging it, I learned that there was this operator, "<'_>" that repesents lifetime parameter. How long the reference should exist isn't explicitly stated. I think it's a confusing concept about time that a reference is valid. To me lifetime of a reference is hard concept to grasp. Another annoying but not hard feature is the unwrap feature. While I loved the error handling with Result, I was confused on why it wasn't returning the right board and an invalid format for it. All the returns with Result needs to be unwrapped, it was just annoying to figure out causing chaos and honestly I don't understand why it's "wrapped" that it needs to be unwrapped with ".unwrap".