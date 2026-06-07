I successfully completed this project in December 2023. 

Developed a dual-mode Sudoku application in C that can both solve any valid Sudoku puzzle automatically and allow users to play interactively.

🔹 Mode 1 — Auto Solver: Takes an unsolved 9×9 Sudoku grid as input and solves it using a backtracking algorithm with a smart cell-selection strategy (MRV — Minimum Remaining Values). The solver finds the empty cell with the fewest valid candidates first, improving efficiency significantly over brute-force approaches.

🔹 Mode 2 — Interactive Play: Lets the user fill in a Sudoku board cell by cell, with real-time board display after every move. Upon completion, the program validates the solution by checking all rows, columns, and 3×3 boxes for correctness and reports any mistakes.

Key Technical Highlights:
• Implemented backtracking with constraint checking (row, column, and 3×3 sub-grid validation)
• Used MRV heuristic in the nxt() function to optimize which cell to fill next
• Designed modular functions: mrk() for validity checks, solve() for recursive backtracking, rowcheck(), colcheck(), cubecheck() for post-game validation
• Handled edge-case inputs and invalid entries gracefully with loop control

Technologies: C, Standard I/O, Arrays, Recursion, Backtracking Algorithm

Here are some pictures of the project:
<img width="1913" height="1018" alt="image" src="https://github.com/user-attachments/assets/9b84a1a7-de81-408e-a19b-d218aefdc841" />

<img width="1906" height="973" alt="image" src="https://github.com/user-attachments/assets/7cfffd45-18d3-4e0a-abc0-0cc22d0cbc3a" />

<img width="1844" height="985" alt="image" src="https://github.com/user-attachments/assets/7cdce0e3-e81e-4892-b210-63527cf83297" />

<img width="1873" height="959" alt="image" src="https://github.com/user-attachments/assets/46e13943-461a-44c5-8d79-773587b180d8" />

<img width="1914" height="978" alt="image" src="https://github.com/user-attachments/assets/729bbab9-52d4-4a08-acf0-18120a253d0e" />

<img width="1906" height="976" alt="image" src="https://github.com/user-attachments/assets/60ac048c-9698-4a67-aa9b-d77d61f60448" />

This project video link: https://youtu.be/b28Yd3Ii2EU

