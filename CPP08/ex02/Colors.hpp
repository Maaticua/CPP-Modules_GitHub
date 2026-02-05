#ifndef COLORS_HPP
#define COLORS_HPP

// Usage : std::cout << RED << "bonjour" << RESET << std::endl;

namespace termcolor {

    // Reset
    static const char* RESET = "\033[0m";

    // Couleurs de texte
    static const char* BLACK   = "\033[30m";
    static const char* RED     = "\033[31m";
    static const char* GREEN   = "\033[32m";
    static const char* YELLOW  = "\033[33m";
    static const char* BLUE    = "\033[34m";
    static const char* MAGENTA = "\033[35m";
    static const char* CYAN    = "\033[36m";
    static const char* WHITE   = "\033[37m";

    // Couleurs claires (bright)
    static const char* BBLACK   = "\033[90m";
    static const char* BRED     = "\033[91m";
    static const char* BGREEN   = "\033[92m";
    static const char* BYELLOW  = "\033[93m";
    static const char* BBLUE    = "\033[94m";
    static const char* BMAGENTA = "\033[95m";
    static const char* BCYAN    = "\033[96m";
    static const char* BWHITE   = "\033[97m";

    // Styles
    static const char* BOLD      = "\033[1m";
    static const char* DIM       = "\033[2m";
    static const char* UNDERLINE = "\033[4m";
    static const char* BLINK     = "\033[5m";
    static const char* REVERSE   = "\033[7m";

}

// Raccourcis globaux
#define RESET     termcolor::RESET
#define RED       termcolor::RED
#define GREEN     termcolor::GREEN
#define YELLOW    termcolor::YELLOW
#define BLUE      termcolor::BLUE
#define MAGENTA   termcolor::MAGENTA
#define CYAN      termcolor::CYAN
#define WHITE     termcolor::WHITE
#define BRED      termcolor::BRED
#define BGREEN    termcolor::BGREEN
#define BYELLOW   termcolor::BYELLOW
#define BBLUE     termcolor::BBLUE
#define BOLD      termcolor::BOLD
#define UNDERLINE termcolor::UNDERLINE

#endif
