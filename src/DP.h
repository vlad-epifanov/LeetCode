
#pragma once
#include <string>
#include <vector>

#define EXPORT_SYM __declspec(dllexport)

// Used only for quick copy-paste to LeetCode - avoid in production!
using namespace std;

/***************************************
1) Divisor Game
https://leetcode.com/problems/divisor-game/

Alice and Bob take turns playing a game, with Alice starting first.

Initially, there is a number N on the chalkboard.  On each player's turn, that player makes a move consisting of:

Choosing any x with 0 < x < N and N % x == 0.
Replacing the number N on the chalkboard with N - x.
Also, if a player cannot make a move, they lose the game.

Return True if and only if Alice wins the game, assuming both players play optimally.

Input: 3
Output: false
Explanation: Alice chooses 1, Bob chooses 1, and Alice has no more moves.
***************************************/

class DivGame {
public:
    bool divisorGame(int N);
};