#ifndef HASHUTILITIES_H
#define HASHUTILITIES_H

#include <cstring>
#include <functional>
#include <iostream>
#include <list>
#include <set>
#include <string>
#include <utility>
#include <vector>

inline int positiveMod(int value, int size)
{
    int result = value % size;
    return result < 0 ? result + size : result;
}

template<typename V>
class OpenAddressingMap
{
public:
    OpenAddressingMap()
    {
        count = 0;
        table.resize(4);
    }

    bool put(int key, V value)
    {
        if ((count + 1.0) / table.size() > 0.5)
            rehash();

        return putWithoutRehash(key, value);
    }

    bool get(int key, V& value) const
    {
        int index = findIndex(key);

        if (index == -1)
            return false;

        value = table[index].value;
        return true;
    }

    bool remove(int key)
    {
        int index = findIndex(key);

        if (index == -1)
            return false;

        table[index].occupied = false;
        table[index].deleted = true;
        count--;
        return true;
    }

    bool containsKey(int key) const
    {
        return findIndex(key) != -1;
    }

    int getSize() const
    {
        return count;
    }

    int getTableSize() const
    {
        return static_cast<int>(table.size());
    }

    void printEntries() const
    {
        for (int i = 0; i < static_cast<int>(table.size()); i++)
        {
            if (table[i].occupied)
                std::cout << "(" << table[i].key << ", " << table[i].value << ") ";
        }
        std::cout << std::endl;
    }

protected:
    enum ProbeMode
    {
        LINEAR,
        QUADRATIC,
        DOUBLE_HASHING
    };

    OpenAddressingMap(ProbeMode mode)
    {
        this->mode = mode;
        count = 0;
        table.resize(4);
    }

private:
    class Entry
    {
    public:
        int key;
        V value;
        bool occupied;
        bool deleted;

        Entry()
        {
            key = 0;
            occupied = false;
            deleted = false;
        }
    };

    ProbeMode mode;
    std::vector<Entry> table;
    int count;

    int probeIndex(int key, int attempt) const
    {
        int h = positiveMod(key, static_cast<int>(table.size()));

        if (mode == LINEAR)
            return (h + attempt) % table.size();

        if (mode == QUADRATIC)
            return (h + attempt * attempt) % table.size();

        int secondHash = 1 + positiveMod(key, static_cast<int>(table.size()) - 2);
        return (h + attempt * secondHash) % table.size();
    }

    bool putWithoutRehash(int key, V value)
    {
        int firstDeleted = -1;

        for (int attempt = 0; attempt < static_cast<int>(table.size()); attempt++)
        {
            int index = probeIndex(key, attempt);

            if (table[index].occupied && table[index].key == key)
            {
                table[index].value = value;
                return false;
            }

            if (!table[index].occupied)
            {
                if (table[index].deleted)
                {
                    if (firstDeleted == -1)
                        firstDeleted = index;
                }
                else
                {
                    int target = firstDeleted == -1 ? index : firstDeleted;
                    table[target].key = key;
                    table[target].value = value;
                    table[target].occupied = true;
                    table[target].deleted = false;
                    count++;
                    return true;
                }
            }
        }

        if (firstDeleted != -1)
        {
            table[firstDeleted].key = key;
            table[firstDeleted].value = value;
            table[firstDeleted].occupied = true;
            table[firstDeleted].deleted = false;
            count++;
            return true;
        }

        rehash();
        return putWithoutRehash(key, value);
    }

    int findIndex(int key) const
    {
        for (int attempt = 0; attempt < static_cast<int>(table.size()); attempt++)
        {
            int index = probeIndex(key, attempt);

            if (table[index].occupied && table[index].key == key)
                return index;

            if (!table[index].occupied && !table[index].deleted)
                return -1;
        }

        return -1;
    }

    void rehash()
    {
        std::vector<Entry> oldTable = table;
        table.clear();
        table.resize(oldTable.size() * 2);
        count = 0;

        for (int i = 0; i < static_cast<int>(oldTable.size()); i++)
        {
            if (oldTable[i].occupied)
                putWithoutRehash(oldTable[i].key, oldTable[i].value);
        }
    }
};

template<typename V>
class LinearProbingMap : public OpenAddressingMap<V>
{
public:
    LinearProbingMap() : OpenAddressingMap<V>(OpenAddressingMap<V>::LINEAR)
    {
    }
};

template<typename V>
class QuadraticProbingMap : public OpenAddressingMap<V>
{
public:
    QuadraticProbingMap() : OpenAddressingMap<V>(OpenAddressingMap<V>::QUADRATIC)
    {
    }
};

template<typename V>
class DoubleHashingMap : public OpenAddressingMap<V>
{
public:
    DoubleHashingMap() : OpenAddressingMap<V>(OpenAddressingMap<V>::DOUBLE_HASHING)
    {
    }
};

template<typename K, typename V>
class MyHashMap
{
public:
    class Iterator
    {
    public:
        Iterator(const std::vector<std::pair<K, V> >& entries, int index)
        {
            this->entries = entries;
            this->index = index;
        }

        Iterator operator++()
        {
            index++;
            return *this;
        }

        Iterator operator++(int)
        {
            Iterator temp(*this);
            index++;
            return temp;
        }

        std::pair<K, V> operator*() const
        {
            return entries[index];
        }

        bool operator!=(const Iterator& other) const
        {
            return index != other.index;
        }

    private:
        std::vector<std::pair<K, V> > entries;
        int index;
    };

    MyHashMap()
    {
        count = 0;
        table.resize(16);
    }

