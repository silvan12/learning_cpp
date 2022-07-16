#include <iostream>
#include <random>
#include <time.h>

using namespace std;

const string options[7] = {"rock", "water", "air", "paper", "sponge", "scissors", "fire"};

enum Winner
{
    PLAYER,
    AI,
    NONE
};

enum Pick
{
    ROCK,
    WATER,
    AIR,
    PAPER,
    SPONGE,
    SCISSORS,
    FIRE
};

Pick get_pick(int index)
{
    if (index < 0)
    {
        return (Pick)(index + 7);
    }
    else if (index >= 7)
    {
        return (Pick)(index - 7);
    }
    else
    {
        return (Pick)index;
    }
}

Winner calculate_winner(Pick player_pick, Pick ai_pick)
{
    // Draw
    if (ai_pick == player_pick)
    {
        return Winner::NONE;
    }

    // Player wins
    for (int i = -3; i < 0; i++)
    {
        if (ai_pick == get_pick(player_pick + i))
        {
            return Winner::PLAYER;
        }
    }
    
    // Ai wins
    for (int i = 1; i <= 3; i++)
    {
        if (ai_pick == get_pick(player_pick + i))
        {
            return Winner::AI;
        }
    }

    // Something went wrong
    return Winner::NONE;
}

inline Pick random_ai_pick()
{
    return (Pick)(rand() % 7);
}

Pick take_input()
{
    printf("Enter rock, water, air, paper, sponge, scissors or fire:\n");

    string input;
    cin >> input;

    for (int i = 0; i < 7; i++)
    {
        if (input == options[i])
        {
            return (Pick)i;
        }
    }

    // Input does not match
    printf("Invalid input. Please try again.\n");

    return take_input();
}

int main()
{
    srand(time(NULL));

    Pick player_pick = take_input();
    Pick ai_pick = random_ai_pick();

    printf("AI picked %s\n", options[ai_pick].c_str());

    Winner winner = calculate_winner(player_pick, ai_pick);  // chicken dinner
    switch (winner)
    {
        case Winner::AI:
            printf("You lose!");
            break;
        case Winner::PLAYER:
            printf("You win!");
            break;
        case Winner::NONE:
            printf("Draw!");
            break;
    }

    char play_again;
    printf("Would you like to play again? (y/N)\n>");
    cin >> play_again;

    if (play_again == 'y') {
        return main();
    }

    return 0;
}