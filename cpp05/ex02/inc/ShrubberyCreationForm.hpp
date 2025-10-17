#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include <cstdlib>
#include <ctime>
#include "AForm.hpp"

#define MAX 5
#define TREE "  ,d                                      \n  88                                      \nMM88MMM 8b,dPPYba,  ,adPPYba,  ,adPPYba,  \n  88    88P'   \"Y8 a8P_____88 a8P_____88  \n  88    88         8PP\"\"\"\"\"\"\" 8PP\"\"\"\"\"\"\"  \n  88,   88         \"8b,   ,aa \"8b,   ,aa  \n  \"Y888 88          `\"Ybbd8\"'  `\"Ybbd8\"'\n"
#define THREE "               ,@@@@@@@,\n       ,,,.   ,@@@@@@/@@,  .oo8888o.\n    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88\'\n   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888\'\n   %&&%/ %&%%&&@@\\ V /@@\' `88\\8 `/88\'\n   `&%\\ ` /%&\'    |.|        \\ \'|8\'\n       |o|        | |         | |\n       |.|        | |         | |\njgs \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_"
#define AUTUM "                                                 .\n                                              .         ;  \n                 .              .              ;%     ;;   \n                   ,           ,                :;%  %;   \n                    :         ;                   :;%;'     .,   \n           ,.        %;     %;            ;        %;'    ,;\n             ;       ;%;  \\%%;        ,     %;    ;%;    ,%'\n              %;       \\%;%;      ,  ;       %;  ;%;   ,%;' \n               ;%;      %;        ;%;        % ;%;  ,%;'\n                `%;.     ;%;     %;'         `;%%;.%;'\n                 `:;%.    ;%%. %@;        %; ;@%;%'\n                    `:%;.  :;bd%;          %;@%;'\n                      `@%:.  :;%.         ;@@%;'   \n                        `@%.  `;@%.      ;@@%;         \n                          `@%%. `@%%    ;@@%;        \n                            ;@%. :@%%  %@@%;       \n                              %@bd%%%bd%%:;     \n                                #@%%%%%:;;\n                                %@@%%%::;\n                                %@@@%(o);  . '         \n                                %@@@o%;:(.,'         \n                            `.. %@@@o%::;         \n                               `)@@@o%::;         \n                                %@@(o)::;        \n                               .%@@@@%::;         \n                               ;%@@@@%::;.          \n                              ;%@@@@%%:;;;. \n                          ...;%@@@@@%%:;;;;,..    Gilo97\n"
#define SQUIRREL "           \\ i.     / s       /\n            \\  \\   /         /\n            .n'   |      a  |_.-._\n           /  /   /       .-'      `-.      --._\n          /  /    |     /            \\-.__'       `.\n         |  (     |    |     _        \\   _      .-.   \n         |   `-.-'     |  .-' '-.      | ' `-.  (   )_ |\n          `-._         \\ (  |    \\     /      \\  `-'  `.\n              `--.      \\ ) \\ \\`-'    /        | .'\n                  \\    .- '-.| `-._.-' \\      /   \n                  |   /      \\     .    `._.-'    |\n                  |  / |      |     '            /\n                  | (_/       |      `-._     _.'\n                  \\ //\\      .|           `--'\n                   \"  \\   '\\ \\___/)_          \n                    |   |  ` \\_      \\`  ,        \n                    \\   \\       (\\ .o-`-o    \n                    |    \\__  _______,-'\\`      \n                    \\      ( |  |              \n                     |      \\  |               \n[nabis]                 b    \"\"  \n"
#define BONSAI "                  %%%,%%%%%%%\n                   ,'%% \\-*%%%%%%%\n             ;%%%%%*%   _%%%%\"\n              ,%%%       \\(_.*%%%%.\n              % *%%, ,%%%%*(    '\n            %^     ,*%%% )\\|,%%*%,_\n                 *%    \\/ #).-\"*%%*\n                     _.) ,/ *%,\n             _________/)#(_____________\n            b'ger\n"

class ShrubberyCreationForm : virtual public AForm
{
	private:
		std::string target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string name);
		ShrubberyCreationForm(ShrubberyCreationForm &other);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm &other);
		~ShrubberyCreationForm();
		void behaviour() const;
};

#endif
