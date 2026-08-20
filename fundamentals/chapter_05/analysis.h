#pragma once //prevents errors associated with multiplie inclussion


// IMPORTANT CONCETP: The one definition rule (ODR):
// A function or object should be defined only once for a whole program!
// the linker should point to a unique function among the files!

// So, when the preprocessor acts, it copies the header into the calling files
// The thing is that when we use .h file that is linked with an input.copp 
// Then the linker is reponsible to find where is the function that is called!


namespace stock_prices // we reopen the namespace
{
  inline bool negative(double value)
  {
    return value < 0.0;
  }
}


// Inline: We use it when we haev a short function that can be inlcuded in the header
// It is like saying to the compiler:
// "Yes youa re going to se several identical copies of tihs function among the files"
// "TREAT THEM AS ONE"
