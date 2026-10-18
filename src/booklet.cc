#include <cstdlib>
#include <iostream>
#include <string_view>

void print_help(const char* program_name) {
    std::cout << "Usage: " << program_name << " [-p | --pages <number>] [-h | --help]\n"
              << "Example: " << program_name << " --pages 6\n";
}

int main(int argc, char* argv[]) {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    unsigned int input_pages = 0;
    bool has_pages = false;

    // Parse command line arguments
    for (int i = 1; i < argc; ++i) {
        std::string_view arg = argv[i];
        if (arg == "-h" || arg == "--help") {
            print_help(argv[0]);
            return 0;
        } else if ((arg == "-p" || arg == "--pages") && i + 1 < argc) {
            char* end = nullptr;
            unsigned long val = std::strtoul(argv[i + 1], &end, 10);
            if (*end == '\0' && val > 0) {
                input_pages = static_cast<unsigned int>(val);
                has_pages = true;
            }
            ++i; // skip the value argument
        }
    }
    
    // If pages weren't provided or invalid, show help and exit
    if (!has_pages) {
        print_help(argv[0]);
        return 1;
    }

    // Always take the minimum multiple of 4 greater than or equal to the input
    unsigned int n = (input_pages + 3) / 4 * 4;

    if (n != input_pages) {
        std::cout << "Note: " << input_pages << " is not a multiple of 4. "
                  << "Adjusted to " << n << " pages.\n\n";
    }

    std::cout << "Booklet Imposition Layout:\n";
    unsigned int sheets = n / 4;
    
    for (unsigned int i = 0; i < sheets; ++i) {
        unsigned int left_front  = n - 2 * i;
        unsigned int right_front = 1 + 2 * i;
        unsigned int left_back   = 2 + 2 * i;
        unsigned int right_back  = n - 1 - 2 * i;

        std::cout << left_front << " - " << right_front 
                  << " / " 
                  << left_back << " - " << right_back << "\n";
    }

    return 0;
}
