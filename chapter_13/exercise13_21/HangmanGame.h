#ifndef HANGMANGAME_H
#define HANGMANGAME_H

#include <string>
#include <vector>

class HangmanGame
{
public:
    HangmanGame(const char *filename);
    int run() const;

private:
    const char *filename;

    bool readWords(std::vector<std::string> &words) const;
    std::string getRandomWord(const std::vector<std::string> &words) const;
    void playOneWord(const std::string &word) const;
};

#endif
