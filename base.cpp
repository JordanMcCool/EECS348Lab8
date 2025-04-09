// EECS 348 Assignment 5
// Matrix operator
// INPUT: User specified file and commands
// OUT: matrix operations
// Collaborators
    // self (past tense)
// Additionall collaborations
    //GPT or google.
// Jordan McCool
// 3/30/2025

// initial comments
    // have created a similar assignment previously for seperate class
        // EECS 210 LAB 8 and LAB 9
            // included copies of them in this submission
        // these were BTIWISE matrices though, but the idea is still similar
        // That lab was in python, however, so to utilize any of it the syntax would need to be translated
        // basically, will be a guide for the matrix operations
    // will be referencing it as an aid for matrix operations
// ??? what is the makefile for
// also, alot of these comments are directed toward myself to help workflow by keeping me calm/stress relief; as well as future readability
    // even if the comment wasnt useful professionally ive opted to leave them all intact


#include <iostream>
    // "declares objects and functions that enable programs to interact with input/output devices like the console"
#include <fstream>
    // Allows file input and output operations
#include <string> // google says i need this for reading string inputs
#include <vector>
    // "a dynamic array - a sequence container that can change in size during runtime - similar to C arrays"
#include <sstream>
    // Allows a method of treating strings as input or output streams
#include <algorithm>
    // includes various prebuilt algorithms

    // these are taken from assignment 5, not sure which ones I will use at this point

// notes to self
    // need these functions
    // read from file
    // add matrix
    // multiply matrix
    // sum diag
        // is this sum the diagonals as ONE output? or print the sum of each diagonal???
    // swap rows
    // swap columns
    // change values
    // get matrix
        // decided this needs to be a standalone function
        // atp probably going to chatgpt the file opener
           // been putting off this assignment specifically because i am scared of debugging a file reader for a matrix
           // could do it in python, but not here
    // also need a makefile, but cant tell why or recall what it was
        // i DO recall battling demons to get it to work on windows though so Im ----not particularly excited--- *ELATED* for that
        // honestly is five points even worth that battle? it was pain

// gpt (mostly - edited by Jordan)
// this is the matrix opener, uses vectors :(
    // honestly not sure if i like that
        // entirely because I dont understand how to access values in the vector
        // BUT i dont know how to change it because i dont think c has dynamic arrays like python did :))))))
std::vector<std::vector<int>> readMatrix(){ // since the function will need a new matrix each time, just going to do file name here
    //
    std::string user; // initializes the variable
    std::cout << "Enter the name of the file WITH .txt extenstion \n";
    
    std::getline(std::cin, user); // stores that input as user
    // above code me - utilizing google for questions
        // gets a input file 
    //
    // below is gpt
    std::ifstream file(user); // opens the file from above
    if (!file){ // runs if we cant find that file
        std::cerr << "Cannot find that file" << std::endl;
        // raises error
            // we know what that does from Assignment5 submission
        exit(EXIT_FAILURE); // ends
    }
    int N; // will be used for the array size
    file >> N; // reads the first line of the file (the size) and stores it to N

    if (N <= 0) { // handles an edge case -- from gpt debugging
        std::cerr << "Invalid matrix size in file." << std::endl;
        exit(EXIT_FAILURE); // ends
    }

    std::vector<std::vector<int>> matrix(N, std::vector<int>(N)); 
    // from gpt - "creates a N x N matrix"
        // im just gonna trust it on that, not familiar enough with c++ to be able to read that

    
    for (int i = 0; i < N; ++i){ // neat, additional comment below
        for (int j = 0; j < N; ++j) {
            file >> matrix[i][j];
        }
    }
    // this is a nested loop for reading the file
        // a lot of this lab will use nested loops
        // comment:
            // the nested loop to read the matrix was specifically why i put off starting this assignment
                // to see it be so simple is humbling

    file.close(); // closes the file
    return matrix; // does this need to return the size too?
}
// ++i
    // seems that it is functionally the same as i++ 
    // but ++i is the PRE increment operator as opposed to POST
    // according to google, this is more efficient
// neat !

void printer(const std::vector<std::vector<int>>& matrix); // seems i need to do this to deal with compiler error? gpt

