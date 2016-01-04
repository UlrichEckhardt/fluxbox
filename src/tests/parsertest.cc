// parsertest.cc a test app for Parser
// Copyright (c) 2006 Henrik Kinnunen (fluxgen at fluxbox dot org)

#include "../FbMenuParser.hh"

#include <iostream>
#include <stdlib.h>

using namespace std;
using namespace FbTk;

int main(int argc, char **argv) {
    if (argc < 2) {
        cerr<<"you must supply an argument!"<<endl;
        return EXIT_FAILURE;
    }
    cerr<<"Loading: "<<argv[1]<<endl;
    FbMenuParser p(argv[1]);
    if (!p.isLoaded()) {
        cerr<<"Couldn't load file: "<<argv[1]<<endl;
        return EXIT_FAILURE;
    }

    Parser::Item item, item2, item3;
    std::string last_line;
    std::string type, name, argument;
    while (!p.eof()) {
        p>>item>>item2>>item3;
        cout<<item.second<<","<<item2.second<<", "<<item3.second<<endl;
    }
}
