#include "ast.hpp"

#include <cstdlib>

int main(int argc, char *argv[])
{
    TreePtr src=Parse(std::cin);
    
    // Constant propogation
    int changed = 0;
    ConstantFold(src, changed);
    
    PrettyPrint(std::cout, src);
    std::cerr << "Number of changes: " << changed << std::endl;
    if (changed>0){
      return 0;
    }
    return 1;
}
