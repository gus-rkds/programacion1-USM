#include <iostream>
#include <string>
#include <ctime>
#include <conio.h>
#include <windows.h>

using namespace std;

const int TIME_LIMIT = 5;

int main() {
  srand(time(nullptr));
  time_t start_time = time(nullptr);
  int remaining_time = TIME_LIMIT * 60;

  cout << "A bomb has been activated! You have 5 minutes to deactivate it!" << endl;

  string deactivation_code = "af";

  bool input_received = false;
  bool code_correct = false;

  while (remaining_time > 0 && !code_correct) {
    // Display the remaining time
    int minutes = remaining_time / 60;
    int seconds = remaining_time % 60;
    cout << "Tiempo restante: " << minutes << ":" << seconds << "\r";
    cout.flush(); // Flush the output buffer
    Sleep(1000); // Sleep for 1 second

    // Check for user input
    if (_kbhit()) {
      cout << "\r                            \r"; // Clear the previous output 
      char c = getch();
      string input_code = "";
      while (c != '\r') {
        input_code += c;
        cout << "*";
        c = getch();
      }
      cout << endl;

      // Check if the user input matches the deactivation code
      if (input_code == deactivation_code) {
        code_correct = true;
      } else {
        remaining_time -= 60;
      }

      input_received = true;
    }

    // Update the remaining time if the user has entered any input
    if (input_received) {
      time_t current_time = time(nullptr);
      remaining_time = TIME_LIMIT * 60 - difftime(current_time, start_time);

      input_received = false;
    }
  }

  if (code_correct) {
    cout << "Congratulations! You have deactivated the bomb!" << endl;
  } else {
    cout << "BOOM! The bomb has exploded!" << endl;
  }

  return 0;
}
