# Sudoku Game using **C++**

Created alongside with **Lucas Losekann** in Algorithms and Programming subject <br />
UNIVALI - Universidade do Vale do Itajaí <br />
June 26th 2023 <br />

## Observations when running the code
1. If you're running on older C++ versions, consider substituting `#include <ctime>` and `#include <cstdlib>` for `#include <time.h>` `#include <stdlib.h>`
2. Running on a console might be a problem for some people. To fix this problem, download **g++ and gcc** and should work properly (I recommend downloading from [MSYS2](https://www.msys2.org/))
   
## How to play the game:
The objective is to complete the grid so that every row, column, and region contains all the numbers from 1 to 9, without any repetition. 
### Here're some steps you should follow if you consider playing the game:
1. **Understand the grid:** A standard Sudoku grid consists of a 9x9 square divided into nine 3x3 boxes. Each box is further divided into nine smaller squares, making a total of 81 squares in the grid.
2. **Empty squares:** At the beginning of the game, some squares will already contain numbers, while others will be empty. Your task is to fill in the empty squares.
3. **Number placement:** Start by analyzing the grid and identifying any numbers that can be immediately placed. Look for obvious placements based on the given numbers and any related constraints. For example, if a row already contains the numbers 1, 3, 4, 5, 6, 7, and 9, the missing number is 2.
4. **Elimination:** Examine each row, column, and box to identify numbers that are missing. Eliminate possibilities by considering the numbers already present in the corresponding row, column, or box. For instance, if a box already contains the numbers 1, 2, 3, 5, 7, and 9, the missing numbers are 4 and 6.
5. **Logic and deduction:** Use logical reasoning to determine the possible placements for each number. Look for opportunities to narrow down the choices by considering the constraints of the game. For example, if a number can only be placed in one row or column within a box, you can eliminate that number as a possibility in other rows or columns in the same box.
6. **Iterate and repeat:** Continue applying the logic and deduction techniques, combined with trial and error, until you complete the entire grid. Remember to double-check your placements to ensure accuracy.
7. **Trial and error:** When you have exhausted all the logical deductions, you may need to resort to trial and error. Select an empty square and assign a number that seems likely. Continue solving the puzzle based on that choice. If you encounter a contradiction, backtrack and try a different number until you find the correct one.
8. **Practice and patience:** Sudoku is a skill that improves with practice. Start with easier puzzles and gradually work your way up to more challenging ones. Developing your pattern recognition, logical thinking, and deduction skills will help you become a better Sudoku player over time.

## Final considerations
For any further problems in the code do not hesite to contact me in my email **aragaoian@edu.univali.br**, I'll be very pleased.
