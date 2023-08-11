// Copyright [2023] Hunter Hasenfus

#ifndef RANDWRITER_H_
#define RANDWRITER_H_

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <map>
#include <random>
#include <chrono>


class RandWriter{
 public:
    RandWriter(std::string text, int k);
    int orderK() const;
    int freq(std::string kgram) const;
    int freq(std::string kgram, int c) const;
    char kRand(std::string kgram);
    std::string generate(std::string kgram, int L);
    friend std::ostream& operator<<(std::ostream &out, RandWriter &rw);
 private:
    std::string BaseText;
    std::map<std::string, int> kgrams;
    std::map<std::string, std::vector<float>> kgramCharProb;
    std::map<std::string, std::discrete_distribution<int>> kgramCharDist;
    int order;
    std::vector<char> alphabet;
    std::default_random_engine generator;
};

#endif  // RANDWRITER_H_
