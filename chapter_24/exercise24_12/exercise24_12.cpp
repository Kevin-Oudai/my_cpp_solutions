#include "../TailModels.h"
#include <iostream>

int main()
{
    TailModel model(4, false);

    if (model.saveParents("Exercise24_12.dat"))
        std::cout << "Saved TailModel16 data for " << model.getNumberOfNodes() << " nodes" << std::endl;
    else
        std::cout << "Unable to save TailModel16 data" << std::endl;

    return 0;
}