// hybrid - gpt (marked) and Jordan
void add_func(){ // add operation
    std::cout << "Enter first matrix" << std::endl;
    std::vector<std::vector<int>> mat1 = readMatrix(); // gpt
    // couldnt tell what type the matrix would be, seems the type is that long thing
        // (tried int, obviously didnt work)
        // neat
    std::cout << "Enter second matrix" << std::endl;
    std::vector<std::vector<int>> mat2 = readMatrix(); // gets the second matrix

    // add the two matrices
        // stuck, not sure how to use the stream to store a third matrix
        // asked gpt, marked below
    
    int N = mat1.size(); // gets the size
    // initially tried returning the N from the readMatrix function - didnt work
        // .size can be used to get it though

    // error checking
    int M = mat2.size();
    if (N != M){
        std::cerr << "Sizes do not match";
        return; // stops the fucntion from running if they dont match
    }

    // gpt in block below
    std::vector<std::vector<int>> result(N, std::vector<int>(N, 0));
    // creates a blank matrix to use as the result

    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            result[i][j] = mat1[i][j] + mat2[i][j]; // adds the two values then writes it to the "result" matrix
        }
    }
    printer(result); // glad this ended up being useful
        // prints the resulting matrix

}


// probably going to gpt the multiply function
    // isnt actually hard, could probably do the warshall algorithm or SOMETHNG similar to it (see attached python files)
    // i honestly just dont want to type it out
    // and gpt can make it faster than I can
// gpt
    // sike its hybrid
        // gpt didnt know what it was talking about and wanted to overcomplicate it
            // which btw, if even I can tell its overcomplicated then it is DEFINITELY overcomplicated
// comments
// i feel like im insane? i KNOW ive made a matrix multiplier before but WHEN?
    // the .py ones are boolean matrices, but i KNOW ive made one that was non boolean???
    // regardless, process is still similar

void mult_func(){ // multiply operation 
    // SKIP; THIS THING TOOK FOREVER IN (old_assignments) DO IT LATER // old comment to myself, keeping it so you can see process
    std::cout << "Enter the first matrix " << std::endl;
    std::vector<std::vector<int>> mat1 = readMatrix(); // gets the first matrix
    std::cout << "Enter the second matrix " << std::endl;
    std::vector<std::vector<int>> mat2 = readMatrix(); // gets the second matrix

    int N = mat1.size();
    int M = mat2.size(); // this will be used to check that they are the same size, since these are square matrix

    if (N != M){ // error check
        std::cerr << "Matrix sizes do not match";
        return;
    }
    std::vector<std::vector<int>> result(N, std::vector<int>(N, 0)); // creates another blank matrix

    // below block is directly from gpt with a few extra comments
        // rather simple, similar to the warshall method in previous work
    //
    // Matrix multiplication logic
    for (int i = 0; i < N; ++i) {           // Iterate over rows of mat1
        for (int j = 0; j < N; ++j) {       // Iterate over columns of mat2
            for (int k = 0; k < N; ++k) {   // Iterate over row elements of mat1 and column elements of mat2
                result[i][j] += mat1[i][k] * mat2[k][j]; // each entry is the cross of the row/column
            }
        }
    } // is a cross product

    // Print the result matrix
    std::cout << "Resultant Matrix after multiplication:\n"; // i forgot you can do \n . thats embarassing
            // you might notice multiple lines of just std::cout << std::endl becauase i forgot about \n
            // COOOOOOOL
    printer(result);
    //
    return; // ends



}

// Jordan
void sum_diag_func(){ // sum diagonals function
    std::vector<std::vector<int>> mat1 = readMatrix(); // same thing as add_func
        // just initializes the matrix
    int N = mat1.size();
    int sum1 = 0;
    // I can NOT tell if we are printing the sumS (as in PLURAL) of the two diagonals, or the SUM of the two diagonals
    int sum2 = 0;
    //for (int i = 0; i < N; ++i){
    //    for (int j = 0; j < N; ++j){
    //        if (i == j){
    //            sum1 = sum1 + mat1[i][j];
    //        }
    //    } // in hindsight, i dont even think i need this second loop. could have just done mat1[i][i]
    //} // doing that instead
    for (int i = 0; i < N; ++i){ // gets first diag
        // shape is "\"
        sum1 = sum1 + mat1[i][i]; // GOOD catch :)))))))))
    }
    for (int i = 0; i < N; ++i){ // gets second  diagonal
        // shape is /
        //sum2 = sum2 + mat1[i][-(i+1)]; this doesnt work :(
            // negative indices dont work like in python
        sum2 = sum2 + mat1[i][N-(i+1)]; // actual way to get that last index
    }
    int sum3 = sum1 + sum2; // see above comment about not being sure what exactly it means by sum of diagonals
    std::cout << "Sum of diagonal 1 (backslash shape): " << sum1 << std::endl; // cant do "\" in the text string
    std::cout << "Sum of diagonal 2 (/ shape): " << sum2 << std::endl;
    std::cout << "Sum of both:" << sum3 << std::endl; // these print the results
    return;
}

