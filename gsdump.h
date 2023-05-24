#ifndef GSDUMP_H
#define GSDUMP_H

#include <vector>

class GSDump
{
public:
    GSDump();

    void setData(std::vector<char>buf);

private:
    std::vector<char> state;
};

#endif // GSDUMP_H
