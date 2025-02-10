#include <iostream>
#include <args.hxx>

int main(int argc, char* argv[])
{
    args::ArgumentParser parser("This is a test program.", "This goes after the options.");
    args::HelpFlag help(parser, "help", "Display this help menu", { 'h', "help" });
    args::ValueFlag<std::string> name(parser, "name", "Your name", { 'n', "name" });

    try
    {
        parser.ParseCLI(argc, argv);
    }
    catch (args::Help&)
    {
        std::cout << parser;
        return 0;
    }
    catch (args::ParseError& e)
    {
        std::cerr << e.what() << std::endl;
        std::cerr << parser;
        return 1;
    }
    catch (args::ValidationError& e)
    {
        std::cerr << e.what() << std::endl;
        std::cerr << parser;
        return 1;
    }

    if (name)
    {
        std::cout << "Hello, " << args::get(name) << "!" << std::endl;
    }
    else
    {
        std::cout << "Hello, World!" << std::endl;
    }

    return 0;
}