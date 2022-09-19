#include "ril.cpp"

int main() {
    std::ofstream compile;
    std::vector<std::string> t = ril::split("out \"string out put\"", "\n");

    compile.open("compile.cpp");
    compile << "#include \"ril.cpp\"\n\nint main() {\n";
    for (int i = 0; i < int(t.size()); i++) {
        try {
            std::string str = "";

            if (ril::startwith(t.at(i), "out")) {
                std::vector<std::string> args = ril::getArgs(t.at(i));

                if (int(args.size()) > 2) 
                    str = "std::cout << " + args.at(0) + " << std::endl";
                else
                    str = "std::cout << " + args.at(0) + " << " + args.at(1);
            }

            compile << "\t" + str + ";\n";
        } catch (int e) {
            compile.close();
        }
    }
    compile << "\n\treturn 0;\n}";
    compile.close();
}