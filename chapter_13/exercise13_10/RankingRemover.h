#ifndef RANKINGREMOVER_H
#define RANKINGREMOVER_H

#include <string>

class RankingRemover
{
public:
    int run() const;

private:
    bool removeRanking(const std::string &filename, std::string &newFilename) const;
};

#endif
