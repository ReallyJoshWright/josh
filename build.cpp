#include <vector>

#include "builder.h"

int main(int argc, char *argv[]) {
    Builder builder(argc, argv);

    std::vector<Debug> debug;
    debug.push_back(Debug::G);
    debug.push_back(Debug::Wall);
    debug.push_back(Debug::Wextra);
    debug.push_back(Debug::Pedantic);

    builder.setOptions(Options{
        .name = "app",
        .root_source_file = "./src/main.cpp",
        .version = Version::V23,
        .debug = debug,
        .optimize = Optimize::Debug,
        .target = Targets::Linux,
    });

    builder.addIncludeDir("-I./src/include");
    builder.addSourceFile("./src/src/generator.cpp");
    builder.addSourceFile("./src/src/lexer.cpp");
    builder.addSourceFile("./src/src/parser.cpp");
    builder.addSourceFile("./src/src/symbol_table.cpp");

    builder.build();
}