// jordan
void swap_rows_func(){ // swaps rows // is basically copied from the column function
    std::vector<std::vector<int>> mat1 = readMatrix(); // gets the matrix you want to use
    int N = mat1.size();
    std::vector<std::vector<int>> result(N, std::vector<int>(N, 0)); // creates another blank matrix

    int row1; // these two lines will be used for loctions
    int row2; // called it row by mistake, dont feel like changing it // ALSO, this is just copied straight from the next function
        // i didnt want to hide that its literally the same as the swap columns function so i kept the comments the same
        // point is: this function works almost exactly like the column function ( which i wrote prior to this one )
    std::cout << "Enter column number of the FIRST row you want to swap";
    std::cin >> row1;
    if (row1 <= 0 || row1 > N){ // error check
        std::cerr << "Invalid input";
        return;
    }
    row1--; // adjusts the index value
    std::cout << std::endl;
    std::cout << "Enter column number of the SECOND row you want to swap";
    std::cin >> row2;
    
    if (row2 <= 0 || row2 > N){ // error check
        std::cerr << "Invalid input";
        return;
    }
    row2--; // adjust to index value
     // above lines get the column values and check if there would be an error
    for (int i = 0; i < N; ++i){ // basically this builds a new matrix but just reads the swapped columns
        if (i == row1){ // checks if its the row you want to swap
            for (int j = 0; j < N; ++j){ // runs on that first condition
                result[i][j] = mat1[row2][j];
            }
        }
        if (i == row2){ // runs on second input row
            for (int j = 0; j < N; ++j){
             result[i][j] = mat1[row1][j];   
            }
        }
        if (i != row1 && i != row2){ // runs on all other cases
        for (int j = 0; j < N; ++j){ // runs if not the line
                result[i][j] = mat1[i][j];
            }
        }
    }
    printer(result); // prints
    return; // ends
}

// jordan
void swap_col_func(){ // swaps columns
    // basically this creates a copy of the input, but when its doing the row/column you tell it to swap it does the swap instead

    std::vector<std::vector<int>> mat1 = readMatrix(); // gets the matrix you want to use
    int N = mat1.size();
    std::vector<std::vector<int>> result(N, std::vector<int>(N, 0)); // creates another blank matrix

    int row1; // these two lines will be used for loctions
    int row2; // called it row by mistake, dont feel like changing it
    std::cout << "Enter column number of the FIRST column you want to swap";
    std::cin >> row1;
    
    if (row1 <= 0 || row1 > N){ // error check
        std::cerr << "Invalid input";
        return;
    }
    row1--; // adjusts the index value
    std::cout << std::endl;
    std::cout << "Enter column number of the SECOND column you want to swap";
    std::cin >> row2;
    
    if (row2 <= 0 || row2 > N){ // error check
        std::cerr << "Invalid input";
        return;
    }
    row2--; // adjust the index value
     // above lines get the column values and check if there would be an error
    for (int i = 0; i < N; ++i){ // basically this builds a new matrix but just reads the swapped columns
        for (int j = 0; j < N; ++j){
            if (j == row1){
                result[i][j] = mat1[i][row2];
            }
            if (j == row2){
                result[i][j] = mat1[i][row1];
            }
            if (j != row1 && j != row2){
                result[i][j] = mat1[i][j];
            }
        }
    }
    printer(result); // prints the result
    return; // end
}

