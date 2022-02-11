#include <iostream>
#include <string>

bool isStop(std::string gene)
{
    std::string stopSequences[3] = {"TAG", "TAA", "TGA"};
    for (int i = 0; i < 3; i++)
    {
        if (stopSequences[i].compare(gene) == 0)
        {
            return true;
        }
    }
    return false;
}

std::string getGenes(std::string seq, std::string &genes)
{
    std::string gene;
    for (int i = 0; i < seq.length(); i += 3)
    {
        gene = seq.substr(i, 3);
        if (isStop(gene))
        {
            genes.append("\n");
            return seq.substr(i + 3, seq.length() - i + 3);
        }
        else
        {
            genes.append(gene);
        }
    }
    return "";
}

int main()
{
    std::string seq, genes = "";
    std::cout << "Enter a genome string: ";
    std::cin >> seq;
    int startIndex = 0;
    while (seq.length() > 3)
    {
        startIndex = seq.find("ATG");
        if (startIndex == std::string::npos)
        {
            break;
        }
        seq = seq.substr(startIndex + 3, seq.length() - startIndex + 3);
        seq = getGenes(seq, genes);
    }
    if (genes.length() == 0)
    {
        std::cout << "no gene is found" << std::endl;
    }
    else
    {
        std::cout << "Genes: \n"
                  << genes << std::endl;
    }

    return 0;
}