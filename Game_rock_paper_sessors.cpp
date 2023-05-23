#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0)); // Seed the random number generator with the current time

    // Display the menu
    std::cout << "Rock-Paper-Scissors Game\n";

    int playerScore = 0;
    int computerScore = 0;
    int rounds;

    std::cout << "Enter the number of rounds to play (1-10), or enter 0 to let the computer decide: ";
    std::cin >> rounds;

    // Validate the number of rounds
    if (rounds < 0 || rounds > 10) {
        std::cout << "Invalid number of rounds. Please enter a number from 0 to 10.\n";
        return 0;
    }

    if (rounds == 0) {
        // Computer decides the number of rounds
        rounds = rand() % 7 + 1;
        std::cout << "The computer has decided to play " << rounds << " rounds.\n";
    }

    int round;
    for (round = 1; round <= rounds; ++round) {
        std::cout << "Round " << round << "\n";
        std::cout << "1. Rock\n";
        std::cout << "2. Paper\n";
        std::cout << "3. Scissors\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice (1-4): ";

        int playerChoice;
        std::cin >> playerChoice;

        // Validate the player's choice
        if (playerChoice < 1 || playerChoice > 4) {
            std::cout << "Invalid choice. Please enter a number from 1 to 4.\n";
            return 0;
        }

        if (playerChoice == 4) {
            std::cout << "Exiting the game. Result of incomplete game:\n";
            break;
        }

        // Generate computer's choice
        int computerChoice = rand() % 3 + 1;

        // Determine the winner
        std::cout << "Player chooses ";

        switch (playerChoice) {
            case 1:
                std::cout << "Rock.\n";
                break;
            case 2:
                std::cout << "Paper.\n";
                break;
            case 3:
                std::cout << "Scissors.\n";
                break;
        }

        std::cout << "Computer chooses ";

        switch (computerChoice) {
            case 1:
                std::cout << "Rock.\n";
                break;
            case 2:
                std::cout << "Paper.\n";
                break;
            case 3:
                std::cout << "Scissors.\n";
                break;
        }

        if (playerChoice == computerChoice) {
            std::cout << "It's a tie!\n";
        } else if ((playerChoice == 1 && computerChoice == 3) ||
                   (playerChoice == 2 && computerChoice == 1) ||
                   (playerChoice == 3 && computerChoice == 2)) {
            std::cout << "Player wins this round!\n";
            ++playerScore;
        } else {
            std::cout << "Computer wins this round!\n";
            ++computerScore;
        }

        std::cout << "-------------------------\n";
    }

    // Display the final result
    if (round <= rounds) {
        std::cout << "The game is incomplete.\n";
        std::cout << "Player Score: " << playerScore << "\n";
        std::cout << "Computer Score: " << computerScore << "\n";
    } else {
        std::cout << "Final result:\n";
        std::cout << "Player Score: " << playerScore << "\n";
        std::cout << "Computer Score: " << computerScore << "\n";

        if (playerScore > computerScore) {
            std::cout << "Player wins the game!\n";
        } else if (playerScore < computerScore) {
            std::cout << "Computer wins the game!\n";
        } else {
            std::cout << "It's a tie!\n";
        }
    }

    return 0;
}
