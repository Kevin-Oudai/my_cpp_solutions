#ifndef WEIGHTEDEDGE_H
#define WEIGHTEDEDGE_H

#include "Edge.h"

class WeightedEdge : public Edge
{
public:
    double weight;

    WeightedEdge(int u, int v, double weight) : Edge(u, v)
    {
        this->weight = weight;
    }

    bool operator<(const WeightedEdge &edge) const
    {
        return (*this).weight < edge.weight;
    }

    bool operator<=(const WeightedEdge &edge) const
    {
        return (*this).weight <= edge.weight;
    }

    bool operator>(const WeightedEdge &edge) const
    {
        return (*this).weight > edge.weight;
    }

    bool operator>=(const WeightedEdge &edge) const
    {
        return (*this).weight >= edge.weight;
    }

    bool operator==(const WeightedEdge &edge) const
    {
        return (*this).weight == edge.weight;
    }

    bool operator!=(const WeightedEdge &edge) const
    {
        return (*this).weight != edge.weight;
    }
};

#endif