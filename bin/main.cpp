#include <functional>
#include <lib/ArgParser.h>

#include <iostream>
#include <numeric>


struct Options {
    bool sum = false;
    bool mult = false;
};



int main(int argc, char** argv) {
    std::vector<bool> flags3_vector;
    std::vector<std::string> string3_vector;
    std::vector<int> int3_vector;

    ArgumentParser::ArgParser parser("My parser");

    parser.AddFlag('f', "flag1", "f1 description").Default(true);
    parser.AddFlag('g').MultiValue(3);
    parser.AddFlag("flag3").MultiValue().StoreValues(flags3_vector);
    parser.AddFlag("flag4", "f4 description").Positional();

    parser.AddStringArgument('h', "str1", "str1 description").Default("default string");
    parser.AddStringArgument('t').MultiValue(3);
    parser.AddStringArgument("str3").MultiValue().StoreValues(string3_vector);
    parser.AddStringArgument("str4", "str4 description").Positional();

    parser.AddIntArgument('q', "int1", "f1 description").Default(69);
    parser.AddIntArgument('l').MultiValue(3);
    parser.AddIntArgument("int3").MultiValue().StoreValues(int3_vector);
    parser.AddIntArgument("int4", "int4 description").Positional();

    std::cout << parser.Parse(std::vector<std::string> {
        "app",
        "-f",
        "-gg",
        "--flag3",
        "--flag3",
        "--flag3",
        "--flag3",
        "true",
        "true",
    });





    return 0;
//    bool aram = true;
//    int kek = 10;
//    std::vector<int> keks;
//    std::vector<bool> flags;
//    std::vector<std::string> flags_string;
//
//    parser.AddFlag('s', "long_name", "and description").StoreValue(aram).Default(true);
//    int h;
//    parser.AddFlag("param2", "youuuuuu").MultiValue(2).StoreValues(flags).Positional().Default(true);
//    parser.AddFlag("param3", "shame moment").Default(true);
//    parser.AddIntArgument("param4", "Im not so smart").Default(123);
//    parser.AddIntArgument("param5", "Just a joke").MultiValue(5).StoreValues(keks).Default(6969);
//    parser.AddStringArgument('f', "param123", "Just a joke2").MultiValue(5).StoreValues(flags_string).Default("pam pam pam");
//    parser.AddStringArgument("param6", "Im genius").Default("mom");
//    parser.AddHelp('h', "help", "aboba you");







//    Options opt;
//    std::vector<int> values;
//
//    ArgumentParser::ArgParser parser("Program");
//    parser.AddIntArgument("N").MultiValue(1).Positional().StoreValues(values);
//    parser.AddFlag("sum", "add args").StoreValue(opt.sum);
//    parser.AddFlag("mult", "multiply args").StoreValue(opt.mult);
//    parser.AddHelp('h', "help", "Program accumulate arguments");
//
//    if(!parser.Parse(argc, argv)) {
//        std::cout << "Wrong argument" << std::endl;
//        std::cout << parser.HelpDescription() << std::endl;
//        return 1;
//    }
//
//    if(parser.Help()) {
//        std::cout << parser.HelpDescription() << std::endl;
//        return 0;
//    }
//
//    if(opt.sum) {
//        std::cout << "Result: " << std::accumulate(values.begin(), values.end(), 0) << std::endl;
//    } else if(opt.mult) {
//        std::cout << "Result: " << std::accumulate(values.begin(), values.end(), 1, std::multiplies<int>()) << std::endl;
//    } else {
//        std::cout << "No one options had chosen" << std::endl;
//        std::cout << parser.HelpDescription();
//        return 1;
//    }
//
//    return 0;

}
