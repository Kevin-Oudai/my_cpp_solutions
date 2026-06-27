#include "../WeightedNineTailModel.h"
#include <iostream>

int main()
{
    WeightedNineTailModel model1(1);
    WeightedNineTailModel model2(3);
    bool sameDepths = true;

    for (int node = 0; node < 512; node++)
    {
        if (model1.getDepth(node) != model2.getDepth(node))
        {
            sameDepths = false;
            break;
        }
    }

    std::cout << "The two weighted models have the same path lengths: " << (sameDepths ? "true" : "false") << std::endl;

    return 0;
}
