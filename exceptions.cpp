#include        "Header/exceptions.h"
#include        "Header/color.h"
#include        <iostream>


void    DeadHeroException::is_dead()
{
        std::cout<< "\n\n\n";
        std::cout<< BOLD(FWHT("\t  -=[Hero is dead]=-\n\n"));
        std::cout<< BOLD(FRED("\t   G.A.M.E  O.V.E.R\n\n"));
        std::cout<< BOLD(FRED("\t\t\\(X_X)/\n\n"));
}