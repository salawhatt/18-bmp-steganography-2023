#include "file_proc.h"
class Process
{
public:
    unsigned long long int lcg(unsigned long long int x0)
    {
        unsigned long long x = ((x0 * MULTIPLIER_FOR_LСG) + INCREMENT_FOR_LCG) % MODULE_FOR_LCG;
        return x;
    }
    void makeMask(const Key& cur_key, unsigned char& img, unsigned char& text)
    {
        text = 0b11111111;
        img = 0b11111111;

        text <<= (BIT_IN_CHARACTER - cur_key.packing_degree);
        img >>= cur_key.packing_degree;
        img <<= cur_key.packing_degree;
    }
    int makeSeed(const Key& cur_key) 
    {
        int seed = (cur_key.key[0] + cur_key.key[1] + (9 * cur_key.key[2]) + (11 * cur_key.key[3]) + (4 * cur_key.key[4]) + (5 * cur_key.key[5]) + cur_key.key[6]);
        return seed;
    }
};

class MainProcess
{
public:
    virtual void coder(File& mutableFile, File& readableFile, File& encryptionFile, Key& encryptionKey) = 0;
};

class Encoder : public MainProcess {
private: 
    Process process;
public:
    void coder(File& mutableFile, File& readableFile, File& encryptionFile, Key& encryptionKey) override;
};

class Decrypt : public MainProcess {
private:
    Process process;
public:
    void coder(File& mutableFile, File& readableFile, File& encryptionFile, Key& encryptionKey) override;
};

// Примеры использованя полиморфизма в С++