    void put(K key, V value)
    {
        int index = hash(key);

        for (typename std::list<std::pair<K, V> >::iterator iterator = table[index].begin(); iterator != table[index].end(); iterator++)
        {
            if (iterator->first == key)
            {
                iterator->second = value;
                return;
            }
        }

        table[index].push_back(std::make_pair(key, value));
        count++;
    }

    bool get(K key, V& value) const
    {
        int index = hash(key);

        for (typename std::list<std::pair<K, V> >::const_iterator iterator = table[index].begin(); iterator != table[index].end(); iterator++)
        {
            if (iterator->first == key)
            {
                value = iterator->second;
                return true;
            }
        }

        return false;
    }

    bool containsKey(K key) const
    {
        V value;
        return get(key, value);
    }

    bool remove(K key)
    {
        int index = hash(key);

        for (typename std::list<std::pair<K, V> >::iterator iterator = table[index].begin(); iterator != table[index].end(); iterator++)
        {
            if (iterator->first == key)
            {
                table[index].erase(iterator);
                count--;
                return true;
            }
        }

        return false;
    }

    std::set<K> getKeys() const
    {
        std::set<K> keys;
        std::vector<std::pair<K, V> > entries = getEntries();

        for (int i = 0; i < static_cast<int>(entries.size()); i++)
            keys.insert(entries[i].first);

        return keys;
    }

    std::vector<V> getValues() const
    {
        std::vector<V> values;
        std::vector<std::pair<K, V> > entries = getEntries();

        for (int i = 0; i < static_cast<int>(entries.size()); i++)
            values.push_back(entries[i].second);

        return values;
    }

    Iterator begin() const
    {
        return Iterator(getEntries(), 0);
    }

    Iterator end() const
    {
        std::vector<std::pair<K, V> > entries = getEntries();
        return Iterator(entries, static_cast<int>(entries.size()));
    }

    int getSize() const
    {
        return count;
    }

private:
    std::vector<std::list<std::pair<K, V> > > table;
    int count;

    int hash(K key) const
    {
        return static_cast<int>(std::hash<K>()(key) % table.size());
    }

    std::vector<std::pair<K, V> > getEntries() const
    {
        std::vector<std::pair<K, V> > entries;

        for (int i = 0; i < static_cast<int>(table.size()); i++)
        {
            for (typename std::list<std::pair<K, V> >::const_iterator iterator = table[i].begin(); iterator != table[i].end(); iterator++)
                entries.push_back(*iterator);
        }

        return entries;
    }
};

template<typename K, typename V>
class DuplicateKeyMap
{
public:
    void put(K key, V value)
    {
        entries.push_back(std::make_pair(key, value));
    }

    std::set<V> getAll(K key) const
    {
        std::set<V> values;

        for (int i = 0; i < static_cast<int>(entries.size()); i++)
        {
            if (entries[i].first == key)
                values.insert(entries[i].second);
        }

        return values;
    }

private:
    std::vector<std::pair<K, V> > entries;
};

template<typename K, typename V>
class MyMultiMap
{
public:
    void put(K key, V value)
    {
        entries.push_back(std::make_pair(key, value));
    }

    std::vector<V> getAll(K key) const
    {
        std::vector<V> values;

        for (int i = 0; i < static_cast<int>(entries.size()); i++)
        {
            if (entries[i].first == key)
                values.push_back(entries[i].second);
        }

        return values;
    }

    int getSize() const
    {
        return static_cast<int>(entries.size());
    }

private:
    std::vector<std::pair<K, V> > entries;
};

template<typename T>
class MySet
{
public:
    class Iterator
    {
    public:
        Iterator(const std::vector<T>& values, int index)
        {
            this->values = values;
            this->index = index;
        }

        Iterator operator++()
        {
            index++;
            return *this;
        }

        Iterator operator++(int)
        {
            Iterator temp(*this);
            index++;
            return temp;
        }

        T operator*() const
        {
            return values[index];
        }

        bool operator!=(const Iterator& other) const
        {
            return index != other.index;
        }

    private:
        std::vector<T> values;
        int index;
    };

    void add(T value)
    {
        map.put(value, value);
    }

    bool contains(T value) const
    {
        return map.containsKey(value);
    }

    bool remove(T value)
    {
        return map.remove(value);
    }

    int getSize() const
    {
        return map.getSize();
    }

    Iterator begin() const
    {
        return Iterator(getValues(), 0);
    }

    Iterator end() const
    {
        std::vector<T> values = getValues();
        return Iterator(values, static_cast<int>(values.size()));
    }

    std::vector<T> getValues() const
    {
        std::set<T> keys = map.getKeys();
        std::vector<T> values;

        for (typename std::set<T>::iterator iterator = keys.begin(); iterator != keys.end(); iterator++)
            values.push_back(*iterator);

        return values;
    }

private:
    MyHashMap<T, T> map;
};

template<typename T>
class MyMultiSet
{
public:
    void add(T value)
    {
        values.push_back(value);
    }

    int count(T value) const
    {
        int result = 0;

        for (int i = 0; i < static_cast<int>(values.size()); i++)
        {
            if (values[i] == value)
                result++;
        }

        return result;
    }

    int getSize() const
    {
        return static_cast<int>(values.size());
    }

private:
    std::vector<T> values;
};

inline int floatToIntBits(float value)
{
    int result;
    std::memcpy(&result, &value, sizeof(value));
    return result;
}

inline long long doubleToLongLongBits(double value)
{
    long long result;
    std::memcpy(&result, &value, sizeof(value));
    return result;
}

inline int hashCodeForString(std::string& s)
{
    int hash = 0;

    for (int i = 0; i < static_cast<int>(s.length()); i++)
        hash = 31 * hash + s[i];

    return hash;
}

#endif
