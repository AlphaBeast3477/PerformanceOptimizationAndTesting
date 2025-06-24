#include <iostream>
#include <vector>
#include <chrono>

// Image dimensions
constexpr int WIDTH = 1920;
constexpr int HEIGHT = 1080;

// Converts RGB to grayscale: simple average method
void grayscale_filter(const uint8_t* input, uint8_t* output, int width, int height) {
    for (int i = 0; i < width * height; ++i) {
        int r = input[3*i];
        int g = input[3*i + 1];
        int b = input[3*i + 2];
        output[i] = static_cast<uint8_t>((r + g + b) / 3);
    }
}

int main() {
    std::vector<uint8_t> input(WIDTH * HEIGHT * 3);
    std::vector<uint8_t> output(WIDTH * HEIGHT);

    // Initialize input with some dummy data
    for (int i = 0; i < WIDTH * HEIGHT * 3; ++i) {
        input[i] = static_cast<uint8_t>(i % 256);
    }

    auto start = std::chrono::high_resolution_clock::now();
    grayscale_filter(input.data(), output.data(), WIDTH, HEIGHT);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Image filter completed in " << elapsed.count() << " seconds.\n";
    std::cout << "Output sample: " << (int)output[0] << ", " << (int)output[1000] << "\n";

    return 0;
}
