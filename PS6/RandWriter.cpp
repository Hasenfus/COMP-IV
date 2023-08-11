// Copyright [2023] Hunter Hasenfus

#include <string>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <random>
#include <chrono>
#include "RandWriter.h"


RandWriter::RandWriter(std::string text, int k) {
    // unsigned nseed = std::chrono::system_clock::now().
    // time_since_epoch().count();
    // generator.seed(nseed);
    BaseText = text;
    BaseText.erase(std::remove(BaseText.begin(), BaseText.end(), '\n'),
     BaseText.cend());
    // std::cout << BaseText << std::endl;
    order = k;
    int x = orderK();
    for (int i = 0; i < 127; i ++) {
        if (BaseText.find(static_cast<char>(i)) != std::string::npos) {
            alphabet.push_back(static_cast<char>(i));
        }
    }
    qsort(&alphabet[0], alphabet.size(), sizeof(char), [](const void *a,
     const void *b) { return (*(char *)a - *(char *)b); });
    for (int i = 0; i < BaseText.length(); i++) {
        std::string kgram = BaseText.substr(i, order);
        if (kgram.size() < order) {
            int x = (i + order)- BaseText.length();
            kgram += BaseText.substr(0, x);

            if (kgrams.find(kgram) == kgrams.end()) {
                kgrams[kgram] = freq(kgram);
                kgramCharProb[kgram] = std::vector<float>(127, 0);
                kgramCharProb[kgram][BaseText[x]] = static_cast<float>
                (freq(kgram,
                 BaseText[x])) / kgrams[kgram];
                // std:: cout << kgramCharProb[kgram][BaseText[x]]
                //  << std::endl;
            } else { if (kgramCharProb[kgram][BaseText[x]] == 0) {
                kgramCharProb[kgram][BaseText[x]] = static_cast<float>
                (freq(kgram,
                 BaseText[x])) / kgrams[kgram];
                //  std:: cout << kgramCharProb[kgram]
                // [BaseText[x]] << std::endl;
            }}

        } else {
        int x = (i + order) == BaseText.length() ? 0 : i + order;

        if (kgrams.find(kgram) == kgrams.end()) {
            kgrams[kgram] = freq(kgram);
            kgramCharProb[kgram] = std::vector<float>(127, 0);
            kgramCharProb[kgram][BaseText[x]] = static_cast<float>
            (freq(kgram, BaseText[x]))
             / kgrams[kgram];
        } else { if (kgramCharProb[kgram][BaseText[x]] == 0) {
            kgramCharProb[kgram][BaseText[x]] = static_cast<float>(freq(kgram,
             BaseText[x])) / kgrams[kgram];
    }}}}
    // std::cout << "HERE" << std::endl;
    for (auto it : kgramCharProb) {
        std::discrete_distribution<int> dist(it.second.begin(),
         it.second.end());
        kgramCharDist[it.first] = dist;
    }
    }

int RandWriter::orderK() const {
    return order;
}
int RandWriter::freq(std::string kgram) const {
    if (kgram.length() != order) {
        throw std::invalid_argument("kgram is not the same length as order"
         + kgram);
    }
    if (kgrams.find(kgram) == kgrams.end()) {
        throw std::invalid_argument("kgram is not valid");
    }
    int n = 0;
    for (int i = 0; i < BaseText.length(); i++) {
        std::string kgram2 = BaseText.substr(i, order);
        if (kgram2.size() < order) {
            int x = (i + order)- BaseText.length();
            kgram2 += BaseText.substr(0, x);
            if (kgram2 == kgram) {
                n++;
            }
        } else {
            if (kgram2 == kgram) {
                n++;
            }}
    }
    return n;
}

int RandWriter::freq(std::string kgram, int c) const {
    if (kgram.length() != order) {
        throw std::invalid_argument("kgram is not the same length as order" +
         kgram);
    }
    int n = 0;
    for (int i = 0; i < BaseText.length(); i++) {
        std::string kgram2 = BaseText.substr(i, order);

        if (kgram2.size() < order) {
            int x = (i + order)- BaseText.length();
            kgram2 += BaseText.substr(0, x);
            // std::cout << "(1) " << i << " - ";
            // std::cout << BaseText[x] <<  ": " << x << std::endl;
            if (kgram2 == kgram && BaseText[x] == c) {
                n++;
            }

        } else {
            int x = (i + order) == BaseText.length() ? 0 : i + order;
            // std::cout << "(2) " << i << " - ";
            // std::cout << BaseText[x] <<  ": " << x << std::endl;
            if (kgram2 == kgram  && BaseText[x] == c) {
                n++;
            }}
    }

    if (n == 0) {
        throw std::invalid_argument("kgram does not exist: " + kgram
         + ", " + static_cast<char>(c));
    }

    return n;
}

char RandWriter::kRand(std::string kgram) {
    int x = kgramCharDist[kgram](generator);
    // int i = 0;
    // std::cout << kgram << ":" << std::endl;
    // for (double x: kgramCharDist[kgram].probabilities()) {
    //     if (x > 0)
    //         std::cout << char(i) << "- " << x << std::endl;
    //     i++;
    // }

    return x;
}
std::string RandWriter::generate(std::string kgram, int L) {
    if (kgram.length() != order) {
        throw std::invalid_argument("kgram is not the same length as order");
    }
    if (kgrams.find(kgram) == kgrams.end()) {
        throw std::invalid_argument("kgram does not exist: " + kgram);
    }
    std::string kgram2 = kgram;
    std::string  output = kgram2;
    for (int i = 0; i < L - kgram.length(); i++) {
        output += static_cast<char>(kRand(kgram2));
        // std::cout << kRand(kgram2) << std::endl;
        // std::cout << "kgram2: " << kgram2 << std::endl;
        kgram2 = output.substr(output.length() - order, order);
    }
    return output;
}
std::ostream& operator<<(std::ostream &out, RandWriter &rw) {
    std::cout << "Order: " << rw.orderK() << std::endl;
    std::cout << "Alphabet: " << std::endl;
    for (char c : rw.alphabet) {
        std::cout << c << ", ";
    }
    std::cout << std::endl << "kgrams frequencies: " << std::endl;
    for (auto x : rw.kgrams) {
        std::cout << x.first << ": " << x.second << std::endl;
    }
    std::cout << "kgrams + 1 frequencies: " <<  std::endl;

    return out;
}
