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
    std::cout << "Enter the name of the file WITH .txt extenstion";
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
void mult_func(){ // multiply operation
    // SKIP THIS THING TOOK FOREVER IN (old_assignments) DO IT LATER

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

void swap_rows_func(){ // swaps rows
}

void swap_col_func(){ // swaps columns

}

// Jordan
void underminer(){ // updates a matrix value
    std::vector<std::vector<int>> mat1 = readMatrix(); // same thing as add_func
    int user;
    int row_loc;
    int col_loc;
    int N = mat1.size(); // initializes them
    std::cout << "DISCLAIMER NOTE: the first row and first column are value 1 (one). Do not enter 0" << std::endl; // disclaimer
    std::cout << "Enter the ROW of the value you are overwriting (1 to N)";
    std::cin >> row_loc; // assigns the value
    std::cout << std::endl; // i want extra space
    if ( row_loc == 0 ){ // handles the error if you dont do it right
        row_loc++;
        std::cout << "Detected input as 0. Adjusted that to 1 as per disclaimer note" << std::endl;
    }
    if ( row_loc <= 0 ){
        std::cerr << "Invalid input"; // handles an error
    }
    if ( row_loc > N ){
        std::cerr << "Invalid input"; // handles an error
    }
    std::cout << "Enter the COLUMN of the value you are overwriting (1 to N)";
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
        if (choice == 1) { add_func() ;} //
        if (choice == 2) { mult_func() ;}
        if (choice == 3) { sum_diag_func() ;}
        if (choice == 4) { swap_rows_func() ;}
        if (choice == 5) { swap_col_func() ;}
        if (choice == 6) { underminer() ;} // these are self explainatory, just runs the function based on input
    }
    return 0; // wont ever run, doesnt seem necessary
}