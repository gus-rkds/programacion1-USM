#include <iostream>
#include <string>
#include <ctime>
#include <conio.h>

using namespace std;

const int TIME_LIMIT = 5;

main() {

    // initialize the time variables
    srand(time(nullptr));
    time_t start_time = time(nullptr);
    int remaining_time = TIME_LIMIT * 60;

    // declare deactivation code

    string deactivation_code = "af";  // The deactivation code is now a string

    // Display the welcome message

    cout << "Una bomba ha sido activada ha sido activada" << endl;
    cout << "Debes adivinar el codigo de dos letras para desactivarlo" << endl;

    // we loop until the time runs out or the user deactivates the bomb
    while (remaining_time > 0) {
    // Simulate the bomb countdown
    int minutes = remaining_time / 60;
    int seconds = remaining_time % 60;
    cout << "Tiempo restante: " << minutes << ":" << seconds << "\r";
    cout.flush(); // Flush the output buffer
    Sleep(1000); // Sleep for 1 second

    // Check for user input
    if (_kbhit()) { // Check if a key has been pressed
      cout << "\r                            \r"; // Clear the previous output 
      char c = _getch();
      string input_code = "";
      while (c != '\r') {  // Wait for the user to press Enter
        input_code += c;
        cout << "*";
        c = _getch();
      }
      cout << endl;
      // Check if the user input matches the deactivation code
      if (input_code == deactivation_code) { // Deactivation code is compared with string comparison
        cout << "Congratulations! You have deactivated the bomb!" << endl;
        return 0;
      } else {
        cout << "Incorrect code. 1 minute has been deducted from the timer." << endl;
        remaining_time -= 60; // Deduct 1 minute from the remaining time
      }
    }

    // Update the remaining time
    time_t current_time = time(nullptr);
    remaining_time = TIME_LIMIT * 60 - difftime(current_time, start_time);
  }

  // The timer has reached 0, the bomb explodes
  cout << "BOOM! The bomb has exploded!" << endl;

}