// Jordan
void underminer(){ // updates a matrix value
    std::vector<std::vector<int>> mat1 = readMatrix(); // same thing as add_func
    int user;
    int row_loc;
    int col_loc;
    int N = mat1.size(); // initializes them
    std::cout << "DISCLAIMER NOTE: the first row and first column are value 1 (one). Do not enter 0" << std::endl; // disclaimer
    std::cout << "Enter the ROW of the value you are overwriting (1 to N) ";
    std::cin >> row_loc; // assigns the value
    std::cout << std::endl; // i want extra space
    if ( row_loc == 0 ){ // handles the error if you dont do it right
        row_loc++;
        std::cout << "Detected input as 0. Adjusted that to 1 as per disclaimer note" << std::endl;
    }
    if ( row_loc <= 0 ){
        std::cerr << "Invalid input"; // handles an error
        return;
    }
    if ( row_loc > N ){
        std::cerr << "Invalid input"; // handles an error
        return;
    }
    std::cout << "Enter the COLUMN of the value you are overwriting (1 to N) ";
    std::cin >> col_loc;
    std::cout << std::endl; // formatting
    if ( col_loc == 0 ){ // handles the error if you dont do it right
        col_loc++;
        std::cout << "Detected input as 0. Adjusted that to 1 as per disclaimer note" << std::endl;
    }
    if ( col_loc <= 0 ){
        std::cerr << "Invalid input"; // handles an error
    }
    if ( col_loc > N ){
        std::cerr << "Invalid input"; // handles an error
    }
    std::cout << "Enter the value you want to write";
    std::cin >> user; // hold that input
    std::cout << std::endl;
    mat1[row_loc-1][col_loc-1] = user;
    std::cout << "The resulting matrix is: " << std::endl;
    printer(mat1);
    return;

}

// gpt
void printer(const std::vector<std::vector<int>>& matrix){ // prints a matrix, may be useful - not sure yet
    for (const auto& row : matrix){ // loops through each row of the matrix
        for (int num : row){ // for each num within the row
            std::cout << num << " "; // prints the number
        }
        std::cout << std::endl;
    }
} // explaination below

// const ensures that this function cannot modify the variable - gpt
// the std::vector... is the type (?) that stores our matrix - neat
// the & is a reference, which gpt says increases the efficiency by avoiding creating a copy (in memory?) - NEAT


int main(){
    int choice;
    while (1 == 1){ // loops
        printf("1.) Add matrices\n" // prints options
        "2.) Multiply matrices\n"
        "3.) Get sum of diagonals\n"
        "4.) Swap rows\n"
        "5.) Swap columns\n"
        "6.) Update matrix\n"
        "Enter selction(number):\n");
        scanf("%d", &choice); // locks in the choice
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // fix for issue ??? 4/9/2025
        // ^^ using gpt as a debugger, says this is odd
            // basically wrote main() a few days before the rest of this assignment and i DONT wanna rewrite it
            // hopefully that doesnt cause issues :)))))))))))))
        if (choice == 1) { add_func() ;} //
        if (choice == 2) { mult_func() ;}
        if (choice == 3) { sum_diag_func() ;}
        if (choice == 4) { swap_rows_func() ;}
        if (choice == 5) { swap_col_func() ;}
        if (choice == 6) { underminer() ;} // these are self explainatory, just runs the function based on input
    }
    return 0; // wont ever run, doesnt seem necessary
}
// starting debugging (mostly using gpt for time - i finished most of the assignment earlier this week, but put off finishing it)
    // and now am low on time to actually finish it :))))))))))
// gpt changes
    // found mistake in row/column swapper
        // i forgot to adjust the index values like how i do in underminer
        // not a logic error, just forgot to do it
        // i am always amazed to see how good gpt can be at spotting inconsistencies like that in code
    // in the same functions ^^^
        // "youre using bitwise or | and bitwise AND &"
            // needs to be || and &&
            // interesting
    // found edge case issue in readMatrix if N is negative
        // this one is interesting, because gpt wrote the original readMatrix function ( i was scarred it would take a long time to figure it out on my own so i had it write it - see comments)'
        // interesting
    // also, it saw my comment about the makefile and tried to explain it. thats kinda sweet BUT it is 10 PM and i havent eaten all day and im NOT hearing it
        // i caved, im gonna try to get a makefile done in time :)

// error testing
    // printer function needs to be moved to the top? LAME